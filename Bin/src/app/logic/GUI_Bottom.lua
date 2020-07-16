-- @Author: fangcheng
-- @URL: github.com/tkzcfc
-- @Date:   2020-04-05 17:13:52
-- @Last Modified by:   fangcheng
-- @Last Modified time: 2020-04-05 17:29:44
-- @Description: 

local function onGUI()
	_MyG.BottomDocumentManager:onGUI()
end

_MyG.edContext:registerLuaHandle("onGUI_Bottom", onGUI)



local log = require("app.document.Log").new()
_MyG.BottomDocumentManager:addDocument(log)

local node = require("app.document.NodeContent").new()
_MyG.BottomDocumentManager:addDocument(node)
_MyG.MainScene.NodeContent = node
