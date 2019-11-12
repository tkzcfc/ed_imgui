local KeyboardStateMng = class("KeyboardStateMng")

function KeyboardStateMng:ctor()
    self.stateMap = {}
    --键盘事件  
    local function onKeyPressed(keyCode, event)
        -- print("pressed", keyCode)
        self.stateMap[keyCode] = true

        -- Ctrl + S
        if _MyG.KeyboardStateMng:keyCodeIsPressed(14) and _MyG.KeyboardStateMng:keyCodeIsPressed(142) then
            G_SysEventEmitter:emit("onKeyBoardSave")
        end
    end  
  
    local function onKeyReleased(keyCode, event)
        -- print("released", keyCode)
        self.stateMap[keyCode] = false
        if not self:haskeyCodePressed() then
            G_SysEventEmitter:emit("onKeyBoard_Single", keyCode)
        end
    end  
  
    local listener = cc.EventListenerKeyboard:create()  
    listener:registerScriptHandler(onKeyPressed, cc.Handler.EVENT_KEYBOARD_PRESSED)  
    listener:registerScriptHandler(onKeyReleased, cc.Handler.EVENT_KEYBOARD_RELEASED)  
    cc.Director:getInstance():getEventDispatcher():addEventListenerWithFixedPriority(listener, 1)
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

return KeyboardStateMng

