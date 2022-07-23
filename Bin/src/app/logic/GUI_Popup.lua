-- @Author : fc
-- @Date   : 2021-8-27 18:21:05
-- @remark : imgui 弹窗

local PopupManager = require("app.imgui.PopupManager").new()

_MyG.PopupManager = PopupManager

G_SysEventEmitter:on(SysEvent.ON_GUI_POPUP, function()
    PopupManager:onGUI()
end, SysEvent.TAG)