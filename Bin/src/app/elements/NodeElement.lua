-- @Author: fangcheng
-- @URL: github.com/tkzcfc
-- @Date:   2020-04-19 14:44:46
-- @Last Modified by:   fangcheng
-- @Last Modified time: 2020-05-30 22:31:28
-- @Description: 节点


local BaseElement = import(".BaseElement")
local NodeElement = class("NodeElement", BaseElement)

NodeElement.type = "Node"
NodeElement.defaultFileName = "Default/DefaultWidget.png"


-- 是否使用图片按钮
local USE_TEXTURE_BUTTON = true

local panel_collapsed_arrow = Tools:getImguiTextureID("panel_collapsed_arrow.png")
local panel_expanded_arrow = Tools:getImguiTextureID("panel_expanded_arrow.png")
local icon_size = cc.p(15, 11)

if not panel_collapsed_arrow or not panel_expanded_arrow then
	USE_TEXTURE_BUTTON = false
end


-- @brief 
function NodeElement:ctor(context)
	NodeElement.super.ctor(self, context)

	self.isOpenFolder = true
end

-- @brief 序列化
function NodeElement:doSerialize()
	local out = NodeElement.super.doSerialize(self)
	if self.renderNode == nil then
		return out
	end

	local t = {
		anchorPoint = self.renderNode:getAnchorPoint(),
		position = cc.p(self.renderNode:getPosition()),
		contentSize = self.renderNode:getContentSize(),
		rotation = self.renderNode:getRotation(),
		scaleX = self.renderNode:getScaleX(),
		scaleY = self.renderNode:getScaleY(),
		opacity = self.renderNode:getOpacity(),
		color = self.renderNode:getColor(),
		name = self.name,
		isOpenFolder = self.isOpenFolder,
	}

	for k,v in pairs(t) do
		out[k] = v
	end

	return out
end

-- @brief 反序列化
function NodeElement:doDeserialize(data)
	if not NodeElement.super.doDeserialize(self, data) then
		return false
	end

	if self:getRenderNode() == nil then
		local render = cc.Node:create()
		self:setRenderNode(render)
	end

	if data.anchorPoint then
		self.renderNode:setAnchorPoint(data.anchorPoint)
	end
	
	if data.position then
		self.renderNode:setPosition(data.position)
	end

	if data.contentSize then
		self.renderNode:setContentSize(data.contentSize)
	end

	if data.rotation then
		self.renderNode:setRotation(data.rotation)
	end

	if data.scaleX then
		self.renderNode:setScaleX(data.scaleX)
	end

	if data.scaleY then
		self.renderNode:setScaleY(data.scaleY)
	end

	if data.opacity then
		self.renderNode:setOpacity(data.opacity)
	end

	if data.color then
		self.renderNode:setColor(data.color)
	end

	if data.name then
		self:setName(data.name)
	end

	if data.isOpenFolder ~= nil then
		self.isOpenFolder = data.isOpenFolder
	end
	
	return true
end

function NodeElement:setName(name)
	self.renderNode:setName(name)
	NodeElement.super.setName(self, name)
end

local retTmp
local tmpTabNumArr = {}
-- @brief 元素属性GUI逻辑 （attribute面板展示）
function NodeElement:onAttributeGUI()

	ImGui.Text(self.type)
	local name = self.name
	retTmp, name = Tools:imgui_inputText(STR("EA_NAME"), name, 32)
    if retTmp then
        self:onAttributeChange("change_name")
    	self:setName(name)
    end
	ImGui.Separator()

	if self.renderNode and ImGui.CollapsingHeader(STR("EA_BASE_ATTR"), ImGuiTreeNodeFlags_DefaultOpen) then
		self:onGUI_Base()
	end

	if ImGui.CollapsingHeader(STR("EA_USER_DATA"), ImGuiTreeNodeFlags_DefaultOpen) then
		self:onGUI_UserData()
	end
