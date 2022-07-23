-- @Author: fangcheng
-- @Date:   2020-04-05 18:55:10
-- @Description: 

local G_uniqueSeed = 0

local BaseElement = class("BaseElement")

BaseElement.isElementType = true
BaseElement.type = "BaseElement"

BaseElement.PointColor = cc.c4f(1.0, 1.0, 1.0, 1.0)
BaseElement.LineColor = cc.c4f(0.1, 0.1, 1.0, 1.0)
-- BaseElement.LineColor = cc.c4f(1.0, 1.0, 1.0, 1.0)


local DRAW_LINE_OFFSET = 2

BaseElement.defaultFileName = "none"

-- @brief
function BaseElement:ctor(context)
	self.context = context

	-- 父节点
	self.parent = nil

	-- 子节点元素
	self.children = {}

	-- cocos渲染节点
	self.renderNode = nil

	self.name = ""

	self.isOpenFolder = false

	G_uniqueSeed = G_uniqueSeed + 1

	self.uniqueId = G_uniqueSeed
	self.uniqueIDStr = "element" .. G_uniqueSeed

	self.worldPoints = {cc.p(0, 0), cc.p(0, 0), cc.p(0, 0), cc.p(0, 0)}
	self.worldAABB = cc.rect(0, 0, 0, 0)
	self.worldAnchorPoint = cc.p(0, 0)

	self.onUserdataValueChange = function()
		self:onAttributeChange(EditorEvent.ON_CHANGE_USERDATA)
	end

	-- 事件监听
	-- 更改资源
	G_SysEventEmitter:on(SysEvent.DO_CHANGE_ASSET, function(target, asset, canUndo)
		if not asset then return end

		if target == self and not self:isAssetEqual(asset) then
			self:onDoChangeAsset(asset, canUndo)
		end
	end, self)
end

-- @brief 设置渲染节点
function BaseElement:setRenderNode(renderNode)
	assert(self.renderNode == nil, "renderNode already exist")
	self.renderNode = renderNode
end

-- @brief
function BaseElement:getRenderNode()
	return self.renderNode
end

-- @brief聚焦
function BaseElement:onFocus()
	self.isFocusCell = true
end

-- @brief失焦
function BaseElement:onLoseFocus()
	self.isFocusCell = false
end

-- @brief 元素销毁时调用
function BaseElement:onDestroy()

	-- 避免重复调用
	if self.callDestroyFuncTag then
		return
	end
	self.callDestroyFuncTag = true

	for k,v in pairs(self.children) do
		v:onDestroy()
	end
	self.children = {}
	self.parent = nil

	if not tolua.isnull(self.renderNode) then
		self.renderNode:removeFromParent()
	end

	self.context = nil

	G_SysEventEmitter:offByTag(self)
end

-- @brief 获取碰撞区域AABB
function BaseElement:getWorldAABB()
	return self.worldAABB
end

-- @brief 获取碰撞多边形
function BaseElement:getWorldPoints()
	return self.worldPoints
end

-- @brief 获取锚点坐标
function BaseElement:getWorldAnchorPoint()
	return self.worldAnchorPoint
end

-- @brief 获取碰撞节点
function BaseElement:getCollisionNode()
	return self.renderNode
end

function BaseElement:isEmptyNode()
	return self.renderNode == nil
end

-- @brief 更新碰撞数据
function BaseElement:updateCollisionData()
	local transformRoot = _MyG.CenterWindow.rootNode
	local node = self:getCollisionNode()

	if node == nil then
		return
	end

	local size = node:getContentSize()
	local mat = node:getNodeToParentTransform(transformRoot)
	local anchorPoint = node:getAnchorPoint()
	anchorPoint.x = anchorPoint.x * size.width
	anchorPoint.y = anchorPoint.y * size.height
	-- local anchorPoint = cc.p(0, 0)

	if not self.cache_box then
		self.cache_box = cc.rect(0, 0, size.width, size.height)
	else
		self.cache_box.width = size.width
		self.cache_box.height = size.height
	end

	G_Helper.obbApplyMatrix(self.cache_box, mat, self.worldPoints[1], self.worldPoints[2], self.worldPoints[3], self.worldPoints[4])
	G_Helper.getPolygonAABB(self.worldAABB, self.worldPoints)
	self.worldAnchorPoint = G_Helper.mat4_transformVector(anchorPoint, mat)
end

-- @brief 设置元素名称
function BaseElement:setName(name)
	self.name = name
end

-- @brief 获取元素名称
function BaseElement:getName()
	return self.name
end

-- @brief 序列化
function BaseElement:serialize()
	local data = {}

	data.type = self.type
	data.data = self:doSerialize()

	local child = {}
	for i=1,#self.children do
		child[i] = self.children[i]:serialize()
	end

	data.child = child

	return data
end

-- @brief 反序列化
function BaseElement:deserialize(data)
	if not self:doDeserialize(data.data or {}) then
		return false
	end

	local child = data.child or {}
	local ele = nil
	for i = 1, #child do
		ele = _MyG.ElementFactory:spawn(child[i].type, child[i], self.context)
		if not ele then
			return false
		end
		self:addChild(ele)
	end

	return true
end

