-- @Author: fangcheng
-- @Date:   2021-9-2 17:29:03
-- @remark: 动画渲染-支持逐帧播放

local ArmatureRender = require("app.render.ArmatureRender")
local TYPE = ArmatureRender.TYPE

--60帧动画
local ACTION_FPS = 1 / 60

local ArmatureRenderStep = class("ArmatureRenderStep", ArmatureRender)

function ArmatureRenderStep:ctor()
    ArmatureRenderStep.super.ctor(self)

    self.curFrame = 0
end

-- @override
function ArmatureRenderStep:initWithFile(...)
    ArmatureRenderStep.super.initWithFile(self, ...)

    if self:isRunning() then
        self.render:unscheduleUpdate()
        -- self.render:update(0)
    else
        self.render:onNodeEvent("enterTransitionFinish", function()
            self.render:unscheduleUpdate()
            -- self.render:update(0)
        end)
    end
    self:jumpToFrame(0)
end

-- @brief 设置当前帧
function ArmatureRenderStep:setFrame(frame)
    local diff = frame - self.curFrame
    if diff == 0 then return end

    self.curFrame = frame

    -- 使用update改变动画进度 (不准确)
    -- self.render:update(ACTION_FPS * diff)

    -- 使用自带API跳转帧
    self:jumpToFrame(frame)
end

function ArmatureRenderStep:jumpToFrame(frame)
    self.curFrame = frame

    if self.curType == TYPE.EXPORTJSON then
        self.render:getAnimation():gotoAndPlay(frame)
    end
end

return ArmatureRenderStep
