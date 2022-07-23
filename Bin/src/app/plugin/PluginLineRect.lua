-- @Author: fangcheng
-- @Date:   2020-05-05 16:25:29
-- @Description: 编辑矩形以及线段

local Plugin = import(".Plugin")
local PluginLineRect = class("PluginLineRect", Plugin)



local CurEditLineColor = cc.c4f(1.0, 0, 0, 1.0)
local CurEditLineColor_UINT = IM_COL32(255, 0, 0, 255)
local LineColor_UINT = IM_COL32(0, 255, 0, 255)
local RectColor_UINT = IM_COL32(231, 86, 34, 255)

function PluginLineRect:ctor()
	PluginLineRect.super.ctor(self)

	self.isShowLine = true
	self.isShowRect = true

	self.onLineRectUserdataValueChange = function()
		self:onAttributeChange(EditorEvent.ON_CHANGE_LINE_RECT_USERDATA)
	end
end

-- @brief 是否阻断元素的Touch事件
function PluginLineRect:isBlockEleTouchEvent()
	if PluginLineRect.super.isBlockEleTouchEvent(self) then
		return true
	end

	if self.editMode then
		return true
	end

    -- 按住左 shift 时拦截事件，用于快速创建矩形
    return _MyG.KeyboardStateMng:keyCodeIsPressed(cc.KeyCode.KEY_SHIFT)
end

function PluginLineRect:attach(edContext)
	PluginLineRect.super.attach(self, edContext)
	self:initRect_Line()
end

function PluginLineRect:detach()
	PluginLineRect.super.detach(self)

	if not tolua.isnull(self.drawLineNode) then
		self.drawLineNode:removeFromParent()
		self.drawLineNode = nil
	end
	if not tolua.isnull(self.drawCurEditLineNode) then
		self.drawCurEditLineNode:removeFromParent()
		self.drawCurEditLineNode = nil
	end
	if not tolua.isnull(self.drawRectNode) then
		self.drawRectNode:removeFromParent()
		self.drawRectNode = nil
	end
	if not tolua.isnull(self.drawCurEditRectNode) then
		self.drawCurEditRectNode:removeFromParent()
		self.drawCurEditRectNode = nil
	end
end

function PluginLineRect:dataDirty()
    self.lineDirty = true
    self.rectDirty = true
	self:updateDrawLine()
	self:updateDrawRect()
end

function PluginLineRect:initRect_Line()
    self.lines = {}
    self.rects = {}
    self.lineDirty = true
    self.rectDirty = true
    self.rootNode = self.context.render

    -- 矩形显示根节点
    local function createDrawNode()
        local drawNode = cc.DrawNode:create()
        drawNode:setAnchorPoint(cc.p(0, 0))
        drawNode:setPosition(0, 0)
        self.context.render:addChild(drawNode, 0xff)
        return drawNode
    end

    self.drawLineNode = createDrawNode()
    self.drawCurEditLineNode = createDrawNode()
    self.drawRectNode = createDrawNode()
    self.drawCurEditRectNode = createDrawNode()
end


function PluginLineRect:onAttributeGUI()
    self.drawLineNode:setVisible(self.isShowLine)
    self.drawRectNode:setVisible(self.isShowRect)
    self:updateDrawLine()
    self:updateDrawRect()
    self:onGUI_Lines()
    self:onGUI_Rects()

	local boolValue, tmp_ret = self.isShowLine
	tmp_ret, boolValue = ImGui.Checkbox(STR("EA_IS_VISIBLE_LINE"), boolValue)
	if tmp_ret then
		self:onAttributeChange(EditorEvent.ON_CHANGE_LINE_VISIBLE)
	    self.isShowLine = boolValue
	end

	local boolValue, tmp_ret = self.isShowRect
	tmp_ret, boolValue = ImGui.Checkbox(STR("EA_IS_VISIBLE_RECT"), boolValue)
	if tmp_ret then
		self:onAttributeChange(EditorEvent.ON_CHANGE_RECT_VISIBLE)
	    self.isShowRect = boolValue
	end
end

