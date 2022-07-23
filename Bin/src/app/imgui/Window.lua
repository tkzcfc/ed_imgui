-- @Author : fc
-- @Date   : 2021-07-08 10:42:28
-- @remark : 窗口

local Window = class("Window")

function Window:ctor(name, unique)
    if name == nil then
        self.winName = "##" .. tostring(self)
    else
        if unique then
            self.winName = name
        else
            self.winName = name .. "##" .. tostring(self)
        end
    end

    self.bUnique = true
    self.bShow = true
    self:setAutoDestroy(false)
    self:setWindowFlags(0)
    self:setWindowSize(cc.p(300, 400))
end

function Window:getWinName()
    return self.winName
end

-- @brief 设置窗口标记
function Window:setWindowFlags(flags)
    if not self.bUnique then
        flags = Tools:bor_int32(flags, ImGuiWindowFlags_NoSavedSettings)
    end
    self.winFlags = flags
end

function Window:getWindowFlags()
    return self.winFlags
end

function Window:onGUI()
	ImGui.SetNextWindowSize(self.winSize, self.winSizeCond);

    local ret = false
    ret, self.bShow = ImGui.Begin(self.winName, self.bShow, self.winFlags)
    if ret then
        self:onGUI_Window()
    end

    if self.autoDestroy and not self.bShow then
        self:destroyWindow()
    end

    ImGui.End()
end

-- @brief 窗口内容GUI绘制
function Window:onGUI_Window()
end

-- @brief 窗口显示设置
function Window:setWindowVisible(visible)
    self.bShow = visible
end

function Window:isWindowVisible()
    return self.bShow
end

-- @brief 设置窗口大小
-- @param size 窗口大小
-- @param cond ImGui::SetNextWindowSize 第二个参数
function Window:setWindowSize(size, cond)
    self.winSize = size
    self.winSizeCond = cond or ImGuiCond_FirstUseEver
end

-- @brief 自动销毁
function Window:setAutoDestroy(value)
    self.autoDestroy = value
end

-- @brief 窗口销毁
function Window:destroyWindow()
    self.winManager:remove(self)
end

-- @brief 被销毁前的回调
function Window:onDestroy()
    G_SysEventEmitter:offByTag(self)
end

return Window
