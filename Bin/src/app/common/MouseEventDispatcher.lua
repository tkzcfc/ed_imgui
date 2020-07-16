local MouseEventDispatcher = class("MouseEventDispatcher")

function MouseEventDispatcher:ctor()
	self.calls = {}

	self.cursorX = 0
	self.cursorY = 0
	self.preCursorX = 0
	self.preCursorY = 0

	local function onMouseMove(event)
		self.cursorX = event:getCursorX()
		self.cursorY = event:getCursorY()
		G_SysEventEmitter:emit("onMouseMove", event)

		self.preCursorX = self.cursorX
		self.preCursorY = self.cursorY
    end

	local function onMouseScroll(event)
		self.cursorX = event:getCursorX()
		self.cursorY = event:getCursorY()
		G_SysEventEmitter:emit("onMouseScroll", event)
    end

	local function onMouseDown(event)
		self.cursorX = event:getCursorX()
		self.cursorY = event:getCursorY()
		G_SysEventEmitter:emit("onMouseDown", event)
    end

	local function onMouseUp(event)
		self.cursorX = event:getCursorX()
		self.cursorY = event:getCursorY()
		G_SysEventEmitter:emit("onMouseUp", event)
    end

    local mouseListener = cc.EventListenerMouse:create()
    mouseListener:registerScriptHandler(onMouseMove,cc.Handler.EVENT_MOUSE_MOVE )
    mouseListener:registerScriptHandler(onMouseScroll,cc.Handler.EVENT_MOUSE_SCROLL )
    mouseListener:registerScriptHandler(onMouseDown,cc.Handler.EVENT_MOUSE_DOWN )
    mouseListener:registerScriptHandler(onMouseUp,cc.Handler.EVENT_MOUSE_UP )
    cc.Director:getInstance():getEventDispatcher():addEventListenerWithFixedPriority(mouseListener, -1)



    local function onTouchBegan(touch, event)
		G_SysEventEmitter:emit("onTouchBegan", event)
        return true
    end

    local function onTouchMoved(touch, event)
		G_SysEventEmitter:emit("onTouchMoved", event)
    end

    local function onTouchEnded(touch, event)
		G_SysEventEmitter:emit("onTouchEnded", event)
    end

    local function onTouchCancelled(touch, event)
		G_SysEventEmitter:emit("onTouchCancelled", event)
    end

    local listener = cc.EventListenerTouchOneByOne:create()
    -- 注册两个回调监听方法
    listener:registerScriptHandler(onTouchBegan,cc.Handler.EVENT_TOUCH_BEGAN )
    listener:registerScriptHandler(onTouchMoved,cc.Handler.EVENT_TOUCH_MOVED )
    listener:registerScriptHandler(onTouchEnded,cc.Handler.EVENT_TOUCH_ENDED )
    listener:registerScriptHandler(onTouchCancelled,cc.Handler.EVENT_TOUCH_CANCELLED )
    cc.Director:getInstance():getEventDispatcher():addEventListenerWithFixedPriority(listener, -1)
end

function MouseEventDispatcher:getCursorX()
	return self.cursorX
end

function MouseEventDispatcher:getCursorY()
	return self.cursorY
end

function MouseEventDispatcher:getCursorPos()
	return {x = self.cursorX, y = self.cursorY}
end

function MouseEventDispatcher:getMoveDelta()
	return {x = self.cursorX - self.preCursorX, y = self.cursorY - self.preCursorY}
end

return MouseEventDispatcher