local vec2_tmp = {}
local node_flags = Tools:bor_int32(ImGuiTreeNodeFlags_OpenOnArrow, ImGuiTreeNodeFlags_OpenOnDoubleClick)

function PluginLineRect:onGUI_Lines()
	if ImGui.TreeNode(STR("EA_LINES")) then
		local lineDirty = false
		local name, deleteLineKey, editLineKey, tmp_ret, deletePointIndex
		for k, v in pairs(self.lines) do
		    name = tostring(k) .. "##Line"
			ImGui.PushID(name)
		    if ImGui.TreeNodeEx(name, node_flags, tostring(k)) then
		        
		        deletePointIndex = nil

		        local pointCount = v:getPointCount()
		        for i = 0, pointCount - 1 do
		            local pos = v:getPointByIndex(i)
		            vec2_tmp[1] = pos.x
		            vec2_tmp[2] = pos.y
		            if ImGui.DragFloat2(tostring(i), vec2_tmp, 1) then
    					self:onAttributeChange(EditorEvent.ON_CHANGE_LINE_DATA)
		                lineDirty = true
		                v:setPointDataByIndex(i, vec2_tmp[1], vec2_tmp[2])
		            end

		            if pointCount > 2 then
		                ImGui.SameLine()
		                if ImGui.Button(string.format("x##%d", i)) then
		                    deletePointIndex = i
		                end
		            end
		        end

		        if deletePointIndex then
					self:onAttributeChange(EditorEvent.ON_CHANGE_LINE_DATA)
		            v:removePointByIndex(deletePointIndex)
		            lineDirty = true
		        end

		        local boolValue = v:isLeftNormal()
		        tmp_ret, boolValue = ImGui.Checkbox(STR("EA_IS_LEFT"), boolValue)
		        if tmp_ret then
					self:onAttributeChange(EditorEvent.ON_CHANGE_LINE_DATA)
		            v:setNormalLeft(boolValue)
		            lineDirty = true
		        end

		        boolValue = v:isVisible()
		        tmp_ret, boolValue = ImGui.Checkbox(STR("EA_IS_VISIBLE"), boolValue)
		        if tmp_ret then
					self:onAttributeChange(EditorEvent.ON_CHANGE_LINE_DATA)
		            v:setVisible(boolValue)
		            lineDirty = true
		        end

		        -- userdata
		        -- ImGui.Indent()
				ImGui.NewLine()
		        _MyG.Functions:onGUI_UserData(v, self.onLineRectUserdataValueChange)
				ImGui.NewLine()
		        -- ImGui.Unindent()

		        if ImGui.Button(STR("EA_EDIT")) then
		            editLineKey = k
		            lineDirty = true
		        end

		        if ImGui.Button(STR("EA_DELETE")) then
					self:onAttributeChange(EditorEvent.ON_CHANGE_LINE_DATA)
		            deleteLineKey = k
		            lineDirty = true
		        end

		        ImGui.TreePop()
		        ImGui.Separator()
		    end
		    ImGui.PopID()
		end

		if deleteLineKey then
		    table.remove(self.lines, deleteLineKey)
		end

		if ImGui.Button(STR("EA_CREATE") .. "##Line") then
		    self:editFinish()
		    self.curEditLine = CLine:new_local()
		    self.curEditLine:setLineCorlor(CurEditLineColor_UINT)

		    self.editMode = true
		    self.isShowLine = true
		    lineDirty = true
		end

		if editLineKey then
		    if self.curEditLine ~= self.lines[editLineKey] then
		    	self:editFinish()
		        self:onAttributeChange(EditorEvent.ON_CHANGE_LINE_DATA)
		        self.curEditLine = self.lines[editLineKey]
		        self.curEditLine:setLineCorlor(CurEditLineColor_UINT)
		        self.curEditLine:setVisible(true)
		        table.remove(self.lines, editLineKey)

		        self:updateCurEditDrawLine()

		    	self.editMode = true
		    	self.isShowLine = true
		    end
		end

		self.lineDirty = lineDirty

		if lineDirty then
		    self:dataDirty()
		end

		ImGui.TreePop()
		ImGui.Separator()
	end
