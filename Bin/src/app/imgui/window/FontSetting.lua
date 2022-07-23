-- @Author : fc
-- @Date   : 2022-1-16 16:25:23
-- @remark : 字体设置

local ImGuiDemo = class("ImGuiDemo", require("app.imgui.Window"))

function ImGuiDemo:ctor(...)
    ImGuiDemo.super.ctor(self, ...)

    local flags = 0
    flags = Tools:bor_int32(flags, ImGuiWindowFlags_NoSavedSettings)
    
    self:setWindowFlags(flags)

    oRoutine(o_once(function()
		-- o_wait(o_seconds(0))
        local fontName = _MyG.sysStorage["sFontName"]
        if fontName and fontName ~= "" then
            if not Tools:setImguiFontName(fontName) then
                _MyG.sysStorage["sFontName"] = ""
            end
        end
	end))
end

function ImGuiDemo:onGUI_Window()
    if Tools:onGUIFontList() then
        _MyG.sysStorage["sFontName"] = Tools:getImguiFontName()
    end
end

return ImGuiDemo