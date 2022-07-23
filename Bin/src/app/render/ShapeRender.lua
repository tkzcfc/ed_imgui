-- @Author : fc
-- @Date   : 2021-9-7 15:13:56
-- @remark : 形状渲染

local ShapeRender = class("ShapeRender", cc.DrawNode)


local ShapeType = ShapeType

local CHANGE_RECT_SCALE = {
    cc.p(-1, -1),
    cc.p(1, -1),
    cc.p(1, 1),    
    cc.p(-1, 1),
}

-- 关键点被点击时的颜色
local color_spr_touch = cc.c3b(0x6d, 0x68, 0x74)
-- 关键点正常状态颜色
local color_spr_normal = cc.c3b(255, 255, 255)

function ShapeRender:ctor()
    -- 关键点显示精灵
    self.sprKeyPoints = {}
    self.shapeType = ShapeType.UNKNOWN

    self.operatePointScale = 1.0

    self.cacheShapes = {}

    self:initEditNode()
end

-- @brief 初始化编辑节点
function ShapeRender:initEditNode()

    self.editNode = cc.Layer:create()
    self:addChild(self.editNode)

    self.editNode:onTouch(function(event)
        return self:onTouchEditNode(event)
    end, false, true)

    _MyG.CenterWindow:changeEventDispatcherSelf(self.editNode)
end

-- @brief 设置形状数据
function ShapeRender:setShapeData(shapeType, data, enableEdit)
    self.curType = shapeType

    local shape = self.cacheShapes[shapeType]

    if shape == nil then
        if shapeType == ShapeType.RECT then
            shape = CRect:new_local()
        elseif shapeType == ShapeType.POLYGON then
            shape = CPolygon:new_local()
        elseif shapeType == ShapeType.CIRCLE then
            shape = CCircle:new_local()
        else
            asset(false)
        end

        self.cacheShapes[shapeType] = shape
    end

    shape:deserialize(data)

    self.shape = shape
    
    self:setEditEnabled(enableEdit)
    if not enableEdit then
        self:updateRender()
    end
end

-- @brief 设置是否启用编辑功能
function ShapeRender:setEditEnabled(enabled)
    self.bEditEnabled = enabled
    self.editNode:setVisible(enabled)

    if not enabled then
        return
    end

    -- 中心点
    if self.sprDot == nil then
        self.sprDot = cc.Sprite:create("Built-in/Icon_opreate.png")
        self.sprDot:setScale(self.operatePointScale)
        self.editNode:addChild(self.sprDot)
    end

    -- 编辑关键点
    local count = self:getKeyPointsCount()

    -- 删除多余的
    for i = 1, #self.sprKeyPoints - count do
        local spr = table.remove(self.sprKeyPoints)
        spr:removeFromParent()
    end
    -- 补充不足的
    for i = 1, count - #self.sprKeyPoints do
        local spr = cc.Sprite:create("Built-in/Icon_opreate.png")
        spr:setScale(self.operatePointScale)
        self.editNode:addChild(spr)

        table.insert(self.sprKeyPoints, spr)
    end

    self:updateRender()
end

function ShapeRender:getShape()
    return self.shape
end

-- @brief 属性重置
function ShapeRender:reset()
    self.shape = nil
    self.curType = ShapeType.UNKNOWN
    self:clear()
    self:setEditEnabled(false)
    self:setVisible(false)
end

-- @brief 显示刷新
function ShapeRender:updateRender()
    self:clear()
    -- 矩形
    if self.curType == ShapeType.RECT then
        self.shape:debugDraw(self)
    -- 多边形
    elseif self.curType == ShapeType.POLYGON then
        self.shape:debugDraw(self)
    -- 圆形
    elseif self.curType == ShapeType.CIRCLE then
        self.shape:debugDraw(self)
    else
        self:setVisible(false)
        return  
    end
    self:setVisible(true)

    if not self.bEditEnabled then return end

    
    -- 矩形
    if self.curType == ShapeType.RECT then
        for k, v in pairs(self.sprKeyPoints) do
            v:setPosition(self.shape:getVertexByIndex(k - 1))
        end

        self.sprDot:setVisible(true)
        self.sprDot:setPosition(self.shape:getPoint())
    -- 多边形
    elseif self.curType == ShapeType.POLYGON then
        self.sprDot:setVisible(false)
        for k, v in pairs(self.sprKeyPoints) do
            v:setPosition(self.shape:getVertex(k - 1))
        end
    -- 圆
    elseif self.curType == ShapeType.CIRCLE then
        local center = self.shape:getCenter()
        self.sprDot:setVisible(true)
        self.sprDot:setPosition(center)
        for k, v in pairs(self.sprKeyPoints) do
            v:setPosition(center.x + self.shape:getRadius(), center.y)
        end
    end
end

-- @brief 设置操作点缩放系数
function ShapeRender:setOperatePointScale(scale)
    self.operatePointScale = scale
    if self.sprDot then
        self.sprDot:setScale(scale)
    end
    for k, v in pairs(self.sprKeyPoints) do
        v:setScale(scale)
    end
end

