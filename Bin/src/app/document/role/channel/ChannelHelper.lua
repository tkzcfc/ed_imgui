


local ChannelHelper = {}

local VecZero = VecZero

ChannelHelper.supportConditions = {
    import(".ScriptCondition")
}

local ConditionMap = {}
for k, v in pairs(ChannelHelper.supportConditions) do
    ConditionMap[v.Type] = v
end

local checkTypeOptions = enum_options("GChannelCheckType")
local interruptTypeOptions = enum_options("GInterruptType")

G_SysEventEmitter:on(SysEvent.ON_CHANGE_LANG, function()
    checkTypeOptions = enum_options("GChannelCheckType")
    interruptTypeOptions = enum_options("GInterruptType")
end, SysEvent.TAG)


local right_click_index = 0
-- @brief 
-- @param channels 通道列表
-- @param curIndex 当前选中下标
-- @param onSelectTrackCB 选中下标回调
-- @param onChangeChannelPreCB 更改通道数据前回调
function ChannelHelper:onGUI_ChannelList(channels, curIndex, onSelectTrackCB, onChangeChannelPreCB)
    -- 轨道列表
    for k, v in pairs(channels) do
        if ImGui.Selectable(v.name, curIndex == k) then
            if curIndex == k then
                onSelectTrackCB(-1)                   
            else
                onSelectTrackCB(k)
            end
        end

        -- 点击右键,弹出选项
        if ImGui.IsMouseReleased(1) and ImGui.IsItemHovered(ImGuiHoveredFlags_AllowWhenBlockedByPopup) then
            ImGui.OpenPopup("role_edit_channel_menu")
            right_click_index = k
        end
    end

    if ImGui.BeginPopup("role_edit_channel_menu") then
        if ImGui.MenuItem(STR("EA_DELETE")) then
            onChangeChannelPreCB()

            for k, v in pairs(channels) do
                if k == right_click_index then
                    table.remove(channels, k)
                    break
                end
            end
            
            onSelectTrackCB(-1)
            G_SysEventEmitter:emit(SysEvent.ON_SHOW_BOTTOM_DOCUMENT, "timeline")
        end

        if right_click_index > 1 then
            if ImGui.MenuItem(STR("MoveActUp")) then
                onChangeChannelPreCB()
                local old = channels[right_click_index]
                channels[right_click_index] = channels[right_click_index - 1]
                channels[right_click_index - 1] = old
                
                onSelectTrackCB(right_click_index - 1)
            end
        end

        if right_click_index < #channels then
            if ImGui.MenuItem(STR("MoveActDown")) then
                onChangeChannelPreCB()
                local old = channels[right_click_index]
                channels[right_click_index] = channels[right_click_index + 1]
                channels[right_click_index + 1] = old
                
                onSelectTrackCB(right_click_index + 1)
            end
        end

        -- 修改名称
        if ImGui.MenuItem(STR("ModifyName")) then
            local track = channels[right_click_index]

            local input = require("app.imgui.popup.InputText").new()
            input:setCurText(track.name)
            input:setInputTextCallback(function(name)
                if name == "" or track.name == name then
                    return
                end

                onChangeChannelPreCB()
                track.name = name
            end)
            _MyG.PopupManager:addPopup(input)
        end

        ImGui.EndPopup()
    end
end




-- @brief 通道详细信息
function ChannelHelper:onGUI_ChannelInfo(channel, roleSkillContext, onChangeChannelPreCB)
    if channel == nil then return end

    ImGui.BeginChild("channel_info_left", cc.p(0, ImGui.GetWindowHeight() * 0.3), true, 0)
        local index = 0
        -- local options = ""
        for k, v in pairs(roleSkillContext.dataInfo) do
            -- options = options .. v.name .. "\0"
            if channel.nextSkillId == v.id then
                index = k
            end
        end
        -- options = options .. "\0\0"

        -- 下一个技能
        local newIndex = Tools:imguiCombo_OneLiner(STR("NextSkill"), index - 1, roleSkillContext.editorRole:getSkillNameOptions())
        if index ~= newIndex + 1 then
            onChangeChannelPreCB()
            channel.nextSkillId = roleSkillContext.dataInfo[newIndex + 1].id
        end
        
        ---------------------------------------------------------------------- 通道检测类型 ----------------------------------------------------------------------
        local checkType = Tools:imguiCombo_OneLiner(STR("GChannelCheckType"), channel.checkType, checkTypeOptions)
        if checkType ~= channel.checkType then
            onChangeChannelPreCB()
            channel.checkType = checkType
        end
        ---------------------------------------------------------------------- 通道检测类型 ----------------------------------------------------------------------
        local interruptType = Tools:imguiCombo_OneLiner(STR("GInterruptType"), channel.interruptType, interruptTypeOptions)
        if interruptType ~= channel.interruptType then
            onChangeChannelPreCB()
            channel.interruptType = interruptType
        end
        
        -- 条件列表
        self:onGUI_ConditionlList(channel, onChangeChannelPreCB, roleSkillContext)
    ImGui.EndChild()
    
    ImGui.BeginChild("channel_info_right", VecZero, true, 0)
        local curIndex = channel.curIndex or -1
        local conditions = channel.conditions
        local curCondition = conditions[curIndex]
        if curCondition then
            ImGui.PushID("channel_info_right" .. tostring(curIndex))
            ConditionMap[curCondition.type]:onGUI_ConditionInfo(curCondition, onChangeChannelPreCB, roleSkillContext)
            ImGui.PopID()
        end
    ImGui.EndChild()
