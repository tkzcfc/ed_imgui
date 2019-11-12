local CellBase = require("app.cell.CellBase")
local WidgetBaseCell = class("WidgetBaseCell", CellBase)


WidgetBaseCell.PointColor = cc.c4f(1.0, 1.0, 1.0, 1.0)
WidgetBaseCell.LineColor = cc.c4f(0, 0.1, 1.0, 0.5)

function WidgetBaseCell:ctor(context)
	WidgetBaseCell.super.ctor(self, context)
	self.name = self:getTypeName() .. "_" .. tostring(context:getUniqueID())
end

function WidgetBaseCell:onMouseScroll(event)
    if _MyG.KeyboardStateMng:haskeyCodePressed() then
        if _MyG.KeyboardStateMng:keyCodeIsPressed(77) then     --按下键盘数字1,改变尺寸
            self:override_ChangeCellSzie(-event:getScrollY() * 10, -event:getScrollY() * 10)
        elseif _MyG.KeyboardStateMng:keyCodeIsPressed(78) then --按下键盘数字2，改变缩放
            self:override_ChangeCellScale(-event:getScrollY() * 0.1)
        elseif _MyG.KeyboardStateMng:keyCodeIsPressed(79) then --按下键盘数字3，改变旋转
            self:override_ChangeCellRotation(-event:getScrollY() * 5)
        end
        return true
    end
    return false
end

function WidgetBaseCell:onTouchBegin(touch, event)
	return true
end

function WidgetBaseCell:onTouchMove(touch, event)
	local curLocation = touch:getLocation()
	local preLocation = touch:getPreviousLocation()

    local appendX = ((curLocation.x - preLocation.x) / self.context.rootNode:getScale())
    local appendY = ((curLocation.y - preLocation.y) / self.context.rootNode:getScale())
    self:override_ChangeCellPosition(appendX, appendY)

	return true
end

function WidgetBaseCell:onTouchEnd(touch, event)
	return true
end

function WidgetBaseCell:setRenderNode(renderNode)
	self.renderNode = renderNode
    self.renderNode.cell = self
    self:setName(self.name)
end

function CellBase:isNode()
	return true
end

-- 聚焦
function WidgetBaseCell:onFocus()
	self:updateDrawBase()
	if self.drawBaseNode then
		self.drawBaseNode:setVisible(true)
	end
end

-- 失焦
function WidgetBaseCell:onLoseFocus()
	if self.drawBaseNode then
		self.drawBaseNode:setVisible(false)
	end
end

function WidgetBaseCell:updateDrawBase()
	if self.renderNode == nil then
		return
	end
	if self.drawBaseNode == nil then
		self.drawBaseNode = cc.DrawNode:create()
		self.drawBaseNode:setAnchorPoint(cc.p(0, 0))
		self.drawBaseNode:setPosition(0, 0)
		self.renderNode:addChild(self.drawBaseNode, 0xffff)
	end

	local anchorPoint = self.renderNode:getAnchorPoint()
	local size = self.renderNode:getContentSize()

	self.drawBaseNode:clear()
	self.drawBaseNode:drawPoint(cc.p(size.width * anchorPoint.x, size.height * anchorPoint.y), 5, WidgetBaseCell.PointColor)
	self.drawBaseNode:drawRect(cc.p(0, 0), cc.p(size.width, size.height), WidgetBaseCell.LineColor)
end

function WidgetBaseCell:override_ChangeCellSzie(appendValue)
	if self.renderNode then
		local size = self.renderNode:getContentSize()
		size.width = size.width + appendValue
		size.height = size.height + appendValue
		self.renderNode:setContentSize(size)
        self:updateDrawBase()
        self:dataDirty()
	end
end

function WidgetBaseCell:override_ChangeCellScale(appendValue)
	if self.renderNode then
		local scaleX = self.renderNode:getScaleX()
    	local scaleY = self.renderNode:getScaleY()
    	scaleX = scaleX + appendValue
    	scaleY = scaleY + appendValue
    	self.renderNode:setScaleX(scaleX)
    	self.renderNode:setScaleY(scaleY)
        self:dataDirty()
	end
end

function WidgetBaseCell:override_ChangeCellRotation(appendValue)
	if self.renderNode then
    	local curScale = self.renderNode:getRotation()
    	curScale = curScale + appendValue
    	self.renderNode:setRotation(curScale)
        self:dataDirty()
	end
end

function WidgetBaseCell:override_ChangeCellPosition(appendValueX, appendValueY)
	if self.renderNode then
    	local posx = self.renderNode:getPositionX()
    	local posy = self.renderNode:getPositionY()
		posx = posx + appendValueX
    	posy = posy + appendValueY
    	self.renderNode:setPosition(posx, posy)
        self:dataDirty()
	end
end







function WidgetBaseCell:setName(name)
	self.name = name
    if self.renderNode then
        self.renderNode:setName(name)
    end
end

function WidgetBaseCell:getName()
	return self.name
end

function WidgetBaseCell:getTypeName()
	return "WidgetBaseCell"
