-- @Author : fc
-- @Date   : 2021-8-31 11:42:17
-- @remark : 文本输入


local InputText = class("InputText", require("app.imgui.Popup"))

function InputText:ctor(name)
    InputText.super.ctor(self, name)
    
    -- self:setWindowFlag(Tools:bor_int32(ImGuiWindowFlags_AlwaysAutoResize, ImGuiWindowFlags_NoMove))
    self:setWindowFlag(ImGuiWindowFlags_AlwaysAutoResize)
    self.curText = ""
end

-- @override
function InputText:iOnGUI()
    local enter_true, inputName = Tools:imgui_inputText(STR("Name"), self.curText, 32, ImGuiInputTextFlags_EnterReturnsTrue)
    self.curText = inputName

    -- 点击回车
    if enter_true then
        self:close()
        if self.onInputCallback then
            self.onInputCallback(self.curText)
        end
    end
    ImGui.Separator()

    if ImGui.Button("OK", cc.p(-1, 0)) then
        self:close()
        if self.onInputCallback then
            self.onInputCallback(self.curText)
        end
    end
end

function InputText:setInputTextCallback(call)
    self.onInputCallback = call
end

function InputText:setCurText(text)
    self.curText = text
end

return InputText