local CustomTree = require("app.imgui.CustomTree")

local NodeContent = class("NodeContent", CustomTree)

function NodeContent:ctor()
	NodeContent.super.ctor(self, "node")
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
	
	G_SysEventEmitter:emit("onNodeContentGUI", self)

	ImGui.EndChild()

	G_SysEventEmitter:emit("onNodeContentGUI_End")

	if ImGui.BeginPopup("node_content_right_click_popup") and self.popLogic then
		self.popLogic()
		ImGui.EndPopup()
	end
end

function NodeContent:setPopLogic(func)
	self.popLogic = func
end

return NodeContent