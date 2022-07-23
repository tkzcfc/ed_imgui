-- @Author : fc
-- @Date   : 2021-8-27 18:21:05
-- @remark : imgui 弹窗管理

local PopupManager = class("PopupManager")

function PopupManager:ctor()
    self.popups = {}
    self.removePopups = {}
    self.popCount = 0
end

function PopupManager:onGUI()
    -- 删除无效popup
    repeat
        if #self.removePopups <= 0 then
            break
        end
        local pop = table.remove(self.removePopups)
        for k, v in pairs(self.popups) do
            if v == pop then
                pop.manager = nil
                self.popCount = self.popCount - 1
                table.remove(self.popups, k)
                break
            end
        end
    until(false)
    
    if self.popCount <= 0 then return end

    -- gui
    self:stackRender(1)
end

function PopupManager:stackRender(index)
    if self.popups[index] == nil then
        return
    end

    self.popups[index]:onGUI(function()
        self:stackRender(index + 1)
    end)
end

function PopupManager:addPopup(pop)
    pop.manager = self

    self.popCount = self.popCount + 1
    table.insert(self.popups, pop)
end

function PopupManager:remvoePopup(pop)
    table.insert(self.removePopups, pop)
end

function PopupManager:getPopCount()
    return self.popCount
end

return PopupManager