end

-- @brief 是否可以编辑size
function NodeElement:bool_can_edit_size()
	return true
end

-- @brief 是否可以编辑锚点
function NodeElement:bool_can_edit_anchor()
	return true
end

-- @brief 元素基本属性GUI逻辑 （attribute面板展示）
function NodeElement:onGUI_Base()
	local anchorPoint = self.renderNode:getAnchorPoint()
	local positionx, positiony = self.renderNode:getPosition()
	local size = self.renderNode:getContentSize()
	local rotation = self.renderNode:getRotation()

    tmpTabNumArr[1] = anchorPoint.x
    tmpTabNumArr[2] = anchorPoint.y
    if self:bool_can_edit_anchor() then
		if ImGui.DragFloat2(STR("EA_ANC"), tmpTabNumArr, 0.05) then
			self:onAttributeChange("change_anchorPoint")

			local prepos = {}
			prepos.x = positionx - size.width * anchorPoint.x
			prepos.y = positiony - size.height * anchorPoint.y

			anchorPoint.x = tmpTabNumArr[1]
			anchorPoint.y = tmpTabNumArr[2]

			local newposx = prepos.x + size.width * anchorPoint.x
			local newposy = prepos.y + size.height * anchorPoint.y

			self.renderNode:setAnchorPoint(anchorPoint)
			self.renderNode:setPosition(newposx, newposy)
		end
	else
        ImGui.InputFloat2(STR("EA_ANC"), tmpTabNumArr, "%.3f", ImGuiInputTextFlags_ReadOnly)
	end

    tmpTabNumArr[1] = positionx
    tmpTabNumArr[2] = positiony
    if ImGui.DragFloat2(STR("EA_POS"), tmpTabNumArr, 1) then
    	self:onAttributeChange("change_position")
    	self.renderNode:setPosition(tmpTabNumArr[1], tmpTabNumArr[2])
    end

    tmpTabNumArr[1] = size.width
    tmpTabNumArr[2] = size.height
    if self:bool_can_edit_size() then
        if ImGui.DragFloat2(STR("EA_SIZE"), tmpTabNumArr, 1) then
    		self:onAttributeChange("change_contentSize")
	        size.width = tmpTabNumArr[1]
        	size.height = tmpTabNumArr[2]
        	self.renderNode:setContentSize(size)
        end
    else
        ImGui.InputFloat2(STR("EA_SIZE"), tmpTabNumArr, "%.3f", ImGuiInputTextFlags_ReadOnly)
    end

	tmpTabNumArr[1] = self.renderNode:getScaleX()
    tmpTabNumArr[2] = self.renderNode:getScaleY()
    if ImGui.DragFloat2(STR("EA_SCALE"), tmpTabNumArr, 0.05) then
		self:onAttributeChange("change_scale")
    	self.renderNode:setScaleX(tmpTabNumArr[1])
    	self.renderNode:setScaleY(tmpTabNumArr[2])
    end

    tmpTabNumArr[1] = self.renderNode:getSkewX()
    tmpTabNumArr[2] = self.renderNode:getSkewY()
    if ImGui.DragFloat2(STR("EA_SKEW"), tmpTabNumArr, 0.05) then
		self:onAttributeChange("change_skew")
    	self.renderNode:setSkewX(tmpTabNumArr[1])
    	self.renderNode:setSkewY(tmpTabNumArr[2])
    end

    retTmp, rotation = ImGui.DragFloat(STR("EA_ROTATION"), rotation, 1)
    if retTmp then
		self:onAttributeChange("change_rotation")
    	self.renderNode:setRotation(rotation)
    end

    local opacity = self.renderNode:getOpacity()
    retTmp, opacity = ImGui.SliderInt(STR("EA_OPACITY"), opacity, 0, 255)
    if retTmp then
		self:onAttributeChange("change_opacity")
    	self.renderNode:setOpacity(opacity)
    end

    local color = self.renderNode:getColor()
    tmpTabNumArr[1] = color.r / 255
    tmpTabNumArr[2] = color.g / 255
    tmpTabNumArr[3] = color.b / 255
    if ImGui.ColorEdit3(STR("EA_COLOR"), tmpTabNumArr) then
		self:onAttributeChange("change_color")
    	color.r = tmpTabNumArr[1] * 255
    	color.g = tmpTabNumArr[2] * 255
    	color.b = tmpTabNumArr[3] * 255
    	self.renderNode:setColor(color)
    end
