local EventEmitter = class("EventEmitter")

function EventEmitter:ctor()
	self.event_listenerMap = {}
	self.doEmit_Map = {}
end

function EventEmitter:on(event, listener)
	self:addListener(event, listener, -1)
end

function EventEmitter:once(event, listener)
	self:addListener(event, listener, 1)
end

function EventEmitter:addListener(event, _listener, _count)
	self.event_listenerMap[event] = self.event_listenerMap[event] or {}
	local listenerTab = self.event_listenerMap[event]

	table.insert(listenerTab, {listener = _listener, count = _count})
end

function EventEmitter:removeListener(event, listener)
	local listenerTab = self.event_listenerMap[event]
	if listenerTab then
		for k, v in pairs(listenerTab) do
			if v.listener == listener then
				v.count = 0
			end
		end

		if not self.doEmit_Map[event] then
			repeat
			until(not EventEmitter.removeOnce(listenerTab))
		end
	end
end

function EventEmitter:removeAllListeners(event)
	if not self.doEmit_Map[event] then
		self.event_listenerMap[event] = {}
	else
		local listenerTab = self.event_listenerMap[event]
		if listenerTab ~= nil then
			for k, v in pairs(listenerTab) do
				v.count = 0
			end
		end
	end
end

function EventEmitter:clear()
	self.event_listenerMap = {}
end

function EventEmitter:emit(event, ...)
	local listenerTab = self.event_listenerMap[event]
	local callCount = 0

	if listenerTab ~= nil then
		self.doEmit_Map[event] = true

		for k, v in pairs(listenerTab) do
			if v.count ~= 0 then
				if v.count > 0 then
					v.count = v.count - 1
				end
				callCount = callCount + 1
				if v.listener(...) == true then
					break
				end
			end
		end

		repeat
		until(not EventEmitter.removeOnce(listenerTab))

		self.doEmit_Map[event] = false
	end

	return callCount
end

function EventEmitter:listeners(event)
	local listenerTab = self.event_listenerMap[event]
	local count = 0
	for k, v in pairs(listenerTab) do
		if v.count ~= 0 then
			count = count + 1
		end
	end
	return count
end

--------------------------------------------------------------------------------------------

function EventEmitter.removeOnce(listenerTab)
	for k, v in pairs(listenerTab) do
		if v.count == 0 then
			table.remove(listenerTab, k)
			return true
		end
	end
	return false
end

return EventEmitter
