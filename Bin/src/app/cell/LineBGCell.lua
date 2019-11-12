local BackgroundCell = require("app.cell.BackgroundCell")
local LineBGCell = class("LineBGCell", BackgroundCell)


local CurEditLineColor = cc.c4f(1.0, 0, 0, 1.0)
local CurEditLineColor_UINT = IM_COL32(255, 0, 0, 255)
local LineColor_UINT = IM_COL32(0, 255, 0, 255)

local RectColor_UINT = IM_COL32(231, 86, 34, 255)

function LineBGCell:ctor(context)
	LineBGCell.super.ctor(self, context)

	self.lines = {}
	self.rects = {}
	self.lineDirty = true
	self.rectDirty = true
end

function LineBGCell:onGUI()
    self:updateDrawLine()
    self:updateDrawRect()
    self:onGUI_Lines()
    self:onGUI_Rects()
end

local vec2_tmp = {}
local node_flags = Tools:bor_int32(ImGuiTreeNodeFlags_OpenOnArrow, ImGuiTreeNodeFlags_OpenOnDoubleClick)

function LineBGCell:onGUI_Lines()
    if not ImGui.CollapsingHeader(STR("EA_LINES"), ImGuiTreeNodeFlags_DefaultOpen) then
    	return
    end

    local lineDirty = false
    local name, deleteLineKey, editLineKey, tmp_ret, deletePointIndex
    for k, v in pairs(self.lines) do
    	name = tostring(k) .. "##Line"
    	if ImGui.TreeNodeEx(name, node_flags, tostring(k)) then
    		
    		deletePointIndex = nil

    		local pointCount = v:getPointCount()
    		for i = 0, pointCount - 1 do
    			local pos = v:getPointByIndex(i)
    			vec2_tmp[1] = pos.x
    			vec2_tmp[2] = pos.y
    			if ImGui.DragFloat2(tostring(i), vec2_tmp, 1) then
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
    			v:removePointByIndex(deletePointIndex)
    			lineDirty = true
    		end

    		local boolValue = v:isLeftNormal()
    		tmp_ret, boolValue = ImGui.Checkbox(STR("EA_IS_LEFT"), boolValue)
    		if tmp_ret then
    			v:setNormalLeft(boolValue)
    			lineDirty = true
    		end

    		boolValue = v:isVisible()
			tmp_ret, boolValue = ImGui.Checkbox(STR("EA_IS_VISIBLE"), boolValue)
    		if tmp_ret then
    			v:setVisible(boolValue)
    			lineDirty = true
    		end

    		if ImGui.Button(STR("EA_EDIT")) then
    			editLineKey = k
    			lineDirty = true
    		end

    		if ImGui.Button(STR("EA_DELETE")) then
    			deleteLineKey = k
    			lineDirty = true
    		end

    		ImGui.TreePop()
		end
	end

	if deleteLineKey then
		table.remove(self.lines, deleteLineKey)
	end

	if ImGui.Button(STR("EA_CREATE") .. "##Line") then
		self:editFinish()
		self.curEditLine = CLine:new_local()
		self.curEditLine:setLineCorlor(CurEditLineColor_UINT)

		self.context:disenableAllCellTouch()
	end

	if editLineKey then
		if self.curEditLine ~= self.lines[editLineKey] then
			self:editFinish()
			self.curEditLine = self.lines[editLineKey]
			self.curEditLine:setLineCorlor(CurEditLineColor_UINT)
			self.curEditLine:setVisible(true)
			table.remove(self.lines, editLineKey)

			self:updateCurEditDrawLine()

			self.context:disenableAllCellTouch()
		end
	end

	self.lineDirty = lineDirty

	if lineDirty then
		self:dataDirty()
	end
end

