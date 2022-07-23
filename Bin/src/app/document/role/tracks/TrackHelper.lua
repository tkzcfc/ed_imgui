local TrackHelper = {}




local right_click_track_index = 0

-- @brief 
-- @param tracks 轨道列表
-- @param curIndex 当前选中下标
-- @param onSelectTrackCB 选中下标回调
-- @param onChangeTrackPreCB 更改轨道数据前回调
function TrackHelper:onGUI_TrackList(tracks, curIndex, onSelectTrackCB, onChangeTrackPreCB)
    -- 轨道列表
    for k, v in pairs(tracks) do
        if ImGui.Selectable(v.name, curIndex == k) then
            if curIndex == k then
                onSelectTrackCB(-1)                   
            else
                onSelectTrackCB(k)
            end
        end

        -- 点击右键,弹出选项
        if ImGui.IsMouseReleased(1) and ImGui.IsItemHovered(ImGuiHoveredFlags_AllowWhenBlockedByPopup) then
            ImGui.OpenPopup("role_edit_action_track_menu")
            right_click_track_index = k
        end
    end

    if ImGui.BeginPopup("role_edit_action_track_menu") then
        if ImGui.MenuItem(STR("EA_DELETE")) then
            onChangeTrackPreCB()

            for k, v in pairs(tracks) do
                if k == right_click_track_index then
                    table.remove(tracks, k)
                    break
                end
            end
            
            onSelectTrackCB(-1)
            G_SysEventEmitter:emit(SysEvent.ON_SHOW_BOTTOM_DOCUMENT, "timeline")
        end

        if right_click_track_index > 1 then
            if ImGui.MenuItem(STR("MoveActUp")) then
                onChangeTrackPreCB()
                local old = tracks[right_click_track_index]
                tracks[right_click_track_index] = tracks[right_click_track_index - 1]
                tracks[right_click_track_index - 1] = old
                
                onSelectTrackCB(right_click_track_index - 1)
            end
        end

        if right_click_track_index < #tracks then
            if ImGui.MenuItem(STR("MoveActDown")) then
                onChangeTrackPreCB()
                local old = tracks[right_click_track_index]
                tracks[right_click_track_index] = tracks[right_click_track_index + 1]
                tracks[right_click_track_index + 1] = old
                
                onSelectTrackCB(right_click_track_index + 1)
            end
        end

        -- 修改名称
        if ImGui.MenuItem(STR("ModifyName")) then
            local track = tracks[right_click_track_index]

            local input = require("app.imgui.popup.InputText").new()
            input:setCurText(track.name)
            input:setInputTextCallback(function(name)
                if name == "" or track.name == name then
                    return
                end

                onChangeTrackPreCB()
                track.name = name
            end)
            _MyG.PopupManager:addPopup(input)
        end

        ImGui.EndPopup()
    end
end


function TrackHelper:getCurFrame(frames, curTime)
    for i = #frames, 1, -1 do
        local frame = frames[i]
        if curTime >= frame.time then
            -- 没有固定长度
            if frame.len < 1 then
                return frame
            else
                -- 有固定的长度
                if curTime < frame.time + frame.len then
                    return frame
                end
            end
        end
    end
end

return TrackHelper



