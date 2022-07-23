-- @Author : fc
-- @Date   : 2021-8-31 11:03:26
-- @remark : loading显示


local Loading = class("Loading", require("app.imgui.Popup"))

function Loading:ctor(name)
    Loading.super.ctor(self, name)
    
    local loadingWindowFlag = ImGuiWindowFlags_NoTitleBar
    loadingWindowFlag = Tools:bor_int32(loadingWindowFlag, ImGuiWindowFlags_NoMove)
    loadingWindowFlag = Tools:bor_int32(loadingWindowFlag, ImGuiWindowFlags_AlwaysAutoResize)
    self:setWindowFlag(loadingWindowFlag)
end

-- @override
function Loading:iOnGUI()
    if self.percent == nil then
        ImGui.Text("Loading...")
    else
        local str = string.format("Loading(%.1f/100)...", self.percent * 100)
        ImGui.Text(str)
    end
end

function Loading:setPercent(percent)
    self.percent = percent
end

return Loading