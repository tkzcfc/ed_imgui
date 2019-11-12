local WidgetBaseCell = require("app.cell.WidgetBaseCell")
local SpriteCell = class("SpriteCell", WidgetBaseCell)

local FileUtilsInstance = cc.FileUtils:getInstance()

function SpriteCell:ctor(context, resPath, resType, pos)
	SpriteCell.super.ctor(self, context)
	self.resPath = resPath
	self.resType = resType

    if resPath ~= nil and not FileUtilsInstance:isFileExist(resPath) then
        logE(resPath, "文件不存在")
        self.resPath = "Default/Sprite.png"
        self.resType = 0
        self:dataDirty()
    end

	if self.resType ~= 1 then
		self.resType = 0
	end

	local sprite = cc.Sprite:create(self.resPath)
    sprite:setAnchorPoint(0.5, 0.5)

    if pos then
    	sprite:setPosition(pos)
    end

    self:setRenderNode(sprite)
    self:bindFocusCall(sprite)
end

function SpriteCell:getTypeName()
	return "Sprite"
end

function SpriteCell:getReferenceResources()
    return { self.resPath }
end

function SpriteCell:bool_can_edit_size()
    return false
end

function SpriteCell:onGUI()
	SpriteCell.super.onGUI(self)

	if not ImGui.CollapsingHeader(STR("EA_FEATURES"), ImGuiTreeNodeFlags_DefaultOpen) then
		return
	end
	-- ImGui.Text(STR("EA_RESOURCE"))
	-- ImGui.SameLine()
	-- ImGui.Text(self.resPath)
	Tools:imgui_inputText(STR("EA_RESOURCE"), self.resPath, 512, ImGuiInputTextFlags_ReadOnly)

    if ImGui.BeginDragDropTarget() then
    	if Tools:check_AcceptDragDropPayload("DRAG_MOVE_CELL_IMAGE_PNG") then
    		local dragPath = Tools:AcceptDragDropPayload("DRAG_MOVE_CELL_IMAGE_PNG")
    		dragPath = _MyG.Functions:getRelativePath(dragPath)
    		if dragPath ~= "" then
    			self.resPath = dragPath
    			self.renderNode:setTexture(self.resPath)
    			self:updateDrawBase()
                self:dataDirty()
    		else
    			logW("dragPath == \"\"")
    		end
    	end
    	ImGui.EndDragDropTarget()
    end

    ImGui.Separator()
end

    -- local size = self.renderNode:getContentSize()

function SpriteCell:serialize()
	local anchorPoint = self.renderNode:getAnchorPoint()
    local positionx, positiony = self.renderNode:getPosition()
    local size = self.renderNode:getContentSize()
    local rotation = self.renderNode:getRotation()
    local zOrder = self.renderNode:getLocalZOrder()
    local scaleX = self.renderNode:getScaleX()
    local scaleY = self.renderNode:getScaleY()
    local opacity = self.renderNode:getOpacity()
    local color = self.renderNode:getColor()

    local output = ""
    output = output .. string.format("\nlocal %s = require(\"app.cell.SpriteCell\").new(context, %q, %d)\n", self.name, self.resPath, self.resType)
    output = output .. string.format("%s:setName(%q)\n", self.name, self.name)
    output = output .. string.format("%s.renderNode:setAnchorPoint(cc.p(%f, %f))\n", self.name, anchorPoint.x, anchorPoint.y)
    output = output .. string.format("%s.renderNode:setPosition(%f, %f)\n", self.name, positionx, positiony)
    output = output .. string.format("%s.renderNode:setContentSize(cc.size(%f, %f))\n", self.name, size.width, size.height)
    output = output .. string.format("%s.renderNode:setRotation(%f)\n", self.name, rotation)
	output = output .. string.format("%s.renderNode:setLocalZOrder(%d)\n", self.name, zOrder)
	output = output .. string.format("%s.renderNode:setScaleX(%f)\n", self.name, scaleX)
	output = output .. string.format("%s.renderNode:setScaleY(%f)\n", self.name, scaleY)
	output = output .. string.format("%s.renderNode:setOpacity(%d)\n", self.name, opacity)
	output = output .. string.format("%s.renderNode:setColor(cc.c3b(%d,%d,%d))\n", self.name, color.r, color.g, color.b)
	output = output .. string.format("context:addCell(%s)\n", self.name)

    local parentName = self:getCocosParentNodeVarName()
    if parentName ~= G_ROOT_NODE_NAME then
        output = output .. string.format("%s.renderNode:retain()\n", self.name)
        output = output .. string.format("%s.renderNode:removeFromParent()\n", self.name)
        output = output .. string.format("%s.renderNode:addChild(%s.renderNode)\n", parentName, self.name)
        output = output .. string.format("%s.renderNode:release()\n", self.name)
    end

    return output
end

function SpriteCell:publish()
	local output = ""
	output = output .. string.format("\nlocal %s = cc.Sprite:create(%q)\n", self.name, self.resPath)
	output = output .. SpriteCell.super.publish(self)
	return output
end

return SpriteCell

