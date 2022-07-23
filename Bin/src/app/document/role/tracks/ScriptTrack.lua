-- @Author : fc
-- @Date   : 2021-12-31 18:01:10
-- @remark : 音效

local ScriptTrack = class("ScriptTrack", import(".EventTrack"))

ScriptTrack.NameLang = "GFrameType.SCRIPT_FRAME"
ScriptTrack.Type = GFrameType.SCRIPT_FRAME

local MAX_SCRIPT_ARG_LEN = 128

local InputFlags = 0--ImGuiInputTextFlags_EnterReturnsTrue


-- @brief 创建新的轨道
function ScriptTrack:newTrack(cb)
    -- 轨道名称
    local curText = ""

    ------------------------------------------ GEventFrame ------------------------------------------
    -- 最大触发次数,0为一直触发
    local triggerMaxCount = 0
    -- 触发间隔,默认0
    local triggerInterval = 0
    
    ------------------------------------------ GForceFrame ------------------------------------------
    local scriptFile = ""
    local argStr = ""
    local isScriptCode = false

    
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

        -- 是否是脚本代码
        ok, value = ImGui.Checkbox(STR("IsScriptCode"), isScriptCode)
        if ok then
            isScriptCode = value
        end
        
        -- 脚本文件
        ok, value = Tools:imgui_inputText(STR("ScriptFile"), scriptFile, 128, InputFlags)
        scriptFile = value
        
        -- 参数
        ok, value = Tools:imgui_inputText(STR("ScriptArg"), argStr, MAX_SCRIPT_ARG_LEN, InputFlags)
        argStr = value
    
        -- name
        ok, value = Tools:imgui_inputText(STR("Name"), curText, 128, InputFlags)
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

            table.insert(track.frames, self:newFrame(triggerMaxCount, triggerInterval, scriptFile, argStr, isScriptCode))

            if cb then
                cb(track)
            end
        end
    end)
    _MyG.PopupManager:addPopup(popup)
end

function ScriptTrack:newDefaultFrame(trackData)
    return self:newFrame(0, 0, "", "")
end

function ScriptTrack:newFrame(triggerMaxCount, triggerInterval, scriptFile, argStr, isScriptCode)
    local frame = ScriptTrack.super.newFrame(self, triggerMaxCount, triggerInterval)
    frame.scriptFile = scriptFile
    frame.argStr = argStr or ""
    frame.isScriptCode = isScriptCode
    return frame
end

function ScriptTrack:onGUI_FrameCustomTrackInfo(frame, track, curTime, maxTime, onChangePreCB, onChangeFinishCB, context)
    -- 脚本文件
    local ok, value = Tools:imgui_inputText(STR("ScriptFile"), frame.scriptFile, 128, InputFlags)
    if ok then
        onChangePreCB()
        frame.scriptFile = value
    end

    -- 脚本参数
    ok, value = Tools:imgui_inputText(STR("ScriptArg"), frame.argStr, MAX_SCRIPT_ARG_LEN, InputFlags)
    if ok then
        onChangePreCB()
        frame.argStr = value
    end

    
    -- 是否是脚本代码
    ok, value = ImGui.Checkbox(STR("IsScriptCode"), frame.isScriptCode)
    if ok then
        onChangePreCB()
        frame.isScriptCode = value
    end
end

return ScriptTrack