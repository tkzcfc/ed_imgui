-- @Author: fangcheng
-- @Date:   2021-06-26 18:35:58
-- @remark: 动画（包含cocostudio导出的骨骼动画,spine动画）


local ArmatureRender = require("app.render.ArmatureRender")

local NodeElement = import(".NodeElement")
local Armature = class("Armature", NodeElement)

Armature.type = "ArmatureFile"
Armature.defaultFileName = "Default/DemoPlayer.ExportJson"

-- @brief 
function Armature:ctor(context)
    Armature.super.ctor(self, context)

    self.resFile = Armature.defaultFileName

    self.dragDropKey_ExportJson = "drag" .. Asset.ResType.EXPORTJSON
    self.dragDropKey_SPINE = "drag" .. Asset.ResType.SPINE
end

function Armature:bool_can_edit_size()
    return false
end

-- @brief 序列化
function Armature:doSerialize()
    local out = Armature.super.doSerialize(self)

    -- 不保存 contentSize
    out.contentSize = nil

    out.resFile = self.resFile

    if self.armatureRender then
        out.playAniName = self.armatureRender:getCurPlayName()
        out.playIndex = self.armatureRender:getCurPlayIndex()
        out.playLoop = self.armatureRender:isPlayLoop()
    end

    return out
end

-- @brief 反序列化
function Armature:doDeserialize(data)

    self.resFile = self:checkResource(data.resFile)

    -- 创建node
    if not Armature.super.doDeserialize(self, data) then
        return false
    end

    self:updateArmature(data)

    return true
end

-- @brief 获取引用资源
function Armature:getReferenceResources()
    local refs = Armature.super.getReferenceResources(self)
    
    refs[#refs + 1] = self.resFile

    return refs
end

-- @brief 更新动画
function Armature:updateArmature(data)
    if self.armatureRender == nil then
        self.armatureRender = ArmatureRender.new()
        self.renderNode:addChild(self.armatureRender)
    end

    if data then
        self.armatureRender:initWithFile(self.resFile, data.playIndex, data.playLoop)
    else
        self.armatureRender:initWithFile(self.resFile)
    end
end

-- @brief 更新碰撞数据
function Armature:updateCollisionData()
    local transformRoot = _MyG.CenterWindow.rootNode
    local node = self.armatureRender

    if node == nil then
        return
    end

    local size = node:getContentSize()
    local mat = node:getNodeToParentTransform(transformRoot)
    local anchorPoint = node:getAnchorPoint()
    anchorPoint.x = anchorPoint.x * size.width
    anchorPoint.y = anchorPoint.y * size.height
    -- local anchorPoint = cc.p(0, 0)

    self.cache_box = self.armatureRender:getBox()

    G_Helper.obbApplyMatrix(self.cache_box, mat, self.worldPoints[1], self.worldPoints[2], self.worldPoints[3], self.worldPoints[4])
    G_Helper.getPolygonAABB(self.worldAABB, self.worldPoints)
    self.worldAnchorPoint = G_Helper.mat4_transformVector(anchorPoint, mat)
end

-- @brief 
function Armature:onAttributeGUI()
    Armature.super.onAttributeGUI(self)

    if not ImGui.CollapsingHeader(STR("EA_FEATURES"), ImGuiTreeNodeFlags_DefaultOpen) then
        return
    end

    Tools:imgui_inputText(STR("EA_RESOURCE"), self.resFile, 512, ImGuiInputTextFlags_ReadOnly)

    if ImGui.BeginDragDropTarget() then
        if Tools:check_AcceptDragDropPayload(self.dragDropKey_ExportJson) then
            local dragData = Tools:AcceptDragDropPayload(self.dragDropKey_ExportJson)
            self:changeAsset(dragData)
        end
        ImGui.EndDragDropTarget()
    end

    if ImGui.BeginDragDropTarget() then
        if Tools:check_AcceptDragDropPayload(self.dragDropKey_SPINE) then
            local dragData = Tools:AcceptDragDropPayload(self.dragDropKey_SPINE)
            self:changeAsset(dragData)
        end
        ImGui.EndDragDropTarget()
    end

    ImGui.Separator()
end

-- @brief 元素基本属性GUI逻辑 （attribute面板展示）
local tmpTabNumArr = {}
function Armature:onGUI_Base()
    local positionx, positiony = self.renderNode:getPosition()
    local size = self.renderNode:getContentSize()


    tmpTabNumArr[1] = positionx
    tmpTabNumArr[2] = positiony
    if ImGui.DragFloat2(STR("EA_POS"), tmpTabNumArr, 1) then
        self:onAttributeChange(EditorEvent.ON_CHANGE_POSITION)
        self.renderNode:setPosition(tmpTabNumArr[1], tmpTabNumArr[2])
    end

    -- tmpTabNumArr[1] = size.width
    -- tmpTabNumArr[2] = size.height
    -- ImGui.InputFloat2(STR("EA_SIZE"), tmpTabNumArr, "%.3f", ImGuiInputTextFlags_ReadOnly)
    local index = self.armatureRender:getCurPlayIndex() - 1
    local loop = self.armatureRender:isPlayLoop()

    local newIndex = Tools:imguiCombo_OneLiner("play", index, self.armatureRender:getPlayNames_imguiCombo())
    local newValue = Tools:imguiComboBool("loop", loop)

    if index ~= newIndex or newValue ~= loop then
        self:onAttributeChange(EditorEvent.ON_CHANGE_ARMATURE_PLAY)
        self.armatureRender:playWithIndex(newIndex + 1, newValue)
    end
end

-- @brief 切换动画资源
function Armature:changeAsset(dragData)
    local asset = _MyG.Functions:getAssetByID(dragData)
	G_SysEventEmitter:emit(SysEvent.DO_CHANGE_ASSET, self, asset, true)
end

-- @brief override 资源对比
function Armature:isAssetEqual(asset)
	local property = asset.property
    return self.resFile == property.relativePath
end

-- @brief override 资源切换
function Armature:onDoChangeAsset(asset, canUndo)
	Armature.super.onDoChangeAsset(self, asset, canUndo)
	if canUndo then
		self:onAttributeChange(EditorEvent.ON_CHANGE_PREFABRESOURCE)
	end
	
	local property = asset.property
    self.resFile = property.relativePath

    self:updateArmature()
end

-- @brief 局部快照数据生成
-- @param attributeName 改变属性名称
function Armature:doPartMementoGen(attributeName)
    if attributeName == EditorEvent.ON_CHANGE_PREFABRESOURCE or 
    attributeName == EditorEvent.ON_CHANGE_ARMATURE_PLAY  then

        local data = {
            file = self.resFile,
        }

        if self.armatureRender then
            data.playAniName = self.armatureRender:getCurPlayName()
            data.playIndex = self.armatureRender:getCurPlayIndex()
            data.playLoop = self.armatureRender:isPlayLoop()
        end

        return data
    else
        return Armature.super.doPartMementoGen(self, attributeName)
    end
end

-- @brief 撤销属性改变
function Armature:revokeAttributeChange(attributeName, data)
    if attributeName == EditorEvent.ON_CHANGE_PREFABRESOURCE or 
    attributeName == EditorEvent.ON_CHANGE_ARMATURE_PLAY then
        self.resFile = data.file
        self:updateArmature(data)
    else
        Armature.super.revokeAttributeChange(self, attributeName, data)
    end
end

return Armature



