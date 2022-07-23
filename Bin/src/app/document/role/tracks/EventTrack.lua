-- @Author : fc
-- @Date   : 2021-12-31 15:08:54
-- @remark : 力施加轨道


local TrackHelper = import(".TrackHelper")
local EventTrack = class("EventTrack", import(".BaseTrack"))


EventTrack.NameLang = "GFrameType.EVENT_FRAME"
EventTrack.Type = GFrameType.EVENT_FRAME

local GFrameTypeNames = enum_names("GFrameType")

-- @brief 创建新的轨道
function EventTrack:newTrack(cb)
    -- 轨道名称
    local curText = ""

    ------------------------------------------ GEventFrame ------------------------------------------
    -- 最大触发次数,0为一直触发
    local triggerMaxCount = 0
    -- 触发间隔,默认0
    local triggerInterval = 0
    
    ------------------------------------------ GForceFrame ------------------------------------------
    local force = {0, 0, 0} -- vec3

    
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

            table.insert(track.frames, self:newFrame(triggerMaxCount, triggerInterval))

            if cb then
                cb(track)
            end
        end
    end)
    _MyG.PopupManager:addPopup(popup)
end

function EventTrack:newDefaultFrame(trackData)
    return self:newFrame(0, 0)
end

function EventTrack:newFrame(triggerMaxCount, triggerInterval)
    local frame = {}
    frame.time = 0
    frame.len = -1
    frame.triggerMaxCount = triggerMaxCount
    frame.triggerInterval = triggerInterval
    return frame
end

-- @brief 
function EventTrack:clampFrameLen(frame, track, maxTime, value)
    -- 长度最小为1
    if value <= 0 then value = -1 end

    -- 限制最大长度
    -- 获取当前帧index
    local curIdx = table.keyof(track.frames, frame)
    if curIdx and track.frames[curIdx + 1] then
        local validMaxTime = track.frames[curIdx + 1].time - 1
        local maxLen = validMaxTime - frame.time + 1
        if value > maxLen then value = maxLen end
    else
        local maxLen = maxTime - frame.time + 1
        if value > maxLen then value = maxLen end
    end
    return value
end

function EventTrack:onGUI_TrackInfo(track, curTime, maxTime, onChangePreCB, onChangeFinishCB, context)
    self:onGUI_TrackFramesMng(track, curTime, onChangePreCB, onChangeFinishCB, context)

    -- 分割线
    ImGui.Separator()

    -- track info
    ImGui.Text(GFrameTypeNames[track.type])

    local frame = TrackHelper:getCurFrame(track.frames, curTime)
    if frame == nil then return end

    -- 分割线
    ImGui.Separator()

    ImGui.Text(string.format("begin time:%d", frame.time))

    -- 帧长度
    local ok, value = ImGui.DragInt(STR("FrameLen"), frame.len)
    if ok then
        value = self:clampFrameLen(frame, track, maxTime, value)
        if frame.len ~= value then
            onChangePreCB()
            frame.len = value
            onChangeFinishCB()
        end
    end

    -- 触发次数
    ok, value = ImGui.InputInt(STR("TriggerMaxCount"), frame.triggerMaxCount)
    if ok then
        onChangePreCB()
        frame.triggerMaxCount = value
    end

    -- 触发间隔
    ok, value = ImGui.InputInt(STR("TriggerInterval"), frame.triggerInterval)
    if ok then
        onChangePreCB()
        frame.triggerInterval = value
    end

    self:onGUI_FrameCustomTrackInfo(frame, track, curTime, maxTime, onChangePreCB, onChangeFinishCB, context)
end

-- @interface
function EventTrack:onGUI_FrameCustomTrackInfo()
end

return EventTrack