-- @Author: fangcheng
-- @Date:   2020-04-05 17:50:09
-- @Description: 编辑器基类

local Document = require("app.imgui.Document")
local lstack = require("app.common.lstack")

local BaseEditor = class("BaseEditor", Document)

function BaseEditor:ctor(name, asset)
	BaseEditor.super.ctor(self, name)

	self.asset = asset

	-- 事件订阅管理
    self.sysRecipient 	= G_Class.Recipient.new(G_SysEventEmitter)

	-- 快照保存
    if asset and asset.property.uuid then
    	self.memorandum		= lstack.new(asset.property.uuid, true, ".cache_memento")
    else
    	self.memorandum		= lstack.new(nil, false, ".cache_memento")
	end
	self.memorandum.cacheSize = 10
	self.memorandum.fragmentSize = 10

	-- 根元素
	self.rootElement	= nil
    -- 焦点元素
	self.focusEles 		= {}
	-- 插件
	self.plugins		= {}
end

-- @brief 页签销毁
-- @override
function BaseEditor:destroy()
	G_SysEventEmitter:offByTag(self)
    self.sysRecipient:clear()
    self.memorandum:clear()
    self:removeAllPlugin()
    BaseEditor.super.destroy(self)
end

-- @brief 添加焦点元素
-- @param monopoly 是否独占
function BaseEditor:addFocusElement(element, monopoly)
	if self:isFocusElement(element) then
		return true
	end

	if monopoly then
		self:clearFocusElement()
		self.focusEles[#self.focusEles + 1] = element
		element:onFocus()
		return true
	end

	self.focusEles[#self.focusEles + 1] = element
	element:onFocus()
	return true
end

-- @brief 取消焦点元素
function BaseEditor:cancelFocusElement(element)
	for k,v in pairs(self.focusEles) do
		if v == element then
			v:onLoseFocus()
			table.remove(self.focusEles, k)
			return true
		end
	end
end

-- @brief 测试是否为焦点元素
function BaseEditor:isFocusElement(element)
	for k,v in pairs(self.focusEles) do
		if v == element then
			return true
		end
	end
end

-- @brief 清除所有焦点元素
function BaseEditor:clearFocusElement()
	for k,v in pairs(self.focusEles) do
		v:onLoseFocus()
	end
	self.focusEles = {}
end

-- @brief 是否有焦点元素
function BaseEditor:hasFocusEles()
	return #self.focusEles > 0
end

-- @brief document被显示
function BaseEditor:onShow()
    BaseEditor.super.onShow(self)
    self.contextVisibleValue = true
    self:initEvent()

    if self.refreshOnShowFlag then
    	self.refreshOnShowFlag = false
    	self:refresh()
    end
end

-- @brief document被隐藏
function BaseEditor:onHide()
    self.sysRecipient:clear()
    self.contextVisibleValue = false
    BaseEditor.super.onHide(self)
end

-- @brief GUI绘制
function BaseEditor:onGUI()
	BaseEditor.super.onGUI(self)

	-- @ param self.disableSnapshotTag 禁用快照标记,当他为 TRUE 时快照无法保存
	-- 此处逻辑主要处理拖动或者输入文本改变属性，防止改变一下就保存一次快照
	-- 快照保存成功之后 disableSnapshotTag 会置为 TRUE，当鼠标处于抬起状态且文本输入框不处于正在输入状态 将 disableSnapshotTag 标记自动置为 FALSE,启用快照功能
	if self.disableSnapshotTag then
		local imgIO = ImGui.GetIO()
		if not imgIO.WantTextInput and not ImGui.IsAnyMouseDown() then
			self.disableSnapshotTag = false
		end
	end
end

-- @brief 事件订阅
function BaseEditor:initEvent()
	self.sysRecipient:on(SysEvent.CONTENT_ON_EDITOR_CONTENT_SAVE, function()
		self:save()
	end)

	self.sysRecipient:on(SysEvent.ON_KEY_BOARD_SAVE, function()
		self:save()
	end)

	self.sysRecipient:on(SysEvent.ON_KEY_BOARD_UNDO, function()
		if _MyG.PopupManager:getPopCount() > 0 then
			logW(STR("UndoFail_HasPopup"))
			return
		end
		self:pop()
	end)

	self.sysRecipient:on(SysEvent.ON_KEY_BOARD_DELETE, function()
		self:onKeyBoardDelete()
	end)

	self.sysRecipient:on(SysEvent.ON_KEY_BOARD_ALL, function()
		self:onKeyBoardAll()
	end)

	G_SysEventEmitter:emit(SysEvent.ON_EDIT_CONTEXT_INIT_EVENT, self)
end

-- @brief 序列化
function BaseEditor:serialize()
    local data = {}
    data.context = self:doSerialize()
    return data
end

-- @brief 序列化,此函数返回的数据保存在 data.context中
function BaseEditor:doSerialize()
	local out = {}

	if not _MyG.IsLocalizeMode then
		out.focusEleUniqueIDs = {}
		for k,v in pairs(self.focusEles) do
			table.insert(out.focusEleUniqueIDs, v.uniqueId)
		end
	end

	local pluginData = {}
	for k,v in pairs(self.plugins) do
		table.merge(pluginData, v:serialize())
	end
	out.plugins = pluginData

	return out
end

-- @brief 反序列化
function BaseEditor:deserialize(data)
	return self:doDeserialize(data.context or {})
end

function BaseEditor:doDeserialize(data)
	for k,v in pairs(self.plugins) do
		if not v:deserialize(data.plugins) then
			return false
		end
	end
	return true
end

-- @brief 保存
function BaseEditor:save()
	if self.dirty then
		G_SysEventEmitter:emit(SysEvent.CONTENT_ON_CONTENT_CHANGE, self.asset)
	end
	self.dirty = false
	return true
end

-- @brief 刷新
function BaseEditor:refresh()
	print("refresh")

	local memento = self:genMemento()
	if memento then
		self:restoreSnapshot(memento)
	end
end

-- @brief 在改界面显示时刷新
function BaseEditor:needRefreshOnShow()
	self.refreshOnShowFlag = true
end


--------------------------------------------------------- 编辑器快照保存/回退逻辑 begin ---------------------------------------------------------

-- @brief 获取当前快照
function BaseEditor:genMemento()
	local data = clone(self:serialize())
	return {
		data = data,
	}
end

-- @brief 快照push
function BaseEditor:push()
	local mem = self:genMemento()
	if mem then
		self.memorandum:push({isPart = false, memento = mem, isMultiPart = false})
	end
end

local function hasArmatureNode(root)
	local contain = false
	for k, v in pairs(root or {}) do
		if v.type == "ArmatureFile" then
			return true
		end

		contain = hasArmatureNode(v.child)
		if contain then break end
	end
	return contain
end

-- @brief 是否可以pop快照
function BaseEditor:canPop(mem)
	if self.lastUndoTime == nil then
		self.lastUndoTime = Tools:gettime()
		return true
	end

	-- 全局快照
	if not mem.isPart then
		-- 全局快照恢复时会重新创建大量对象,这儿也做一个间隔时间限制
		-- 全局回退默认间隔
		local waitTime = 0.5

		-- 全局回退时有cocos自带的Armature动画,太快会崩溃...
		-- 含有Armature动画时回退间隔久点...
		if mem.memento.data and mem.memento.data.children then
			if hasArmatureNode(mem.memento.data.children) then
				waitTime = 1
			end
		end

		local curTime = Tools:gettime()
		if curTime - self.lastUndoTime < waitTime then
			return false
		end
		self.lastUndoTime = curTime
	end

	return true
end

-- @brief 快照pop
function BaseEditor:pop()
	local mem = self.memorandum:pop()

	if not mem or not mem.memento then
		return
	end

	if not self:canPop(mem) then
		self.memorandum:push(mem)
		return
	end
	
	-- 快照恢复标记
	-- 处于恢复阶段时不进行快照保存操作
	self.recoverPhase = true

	if mem.isPart then
		if mem.isMultiPart then
			for k,v in pairs(mem.memento) do
				self:restorePartSnapshot(v)
			end
		else
			self:restorePartSnapshot(mem.memento)
		end
		self:dataDirty()
	else
		logI("restoreSnapshot All---------->>")
		self:restoreSnapshot(mem.memento)
		self:dataDirty()
	end

	-- 恢复完毕
	self.recoverPhase = false
end

-- @brief 保存当前快照(全局快照)
function BaseEditor:doSaveSnapshot()
	logI("doSaveSnapshot All---------------------->>>>")
	self:push()
end

-- @brief 恢复快照
function BaseEditor:restoreSnapshot(memento)
	self:deserialize(memento.data)
end

-- @brief 保存局部快照
function BaseEditor:doSavePartSnapshot(dirtyTarget, isPart, attributeName, memento)
	if type(memento) == "table" then
		memento = clone(memento)
	end

	if dirtyTarget and isPart and memento ~= nil then
		local partType = nil
		local identify = nil
		
		if dirtyTarget == self then
			partType = "editor"
			identify = "editor"
		elseif dirtyTarget.isElementType then
			partType = "element"
			identify = dirtyTarget.uniqueId
		elseif dirtyTarget.isPluginType then
			partType = "plugin"
			identify = dirtyTarget.__cname
		else
			asset(false)
		end

		if partType == nil then
			error("unknown type")
			return
		end
		-- 
		local mem = {}
		mem.type 			= partType
		mem.identify 		= identify
		mem.attributeName 	= attributeName
		mem.data 			= memento
		return mem
	end
end

-- @brief 恢复局部快照
function BaseEditor:restorePartSnapshot(memento)
	local partType = memento.type
	local identify = memento.identify
	local data	   = memento.data
	local attributeName = memento.attributeName

	if partType == "plugin" then
		local plugin = self:getPlugin(identify)
		if plugin then
			plugin:revokeAttributeChange(attributeName, data)
		else
			logE("restorePartSnapshot fail: plugin not found")
		end
	elseif partType == "element" then
		local element = self:getElementByUniqueID(identify)
		if element then
			element:revokeAttributeChange(attributeName, data)
		else
			logE("restorePartSnapshot fail: element not found")
		end
	elseif partType == "editor" then
		self:revokeAttributeChange(attributeName, data)
	end
end

-- @brief 开始快照保存(用于同一时刻多元素改变)
function BaseEditor:beginSaveSnapshot()
	self.isMultiPart = true
	self.multiPartArr = {}
end

-- @brief 保存当前快照
-- @param dirtyTarget 被改变的对象
-- @param isPart 是否只保存该对象的快照就行
-- 一般操作都为true,撤回时直接使用该对象的记快照重置就行,但是一旦涉及到删除这种不可逆操作时该值为false编辑器直接保存整体快照

-- @param attributeName 对象被改变的值
-- @param memento 被改变的对象的记忆数据
function BaseEditor:saveSnapshot(dirtyTarget, isPart, attributeName, memento)
	-- 处于快照恢复阶段,不保存快照(正常情况下处于恢复操作不会调用此函数，这儿起一个预防作用)
	if self.recoverPhase then
		return
	end

	if not self.disableSnapshotTag then
		-- 保存局部快照
		local mem = self:doSavePartSnapshot(dirtyTarget, isPart, attributeName, memento)
		if mem ~= nil then
			if self.isMultiPart then
				self.multiPartArr[#self.multiPartArr + 1] = mem
			else
				self.memorandum:push({isPart = true, memento = mem, isMultiPart = false})
				self.disableSnapshotTag = true
			end
		else
			-- 保存整体快照
			self:doSaveSnapshot()
			self.disableSnapshotTag = true
		end
	end
	self:dataDirty()
end

-- @brief 快照保存完毕(用于同一时刻多元素改变)
function BaseEditor:endSaveSnapshot()
	self.isMultiPart = false
	if not self.disableSnapshotTag then
		self.disableSnapshotTag = true
		if #self.multiPartArr > 0 then
			self.memorandum:push({isPart = true, memento = self.multiPartArr, isMultiPart = true})
		end
	end
	self.multiPartArr = {}
end

--------------------------------------------------------- 编辑器快照保存/回退逻辑 end ---------------------------------------------------------

-- @brief delete按键事件回调
function BaseEditor:onKeyBoardDelete()
    for k,v in pairs(self.plugins) do
        if v:onKeyBoardDelete() then
            return true
        end
    end
end

-- @brief ctrl + a
function BaseEditor:onKeyBoardAll()
end

-- @brief 是否显示
function BaseEditor:contextVisible()
    return self.contextVisibleValue
end

-- @brief 是否阻断元素的Touch事件
function BaseEditor:isBlockEleTouchEvent()
	for k,v in pairs(self.plugins) do
		if v:isBlockEleTouchEvent() then
			return true
		end
	end
	return false
end

-- @brief 添加插件
function BaseEditor:addPlugin(plugin)
	plugin:attach(self)
	self.plugins[#self.plugins + 1] = plugin
end

--@brief 移除插件
function BaseEditor:removePlugin(plugin)
	for k,v in pairs(self.plugins) do
		if v == plugin then
			v:detach()
			table.remove(self.plugins, k)
			break
		end
	end
end

-- @brief 获取插件
function BaseEditor:getPlugin(pluginName)
	for k,v in pairs(self.plugins) do
		if v.__cname == pluginName then
			return v
		end
	end
end

--@brief 移除插件
function BaseEditor:removePluginByName(pluginName)
	for k,v in pairs(self.plugins) do
		if v.__cname == pluginName then
			v:detach()
			table.remove(self.plugins, k)
			break
		end
	end
end

-- @brief 移除所有插件
function BaseEditor:removeAllPlugin()
	for k,v in pairs(self.plugins) do
		v:detach()
	end
	self.plugins = {}
end

-- @brief 通过uniqueID获取元素
function BaseEditor:getElementByUniqueID(uniqueId)
	if self.rootElement then
		return self.rootElement:searchByUniqueId(uniqueId)
	end
end

-- @brief 元素改变父节点回调
function BaseEditor:elementChangeParentHook(tar, newParent)
	return true
end

--------------------------------------------------------- 属性更改/撤销相关 ---------------------------------------------------------

-- @brief 属性改变时调用
function BaseEditor:onAttributeChange(attributeName)
	local mem = self:doPartMementoGen(attributeName)
	if mem ~= nil then
		self:saveSnapshot(self, true, attributeName, mem)
	else
		-- 保存整体
		self:saveSnapshot()
	end
end

-- @brief 保存局部快照时,此函数返回改变属性要存储的数据
-- 如果返回为nil则Context保存全局快照
function BaseEditor:doPartMementoGen(attributeName)
end

-- @brief 撤销属性更改
-- 撤销的属性改变是保存的局部快照时,根据 data 字段对元素进行还原操作
-- @param attributeName 改变的属性名称
-- @param data doPartMementoGen 返回的局部快照数据
function BaseEditor:revokeAttributeChange(attributeName, data)
end

--------------------------------------------------------- 属性更改/撤销相关 end ---------------------------------------------------------

return BaseEditor