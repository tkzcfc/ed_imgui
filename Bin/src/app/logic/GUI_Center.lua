-- @Author: fangcheng
-- @Date:   2020-04-05 17:05:54
-- @Description: 

local CenterWindow = class("CenterWindow")

local centerDocumentManager = _MyG.CenterDocumentManager

function CenterWindow:ctor()

	self.cache_isContainMouse = false
	self.cache_ceontex_w = 0
	self.cache_ceontex_h = 0

	local render = ScissorLayer:create()
	_MyG.MainScene.rootNode:addChild(render)

	self.render = render
    self.senderSize = cc.size(0, 0)

    self.rootNode = cc.Node:create()
    render:addChild(self.rootNode, 1)

    self.renderGuiShow = false
    self.renderCanShow = true

	self:initEventDispatcher()
end

function CenterWindow:onGUI()
	if centerDocumentManager:count() > 0 then
        self.renderGuiShow = true
		self:updateRenderSize()
		self:updateContainStatus()
		centerDocumentManager:onGUI()
	else
        self.renderGuiShow = false
	end

    self.render:setVisible(self.renderGuiShow and self.renderCanShow)
end

function CenterWindow:changeEventDispatcher(rootNode)
	if rootNode.isTouchEnabled and rootNode:isTouchEnabled() then
		rootNode:setTouchEnabled(false)
		rootNode:setEventDispatcher(self.eventDispatcher)
		rootNode:setTouchEnabled(true)
	else
		rootNode:setEventDispatcher(self.eventDispatcher)
	end

	local children = rootNode:getChildren()
	if #children < 1 then
		return
	end

	for k,v in pairs(children) do
		self:changeEventDispatcher(v)
	end
end

function CenterWindow:changeEventDispatcherSelf(rootNode)
	if rootNode.isTouchEnabled and rootNode:isTouchEnabled() then
		rootNode:setTouchEnabled(false)
		rootNode:setEventDispatcher(self.eventDispatcher)
		rootNode:setTouchEnabled(true)
	else
		rootNode:setEventDispatcher(self.eventDispatcher)
	end
end

function CenterWindow:isContainMouse()
	return self.cache_isContainMouse
end

function CenterWindow:checkMouseIsContain()
    local pos = _MyG.MouseEventDispatcher:getCursorPos()
    return Tools:isInRect(self.render, pos.x, pos.y)
end


function CenterWindow:updateRenderSize()
	local edContext = _MyG.edContext
    local style = ImGui.GetStyle()
    local thickness = edContext:getSplitterThickness()
    local framePaddingY = style.FramePadding.y

    local pos = cc.p(edContext:getLeftPaneWidth(), edContext:getBottomPanelHeight())
	local size = cc.size(edContext:getCenterPaneWidth(), edContext:getCenterPaneHeight())

    pos.x = pos.x + thickness * 3 + framePaddingY
    pos.y = pos.y + thickness * 2 + framePaddingY

    size.width = size.width - thickness - framePaddingY
    size.height = size.height - thickness - style.IndentSpacing - framePaddingY

    pos.x = G_Helper.win_2_visible_x(pos.x)
    pos.y = G_Helper.win_2_visible_y(pos.y)
    size.width = G_Helper.win_2_visible_x(size.width)
    size.height = G_Helper.win_2_visible_y(size.height)

    if size.height < 20 or size.width < 20 then
        self.renderCanShow = false
        return
    else
        self.renderCanShow = true
    end

    self.senderSize = size

	self.render:setPosition(pos)
	self.render:setContentSize(size)

	if math.abs(size.width - self.cache_ceontex_w) > 0.0001 or math.abs(size.height - self.cache_ceontex_h) > 0.0001 then
		self.cache_ceontex_w = size.width
		self.cache_ceontex_h = size.height
		self:onContentSizeChange()
	end
end

function CenterWindow:updateBGGrid()
    local gridRender = self.gridRender
    if gridRender == nil then
        gridRender = cc.Sprite:create("Res/grid.png")
        gridRender:getTexture():setTexParameters(GL_LINEAR, GL_LINEAR, GL_REPEAT, GL_REPEAT)
        self.render:addChild(gridRender, 0)

        gridRender.cache_width = 0
        gridRender.cache_height = 0

        self.gridRender = gridRender
    end

    if gridRender.cache_width < self.senderSize.width or gridRender.cache_height < self.senderSize.height then
        gridRender:setPosition(self.senderSize.width * 0.5, self.senderSize.height * 0.5)

        local textureRect = cc.rect(0, 0, self.senderSize.width, self.senderSize.height)
        gridRender:setTextureRect(textureRect)

        gridRender.cache_width = self.senderSize.width
        gridRender.cache_height = self.senderSize.height
    end
