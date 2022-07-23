-- @Author: fangcheng
-- @URL: github.com/tkzcfc
-- @Date:   2019-10-17 21:26:05
-- @Description: 事件订阅器
-- 已废弃,现在尽量直接使用 EventEmitter

local Recipient = class("Recipient")

function Recipient:ctor(_eventEmitter)
   self.eventEmitter = _eventEmitter
end

-- @brief 订阅事件
-- @param event 事件key
-- @param listener 监听者
-- @param priority 派发优先级 默认3
function Recipient:on(event, listener, priority)
	self.eventEmitter:on(event, listener, self, priority)
end

-- @brief 订阅一次事件
function Recipient:once(event, listener, priority)
	self.eventEmitter:once(event, listener, self, priority)
end

-- @brief 取消所有订阅的事件
function Recipient:clear()
   self.eventEmitter:offByTag(self)
end

return Recipient