end

function PluginLineRect:onGUI_Rects()
	if ImGui.TreeNode(STR("EA_RECTS")) then
		local name, vec2Value, rectDirty, retTmp, deleteRectKey
		for k,v in pairs(self.rects) do
		    name = tostring(k) .. "##Rect"
			ImGui.PushID(name)
		    if ImGui.TreeNodeEx(name, node_flags, tostring(k)) then

		        vec2Value = v:getPoint()
		        vec2_tmp[1] = vec2Value.x
		        vec2_tmp[2] = vec2Value.y
		        if ImGui.DragFloat2(STR("EA_POS"), vec2_tmp, 1) then
		            rectDirty = true
					self:onAttributeChange(EditorEvent.ON_CHANGE_RECT_DATA)
		            v:setPoint(vec2_tmp[1], vec2_tmp[2])
		        end

		        vec2Value = v:getAnchorPoint()
		        vec2_tmp[1] = vec2Value.x
		        vec2_tmp[2] = vec2Value.y
		        if ImGui.DragFloat2(STR("EA_ANC"), vec2_tmp, 0.05) then
		            rectDirty = true
					self:onAttributeChange(EditorEvent.ON_CHANGE_RECT_DATA)
		            v:setAnchorPoint(vec2_tmp[1], vec2_tmp[2])
		        end

		        vec2Value = v:getContentSize()
		        vec2_tmp[1] = vec2Value.x
		        vec2_tmp[2] = vec2Value.y
		        if ImGui.DragFloat2(STR("EA_SIZE"), vec2_tmp, 1) then
		            rectDirty = true
					self:onAttributeChange(EditorEvent.ON_CHANGE_RECT_DATA)
		            v:setContentSize(vec2_tmp[1], vec2_tmp[2])
		        end

		        vec2Value = v:getScale()
		        vec2_tmp[1] = vec2Value.x
		        vec2_tmp[2] = vec2Value.y
		        if ImGui.DragFloat2(STR("EA_SCALE"), vec2_tmp, 0.1) then
		            rectDirty = true
					self:onAttributeChange(EditorEvent.ON_CHANGE_RECT_DATA)
		            v:setScale(vec2_tmp[1], vec2_tmp[2])
		        end

		        vec2Value = v:getSkew()

		        retTmp, vec2Value.x = ImGui.DragFloat(STR("EA_SKEW_X"), vec2Value.x, 1)
		        if retTmp then
		            rectDirty = true
					self:onAttributeChange(EditorEvent.ON_CHANGE_RECT_DATA)
		            v:setSkewX(vec2Value.x)
		        end

		        retTmp, vec2Value.y = ImGui.DragFloat(STR("EA_SKEW_Y"), vec2Value.y, 1)
		        if retTmp then
		            rectDirty = true
					self:onAttributeChange(EditorEvent.ON_CHANGE_RECT_DATA)
		            v:setSkewY(vec2Value.y)
		        end

		        vec2Value = v:getRotation()
		        retTmp, vec2Value = ImGui.DragFloat(STR("EA_ROTATION"), vec2Value, 1)
		        if retTmp then
		            rectDirty = true
					self:onAttributeChange(EditorEvent.ON_CHANGE_RECT_DATA)
		            v:setRotation(vec2Value)
		        end

		        vec2Value = v:isVisible()
		        retTmp, vec2Value = ImGui.Checkbox(STR("EA_IS_VISIBLE"), vec2Value)
		        if retTmp then
					self:onAttributeChange(EditorEvent.ON_CHANGE_RECT_DATA)
		            v:setVisible(vec2Value)
		            rectDirty = true
		        end

		        -- userdata
		        -- ImGui.Indent()
				ImGui.NewLine()
		        _MyG.Functions:onGUI_UserData(v, self.onLineRectUserdataValueChange)
				ImGui.NewLine()
		        -- ImGui.Unindent()

		        if ImGui.Button(STR("EA_DELETE")) then
					self:onAttributeChange(EditorEvent.ON_CHANGE_RECT_DATA)
		            deleteRectKey = k
		            rectDirty = true
		        end

		        ImGui.TreePop()
		        ImGui.Separator()
		    end
			ImGui.PopID()
		end

		if ImGui.Button(STR("EA_CREATE") .. "##Rect") then
		    self:editFinish()
		    self.curEditRectData = {}
		    self.editMode = true
		    self.isShowRect = true
		end

		if deleteRectKey then
		    table.remove(self.rects, deleteRectKey)
		end

		self.rectDirty = rectDirty

		if rectDirty then
		    self:dataDirty()
		end

		ImGui.TreePop()
		ImGui.Separator()
	end
