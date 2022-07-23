-- @Author: fangcheng
-- @Date:   2021-07-25 14:50:45
-- @remark: 


_MyG.arrManagers        = {}

_MyG.SysSetManager      = require("app.manager.SysSetManager").new()
_MyG.AudioManager       = require("app.manager.AudioManager").new()
_MyG.ThemeManager       = require("app.manager.ThemeManager").new()

-- G_SysEventEmitter:on("event_appWillExit", function()
--     for k,v in pairs(_MyG.arrManagers) do
--         v:destroy()
--     end
--     _MyG.arrManagers = {}
-- end, SysEvent.TAG)

-- G_SysEventEmitter:on("event_restartApp", function()
--     for k,v in pairs(_MyG.arrManagers) do
--         v:destroy()
--     end
--     _MyG.arrManagers = {}
-- end, SysEvent.TAG)
