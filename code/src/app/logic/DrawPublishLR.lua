local DrawPublishLR = class("DrawPublishLR")

function DrawPublishLR:ctor(rootNode)
	self.drawLineNode = self:createDrawNode(rootNode)
	self.drawRectNode = self:createDrawNode(rootNode)

	self:setLineColor(cc.c4f(0, 1.0, 0, 0.6))

-- 231 86 34 255
-- 0.9 0.33 0.13 1.0
	self:setRectColor(cc.c4f(0.9, 0.33, 0.13, 0.6))
end

function DrawPublishLR:setVisible(value)
	self.drawLineNode:setVisible(value)
	self.drawRectNode:setVisible(value)
end

function DrawPublishLR:setLineColor(color)
	self.lineColor = color
	-- self.lineColor_Imgui = {color.r, color.g, color.b, color.a}
end

function DrawPublishLR:setRectColor(color)
	self.rectColor = color
	-- self.rectColor_Imgui = {color.r, color.g, color.b, color.a}
end

function DrawPublishLR:setDrawData(data)
	self.drawData = data
	self:updateDrawLine()
	self:updateDrawRect()
end

function DrawPublishLR:updateDrawLine()
	if self.drawData == nil then
		return
	end

	self.drawLineNode:clear()
	self:drawLine(self.drawLineNode, self.drawData.line_data)
	self:drawLine(self.drawLineNode, self.drawData.child_line_data)
end

function DrawPublishLR:updateDrawRect()
	if self.drawData == nil then
		return
	end
	
	self.drawRectNode:clear()
	self:drawRect(self.drawRectNode, self.drawData.rect_data)
	self:drawRect(self.drawRectNode, self.drawData.child_rect_data)
end

function DrawPublishLR:drawLine(drawNode, drawData)
	if drawData == nil then
		return
	end
	for k,v in pairs(drawData) do
		if #v.points > 1 then
			for i = 2,#v.points do
				drawNode:drawLine(v.points[i - 1], v.points[i], self.lineColor)
			end
		end
	end
end

function DrawPublishLR:drawRect(drawNode, drawData)
	if drawData == nil then
		return
	end
	for k,v in pairs(drawData) do
		drawNode:drawRect(v.points[1], v.points[2], v.points[3], v.points[4], self.rectColor)
	end
end

function DrawPublishLR:createDrawNode(rootNode)
	local drawNode = cc.DrawNode:create()
	drawNode:setAnchorPoint(cc.p(0, 0))
	drawNode:setPosition(0, 0)
	rootNode:addChild(drawNode, 0xffffff)
	return drawNode
end


return DrawPublishLR
