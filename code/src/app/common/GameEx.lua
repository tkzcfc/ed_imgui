
-- line
function CLine:serialize()
	self:apply()
	local t = {}
	t.points = self:getAllPoint()
	t.isLeftNormal = self:isLeftNormal()
	t.isVisible = self:isVisible()
	t.lineColor = self:getLineColor()
	t.normalColor = self:getNormalColor()
	return t
end

function CLine:deserialize(data)
	if data == nil then
		return
	end
	self:setPointCount(#data.points)
	for idx, pos in pairs(data.points) do
		self:setPointDataByIndex(idx - 1, pos.x, pos.y)
	end

	self:setNormalLeft(data.isLeftNormal)
	self:setVisible(data.isVisible)
	self:setLineCorlor(data.lineColor)
	self:setNormalColor(data.normalColor)
	self:apply()
end

function CLine:publish()
	self:apply()
	local t = {}
	t.points = self:getAllPoint()
	t.normals = self:getAllNormal()
	return t
end


-- rect
function CRect:serialize()
	self:apply()
	local t = {}
	t.anchorPoint = self:getAnchorPoint()
	t.contentSize = self:getContentSize()
	t.point = self:getPoint()
	t.scale = self:getScale()
	t.rotation = self:getRotation()
	t.skew = self:getSkew()
	t.isVisible = self:isVisible()
	t.color = self:getColor()
	return t
end

function CRect:deserialize(data)
	if data == nil then
		return
	end

	self:setAnchorPoint(data.anchorPoint.x, data.anchorPoint.y)
	self:setContentSize(data.contentSize.x, data.contentSize.y)
	self:setPoint(data.point.x, data.point.y)
	self:setScale(data.scale.x, data.scale.y)
	self:setRotation(data.rotation)
	self:setSkewX(data.skew.x)
	self:setSkewY(data.skew.y)
	self:setVisible(data.isVisible)
	self:setColor(data.color)
	self:apply()
end


function CRect:publish()
	self:apply()
	local t = {}
	t.points = {}
	for i=1,self:getVertexCount() do
		t.points[i] = self:getVertexByIndex(i - 1)
	end
	return t
end
