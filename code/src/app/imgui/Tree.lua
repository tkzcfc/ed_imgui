local Document = require("app.imgui.Document")
local FileDialog = require("app.imgui.FileDialog")

local Tree = class("Tree", Document)

function Tree:ctor(name)
	Tree.super.ctor(self, name)

	local node_flags = ImGuiTreeNodeFlags_OpenOnArrow
	node_flags = Tools:bor_int32(node_flags, ImGuiTreeNodeFlags_OpenOnDoubleClick)
	self.node_flags = node_flags

	self.node_flags_no_open = Tools:bor_int32(ImGuiTreeNodeFlags_Leaf, ImGuiTreeNodeFlags_NoTreePushOnOpen)

	local windoFlag = 0
    windoFlag = Tools:bor_int32(windoFlag, ImGuiWindowFlags_Tooltip)
    windoFlag = Tools:bor_int32(windoFlag, ImGuiWindowFlags_NoInputs)
    windoFlag = Tools:bor_int32(windoFlag, ImGuiWindowFlags_NoTitleBar)
    windoFlag = Tools:bor_int32(windoFlag, ImGuiWindowFlags_NoMove)
    windoFlag = Tools:bor_int32(windoFlag, ImGuiWindowFlags_NoResize)
    windoFlag = Tools:bor_int32(windoFlag, ImGuiWindowFlags_NoSavedSettings)
    windoFlag = Tools:bor_int32(windoFlag, ImGuiWindowFlags_AlwaysAutoResize)
    self.drag_window_flag = windoFlag

    
	self.scrolling_size = cc.p(0, 0)
	self.scrolling_flag = ImGuiWindowFlags_HorizontalScrollbar

    self.drag_cur_data = nil
    self:updateContent()
end

function Tree:updateContent()
end

function Tree:doseek(tab)
end

--[[
{
	items = {...}
	name = "",
	noOpen = true,
	noDrag = false,
}
]]
function Tree:setShowData(data)
	self.uniqueID = 1000
	self.showData = data
end

function Tree:onGUI()
	if self.img_ui_io == nil then
		self.img_ui_io = ImGui.GetIO()
	end

	self.unLockRightClick = true

	ImGui.BeginChild("scrolling", self.scrolling_size, false, self.scrolling_flag)
	self:drawItem(self.showData)
	ImGui.EndChild()
end

function Tree:drawItem(item)

	if item == nil then
		return
	end

	if item.__nodeKey == nil then
		item.__nodeKey = tostring(self.uniqueID)
		self.uniqueID = self.uniqueID + 1
	end

	if item.noOpen then
		ImGui.TreeNodeEx(item.__nodeKey, self.node_flags_no_open, item.name)

		if self.onItemHoveredCallback and ImGui.IsItemHovered() then
			self.onItemHoveredCallback(item)
		end

		if self.unLockRightClick and ImGui.IsItemHovered() then
			-- 左键双击
			if ImGui.IsMouseDoubleClicked(0) then
				if self.leftDoubleClickCall then
					self.leftDoubleClickCall(item)
				end
			end
			-- 右键点击
			if ImGui.IsMouseClicked(1) then
				self.unLockRightClick = false
				if self.rightClickCall then
					self.rightClickCall(item)
				end
			end
		end

		if self.drag_cur_data == item then
			if ImGui.IsItemActive() then
				ImGui.SetNextWindowPos(self.img_ui_io.MousePos, ImGuiCond_Always)
				ImGui.Begin("##Drag_Window_Content", true, self.drag_window_flag)
					ImGui.Text(item.name)
				ImGui.End()
			else
				if self.dragEndCallback then
					self.dragEndCallback(self.img_ui_io.MousePos, item)
				end

				self.drag_cur_data = nil
			end
		else
			if not item.noDrag and ImGui.IsItemActive() then
				local clickPos = Tools:getMouseClickedPos(0)
				if cc.pDistanceSQ(clickPos, self.img_ui_io.MousePos) > 10 then
					
					ImGui.SetNextWindowPos(self.img_ui_io.MousePos, ImGuiCond_Always)
					ImGui.Begin("##Drag_Window_Content", true, self.drag_window_flag)
						ImGui.Text(item.name)
					ImGui.End()
					self.drag_cur_data = item
				end
			end
		end
	else
		if ImGui.TreeNodeEx(item.__nodeKey, self.node_flags, item.name) then
			if item.dataDirty then
				item.dataDirty = false
				self:doseek(item)
			end
			if item.items then
				for k, v in pairs(item.items) do
					self:drawItem(v)
				end
			end
			ImGui.TreePop()
		end
		if self.unLockRightClick and ImGui.IsItemClicked(1) then
			-- 右键点击
			self.unLockRightClick = false
			if self.rightClickCall then
				self.rightClickCall(item)
			end
		end
	end
end

function Tree:canRemove()
	return false
end

function Tree:canClose()
	return false
end

return Tree
