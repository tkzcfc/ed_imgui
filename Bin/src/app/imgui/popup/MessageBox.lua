-- @Author : fc
-- @Date   : 2021-8-30 18:21:33
-- @remark : 消息弹窗

local MessageBox = class("MessageBox", require("app.imgui.Popup"))

local msgBox_WidgetSize = cc.p(0, 0)
local msgBox_LayoutSize = cc.p(0, 0)

function MessageBox:ctor(name)
    MessageBox.super.ctor(self, name)

    local msgWindowFlag = 0
    -- msgWindowFlag = Tools:bor_int32(msgWindowFlag, ImGuiWindowFlags_NoMove)
    msgWindowFlag = Tools:bor_int32(msgWindowFlag, ImGuiWindowFlags_AlwaysAutoResize)
    self:setWindowFlag(msgWindowFlag)

    -- 消息文本内容
    self.content = ""
    -- 按钮
    self.btns = {}
end

-- @override
function MessageBox:iOnGUI()
    ImGui.Text(self.content)
    ImGui.Separator()

    msgBox_LayoutSize.x = ImGui.GetContentRegionAvailWidth()
    ImGui.BeginHorizontal("h1", msgBox_LayoutSize, 0.5)

    msgBox_WidgetSize.x = msgBox_LayoutSize.x / (#self.btns + 1)

    for k, v in pairs(self.btns) do
        ImGui.Spring(0.5)
        if ImGui.Button(v.btnText, msgBox_WidgetSize) then
            if v.call then
                v.call()
            end
            self:close()
        end
        ImGui.Spring(0.5)
    end

    ImGui.EndHorizontal()
end

function MessageBox:setContent(content)
    self.content = content
end

-- @brief 按钮添加
function MessageBox:addBtn(btnText, call)
    table.insert(self.btns, {
        btnText = btnText,
        call = call
    })
end

return MessageBox
