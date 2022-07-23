-- @Author : fc
-- @Date   : 2021-12-31 18:01:10
-- @remark : 音效

local AudioTrack = class("AudioTrack", import(".EventTrack"))

AudioTrack.NameLang = "GFrameType.AUDIO_FRAME"
AudioTrack.Type = GFrameType.AUDIO_FRAME


-- @brief 创建新的轨道
function AudioTrack:newTrack(cb)
    -- 轨道名称
    local curText = ""

    ------------------------------------------ GEventFrame ------------------------------------------
    -- 最大触发次数,0为一直触发
    local triggerMaxCount = 0
    -- 触发间隔,默认0
    local triggerInterval = 0
    
    ------------------------------------------ GForceFrame ------------------------------------------
    local audioName = ""

    
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
        
        -- 音效
        ok, value = Tools:imgui_inputText(STR("AudioName"), audioName, 32, ImGuiInputTextFlags_EnterReturnsTrue)
        audioName = value
    
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

            table.insert(track.frames, self:newFrame(triggerMaxCount, triggerInterval, audioName))

            if cb then
                cb(track)
            end
        end
    end)
    _MyG.PopupManager:addPopup(popup)
end

function AudioTrack:newDefaultFrame(trackData)
    return self:newFrame(0, 0, "")
end

function AudioTrack:newFrame(triggerMaxCount, triggerInterval, audioName)
    local frame = AudioTrack.super.newFrame(self, triggerMaxCount, triggerInterval)
    frame.audioName = audioName
    return frame
end

function AudioTrack:onGUI_FrameCustomTrackInfo(frame, track, curTime, maxTime, onChangePreCB, onChangeFinishCB, context)
    -- 音效
    local ok, value = Tools:imgui_inputText(STR("AudioName"), frame.audioName, 32, ImGuiInputTextFlags_EnterReturnsTrue)
    if ok then
        onChangePreCB()
        frame.audioName = value
    end
end

return AudioTrack