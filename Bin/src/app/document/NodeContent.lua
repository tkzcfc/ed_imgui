local CustomTree = require("app.imgui.CustomTree")

local NodeContent = class("NodeContent", CustomTree)

function NodeContent:ctor()
	NodeContent.super.ctor(self, "node")
	G_SysEventEmitter:on("onNodeContentUpdate", function(rootNode)
		if self.rootNode == rootNode then
			self:updateContentExt()
		end
	end)
end

function NodeContent:setRootNode(rootNode)
	self.rootNode = rootNode
	self:updateContent()
end

function NodeContent:updateContent()
	if self.rootNode == nil then
		self:setShowData()
		return
	end

	local showData = {}
	showData.name = G_ROOT_NODE_NAME
	showData.noOpen = #self:getValidChildren(self.rootNode) <= 0
	showData.noDrag = false
	showData.noSelect = true
	showData.dataDirty = true
	showData.fullPath = tostring(self.noSelect)
	showData.node = self.rootNode
	self:setShowData(showData)
end

function NodeContent:doseek(tab)
	local children = self:getValidChildren(tab.node)
	if children == nil or #children <= 0 then
		return
	end

	tab.items = {}
	for k,v in pairs(children) do
		local t = {}
		t.node = v
		t.name = v:getName()
		t.fullPath = tostring(v)
		t.noOpen = #self:getValidChildren(v) <= 0
		t.dataDirty = true
		table.insert(tab.items, t)
	end
end

function NodeContent:getValidChildren(node)
	if node == nil or node:getChildrenCount() <= 0 then
		return {}
	end

	local children = node:getChildren()

	local validChildren = {}
	for k, v in pairs(children) do
		if self.onNodeFilter then
			if self.onNodeFilter(v) then
				table.insert(validChildren, v)
			end
		else
			table.insert(validChildren, v)
		end
	end
	return validChildren
end

function NodeContent:pushContext()
	local openTagMap = {}

	local function push(item)
		if item == nil then
			return
		end
		if item.__isOpen then
			openTagMap[item.fullPath] = true
		end
		if item.items then
			for k,v in pairs(item.items) do
				push(v)
			end
		end
	end

	push(self.showData)

	return openTagMap
end

function NodeContent:popContext(openTagMap)
	if openTagMap == nil then
		return
	end
	local function pop(item)
		if item == nil then
			return
		end

		if openTagMap[item.fullPath] then
			item.__isOpen = true
		end
		if item.dataDirty then
			item.dataDirty = false
			self:doseek(item)
		end
		if item.items then
			for k,v in pairs(item.items) do
				pop(v)
			end
		end
	end
	pop(self.showData)
end

function NodeContent:updateContentExt()
	local context = self:pushContext()
	self:updateContent()
	self:popContext(context)
end

function NodeContent:canRemove()
	return false
end

function NodeContent:canClose()
	return false
end

function NodeContent:onGUI()
	if self.img_ui_io == nil then
		self.img_ui_io = ImGui.GetIO()
	end

	ImGui.BeginChild("scrolling", self.scrolling_size, false, self.scrolling_flag)
	-- ImGui.Indent()
	self:drawItem(self.showData)
	-- ImGui.Unindent()
	ImGui.EndChild()

	if self.dragBeginData and self.dragEndData then
		local beginNode = self.dragBeginData.node
		local endNode = self.dragEndData.node
		self.dragBeginData = nil
		self.dragEndData = nil
		if self:canDoMoveOperation(beginNode, endNode) then
			beginNode:retain()
			beginNode:removeFromParent()
			endNode:addChild(beginNode)
			beginNode:release()
			self:updateContentExt()
			G_SysEventEmitter:emit("onNodeZOrderUpdate")
		end
	end

	if self.openRightClickPopupTag then
		self.openRightClickPopupTag = false
		ImGui.OpenPopup("node_content_right_click_popup")
	end

	if ImGui.BeginPopup("node_content_right_click_popup") then
		if ImGui.MenuItem(STR("EA_NODE_MOVE_UP_ITEM"), "", false, self:canMovingOrder(true, self.curRightClickItem.node)) then
			self:nodeMovingOrder(true, self.curRightClickItem.node)
			self:updateContentExt()
		end
		if ImGui.MenuItem(STR("EA_NODE_MOVE_DOWN_ITEM"), "", false, self:canMovingOrder(false, self.curRightClickItem.node)) then
			self:nodeMovingOrder(false, self.curRightClickItem.node)
			self:updateContentExt()
		end
		ImGui.EndPopup()
	end
end

