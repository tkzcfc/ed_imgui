-- @Author: fangcheng
-- @Date:   2021-07-24 14:38:53
-- @remark: 角色编辑器


local BaseEditorCocos = import(".BaseEditorCocos")
local CoordinateAxis = require("app.common.CoordinateAxis")
require("app.document.role.config")

local EditorRole = class("EditorRole", BaseEditorCocos)

function EditorRole:ctor(name, asset)
    EditorRole.super.ctor(self, name, asset)

    --坐标轴
    local coord = CoordinateAxis:create()
    coord:setLineLength(10000)
    self.render:addChild(coord)

    -- 角色形象
    self.armatureRender = require("app.render.ArmatureRenderStep").new()
    self.render:addChild(self.armatureRender)

    -- 形状渲染节点
    self.shapRenderNode = cc.Node:create()
    self.render:addChild(self.shapRenderNode)

    -- 角色胶囊体渲染节点
    self.roleShapRender = cc.DrawNode:create()
    self.render:addChild(self.roleShapRender)
        
    -- 文件拖拽响应key
    self.dragDropKeys = {
        "drag" .. Asset.ResType.EXPORTJSON,
        "drag" .. Asset.ResType.SPINE,
    }

    -- 时间轴页签
    self.roleActionDoc = require("app.document.role.RoleAction").new(self)
    self.roleSkillDoc = require("app.document.role.RoleSkill").new(self)
    
    -- 时间轴页签管理
    self.timelineDocMng = require("app.imgui.DocumentManager").new()
    self.timelineDocMng:addDocument(self.roleActionDoc)
    self.timelineDocMng:addDocument(self.roleSkillDoc)
    self.timelineDocMng:setClickDocumentCall(function(doc)
        G_SysEventEmitter:emit(SysEvent.ON_WINDOW_ROLE_DOC_CHANGE, doc:getFullName())
    end)

    -- 此处不使用 self.sysRecipient 监听事件,因为 sysRecipient 监听的时候会在document隐藏时移除监听
    -- 资源更改可能在此页签隐藏时发生,所以使用 G_SysEventEmitter 监听
	-- 更改资源事件监听
	G_SysEventEmitter:on(SysEvent.DO_CHANGE_ASSET, function(target, asset, canUndo)
		if not asset then return end

		if target == self and not self:isAssetEqual(asset) then
			self:onDoChangeAsset(asset, canUndo)
		end
	end, self)

    G_SysEventEmitter:on(SysEvent.ON_ROLE_TIMELINE_DOC_CHANGE, function(docName)
        self.timelineDocMng:setCurShowDocumentByName(docName)
    end, self)
end

-- @brief 页签销毁
-- @override
function EditorRole:destroy()
    self.timelineDocMng:destroy()
    EditorRole.super.destroy(self)
end

-- @brief 事件订阅
function EditorRole:initEvent()
    EditorRole.super.initEvent(self)

    self.sysRecipient:on(SysEvent.ON_TIMELINE_GUI, function()
        self:onTimelineGUI()
    end)
    
    self.sysRecipient:on(SysEvent.ON_REBUILD_SKILL_NAME_NTF, function(editorRole)
        if self.editorRole == editorRole then
            self:buildSkillNames()
        end
    end)
    
	G_SysEventEmitter:emit(SysEvent.ON_SHOW_BOTTOM_DOCUMENT, "timeline")
end

-- @brief 预制体拖拽 override
function EditorRole:onDragPreWidgetDragEnd(typeName, pos)
end

-- @brief 资源拖拽 override
function EditorRole:onAssetDragEnd(assetItem, pos)
end

-- @brief override 重载序列化逻辑
function EditorRole:doSerialize()
    local out = EditorRole.super.doSerialize(self)

    out.role = self.role
    out.roleActionDoc = self.roleActionDoc:serialize()
    out.roleSkillDoc = self.roleSkillDoc:serialize()

    return out
end

-- @brief override
function EditorRole:doDeserialize(data)
    if not EditorRole.super.doDeserialize(self, data) then
        return false
    end

    self.role = data.role
    -- 初始化角色形象
    self.armatureRender:initWithFile(self.role.resFile)

    self.armatureRender:setPosition(self.role.offset)
    self.armatureRender:setScaleX(cond(self.role.directionLeft, -1, 1))

    -- 动作信息
    self.role.actInfo = self.role.actInfo or {}
    -- 技能信息
    self.role.skillInfo = self.role.skillInfo or {}

    self.roleActionDoc:deserialize(data.roleActionDoc or {})
    self.roleSkillDoc:deserialize(data.roleSkillDoc or {})

    -- 默认技能下标
    self.role.defaultSkillIndex = self.role.defaultSkillIndex or 1
    self:buildSkillNames()
    
    self:syncRoleShape()
    
    return true
