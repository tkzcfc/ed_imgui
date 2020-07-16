-- @Author : fangcheng
-- @Date   : 2020-05-22 16:54:47
-- @remark : 坐标轴

local CoordinateAxis = class("CoordinateAxis", cc.Node)

function CoordinateAxis:ctor()
	local axisX = cc.DrawNode:create()
	local axisY = cc.DrawNode:create()
	self:addChild(axisX)
	self:addChild(axisY)

	self.axisX = axisX
	self.axisY = axisY

	self:setLineLength(2000)

	self:onUpdate(function()
		local parent = self:getParent()
		if parent then
			local posx, posy = parent:getPosition()
			axisX:setPositionX(-posx / parent:getScaleX())
			axisY:setPositionY(-posy / parent:getScaleY())
		end
	end)
end

function CoordinateAxis:setLineLength(lineLength, xColor, yColor)
	xColor = xColor or cc.c4f(1.0, 1.0, 1.0, 1.0)
	yColor = yColor or cc.c4f(1.0, 1.0, 1.0, 1.0)

	self.axisX:clear()
	self.axisY:clear()
	self.axisX:drawLine(cc.p(-lineLength, 0), cc.p(lineLength, 0), xColor)
	self.axisY:drawLine(cc.p(0, -lineLength), cc.p(0, lineLength), yColor)
end

return CoordinateAxis
