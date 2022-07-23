-- @Author: fangcheng
-- @Date:   2020-04-12 13:52:08
-- @remark: 键盘事件管理

local KeyboardStateMng = class("KeyboardStateMng")

function KeyboardStateMng:ctor()
    self.stateMap = {}
    --键盘事件  
    local function onKeyPressed(keyCode, event)
        -- print("pressed", keyCode, cc.KeyCodeKey[keyCode + 1])
        self.stateMap[keyCode] = true

        if not self:canDispatch() then
            return
        end

        -- Ctrl + S
        if self:keyCodeIsPressed(cc.KeyCode.KEY_CTRL) and self:keyCodeIsPressed(cc.KeyCode.KEY_S) then
            G_SysEventEmitter:emit(SysEvent.ON_KEY_BOARD_SAVE)
        end

        -- Ctrl + Z
        if self:keyCodeIsPressed(cc.KeyCode.KEY_CTRL) and self:keyCodeIsPressed(cc.KeyCode.KEY_Z) then
            G_SysEventEmitter:emit(SysEvent.ON_KEY_BOARD_UNDO)
        end

        -- Ctrl + A
        if self:keyCodeIsPressed(cc.KeyCode.KEY_CTRL) and self:keyCodeIsPressed(cc.KeyCode.KEY_A) then
            G_SysEventEmitter:emit(SysEvent.ON_KEY_BOARD_ALL)
        end

        -- 删除键
        if self:keyCodeIsPressed(cc.KeyCode.KEY_DELETE) then
            G_SysEventEmitter:emit(SysEvent.ON_KEY_BOARD_DELETE)
        end
    end  
  
    local function onKeyReleased(keyCode, event)
        -- print("released", keyCode)
        self.stateMap[keyCode] = false

        if not self:canDispatch() then
            return
        end

        if not self:haskeyCodePressed() then
            G_SysEventEmitter:emit(SysEvent.ON_KEY_BOARD_SINGLE_PRESSED, keyCode)
        end
    end  
  
    local listener = cc.EventListenerKeyboard:create()  
    listener:registerScriptHandler(onKeyPressed, cc.Handler.EVENT_KEYBOARD_PRESSED)  
    listener:registerScriptHandler(onKeyReleased, cc.Handler.EVENT_KEYBOARD_RELEASED)  
    cc.Director:getInstance():getEventDispatcher():addEventListenerWithFixedPriority(listener, 1)
end

function KeyboardStateMng:canDispatch()
    local imgIO = ImGui.GetIO()
    return not imgIO.WantTextInput and not ImGui.IsAnyMouseDown()
end

function KeyboardStateMng:keyCodeIsPressed(keyCode)
    return self.stateMap[keyCode]
end

function KeyboardStateMng:haskeyCodePressed()
    for k,v in pairs(self.stateMap) do
        if v == true then
            return true
        end
    end
    return false
end

function KeyboardStateMng:getPressedKeyCodeCount()
    local count = 0
    for k,v in pairs(self.stateMap) do
        if v == true then
            count = count + 1
        end
    end
    return count
end

function KeyboardStateMng:setKeyCodePressed(keyCode, isPressed)
    self.stateMap[keyCode] = isPressed
end

-- @brief 是否可以缩放编辑区域内容
function KeyboardStateMng:canScrollEditContext()
    -- return not self:haskeyCodePressed()
    return true
end

return KeyboardStateMng