end

function WidgetBaseCell:getPosition()
    if self.renderNode == nil then
        return 0, 0
    end
    return self.renderNode:getPosition()
end

function WidgetBaseCell:getPositionX()
    if self.renderNode == nil then
        return 0
    end
    return self.renderNode:getPositionX()
end

function WidgetBaseCell:getPositionY()
    if self.renderNode == nil then
        return 0
    end
    return self.renderNode:getPositionY()
end

function WidgetBaseCell:setPosition(posx, posy)
    if self.renderNode then
        self.renderNode:setPosition(posx, posy)
    end
end

local retTmp
local tmpTabNumArr = {}

function WidgetBaseCell:onGUI()
	ImGui.Text(self:getTypeName())
	retTmp, self.name = Tools:imgui_inputText(STR("EA_NAME"), self.name, 32)
    if retTmp then
        self:setName(self.name)
        self.context:onNodeChange()
    end
	ImGui.Separator()

	if self.renderNode and ImGui.CollapsingHeader(STR("EA_BASE_ATTR"), ImGuiTreeNodeFlags_DefaultOpen) then
		self:onGUI_Base()
	end
end

function WidgetBaseCell:onGUI_Base()
	local anchorPoint = self.renderNode:getAnchorPoint()
	local positionx, positiony = self.renderNode:getPosition()
	local size = self.renderNode:getContentSize()
	local rotation = self.renderNode:getRotation()

    tmpTabNumArr[1] = anchorPoint.x
    tmpTabNumArr[2] = anchorPoint.y
    if ImGui.DragFloat2(STR("EA_ANC"), tmpTabNumArr, 0.05) then

    	local prepos = {}
    	prepos.x = positionx - size.width * anchorPoint.x
    	prepos.y = positiony - size.height * anchorPoint.y

    	anchorPoint.x = tmpTabNumArr[1]
    	anchorPoint.y = tmpTabNumArr[2]

    	local newposx = prepos.x + size.width * anchorPoint.x
    	local newposy = prepos.y + size.height * anchorPoint.y

    	self.renderNode:setAnchorPoint(anchorPoint)
    	self.renderNode:setPosition(newposx, newposy)
    	self:updateDrawBase()
        self:dataDirty()
    end

    tmpTabNumArr[1] = positionx
    tmpTabNumArr[2] = positiony
    if ImGui.DragFloat2(STR("EA_POS"), tmpTabNumArr, 1) then
    	self.renderNode:setPosition(tmpTabNumArr[1], tmpTabNumArr[2])
        self:dataDirty()
    end

    tmpTabNumArr[1] = size.width
    tmpTabNumArr[2] = size.height
    if self:bool_can_edit_size() then
        if ImGui.DragFloat2(STR("EA_SIZE"), tmpTabNumArr, 1) then
	        size.width = tmpTabNumArr[1]
        	size.height = tmpTabNumArr[2]
        	self.renderNode:setContentSize(size)
        	self:updateDrawBase()
            self:dataDirty()
        end
    else
        ImGui.InputFloat2(STR("EA_SIZE"), tmpTabNumArr, "%.3f", ImGuiInputTextFlags_ReadOnly)
    end

	tmpTabNumArr[1] = self.renderNode:getScaleX()
    tmpTabNumArr[2] = self.renderNode:getScaleY()
    if ImGui.DragFloat2(STR("EA_SCALE"), tmpTabNumArr, 0.05) then
    	self.renderNode:setScaleX(tmpTabNumArr[1])
    	self.renderNode:setScaleY(tmpTabNumArr[2])
        self:dataDirty()
    end

    retTmp, rotation = ImGui.DragFloat(STR("EA_ROTATION"), rotation, 1)
    if retTmp then
    	self.renderNode:setRotation(rotation)
        self:dataDirty()
    end

    local opacity = self.renderNode:getOpacity()
    retTmp, opacity = ImGui.SliderInt(STR("EA_OPACITY"), opacity, 0, 255)
    if retTmp then
    	self.renderNode:setOpacity(opacity)
        self:dataDirty()
    end

    opacity = self.renderNode:getLocalZOrder()
    retTmp, opacity = ImGui.DragInt(STR("EA_Z_ORDER"), opacity, 1)
    if retTmp then
        self.renderNode:setLocalZOrder(opacity)
        self:dataDirty()
    end

    local color = self.renderNode:getColor()
    tmpTabNumArr[1] = color.r / 255
    tmpTabNumArr[2] = color.g / 255
    tmpTabNumArr[3] = color.b / 255
    if ImGui.ColorEdit3(STR("EA_COLOR"), tmpTabNumArr) then
    	color.r = tmpTabNumArr[1] * 255
    	color.g = tmpTabNumArr[2] * 255
    	color.b = tmpTabNumArr[3] * 255
    	self.renderNode:setColor(color)
        self:dataDirty()
    end

    -- local isVisible = self.renderNode:isVisible()
    -- retTmp, isVisible = ImGui.Checkbox("checkbox", isVisible)
    -- if retTmp then
    -- 	self.renderNode:setVisible(isVisible)
        -- self:dataDirty()
    -- end
