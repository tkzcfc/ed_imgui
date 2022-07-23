-- @Author : fc
-- @Date   : 2021-9-2 17:15:19
-- @remark : 角色技能

local TrackHelper = require("app.document.role.tracks.TrackHelper")
local ChannelHelper = require("app.document.role.channel.ChannelHelper")
local RoleTimelineBase = require("app.document.role.RoleTimelineBase")

local VecZero = VecZero
local GFrameType = GFrameType

local RoleSkill = class("RoleSkill", RoleTimelineBase)

local IsShapeFrame = {
	[GFrameType.ATT_COLLISION_FRAME] = true,
	[GFrameType.DEF_COLLISION_FRAME] = true,
}

local BASE_VALUE = 10000

function RoleSkill:ctor(editorRole)
	RoleSkill.super.ctor(self, editorRole, RoleDocName[RoleDocType.SKILL])
	
	-- 当前编辑的技能下标
	self.curDataIndex = 1
	-- 当前编辑的轨道下标
	self.curEditTrackIndex = -1
	-- 当前编辑的通道下标
	self.curEditChannelIndex = -1



	-- 添加支持的轨道类型
	self.supportTracks = {
		require("app.document.role.tracks.PhysicalForceTrack"),
		require("app.document.role.tracks.AudioTrack"),
		require("app.document.role.tracks.ScriptTrack"),
		require("app.document.role.tracks.AttackTrack"),
		require("app.document.role.tracks.DefTrack"),
	}

	self.typeTrackMap = {}
	for k, v in pairs(self.supportTracks) do
		self.typeTrackMap[v.Type] = v
	end

	local RoleSkillDoc = require("app.document.role.RoleSkillDoc")

	-- 中间document绘制
    self.docMng = require("app.imgui.DocumentManager").new()
	self.docMng:addDocument(RoleSkillDoc.new(STR("role_skill_actions"))):setGUICallback(handler(self, self.onGUI_ActList))
	self.docMng:addDocument(RoleSkillDoc.new(STR("role_skill_tracks"))):setGUICallback(handler(self, self.onGUI_TrackList))
	self.docMng:addDocument(RoleSkillDoc.new(STR("role_skill_channels"))):setGUICallback(handler(self, self.onGUI_ChannelList))
	
	------------------------------------ 轨道列表绘制时的回调函数  ------------------------------------
	self.fTrackList_onSelectTrackCB = function(index)
		self:selectTrackIndex(index)
	end
	self.fTrackList_onChangeTrackPreCB = function()
		self:onAttributeChange(EditorEvent.ON_CHANGE_ROLE_SKILL)
	end

	------------------------------------ 轨道详情绘制时的回调函数  ------------------------------------
	self.fTrackInfo_onChangePreCB = function()
		self:onAttributeChange(EditorEvent.ON_CHANGE_ROLE_SKILL)
	end
	self.fTrackInfo_onChangeFinishCB = function()
		self:syncSequentity()
	end

	------------------------------------ 通道列表绘制时的回调函数  ------------------------------------
	self.fChannelList_onSelectChannelCB = function(index)
		self:selectChannelIndex(index)
	end
	self.fChannelList_onChangeChannelPreCB = function()
		self:onAttributeChange(EditorEvent.ON_CHANGE_ROLE_SKILL)
	end


	G_SysEventEmitter:on(SysEvent.ON_EDIT_CONTEXT_INIT_EVENT, function(context)
		if context == editorRole then
			self:initEventBySysRecipient()
		end
	end, self)

	G_SysEventEmitter:on(SysEvent.ON_ROLE_ACTION_ID_CHANGE, function(edRole, oldActId, newActId)
		if self.editorRole == edRole then
			local skillInfo = self.editorRole.role.skillInfo
			for k, v in pairs(skillInfo) do
				for idx, info in pairs(v.arrActInfo or {}) do
					if info.id == oldActId then
						v.arrActInfo[idx].id = newActId
					end
				end
			end
		end
	end, self)
end

-- @brief 使用编辑器的sysRecipient初始化事件
function RoleSkill:initEventBySysRecipient()
	self.editorRole.sysRecipient:on(SysEvent.ON_WINDOW_GUI_ROLE_SKILL, function()
		if self:isVisible() then
			self:GUI_RoleSkillWindow()
		end
	end)
