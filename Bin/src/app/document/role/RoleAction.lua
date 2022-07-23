-- @Author : fc
-- @Date   : 2021-9-2 17:14:30
-- @remark : 角色动作

local TrackHelper = require("app.document.role.tracks.TrackHelper")
local RoleTimelineBase = require("app.document.role.RoleTimelineBase")
local RoleAction = class("RoleAction", RoleTimelineBase)

local VecZero = VecZero
local ACTION_ID_CHANGE_OLD = 0
local ACTION_ID_CHANGE_NEW = 0

function RoleAction:ctor(editorRole)
    RoleAction.super.ctor(self, editorRole, RoleDocName[RoleDocType.ACTION])

    -- 当前编辑的动作下标
    self.curDataIndex = 1
    -- 当前编辑的轨道下标
    self.curEditTrackIndex = -1


	-- 支持添加的轨道类型
	self.supportTracks = {
		require("app.document.role.tracks.AttackTrack"),
		require("app.document.role.tracks.DefTrack"),
	}

	self.typeTrackMap = {}
	for k, v in pairs(self.supportTracks) do
		self.typeTrackMap[v.Type] = v
	end

	------------------------------------ 轨道列表绘制时的回调函数  ------------------------------------
	self.fTrackList_onSelectTrackCB = function(index)
        self:selectTrackIndex(index)
	end
	self.fTrackList_onChangeTrackPreCB = function()
		self:onAttributeChange(EditorEvent.ON_CHANGE_ROLE_ACTION)
	end

	------------------------------------ 轨道详情绘制时的回调函数  ------------------------------------
	self.fTrackInfo_onChangePreCB = function()
		self:onAttributeChange(EditorEvent.ON_CHANGE_ROLE_ACTION)
	end
	self.fTrackInfo_onChangeFinishCB = function()
		self:syncSequentity()
	end


    G_SysEventEmitter:on(SysEvent.ON_EDIT_CONTEXT_INIT_EVENT, function(context)
        if context == editorRole then
            self:initEventBySysRecipient()
        end
    end, self)
end

-- @brief 使用编辑器的sysRecipient初始化事件
function RoleAction:initEventBySysRecipient()
    self.editorRole.sysRecipient:on(SysEvent.ON_WINDOW_GUI_ROLE_ACTION, function()
        if self:isVisible() then
            self:GUI_RoleActionWindow()
        end
    end)
end

-- @brief 显示
-- @override
function RoleAction:onShow()
    RoleAction.super.onShow(self)
    self:setCurEditActIndex(self.curDataIndex, self.sequentity:getCurrentTime(), self.curEditTrackIndex)
end

-- @brief 时间帧数改变
function RoleAction:onTimeChange()
    local curActInfo = self.dataInfo[self.curDataIndex]
    if curActInfo == nil then return end

    self.editorRole.armatureRender:setFrame(self.curTime)

    self:syncSequentity()
end

-- @brief 形状编辑数据之后
function RoleAction:onShapeEditChangeFinish(render) 
    local actInfo = self.dataInfo[self.curDataIndex]
    if actInfo == nil then return end
    
    local curTrack = actInfo.tracks[self.curEditTrackIndex]
    if curTrack == nil then return end

    local curFrame = TrackHelper:getCurFrame(curTrack.frames, self.curTime)
    if curFrame == nil then return end

    self:onAttributeChange(EditorEvent.ON_CHANGE_ROLE_ACTION)

    curFrame.shapeData = render:getShape():serialize()
end


--------------------------------------------------------- 属性更改/撤销相关 begin ---------------------------------------------------------

-- @brief 序列化
function RoleAction:serialize()
    local data = RoleAction.super:serialize(self)
    data.curDataIndex = self.curDataIndex
    return data
end

-- @brief 反序列化
function RoleAction:deserialize(data)
    self.dataInfo = self.editorRole.role.actInfo

    RoleAction.super:deserialize(data)

    -- 当前选中的动作
    if #self.dataInfo > 0 then
        if data.curDataIndex and data.curDataIndex > #self.dataInfo then
            data.curDataIndex = 1
        end
    end
    self:setCurEditActIndex(data.curDataIndex or 1)

    self:stopAutoPlay()
end