-- @brief 序列化
function BaseElement:doSerialize()
	local data = {
		userdata = self.userdata
	}

	if _MyG.IsLocalizeMode then
		if self.context.__cname == "EditorLayer" then
			data.aabb = G_Helper.getBox(self.renderNode)
		end

		return data
	end

	data.uniqueId = self.uniqueId

	return data
end

-- @brief 反序列化
function BaseElement:doDeserialize(data)
	if data.uniqueId then
		self.uniqueId = data.uniqueId
		self.uniqueIDStr = "element" .. self.uniqueId
	end

	self.userdata = data.userdata or {}
	return true
end

-- @brief 获取引用资源
function BaseElement:getReferenceResources()
	return {}
end

-- @brief 资源对比
function BaseElement:isAssetEqual(asset)
	assert(false)
end

-- @brief 资源切换
function BaseElement:onDoChangeAsset(asset, canUndo)
end

--------------------------------------------------------- 属性更改/撤销相关 begin ---------------------------------------------------------

-- @brief 属性改变时调用
function BaseElement:onAttributeChange(attributeName)
	local mem = self:doPartMementoGen(attributeName)
	if mem ~= nil then
		self.context:saveSnapshot(self, true, attributeName, mem)
	else
		-- 保存整体
		self.context:saveSnapshot()
	end
end

-- @brief 保存局部快照时,此函数返回改变属性要存储的数据
-- 如果返回为nil则Context保存全局快照
function BaseElement:doPartMementoGen(attributeName)
	if attributeName == EditorEvent.ON_CHANGE_USERDATA then
		return self.userdata or {}
	end
end

-- @brief 撤销属性改变
-- 撤销的属性改变是保存的局部快照时,根据 data 字段对元素进行还原操作
-- @param attributeName 改变的属性名称
-- @param data doPartMementoGen 返回的局部快照数据
function BaseElement:revokeAttributeChange(attributeName, data)
	if attributeName == EditorEvent.ON_CHANGE_USERDATA then
		self.userdata = data
	end
end

--------------------------------------------------------- 属性更改/撤销相关 end ---------------------------------------------------------

-- @brief 获取子节点元素
function BaseElement:getChildByName(name)
	for k,v in pairs(self.children) do
		if v:getName() == name then
			return v
		end
	end
end

-- @brief 添加子节点元素 （不是cocos的 addChild ）
function BaseElement:addChild(child)
	child.parent = self
	self.children[#self.children + 1] = child

	self.renderNode:addChild(child:getRenderNode())
end

-- @brief 从父节点元素上移除（不是cocos的 removeFromParent ）
function BaseElement:removeFromParent(cleanup)
	if cleanup == nil then
		cleanup = true
	end

	local ele = self.parent
	if ele then
		for k,v in pairs(ele.children) do
			if v == self then
				table.remove(ele.children, k)
				break
			end
		end
	end
	self.parent = nil

	if self.renderNode then
		self.renderNode:removeFromParent(cleanup)
	end
end

-- @brief 移除所有子节点元素（不是cocos的 removeAllChildren ）
function BaseElement:removeAllChildren(cleanup)
	if cleanup == nil then
		cleanup = true
	end
	
	for k, v in pairs(self.children) do
		v.parent = nil
		if v.renderNode then
			v.renderNode:removeFromParent(cleanup)
		end
	end

	self.children = {}
end

-- 控制显隐
function BaseElement:setVisible(visible)
	if self.renderNode then
		self.renderNode:setVisible(visible)
	end
end

-- @brief 拖拽元素时调用
function BaseElement:doElementDrag(offset)
	self.renderNode:setPosition(self.renderNode:getPositionX() + offset.x, self.renderNode:getPositionY() + offset.y)
end

-- @brief node面板GUI展示
function BaseElement:onNodeContentGUI(nodeContent)
end

function BaseElement:onGUI_UserData()
	self.userdata = self.userdata or {}

	ImGui.PushID(self.uniqueIDStr)
	_MyG.Functions:onGUI_UserData(self, self.onUserdataValueChange)
	ImGui.PopID()
end

-- @brief 通过唯一ID查找子元素
function BaseElement:searchByUniqueId(uniqueId)
	if self.uniqueId == uniqueId then
		return self
	end
	for k,v in pairs(self.children) do
		local tar = v:searchByUniqueId(uniqueId)
		if tar then
			return tar
		end
	end
end

-- @brief 顺序遍历子节点(不包括调用节点)
function BaseElement:forEachChildren(call)
	for k,v in pairs(self.children) do
		if call(v) then
			return true
		end
		if v:forEachChildren(call) then
			return true
		end
	end
end

-- @brief 逆序遍历子节点(不包括调用节点)
function BaseElement:forEachChildrenReverse(call)
	for i = #self.children, 1, -1 do
		local child = self.children[i]
		if child:forEachChildrenReverse(call) then
			return true
		end
		if call(child) then
			return true
		end
	end
end

function BaseElement:checkResource(filepath)
	if _MyG.Functions:isFileExist(filepath) then
		return filepath
	end
	logE(string.format(STR("NO_RES_USE_DEFAILT_FMT"), tostring(filepath), tostring(self.defaultFileName)))
	return self.defaultFileName
end

return BaseElement