end

function CenterWindow:addChild(node, z)
    self.rootNode:addChild(node, z or 0)
end

function CenterWindow:onContentSizeChange()
	self.rootNode:setPosition(self.cache_ceontex_w * 0.5, self.cache_ceontex_h * 0.5)
	self:updateBGGrid()
end

function CenterWindow:updateContainStatus()
    self.cache_isContainMouse_valid = true

    if not ImGui.IsRootWindowOrAnyChildHovered() then
        self.cache_isContainMouse =false
        return false
    end

    local style = ImGui.GetStyle()
    local framePaddingY = style.FramePadding.y
    local canvas_pos = ImGui.GetCursorScreenPos()
    local canvas_size = ImGui.GetContentRegionAvail()
    local mousePos = ImGui.GetIO().MousePos
    local mouse_pos_in_canvas = cc.p(mousePos.x - canvas_pos.x, mousePos.y - canvas_pos.y)

    if mouse_pos_in_canvas.x >= 0 and mouse_pos_in_canvas.y >= framePaddingY and mouse_pos_in_canvas.x <= canvas_size.x and mouse_pos_in_canvas.y <= canvas_size.y then
        self.cache_isContainMouse = true
    else
        self.cache_isContainMouse = false
    end
    self.cache_mouse_pos_in_canvas = mouse_pos_in_canvas
end


function CenterWindow:initEventDispatcher()
    self.cache_MouseDownStatus = {}

    G_SysEventEmitter:on(SysEvent.ON_MOUSE_MOVE, function(event)
        if self.cache_MouseDownStatus[event:getMouseButton()] or self:isContainMouse() then
            self.eventDispatcher:dispatchEvent(event)
            -- print("move", _MyG.MouseEventDispatcher:getCursorX(), _MyG.MouseEventDispatcher:getCursorY())
        end
    end, self)

    G_SysEventEmitter:on(SysEvent.ON_MOUSE_SCROLL, function(event)
        if self:isContainMouse() then
            self.eventDispatcher:dispatchEvent(event)
            -- print("scroll", _MyG.MouseEventDispatcher:getCursorX(), _MyG.MouseEventDispatcher:getCursorY())
        end
    end, self)

    G_SysEventEmitter:on(SysEvent.ON_MOUSE_DOWN, function(event)
        if self:isContainMouse() then
            self.cache_MouseDownStatus[event:getMouseButton()] = true
            self.eventDispatcher:dispatchEvent(event)
            -- print("down", _MyG.MouseEventDispatcher:getCursorX(), _MyG.MouseEventDispatcher:getCursorY())
        end
    end, self)

    G_SysEventEmitter:on(SysEvent.ON_MOUSE_UP, function(event)
        local valid = self.cache_MouseDownStatus[event:getMouseButton()] or self:isContainMouse()
        self.cache_MouseDownStatus[event:getMouseButton()] = false
        if valid then
            self.eventDispatcher:dispatchEvent(event)
        end
    end, self)

    G_SysEventEmitter:on(SysEvent.ON_TOUCH_BEGAN, function(event)
        if self:isContainMouse() then
            self.eventDispatcher:dispatchEvent(event)
        end
    end, self)

    G_SysEventEmitter:on(SysEvent.ON_TOUCH_MOVED, function(event)
        self.eventDispatcher:dispatchEvent(event)
    end, self)


    G_SysEventEmitter:on(SysEvent.ON_TOUCH_ENDED, function(event)
        self.eventDispatcher:dispatchEvent(event)
    end, self)

    G_SysEventEmitter:on(SysEvent.ON_TOUCH_CANCELLED, function(event)
        self.eventDispatcher:dispatchEvent(event)
    end, self)

    self.eventDispatcher = cc.EventDispatcher:new()
    self.eventDispatcher:setEnabled(true)
    self.eventDispatcher:retain()
end













local function onGUI()
	_MyG.CenterWindow:onGUI()
end

_MyG.CenterWindow = CenterWindow.new()
_MyG.edContext:registerLuaHandle("onGUI_Center", onGUI)