end

-- @brief attributes面板GUI绘制
function EditorRole:onAttributeContent_GUI_Self()
    self:onAttributeContent_GUI_Self_Ex()
    EditorRole.super.onAttributeContent_GUI_Self(self)
end

local tmpTabNumArr = {}
function EditorRole:onAttributeContent_GUI_Self_Ex()
    -- 基础属性展示
    if ImGui.CollapsingHeader(STR("EA_BASE_ATTR"), ImGuiTreeNodeFlags_DefaultOpen) then
        local positionx, positiony = self.armatureRender:getPosition()
        tmpTabNumArr[1] = positionx
        tmpTabNumArr[2] = positiony
        if ImGui.DragFloat2(STR("EA_POS"), tmpTabNumArr, 1) then
            self:onAttributeChange(EditorEvent.ON_CHANGE_POSITION)
            self.armatureRender:setPosition(tmpTabNumArr[1], tmpTabNumArr[2])
            self.role.offset.x = tmpTabNumArr[1]
            self.role.offset.y = tmpTabNumArr[2]
        end
        
        -- 资源默认朝向
        local ok, value = ImGui.Checkbox(STR("ResDirectionLeft"), self.role.directionLeft)
        if ok then
            self:onAttributeChange(EditorEvent.ON_CHANGE_ROLE_DIRECTION)
            self.role.directionLeft = value
            self.armatureRender:setScaleX(cond(self.role.directionLeft, -1, 1))
        end
	end

    -- 特殊属性展示
    if ImGui.CollapsingHeader(STR("EA_FEATURES"), ImGuiTreeNodeFlags_DefaultOpen) then
        Tools:imgui_inputText(STR("EA_RESOURCE"), self.role.resFile, 512, ImGuiInputTextFlags_ReadOnly)

        -- 拖拽响应
        for k, v in pairs(self.dragDropKeys) do
            if ImGui.BeginDragDropTarget() then
                if Tools:check_AcceptDragDropPayload(v) then
                    self:changeAsset(Tools:AcceptDragDropPayload(v))
                end
                ImGui.EndDragDropTarget()
            end
        end
    end

    -- 物理属性
    if ImGui.CollapsingHeader(STR("PhysicalProperty"), ImGuiTreeNodeFlags_DefaultOpen) then
        -- 角色宽高
        tmpTabNumArr[1] = self.role.roleSize.x
        tmpTabNumArr[2] = self.role.roleSize.y
        tmpTabNumArr[3] = self.role.roleSize.z
        if ImGui.DragFloat3(STR("RoleSize"), tmpTabNumArr, 1) then
            self:onAttributeChange(EditorEvent.ON_CHANGE_ROLE_SIZE)
            self.role.roleSize.x = math.max(tmpTabNumArr[1], 1.0)
            self.role.roleSize.y = math.max(tmpTabNumArr[2], 1.0)
            self.role.roleSize.z = math.max(tmpTabNumArr[3], 1.0)
            self:syncRoleShape()
        end

        -- 角色半径
        local retTmp, radius = ImGui.DragFloat(STR("RoleRadius"), self.role.radius, 1)
        if retTmp then
            self:onAttributeChange(EditorEvent.ON_CHANGE_ROLE_RADIUS)
            self.role.radius = radius
            self:syncRoleShape()
        end

        -- 角色质量
        local retTmp, mass = ImGui.DragFloat(STR("RoleMass"), self.role.mass, 0.1)
        if retTmp then
            self:onAttributeChange(EditorEvent.ON_CHANGE_ROLE_MASS)
            self.role.mass = mass
        end
        
        -- 角色速度
        tmpTabNumArr[1] = self.role.moveSpeed.x
        tmpTabNumArr[2] = self.role.moveSpeed.y
        if ImGui.InputFloat2(STR("RoleVelocity"), tmpTabNumArr) then
            self:onAttributeChange(EditorEvent.ON_CHANGE_ROLE_VELOCITY)
            self.role.moveSpeed.x = tmpTabNumArr[1]
            self.role.moveSpeed.y = tmpTabNumArr[2]
        end
        
        -- 角色冲力
        tmpTabNumArr[1] = self.role.impulsion.x
        tmpTabNumArr[2] = self.role.impulsion.y
        tmpTabNumArr[3] = self.role.impulsion.z
        if ImGui.DragFloat3(STR("RoleImpulsion"), tmpTabNumArr, 1) then
            self:onAttributeChange(EditorEvent.ON_CHANGE_ROLE_IMPULSION)
            self.role.impulsion.x = math.max(tmpTabNumArr[1], 1.0)
            self.role.impulsion.y = math.max(tmpTabNumArr[2], 1.0)
            self.role.impulsion.z = math.max(tmpTabNumArr[3], 1.0)
        end
        -- force
        tmpTabNumArr[1] = self.role.force.x
        tmpTabNumArr[2] = self.role.force.y
        tmpTabNumArr[3] = self.role.force.z
        if ImGui.DragFloat3(STR("RoleForce"), tmpTabNumArr, 1) then
            self:onAttributeChange(EditorEvent.ON_CHANGE_ROLE_FORCE)
            self.role.force.x = math.max(tmpTabNumArr[1], 1.0)
            self.role.force.y = math.max(tmpTabNumArr[2], 1.0)
            self.role.force.z = math.max(tmpTabNumArr[3], 1.0)
        end

        -- 默认技能
        local index = self.role.defaultSkillIndex - 1
        local newIndex = Tools:imguiCombo_OneLiner(STR("RoleDefaultSkill"), index, self.skillNameOptions)
        if newIndex ~= index then
            self:onAttributeChange(EditorEvent.ON_CHANGE_ROLE_DFT_SKILL_IDX)
            self.role.defaultSkillIndex = newIndex + 1
        end
    end


    -- 分割线
    ImGui.Separator()
