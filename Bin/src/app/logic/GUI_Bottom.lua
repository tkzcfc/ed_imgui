-- @Author: fangcheng
-- @Date:   2020-04-05 17:13:52
-- @Description: 

local BottomDocMger = _MyG.BottomDocumentManager

local function onGUI()
	BottomDocMger:onGUI()
end

_MyG.edContext:registerLuaHandle("onGUI_Bottom", onGUI)


-- logger
local log = require("app.document.Log").new()
BottomDocMger:addDocument(log)

-- node
local node = require("app.document.NodeContent").new()
BottomDocMger:addDocument(node)
_MyG.MainScene.NodeContent = node

-- time line
BottomDocMger:addDocument(require("app.document.Timeline").new())

G_SysEventEmitter:on(SysEvent.ON_SHOW_BOTTOM_DOCUMENT, function(docName)
	BottomDocMger:setCurShowDocumentByName(docName)
end, SysEvent.TAG)
