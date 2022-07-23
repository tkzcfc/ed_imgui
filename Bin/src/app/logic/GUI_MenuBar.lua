-- @Author: fangcheng
-- @Date:   2020-04-05 17:21:33
-- @Description: 

local function onGUI()
	if ImGui.BeginMainMenuBar() then
	    G_SysEventEmitter:emit(SysEvent.ON_GUI_MAIN_MENUBAR)
	    ImGui.EndMainMenuBar()
	end
end

_MyG.edContext:registerLuaHandle("onGUI_MenuBar", onGUI)

require("app.logic.Menu")
require("app.logic.MenuItem")
