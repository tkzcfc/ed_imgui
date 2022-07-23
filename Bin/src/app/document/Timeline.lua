-- @Author : fc
-- @Date   : 2021-8-24 11:43:27
-- @remark : 时间线编辑

local Document = require("app.imgui.Document")

local Timeline = class("Timeline", Document)

function Timeline:ctor()
	Timeline.super.ctor(self, "timeline")

    self.sequentity = CSequentity()
    self.sequentity:setRange(0, 100)
end

function Timeline:onGUI()
    local count = G_SysEventEmitter:emit(SysEvent.ON_TIMELINE_GUI)
    if count < 1 then
        self.sequentity:onGUI()
    end
end

function Timeline:canRemove()
	return false
end

function Timeline:canClose()
	return false
end

return Timeline