end

function EditorRole:buildSkillNames()
    if #self.role.skillInfo == 0 then
        self.skillNameOptions = "<-NONE->\0\0"
        return
    end

    local options = ""
    for k, v in pairs(self.role.skillInfo) do
        options = options .. v.name .. "\0"
    end
    options = options .. "\0\0"
    self.skillNameOptions = options
end

function EditorRole:getSkillNameOptions()
    return self.skillNameOptions
end

-- @brief 切换动画资源
function EditorRole:changeAsset(dragData)
    local asset = _MyG.Functions:getAssetByID(dragData)
	G_SysEventEmitter:emit(SysEvent.DO_CHANGE_ASSET, self, asset, true)
end

-- @brief 判断资源是否相同
function EditorRole:isAssetEqual(asset)
    local property = asset.property
    if self.role.resFile == property.relativePath then
        return true
    end
    return false
end

-- @brief 资源切换
function EditorRole:onDoChangeAsset(asset, canUndo)
	if canUndo then
		self:onAttributeChange(EditorEvent.ON_CHANGE_PREFABRESOURCE)
	end
	
    local property = asset.property
    self.role.resFile = property.relativePath

    self.armatureRender:initWithFile(self.role.resFile, self.armatureRender:getCurPlayIndex(), self.armatureRender:isPlayLoop())
end

--------------------------------------------------------- 属性更改/撤销相关 ---------------------------------------------------------
-- @brief 保存局部快照时,此函数返回改变属性要存储的数据
-- 如果返回为nil则Context保存全局快照
function EditorRole:doPartMementoGen(attributeName)
	if attributeName == EditorEvent.ON_CHANGE_PREFABRESOURCE then -- 改变动画资源
        return self.role.resFile
    elseif attributeName == EditorEvent.ON_CHANGE_POSITION then -- 改变位置
        return self.role.offset
    elseif attributeName == EditorEvent.ON_CHANGE_ROLE_SIZE then -- 改变角色大小
        return self.role.roleSize
    elseif attributeName == EditorEvent.ON_CHANGE_ROLE_RADIUS then -- 改变角色半径
        return self.role.radius
    elseif attributeName == EditorEvent.ON_CHANGE_ROLE_MASS then -- 改变角色质量
        return self.role.mass
    elseif attributeName == EditorEvent.ON_CHANGE_ROLE_VELOCITY then -- 改变角色速度
        return self.role.moveSpeed
    elseif attributeName == EditorEvent.ON_CHANGE_ROLE_IMPULSION then -- 改变角色冲力
        return self.role.impulsion
    elseif attributeName == EditorEvent.ON_CHANGE_ROLE_FORCE then -- 改变角色力
        return self.role.force
    elseif attributeName == EditorEvent.ON_CHANGE_ROLE_DIRECTION then -- 改变角色资源朝向
        return self.role.directionLeft == true
    elseif attributeName == EditorEvent.ON_CHANGE_ROLE_DFT_SKILL_IDX then -- 改变默认技能下标
        return self.role.defaultSkillIndex
	else
		return EditorRole.super.doPartMementoGen(self, attributeName)
	end
end

