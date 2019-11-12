local CellBase = require("app.cell.CellBase")
local BackgroundCell = class("BackgroundCell", CellBase)

function BackgroundCell:ctor(context)
	BackgroundCell.super.ctor(self, context)
end

function BackgroundCell:onMouseScroll(event)
	local pos = cc.p(event:getCursorX(), event:getCursorY())
    --没有按键按下，进行整体缩放
    if not _MyG.KeyboardStateMng:haskeyCodePressed() then
        local convertpos = self.rootNode:convertToNodeSpace(pos)
    
        local oldscale = self.rootNode:getScale()
        local scale = oldscale - event:getScrollY() * 0.1
        scale = math.max(scale, 0.1)
        scale = math.min(scale, 3.0)
        self.rootNode:setScale(scale)
    
        local moveScale = scale - oldscale
        self.rootNode:setPositionX(self.rootNode:getPositionX() - convertpos.x * moveScale)
        self.rootNode:setPositionY(self.rootNode:getPositionY() - convertpos.y * moveScale)

        self.helpInfo_NodeScaleLabel:setString(string.format("%.1f", scale))
        self:dataDirty()
    end
end

function BackgroundCell:onMouseDown(event)
    self.isMouseDown = true
    if event:getMouseButton() == 2 then
        self.enableMoveRootNode = true
    end

    if self.movePrePos then
        self.movePrePos.x = event:getCursorX()
        self.movePrePos.y = event:getCursorY()
    else
        self.movePrePos = cc.p(event:getCursorX(), event:getCursorY())
    end
end

function BackgroundCell:onMouseMove(event)
	-- 中键按住拖动屏幕
 	if event:getMouseButton() == 2 then
        if self.enableMoveRootNode and self.movePrePos then
            local newposx = self.rootNode:getPositionX()
            local newposy = self.rootNode:getPositionY()
            newposx = newposx + (event:getCursorX() - self.movePrePos.x)
            newposy = newposy + (event:getCursorY() - self.movePrePos.y)
            self.rootNode:setPosition(newposx, newposy)
            self:dataDirty()
        end
    end
    if self.movePrePos then
    	self.movePrePos.x = event:getCursorX()
    	self.movePrePos.y = event:getCursorY()
    else
    	self.movePrePos = cc.p(event:getCursorX(), event:getCursorY())
	end

    local convertpos = self.rootNode:convertToNodeSpace(self.movePrePos)
    self.helpInfo_MousePosLabel:setString(string.format("(%d,%d)", convertpos.x, convertpos.y))
end

function BackgroundCell:onMouseUp(event)
	self.isMouseDown = false
    if event:getMouseButton() == 2 then
        self.enableMoveRootNode = true
    end
end

function BackgroundCell:onTouchMove(touch, event)
    local convertpos = self.rootNode:convertToNodeSpace(touch:getLocation())
    self.helpInfo_MousePosLabel:setString(string.format("(%d,%d)", convertpos.x, convertpos.y))
end

function BackgroundCell:onAdd()
    self.rootNode = self.context.rootNode

    -- 信息显示
    local label
    label = cc.Label:create()
    label:setSystemFontSize(22)
    label:setTextColor(cc.c3b(0xf3, 0xd3, 0x65))
    label:setAnchorPoint(cc.p(0, 0))
    label:setPosition(cc.p(20, 50))
    self.context.bgNode:addChild(label)
    self.helpInfo_MousePosLabel = label

    label = cc.Label:create()
    label:setSystemFontSize(22)
    label:setTextColor(cc.c3b(0xf3, 0xd3, 0x65))
    label:setAnchorPoint(cc.p(0, 0))
    label:setPosition(cc.p(20, 20))
    self.context.bgNode:addChild(label)
    self.helpInfo_NodeScaleLabel = label

    self.helpInfo_NodeScaleLabel:setString(string.format("%.1f", self.rootNode:getScale()))
end

-- 序列化
function BackgroundCell:serialize()
    local posx, posy = self.rootNode:getPosition()

    local t = {}
    t.posx = posx
    t.posy = posy
    t.scale = self.rootNode:getScale()
    return t
end

-- 发序列化
function BackgroundCell:deserialize(data)
    if data == nil then
        return
    end
    self.rootNode:setPosition(data.posx, data.posy)
    self.rootNode:setScale(data.scale)    
    self.helpInfo_NodeScaleLabel:setString(string.format("%.1f", self.rootNode:getScale()))
end

-- 发布
function BackgroundCell:publish()
    local t = {}
    t.referenceResources = self:getReferenceResources()
    return t
end

function BackgroundCell:getReferenceResources()
    local res_boolMap = {}
    local res = {}
    local tmp

    for k,v in pairs(self.context.cells) do
        tmp = v:getReferenceResources()
        if tmp then
            for k,v in pairs(tmp) do
                if not res_boolMap[v] then
                    table.insert(res, v)
                end
                res_boolMap[v] = true
            end
        end
    end

    return res
end


return BackgroundCell
