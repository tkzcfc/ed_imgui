-- @Author : fc
-- @Date   : 2021-07-08 10:42:28
-- @remark : 窗口管理

local WindowManager = class("WindowManager")

function WindowManager:ctor()
    self.windows = {}
    self.removeWindows = {}
end

function WindowManager:onGUI()
    if self.bRemoveDirty then
        self.bRemoveDirty = false

        repeat
            if #self.removeWindows <= 0 then break end
            local win = table.remove(self.removeWindows)

            for k, v in pairs(self.windows) do
                if v == win then
                    win.winManager = nil
                    win:onDestroy()
                    table.remove(self.windows, k)
                    break
                end
            end
        until(false)
    end

    for k, v in pairs(self.windows) do
        if v.bShow then
            v:onGUI()
        end
    end
end

function WindowManager:add(win, winTag)
    win.winManager = self
    win.winTag = winTag
    table.insert(self.windows, win)
end

function WindowManager:remove(win)
    table.insert(self.removeWindows, win)
    self.bRemoveDirty = true
end

function WindowManager:getWindows()
    return self.windows
end

function WindowManager:showWindow(winTag, show)
    for k, v in pairs(self.windows) do
        if v.winTag == winTag then
            v:setWindowVisible(show)
            break
        end
    end
end

return WindowManager
