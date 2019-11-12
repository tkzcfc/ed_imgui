local Document = require("app.imgui.Document")

local WidgetContent = class("WidgetContent", Document)

function WidgetContent:ctor()
	WidgetContent.super.ctor(self, "widgets")

	self.scrolling_size = cc.p(0, 0)
	self.scrolling_flag = ImGuiWindowFlags_HorizontalScrollbar

	self.widgetDataArr = {}

	self:appendWidgetInfo(Tools:getImguiTextureID("res/Default/Sprite.png"), "WC_Sprite")
	self:appendWidgetInfo(Tools:getImguiTextureID("res/Default/ImageFile.png"), "WC_Image")
	-- 复活点
	self:appendWidgetInfo(Tools:getImguiTextureID("Res/Default/RevivePoint.png"), "WC_RevivePoint")
end

function WidgetContent:appendWidgetInfo(_icon, _text)
	table.insert(self.widgetDataArr, {icon = _icon, text = _text})
end

local widget_min_width = 80
local widget_max_width = 85
local widget_size = {x = 80, y = 80}
local icon_size = {x = 40, y = 40}

local color = Tools:getStyleColor(ImGuiCol_FrameBgHovered)
local FrameBgHovered_Color = IM_COL32(color.x * 255, color.y * 255, color.z * 255, color.w * 255)

color = Tools:getStyleColor(ImGuiCol_FrameBgActive)
local FrameBgActive_Color = IM_COL32(color.x * 255, color.y * 255, color.z * 255, color.w * 255)

function WidgetContent:onGUI()
	self.cache_drag_item_last = self.cache_drag_item
	self.cache_drag_item = nil

	self:render()

	if self.cache_drag_item == nil then
		if self.cache_drag_item_last then
			local pos = ImGui.GetIO().MousePos
			pos = G_Helper.win_2_visible_pos(pos)
			G_SysEventEmitter:emit("onDragPreWidget", pos, self.cache_drag_item_last.text)
		end
	end
end

function WidgetContent:render()
	ImGui.BeginChild("scrolling", self.scrolling_size, false, self.scrolling_flag)

	local count = self:getWidgetCount()
	local style = ImGui.GetStyle()
	local layout_widget_size = {}
	local last_button_x2, next_button_x2
	local window_visible_x2 = ImGui.GetWindowPos().x + ImGui.GetWindowContentRegionMax().x

	layout_widget_size.x = ImGui.GetWindowContentRegionWidth()
	if layout_widget_size.x < widget_max_width then
		widget_size.x = math.max(layout_widget_size.x, widget_min_width)
	else
		local c = layout_widget_size.x / widget_min_width
		local z = math.modf(c)
		widget_size.x = layout_widget_size.x / z - style.ItemSpacing.x
		if c > 0 then
			widget_size.x = widget_size.x + (style.ItemSpacing.x / c)
		end
	end
	widget_size.y = widget_size.x + 5
	icon_size.y = widget_size.y * 0.5
	icon_size.x = icon_size.y

	for i = 1, count do
		ImGui.BeginChild(i, widget_size, true, ImGuiWindowFlags_NoScrollWithMouse)

        layout_widget_size = ImGui.GetContentRegionAvail()

		if self.widgetDataArr[i].isDrawBGRectTag then
			local start = ImGui.GetCursorScreenPos()
			local drawList = ImGui.GetWindowDrawList()
			if ImGui.IsMouseDown(0) then
				drawList:AddRectFilled(start, cc.p(start.x + layout_widget_size.x, start.y + layout_widget_size.y), FrameBgActive_Color)
			else
				drawList:AddRectFilled(start, cc.p(start.x + layout_widget_size.x, start.y + layout_widget_size.y), FrameBgHovered_Color)
			end
		end

		ImGui.BeginGroup()
		ImGui.BeginVertical("h1", layout_widget_size, 0.5)
		ImGui.Image(self.widgetDataArr[i].icon, icon_size)
		ImGui.PushTextWrapPos(ImGui.GetCursorPos().x + widget_size.x)
		ImGui.Text(STR(self.widgetDataArr[i].text))
		ImGui.PopTextWrapPos()
		ImGui.EndVertical()
		ImGui.EndGroup()

		if ImGui.BeginDragDropSource(ImGuiDragDropFlags_SourceAllowNullID) then
        	ImGui.SetDragDropPayload("DRAG_MOVE_WIDGET", self.widgetDataArr[i].text, #self.widgetDataArr[i].text)
        	self:drawDragWidget(self.widgetDataArr[i])
        	self.cache_drag_item = self.widgetDataArr[i]
        	ImGui.EndDragDropSource()
    	end

		ImGui.EndChild()

		self.widgetDataArr[i].isDrawBGRectTag = ImGui.IsItemHovered(ImGuiHoveredFlags_AllowWhenBlockedByActiveItem)

		last_button_x2 = ImGui.GetItemRectMax().x
		next_button_x2 = last_button_x2 + style.ItemSpacing.x + widget_size.x;
		if i < count and next_button_x2 < window_visible_x2 then
			ImGui.SameLine()
		end
	end
	ImGui.EndChild()
end

function WidgetContent:getWidgetCount()
	return #self.widgetDataArr
end

function WidgetContent:drawDragWidget(widgetData)
	ImGui.Image(widgetData.icon, icon_size)
	ImGui.PushTextWrapPos(ImGui.GetCursorPos().x + widget_size.x)
	ImGui.Text(STR(widgetData.text))
	ImGui.PopTextWrapPos()
end

function WidgetContent:canRemove()
	return false
end

function WidgetContent:canClose()
	return false
end

return WidgetContent