end

function WidgetBaseCell:bool_can_edit_size()
    return true
end

function WidgetBaseCell:onAdd()
	self.context.rootNode:addChild(self.renderNode)
end

function WidgetBaseCell:onRemove()
    if tolua.isnull(self.renderNode) then
        print("self.renderNode = nil", self.name)
    else
	   self.renderNode:removeFromParent()
    end
    self.renderNode.cell = nil
    self.renderNode = nil
    print("onRemove", self.name)
    WidgetBaseCell.super.onRemove(self)
end

function WidgetBaseCell:serialize()
end

function WidgetBaseCell:getCocosParentNodeVarName()
    local parent = self.renderNode:getParent()

    if parent.cell then
        return parent.cell:getCocosNodeVarName()
    else
        return parent:getName()
    end
end

function WidgetBaseCell:getCocosNodeVarName()
    if self:getTypeName() == "CocostudioFile" then
        return self.name .. ".root"
    end
    return self.name
end

-- 反序列化
function WidgetBaseCell:deserialize(data)
end

-- 发布
function WidgetBaseCell:publish()
    local anchorPoint = self.renderNode:getAnchorPoint()
    local positionx, positiony = self.renderNode:getPosition()
    local size = self.renderNode:getContentSize()
    local rotation = self.renderNode:getRotation()
    local zOrder = self.renderNode:getLocalZOrder()
    local scaleX = self.renderNode:getScaleX()
    local scaleY = self.renderNode:getScaleY()
    local opacity = self.renderNode:getOpacity()
    local color = self.renderNode:getColor()
    local parentName = self:getCocosParentNodeVarName()

    local output = ""
    output = output .. string.format("%s:setName(%q)\n", self.name, self.name)
    output = output .. string.format("%s:setAnchorPoint(cc.p(%.02f, %.02f))\n", self.name, anchorPoint.x, anchorPoint.y)
    output = output .. string.format("%s:setPosition(%.02f, %.02f)\n", self.name, positionx, positiony)
    output = output .. string.format("%s:setContentSize(cc.size(%.02f, %.02f))\n", self.name, size.width, size.height)

    if rotation ~= 0.0 then
        output = output .. string.format("%s:setRotation(%.02f)\n", self.name, rotation)
    end

    if zOrder ~= 0 then
        output = output .. string.format("%s:setLocalZOrder(%d)\n", self.name, zOrder)
    end

    if scaleX ~= 1.0 then
        output = output .. string.format("%s:setScaleX(%.02f)\n", self.name, scaleX)
    end

    if scaleY ~= 1.0 then
        output = output .. string.format("%s:setScaleY(%.02f)\n", self.name, scaleY)
    end

    if opacity ~= 255 then
        output = output .. string.format("%s:setOpacity(%d)\n", self.name, opacity)
    end

    if color.r ~= 255 or color.g ~= 255 or color.b ~= 255 then
        output = output .. string.format("%s:setColor(cc.c3b(%d,%d,%d))\n", self.name, color.r, color.g, color.b)
    end

    if self.context.__cname == "LayerEditContext" and parentName == G_ROOT_NODE_NAME then
        output = output .. string.format("%s.boxData = %s\n", self.name, format_lua_value(self:getBox()))
    end

    output = output .. string.format("%s:addChild(%s)\n", parentName, self.name)

    return output
end

local zeroPos = cc.p(0, 0)

-- 获取碰撞矩形
function WidgetBaseCell:getBox()
    if self.renderNode == nil then
        return WidgetCell.super.getBox(self)
    end

    local anchorPoint = self.renderNode:getAnchorPoint()
    local positionx, positiony = self.renderNode:getPosition()
    local size = self.renderNode:getContentSize()

    local rect = CRect:new_local()
    rect:setAnchorPoint(anchorPoint.x, anchorPoint.y)
    rect:setContentSize(size.width, size.height)
    rect:setPoint(positionx, positiony)
    rect:setScale(self.renderNode:getScaleX(), self.renderNode:getScaleY())
    rect:setRotation(self.renderNode:getRotation())
    rect:apply()

    local p1 = rect:getVertexByIndex(0)
    local p2 = rect:getVertexByIndex(1)
    local p3 = rect:getVertexByIndex(2)
    local p4 = rect:getVertexByIndex(3)

    local minPos = {}
    local maxPos = {}

    local function del_pos(pos)
        minPos.x = math.min(minPos.x, pos.x)
        minPos.y = math.min(minPos.y, pos.y)
        maxPos.x = math.max(maxPos.x, pos.x)
        maxPos.y = math.max(maxPos.y, pos.y)
    end

    minPos = cc.p(p1.x, p1.y)
    maxPos = cc.p(p1.x, p1.y)

    del_pos(p2)
    del_pos(p3)
    del_pos(p4)

    return cc.rect(minPos.x, minPos.y, maxPos.x - minPos.x, maxPos.y - minPos.y)
end

return WidgetBaseCell