-- @brief 保存局部快照时,此函数返回改变属性要存储的数据
-- 如果返回为nil则Context保存全局快照
function RoleAction:doPartMementoGen(attributeName)
    if attributeName == EditorEvent.ON_CHANGE_ROLE_ACTION or attributeName == EditorEvent.ON_CHANGE_ROLE_ACTION_ID then
        local data = {
            actInfo = self.dataInfo,
            curDataIndex = self.curDataIndex,
            curTime = self.sequentity:getCurrentTime(),
            trackIndex = self.curEditTrackIndex,
        }

        if attributeName == EditorEvent.ON_CHANGE_ROLE_ACTION_ID then
            data.oldId = ACTION_ID_CHANGE_OLD
            data.newId = ACTION_ID_CHANGE_NEW
        end

        return data
    else
        return RoleAction.super.doPartMementoGen(self, attributeName)
    end
end

-- @brief 撤销属性改变
-- 撤销的属性改变是保存的局部快照时,根据 data 字段对元素进行还原操作
-- @param attributeName 改变的属性名称
-- @param data doPartMementoGen 返回的局部快照数据
function RoleAction:revokeAttributeChange(attributeName, data)
    if attributeName == EditorEvent.ON_CHANGE_ROLE_ACTION or attributeName == EditorEvent.ON_CHANGE_ROLE_ACTION_ID then
        self.editorRole.role.actInfo = data.actInfo
        self.dataInfo = self.editorRole.role.actInfo

        if attributeName == EditorEvent.ON_CHANGE_ROLE_ACTION_ID then
            G_SysEventEmitter:emit(SysEvent.ON_ROLE_ACTION_ID_CHANGE, self.editorRole, data.newId, data.oldId)
        end
        
        self:setCurEditActIndex(data.curDataIndex, data.curTime, data.trackIndex)
    else
        RoleAction.super.revokeAttributeChange(self, attributeName, data)
    end
    self:stopAutoPlay()
end

--------------------------------------------------------- 属性更改/撤销相关 end ---------------------------------------------------------


-- @brief
-- @override
function RoleAction:onEventMoveTime(track_count, channel_count, event_count, curTime, channel)
    local actInfo = self.dataInfo[self.curDataIndex]
    if actInfo == nil then
        return
    end

    local track = actInfo.tracks[channel_count + 1]
    if track == nil then return end

    local frame = track.frames[event_count + 1]
    if frame == nil then return end

    self:onAttributeChange(EditorEvent.ON_CHANGE_ROLE_ACTION)

    frame.time = curTime
end

-- @brief
-- @override
function RoleAction:onClickSequentityChannel(track_count, channel_count)
    oRoutine(o_once(function()
        if self.curEditTrackIndex == channel_count then
            self:selectTrackIndex(-1)                   
        else
            self:selectTrackIndex(channel_count)
        end
    end))
end

-- @brief 是否是无效动作
function RoleAction:isInvalidAction(act)
    if not self.editorRole.armatureRender:hasPlayName(act.playName) then
        return true
    end
    return false
end

-- @brief Role Action 窗口GUI逻辑
function RoleAction:GUI_RoleActionWindow()
	local winWidth = ImGui.GetWindowWidth()

    ImGui.BeginChild("actions", cc.p(winWidth * 0.33, 0), false, 0)
        self:onGUI_ActList()
    ImGui.EndChild()

	ImGui.SameLine()
	ImGui.BeginChild("tracks", cc.p(winWidth * 0.33, 0), true, 0)
        self:onGUI_TrackList()
	ImGui.EndChild()

    ImGui.SameLine()    
    ImGui.BeginChild("right", VecZero, true, 0)
        self:onGUI_TrackInfo()
    ImGui.EndChild()
end

-- @brief 轨道信息
function RoleAction:onGUI_TrackInfo()
    local ok, curTime = ImGui.SliderInt("time", self.sequentity:getCurrentTime(), self.sequentity:getMin(), self.sequentity:getMax(), "frame:%d")
    if ok then
        if curTime ~= self.sequentity:getCurrentTime() then
            self:jump(curTime, true)
        end
    end

    if ImGui.ArrowButton("##last_time", ImGuiDir_Left) then
        self:step(-1)
        self:stopAutoPlay()
    end
    ImGui.SameLine()
    if ImGui.ArrowButton("##next_time", ImGuiDir_Right) then
        self:step(1)
        self:stopAutoPlay()
    end

    local actInfo = self.dataInfo[self.curDataIndex]
    if actInfo == nil or self.curTime < 0 then
        return
    end

    local track = actInfo.tracks[self.curEditTrackIndex]
    if track == nil then return end

	self.typeTrackMap[track.type]:onGUI_TrackInfo(track, self.curTime, self.sequentity:getMax(), self.fTrackInfo_onChangePreCB, self.fTrackInfo_onChangeFinishCB, self)
