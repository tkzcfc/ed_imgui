-- 复活点

local WidgetBaseCell = require("app.cell.WidgetBaseCell")
local RevivePointCell = class("RevivePointCell", WidgetBaseCell)


function RevivePointCell:ctor(context, pos)
	RevivePointCell.super.ctor(self, context)
	self.name = self:getTypeName()

	local sprite = cc.Sprite:create("Res/gem_icon/icon_4.png")
    sprite:setAnchorPoint(0.5, 0.5)

    if pos then
    	sprite:setPosition(pos)
    end

    self:setRenderNode(sprite)
    self:bindFocusCall(sprite)
end

function RevivePointCell:onMouseScroll(event)
	-- 不接受滚动事件
    return false
end

-- 重载 bindFocusCall 函数，让 RevivePointCell 能在map中聚焦
function RevivePointCell:bindFocusCall(node, testCall)
	if testCall == nil then
		testCall = function(touch,event)
			return Tools:isInRect(node, touch:getLocation().x, touch:getLocation().y)
		end
	end

	local function onTouchBegin(touch,event)
		-- 快速编辑矩形按键
		if _MyG.KeyboardStateMng:keyCodeIsPressed(cc.KeyCode.KEY_SHIFT) then
			return
		end

		if self.disenableTouchTag then
			return false
		end
		if self.context.isVisible and not self.context.fixFocusCellTag and testCall(touch, event) then
			self.context.fixFocusCellTag = true
			self:focus()
		end
    	return false
    end

    local listener = cc.EventListenerTouchOneByOne:create()
    listener:registerScriptHandler(onTouchBegin,cc.Handler.EVENT_TOUCH_BEGAN)
    cc.Director:getInstance():getEventDispatcher():addEventListenerWithSceneGraphPriority(listener, node)
end

local retTmp
local tmpTabNumArr = {}

function RevivePointCell:onGUI()
	ImGui.Text(self:getTypeName())
	ImGui.Separator()

	if self.renderNode == nil then
		return
	end

	local positionx, positiony = self.renderNode:getPosition()
    tmpTabNumArr[1] = positionx
    tmpTabNumArr[2] = positiony
    if ImGui.DragFloat2(STR("EA_POS"), tmpTabNumArr, 1) then
    	self.renderNode:setPosition(tmpTabNumArr[1], tmpTabNumArr[2])
        self:dataDirty()
    end
end

-- 不属于节点，序列化时只序列化成数据点
-- 不遵从节点序列化流程
function RevivePointCell:isNode()
	return false
end

function RevivePointCell:getTypeName()
	return "RevivePointCell"
end

-- 加入时添加到zTopNode节点
function RevivePointCell:onAdd()
	self.context.zTopNode:addChild(self.renderNode)
end

function RevivePointCell:serialize()
    local positionx, positiony = self.renderNode:getPosition()

    local output = ""
    output = output .. string.format("\nrevivePointCellTmp = require(\"app.cell.RevivePointCell\").new(context, cc.p(%f, %f))\n", positionx, positiony)
	output = output .. string.format("context:addCell(revivePointCellTmp)\n")

    return output
end

function RevivePointCell:deserialize(data)
end

-- 发布
function RevivePointCell:publish()
    local positionx, positiony = self.renderNode:getPosition()
    return cc.p(positionx, positiony)
end

return RevivePointCell