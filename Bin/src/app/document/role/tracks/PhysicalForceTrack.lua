-- @Author : fc
-- @Date   : 2021-12-31 15:08:54
-- @remark : 力施加轨道


local PhysicalForceTrack = class("PhysicalForceTrack", import(".EventTrack"))


PhysicalForceTrack.NameLang = "GFrameType.PHYSICAL_FORCE_FRAME"
PhysicalForceTrack.Type = GFrameType.PHYSICAL_FORCE_FRAME


local valueTypeOptions = enum_options("GValueType")
local forceOrientationOptions = enum_options("GForceOrientation")
local physicalForceTypeOptions = enum_options("GPhysicalForceType")

G_SysEventEmitter:on(SysEvent.ON_CHANGE_LANG, function()
    valueTypeOptions = enum_options("GValueType")
    forceOrientationOptions = enum_options("GForceOrientation")
    physicalForceTypeOptions = enum_options("GPhysicalForceType")
end, SysEvent.TAG)

-- @brief 创建新的轨道
function PhysicalForceTrack:newTrack(cb)
    -- 轨道名称
    local curText = ""

    ------------------------------------------ GEventFrame ------------------------------------------
    -- 最大触发次数,0为一直触发
    local triggerMaxCount = 0
    -- 触发间隔,默认0
    local triggerInterval = 0
    
    ------------------------------------------ GForceFrame ------------------------------------------
    local force = {0, 0, 0} -- vec3
    local valueType = GValueType.VALUE_ABSOLUTE
    local forceOrientation = GForceOrientation.Positive_Direction
    local forceType = GPhysicalForceType.FORCE

    
    local popup = require("app.imgui.Popup").new()
    popup:setWindowFlag(ImGuiWindowFlags_AlwaysAutoResize)
    popup:setGUICallback(function()
        -- 触发次数
        local ok, value = ImGui.InputInt(STR("TriggerMaxCount"), triggerMaxCount)
        if ok then
            triggerMaxCount = value
        end

        -- 触发间隔
        ok, value = ImGui.InputInt(STR("TriggerInterval"), triggerInterval)
        if ok then
            triggerInterval = value
        end

        -- 力类型
        forceType = Tools:imguiCombo_OneLiner(STR("GPhysicalForceType"), forceType, physicalForceTypeOptions)
        
        -- 力方向
        forceOrientation = Tools:imguiCombo_OneLiner(STR("GForceOrientation"), forceOrientation, forceOrientationOptions)

        -- 力
        if forceType == GPhysicalForceType.MOVEMENT then
            ImGui.DragFloat2(STR("Value"), force, 1)
        else
            ImGui.DragFloat3(STR("Value"), force, 1)
        end

        -- 值类型
        valueType = Tools:imguiCombo_OneLiner(STR("GValueType"), valueType, valueTypeOptions)
    
        -- name
        ok, value = Tools:imgui_inputText(STR("Name"), curText, 32, ImGuiInputTextFlags_EnterReturnsTrue)
        curText = value
        
        ImGui.Separator()
    
        if ImGui.Button("OK", cc.p(-1, 0)) then
            -- 关闭弹窗
            popup:close()

            local track = {
                name = curText,
                type = self.Type,
                clamp = true,
                frames = {}
            }

            table.insert(track.frames, self:newFrame(triggerMaxCount, triggerInterval, force, valueType, forceOrientation, forceType))

            if cb then
                cb(track)
            end
        end
    end)
    _MyG.PopupManager:addPopup(popup)
end

function PhysicalForceTrack:newDefaultFrame(trackData)
    return self:newFrame(0, 0, {0, 0, 0}, GValueType.VALUE_ABSOLUTE, GForceOrientation.Positive_Direction, GPhysicalForceType.FORCE)
end

function PhysicalForceTrack:newFrame(triggerMaxCount, triggerInterval, force, valueType, forceOrientation, forceType)
    local frame = PhysicalForceTrack.super.newFrame(self, triggerMaxCount, triggerInterval)
    frame.force = {x = force[1], y = force[2], z = force[3]}
    frame.valueType = valueType
    frame.forceOrientation = forceOrientation
    frame.forceType = forceType
    return frame
end

local cache_vec3_arr = {0, 0, 0}
function PhysicalForceTrack:onGUI_FrameCustomTrackInfo(frame, track, curTime, maxTime, onChangePreCB, onChangeFinishCB, context)
    cache_vec3_arr[1] = frame.force.x
    cache_vec3_arr[2] = frame.force.y
    cache_vec3_arr[3] = frame.force.z
    
    -- 力类型
    local newValue = Tools:imguiCombo_OneLiner(STR("GPhysicalForceType"), frame.forceType, physicalForceTypeOptions)
    if newValue ~= frame.forceType then
        onChangePreCB()
        frame.forceType = newValue
    end

    -- 力
    if forceType == GPhysicalForceType.MOVEMENT then
        if ImGui.DragFloat2(STR("Force"), cache_vec3_arr, 1) then
            onChangePreCB()
            frame.force.x = cache_vec3_arr[1]
            frame.force.y = cache_vec3_arr[2]
        end
    else
        if ImGui.DragFloat3(STR("Force"), cache_vec3_arr, 1) then
            onChangePreCB()
            frame.force.x = cache_vec3_arr[1]
            frame.force.y = cache_vec3_arr[2]
            frame.force.z = cache_vec3_arr[3]
        end
    end

    -- 力方向
    newValue = Tools:imguiCombo_OneLiner(STR("GForceOrientation"), frame.forceOrientation, forceOrientationOptions)
    if newValue ~= frame.forceOrientation then
        onChangePreCB()
        frame.forceOrientation = newValue
    end

    -- 值类型
    newValue = Tools:imguiCombo_OneLiner(STR("GValueType"), frame.valueType, valueTypeOptions)
    if newValue ~= frame.valueType then
        onChangePreCB()
        frame.valueType = newValue
    end
end

return PhysicalForceTrack