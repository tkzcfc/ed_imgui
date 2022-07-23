local Document = require("app.imgui.Document")
local FileDialog = require("app.imgui.FileDialog")

local CustomTree = class("CustomTree", Document)

function CustomTree:ctor(name)
	CustomTree.super.ctor(self, name)

	self.scrolling_size = cc.p(0, 0)
	self.scrolling_flag = ImGuiWindowFlags_HorizontalScrollbar

    self.treeNodeSize = cc.p(0, 0)

	self.fileIcon = EditorIconContent:get(EditorIcon.ICON_FILE)
	self.folderIcon = EditorIconContent:get(EditorIcon.ICON_FOLDER)

    self:updateContent()
end

function CustomTree:updateContent()
end

function CustomTree:doseek(tab)
end

--[[
{
	items = {...}
	name = "",
	noOpen = true,
	noDrag = false,
}
]]
function CustomTree:setShowData(data)
	self.uniqueID = 1000
	self.showData = data
end

function CustomTree:onGUI()
	if self.img_ui_io == nil then
		self.img_ui_io = ImGui.GetIO()
	end

	ImGui.BeginChild("scrolling", self.scrolling_size, false, self.scrolling_flag)
	self:drawItem(self.showData)
	ImGui.EndChild()
end

function CustomTree:cosutomDrawItem(item, noDrag)
	local height = ImGui.GetFrameHeight()
	local iconSize = {x = height, y = height}

	if item.noOpen then
		ImGui.Image(self.fileIcon, iconSize)
	else
		ImGui.Image(self.folderIcon, iconSize)
	end
	ImGui.SameLine()

	if noDrag then
		ImGui.Selectable(item.name, false, ImGuiSelectableFlags_AllowDoubleClick)
		return
	end

	if ImGui.Selectable(item.name, false, ImGuiSelectableFlags_AllowDoubleClick) then
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
		if ImGui.IsMouseClicked(1) then
			if self.rightClickCall then
				self.rightClickCall(item)
			end
		end
	end
end

function CustomTree:drawItem(item)

	if item == nil then
		return
	end

	if item.__nodeKey == nil then
		item.__nodeKey = tostring(self.uniqueID)
		self.uniqueID = self.uniqueID + 1
		item.__buttonKey = tostring(self.uniqueID)
		self.uniqueID = self.uniqueID + 1
	end

	if not item.noOpen then
		if item.__isOpen then
			if ImGui.ArrowButton(item.__buttonKey, ImGuiDir_Down) then
				item.__isOpen = not item.__isOpen
			end
		else
			if ImGui.ArrowButton(item.__buttonKey, ImGuiDir_Right) then
				item.__isOpen = not item.__isOpen
			end
		end
		ImGui.SameLine()
		self:cosutomDrawItem(item)

		if item.__isOpen then
			if item.dataDirty then
				item.dataDirty = false
				print("doseek", item.name)
				self:doseek(item)
			end
			if item.items then
				local frameHeight = ImGui.GetFrameHeight()
				ImGui.Indent(frameHeight)
				for k, v in pairs(item.items) do
					self:drawItem(v)
				end
				ImGui.Unindent(frameHeight)
			end
		end
	else
		self:cosutomDrawItem(item)
	end
end

function CustomTree:canRemove()
	return false
end

function CustomTree:canClose()
	return false
end

return CustomTree