end

-- @brief 轨道列表
function RoleAction:onGUI_TrackList()
    -- 轨道列表
    ImGui.Text(STR("tracks"))
    ImGui.SameLine()

    if ImGui.Button(STR("RoleSkillAddTrack")) then
        ImGui.OpenPopup("role_action_add_track")
    end

    -- 添加轨道弹窗
    if ImGui.BeginPopup("role_action_add_track") then
        for k, v in pairs(self.supportTracks) do
            if ImGui.Selectable(STR(v.NameLang)) then
                v:newTrack(function(data)					
                    local actInfo = self.dataInfo[self.curDataIndex]
                    table.insert(actInfo.tracks, data)

                    self:selectTrackIndex(#actInfo.tracks)
                    G_SysEventEmitter:emit(SysEvent.ON_SHOW_BOTTOM_DOCUMENT, "timeline")
                end)
            end
        end
        ImGui.EndPopup()
    end
    
    -- 分割线
    ImGui.Separator()

    -- 轨道列表绘制
    local actInfo = self.dataInfo[self.curDataIndex]
    if actInfo then
        TrackHelper:onGUI_TrackList(actInfo.tracks, self.curEditTrackIndex, self.fTrackList_onSelectTrackCB, self.fTrackList_onChangeTrackPreCB)
    end
end

-- @brief 动作列表
function RoleAction:onGUI_ActList()
    -- 动作列表
    -- ImGui.BeginChild("act_list", cc.p(0, ImGui.GetWindowHeight() * 0.5), true, 0)
        ImGui.Text(STR("actions"))
        ImGui.SameLine()
        if ImGui.Button(STR("RoleActionAddAction")) then
            local popup = require("app.imgui.popup.RoleAddAction").new()
            popup:setShowData(self.dataInfo, self.editorRole.armatureRender, function(act)
                self:onAttributeChange(EditorEvent.ON_CHANGE_ROLE_ACTION)

                act.min = 0
                act.max = self.editorRole.armatureRender:getPlayDurationByName(playName) - 1
                table.insert(self.dataInfo, act)

                if #self.dataInfo == 1 then
                    self:setCurEditActIndex(1)
                end
                G_SysEventEmitter:emit(SysEvent.ON_SHOW_BOTTOM_DOCUMENT, "timeline")
            end)
            _MyG.PopupManager:addPopup(popup)
        end

        -- 分割线
        ImGui.Separator()

        -- 动作列表
        for k, v in pairs(self.dataInfo) do
            local pop_color = self:isInvalidAction(v)

            -- push color
            if pop_color then ImGui.PushStyleColor(ImGuiCol_Text, INVALID_TEXT_COLOR) end

            if ImGui.Selectable(v.name, self.curDataIndex == k) then
                if self.curDataIndex ~= k then
                    self:setCurEditActIndex(k)
                end
            end

            -- pop color
            if pop_color then ImGui.PopStyleColor() end

            if ImGui.IsItemHovered(0) then
                ImGui.BeginTooltip()

                if pop_color then
                    ImGui.TextColored(INVALID_TEXT_COLOR, "play name: " .. v.playName)
                    ImGui.Text("id: " .. v.id)
                    ImGui.Text(string.format("range: (%d,%d)", v.min, v.max))
                else
                    ImGui.Text("play name: " .. v.playName)
                    ImGui.Text("id: " .. v.id)
                    ImGui.Text(string.format("range: (%d,%d)", v.min, v.max))
                end

                ImGui.EndTooltip()
            end

            -- 点击右键,弹出选项
            if ImGui.IsMouseReleased(1) and ImGui.IsItemHovered(ImGuiHoveredFlags_AllowWhenBlockedByPopup) then
                ImGui.OpenPopup("role_edit_action_menu")
                self.actionMeunRClickIdx = k
            end
        end

        
        if ImGui.BeginPopup("role_edit_action_menu") then
            if ImGui.MenuItem(STR("EA_EDIT")) then
                -- 编辑动作弹窗弹出
                local popup = require("app.imgui.popup.RoleEditAction").new()
                popup:setShowData(self.dataInfo, self.editorRole.armatureRender, self.actionMeunRClickIdx, function(name, playName, id)
                    local act = self.dataInfo[self.actionMeunRClickIdx]

                    if act.id == id then
                        self:onAttributeChange(EditorEvent.ON_CHANGE_ROLE_ACTION)
                    else
                        ACTION_ID_CHANGE_OLD = act.id
                        ACTION_ID_CHANGE_NEW = id

                        self:onAttributeChange(EditorEvent.ON_CHANGE_ROLE_ACTION_ID)
                        G_SysEventEmitter:emit(SysEvent.ON_ROLE_ACTION_ID_CHANGE, self.editorRole, act.id, id)
                    end

                    act.name = name
                    act.playName = playName
                    act.id = id
                    act.min = 0
                    act.max = self.editorRole.armatureRender:getPlayDurationByName(playName) - 1
                    
                    self:setCurEditActIndex(self.actionMeunRClickIdx)
                end)
                _MyG.PopupManager:addPopup(popup)
            end

            ImGui.EndPopup()
        end

    -- ImGui.EndChild()
end

-- @brief 同步形状渲染
function RoleAction:syncShapeRender()
    local actInfo = self.dataInfo[self.curDataIndex]
    if actInfo == nil or self.curTime < 0 then
        self:resizeShapeRender(0)
        return
    end

    local shapeCount = 0
    for k, v in pairs(actInfo.tracks) do
        if TrackHelper:getCurFrame(v.frames, self.curTime) then
            shapeCount = shapeCount + 1
        end
    end

    self:resizeShapeRender(shapeCount)

    local curIndex = 0
    for k, v in pairs(actInfo.tracks) do
        local curFrame = TrackHelper:getCurFrame(v.frames, self.curTime)
        if curFrame then
            curIndex = curIndex + 1
            self.shapeRenders[curIndex]:setShapeData(v.shape, curFrame.shapeData, self.curEditTrackIndex == k and not self.isPlaying)
        end
    end
end

-- @brief 同步时间轴相关
function RoleAction:syncSequentity()
    self:syncShapeRender()

    local actInfo = self.dataInfo[self.curDataIndex]
    if actInfo == nil then return end

    self.sequentity:clearTrack()

    local track = self.sequentity:addTrack()
    track.label = "tracks"

    for k, v in pairs(actInfo.tracks) do
        local channel = self.sequentity:addChannel(track, k)
        channel.label = v.name
        channel.can_overlap = false
        channel.is_active = self.curEditTrackIndex == k
        channel.color = TRANCK_EVENT_COLOR_MAP[v.type] or TRANCK_EVENT_COLOR

        for _, frame in pairs(v.frames) do
            local event = self.sequentity:addEvent(channel)
            event.time = frame.time
            event.length = 1
            event.enabled = true
            event.canmove = frame.time > 0
            event.move_min = actInfo.min
            event.move_max = actInfo.max
            event.color = TRANCK_EVENT_COLOR_MAP[v.type] or TRANCK_EVENT_COLOR
        end
    end
end

-- @brief 设置当前正在编辑的动作下标
-- @param actIndex 动作下标
-- @param time 当前时间
-- @param trackIndex 轨道下标
function RoleAction:setCurEditActIndex(actIndex, time, trackIndex)
    actIndex = actIndex or 1
    time = time or 0

    self.dataInfo = self.editorRole.role.actInfo
    self.curDataIndex = actIndex

    self:selectTrackIndex(trackIndex)
    
    local actInfo = self.dataInfo[actIndex]
    if actInfo == nil then
        self.curEditTrackIndex = -1
        if #self.editorRole.armatureRender:getPlayNames() > 0 then
            local duration = self.editorRole.armatureRender:getPlayDuration(self.editorRole.armatureRender:getCurPlayIndex())
            if duration == nil then return end

            self.curTime = -1
            self.sequentity:setRange(0, duration - 1)
            self.sequentity:setCurrentTime(0)
        end
        return
    end

    -- 切换动画显示
    if self.editorRole.armatureRender:hasPlayName(actInfo.playName) then
        self.editorRole.armatureRender:play(actInfo.playName, false)
    end

    -- 重置时间轴
    self.curTime = -1
    self.sequentity:setRange(actInfo.min, actInfo.max)
    self.sequentity:setCurrentTime(time)
end

function RoleAction:selectTrackIndex(trackIndex)
    trackIndex = trackIndex or 1

    local actInfo = self.dataInfo[self.curDataIndex]
    if actInfo == nil then
        self.curEditTrackIndex = -1
        self:syncSequentity()
        return
    end

    if actInfo.tracks[trackIndex] == nil then
        self.curEditTrackIndex = -1
        self:syncSequentity()
        return
    end

    self.curEditTrackIndex = trackIndex
    self:syncSequentity()
end

return RoleAction
