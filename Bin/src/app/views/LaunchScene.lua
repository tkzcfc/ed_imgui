-- @Author: fangcheng
-- @Date:   2021-06-20 13:43:39
-- @remark: 启动场景


local LaunchScene = class("LaunchScene", cc.load("mvc").ViewBase)


function LaunchScene:onCreate()
    local director = cc.Director:getInstance()
    
    self.ui = G_Helper.loadStudioFile("LaunchScene", self)
    self.ui.root:setContentSize(director:getWinSize())
    ccui.Helper:doLayout(self.ui.root)

    self:addChild(self.ui.root)


    G_SysEventEmitter:on(SysEvent.EVENT_WINDOW_RESIZED, function()
        self.ui.root:setContentSize(director:getWinSize())
        ccui.Helper:doLayout(self.ui.root)
    end, self)

    self:enableNodeEvents()

    performWithDelay(self, function()
        self:gotoMainScene()
    end, 0.5)
end

function LaunchScene:onExit()
    G_SysEventEmitter:offByTag(self)
end

function LaunchScene:gotoMainScene()
    local MainScene = require("app.views.MainScene")
    MainScene.new():showWithScene()
end

return LaunchScene