-- @brief 获取形状关键点数量
function ShapeRender:getKeyPointsCount()
    -- 矩形
    if self.curType == ShapeType.RECT then
        return self.shape:getVertexCount()
    -- 多边形
    elseif self.curType == ShapeType.POLYGON then
        return self.shape:getVertexCount()
    -- 圆
    elseif self.curType == ShapeType.CIRCLE then
        return 1
    end
    return 0
end

-- @brief 触摸事件处理
function ShapeRender:onTouchEditNode(event)
    if not self.bEditEnabled then return end
    if self.curType == ShapeType.UNKNOWN then return end

    if event.name == "began" then
        local node, index = self:touchTest(event)
        
        self.touchSpr = node
        self.touchIndex = index
        self.touchEditDirty = false
        
        if self.touchSpr then
            self.touchSpr:setColor(color_spr_touch)
            self.touchBeginPos = self:convertToNodeSpace(event)
            return true
        end
    elseif event.name == "moved" then
        -- 矩形
        if self.curType == ShapeType.RECT then
            self:move_rect(event)
        -- 多边形
        elseif self.curType == ShapeType.POLYGON then
            self:move_polygon(event)
        -- 圆形
        elseif self.curType == ShapeType.CIRCLE then
            self:move_circle(event)
        end
    else
        if self.touchSpr then
            self.touchSpr:setColor(color_spr_normal)
        end
        self.touchSpr = nil
        self.touchIndex = -1

        if self.touchEditDirty then
            self.touchEditDirty = false
            self:editFinish()
        end
    end
    
    return false
end

-- @brief 触摸检测
function ShapeRender:touchTest(event)
    for i = #self.sprKeyPoints, 1, -1 do
        if Tools:isInRect(self.sprKeyPoints[i], event.x, event.y) then
            return self.sprKeyPoints[i], i
        end
    end

    if Tools:isInRect(self.sprDot, event.x, event.y) then
        return self.sprDot, -1
    end
end

function ShapeRender:move_rect(event)
    local curPos = self:convertToNodeSpace(event)
    local offset = cc.pSub(curPos, self.touchBeginPos)

    self.touchBeginPos = curPos

    -- 不改变
    if self:dispatchEditBeforeEvent() then return end

    self.touchEditDirty = true

    if self.touchIndex > 0 then
        local rectScale = CHANGE_RECT_SCALE[self.touchIndex]

        -- 修正偏移值
        offset.x = offset.x * rectScale.x
        offset.y = offset.y * rectScale.y

        -- 计算新的大小
        local size = self.shape:getContentSize()
        local newSize = cc.pAdd(size, offset)

        -- 防止小于0
        if newSize.x < 0 then newSize.x = 1 end
        if newSize.y < 0 then newSize.y = 1 end

        local center = self.shape:getPoint()

        -- 中心点偏移
        offset = cc.pSub(newSize, size)
        center.x = center.x + offset.x * rectScale.x * 0.5
        center.y = center.y + offset.y * rectScale.y * 0.5

        -- 重新设置新的数据
        self.shape:setContentSize(newSize.x, newSize.y)
        self.shape:setPoint(center.x, center.y)
        
        self:updateRender()
    else
        -- 更改中心坐标
        local pos = self.shape:getPoint()
        pos = cc.pAdd(pos, offset)
        self.shape:setPoint(pos.x, pos.y)

        self:updateRender()
    end
end

function ShapeRender:move_polygon(event)
    local curPos = self:convertToNodeSpace(event)
    local offset = cc.pSub(curPos, self.touchBeginPos)

    self.touchBeginPos = curPos

    if self.touchIndex > 0 then
        -- 不改变
        if self:dispatchEditBeforeEvent() then return end

        local index = self.touchIndex - 1

        local newPos = cc.pAdd(self.shape:getVertex(index), offset)
        self.shape:setVertex(newPos, index)

        self.touchEditDirty = true

        self:updateRender()
    end
end

function ShapeRender:move_circle(event)
    local curPos = self:convertToNodeSpace(event)
    local offset = cc.pSub(curPos, self.touchBeginPos)

    self.touchBeginPos = curPos

    -- 不改变
    if self:dispatchEditBeforeEvent() then return end

    self.touchEditDirty = true

    if self.touchIndex > 0 then
        local radius = self.shape:getRadius() + offset.x

        -- 防止半径太小
        if radius < 1 then
            radius = 1
        end

        self.shape:setRadius(radius)

        self:updateRender()
    else
        -- 更改中心坐标
        local pos = self.shape:getCenter()
        pos = cc.pAdd(pos, offset)
        self.shape:setCenter(pos.x, pos.y)

        self:updateRender()
    end
end

-- @brief 派发马上要改变数据事件
function ShapeRender:dispatchEditBeforeEvent()
    if self.onEditBeforeCall then
        return self.onEditBeforeCall()
    end
    return false
end

function ShapeRender:editFinish()
    if self.onEditChangeFinishCall then
        self.onEditChangeFinishCall()
    end
end

-- @brief 设置编辑前回调
function ShapeRender:setEditBeforeCallback(call)
    self.onEditBeforeCall = call
end

-- @brief 设置编辑完成回调
function ShapeRender:setEditChangeFinishCallback(call)
    self.onEditChangeFinishCall = call
end

return ShapeRender

