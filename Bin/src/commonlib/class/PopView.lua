-- @Author: fangcheng
-- @URL: github.com/tkzcfc
-- @Date:   2019-10-17 21:26:05
-- @Last Modified by:   fangcheng
-- @Last Modified time: 2020-04-04 19:07:34
-- @Description: UI节点父类

local PopView = class("PopView", function() return ccui.Layout:create() end)

function PopView:ctor()
	self.showMaskTag = true
	self.canOptimizeTag = true

	self:setContentSize(cc.size(G_MAC.SCREEN_WIDTH, G_MAC.SCREEN_HEIGHT))
	self:setBackGroundColorType(ccui.LayoutBackGroundColorType.solid)
	self:setBackGroundColor(cc.c3b(0, 0, 0))
	if self.showMaskTag then
		self:showMask()
	else
		self:hideMask()
	end

	local function onTouchBegan(touch, event)
		if self.runOpenActionTag then
			return true
		end
		return self:onTouchBegan(touch, event)
	end

	local function onTouchEnded(touch, event)
		self:onTouchEnded(touch, event)
	end

	self.listener = cc.EventListenerTouchOneByOne:create()
	self.listener:setSwallowTouches(true)
	self.listener:registerScriptHandler(onTouchBegan, cc.Handler.EVENT_TOUCH_BEGAN)
	self.listener:registerScriptHandler(onTouchEnded, cc.Handler.EVENT_TOUCH_ENDED)
	self:getEventDispatcher():addEventListenerWithSceneGraphPriority(self.listener, self)

	self:enableNodeEvents()
end

function PopView:onTouchBegan(touch, event)
	if self.autoDismissTag then
		if self.contentView then
			self.touchContentViewBeginTag = not self:isContainContentView(touch, event)
		else
			self.touchContentViewBeginTag = true
		end
	end
	return true
end

function PopView:onTouchEnded(touch, event)
	if not self.autoDismissTag then
		return
	end

	if self.touchContentViewBeginTag and not self:isContainContentView(touch, event) then
		self:dismiss()
	end

	self.touchContentViewBeginTag = false
end

-- @brief 隐藏遮罩
function PopView:hideMask()
	self:setBackGroundColorOpacity(0)
	-- print("hideMask----------------->>>", tostring(self))
end

-- @brief 显示遮罩
function PopView:showMask()
	self:setBackGroundColorOpacity(130)
	-- print("showMask----------------->>>", tostring(self))
end

-- @brief 是否显示遮罩
function PopView:isShowMask()
	return self.showMaskTag
end

-- @brief 设置是否显示遮罩
-- @param showMaskTag 是否显示遮罩
function PopView:setShowMask(showMaskTag)
	self.showMaskTag = showMaskTag

	if self.showMaskTag then
		self:showMask()
	else
		self:hideMask()
	end
end

function PopView:isContainContentView(touch, event)
	if self.contentView == nil then
		return false
	end
	-- local box = self.contentView:getBoundingBox()
	-- local location = touch:getLocation()
	-- return cc.rectContainsPoint(box, location)

	local location = touch:getLocation()
	return Tools:isInRect(self.contentView, location.x, location.y)
end

---------------------------------------public---------------------------------------

-- @brief 设置UI内容显示节点
function PopView:setContentView(contentView)
	self.contentView = contentView
end

-- @brief 显示UI
-- @param runAction 是否执行动画
-- @param parentNode 父节点，为空则父节点为当前场景
-- @param unique 是否为独占模式
function PopView:show(runAction, parentNode, unique)
	self:iBeforeOpenedWindow()
	G_PopViewManager:addPopView(self, parentNode, unique)
	if runAction ~= false then
		self:iRunOpenActionBegin()
	else
		self:iAfterOpenedWindow()
	end
	-- print("show----------------->>>", tostring(self))
end

-- @brief 是否启用关闭动画
function PopView:setEnableCloseAnimation(enable)
	self.enableCloseAnimationTag = enable
end

-- @brief 使本窗口不接受关闭响应，除非调用dismiss函数时参数force为true
function PopView:eternal()
	self.eternalTag = true
end

-- @brief 关闭UI
-- @param force 是否强制关闭
function PopView:dismiss(force)

	if self.eternalTag and not force then
		return
	end

	-- 正在执行打开窗口动画
	if self.runOpenActionTag then
		return
	end

	-- 保证此函数只执行一次
	if self.executeDismissTag then
		return
	end
	self.executeDismissTag = true

	self:iWillCloseWindow()
	if self.enableCloseAnimationTag then
		self:iCloseActionBegin()
	else
		self:iAfterClosedWindow()
	end
end

-- @brief 设置UI点击空白处自动关闭
function PopView:setAutoDismiss()
	self.autoDismissTag = true
end

-- @brief 取消UI点击空白处自动关闭
function PopView:disEnableAutoDismiss()
	self.autoDismissTag = false
end

-- @brief 禁止对本UI优化显示
function PopView:keepOutOptimize()
	self.canOptimizeTag = false
end

-- @brief 是否可以对本UI优化显示
function PopView:canOptimize()
	return self.canOptimizeTag
end

----------------------------------------interface----------------------------------------
-- @brief UI界面打开动画
function PopView:iRunOpenActionBegin()
	if not self.contentView then
		self:iAfterOpenedWindow()
		return
	end

	self.runOpenActionTag = true
	
    self.contentView:setScale(0.3)
    local actionEnd = function()
		self:iAfterOpenedWindow()
    end
    local q = cc.Sequence:create(cc.ScaleTo:create(0.25, 1.1), cc.ScaleTo:create(0.1, 1.0), cc.CallFunc:create(actionEnd))
    self.contentView:runAction(q)

    -- 启用关闭动画
    self:setEnableCloseAnimation(true)
end

-- @brief UI界面关闭动画
function PopView:iCloseActionBegin()
	if not self.contentView then
		self:iAfterClosedWindow()
		return
	end

    self.contentView:setScale(1.0)
    local actionEnd = function()
        self:iAfterClosedWindow() 
    end
    local q = cc.Sequence:create(cc.ScaleTo:create(0.1, 1.1), cc.ScaleTo:create(0.25, 0.5), cc.CallFunc:create(actionEnd))
    self.contentView:runAction(q)
end

-- @brief UI界面打开之前的回调
function PopView:iBeforeOpenedWindow()
	-- print("iBeforeOpenedWindow------------>>")
end

-- @brief UI界面打开后的回调
function PopView:iAfterOpenedWindow()
	-- print("iAfterOpenedWindow------------>>")
	self.runOpenActionTag = false
	G_SysEventEmitter:emit("event_ViewShowFinish", self)
end

-- @brief UI界面关闭前的回调
function PopView:iWillCloseWindow()
	-- print("iWillCloseWindow------------>>")
end

-- @brief UI界面关闭后的回调
function PopView:iAfterClosedWindow()
	-- print("iAfterClosedWindow------------>>")
	G_PopViewManager:removePopView(self)
end


----------------------------------------override----------------------------------------
function PopView:onEnter()
end

function PopView:onExit()
end

function PopView:onEnterTransitionFinish()
end

function PopView:onExitTransitionStart()
end

function PopView:onCleanup()
end

return PopView
