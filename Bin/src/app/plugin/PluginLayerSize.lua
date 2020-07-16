-- @Author: fangcheng
-- @Date:   2020-06-04 19:33:02
-- @remark: 

local Plugin = import(".Plugin")
local PluginLayerSize = class("PluginLayerSize", Plugin)

local DefaultWorkSpaceRectColor = cc.c4f(0.9, 0, 1, 1)

function PluginLayerSize:ctor()
	PluginLayerSize.super.ctor(self)

	self:setWorkSpaceSize(cc.p(_MyG.Editor_DesignResolution.width, _MyG.Editor_DesignResolution.height))
	self:setWorkSpaceRectColor(DefaultWorkSpaceRectColor)
end

function PluginLayerSize:attach(edContext)
	PluginLayerSize.super.attach(self, edContext)

	self.rootNode = self.context.render
	self.borderDraw = self.context.borderDraw
end

-- @brief 
function PluginLayerSize:onEditorDraw()
	PluginLayerSize.super.onEditorDraw(self)

	local transformRoot = _MyG.CenterWindow.rootNode
	local mat = self.rootNode:getNodeToParentTransform(transformRoot)
	local worldSize = G_Helper.mat4_transformVector(self.workSpace, mat)

	local pos = cc.p(self.rootNode:getPosition())
	local oldLineWidth = self.borderDraw:getLineWidth()

	self.borderDraw:setLineWidth(3)
	self.borderDraw:drawRect(pos, worldSize, self.workSpaceRectColor)
	self.borderDraw:setLineWidth(oldLineWidth)
end

function PluginLayerSize:setWorkSpaceRectColor(color)
	color = color or DefaultWorkSpaceRectColor
	self.workSpaceRectColor = color
	self.workSpaceRectColor_Imgui = {color.r, color.g, color.b, color.a}
end

function PluginLayerSize:setWorkSpaceSize(size)
	self.workSpace = size
	self.workSpace_Imgui = {size.x, size.y}
end

function PluginLayerSize:onAttributeGUI()
	if ImGui.DragFloat2(STR("EA_WORK_SPACE"), self.workSpace_Imgui, 1) then
		self:onAttributeChange("change_work_space")
		self:setWorkSpaceSize(cc.p(self.workSpace_Imgui[1], self.workSpace_Imgui[2]))
    end

    if ImGui.ColorEdit4(STR("EA_WORK_SPACE_COLOR"), self.workSpaceRectColor_Imgui) then
    	self:onAttributeChange("change_work_space_color")
    	local color = cc.c4f(self.workSpaceRectColor_Imgui[1], self.workSpaceRectColor_Imgui[2], self.workSpaceRectColor_Imgui[3], self.workSpaceRectColor_Imgui[4])
    	self:setWorkSpaceRectColor(color)
    end
end

-- 序列化
function PluginLayerSize:doSerialize()
	local output = PluginLayerSize.super.doSerialize(self)

	output.color = self.workSpaceRectColor
	output.size = self.workSpace

	return output
end

-- 序列化
function PluginLayerSize:doDeserialize(data)
	if not PluginLayerSize.super.doDeserialize(self, data) then
		return false
	end

	self.workSpace = data.size
	self:setWorkSpaceRectColor(data.color)
	return true
end

return PluginLayerSize