end

-- @brief 元素拖拽
function NodeElement:doElementDrag(offset)
	self:onAttributeChange("change_position")
	NodeElement.super.doElementDrag(self, offset)
end

function NodeElement:doPartMementoGen(attributeName)
	if attributeName == "change_NodeOrder" then			-- 顺序改变
	elseif attributeName == "change_parent" then		-- 父节点改变
	elseif attributeName == "change_name" then			-- 改变名称
		return self.name
	elseif attributeName == "change_anchorPoint" then	-- 改变锚点
		local m = {}
		m.anchor = self.renderNode:getAnchorPoint()
		m.position = cc.p(self.renderNode:getPosition())
		return m
	elseif attributeName == "change_position" then		-- 改变位置
		return cc.p(self.renderNode:getPosition())
	elseif attributeName == "change_contentSize" then	-- 改变尺寸
		return self.renderNode:getContentSize()
	elseif attributeName == "change_scale" then			-- 改变缩放
		return cc.p(self.renderNode:getScaleX(), self.renderNode:getScaleY())
	elseif attributeName == "change_rotation" then		-- 改变旋转
		return self.renderNode:getRotation()
	elseif attributeName == "change_opacity" then		-- 改变不透明度
		return self.renderNode:getOpacity()
	elseif attributeName == "change_color" then			-- 改变颜色
		return self.renderNode:getColor()
	elseif attributeName == "change_skew" then			-- 改变斜率
		return cc.p(self.renderNode:getSkewX(), self.renderNode:getSkewY())
	end

	return NodeElement.super.doPartMementoGen(self, attributeName)
end

-- @brief 撤销属性改变
function NodeElement:revokeAttributeChange(attributeName, data)

	if attributeName == "change_NodeOrder" then			-- 顺序改变
	elseif attributeName == "change_parent" then		-- 父节点改变
	elseif attributeName == "change_name" then			-- 改变名称
		self:setName(data)
	elseif attributeName == "change_anchorPoint" then	-- 改变锚点
		self.renderNode:setAnchorPoint(data.anchor)
		self.renderNode:setPosition(data.position)
	elseif attributeName == "change_position" then		-- 改变位置
		self.renderNode:setPosition(data)
	elseif attributeName == "change_contentSize" then	-- 改变尺寸
		self.renderNode:setContentSize(data)
	elseif attributeName == "change_scale" then			-- 改变缩放
		self.renderNode:setScaleX(data.x)
		self.renderNode:setScaleY(data.y)
	elseif attributeName == "change_rotation" then		-- 改变旋转
		self.renderNode:setRotation(data)
	elseif attributeName == "change_opacity" then		-- 改变不透明度
		self.renderNode:setOpacity(data)
	elseif attributeName == "change_color" then			-- 改变颜色
		self.renderNode:setColor(data)
	elseif attributeName == "change_skew" then			-- 改变斜率
		self.renderNode:setSkewX(data.x)
		self.renderNode:setSkewY(data.y)
	else
		NodeElement.super.revokeAttributeChange(self, attributeName, data)
	end
end

