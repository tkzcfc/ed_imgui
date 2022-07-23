-- @Author: fangcheng
-- @Date:   2020-07-05 20:46:34
-- @remark: 复活点设置

local Plugin = import(".Plugin")
local PluginRevivePoint = class("PluginRevivePoint", Plugin)

local DefaultWorkSpaceRectColor = cc.c4f(0.9, 0, 1, 1)

function PluginRevivePoint:ctor()
	PluginRevivePoint.super.ctor(self)

	self.revivePoints = {}
end

function PluginRevivePoint:attach(edContext)
	PluginRevivePoint.super.attach(self, edContext)

	self.rootNode = self.context.render

	local render = cc.Node:create()
	self.rootNode:addChild(render, 0xff)

	self.renderNode = render
end

function PluginRevivePoint:detach()
	self.renderNode:removeFromParent()
	PluginRevivePoint.super.detach(self)
end

function PluginRevivePoint:onKeyBoardDelete()
	if tolua.isnull(self.focalNode) then
		self.focalNode = nil
	else
		self:onAttributeChange(EditorEvent.ON_CHANGE_REVIVEPOINT_DEL)
		self.focalNode:removeFromParent()
		self.focalNode = nil
		return true
	end
end

-- @brief 预制体拖拽
function PluginRevivePoint:onDragPreWidgetDragEnd(typeName, pos)
	if typeName == "WC_RevivePoint" then
		self:onAttributeChange(EditorEvent.ON_CHANGE_REVIVEPOINT_CREATE)
		self.revivePoints[#self.revivePoints + 1] = pos
		self:revivePointsRender()
		return
	end
end

-- @brief touch
function PluginRevivePoint:onTouchBegan(touch, event)
	local pos = self.renderNode:convertToNodeSpace(_MyG.MouseEventDispatcher:getCursorPos())

	self.focalNode = nil

	local children = self.renderNode:getChildren()
	for k,child in pairs(children) do
		if cc.rectContainsPoint(child:getBoundingBox(), pos) then
			child.touchOffset = cc.pSub( cc.p(child:getPosition()), pos )
			self.focalNode = child
			return true
		end
	end
	return false
end

function PluginRevivePoint:onTouchMoved(touch, event)
	if self.focalNode then
		self:onAttributeChange(EditorEvent.ON_CHANGE_REVIVEPOINT_POS)
		local pos = self.renderNode:convertToNodeSpace(_MyG.MouseEventDispatcher:getCursorPos())
		local touchOffset = self.focalNode.touchOffset or cc.p(0, 0)
		self.focalNode:setPosition(cc.pAdd(pos, touchOffset))
	end
end

function PluginRevivePoint:onTouchEnded(touch, event)
	-- self.focalNode = nil
end

function PluginRevivePoint:onTouchCancelled(touch, event)
	-- self.focalNode = nil
end

-- 序列化
function PluginRevivePoint:doSerialize()
	local output = PluginRevivePoint.super.doSerialize(self)

	self.revivePoints = {}
	local children = self.renderNode:getChildren()
	for i = 1, #children do
		self.revivePoints[i] = cc.p(children[i]:getPosition())
	end

	output.revivePoints = self.revivePoints

	return output
end

-- 反序列化
function PluginRevivePoint:doDeserialize(data)
	if not PluginRevivePoint.super.doDeserialize(self, data) then
		return false
	end

	self.revivePoints = data.revivePoints or {}

	self:revivePointsRender()

	return true
end

function PluginRevivePoint:revivePointsRender()
	if not self.renderNode then
		return
	end
	local childCount = self.renderNode:getChildrenCount()
	local curCount   = #self.revivePoints

	if childCount <= curCount then
		for i = childCount + 1, curCount do
			local sp = cc.Sprite:create("Res/gem_icon/icon_4.png")
			self.renderNode:addChild(sp)
		end
	end

	local children = self.renderNode:getChildren()
	for i = curCount + 1, #children do
		children[i]:removeFromParent()
	end

	for i = 1, curCount do
		children[i]:setPosition(self.revivePoints[i])
	end
end

return PluginRevivePoint