end

function PluginLineRect:editFinish(noSaveSnapshot)
	self:editLineFinish(noSaveSnapshot)
	self:editRectFinish(noSaveSnapshot)
end

function PluginLineRect:editLineFinish(noSaveSnapshot)
	if self.curEditLine then
		if self.curEditLine:getPointCount() >= 2 then
			self.curEditLine:setLineCorlor(LineColor_UINT)
			self.editMode = false
			if not noSaveSnapshot then
				self:onAttributeChange(EditorEvent.ON_CHANGE_LINE_DATA)
			end
			table.insert(self.lines, self.curEditLine)
			self:dataDirty()
		end
		self.curEditLine = nil
		self:updateCurEditDrawLine()
	end

	self.editMode = false
end

function PluginLineRect:editRectFinish(noSaveSnapshot)
	if self.curEditRectData then
		if self.curEditRectData.beginpos and self.curEditRectData.endpos then
			local w = math.abs(self.curEditRectData.endpos.x - self.curEditRectData.beginpos.x)
			local h = math.abs(self.curEditRectData.endpos.y - self.curEditRectData.beginpos.y)
			if w > 5 and h > 5 then
				self.editMode = false
				if not noSaveSnapshot then
					self:onAttributeChange(EditorEvent.ON_CHANGE_RECT_DATA)
				end
				local posx = math.min(self.curEditRectData.endpos.x, self.curEditRectData.beginpos.x)
				local posy = math.min(self.curEditRectData.endpos.y, self.curEditRectData.beginpos.y)
				local rect = CRect:new_local()

				local anchorPoint = rect:getAnchorPoint()
				posx = posx + anchorPoint.x * w
				posy = posy + anchorPoint.y * h

				rect:setPoint(posx, posy)
				rect:setContentSize(w, h)
				rect:setColor(RectColor_UINT)
				table.insert(self.rects, rect)
				self:dataDirty()
			end
		end
		self.curEditRectData = nil
	end
	self:updateCurEditDrawRect()

	self.editMode = false
end

function PluginLineRect:updateDrawLine()
	if not self.lineDirty then
		return
	end
	self.lineDirty = false
	self.drawLineNode:clear()
	for k,v in pairs(self.lines) do
		v:debugDraw(self.drawLineNode)
	end
end

function PluginLineRect:updateCurEditDrawLine(newPoint)
	self.drawCurEditLineNode:clear()
	if self.curEditLine == nil then
		return
	end

	self.curEditLine:debugDraw(self.drawCurEditLineNode, true)

	if newPoint and self.curEditLine:getPointCount() > 0 then
		self.drawCurEditLineNode:drawLine(self.curEditLine:getLastPoint(), newPoint, CurEditLineColor)
	end
end

function PluginLineRect:updateDrawRect()
	if not self.rectDirty then
		return
	end
	self.rectDirty = false

	self.drawRectNode:clear()
	for k,v in pairs(self.rects) do
		v:debugDraw(self.drawRectNode)
	end
end

function PluginLineRect:updateCurEditDrawRect()
	self.drawCurEditRectNode:clear()

	if self.curEditRectData == nil then
		return
	end

	if self.curEditRectData.beginpos and self.curEditRectData.endpos then
		self.drawCurEditRectNode:drawRect(self.curEditRectData.beginpos, self.curEditRectData.endpos, CurEditLineColor)
	end
end