-- @brief 节点显示GUI逻辑
function NodeElement:onNodeContentGUI(nodeContent)
	local showFolderMode = #self.children > 0

	if showFolderMode then

		if USE_TEXTURE_BUTTON then
			if self.isOpenFolder then
				if ImGui.ImageButton(panel_expanded_arrow, icon_size) then
					self.isOpenFolder = not self.isOpenFolder
				end
			else
				if ImGui.ImageButton(panel_collapsed_arrow, icon_size) then
					self.isOpenFolder = not self.isOpenFolder
				end
			end
		else
			if self.isOpenFolder then
				if ImGui.ArrowButton(self.uniqueIDStr, ImGuiDir_Down) then
					self.isOpenFolder = not self.isOpenFolder
				end
			else
				if ImGui.ArrowButton(self.uniqueIDStr, ImGuiDir_Right) then
					self.isOpenFolder = not self.isOpenFolder
				end
			end
		end
		ImGui.SameLine()
		self:onItemGUI(nodeContent)

		if self.isOpenFolder then
			if #self.children > 0 then
				ImGui.Indent(20)
					for k, v in pairs(self.children) do
						v:onNodeContentGUI(nodeContent)
					end
				ImGui.Unindent(20)
			end
		end
	else
		self:onItemGUI(nodeContent)
	end
end



local nodeSelectable = cc.p(0, 18)
local dragDropEle = nil
function NodeElement:onItemGUI(nodeContent)
	if ImGui.Selectable(self.name, self.isFocusCell, ImGuiSelectableFlags_AllowDoubleClick, nodeSelectable) then

		if _MyG.KeyboardStateMng:keyCodeIsPressed(cc.KeyCode.KEY_CTRL) then
			if self.context:isFocusElement(self) then
				self.context:cancelFocusElement(self)
			else
				self.context:addFocusElement(self, false)
			end
		else
			self.context:clearFocusElement()
			self.context:addFocusElement(self, true)
		end

		if ImGui.IsMouseDoubleClicked(0) then
			self.isOpenFolder = not self.isOpenFolder
		end
	end

    if ImGui.BeginDragDropSource(ImGuiDragDropFlags_None) then
        ImGui.SetDragDropPayload("DND_MOVE_NODE_CELL", "1", 1)
        ImGui.Text(self.name)
        ImGui.EndDragDropSource()
        dragDropEle = self
    end

    if ImGui.BeginDragDropTarget() then
    	if Tools:check_AcceptDragDropPayload("DND_MOVE_NODE_CELL") then
    		if tolua.isnull(dragDropEle.renderNode) then
    		else
				if dragDropEle ~= self then
					if self:canDoMoveOperation(dragDropEle) then
						if self.context:elementChangeParentHook(dragDropEle, self) then
							self:onAttributeChange("change_parent")
	
							local beginNode = dragDropEle.renderNode
							local endNode = self.renderNode
							beginNode:retain()
							dragDropEle:removeFromParent(false)
							self:addChild(dragDropEle)
							beginNode:release()
						end
					end
    			end
    		end
    	end
    	ImGui.EndDragDropTarget()
    end

	if ImGui.IsItemHovered() then
		-- 右键点击
		if ImGui.IsMouseClicked(1) then

			G_SysEventEmitter:once("onNodeContentGUI_End", function()
				ImGui.OpenPopup("node_content_right_click_popup")
			end)

			local canUp = self:canMoveOrderUp()
			local canDown = self:canMoveOrderDown()
			local canMoveToRoot = not (self.context.rootElement == self.parent)

			nodeContent:setPopLogic(function()
				-- 上移
				if ImGui.MenuItem(STR("EA_NODE_MOVE_UP_ITEM"), "", false, canUp) then
					self:nodeMovingOrder(true)
				end
				
				-- 上移至顶部
				if ImGui.MenuItem(STR("EA_NODE_MOVE_UP_ITEM_EX"), "", false, canUp) then
					self:nodeMovingOrder(true, true)
				end

				-- 下移
				if ImGui.MenuItem(STR("EA_NODE_MOVE_DOWN_ITEM"), "", false, canDown) then
					self:nodeMovingOrder(false)
				end

				-- 下移至底部
				if ImGui.MenuItem(STR("EA_NODE_MOVE_DOWN_ITEM_EX"), "", false, canDown) then
					self:nodeMovingOrder(false, true)
				end

				if ImGui.MenuItem(STR("EA_NODE_MOVE_TO_ROOT_ITEM"), "", false, canMoveToRoot) then
					self:onAttributeChange("change_NodeOrder")
					self:getRenderNode():retain()
					self:removeFromParent(false)
					self.context.rootElement:addChild(self)
					self:getRenderNode():release()
				end
			end)
		end
	end
