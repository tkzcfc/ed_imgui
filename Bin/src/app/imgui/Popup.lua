local Popup = class("Popup")

function Popup:ctor(name)
    if name == nil then
        self.name = "##popup_" .. tostring(self)
    else
        self.name = name
    end
    self:setWindowFlag(0)
end

-- @brief 设置窗口标记
function Popup:setWindowFlag(winFlag)
    self.windowFlag = winFlag
end

-- @brief 设置GUI回调函数
function Popup:setGUICallback(call)
    self.onGUICall = call
end

function Popup:onGUI(call)
    if not self.openTag then
        self.openTag = true
        ImGui.OpenPopup(self.name)
    end

    self.bInGUiLogic = true

    if ImGui.BeginPopupModal(self.name, true, self.windowFlag) then
        self:iOnGUI()

        if self.willCloseTag then
            self:close()
        end

        call()

        ImGui.EndPopup()
    else
        self.manager:remvoePopup(self)
        if self.onDefaultClose then
            self.onDefaultClose()
        end
    end
    
    self.bInGUiLogic = false
end

-- @brief interface
function Popup:iOnGUI()
    if self.onGUICall then self.onGUICall() end
end

function Popup:close()
    if self.bInGUiLogic then
        ImGui.CloseCurrentPopup()
        self.manager:remvoePopup(self)
    else
        self.willCloseTag = true
    end
end

-- @brief 设置点击默认的关闭按钮回调，即右上角的x
function Popup:setDefaultCloseCall(call)
    self.onDefaultClose = call
end

return Popup