function PluginLineRect:onMouseDown(event)
	-- 右键按下
	if event:getMouseButton() == 1 then
		self:editFinish()
	end
end

function PluginLineRect:onMouseMove(event)	
	if self.curEditLine then
		local convertpos = self.rootNode:convertToNodeSpace(cc.p(event:getCursorX(), event:getCursorY()))
		self:updateCurEditDrawLine(convertpos)
	end
end

function PluginLineRect:onTouchBegan(touch, event)
	-- 快速编辑矩形按键
	if _MyG.KeyboardStateMng:keyCodeIsPressed(cc.KeyCode.KEY_SHIFT) then
		self:editFinish()
		self.curEditRectData = {}
	end

	if self.curEditRectData then
		self.curEditRectData.beginpos = self.rootNode:convertToNodeSpace(touch:getLocation())
	end

	return true
end

function PluginLineRect:onTouchMoved(touch, event)
	if self.curEditRectData then
		self.isShowRect = true
		self.curEditRectData.endpos = self.rootNode:convertToNodeSpace(touch:getLocation())
		self:updateCurEditDrawRect()
	end
end

function PluginLineRect:onTouchEnded(touch, event)
	if self.curEditLine then
		self:onAttributeChange(EditorEvent.ON_CHANGE_LINE_DATA)

		local count = self.curEditLine:getPointCount()
		local convertpos = self.rootNode:convertToNodeSpace(touch:getLocation())
		self.curEditLine:setPointDataByIndex(count, convertpos.x, convertpos.y)
		self:updateCurEditDrawLine()
	end
	if self.curEditRectData then
		self.curEditRectData.endpos = self.rootNode:convertToNodeSpace(touch:getLocation())
		self:editRectFinish()
	end
end

-- 序列化
function PluginLineRect:doSerialize()
	local output = PluginLineRect.super.doSerialize(self)

	if _MyG.IsLocalizeMode then
		self:editFinish(true)
	else
		if self.curEditLine then
			local tmp = self.curEditLine:serialize()
			if #tmp.points > 1 then
				output["tmpData"] = self.curEditLine:serialize()
			end
		end
	end

	local line_data = {}
	for k,v in pairs(self.lines) do
		table.insert(line_data, v:serialize())
	end

	local rect_data = {}
	for k,v in pairs(self.rects) do
		table.insert(rect_data, v:serialize())
	end

	output["line_data"] = line_data
	output["rect_data"] = rect_data
	output["show_line"] = self.isShowLine
	output["show_rect"] = self.isShowRect

	return output
end

-- 反序列化
function PluginLineRect:doDeserialize(data)
	if not PluginLineRect.super.doDeserialize(self, data) then
		return false
	end

	self.curEditLine = nil
	self.curEditRectData = nil
	self.lineDirty = true
	self.rectDirty = true
	self:updateCurEditDrawLine()
	self:updateCurEditDrawRect()

	local pluginData = data or {}

	if pluginData.show_line == nil then
		pluginData.show_line = true
	end
	if pluginData.show_rect == nil then
		pluginData.show_rect = true
	end

	self.isShowLine = pluginData.show_line
	self.isShowRect = pluginData.show_rect
	self.lines = {}
	self.rects = {}

	for k,v in pairs(pluginData.line_data or {}) do
		local line = CLine:new_local()
		line:deserialize(v)
		table.insert(self.lines, line)
	end

	for k,v in pairs(pluginData.rect_data or {}) do
		local rect = CRect:new_local()
		rect:deserialize(v)
		table.insert(self.rects, rect)
	end

	if pluginData.tmpData then
		local line = CLine:new_local()
		line:deserialize(pluginData.tmpData)
		self.curEditLine = line
        self.curEditLine:setLineCorlor(CurEditLineColor_UINT)
        self.editMode = true

        local convertpos = self.rootNode:convertToNodeSpace(_MyG.MouseEventDispatcher:getCursorPos())
        self:updateCurEditDrawLine(convertpos)
	end

	self:dataDirty()

	return PluginLineRect.super.deserialize(self, data)
end


return PluginLineRect

