-- @Author : fc
-- @Date   : 2021-9-8 17:10:47
-- @remark : 角色时间轴基类

local Document = require("app.imgui.Document")

local RoleTimelineBase = class("RoleTimelineBase", Document)


-- 当前帧率
local curInterval = cc.Director:getInstance():getAnimationInterval()
-- 动画帧率
local aniInterval = 1 / 60
-- 步进缩放
local STEP_SCALE = math.floor(curInterval / aniInterval)

function RoleTimelineBase:ctor(editorRole, name)
	RoleTimelineBase.super.ctor(self, name)

    self.editorRole = editorRole
 
    -- 时间轴
    self.sequentity = CSequentity()
    self.sequentity:setRange(0, 100)
    self.sequentity:registerLuaHandle("onLeftTopGUI", handler(self, self.onSequentityLTGUI))
    -- self.sequentity:registerLuaHandle("onEventMoveTimeCondition", handler(self, self.onEventMoveTimeCondition))
    self.sequentity:registerLuaHandle("onEventMoveTime", handler(self, self.onEventMoveTime))
    self.sequentity:registerLuaHandle("onClickChannel", handler(self, self.onClickSequentityChannel))

    -- 形状渲染相关
    self.shapeRenderCount = 0
    self.shapeRenders = {}
    self.operatePointScale = 1.0
    
    -- 当前时间帧
    self.curTime = -1
    -- 是否循环播放
    self.isPlayLoop = true
    -- 是否正在播放
    self.isPlaying = false

    -- 播放放慢缩放倍速(为2表示动作变慢2倍 1则正常播放速度)
    -- 此处不处理快速行为所以这个值只能大于等于1
    self.playSlowScale = 1
    
	_MyG.WindowManager:showWindow(WinTag.ROLE, true)

    -- 同步时间轴时间
    G_SysEventEmitter:on(SysEvent.ON_GUI_END, function()
        local current = self.sequentity:getCurrentTime()
        if self.curTime ~= current then
            self.curTime = current
            self:onTimeChange()
        end
    end, editorRole)
end

-- @override
function RoleTimelineBase:destroy()
    RoleTimelineBase.super.destroy(self)

    G_SysEventEmitter:offByTag(self)

    self:stopAutoPlay()

    self.editorRole = nil
    self.sequentity = nil
end

-- @override
function RoleTimelineBase:onGUI()
    RoleTimelineBase.super.onGUI(self)
    self.sequentity:onGUI()
end

-- @brief 隐藏
-- @override
function RoleTimelineBase:onHide()
    RoleTimelineBase.super.onHide(self)

    for k, v in pairs(self.shapeRenders) do
        v:setVisible(false)
    end

    -- self.oldPlayStatus = self.isPlaying
    self:stopAutoPlay()
end

-- @brief 显示
-- @override
function RoleTimelineBase:onShow()
    RoleTimelineBase.super.onShow(self)

    for k, v in pairs(self.shapeRenders) do
        v:setVisible(k <= self.shapeRenderCount)
    end

    -- if self.oldPlayStatus then
    --     self:startAutoPlay()
    -- end
end

function RoleTimelineBase:canRemove()
	return false
end

function RoleTimelineBase:canClose()
	return false
end

-- @brief 调整形状渲染器数量
function RoleTimelineBase:resizeShapeRender(shapeCount)
    if self.shapeRenderCount == shapeCount then return end
    self.shapeRenderCount = shapeCount

    -- 补充不足的
    for i = 1, shapeCount - #self.shapeRenders do
        local render = require("app.render.ShapeRender").new()
        render:setEditChangeFinishCallback(function()
            self:onShapeEditChangeFinish(render)
        end)
        render:setOperatePointScale(self.operatePointScale)
        self.editorRole.shapRenderNode:addChild(render)
        table.insert(self.shapeRenders, render)
    end

    -- 隐藏多余的
    for i = shapeCount + 1, #self.shapeRenders do
        self.shapeRenders[i]:reset()
    end
end

-- @brief 画布缩放发生改变
function RoleTimelineBase:onRenderScaleChange(scale)
    self.operatePointScale = 1 / scale
    for k, v in pairs(self.shapeRenders) do
        v:setOperatePointScale(self.operatePointScale)
    end
end

-- @brief 时间帧数改变
function RoleTimelineBase:onTimeChange()
end

-- @brief 形状编辑数据之后
function RoleTimelineBase:onShapeEditChangeFinish(render)
end

-- @brief 形状编辑数据改变之后
function RoleTimelineBase:onShapeEditChange()
end

-- @brief 序列化
function RoleTimelineBase:serialize()
    return {}
end

-- @brief 反序列化
function RoleTimelineBase:deserialize(data)
    self.curTime = -1
    self:stopAutoPlay()
end


--------------------------------------------------------- 属性更改/撤销相关 begin ---------------------------------------------------------

