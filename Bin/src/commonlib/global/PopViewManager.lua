-- @Author: fangcheng
-- @URL: github.com/tkzcfc
-- @Date:   2019-10-17 21:26:05
-- @Last Modified by:   fangcheng
-- @Last Modified time: 2020-02-29 21:33:45
-- @Description: UI节点管理器

local Vector = require("commonlib.class.Vector")
local PopViewContext = require("commonlib.class.PopViewContext")

local PopViewManager = class("PopViewManager")

function PopViewManager:ctor()
	self.contextStack = Vector:new(false)
	self:push()
end

function PopViewManager:pop()
	self.contextStack:back():clear()
	self.contextStack:popBack()
end

function PopViewManager:push()
	self.contextStack:pushBack(PopViewContext.new())
end

function PopViewManager:curContext()
	return self.contextStack:back()
end

function PopViewManager:addPopView(view, parentNode, unique)
	return self:curContext():addPopView(view, parentNode, unique)
end

function PopViewManager:getTopView()
	return self:curContext():getTopView()
end

function PopViewManager:popView()
	return self:curContext():popView()
end

function PopViewManager:removePopView(view)
	self:curContext():removePopView(view)
end

function PopViewManager:removeAllPopView(except_cls)
	self:curContext():removeAllPopView(except_cls)
end

function PopViewManager:clear()
	self:curContext():clear()
end

function PopViewManager:removePopViewByTag(tag)
	self:curContext():removePopViewByTag(tag)
end

function PopViewManager:hasPanel(cls)
	return self:curContext():hasPanel(cls)
end

function PopViewManager:pushQueueView(view)
	self:curContext():pushQueueView(view)
end

function PopViewManager:clearQueue()
	self:curContext():clearQueue()
end

function PopViewManager:getViewByName(name)
	return self:curContext():getViewByName(name)
end

function PopViewManager:getViewByTag(tag)
	return self:curContext():getViewByTag(tag)
end

function PopViewManager:getViewFromQueueByName(name)
	return self:curContext():getViewFromQueueByName(name)
end

return PopViewManager