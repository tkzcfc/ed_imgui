local CellBase = class("CellBase")


function CellBase:ctor(context)
	self.context = context
	self:enableTouch()
end

function CellBase:onMouseScroll(event)
end

function CellBase:onMouseDown(event)
end

function CellBase:onMouseMove(event)
end

function CellBase:onMouseUp(event)
end

function CellBase:onTouchBegin(touch, event)
end

function CellBase:onTouchMove(touch, event)
end

function CellBase:onTouchEnd(touch, event)
end

function CellBase:onAdd()
end

function CellBase:onRemove()
	self.context = nil
end

-- 聚焦
function CellBase:onFocus()
end

-- 失焦
function CellBase:onLoseFocus()
end

function CellBase:onGUI()
end

function CellBase:dataDirty()
	if self.context then
		self.context.dirty = true
	end
end

function CellBase:isNode()
	return false
end

function CellBase:focus()
	self.context:changeFocusCell(self)
end


function CellBase:disenableTouch()
	self.disenableTouchTag = true
end

function CellBase:enableTouch()
	self.disenableTouchTag = false
end

function CellBase:bindFocusCall(node, testCall)
	if testCall == nil then
		testCall = function(touch,event)
			return Tools:isInRect(node, touch:getLocation().x, touch:getLocation().y)
		end
	end

	local function onTouchBegin(touch,event)
		-- 快速编辑矩形按键
		if _MyG.KeyboardStateMng:keyCodeIsPressed(cc.KeyCode.KEY_SHIFT) then
			return
		end

		if self.disenableTouchTag or self.context.isFreezeCellTag then
			return false
		end
		if self.context.isVisible and not self.context.fixFocusCellTag and testCall(touch, event) then
			self.context.fixFocusCellTag = true
			self:focus()
		end
    	return false
    end

    local listener = cc.EventListenerTouchOneByOne:create()
    listener:registerScriptHandler(onTouchBegin,cc.Handler.EVENT_TOUCH_BEGAN)
    cc.Director:getInstance():getEventDispatcher():addEventListenerWithSceneGraphPriority(listener, node)
end

-- 序列化
function CellBase:serialize()
end

-- 反序列化
function CellBase:deserialize(data)
end

-- 发布
function CellBase:publish()
end

-- 获取引用资源
function CellBase:getReferenceResources()
	return {}
end

-- 获取碰撞矩形
function CellBase:getBox()
	return cc.rect(0, 0, 0, 0)
end

return CellBase
