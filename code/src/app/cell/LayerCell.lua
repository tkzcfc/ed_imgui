local WidgetCell = require("app.cell.WidgetCell")
local DrawPublishLR = require("app.logic.DrawPublishLR")

local LayerCell = class("LayerCell", WidgetCell)

local FileUtilsInstance = cc.FileUtils:getInstance()

function LayerCell:ctor(context, resPath, pos)
	LayerCell.super.ctor(self, context, resPath, pos)
end

function LayerCell:checkRes(resPath)
    local resPath_Lua = Tools:replaceString(resPath, _MyG.GlobalData:getFileFullExtension("LAYER"), ".lua")
    
    if resPath ~= nil and not FileUtilsInstance:isFileExist(resPath_Lua) then
        logE(resPath, "文件不存在")
        resPath = "Default/defaultLayer.layer"
        resPath_Lua = Tools:replaceString(resPath, _MyG.GlobalData:getFileFullExtension("LAYER"), ".lua")
        self:dataDirty()
    end

    self.resPath = resPath
    self.resPath_Lua = resPath_Lua
    if self.resPath == nil or self.resPath  == "" then
        error("resPath invalid")
    end
end

function LayerCell:getTypeName()
	return "Layer"
end

function LayerCell:bool_can_edit_size()
    return false
end

function LayerCell:onGUI()
    CocostudioCell.super.onGUI(self)

    if not ImGui.CollapsingHeader(STR("EA_FEATURES"), ImGuiTreeNodeFlags_DefaultOpen) then
        return
    end
    
    Tools:imgui_inputText(STR("EA_RESOURCE"), self.resPath, 512, ImGuiInputTextFlags_ReadOnly)

    if ImGui.BeginDragDropTarget() then
        if Tools:check_AcceptDragDropPayload("DRAG_MOVE_CELL_LAYER") then

            local dragPath = Tools:AcceptDragDropPayload("DRAG_MOVE_CELL_LAYER")
            dragPath = _MyG.Functions:getRelativePath(dragPath)

            local resPath_Lua = Tools:replaceString(dragPath, _MyG.GlobalData:getFileFullExtension("LAYER"), ".lua")
            if not cc.FileUtils:getInstance():isFileExist(resPath_Lua) then
                logE(string.format("文件%q不存在，请先保存%q", resPath_Lua, dragPath))
            else
                self:setResource(dragPath)
                self:dataDirty()
                self:updateDrawBase()
            end
        end
        ImGui.EndDragDropTarget()
    end
end

function LayerCell:serialize()
    local positionx, positiony = self:getPosition()
    local zOrder = self.renderNode:getLocalZOrder()

    local output = ""
    output = output .. string.format("\nlocal %s = require(\"app.cell.LayerCell\").new(context, %q, cc.p(%f, %f))\n", self.name, self.resPath, positionx, positiony)
    output = output .. string.format("%s:setName(%q)\n", self.name, self.name)
    output = output .. string.format("%s.renderNode:setLocalZOrder(%d)\n", self.name, zOrder)
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

return LayerCell

