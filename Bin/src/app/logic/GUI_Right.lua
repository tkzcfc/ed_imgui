-- @Author: fangcheng
-- @URL: github.com/tkzcfc
-- @Date:   2020-04-05 17:14:07
-- @Last Modified by:   fangcheng
-- @Last Modified time: 2020-04-05 17:28:52
-- @Description: 

local function onGUI()
	_MyG.RightDocumentManager:onGUI()
end


_MyG.edContext:registerLuaHandle("onGUI_Right", onGUI)


local attribute = require("app.document.AttributeContent").new()
_MyG.RightDocumentManager:addDocument(attribute)