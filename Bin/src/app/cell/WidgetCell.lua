local CocostudioCell = require("app.cell.CocostudioCell")
local DrawPublishLR = require("app.logic.DrawPublishLR")

local WidgetCell = class("WidgetCell", CocostudioCell)

local FileUtilsInstance = cc.FileUtils:getInstance()

function WidgetCell:ctor(context, resPath, pos)
	WidgetCell.super.ctor(self, context, resPath, pos)
end

function WidgetCell:setResource(resPath, pos)
    self:checkRes(resPath)

    local R = _MyG.require(self:getLuaPath(self.resPath_Lua))
    local root = R:loadNode()
    self.bgCellData = R.bgCellData

    self:setupNode(root, pos)

    if self.drawPublishLR == nil then
        self.drawPublishLR = DrawPublishLR.new(self.renderNode)
    end
    self.drawPublishLR:setDrawData(self.bgCellData)
end

function WidgetCell:checkRes(resPath)
    local resPath_Lua = Tools:replaceString(resPath, _MyG.GlobalData:getFileFullExtension("WIDGET"), ".lua")
    
    if resPath ~= nil and not FileUtilsInstance:isFileExist(resPath_Lua) then
        logE(resPath, "文件不存在")
        resPath = "Default/defaultWidget.widget"
        resPath_Lua = Tools:replaceString(resPath, _MyG.GlobalData:getFileFullExtension("WIDGET"), ".lua")
        self:dataDirty()
    end

    self.resPath = resPath
    self.resPath_Lua = resPath_Lua
    if self.resPath == nil or self.resPath  == "" then
        error("resPath invalid")
    end
end

function WidgetCell:getReferenceResources()
    return self.bgCellData.referenceResources
end

-- 重载onMouseScroll函数，不允许更改旋转缩放等影响碰撞数据计算的属性
function WidgetCell:onMouseScroll(event)
    return false
end

function WidgetCell:setVisiblePublishLR(value)
    if not self.drawPublishLR then
        logI("WidgetCell:setVisiblePublishLR() -> self.drawPublishLR == nil")
        return
    end
    self.drawPublishLR:setVisible(value)
end

function WidgetCell:getTypeName()
	return "Widget"
end

function WidgetCell:bool_can_edit_size()
    return false
end

function WidgetCell:onGUI()
    CocostudioCell.super.onGUI(self)

    if not ImGui.CollapsingHeader(STR("EA_FEATURES"), ImGuiTreeNodeFlags_DefaultOpen) then
        return
    end
    
    Tools:imgui_inputText(STR("EA_RESOURCE"), self.resPath, 512, ImGuiInputTextFlags_ReadOnly)

    if ImGui.BeginDragDropTarget() then
        if Tools:check_AcceptDragDropPayload("DRAG_MOVE_CELL_WIDGET") then

            local dragPath = Tools:AcceptDragDropPayload("DRAG_MOVE_CELL_WIDGET")
            dragPath = _MyG.Functions:getRelativePath(dragPath)

            local resPath_Lua = Tools:replaceString(dragPath, _MyG.GlobalData:getFileFullExtension("WIDGET"), ".lua")
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

function WidgetCell:serialize()
    local positionx, positiony = self:getPosition()
    local zOrder = self.renderNode:getLocalZOrder()

    local output = ""
    output = output .. string.format("\nlocal %s = require(\"app.cell.WidgetCell\").new(context, %q, cc.p(%f, %f))\n", self.name, self.resPath, positionx, positiony)
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

function WidgetCell:publish()
    local luaFileVarName = self.name .. "_luafile"

    local zOrder = self.renderNode:getLocalZOrder()
    local parentName = self:getCocosParentNodeVarName()
    local positionx, positiony = self:getPosition()

    local output = ""
    output = output .. string.format("\nlocal %s = require(%q)\n", luaFileVarName, self:getLuaPath(self.resPath_Lua))
    output = output .. string.format("local %s = %s:loadNode()\n", self.name, luaFileVarName)
    output = output .. string.format("%s.LuaFileInfo = %s\n", self.name, luaFileVarName)

    if zOrder ~= 0 then
        output = output .. string.format("%s:setLocalZOrder(%d)\n", self.name, zOrder)
    end

    if positionx ~= 0 or positiony ~= 0 then
        output = output .. string.format("%s:setPosition(%.02f,%.02f)\n", self.name, positionx, positiony)
    end

    if self.context.__cname == "LayerEditContext" and parentName == G_ROOT_NODE_NAME then
        output = output .. string.format("%s.boxData = %s\n", self.name, format_lua_value(self:getBox()))
    end

    output = output .. string.format("%s:addChild(%s)\n", parentName, self.name)
    return output
end

return WidgetCell