-- @brief 撤销属性更改
-- 撤销的属性改变是保存的局部快照时,根据 data 字段对元素进行还原操作
-- @param attributeName 改变的属性名称
-- @param data doPartMementoGen 返回的局部快照数据
function EditorRole:revokeAttributeChange(attributeName, data)
	if attributeName == EditorEvent.ON_CHANGE_PREFABRESOURCE then   -- 改变动画资源
        self.role.resFile = data
        self.armatureRender:initWithFile(self.role.resFile)
    elseif attributeName == EditorEvent.ON_CHANGE_POSITION then -- 改变位置
		self.armatureRender:setPosition(data)
        self.role.offset = data
    elseif attributeName == EditorEvent.ON_CHANGE_ROLE_SIZE then -- 改变角色大小
        self.role.roleSize = data
        self:syncRoleShape()
    elseif attributeName == EditorEvent.ON_CHANGE_ROLE_RADIUS then -- 改变角色半径
        self.role.radius = data
        self:syncRoleShape()
    elseif attributeName == EditorEvent.ON_CHANGE_ROLE_MASS then -- 改变角色质量
        self.role.mass = data
    elseif attributeName == EditorEvent.ON_CHANGE_ROLE_VELOCITY then -- 改变角色速度
        self.role.moveSpeed = data
    elseif attributeName == EditorEvent.ON_CHANGE_ROLE_IMPULSION then -- 改变角色冲力
        self.role.impulsion = data
    elseif attributeName == EditorEvent.ON_CHANGE_ROLE_FORCE then -- 改变角色力
        self.role.force = data
    elseif attributeName == EditorEvent.ON_CHANGE_ROLE_DIRECTION then -- 改变角色资源朝向
        self.role.directionLeft = data
        self.armatureRender:setScaleX(cond(self.role.directionLeft, -1, 1))
    elseif attributeName == EditorEvent.ON_CHANGE_ROLE_DFT_SKILL_IDX then -- 改变默认技能下标
        self.role.defaultSkillIndex = data
    else
        if attributeName > EditorEvent.ROLE_CONTEXT_BEGIN and attributeName < EditorEvent.ROLE_CONTEXT_END then
            if attributeName > EditorEvent.ROLE_ACTION_BEGIN and attributeName < EditorEvent.ROLE_ACTION_END then
                self.timelineDocMng:setCurShowDocument(self.roleActionDoc)
                self.roleActionDoc:revokeAttributeChange(attributeName, data)
            elseif attributeName > EditorEvent.ROLE_SKILL_BEGIN and attributeName < EditorEvent.ROLE_SKILL_END then
                self.timelineDocMng:setCurShowDocument(self.roleSkillDoc)
                self.roleSkillDoc:revokeAttributeChange(attributeName, data)
            end
        else
            EditorRole.super.revokeAttributeChange(self, attributeName, data)
        end
	end
end

--------------------------------------------------------- 属性更改/撤销相关 end ---------------------------------------------------------

-- @brief 画布缩放发生改变
function EditorRole:onRenderScaleChange(scale)
    for k, v in pairs(self.timelineDocMng:getDocuments()) do
        v:onRenderScaleChange(scale)
    end
end

-- @brief timeline GUI绘制
function EditorRole:onTimelineGUI()
    self.timelineDocMng:onGUI()
end

-- 角色底座范围颜色
local bottom_color        = cc.c4f(1.0, 0.65, 0, 1)
local bottom_full_color   = cc.c4f(1.0, 0.65, 0, 0.5)

-- 角色身体范围颜色
local body_color        = cc.c4f(0.0, 0.8, 0.0, 0.4)
local body_full_color   = cc.c4f(0.0, 0.8, 0.0, 0.1)

-- 角色半径颜色
local radius_color      = cc.c4f(0.3, 0.3, 0.8, 1)
local radius_full_color = cc.c4f(0.3, 0.3, 0.8, 0.3)


function EditorRole:syncRoleShape()
    self.roleShapRender:clear()

    -- 角色半径绘制
    local radius = self.role.radius    
    self:drawRoleRect(600, radius * 2, radius_full_color, radius_color)

    local size = self.role.roleSize
    -- 底座范围绘制
    self:drawRoleRect(size.x, size.z, bottom_full_color, bottom_color)

    -- 身体范围绘制
    self:drawRoleRect(size.x, size.y, body_full_color, body_color, cc.p(0, size.y * 0.5))
end


function EditorRole:drawRoleRect(width, height, fullColor, frameColor, offset)
    local origin      = cc.p(-width * 0.5, -height * 0.5)
    local destination = cc.p(width * 0.5, height * 0.5)

    if offset then
        origin.x = origin.x + offset.x
        origin.y = origin.y + offset.y
        destination.x = destination.x + offset.x
        destination.y = destination.y + offset.y
    end
    
    self.roleShapRender:drawSolidRect(origin, destination, fullColor)
    self.roleShapRender:drawRect(origin, destination, frameColor)
end

return EditorRole

