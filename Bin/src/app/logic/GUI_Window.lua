-- @Author : fc
-- @Date   : 2021-9-2 10:14:04
-- @remark : 

cc.exports.WinTag = enum {
    "IMGUI_DEMO",
    "ROLE",
    "GLOBAL_SCALE",
    "FONT_SETTING",
}

local WindowManager = require("app.imgui.WindowManager").new()

_MyG.WindowManager = WindowManager

G_SysEventEmitter:on(SysEvent.ON_GUI, function()
    WindowManager:onGUI()
end, SysEvent.TAG)

local win

-- ImGui Demo
win = require("app.imgui.window.ImGuiDemo").new("ImGui Demo", true)
win:setWindowVisible(false)
WindowManager:add(win, WinTag.IMGUI_DEMO)

-- RoleInfoWindow
win = require("app.imgui.window.RoleInfoWindow").new("Role", true)
win:setWindowVisible(false)
WindowManager:add(win, WinTag.ROLE)

-- GlobalScaleWindow
win = require("app.imgui.window.GlobalScaleWindow").new("Global Scale", true)
win:setWindowVisible(false)
WindowManager:add(win, WinTag.GLOBAL_SCALE)

-- GlobalScaleWindow
win = require("app.imgui.window.FontSetting").new("Font", true)
win:setWindowVisible(false)
WindowManager:add(win, WinTag.FONT_SETTING)
