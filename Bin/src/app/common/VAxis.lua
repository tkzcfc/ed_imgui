-- @Author : fangcheng
-- @Date   : 2020-06-03 13:45:20

-- @remark : 坐标轴绘制
local VAxis = class("VAxis", cc.DrawNode)

-- 边框线段颜色
local lineColor = cc.c4f(0, 0.5, 1.0, 1)

-- X轴默认颜色
local xCoordNormalColor = cc.c4f(0, 0.8, 0, 1)
-- Y轴默认颜色
local yCoordNormalColor = cc.c4f(0.8, 0, 0, 1)

-- 矩形边框颜色
local rectColorBorder = cc.c4f(0, 0, 1.0, 1)
-- 矩形填充颜色
local rectColorFull = cc.c4f(0, 0, 1.0, 0.5)

-- 鼠标与坐标轴重叠时颜色
local overlapColor = cc.c4f(0.8, 0.8, 0, 1)

-- XY轴长度
local coordHeight = 200

-- 三角形宽高
local TriangleWidth = 15
local TriangleHeight = 20
local TriangleWidthHalf = TriangleWidth * 0.5

-- 矩形宽高
local RectWidth = 20

-- 线段宽度
local default_lineWidth = 1.5

function VAxis:ctor()
	self.collision_X = cc.rect(0, 0, coordHeight, TriangleWidth)
	self.collision_Y = cc.rect(0, 0, TriangleWidth, coordHeight)
	self.collision_Rect = cc.rect(0, 0, RectWidth, RectWidth)
end

function VAxis:drawAxis(center, isOverlapRect, isOverlapX, isOverlapY)
	self.isShow = true
	self:clear()

	center.x = center.x + 1
	center.y = center.y + 1

	-- rect
	local rect = {}
	rect[1] = center
	rect[2] = cc.p(center.x, center.y + RectWidth)
	rect[3] = cc.p(center.x + RectWidth, center.y + RectWidth)
	rect[4] = cc.p(center.x + RectWidth, center.y)
	self.collision_Rect.x = center.x
	self.collision_Rect.y = center.y

	local lineWidth = default_lineWidth
	local drawColor = rectColorBorder
	local fullColor = rectColorFull

	if isOverlapRect then
		drawColor = overlapColor
		fullColor = overlapColor
	end

	self:drawPolygon(rect, #rect, fullColor, 1, drawColor)

	center.x = center.x - 1
	center.y = center.y - 1

	-- x
	local endPoint = cc.p(center.x + coordHeight - TriangleHeight, center.y)
	local p1 = cc.p(center.x + coordHeight, center.y)
	local p2 = cc.p(endPoint.x, endPoint.y - TriangleWidthHalf)
	local p3 = cc.p(endPoint.x, endPoint.y + TriangleWidthHalf)
	self.collision_X.x = center.x
	self.collision_X.y = center.y - TriangleWidthHalf

	drawColor = xCoordNormalColor
	if isOverlapX then
		drawColor = overlapColor
	end

	self:drawSegment(center, endPoint, lineWidth, drawColor)
	self:drawTriangle(p1, p2, p3, drawColor)

	-- y
	endPoint = cc.p(center.x, center.y + coordHeight - TriangleHeight)
	p1 = cc.p(center.x, center.y + coordHeight)
	p2 = cc.p(endPoint.x + TriangleWidthHalf, endPoint.y)
	p3 = cc.p(endPoint.x - TriangleWidthHalf, endPoint.y)
	self.collision_Y.x = center.x - TriangleWidthHalf
	self.collision_Y.y = center.y

	drawColor = yCoordNormalColor
	if isOverlapY then
		drawColor = overlapColor
	end

	self:drawSegment(center, endPoint, lineWidth, drawColor)
	self:drawTriangle(p1, p2, p3, drawColor)
end

function VAxis:collisionTestX(point)
	return cc.rectContainsPoint(self.collision_X, point)
end

function VAxis:collisionTestY(point)
	return cc.rectContainsPoint(self.collision_Y, point)
end

function VAxis:collisionTestRect(point)
	return cc.rectContainsPoint(self.collision_Rect, point)
end

function VAxis:clearEx()
	self.isShow = false
	self:clear()
end

return VAxis
