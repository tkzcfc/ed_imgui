-- @Author: fangcheng
-- @URL: github.com/tkzcfc
-- @Date:   2020-04-05 17:21:33
-- @Last Modified by:   fangcheng
-- @Last Modified time: 2020-04-06 13:09:30
-- @Description: 

local function onGUI()
	if ImGui.BeginMainMenuBar() then
	    G_SysEventEmitter:emit("onGUI_MainMenuBar")
	    ImGui.EndMainMenuBar()
	end
end

_MyG.edContext:registerLuaHandle("onGUI_MenuBar", onGUI)

require("app.logic.Menu")
require("app.logic.MenuItem")

-- G_SysEventEmitter:on("onGUI", function() print("onGUI_MainMenuBar") end)