-- @Author: fangcheng
-- @Date:   2020-04-05 17:14:07
-- @Description: 

local function onGUI()
	_MyG.RightDocumentManager:onGUI()
end


_MyG.edContext:registerLuaHandle("onGUI_Right", onGUI)


local attribute = require("app.document.AttributeContent").new()
_MyG.RightDocumentManager:addDocument(attribute)