function LineBGCell:onGUI_Rects()
    if not ImGui.CollapsingHeader(STR("EA_RECTS"), ImGuiTreeNodeFlags_DefaultOpen) then
    	return
    end

    local name, vec2Value, rectDirty, retTmp, deleteRectKey
    for k,v in pairs(self.rects) do
    	name = tostring(k) .. "##Rect"
    	if ImGui.TreeNodeEx(name, node_flags, tostring(k)) then

    		vec2Value = v:getPoint()
    		vec2_tmp[1] = vec2Value.x
    		vec2_tmp[2] = vec2Value.y
    		if ImGui.DragFloat2(STR("EA_POS"), vec2_tmp, 1) then
    			rectDirty = true
    			v:setPoint(vec2_tmp[1], vec2_tmp[2])
    		end

    		vec2Value = v:getAnchorPoint()
    		vec2_tmp[1] = vec2Value.x
    		vec2_tmp[2] = vec2Value.y
    		if ImGui.DragFloat2(STR("EA_ANC"), vec2_tmp, 0.05) then
    			rectDirty = true
    			v:setAnchorPoint(vec2_tmp[1], vec2_tmp[2])
    		end

    		vec2Value = v:getContentSize()
    		vec2_tmp[1] = vec2Value.x
    		vec2_tmp[2] = vec2Value.y
    		if ImGui.DragFloat2(STR("EA_SIZE"), vec2_tmp, 1) then
    			rectDirty = true
    			v:setContentSize(vec2_tmp[1], vec2_tmp[2])
    		end

    		vec2Value = v:getScale()
    		vec2_tmp[1] = vec2Value.x
    		vec2_tmp[2] = vec2Value.y
    		if ImGui.DragFloat2(STR("EA_SCALE"), vec2_tmp, 0.1) then
    			rectDirty = true
    			v:setScale(vec2_tmp[1], vec2_tmp[2])
    		end

    		vec2Value = v:getSkew()

    		retTmp, vec2Value.x = ImGui.DragFloat(STR("EA_SKEW_X"), vec2Value.x, 1)
    		if retTmp then
    			rectDirty = true
    			v:setSkewX(vec2Value.x)
    		end

    		retTmp, vec2Value.y = ImGui.DragFloat(STR("EA_SKEW_Y"), vec2Value.y, 1)
    		if retTmp then
    			rectDirty = true
    			v:setSkewY(vec2Value.y)
    		end

    		vec2Value = v:getRotation()
    		retTmp, vec2Value = ImGui.DragFloat(STR("EA_ROTATION"), vec2Value, 1)
    		if retTmp then
    			rectDirty = true
    			v:setRotation(vec2Value)
    		end

    		vec2Value = v:isVisible()
			retTmp, vec2Value = ImGui.Checkbox(STR("EA_IS_VISIBLE"), vec2Value)
    		if retTmp then
    			v:setVisible(vec2Value)
    			rectDirty = true
    		end

			if ImGui.Button(STR("EA_DELETE")) then
    			deleteRectKey = k
    			rectDirty = true
    		end

    		ImGui.TreePop()
		end
    end

	if ImGui.Button(STR("EA_CREATE") .. "##Rect") then
		self:editFinish()
		self.curEditRectData = {}
		self.context:disenableAllCellTouch()
	end

    if deleteRectKey then
    	table.remove(self.rects, deleteRectKey)
    end

    self.rectDirty = rectDirty

	if rectDirty then
		self:dataDirty()
	end
end

function LineBGCell:editFinish()
	self:editLineFinish()
	self:editRectFinish()
end

function LineBGCell:editLineFinish()
	if self.curEditLine then
		if self.curEditLine:getPointCount() >= 2 then
			self.curEditLine:setLineCorlor(LineColor_UINT)
			table.insert(self.lines, self.curEditLine)
			self:dataDirty()
		end
		self.curEditLine = nil
		self.lineDirty = true
		self:updateCurEditDrawLine()
	end

	self.context:enableAllCellTouch()
end

function LineBGCell:editRectFinish()
	if self.curEditRectData then
		if self.curEditRectData.beginpos and self.curEditRectData.endpos then
			local w = math.abs(self.curEditRectData.endpos.x - self.curEditRectData.beginpos.x)
			local h = math.abs(self.curEditRectData.endpos.y - self.curEditRectData.beginpos.y)
			if w > 5 and h > 5 then
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
				self.rectDirty = true
				self:dataDirty()
			end
		end
		self.curEditRectData = nil
	end
	self:updateCurEditDrawRect()

	self.context:enableAllCellTouch()
end

