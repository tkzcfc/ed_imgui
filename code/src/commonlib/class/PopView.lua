local PopView = class("PopView", function() return ccui.Layout:create() end)

function PopView:ctor(showMask)
	if showMask == nil then
		showMask = true
	end

	self:setContentSize(cc.size(G_MAC.SCREEN_WIDTH, G_MAC.SCREEN_HEIGHT))
	self:setBackGroundColorType(ccui.LayoutBackGroundColorType.solid)
	self:setBackGroundColor(cc.c3b(0, 0, 0))
	if showMask then
		self:setBackGroundColorOpacity(130)
	else
		self:setBackGroundColorOpacity(0)
	end

	local function onTouchBegan(touch, event)
		return true
	end

	self.listener = cc.EventListenerTouchOneByOne:create()
	self.listener:setSwallowTouches(true)
	self.listener:registerScriptHandler(onTouchBegan, cc.Handler.EVENT_TOUCH_BEGAN)
	self:getEventDispatcher():addEventListenerWithSceneGraphPriority(self.listener, self)
end

function PopView:setContentView(contentView)
	self.contentView = contentView
end

function PopView:show()
	G_PopViewManager:addPopView(self)
end

function PopView:dismiss()
	G_PopViewManager:removePopView(self)
end

function PopView:setAutoDismiss()
	local function onTouchEnded(touch, event)
		if self.contentView then
			local box = self.contentView:getBoundingBox()
			local location = touch:getLocation()
			if not cc.rectContainsPoint(box, location) then
				self:dismiss()
			end
		else
			self:dismiss()
		end
	end

	self.listener:registerScriptHandler(onTouchEnded, cc.Handler.EVENT_TOUCH_ENDED)
end

return PopView
