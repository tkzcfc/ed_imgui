local Recipient = class("Recipient")

function Recipient:ctor(_eventEmitter)
	self.event_lamdaMap = {}
    self.eventEmitter = _eventEmitter
end

function Recipient:on(event, listener)
	if self.event_lamdaMap[event] then
		print("警告：重复注册消息订阅", event)
	end
	self.event_lamdaMap[event] = listener
	self.eventEmitter:on(event, listener)
end

function Recipient:once(event, listener)
	self.event_lamdaMap[event] = listener
	self.eventEmitter:once(event, listener)
end

function Recipient:addListener(event, listener, _count)
	self.event_lamdaMap[event] = listener
	self.eventEmitter:addListener(event, listener, _count)
end

function Recipient:clear()
	for k, v in pairs(self.event_lamdaMap) do
		self.eventEmitter:removeListener(k, v)
	end
	self.event_lamdaMap = {}
end

function Recipient:remove(event)
	if self.event_lamdaMap[event] then
		self.eventEmitter:removeListener(event, self.event_lamdaMap[event])
		self.event_lamdaMap[event] = nil
	end
end

return Recipient




   -- local eventEmitter = Class.EventEmitter.new()
   -- local recipient = Class.Recipient.new(eventEmitter)
   -- recipient:on("1", function(...) print(...) end)
   -- recipient:once("2", function(...) print(...) end)
   -- recipient:once("3", function(...) print(...) end)
   -- recipient:on("4", function(...) print(...) end)
   -- recipient:remove("3")
   -- recipient:remove("4")

   -- eventEmitter:emit("1", "key_1",2,1)
   -- eventEmitter:emit("2", "key_2",2,2)
   -- eventEmitter:emit("2", "key_2",2,3)
   -- eventEmitter:emit("3", "key_3",2,4)
   -- eventEmitter:emit("1", "key_1",2,5)
   -- eventEmitter:emit("4", "key_4",2,6)

   -- recipient:clear()

   -- eventEmitter:emit("1", "key_1",2,1)
   -- eventEmitter:emit("2", "key_2",2,2)
   -- eventEmitter:emit("2", "key_2",2,3)
   -- eventEmitter:emit("3", "key_3",2,4)
   -- eventEmitter:emit("1", "key_1",2,5)
   -- eventEmitter:emit("4", "key_4",2,6)

-- [LUA-print] key_1       2       1
-- [LUA-print] key_2       2       2
-- [LUA-print] key_1       2       5