-- @brief 属性改变时调用
function RoleTimelineBase:onAttributeChange(attributeName)
	local mem = self:doPartMementoGen(attributeName)
	if mem ~= nil then
		self.editorRole:saveSnapshot(self.editorRole, true, attributeName, mem)
	else
		-- 保存整体
		self.editorRole:saveSnapshot()
	end
end

-- @brief 保存局部快照时,此函数返回改变属性要存储的数据
-- 如果返回为nil则Context保存全局快照
function RoleTimelineBase:doPartMementoGen(attributeName)
end

-- @brief 撤销属性改变
-- 撤销的属性改变是保存的局部快照时,根据 data 字段对元素进行还原操作
-- @param attributeName 改变的属性名称
-- @param data doPartMementoGen 返回的局部快照数据
function RoleTimelineBase:revokeAttributeChange(attributeName, data)
    self:stopAutoPlay()
end

--------------------------------------------------------- 属性更改/撤销相关 end ---------------------------------------------------------

local Texture_Btn_Pre = EditorIconContent:get(EditorIcon.BUTTON_PRE)
local Texture_Btn_Next = EditorIconContent:get(EditorIcon.BUTTON_NEXT)
local Texture_Btn_Play = EditorIconContent:get(EditorIcon.BUTTON_PLAY)
local Texture_Btn_Pause = EditorIconContent:get(EditorIcon.BUTTON_PAUSE)
local btn_size = cc.p(32, 32)
local layout_size = cc.p(0, 0)

-- @brief 时间轴左上角GUI绘制
function RoleTimelineBase:onSequentityLTGUI()
    layout_size.x = ImGui.GetContentRegionAvailWidth()
    ImGui.BeginHorizontal("h1", layout_size, -1)

    -- 上一帧
    if ImGui.ImageButton(Texture_Btn_Pre, btn_size) then
        self:step(-1)
        self:stopAutoPlay()
    end

    -- 播放/暂停
    if self.isPlaying then
        if ImGui.ImageButton(Texture_Btn_Pause, btn_size) then
            self:stopAutoPlay()
        end
    else
        if ImGui.ImageButton(Texture_Btn_Play, btn_size) then
            self:startAutoPlay()
        end
    end

    -- 下一帧
    if ImGui.ImageButton(Texture_Btn_Next, btn_size) then
        self:step(1)
        self:stopAutoPlay()
    end

    -- ImGui.Spring(0.5)

    -- local showValue = 1 - ((self.playSlowScale - 1) / 10.0)
    -- local ok, curScale = ImGui.SliderFloat("scale", showValue, 0.1, 1, "%.1f")
	-- if ok then
    --     curScale = math.max(curScale, 0.1)
    --     curScale = math.min(curScale, 1)
    --     self.playSlowScale = (1 - curScale) * 10 + 1
    --     self.playSlowScale = math.floor(self.playSlowScale)
	-- end

    ImGui.Spring(0.5)
    local ok, loop = ImGui.Checkbox("loop", self.isPlayLoop)
    if ok then
        self.isPlayLoop = loop
    end
    
    ImGui.EndHorizontal()
end

-- @brief
function RoleTimelineBase:onEventMoveTimeCondition(track_count, channel_count, event_count, curTime, channel)
    return true
end

-- @brief
function RoleTimelineBase:onEventMoveTime(track_count, channel_count, event_count, curTime, channel)
end

-- @brief
function RoleTimelineBase:onClickSequentityChannel(track_count, channel_count, channel)
end

function RoleTimelineBase:step(value)
    local current = self.sequentity:getCurrentTime()
    local min = self.sequentity:getMin()
    local max = self.sequentity:getMax()

    current = current + value
    if current > max then
        if self.isPlayLoop then
            current = min
        else
            current = max
            self:stopAutoPlay()
        end
    end

    if current < min then
        if self.isPlayLoop then
            current = max
        else
            current = min
            self:stopAutoPlay()
        end        
    end

    self.sequentity:setCurrentTime(current)
end

function RoleTimelineBase:jump(current, pause)
    if pause then
        self:stopAutoPlay()
    end
    
    local min = self.sequentity:getMin()
    local max = self.sequentity:getMax()

    current = math.max(current, min)
    current = math.min(current, max)
    
    self.sequentity:setCurrentTime(current)
end

function RoleTimelineBase:stopAutoPlay()
    self.isPlaying = false

    if self.schedule_id then
        cc.Director:getInstance():getScheduler():unscheduleScriptEntry(self.schedule_id)
        self.schedule_id = nil
    end
end

function RoleTimelineBase:startAutoPlay()
    self:stopAutoPlay()
    self.isPlaying = true
    self.delayCount = self.playSlowScale
    
	self.schedule_id = cc.Director:getInstance():getScheduler():scheduleScriptFunc(function()
        self.delayCount = self.delayCount - 1
        if self.delayCount <= 0 then
            self.delayCount = self.playSlowScale
            self:step(STEP_SCALE)
        end
    end, 0, false)
end

return RoleTimelineBase