end

-- @brief 显示
-- @override
function RoleSkill:onShow()
	RoleSkill.super.onShow(self)
	self:setCurEditSkillIndex(self.curDataIndex, self.sequentity:getCurrentTime(), self.curEditTrackIndex, self.curEditChannelIndex, self.curSkillActs_ActIndex)
end

--------------------------------------------------------- 属性更改/撤销相关 begin ---------------------------------------------------------

-- @brief
-- @override
function RoleSkill:onEventMoveTime(track_count, channel_count, event_count, curTime, channel)
	local channelType = channel.type
	if channelType == 0 then
		return
	end

	-- 通道
	if channelType > BASE_VALUE then
		local channelIndex = math.floor(channelType / BASE_VALUE)
		local conditionIndex = channelType % BASE_VALUE

		local actInfo = self.dataInfo[self.curDataIndex]
		if actInfo == nil then return end
		
		local curChannel = actInfo.channels[channelIndex]
		if curChannel == nil then return end

		local condition = curChannel.conditions[conditionIndex]
		if condition == nil then return end
		
		self:onAttributeChange(EditorEvent.ON_CHANGE_ROLE_SKILL)
		condition.beginFrame = curTime
		
		if condition.frameLen < 0 then
			oRoutine(o_once(function()
				self:syncSequentity()
			end))
		end
	else
		local actInfo = self.dataInfo[self.curDataIndex]
		if actInfo == nil then
			return
		end

		local track = actInfo.tracks[channel_count + 1]
		if track == nil then return end

		local frame = track.frames[event_count + 1]
		if frame == nil then return end

		self:onAttributeChange(EditorEvent.ON_CHANGE_ROLE_SKILL)

		frame.time = curTime

		if frame.len < 0 then
			oRoutine(o_once(function()
				self:syncSequentity()
			end))
		end
	end
end

-- @brief
-- @override
function RoleSkill:onClickSequentityChannel(track_count, channel_count, channel)
	local channelType = channel.type

	if channelType == 0 then
		return
	end

	-- 通道
	if channelType > BASE_VALUE then
		local channelIndex = math.floor(channelType / BASE_VALUE)
		local conditionIndex = channelType % BASE_VALUE

		local actInfo = self.dataInfo[self.curDataIndex]
		if actInfo == nil then return end

		local curChannel = actInfo.channels[channelIndex]
		if curChannel then
			if self.curEditChannelIndex == channelIndex then
				if curChannel.curIndex == conditionIndex then
					-- curChannel.curIndex = -1
				else
					curChannel.curIndex = conditionIndex
					oRoutine(o_once(function()
						self:syncSequentity()
					end))
				end
			else
				curChannel.curIndex = conditionIndex
				oRoutine(o_once(function()
					self:selectChannelIndex(channelIndex)
				end))
			end
		end
	else
		oRoutine(o_once(function()
			if self.curEditTrackIndex == channelType then
				self:selectTrackIndex(-1)                   
			else
				self:selectTrackIndex(channelType)
			end
		end))
	end
end

-- @brief 序列化
function RoleSkill:serialize()
	local data = RoleSkill.super:serialize(self)
	data.curDataIndex = self.curDataIndex
	return data
end

-- @brief 反序列化
function RoleSkill:deserialize(data)
	self.dataInfo = self.editorRole.role.skillInfo

	RoleSkill.super:deserialize(data)

	-- 当前选中的技能
	if #self.dataInfo > 0 then
		if data.curDataIndex and data.curDataIndex > #self.dataInfo then
			data.curDataIndex = 1
		end
	end
	self:setCurEditSkillIndex(data.curDataIndex or 1)

	self:stopAutoPlay()
end

-- @brief 保存局部快照时,此函数返回改变属性要存储的数据
-- 如果返回为nil则Context保存全局快照
function RoleSkill:doPartMementoGen(attributeName)
	if attributeName == EditorEvent.ON_CHANGE_ROLE_SKILL then
		local data = {
			skillInfo = self.dataInfo,
			curDataIndex = self.curDataIndex,
			curTime = self.sequentity:getCurrentTime(),
			trackIndex = self.curEditTrackIndex,
			channelIndex = self.curEditChannelIndex,
			actIndex = self.curSkillActs_ActIndex,
		}

		return data
	else
		return RoleSkill.super.doPartMementoGen(self, attributeName)
	end
