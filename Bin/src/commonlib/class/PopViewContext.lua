-- @Author: fangcheng
-- @URL: github.com/tkzcfc
-- @Date:   2020-02-29 21:23:48
-- @Last Modified by:   fangcheng
-- @Last Modified time: 2020-03-04 21:19:24
-- @Description: 


local Vector = require("commonlib.class.Vector")

local PopViewContext = class("PopViewContext")


function PopViewContext:ctor()
	self.popViews = Vector:new()
end

function PopViewContext:addPopView(view, parentNode, unique)

	if parentNode == nil then
		parentNode = cc.Director:getInstance():getRunningScene()
		if parentNode == nil then
			print("[ERROR]: PopViewContext parentNode == nil")
			return false
		end
	end

	parentNode:addChild(view)
	view:setAnchorPoint(0.5, 0.5)
	view:setPosition(G_MAC.SCREEN_CENTER)
	
	-- 独占模式
	if unique then
		view.__cache_view_tag = true
		local curView
		for i = self.popViews:size(), 1, -1 do
			curView = self.popViews:at(i)
			if curView:canOptimize() and curView:getLocalZOrder() <= view:getLocalZOrder() then
				curView:setVisible(false)
			end
		end
	end

	local topView = self:getTopView()
	if topView and topView:isShowMask() then
		topView:hideMask()
	end

	self.popViews:pushBack(view)

	G_SysEventEmitter:emit("event_ViewShow", view)

	return true
end

function PopViewContext:getTopView()
	if self.popViews:size() > 0 then
		return self.popViews:back()
	end
end

function PopViewContext:popView()
	local pop = self:getTopView()
	if pop then
		pop:dismiss()
		return true
	end
	return false
end

function PopViewContext:removePopView(view)
	local bQueueView = view == self.curQueueView
	local unique = view.__cache_view_tag

	if not self.popViews:eraseObject(view) then
		return
	end

	G_SysEventEmitter:emit("event_ViewDismiss", view)

	view:removeFromParent()

	-- 独占模式
	if unique then
		for i = self.popViews:size(), 1, -1 do
			view = self.popViews:at(i)
			view:setVisible(true)
			if view.__cache_view_tag then
				break
			end
		end
	end

	view = self:getTopView()
	if view and view:isShowMask() then
		view:showMask()
	end

	if bQueueView then
		self.curQueueView = nil
		self:checkQueueNext()
	end
end

function PopViewContext:removeAllPopView(except_cls)
	except_cls = except_cls or ""
	for i = self.popViews:size(), 1, -1 do
		local view = self.popViews:at(i)
		if view.__cname ~= except_cls then
			if view.dismiss then
				view:dismiss()
			end
		end
	end

	self:clearQueue()
end

function PopViewContext:clear()
	self.popViews:clear()
	self:clearQueue()
end

function PopViewContext:removePopViewByTag(tag)
	for key, view in ipairs(self.popViews) do
		if view:getTag() == tag then
			view:dismiss()
			break
		end
	end
end

function PopViewContext:hasPanel(cls)
	if type(cls) == type("") then
		cls = { cls }
	end
	for i = self.popViews:size(), 1, -1 do
		local view = self.popViews:at(i)
		local classname = view.__cname
		if classname and G_Helper.findEleInTab(cls, classname) ~= nil then
			return true
		end
	end
	return false
end

function PopViewContext:pushQueueView(view)
	if not self.viewQueue then
		self.viewQueue = { }
	end

	view:retain()
	table.insert(self.viewQueue, view)

	self:checkQueueNext()
end

function PopViewContext:checkQueueNext()
	if not self.curQueueView and #self.viewQueue > 0 then
		self.curQueueView = self.viewQueue[1]
		table.remove(self.viewQueue, 1)

		self:addPopView(self.curQueueView)
		self.curQueueView:release()
	end
end

function PopViewContext:clearQueue()
	if self.viewQueue then
		for key, var in ipairs(self.viewQueue) do
			var:release()
		end
		self.viewQueue = nil
	end
	self.curQueueView = nil
end

function PopViewContext:getViewByName(name)
	for i, view in ipairs(self.popViews) do
		if view.__cname == name then
			return view
		end
	end
end

function PopViewContext:getViewByTag(tag)
	for i, view in ipairs(self.popViews) do
		if view:getTag() == tag then
			return view
		end
	end
end

function PopViewContext:getViewFromQueueByName(name)
	if not self.viewQueue then
		return
	end

	for i, view in ipairs(self.viewQueue) do
		if view.__cname == name then
			return view
		end
	end
end

return PopViewContext