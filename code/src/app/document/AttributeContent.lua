local Document = require("app.imgui.Document")

local AttributeContent = class("AttributeContent", Document)

function AttributeContent:ctor()
	AttributeContent.super.ctor(self, "attribute")
	self.scrolling_size = cc.p(0, 0)
	self.scrolling_flag = ImGuiWindowFlags_HorizontalScrollbar
end

function AttributeContent:onGUI()
	ImGui.BeginChild("scrolling", self.scrolling_size, false, self.scrolling_flag)
	G_SysEventEmitter:emit("onAttributeContent_GUI")
	ImGui.EndChild()
end

function AttributeContent:canRemove()
	return false
end

function AttributeContent:canClose()
	return false
end

return AttributeContent