end

-- @brief 撤销属性改变
-- 撤销的属性改变是保存的局部快照时,根据 data 字段对元素进行还原操作
-- @param attributeName 改变的属性名称
-- @param data doPartMementoGen 返回的局部快照数据
function RoleSkill:revokeAttributeChange(attributeName, data)
	if attributeName == EditorEvent.ON_CHANGE_ROLE_SKILL then
		self.editorRole.role.skillInfo = data.skillInfo
		self.dataInfo = self.editorRole.role.skillInfo

		G_SysEventEmitter:emit(SysEvent.ON_REBUILD_SKILL_NAME_NTF, self.editorRole)
		self:setCurEditSkillIndex(data.curDataIndex, data.curTime, data.trackIndex, data.channelIndex, data.actIndex)
	else
		RoleSkill.super.revokeAttributeChange(self, attributeName, data)
	end
	self:stopAutoPlay()
end

--------------------------------------------------------- 属性更改/撤销相关 end ---------------------------------------------------------

-- @brief Role Skill 窗口GUI逻辑
function RoleSkill:GUI_RoleSkillWindow()
	ImGui.BeginChild("left", cc.p(ImGui.GetWindowWidth() * 0.33, 0))--, true, 0)
		self:onGUI_SkillList()
	ImGui.EndChild()

	ImGui.SameLine()
	ImGui.BeginChild("right", VecZero)--, true, 0)
		self.docMng:onGUI()
	ImGui.EndChild()
end

-- @brief 动作列表
function RoleSkill:onGUI_ActList()
	local curSkillData = self.dataInfo[self.curDataIndex]
	if not curSkillData then return end

	-- 角色的全部动作信息
	local actInfo = self.editorRole.role.actInfo

	-- 添加动作
	if ImGui.Button(STR("RoleSkillAddAction")) then
		ImGui.OpenPopup("add_act_to_skill")
	end
	
    if ImGui.BeginPopup("add_act_to_skill") then		
        for k, v in pairs(actInfo) do
            if ImGui.MenuItem(v.name) then
				self:onAttributeChange(EditorEvent.ON_CHANGE_ROLE_SKILL)
				table.insert(curSkillData.arrActInfo, {
					id = v.id,
					loopCount = 1,
				})
            end
        end
        ImGui.EndPopup()
    end

	-- 动作列表数据删选
    local acts = {}
    for k, v in pairs(curSkillData.arrActInfo or {}) do
        local find = false
        for _, info in pairs(actInfo) do
            if v.id == info.id then
                table.insert(acts, {
					info = info,
					data = v,
				})
                find = true
            end
        end

        if not find then
            table.insert(acts, {
                info = {
					name = string.format("invalid action(id:%d)", id),
					invalid = true,
				},
				data = v,
            })
        end
    end

	ImGui.BeginChild("acts", cc.p(0, ImGui.GetWindowHeight() * 0.3), true, 0)
        for k, v in pairs(acts) do
            if v.info.invalid then
                ImGui.PushStyleColor(ImGuiCol_Text, INVALID_TEXT_COLOR)
            end

            if ImGui.Selectable(v.info.name, self.curSkillActs_ActIndex == k) then
				self.curSkillActs_ActIndex = k
			end

            if v.info.invalid then
                ImGui.PopStyleColor()
            end
        end
    ImGui.EndChild()

	-- 动作信息
	local curAct = acts[self.curSkillActs_ActIndex]
	if curAct == nil then return end

	local curActData = curAct.data

	
	ImGui.BeginChild("actInfo", VecZero, true, 0)
		local ok, count = ImGui.InputInt("loop", curActData.loopCount)
		if ok and curActData.loopCount ~= count then
			self:onAttributeChange(EditorEvent.ON_CHANGE_ROLE_SKILL)
			curActData.loopCount = count
		end
    ImGui.EndChild()
end

