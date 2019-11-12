
local Loading = class("Loading", cc.load("mvc").ViewBase)


function Loading:onCreate()
    self.ui = G_Helper.loadStudioFile("widget.Loading", self)
    self:addChild(self.ui.root)

    local listener = cc.EventListenerTouchOneByOne:create();
    listener:setSwallowTouches(true)
    listener:registerScriptHandler(function() return true end,cc.Handler.EVENT_TOUCH_BEGAN)
    cc.Director:getInstance():getEventDispatcher():addEventListenerWithSceneGraphPriority(listener, self)
end

return Loading
