-- @Author : fc
-- @Date   : 2021-9-2 10:17:37
-- @remark : ImGui Demo

local ImGuiDemo = class("ImGuiDemo", require("app.imgui.Window"))

function ImGuiDemo:onGUI()
    self.bShow = ImGui.ShowDemoWindow(self.bShow)

    -- if not self.bShow and self.autoDestroy then
    --     self:destroyWindow()
    -- end
end

return ImGuiDemo