-- @Author : fc
-- @Date   : 2022-1-30 18:20:15
-- @remark : 自定义脚本条件

local ScriptCondition = class("ScriptCondition")

-- 类型名称
ScriptCondition.NameLang = "GConditionType.SCRIPT_CONDITION"
-- 类型
ScriptCondition.Type = GConditionType.SCRIPT_CONDITION


local MAX_SCRIPT_ARG_LEN = 128

-- @interface
-- @brief 创建新的条件
function ScriptCondition:newCondition(roleSkillContext, cb)
    -- 条件名称
    local curText = ""

    ------------------------------------------ GCondition ------------------------------------------
    -- 起始帧
    local beginFrame = roleSkillContext.sequentity:getCurrentTime()
    -- 帧长度
    local frameLen = 0

    ------------------------------------------ GScriptCondition ------------------------------------------
    local scriptFile = ""
    local argStr = ""
    local isScriptCode = false


    local popup = require("app.imgui.Popup").new()
    popup:setWindowFlag(ImGuiWindowFlags_AlwaysAutoResize)
    popup:setGUICallback(function()
        local _, curTime = ImGui.SliderInt(STR("condition_begin_frame"), beginFrame, roleSkillContext.sequentity:getMin(), roleSkillContext.sequentity:getMax(), "%d")
        beginFrame = curTime
        
        local _, curTime = ImGui.SliderInt(STR("condition_frame_len"), frameLen, 0, roleSkillContext.sequentity:getMax(), "%d")
        frameLen = curTime

        -- 是否是脚本代码
        local ok, value = ImGui.Checkbox(STR("IsScriptCode"), isScriptCode)
        if ok then
            isScriptCode = value
        end
        
        -- 脚本文件
        ok, value = Tools:imgui_inputText(STR("ScriptFile"), scriptFile, 128, ImGuiInputTextFlags_EnterReturnsTrue)
        scriptFile = value
        
        -- 参数
        ok, value = Tools:imgui_inputText(STR("ScriptArg"), argStr, MAX_SCRIPT_ARG_LEN, ImGuiInputTextFlags_EnterReturnsTrue)
        argStr = value

        -- name
        ok, value = Tools:imgui_inputText(STR("Name"), curText, 128, ImGuiInputTextFlags_EnterReturnsTrue)
        curText = value
        
        ImGui.Separator()

        if ImGui.Button("OK", cc.p(-1, 0)) then
            -- 关闭弹窗
            popup:close()

            local condition = {
                name = curText,
                type = self.Type,
                beginFrame = beginFrame,
                frameLen = frameLen,
                scriptFile = scriptFile,
                argStr = argStr,
                isScriptCode = isScriptCode,
            }
            if cb then
                cb(condition)
            end
        end
    end)
    _MyG.PopupManager:addPopup(popup)
end

-- @interface
-- @brief
function ScriptCondition:onGUI_ConditionInfo(curCondition, onChangeChannelPreCB, roleSkillContext)

    local ok, value = ImGui.SliderInt(STR("condition_begin_frame"), curCondition.beginFrame, roleSkillContext.sequentity:getMin(), roleSkillContext.sequentity:getMax(), "%d")
    if ok then
        onChangeChannelPreCB()
        curCondition.beginFrame = value
        roleSkillContext:syncSequentity()
    end
    
    ok, value = ImGui.SliderInt(STR("condition_frame_len"), curCondition.frameLen, 0, roleSkillContext.sequentity:getMax(), "%d")
    if ok then
        onChangeChannelPreCB()
        curCondition.frameLen = value
        roleSkillContext:syncSequentity()
    end

    -- 是否是脚本代码
    ok, value = ImGui.Checkbox(STR("IsScriptCode"), curCondition.isScriptCode)
    if ok then
        onChangeChannelPreCB()
        curCondition.isScriptCode = value
    end
    
    -- 脚本文件
    ok, value = Tools:imgui_inputText(STR("ScriptFile"), curCondition.scriptFile, 128, 0)
    if ok then
        onChangeChannelPreCB()
        curCondition.scriptFile = value
    end
    
    -- 参数
    ok, value = Tools:imgui_inputText(STR("ScriptArg"), curCondition.argStr, MAX_SCRIPT_ARG_LEN, 0)
    if ok then
        onChangeChannelPreCB()
        curCondition.argStr = value
    end

    -- -- name
    -- ok, value = Tools:imgui_inputText(STR("Name"), name, 128, ImGuiInputTextFlags_EnterReturnsTrue)
    -- if ok then
    --     onChangeChannelPreCB()
    --     curCondition.name = value
    -- end
end

return ScriptCondition
