-- @Author: fangcheng
-- @URL: github.com/tkzcfc
-- @Date:   2020-04-05 17:50:09
-- @Last Modified by:   fangcheng
-- @Last Modified time: 2020-05-30 22:00:03
-- @Description: 

local Document = require("app.imgui.Document")
local lstack = require("app.common.lstack")

local BaseEditor = class("BaseEditor", Document)

function BaseEditor:ctor(name, asset)
	BaseEditor.super.ctor(self, name)

	self.asset = asset

    self.sysRecipient 	= G_Class.Recipient.new(G_SysEventEmitter)

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

function BaseEditor:destroy()
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

function BaseEditor:onShow()
    BaseEditor.super.onShow(self)
    self.contextVisibleValue = true
    self:initEvent()

    if self.refreshOnShowFlag then
    	self.refreshOnShowFlag = false
    	self:refresh()
    end
end

function BaseEditor:onHide()
    self.sysRecipient:clear()
    self.contextVisibleValue = false
    BaseEditor.super.onHide(self)
end

function BaseEditor:onGUI()
	BaseEditor.super.onGUI(self)

	if self.saveSnapshotTag then
		local imgIO = ImGui.GetIO()
		if not imgIO.WantTextInput and not ImGui.IsAnyMouseDown() then
			self.saveSnapshotTag = false
		end
	end
end

function BaseEditor:initEvent()
	self.sysRecipient:on("onEditorContentSave", function()
		self:save()
	end)

	self.sysRecipient:on("onKeyBoardSave", function()
		self:save()
	end)

	self.sysRecipient:on("onKeyBoardUndo", function()
		self:pop()
	end)

	self.sysRecipient:on("onKeyBoardDelete", function()
		self:onKeyBoardDelete()
	end)

	self.sysRecipient:on("onKeyBoardAll", function()
		self:onKeyBoardAll()
	end)
end

-- @brief 序列化
function BaseEditor:serialize()
    local data = {}
    data.context = self:doSerialize()
    return data
end

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
		G_SysEventEmitter:emit("content_onContentChange", self.asset)
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

-- @brief 快照pop
function BaseEditor:pop()
	local mem = self.memorandum:pop()

	-- print_lua_value(mem)
	if not mem or not mem.memento then
		return
	end
	
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

	self.recoverPhase = false
end

-- @brief 保存当前快照
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

	if dirtyTarget and isPart and memento then
		local partType = nil
		local identify = nil

		if dirtyTarget.isElementType then
			partType = "element"
			identify = dirtyTarget.uniqueId
		elseif dirtyTarget.isPluginType then
			partType = "plugin"
			identify = dirtyTarget.__cname
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
	if self.recoverPhase then
		return
	end

	if not self.saveSnapshotTag then
		-- 保存局部快照
		local mem = self:doSavePartSnapshot(dirtyTarget, isPart, attributeName, memento)
		if mem then
			if self.isMultiPart then
				self.multiPartArr[#self.multiPartArr + 1] = mem
			else
				self.memorandum:push({isPart = true, memento = mem, isMultiPart = false})
				self.saveSnapshotTag = true
			end
		else
			-- 保存整体快照
			self:doSaveSnapshot()
			self.saveSnapshotTag = true
		end
	end
	self:dataDirty()
end

function BaseEditor:endSaveSnapshot()
	self.isMultiPart = false
	if not self.saveSnapshotTag then
		self.saveSnapshotTag = true
		if #self.multiPartArr > 0 then
			self.memorandum:push({isPart = true, memento = self.multiPartArr, isMultiPart = true})
		end
	end
	self.multiPartArr = {}
end

function BaseEditor:dataDirty()
	self.dirty = true
end

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

return BaseEditor