function LineBGCell:onAdd()
	LineBGCell.super.onAdd(self)

	local function createDrawNode()
		local drawNode = cc.DrawNode:create()
		drawNode:setAnchorPoint(cc.p(0, 0))
		drawNode:setPosition(0, 0)
		self.rootNode:addChild(drawNode, 0xffffff)
		return drawNode
	end

	self.drawLineNode = createDrawNode()
	self.drawCurEditLineNode = createDrawNode()
	self.drawRectNode = createDrawNode()
	self.drawCurEditRectNode = createDrawNode()
end

function LineBGCell:updateDrawLine()
	if not self.lineDirty then
		return
	end
	self.lineDirty = false
	self.drawLineNode:clear()
	for k,v in pairs(self.lines) do
		v:debugDraw(self.drawLineNode)
	end
end

function LineBGCell:updateCurEditDrawLine(newPoint)
	self.drawCurEditLineNode:clear()
	if self.curEditLine == nil then
		return
	end

	self.curEditLine:debugDraw(self.drawCurEditLineNode, true)

	if newPoint and self.curEditLine:getPointCount() > 0 then
		self.drawCurEditLineNode:drawLine(self.curEditLine:getLastPoint(), newPoint, CurEditLineColor)
	end
end

function LineBGCell:updateDrawRect()
	if not self.rectDirty then
		return
	end
	self.rectDirty = false

	self.drawRectNode:clear()
	for k,v in pairs(self.rects) do
		v:debugDraw(self.drawRectNode)
	end
end

function LineBGCell:updateCurEditDrawRect()
	self.drawCurEditRectNode:clear()

	if self.curEditRectData == nil then
		return
	end

	if self.curEditRectData.beginpos and self.curEditRectData.endpos then
		self.drawCurEditRectNode:drawRect(self.curEditRectData.beginpos, self.curEditRectData.endpos, CurEditLineColor)
	end
end

function LineBGCell:onMouseDown(event)
	LineBGCell.super.onMouseDown(self, event)
	-- 右键按下
	if event:getMouseButton() == 1 then
		self:editFinish()
	end
end

function LineBGCell:onMouseMove(event)
	LineBGCell.super.onMouseMove(self, event)
	
	if self.curEditLine then
		local convertpos = self.rootNode:convertToNodeSpace(cc.p(event:getCursorX(), event:getCursorY()))
		self:updateCurEditDrawLine(convertpos)
	end
end

function LineBGCell:onTouchBegin(touch, event)
	-- 快速编辑矩形按键
	if _MyG.KeyboardStateMng:keyCodeIsPressed(cc.KeyCode.KEY_SHIFT) then
		self:editFinish()
		self.curEditRectData = {}
	end

	if self.curEditRectData then
		self.curEditRectData.beginpos = self.rootNode:convertToNodeSpace(touch:getLocation())
	end
end

function LineBGCell:onTouchMove(touch, event)
	LineBGCell.super.onTouchMove(self, touch, event)
	if self.curEditRectData then
		self.curEditRectData.endpos = self.rootNode:convertToNodeSpace(touch:getLocation())
		self:updateCurEditDrawRect()
	end
end

function LineBGCell:onTouchEnd(touch, event)
	if self.curEditLine then
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
function LineBGCell:serialize()
	local output = LineBGCell.super.serialize(self)

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

	return output
end

-- 发序列化
function LineBGCell:deserialize(data)
	if data == nil then
		return
	end
	LineBGCell.super.deserialize(self, data)

	for k,v in pairs(data.line_data) do
		local line = CLine:new_local()
		line:deserialize(v)
		table.insert(self.lines, line)
	end

	for k,v in pairs(data.rect_data) do
		local rect = CRect:new_local()
		rect:deserialize(v)
		table.insert(self.rects, rect)
	end

	self.lineDirty = true
	self.rectDirty = true
end

-- 发布
function LineBGCell:publish()
	local output = LineBGCell.super.publish(self)

	local line_data = {}
	for k,v in pairs(self.lines) do
		table.insert(line_data, v:publish())
	end

	local rect_data = {}
	for k,v in pairs(self.rects) do
		table.insert(rect_data, v:publish())
	end

	output["line_data"] = line_data
	output["rect_data"] = rect_data

	return output
end

return LineBGCell
