-- @Author: fangcheng
-- @Date:   2020-04-05 17:13:40
-- @Description: 

local function onGUI()
	_MyG.TopDocumentManager:onGUI()
end


_MyG.edContext:registerLuaHandle("onGUI_Top", onGUI)