-- @Author: fangcheng
-- @Date:   2020-04-05 17:44:30
-- @Description: 编辑器cocos相关


-- 边框线段颜色
local lineColor = cc.c4f(0, 0.5, 1.0, 1)
-- 线段宽度
local default_lineWidth = 2

local VAxis = require("app.common.VAxis")
local BaseEditor = require("app.document.context.BaseEditor")
local EdRootNodeElement = require("app.elements.EdRootNodeElement")

local BaseEditorCocos = class("BaseEditorCocos", BaseEditor)

function BaseEditorCocos:ctor(name, asset)
	BaseEditorCocos.super.ctor(self, name, asset)

	local render = cc.Node:create()
    render:setEventDispatcher(_MyG.CenterWindow.eventDispatcher)
	_MyG.CenterWindow:addChild(render)

    local eleNode = cc.Node:create()
    eleNode:setEventDispatcher(_MyG.CenterWindow.eventDispatcher)
    render:addChild(eleNode, 1)

    local borderDraw = cc.DrawNode:create()
    _MyG.CenterWindow:addChild(borderDraw, 2)

    local axisDraw = VAxis:create()
    _MyG.CenterWindow:addChild(axisDraw, 3)

	self.render     = render
    self.eleNode    = eleNode
    self.borderDraw = borderDraw
    self.axisDraw   = axisDraw

    self.axisCache = {}

    self.render:onUpdate(function()
        if self:contextVisible() then
            self:onEditorDraw()
        end
    end)

    self:initMouseListener()
    self:setTouchEnabled(true)
end

function BaseEditorCocos:initEvent()
    BaseEditorCocos.super.initEvent(self)

    self.sysRecipient:on(SysEvent.ON_ASSET_DRAG_END, function(assetItem)
        if _MyG.CenterWindow:isContainMouse() and self.render:isVisible() then
            local curPos = self.render:convertToNodeSpace(_MyG.MouseEventDispatcher:getCursorPos())
            self:onAssetDragEnd(assetItem, curPos)
        end
    end)

    self.sysRecipient:on(SysEvent.ON_DRAG_PRE_WIDGET, function(typeName)
        if self.render:isVisible() and _MyG.CenterWindow:checkMouseIsContain() then
            local curPos = self.render:convertToNodeSpace(_MyG.MouseEventDispatcher:getCursorPos())
            self:onDragPreWidgetDragEnd(typeName, curPos)
        end
    end)

    self.sysRecipient:on(SysEvent.ON_ATTRIBUTE_CONTENT_GUI, function()
        if self.render:isVisible() then
            self:onAttributeContent_GUI()
        end
    end)

    self.sysRecipient:on(SysEvent.ON_NODE_CONTENT_GUI, function(nodeContent)
        self:onNodeContentGUI(nodeContent)
    end)
end

function BaseEditorCocos:genName(typeName)
    self.typeNameGenSeeds = self.typeNameGenSeeds or {}

    if not self.typeNameGenSeeds[typeName] then
        self.typeNameGenSeeds[typeName] = 0
    end
    self.typeNameGenSeeds[typeName] = self.typeNameGenSeeds[typeName] + 1

    return string.format("%s_%d", typeName, self.typeNameGenSeeds[typeName])
end

function BaseEditorCocos:save()
    if not BaseEditorCocos.super.save(self) then
        return false
    end

    _MyG.IsLocalizeMode = true

    local data = self:serialize()
    _MyG.ProjectAssetManager:saveAsset(self.asset, data)

    _MyG.IsLocalizeMode = false

    return true
end

