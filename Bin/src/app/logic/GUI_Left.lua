-- @Author: fangcheng
-- @URL: github.com/tkzcfc
-- @Date:   2020-04-05 17:13:59
-- @Last Modified by:   fangcheng
-- @Last Modified time: 2020-04-12 11:21:39
-- @Description: 

local function onGUI()
	_MyG.LeftDocumentManager:onGUI()
end


_MyG.edContext:registerLuaHandle("onGUI_Left", onGUI)


local content

content = require("app.document.ProjContent").new("asset", _MyG.ProjectAssetManager)
_MyG.LeftDocumentManager:addDocument(content)

content = require("app.document.CocosContent").new("cocos", _MyG.CocosAssetManager)
_MyG.LeftDocumentManager:addDocument(content)

content = require("app.document.WidgetContent").new()
_MyG.LeftDocumentManager:addDocument(content)