end


local right_click_condtion_index = -1
-- @brief 
-- @param onChangeChannelPreCB 更改通道数据前回调
function ChannelHelper:onGUI_ConditionlList(channel, onChangeChannelPreCB, roleSkillContext)
    if ImGui.Button(STR("AddCondition")) then
		ImGui.OpenPopup("role_channel_add_condition")
    end
    
	-- 添加条件弹窗
	if ImGui.BeginPopup("role_channel_add_condition") then
		for k, v in pairs(self.supportConditions) do
			if ImGui.Selectable(STR(v.NameLang)) then
				v:newCondition(roleSkillContext, function(data)
                    onChangeChannelPreCB()

					table.insert(channel.conditions, data)

                    channel.curIndex = #channel.conditions
					G_SysEventEmitter:emit(SysEvent.ON_SHOW_BOTTOM_DOCUMENT, "timeline")
                    roleSkillContext:syncSequentity()
				end)
			end
		end
		ImGui.EndPopup()
	end


    local curIndex = channel.curIndex or -1
    local conditions = channel.conditions
    -- 轨道列表
    for k, v in pairs(conditions) do
        if ImGui.Selectable(v.name, curIndex == k) then
            if curIndex == k then
                channel.curIndex = -1              
            else
                channel.curIndex = k
            end
        end

        -- 点击右键,弹出选项
        if ImGui.IsMouseReleased(1) and ImGui.IsItemHovered(ImGuiHoveredFlags_AllowWhenBlockedByPopup) then
            ImGui.OpenPopup("role_edit_channel_menu")
            right_click_condtion_index = k
        end
    end

    if ImGui.BeginPopup("role_edit_channel_menu") then
        if ImGui.MenuItem(STR("EA_DELETE")) then
            onChangeChannelPreCB()

            for k, v in pairs(conditions) do
                if k == right_click_condtion_index then
                    table.remove(conditions, k)
                    break
                end
            end

            channel.curIndex = -1
            G_SysEventEmitter:emit(SysEvent.ON_SHOW_BOTTOM_DOCUMENT, "timeline")
        end

        if right_click_condtion_index > 1 then
            if ImGui.MenuItem(STR("MoveActUp")) then
                onChangeChannelPreCB()
                local old = conditions[right_click_condtion_index]
                conditions[right_click_condtion_index] = conditions[right_click_condtion_index - 1]
                conditions[right_click_condtion_index - 1] = old
                
                channel.curIndex = right_click_condtion_index - 1
            end
        end

        if right_click_condtion_index < #conditions then
            if ImGui.MenuItem(STR("MoveActDown")) then
                onChangeChannelPreCB()
                local old = conditions[right_click_condtion_index]
                conditions[right_click_condtion_index] = conditions[right_click_condtion_index + 1]
                conditions[right_click_condtion_index + 1] = old
                
                channel.curIndex = right_click_condtion_index + 1
            end
        end

        -- 修改名称
        if ImGui.MenuItem(STR("ModifyName")) then
            local track = conditions[right_click_condtion_index]

            local input = require("app.imgui.popup.InputText").new()
            input:setCurText(track.name)
            input:setInputTextCallback(function(name)
                if name == "" or track.name == name then
                    return
                end

                onChangeChannelPreCB()
                track.name = name
            end)
            _MyG.PopupManager:addPopup(input)
        end

        ImGui.EndPopup()
    end
end

return ChannelHelper