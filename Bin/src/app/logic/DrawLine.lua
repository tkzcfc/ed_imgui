local DrawLine = class("DrawLine")

function DrawLine:ctor(rootNode)
	self.drawLineNode = self:createDrawNode(rootNode)
	self.drawRectNode = self:createDrawNode(rootNode)
end

function DrawLine:setDrawData(data)
	self.lines = {}
	self.rects = {}

	for k,v in pairs(data.line_data) do
		local line = CLine:new_local()
		line:setLineCorlor(LineColor_UINT)
		line:setPointCount(#v.points)

		for idx, pos in pairs(v.points) do
			line:setPointDataByIndex(idx - 1, pos.x, pos.y)
		end
		line:setNormalLeft(v.isLeftNormal)
		line:setVisible(v.isVisible)
		table.insert(self.lines, line)
	end

	for k,v in pairs(data.rect_data) do
		local rect = CRect:new_local()
		rect:deserialize(v)
		table.insert(self.rects, rect)
	end
end


-- function CRect:deserialize(data)
-- 	if data == nil then
-- 		return
-- 	end

-- 	self:setAnchorPoint(data.anchorPoint.x, data.anchorPoint.y)
-- 	self:setContentSize(data.contentSize.x, data.contentSize.y)
-- 	self:setPoint(data.point.x, data.point.y)
-- 	self:setScale(data.scale)
-- 	self:setRotation(data.rotation)
-- 	self:setSkewX(data.skew.x)
-- 	self:setSkewY(data.skew.y)
-- 	self:setVisible(data.isVisible)
-- 	self:apply()
-- end

function DrawLine:createDrawNode(rootNode)
	local drawNode = cc.DrawNode:create()
	drawNode:setAnchorPoint(cc.p(0, 0))
	drawNode:setPosition(0, 0)
	rootNode:addChild(drawNode, 0xffffff)
	return drawNode
end


return DrawLine
