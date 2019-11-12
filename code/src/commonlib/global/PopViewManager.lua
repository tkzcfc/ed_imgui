local Vector = require("commonlib.class.Vector")

local PopViewManager = class("PopViewManager")

PopViewManager.POPVIEW_Z = 10000

function PopViewManager:ctor()
	self.popViews = Vector:new()
end

function PopViewManager:addPopView(view)
	local scene = cc.Director:getInstance():getRunningScene()
	if scene == nil then
		return false
	end

	scene:addChild(view, PopViewManager.POPVIEW_Z)
	view:setAnchorPoint(0.5, 0.5)
	view:setPosition(cc.p(G_MAC.SCREEN_WIDTH / 2, G_MAC.SCREEN_HEIGHT / 2))

	self.popViews:pushBack(view)

	G_SysEventEmitter:emit("ViewShow", view)

	return true
end

function PopViewManager:getTopView()
	if self.popViews:size() > 0 then
		return self.popViews:back()
	end
end

function PopViewManager:removePopView(view)
	local bQueueView = view == self.curQueueView

	self.popViews:eraseObject(view)

	G_SysEventEmitter:emit("ViewDismiss", view)

	view:removeFromParent()

	if bQueueView then
		self.curQueueView = nil
		self:checkQueueNext()
	end
end

function PopViewManager:removeAllPopView(except_cls)
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

function PopViewManager:clear()
	self.popViews:clear()
	self:clearQueue()
end

function PopViewManager:removePopViewByTag(tag)
	for key, view in ipairs(self.popViews) do
		if view:getTag() == tag then
			view:dismiss()
			break
		end
	end
end

function PopViewManager:hasPanel(cls)
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

function PopViewManager:pushQueueView(view)
	if not self.viewQueue then
		self.viewQueue = { }
	end

	view:retain()
	table.insert(self.viewQueue, view)

	self:checkQueueNext()
end

function PopViewManager:checkQueueNext()
	if not self.curQueueView and #self.viewQueue > 0 then
		self.curQueueView = self.viewQueue[1]
		table.remove(self.viewQueue, 1)

		self:addPopView(self.curQueueView)
		self.curQueueView:release()
	end
end

function PopViewManager:clearQueue()
	if self.viewQueue then
		for key, var in ipairs(self.viewQueue) do
			var:release()
		end
		self.viewQueue = nil
	end
	self.curQueueView = nil
end

function PopViewManager:getViewByName(name)
	for i, view in ipairs(self.popViews) do
		if view.__cname == name then
			return view
		end
	end
end

function PopViewManager:getViewByTag(tag)
	for i, view in ipairs(self.popViews) do
		if view:getTag() == tag then
			return view
		end
	end
end

function PopViewManager:getViewFromQueueByName(name)
	if not self.viewQueue then
		return
	end

	for i, view in ipairs(self.viewQueue) do
		if view.__cname == name then
			return view
		end
	end
end

return PopViewManager