-- 序列化
function BaseEditorCocos:serialize()
    local data = BaseEditorCocos.super.serialize(self)

    local childrenSerialize = {}

    local children = self.rootElement.children
    if children then
        for k,v in pairs(children) do
            childrenSerialize[#childrenSerialize + 1] = v:serialize()
        end
    end
    data.children = childrenSerialize

    return data
end

function BaseEditorCocos:doSerialize()
    local data = BaseEditorCocos.super.doSerialize(self)
    data.typeNameGenSeeds = self.typeNameGenSeeds

    if _MyG.IsLocalizeMode then
        data._renderPos = cc.p(self.render:getPosition())
        data._renderScale = self.render:getScaleX()
    end

    return data
end

-- 反序列化
function BaseEditorCocos:deserialize(data)
    data = data or {}

    self:clearFocusElement()

    -- 清理
    if self.rootElement then
        self.rootElement:onDestroy()
    end

    self.rootElement = EdRootNodeElement.new(self)
    self.eleNode:addChild(self.rootElement:getRenderNode())

    if data.children then
        for k, v in pairs(data.children) do
            local ele = _MyG.ElementFactory:spawn(v.type, v, self)
            if not ele then
                return false
            end
            self.rootElement:addChild(ele)
        end
    end

    return BaseEditorCocos.super.deserialize(self, data)
end

function BaseEditorCocos:doDeserialize(data)
    if not BaseEditorCocos.super.doDeserialize(self, data) then
        return false
    end

    self.typeNameGenSeeds = data.typeNameGenSeeds

    self:clearFocusElement()

    local children = self.rootElement.children
    if data.focusEleUniqueIDs and children then
        for _,focusID in pairs(data.focusEleUniqueIDs) do
            for __,v in pairs(children) do
                local fEle = v:searchByUniqueId(focusID)
                if fEle then
                    self:addFocusElement(fEle)
                    break
                end
            end
        end
    end

    if data._renderPos then
        self.render:setPosition(data._renderPos)
    end
    if data._renderScale then
        self.render:setScale(data._renderScale)
    end

    return true
end

-- @brief ctrl + a
function BaseEditorCocos:onKeyBoardAll()
    self:clearFocusElement()
    
    self.rootElement:forEachChildren(function(ele)
        self:addFocusElement(ele)
    end)
end

function BaseEditorCocos:onGUI()
	BaseEditorCocos.super.onGUI(self)

    self.render:setVisible(true)
    self.borderDraw:setVisible(true)
    self.axisDraw:setVisible(true)
end

function BaseEditorCocos:onShow()
    BaseEditorCocos.super.onShow(self)
end

function BaseEditorCocos:onHide()
    if self.render then
        self.render:setVisible(false)
    end
    if self.borderDraw then
        self.borderDraw:setVisible(false)
    end
    if self.axisDraw then
        self.axisDraw:setVisible(false)
    end
    BaseEditorCocos.super.onHide(self)
end

function BaseEditorCocos:onAttributeContent_GUI()
    if #self.focusEles <= 0 then
        self:onAttributeContent_GUI_Self()
        return
    end

    if #self.focusEles == 1 then
        self.focusEles[1]:onAttributeGUI()
    end
end

function BaseEditorCocos:onAttributeContent_GUI_Self()
    for k,v in pairs(self.plugins) do
        v:onAttributeContent_GUI()
    end
end

function BaseEditorCocos:destroy()
    self:clearFocusElement()

    if self.rootElement then
        self.rootElement:onDestroy()
        self.rootElement = nil
    end

    BaseEditorCocos.super.destroy(self)
    
    self.render:removeFromParent()
    self.borderDraw:removeFromParent()
    self.axisDraw:removeFromParent()
end

function BaseEditorCocos:onContentSizeChange()
    self:updateBGGrid()
end

function BaseEditorCocos:initMouseListener()

    local function onMouseMove(event)
        if self.render:isVisible() then
            self:onMouseMove(event)
            self:saveMousePos(event)
        end
    end

    local function onMouseScroll(event)
        if self.render:isVisible() then
            self:onMouseScroll(event)
        end
    end

    local function onMouseDown(event)
        if self.render:isVisible() then
            self:onMouseDown(event)
            self:saveMousePos(event)
        end
    end

    local function onMouseUp(event)
        if self.render:isVisible() then
            self:onMouseUp(event)
            self:saveMousePos(event)
        end
    end

    local mouseListener = cc.EventListenerMouse:create()
    mouseListener:registerScriptHandler(onMouseMove,cc.Handler.EVENT_MOUSE_MOVE )
    mouseListener:registerScriptHandler(onMouseScroll,cc.Handler.EVENT_MOUSE_SCROLL )
    mouseListener:registerScriptHandler(onMouseDown,cc.Handler.EVENT_MOUSE_DOWN )
    mouseListener:registerScriptHandler(onMouseUp,cc.Handler.EVENT_MOUSE_UP )
    _MyG.CenterWindow.eventDispatcher:addEventListenerWithSceneGraphPriority(mouseListener, self.render)
end

function BaseEditorCocos:onMouseDown(event)

    for k,v in pairs(self.plugins) do
        if v:onMouseDown(event) then
            return
        end
    end

    if event:getMouseButton() == 2 then
        self.enableMoveRootNode = true
    end
end

function BaseEditorCocos:onMouseUp(event)

    for k,v in pairs(self.plugins) do
        if v:onMouseUp(event) then
            return
        end
    end

    if event:getMouseButton() == 2 then
        self.enableMoveRootNode = false
    end
end

function BaseEditorCocos:onMouseMove(event)
    for k,v in pairs(self.plugins) do
        if v:onMouseMove(event) then
            return
        end
    end

    -- 中键按住拖动屏幕
    if event:getMouseButton() == 2 then
        if self.enableMoveRootNode and self.movePrePos then
            local newposx = self.render:getPositionX()
            local newposy = self.render:getPositionY()
            newposx = newposx + (event:getCursorX() - self.movePrePos.x)
            newposy = newposy + (event:getCursorY() - self.movePrePos.y)
            self.render:setPosition(newposx, newposy)
        end
        event:stopPropagation()
    end

    -- 空格+左键=拖动
    if event:getMouseButton() == 0 and _MyG.KeyboardStateMng:keyCodeIsPressed(cc.KeyCode.KEY_SPACE) then
        if self.movePrePos then
            local newposx = self.render:getPositionX()
            local newposy = self.render:getPositionY()
            newposx = newposx + (event:getCursorX() - self.movePrePos.x)
            newposy = newposy + (event:getCursorY() - self.movePrePos.y)
            self.render:setPosition(newposx, newposy)
        end
        event:stopPropagation()
    end
end

function BaseEditorCocos:saveMousePos(event)
    if self.movePrePos then
        self.movePrePos.x = event:getCursorX()
        self.movePrePos.y = event:getCursorY()
    else
        self.movePrePos = cc.p(event:getCursorX(), event:getCursorY())
    end
end

function BaseEditorCocos:onMouseScroll(event)

    for k,v in pairs(self.plugins) do
        if v:onMouseScroll(event) then
            return
        end
    end

    if _MyG.KeyboardStateMng:canScrollEditContext() then
        local pos = cc.p(event:getCursorX(), event:getCursorY())
        local convertpos = self.render:convertToNodeSpace(pos)
    
        local oldscale = self.render:getScale()
        local scale = oldscale - event:getScrollY() * 0.1
        scale = math.max(scale, 0.2)
        scale = math.min(scale, 6.0)
        self.render:setScale(scale)
    
        local moveScale = scale - oldscale
        self.render:setPositionX(self.render:getPositionX() - convertpos.x * moveScale)
        self.render:setPositionY(self.render:getPositionY() - convertpos.y * moveScale)

        G_SysEventEmitter:emit(SysEvent.ON_EDIT_CONTENT_SCALE, self, scale)

        self:onRenderScaleChange(scale)
    end
end

function BaseEditorCocos:setTouchEnabled(enabled)
    if self.touchEnabled == enabled then
        return
    end
    self.touchEnabled = enabled

    if enabled then
        local function onTouchBegan(touch, event)
            if not self:contextVisible() then
                return
            end
            return self:onTouchBegan(touch, event)
        end

        local function onTouchMoved(touch, event)
            self:onTouchMoved(touch, event)
        end

        local function onTouchEnded(touch, event)
            self:onTouchEnded(touch, event)
        end

        local function onTouchCancelled(touch, event)
            self:onTouchCancelled(touch, event)
        end

        local listener = cc.EventListenerTouchOneByOne:create()
        -- 注册两个回调监听方法
        listener:registerScriptHandler(onTouchBegan,cc.Handler.EVENT_TOUCH_BEGAN )
        listener:registerScriptHandler(onTouchMoved,cc.Handler.EVENT_TOUCH_MOVED )
        listener:registerScriptHandler(onTouchEnded,cc.Handler.EVENT_TOUCH_ENDED )
        listener:registerScriptHandler(onTouchCancelled,cc.Handler.EVENT_TOUCH_CANCELLED )
        listener:setSwallowTouches(true)
        self.render:getEventDispatcher():addEventListenerWithSceneGraphPriority(listener, self.render)

        self.touchListener = listener
    else
        self.render:getEventDispatcher():removeEventListener(self.touchListener)
        self.touchListener = nil
    end
end

-- 触摸事件派发
function BaseEditorCocos:onTouchBegan(touch, event)
    -- 按住空格时拦截事件，用于拖动画布
    if _MyG.KeyboardStateMng:keyCodeIsPressed(cc.KeyCode.KEY_SPACE) then
        return false
    end

    local worldPos = self.axisDraw:convertToNodeSpace(_MyG.MouseEventDispatcher:getCursorPos())

    -- 清空标志位
    self.cancelAllFocusEleTag = true
    self.touchAnyEleTag = false
    self.axisCache.isTouchAxis = false
    self.preTouchWorldPos = worldPos

    -- plugins
    self.touchPlugin = nil
    for k,v in pairs(self.plugins) do
        if v:onTouchBegan(touch, event) then
            self.touchPlugin = v
            break
        end
    end

    if self:isBlockEleTouchEvent() then
        return true
    end

    -- 先判断是否点击到虚拟坐标轴
    if self.axisDraw.isShow then
        local isOverlapRect, isOverlapX, isOverlapY = false, false, false
        isOverlapRect = self.axisDraw:collisionTestRect(worldPos)
        if not isOverlapRect then
            isOverlapX = self.axisDraw:collisionTestX(worldPos)
            if not isOverlapX then
                isOverlapY = self.axisDraw:collisionTestY(worldPos) 
            end
        end
        self.axisCache.isOverlapRect = isOverlapRect
        self.axisCache.isOverlapX = isOverlapX
        self.axisCache.isOverlapY = isOverlapY
        self.axisCache.isTouchAxis = isOverlapRect or isOverlapX or isOverlapY
    end

    -- 
    if self.axisCache.isTouchAxis then
        self.cancelAllFocusEleTag = false
        self.touchAnyEleTag = true
    else
        local focusEle = nil
        self.rootElement:forEachChildrenReverse(function(ele)
            if not ele:isEmptyNode() then
                ele:updateCollisionData()
                if cc.rectContainsPoint(ele.worldAABB, worldPos) and G_Helper.pointInPolygon(worldPos, ele.worldPoints) then
                    focusEle = ele
                    return true
                end
            end
        end)

        self.willCancelFocusEle = nil
        if focusEle then
            self.cancelAllFocusEleTag = false
            self.touchAnyEleTag = true
            local isFocusPre = self:isFocusElement(focusEle)
            if isFocusPre then
                self.willCancelFocusEle = focusEle
            else
                self:addFocusElement(focusEle, not _MyG.KeyboardStateMng:keyCodeIsPressed(cc.KeyCode.KEY_CTRL))
            end
        end
    end

    return true
end

function BaseEditorCocos:onTouchMoved(touch, event)
    -- 按住空格时拦截事件，用于拖动画布
    if _MyG.KeyboardStateMng:keyCodeIsPressed(cc.KeyCode.KEY_SPACE) then
        return
    end

    if self.touchPlugin then
        self.touchPlugin:onTouchMoved(touch, event)
    end

    if self:isBlockEleTouchEvent() then
        return
    end

    local worldPos = self.axisDraw:convertToNodeSpace(_MyG.MouseEventDispatcher:getCursorPos())

    -- 拖动元素逻辑
    if self.touchAnyEleTag then
        self.willCancelFocusEle = nil
        local offset = cc.pSub(worldPos, self.preTouchWorldPos)

        if self.axisCache.isTouchAxis then
            if self.axisCache.isOverlapX then
                offset.y = 0
            elseif self.axisCache.isOverlapY then
                offset.x = 0
            end
        end

        self:doFocusElementDrag(offset)
    end
    self.preTouchWorldPos = worldPos
end

function BaseEditorCocos:onTouchEnded(touch, event)
    if self.touchPlugin then
        self.touchPlugin:onTouchEnded(touch, event)
        self.touchPlugin = nil
    end

    if self:isBlockEleTouchEvent() then
        return
    end

    if self.cancelAllFocusEleTag then
        self:clearFocusElement()
        self.cancelAllFocusEleTag = false
    else
        if self.willCancelFocusEle then
            if _MyG.KeyboardStateMng:keyCodeIsPressed(cc.KeyCode.KEY_CTRL) then
                self:cancelFocusElement(self.willCancelFocusEle)
            else
                self:clearFocusElement()
                self:addFocusElement(self.willCancelFocusEle, true)
            end
            self.willCancelFocusEle = nil
        end
    end

    self.axisCache.isTouchAxis = false
end

function BaseEditorCocos:onTouchCancelled(touch, event)
    if self.touchPlugin then
        self.touchPlugin:onTouchCancelled(touch, event)
        self.touchPlugin = nil
    end

    self.axisCache.isTouchAxis = false
end

-- @brief 删除键按下
function BaseEditorCocos:onKeyBoardDelete()
    if BaseEditorCocos.super.onKeyBoardDelete(self) then
        return
    end
    if #self.focusEles > 0 then
        -- 快照保存
        self:saveSnapshot()

        local focusEles = {}

        for k,v in pairs(self.focusEles) do
            focusEles[k] = v
        end

        self:clearFocusElement()

        -- 删除选中元素
        for k,v in pairs(focusEles) do
            v:removeFromParent()
            v:onDestroy()
        end
    end
end

-- @brief 资源拖拽
function BaseEditorCocos:onAssetDragEnd(assetItem, pos)
    local property  = assetItem.property
    local resType = property.resType

    if resType == Asset.ResType.PNG or resType == Asset.ResType.JPG then
        self:genElement(function()
            local data = {
                position = pos,
            }
            data.isPlist = false
            data.plistFileName = ""
            data.textureName = property.relativePath
    
            return _MyG.ElementFactory:spawn("Sprite", {data = data}, self)
        end)
    elseif resType == Asset.ResType.PLIST_SUBGRAPH then
        self:genElement(function()
            local data = {
                position = pos,
            }
            data.isPlist = true
            data.plistFileName = property.relativePath
            data.textureName = property.textureName
    
            return _MyG.ElementFactory:spawn("Sprite", {data = data}, self)
        end)
    elseif resType == Asset.ResType.LUA then
        self:genElement(function()
            local data = {
                position = pos,
                scriptFile = property.relativePath,
            }
    
            return _MyG.ElementFactory:spawn("CocostudioFile", {data = data}, self)
        end)
    elseif resType == Asset.ResType.EXPORTJSON or resType == Asset.ResType.SPINE then
        self:genElement(function()
            local data = {
                position = pos,
                resFile = property.relativePath,
            }
    
            return _MyG.ElementFactory:spawn("ArmatureFile", {data = data}, self)
        end)
    end
end

-- @brief 预制体拖拽
function BaseEditorCocos:onDragPreWidgetDragEnd(typeName, pos)

    -- print("onDragPreWidgetDragEnd", typeName, pos.x, pos.y)

    for k,v in pairs(self.plugins) do
        if v:onDragPreWidgetDragEnd(typeName, pos) then
            return
        end
    end

    local data = {
        position = pos,
        isPlist = false,
        plistFileName = "",
    }
    if typeName == "WC_Image" then
        data.textureName = "Default/ImageFile.png"
    elseif typeName == "WC_Sprite" then
        data.textureName = "Default/Sprite.png"
    else
        return
    end

    self:genElement(function()
        if typeName == "WC_Image" then
            return _MyG.ElementFactory:spawn("Image", {data = data}, self)
        elseif typeName == "WC_Sprite" then
            return _MyG.ElementFactory:spawn("Sprite", {data = data}, self)
        end
    end)
end

function BaseEditorCocos:onNodeContentGUI(nodeContent)
    if self.rootElement then
        for k,v in pairs(self.rootElement.children) do
            v:onNodeContentGUI(nodeContent)
        end
    end
end

-- @brief 画布缩放发生改变
function BaseEditorCocos:onRenderScaleChange(scale)
end

-- @brief 元素拖动回调
function BaseEditorCocos:doFocusElementDrag(offset)
    if math.abs(offset.x) < 1e-5 and math.abs(offset.y) < 1e-5 then
        return
    end

    local function hasParent(curNode)
        local p = nil
        while true
        do
            p = curNode.parent
            if p == nil then
                return
            end
            for k,v in pairs(self.focusEles) do
                if v == p then
                    return true
                end
            end
            curNode = p
        end
    end

    local zeroOffset  = self.axisDraw:convertToWorldSpace(cc.p(0, 0))
    local worldOffset = self.axisDraw:convertToWorldSpace(offset)

    self:beginSaveSnapshot()
    for k,v in pairs(self.focusEles) do
        if not hasParent(v) then
            local render = v:getRenderNode()
            if render then
                local offset1 = render:getParent():convertToNodeSpace(zeroOffset)
                local offset2 = render:getParent():convertToNodeSpace(worldOffset)
                v:doElementDrag(cc.pSub(offset2, offset1))
            end
        end
    end
    self:endSaveSnapshot()
end

-- @brief 创建元素
function BaseEditorCocos:genElement(func)
    local ele = func()

    if not ele then
        logE("genElement Error!!!")
        return
    end

    -- 快照保存
    self:saveSnapshot()

    ele:setName(self:genName(ele.type))
    self.rootElement:addChild(ele)

    self:addFocusElement(ele, true)
end

function BaseEditorCocos:onEditorDraw()
    self.borderDraw:clear()
    self.axisDraw:clearEx()

    -- self.rootElement:forEachChildren(function(ele)
    --     if not ele:isEmptyNode() and ele.isFocusCell then
    --         ele:updateCollisionData()

    --         local points = ele:getWorldPoints()
    --         local drawColor = lineColor
    --         -- draw border
    --         for i = 1, #points do
    --             if i == #points then
    --                 self.borderDraw:drawSegment(points[i], points[1], default_lineWidth, drawColor)
    --             else
    --                 self.borderDraw:drawSegment(points[i], points[i + 1], default_lineWidth, drawColor)
    --             end
    --         end
    --     end
    -- end)

    local first = true
    for k,ele in pairs(self.focusEles) do
        if not ele:isEmptyNode() then
            ele:updateCollisionData()
            if first then
                -- 碰撞测试
                if not self.axisCache.isTouchAxis then
                    local worldPos = self.axisDraw:convertToNodeSpace(_MyG.MouseEventDispatcher:getCursorPos())
                    local isOverlapRect, isOverlapX, isOverlapY = false, false, false
                    isOverlapRect = self.axisDraw:collisionTestRect(worldPos)
                    if not isOverlapRect then
                        isOverlapX = self.axisDraw:collisionTestX(worldPos)
                        if not isOverlapX then
                            isOverlapY = self.axisDraw:collisionTestY(worldPos) 
                        end
                    end
                    -- 虚拟坐标绘制
                    self.axisDraw:drawAxis(ele:getWorldAnchorPoint(), isOverlapRect, isOverlapX, isOverlapY)
                else
                    -- 虚拟坐标绘制
                    self.axisDraw:drawAxis(ele:getWorldAnchorPoint(), self.axisCache.isOverlapRect, self.axisCache.isOverlapX, self.axisCache.isOverlapY)
                end

                first = false
            end
            
            local points = ele:getWorldPoints()
            local drawColor = lineColor
            -- draw border
            for i = 1, #points do
                if i == #points then
                    self.borderDraw:drawSegment(points[i], points[1], default_lineWidth, drawColor)
                else
                    self.borderDraw:drawSegment(points[i], points[i + 1], default_lineWidth, drawColor)
                end
            end
        end
    end

    for k,v in pairs(self.plugins) do
        v:onEditorDraw()
    end
end

return BaseEditorCocos