end

-- @brief 是否可以上移顺序
function NodeElement:canMoveOrderUp()
	return self:canMovingOrder(true)
end

-- @brief 是否可以下移顺序
function NodeElement:canMoveOrderDown()
	return self:canMovingOrder(false)
end

-- @brief 是否可以改变顺序
function NodeElement:canMovingOrder(isUp)
	if tolua.isnull(self.renderNode) then
		return false
	end

	-- 元素父节点
	local parent = self.parent

	-- 如果他为空则表明处于根节点
	if parent == nil then
		return false
	end

	if #parent.children <= 1 then
		return false
	end

	if isUp then
		return parent.children[1] ~= self
	end
	return parent.children[#parent.children] ~= self
end

-- @brief 节点移动顺序

function NodeElement:nodeMovingOrder(isUp, isFull)
	if not self:canMovingOrder(isUp) then
		return
	end

	local parent = self.parent
	local children = self.parent.children

	-- 获取当前位置
	local tarPos = nil
	for k, v in pairs(children) do
		if v == self then
			tarPos = k
			break
		end
	end

	if tarPos == nil then
		return
	end

	self:onAttributeChange("change_NodeOrder")

	for k, v in pairs(children) do
		if v:getRenderNode() then
			v:getRenderNode():retain()
		end
	end

	if isFull then
		local newChildren = {}

		if isUp then
			newChildren[#newChildren + 1] = children[tarPos]
		end

		for k, v in pairs(children) do
			if k ~= tarPos then
				newChildren[#newChildren + 1] = children[k]
			end
		end

		if not isUp then
			newChildren[#newChildren + 1] = children[tarPos]
		end

		parent:removeAllChildren(false)
	
		for k, v in pairs(newChildren) do
			parent:addChild(v)
		end

		for k, v in pairs(children) do
			if v:getRenderNode() then
				v:getRenderNode():release()
			end
		end
		return
	end

	-- 重新排序
	local newChildren = {}
	for k, v in pairs(children) do
		if k ~= tarPos then
			if isUp then
				if k == tarPos - 1 then
					newChildren[#newChildren + 1] = children[tarPos]
				end
				newChildren[#newChildren + 1] = v
			else
				newChildren[#newChildren + 1] = v
				if k == tarPos + 1 then
					newChildren[#newChildren + 1] = children[tarPos]
				end
			end
		end
	end

	parent:removeAllChildren(false)

	for k, v in pairs(newChildren) do
		parent:addChild(v)
	end

	children = self.parent.children
	for k, v in pairs(children) do
		if v:getRenderNode() then
			v:getRenderNode():release()
		end
	end
end

-- @brief 是否可以执行拖动操作
function NodeElement:canDoMoveOperation(dragDropEle)

	if dragDropEle.parent == self then
		print("父节点未改变")
		return false
	end

	if self:isChild(dragDropEle, self) then
		return false
	end
	return true
end

-- @brief 判断是否为某个节点的子节点
function NodeElement:isChild(root, tar)
	local function doFunc(node, tar)
		if node == nil or node == tar then
			return false
		end
	
		local children = node.children
		if #node.children <= 0 then
			return false
		end

		for k,v in pairs(children) do
			if v == tar or doFunc(v, tar) then
				return true
			end
		end
		return false
	end
	return doFunc(root, tar)
end

return NodeElement