function NodeContent:canDoMoveOperation(root, tar)

	if self.canDoMoveOperationHook then
		if not self.canDoMoveOperationHook(root, tar) then
			return false
		end
	end

	if self:isChild(root, tar) then
		return false
	end
	return true
end

function NodeContent:isChild(root, tar)
	local function doFunc(node, tar)
		if node == nil or node == tar then
			return false
		end

		if node == nil or node:getChildrenCount() <= 0 then
			return false
		end
	
		local children = node:getChildren()
		for k,v in pairs(children) do
			if v == tar or doFunc(v, tar) then
				return true
			end
		end
		return false
	end
	return doFunc(root, tar)
end

function NodeContent:canMovingOrder(isUp, node)
	if node == nil then
		return false
	end

	local parent = node:getParent()
	if parent == nil then
		return false
	end

	if parent:getChildrenCount() <= 1 then
		return false
	end

	local children = self:getValidChildren(parent)

	if #children <= 1 then
		return false
	end

	if isUp then
		return children[1] ~= node
	end
	return children[#children] ~= node
end

function NodeContent:canOpenPopup(node)
	if tolua.isnull(node) then
		return false
	end
	if self.rootNode == node then
		return false
	end

	return true
end

function NodeContent:nodeMovingOrder(isUp, node)
	if node == nil then
		return
	end

	local parent = node:getParent()
	if parent == nil then
		return
	end

	if parent:getChildrenCount() <= 1 then
		return
	end
	
	local children = self:getValidChildren(parent)

	for k,v in pairs(children) do
		v:retain()
		v:removeFromParent()
	end

	local newTab = {}
	for k,v in pairs(children) do
		if v ~= node then
			if isUp then
				if children[k + 1] == node then
					table.insert(newTab, node)
				end
			end
			table.insert(newTab, v)
			if not isUp then
				if children[k - 1] == node then
					table.insert(newTab, node)
				end
			end
		end
	end

	for k,v in pairs(newTab) do
		parent:addChild(v)
		v:release()
	end
end

function NodeContent:cosutomDrawItem(item, noDrag)
	if noDrag then
		ImGui.Selectable(item.name, false, ImGuiSelectableFlags_AllowDoubleClick, self.nodeSelectable)
		return
	end

	local isFocusCell = false
	if self.onNodeIsFocus then
		isFocusCell = self.onNodeIsFocus(item.node)
	end

	if ImGui.Selectable(item.name, isFocusCell, ImGuiSelectableFlags_AllowDoubleClick, self.nodeSelectable) then
		
		if self.onSelectFocusCell then
			self.onSelectFocusCell(item.node)
		end

		if ImGui.IsMouseDoubleClicked(0) then
			if not item.noOpen then
				item.__isOpen = not item.__isOpen
			else
				if self.leftDoubleClickCall then
					self.leftDoubleClickCall(item)
				end
			end
		end
	end
	
	if ImGui.IsItemHovered() then
		if self.onItemHoveredCallback then
			self.onItemHoveredCallback(item)
		end
		-- 右键点击
		if ImGui.IsMouseClicked(1) and self:canOpenPopup(item.node) then
			self.curRightClickItem = item
			self.openRightClickPopupTag = true
			print("item.name", item.name)
		end
	end

	local table_key = tostring(item)

    if ImGui.BeginDragDropSource(ImGuiDragDropFlags_None) then
        ImGui.SetDragDropPayload("DND_MOVE_NODE_CELL", table_key, #table_key)
        ImGui.Text(item.name)
        ImGui.EndDragDropSource()
    end

    if ImGui.BeginDragDropTarget() then
    	if Tools:check_AcceptDragDropPayload("DND_MOVE_NODE_CELL") then
    		table_key = Tools:AcceptDragDropPayload("DND_MOVE_NODE_CELL")
    		self.dragBeginData = self:getTableByKey(table_key)
    		self.dragEndData = item
    	end
    	ImGui.EndDragDropTarget()
    end
end

function NodeContent:getTableByKey(key)
	local function findFunc(tab, tab_key)
		if tostring(tab) == tab_key then
			return tab
		end

		if tab.items then
			local tmp
			for k,v in pairs(tab.items) do
				tmp = findFunc(v, tab_key)
				if tmp then
					return tmp
				end
			end
		end
	end

	return findFunc(self.showData, key)
end

function NodeContent:drawItem(item)
	if item == nil then
		return
	end

	ImGui.PushID(item.fullPath)
	NodeContent.super.drawItem(self, item)
	ImGui.PopID()
end

return NodeContent