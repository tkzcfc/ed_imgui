local MouseEventDispatcher = class("MouseEventDispatcher")

function MouseEventDispatcher:ctor()
	self.calls = {}

	self.cursorX = 0
	self.cursorY = 0

	local function onMouseMove(event)
		self.cursorX = event:getCursorX()
		self.cursorY = event:getCursorY()
		for k,v in pairs(self.calls) do
			if v.receiver and v.receiver["onMouseMove"] then
				if v.receiver["onMouseMove"](v.receiver, event) then
					return
				end
			end
		end
    end

	local function onMouseScroll(event)
		self.cursorX = event:getCursorX()
		self.cursorY = event:getCursorY()
		for k,v in pairs(self.calls) do
			if v.receiver and v.receiver["onMouseScroll"] then
				if v.receiver["onMouseScroll"](v.receiver, event) then
					return
				end
			end
		end
    end

	local function onMouseDown(event)
		self.cursorX = event:getCursorX()
		self.cursorY = event:getCursorY()
		for k,v in pairs(self.calls) do
			if v.receiver and v.receiver["onMouseDown"] then
				if v.receiver["onMouseDown"](v.receiver, event) then
					return
				end
			end
		end
    end

	local function onMouseUp(event)
		self.cursorX = event:getCursorX()
		self.cursorY = event:getCursorY()
		for k,v in pairs(self.calls) do
			if v.receiver and v.receiver["onMouseUp"] then
				if v.receiver["onMouseUp"](v.receiver, event) then
					return
				end
			end
		end
    end

    local mouseListener = cc.EventListenerMouse:create()
    mouseListener:registerScriptHandler(onMouseMove,cc.Handler.EVENT_MOUSE_MOVE )
    mouseListener:registerScriptHandler(onMouseScroll,cc.Handler.EVENT_MOUSE_SCROLL )
    mouseListener:registerScriptHandler(onMouseDown,cc.Handler.EVENT_MOUSE_DOWN )
    mouseListener:registerScriptHandler(onMouseUp,cc.Handler.EVENT_MOUSE_UP )
    cc.Director:getInstance():getEventDispatcher():addEventListenerWithFixedPriority(mouseListener, 1)
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

function MouseEventDispatcher:register(receiver, priority)
	for k,v in pairs(self.calls) do
		if v.receiver == receiver then
			print("[ERROR]MouseEventDispatcher重复注册")
		end
	end

	if priority == nil then
		priority = 0
	end

	local newcall = {}
	newcall.receiver = receiver
	newcall.priority = priority
	table.insert(self.calls, newcall)

	table.sort(self.calls, function(a, b) return a.priority > b.priority end)

	-- print(tostring(receiver), priority)
	-- for i,v in ipairs(self.calls) do
	-- 	print(i,tostring(v.receiver))
	-- end
end


function MouseEventDispatcher:unRegister(receiver)
	for k,v in pairs(self.calls) do
		if v.receiver == receiver then
			table.remove(self.calls, k)
		end
	end
end


return MouseEventDispatcher