-- @brief 轨道信息
function RoleSkill:onGUI_TrackInfo()
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
function RoleSkill:onGUI_TrackList()
	local curSkillData = self.dataInfo[self.curDataIndex]
	if not curSkillData then return end

	if ImGui.Button(STR("RoleSkillAddTrack")) then
		ImGui.OpenPopup("role_action_add_track")
	end

	-- 添加轨道弹窗
	if ImGui.BeginPopup("role_action_add_track") then
		for k, v in pairs(self.supportTracks) do
			if ImGui.Selectable(STR(v.NameLang)) then
				v:newTrack(function(data)
					self:onAttributeChange(EditorEvent.ON_CHANGE_ROLE_SKILL)
					
					table.insert(curSkillData.tracks, data)

					self:selectTrackIndex(#curSkillData.tracks)
					G_SysEventEmitter:emit(SysEvent.ON_SHOW_BOTTOM_DOCUMENT, "timeline")
				end)
			end
		end
		ImGui.EndPopup()
	end

    -- 轨道列表
    ImGui.BeginChild("track_list", cc.p(0, ImGui.GetWindowHeight() * 0.3), true, 0)
		-- 轨道列表绘制
		TrackHelper:onGUI_TrackList(curSkillData.tracks, self.curEditTrackIndex, self.fTrackList_onSelectTrackCB, self.fTrackList_onChangeTrackPreCB)
    ImGui.EndChild()

	ImGui.BeginChild("track_info", VecZero, true, 0)
		self:onGUI_TrackInfo()
    ImGui.EndChild()
end

-- @brief 通道列表
function RoleSkill:onGUI_ChannelList()
	local curSkillData = self.dataInfo[self.curDataIndex]
	if not curSkillData then return end

	if ImGui.Button(STR("RoleSkillAddChannel")) then
		-- 添加通道弹窗
		local popup = require("app.imgui.popup.RoleAddChannel").new()
		popup:setShowData(self.editorRole.role, self.curDataIndex, function(newChannel)
			self:onAttributeChange(EditorEvent.ON_CHANGE_ROLE_SKILL)

			table.insert(curSkillData.channels, newChannel)
			self:selectChannelIndex(#curSkillData.channels)
			G_SysEventEmitter:emit(SysEvent.ON_SHOW_BOTTOM_DOCUMENT, "timeline")
		end)
		_MyG.PopupManager:addPopup(popup)
	end
	

    -- 通道列表
    ImGui.BeginChild("channel_list", cc.p(ImGui.GetWindowWidth() * 0.3, 0), true, 0)
		-- 通道列表绘制
		ChannelHelper:onGUI_ChannelList(curSkillData.channels, self.curEditChannelIndex, self.fChannelList_onSelectChannelCB, self.fChannelList_onChangeChannelPreCB)
    ImGui.EndChild()

	ImGui.SameLine()
	ImGui.BeginChild("channel_info", VecZero, true, 0)
		ChannelHelper:onGUI_ChannelInfo(curSkillData.channels[self.curEditChannelIndex], self, self.fChannelList_onChangeChannelPreCB)
    ImGui.EndChild()
end

-- @brief 技能列表
function RoleSkill:onGUI_SkillList()
	-- 技能列表
	ImGui.Text(STR("skills"))
	ImGui.SameLine()
	if ImGui.Button(STR("RoleSkillAddSkill")) then
		local popup = require("app.imgui.popup.RoleAddSkill").new()
		popup:setShowData(self.editorRole.role, function(newSkill)
			self:onAttributeChange(EditorEvent.ON_CHANGE_ROLE_SKILL)

			table.insert(self.dataInfo, newSkill)

			if #self.dataInfo == 1 then
				self:setCurEditSkillIndex(1)
			end
			G_SysEventEmitter:emit(SysEvent.ON_SHOW_BOTTOM_DOCUMENT, "timeline")
			G_SysEventEmitter:emit(SysEvent.ON_REBUILD_SKILL_NAME_NTF, self.editorRole)
		end)
		_MyG.PopupManager:addPopup(popup)
	end

	-- 分割线
	ImGui.Separator()

	-- 技能列表
	for k, v in pairs(self.dataInfo) do
		if ImGui.Selectable(v.name, self.curDataIndex == k) then
			if self.curDataIndex ~= k then
				self:setCurEditSkillIndex(k)
			end
		end

		-- 点击右键,弹出选项
		if ImGui.IsMouseReleased(1) and ImGui.IsItemHovered(ImGuiHoveredFlags_AllowWhenBlockedByPopup) then
			ImGui.OpenPopup("role_edit_skill_menu")
			self.skillMeunRClickIdx = k
		end		
	end

	if ImGui.BeginPopup("role_edit_skill_menu") then
		if ImGui.MenuItem(STR("EA_EDIT")) then
			local info = self.dataInfo[self.skillMeunRClickIdx]
			-- 编辑弹窗弹出
			local popup = require("app.imgui.popup.RoleEditSkill").new()
			popup:setShowData(self.editorRole.role, info, function(name, id, arrActInfo)
				self:onAttributeChange(EditorEvent.ON_CHANGE_ROLE_SKILL)

				local changeName = (info.name ~= name)
				local oldId = info.id

				info.id = id
				info.name = name
				info.arrActInfo = arrActInfo
				self:setCurEditSkillIndex(self.curDataIndex, self.sequentity:getCurrentTime(), self.curEditTrackIndex, self.curEditChannelIndex, self.curSkillActs_ActIndex)

				if changeName then
					G_SysEventEmitter:emit(SysEvent.ON_REBUILD_SKILL_NAME_NTF, self.editorRole)
				end

				-- 技能id发生变化
				if oldId ~= id then
					-- 遍历技能通道，更改对应的id
					for _, v in pairs(self.dataInfo) do
						for __, channel in pairs(v.channels) do
							if channel.nextSkillId == oldId then
								channel.nextSkillId = id
							end
						end
					end
				end
			end)
			_MyG.PopupManager:addPopup(popup)
		end
		ImGui.EndPopup()
	end
end

-- @brief 技能id变化
-- @param oldId 以前的id
-- @param newId 现在新的id(如果为-1则表示删除次技能)
function RoleSkill:onChangeSkillId(oldId, newId)
	for k, v in pairs(self.dataInfo) do
		if v.nextSkillId == oldId then
			v.nextSkillId = newId
		end
	end
end

-- @brief 时间帧数改变
function RoleSkill:onTimeChange()
	if self.curSkillData == nil then return end

	-- 计算当前帧对应的动作和该动作的时间
	local actInfo, actTime = self:getCurActionAndTime()
	
	self.editorRole.armatureRender:play(actInfo.playName, false)
	self.editorRole.armatureRender:setFrame(actTime)

	self:syncSequentity()
end

-- @brief 形状编辑数据之后
function RoleSkill:onShapeEditChangeFinish(render) 
    local curSkillData = self.dataInfo[self.curDataIndex]
    if curSkillData == nil then return end
    
    local curTrack = curSkillData.tracks[self.curEditTrackIndex]
    if curTrack == nil then return end

    local curFrame = TrackHelper:getCurFrame(curTrack.frames, self.curTime)
    if curFrame == nil then return end

    self:onAttributeChange(EditorEvent.ON_CHANGE_ROLE_SKILL)

    curFrame.shapeData = render:getShape():serialize()
end


-- @brief 设置当前正在编辑的技能下标
-- @param skillIndex 技能下标
-- @param time 当前时间
-- @param trackIndex 轨道下标
-- @param channelIndex 通道下标
-- @param actIndex 动作下标
function RoleSkill:setCurEditSkillIndex(skillIndex, time, trackIndex, channelIndex, actIndex)
	skillIndex = skillIndex or 1
	time = time or 0
	trackIndex = trackIndex or 1
	channelIndex = channelIndex or 1
	
	self.curSkillActs_ActIndex = actIndex or 1
	self.dataInfo = self.editorRole.role.skillInfo

	self.curDataIndex = skillIndex
	self:syncCurSkillData()

	if self.curDataIndex == -1 then
		self.curTime = -1
		self.sequentity:setRange(0, 100)
		self.sequentity:setCurrentTime(0)
		return
	end

	-- 重置时间轴
	self.curTime = -1
	self.sequentity:setRange(0, self.curSkillTotalTime - 1)
	self.sequentity:setCurrentTime(time)
end

-- @brief 将编辑存储的数据转换为当前编辑的数据格式
function RoleSkill:syncCurSkillData()
	self.curSkillData = nil

	local curSkillData = self.dataInfo[self.curDataIndex]
	if curSkillData == nil then
		self.curDataIndex = -1
		self.curEditTrackIndex = -1
		self.curEditChannelIndex = -1
		return
	end

	self.curSkillData = {}
	-- 当前技能名称
	self.curSkillData.name = curSkillData.name
	-- 当前技能Id
	self.curSkillData.id = curSkillData.id

	-- 当前技能由哪几个动作组成
	local arrActInfo = curSkillData.arrActInfo or {}

	-- 角色身上的动作信息
	local actInfoList = {}
	for idx, info in pairs(arrActInfo) do
		local find = false
		for k, v in pairs(self.editorRole.role.actInfo) do
			if v.id == info.id then
				find = true
				table.insert(actInfoList, v)
			end
		end
		if not find then
			local str = fmt(STR("SkillActCannotFind"), info.name, idx, id)
			logE(str)
		end
	end
	self.curSkillData.actInfoList = actInfoList

	-- 当前技能总时间
	local totalTime = 0
	for k, v in pairs(actInfoList) do
		totalTime = totalTime + (v.max - v.min + 1)
	end
	self.curSkillTotalTime = totalTime
end

-- @brief 同步形状渲染
function RoleSkill:syncShapeRender()
	if self.curSkillData == nil then
		self:resizeShapeRender(0)
		return
	end
	
	-------------------------------------------------------- 技能信息里面的形状 --------------------------------------------------------
	local skillTracks = {}

	local curData = self.dataInfo[self.curDataIndex]
	if curData then
		for k, v in pairs(curData.tracks) do
			if IsShapeFrame[v.type] then
				if TrackHelper:getCurFrame(v.frames, self.curTime) then
					table.insert(skillTracks, v)
				end
			end
		end
	end
	
	local shapeCount = #skillTracks

	---------------------------------------------------------- 动作里面的形状 ----------------------------------------------------------
	-- 计算当前帧对应的动作和该动作的时间
	local actInfo, actTime = self:getCurActionAndTime()
	for k, v in pairs(actInfo.tracks) do
		if TrackHelper:getCurFrame(v.frames, actTime) then
			shapeCount = shapeCount + 1
		end
	end


	-- 重置形状数量
	self:resizeShapeRender(shapeCount)

	local index = 0
	local curFrame
	-- 先绘制动作里面的形状数据
	for k, v in pairs(actInfo.tracks) do
		curFrame = TrackHelper:getCurFrame(v.frames, actTime)
		if curFrame then
			index = index + 1
			self.shapeRenders[index]:setShapeData(v.shape, curFrame.shapeData, false)
		end
	end
	-- 后绘制技能里面的形状数据
	for k, v in pairs(skillTracks) do
		curFrame = TrackHelper:getCurFrame(v.frames, self.curTime)
		if curFrame then
			index = index + 1
			self.shapeRenders[index]:setShapeData(v.shape, curFrame.shapeData, self.curEditTrackIndex == k and not self.isPlaying)
		end
	end
end

-- @brief 同步时间轴相关
function RoleSkill:syncSequentity()
	self:syncShapeRender()
	
	if self.curSkillData == nil then
		return
	end
    local actInfo = self.dataInfo[self.curDataIndex]
    if actInfo == nil then return end
	
	self.sequentity:clearTrack()

	
	-- 绘制技能中的转换通道
	local maxTime = self.sequentity:getMax()
    for k, v in pairs(actInfo.channels) do
		local track = self.sequentity:addTrack()
		track.label = "<-" .. v.name .. "->"

		for index, condition in pairs(v.conditions) do
			local channel = self.sequentity:addChannel(track, BASE_VALUE * k + index)
			channel.label = condition.name
			channel.can_overlap = false
			channel.is_active = v.curIndex == index

			local event = self.sequentity:addEvent(channel)
			event.time = condition.beginFrame

			if condition.frameLen > 0 then
				event.length = condition.frameLen
			else
				-- 自动往后延展
				event.length = maxTime - event.time
				if event.length <= 0 then
					event.length = 1 
				end
			end
		
			event.enabled = true
			-- 技能里面的帧随便移动
			event.canmove = true--frame.time > 0
			event.move_min = 0
			event.move_max = self.curSkillTotalTime
			event.color = CHANNEL_EVENT_COLOR
		end
    end


	-- 先绘制技能中的帧事件
    local track = self.sequentity:addTrack()
    track.label = "tracks"

	local maxTime = self.sequentity:getMax()
    for k, v in pairs(actInfo.tracks) do
        local channel = self.sequentity:addChannel(track, k)
        channel.label = v.name
        channel.can_overlap = false
        channel.is_active = self.curEditTrackIndex == k
		channel.color = TRANCK_EVENT_COLOR_MAP[v.type] or TRANCK_EVENT_COLOR

        for index, frame in pairs(v.frames) do
            local event = self.sequentity:addEvent(channel)
            event.time = frame.time

			-- if IsShapeFrame[v.type] then
			-- 	event.length = 1
			-- else
				if frame.len > 0 then
					event.length = frame.len
				else
					-- 自动往后延展
					local nextFrame = v.frames[index + 1]
					local maxValue = maxTime
					if nextFrame then
						maxValue = nextFrame.time
					end
					event.length = maxValue - event.time
					if event.length <= 0 then asset(0) end
				end
			-- end
            event.enabled = true
			-- 技能里面的帧随便移动
            event.canmove = true--frame.time > 0
            event.move_min = 0
            event.move_max = self.curSkillTotalTime
            event.color = TRANCK_EVENT_COLOR_MAP[v.type] or TRANCK_EVENT_COLOR
        end
    end

	-- 绘制动作信息帧事件
	local beginTime = 0
	for _, actInfo in pairs(self.curSkillData.actInfoList) do
		local track = self.sequentity:addTrack()
		track.label = actInfo.name
	
		for k, v in pairs(actInfo.tracks) do
			local channel = self.sequentity:addChannel(track, 0)
			channel.label = v.name
			channel.can_overlap = false
			channel.is_active = false
			channel.color = TRANCK_EVENT_COLOR_MAP[v.type] or TRANCK_EVENT_COLOR

			local fLen = #v.frames
			for fcount, frame in pairs(v.frames) do
				local event = self.sequentity:addEvent(channel)
				event.time = beginTime + frame.time
				event.enabled = true
				event.canmove = false
				event.move_min = actInfo.min
				event.move_max = actInfo.max
				event.color = TRANCK_EVENT_COLOR_MAP[v.type] or TRANCK_EVENT_COLOR

				local length = 0
				if fcount < fLen then
					length = v.frames[fcount + 1].time - frame.time
				else
					length = (actInfo.max - actInfo.min + 1) - frame.time
				end
				if length < 1 then length = 1 end
				event.length = length
			end
		end
		beginTime = beginTime + (actInfo.max - actInfo.min + 1)
	end
end

-- @brief 计算当前帧对应的动作和该动作的时间
function RoleSkill:getCurActionAndTime()
	local time = self.sequentity:getCurrentTime()
	local current = 0

	for k, v in pairs(self.curSkillData.actInfoList) do
		local new = current + (v.max - v.min + 1)
		if time >= current and time < new then
			return v, time - current
		end
		current = new
	end
end

function RoleSkill:selectTrackIndex(index)
    index = index or 1
	
    local actInfo = self.dataInfo[self.curDataIndex]
    if actInfo == nil then
        self.curEditTrackIndex = -1
        self:syncSequentity()
        return
    end

    if actInfo.tracks[index] == nil then
        self.curEditTrackIndex = -1
        self:syncSequentity()
        return
    end

    self.curEditTrackIndex = index
    self:syncSequentity()
end

-- @brief 通道选择
function RoleSkill:selectChannelIndex(index)
	index = index or 1
	
    local actInfo = self.dataInfo[self.curDataIndex]
    if actInfo == nil then
        self.curEditChannelIndex = -1
        self:syncSequentity()
        return
    end

    if actInfo.channels[index] == nil then
        self.curEditChannelIndex = -1
        self:syncSequentity()
        return
    end

    self.curEditChannelIndex = index
    self:syncSequentity()
end

return RoleSkill