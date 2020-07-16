-- @Author: fangcheng
-- @URL: github.com/tkzcfc
-- @Date:   2020-04-05 17:13:40
-- @Last Modified by:   fangcheng
-- @Last Modified time: 2020-04-05 17:17:09
-- @Description: 

local function onGUI()
	_MyG.TopDocumentManager:onGUI()
end


_MyG.edContext:registerLuaHandle("onGUI_Top", onGUI)