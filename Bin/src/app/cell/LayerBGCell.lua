local LineBGCell = require("app.cell.LineBGCell")
local LayerBGCell = class("LayerBGCell", LineBGCell)

local DefaultWorkSpaceRectColor = cc.c4f(0, 0, 0, 1)

function LayerBGCell:ctor(context)
	LayerBGCell.super.ctor(self, context)
	self.workSpace = {_MyG.Editor_DesignResolution.width, _MyG.Editor_DesignResolution.height}
	self:setWorkSpaceRectColor(DefaultWorkSpaceRectColor)
end

function LayerBGCell:onGUI()

    if ImGui.DragFloat2(STR("EA_WORK_SPACE"), self.workSpace, 1) then
    	self:updateDrawWorkSpace()
		self:dataDirty()
    end

    if ImGui.ColorEdit4(STR("EA_WORK_SPACE_COLOR"), self.workSpaceRectColor_Imgui) then
    	local color = cc.c4f(self.workSpaceRectColor_Imgui[1], self.workSpaceRectColor_Imgui[2], self.workSpaceRectColor_Imgui[3], self.workSpaceRectColor_Imgui[4])
    	self:setWorkSpaceRectColor(color)
		self:updateDrawWorkSpace()
        self:dataDirty()
    end

	LayerBGCell.super.onGUI(self)
end

function LayerBGCell:setWorkSpaceRectColor(color)
	self.workSpaceRectColor = color
	self.workSpaceRectColor_Imgui = {color.r, color.g, color.b, color.a}
end

function LayerBGCell:onAdd()

	local function createDrawNode()
		local drawNode = cc.DrawNode:create()
		drawNode:setAnchorPoint(cc.p(0, 0))
		drawNode:setPosition(0, 0)
		self.context.rootNode:addChild(drawNode)
		return drawNode
	end

	self.drawBGNode = createDrawNode()
	self.drawBGNode:setLocalZOrder(-0xffff)

	self:updateDrawWorkSpace()

	LayerBGCell.super.onAdd(self)
end

function LayerBGCell:updateDrawWorkSpace()
	self.drawBGNode:clear()
	self.drawBGNode:drawSolidRect(cc.p(0, 0), cc.p(self.workSpace[1], self.workSpace[2]), self.workSpaceRectColor)
end

function LayerBGCell:serialize()
	local output = LayerBGCell.super.serialize(self)
	output["workSpace"] = self.workSpace
	output["workSpaceRectColor"] = self.workSpaceRectColor
	return output
end

function LayerBGCell:deserialize(data)
	if data == nil then
		return
	end
	LayerBGCell.super.deserialize(self, data)

	self.workSpace = data.workSpace
	self:setWorkSpaceRectColor(data.workSpaceRectColor)
	self:updateDrawWorkSpace()
end


function LayerBGCell:publish()
	local output = LayerBGCell.super.publish(self)

    local zeroPos = cc.p(0, 0)
    local offsetPos = {}
    local rect_data = {}
    local line_data = {}

    local function del_data(offset, datas, container, node)
        for _, data in pairs(datas) do
            local t = G_Helper.copyTable(data)
            for k,point in pairs(t.points) do
                point.x = point.x + offset.x
                point.y = point.y + offset.y
            end

            table.insert(container, t)
        end
    end

    local p1 = self.rootNode:convertToNodeSpace(zeroPos)

    for k,v in pairs(self.context.cells) do
        if v.bgCellData and v.renderNode then
            local p2 = v.renderNode:convertToNodeSpace(zeroPos)

            offsetPos.x = p1.x - p2.x
            offsetPos.y = p1.y - p2.y

            del_data(offsetPos, v.bgCellData.rect_data, rect_data, v.renderNode)
            del_data(offsetPos, v.bgCellData.line_data, line_data, v.renderNode)
        end
    end

    output.child_rect_data = rect_data
    output.child_line_data = line_data
    output["workSpace"] = self.workSpace

    return output
end

return LayerBGCell
