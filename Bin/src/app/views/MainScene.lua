-- @Author: fangcheng
-- @Date:   2020-04-05 12:48:03
-- @Description: 
local MainScene = class("MainScene", cc.load("mvc").ViewBase)

function MainScene:onCreate()

	local context = EditorContext:create()
	self:addChild(context)

	local ilayer = context:getIlayer()
    ilayer:registerLuaHandle("onGUIBegin", function()
        _MyG.IsOnGUI = true
        G_SysEventEmitter:emit(SysEvent.ON_GUI_BEGIN)
    end)

    ilayer:registerLuaHandle("onGUI", function()
        G_SysEventEmitter:emit(SysEvent.ON_GUI)
    end)

    ilayer:registerLuaHandle("onGUIEnd", function()
        G_SysEventEmitter:emit(SysEvent.ON_GUI_POPUP)
        G_SysEventEmitter:emit(SysEvent.ON_GUI_END)
        _MyG.IsOnGUI = false
    end)

    
    ilayer:registerLuaHandle("onInit", function()
    	self:onGUI_Init()
    end)

    local rootNode = cc.Node:create()
    ilayer:addChild(rootNode, -1)

    _MyG.MainScene = self
	_MyG.edContext = context
	_MyG.MainScene.ilayer = ilayer
	_MyG.MainScene.rootNode = rootNode
end

function MainScene:onGUI_Init()
    _MyG.ThemeManager:readTheme()
    
    local ilayer = self.ilayer

    local DocumentManager = require("app.imgui.DocumentManager")
    _MyG.TopDocumentManager = DocumentManager.new()
    _MyG.LeftDocumentManager = DocumentManager.new()
    _MyG.RightDocumentManager = DocumentManager.new()
    _MyG.BottomDocumentManager = DocumentManager.new()
    _MyG.CenterDocumentManager = DocumentManager.new()

	require("app.logic.GUI_Bottom")
	require("app.logic.GUI_Center")
	require("app.logic.GUI_Left")
	require("app.logic.GUI_Right")
	require("app.logic.GUI_Top")
	require("app.logic.GUI_MenuBar")
	require("app.logic.GUI_Popup")
	require("app.logic.GUI_Window")

    _MyG.SupportChineseFont = false
    for k, v in pairs(_MyG.SupportFonts) do
        if ilayer:setChineseFont(v.fullPath, v.fontSize) then
            _MyG.SupportChineseFont = true
        end
    end

    local loadChineseFont = false
    -- 首次启动默认选中文
    if G_LangManager:isFirstStart() then
        loadChineseFont = true
    else
        if G_LangManager:getLang() == G_LangManager.LANGUAGE.CN then
            loadChineseFont = true
        else
            loadChineseFont = false
        end
    end

    if loadChineseFont and _MyG.SupportChineseFont then
        G_LangManager:setLang(G_LangManager.LANGUAGE.CN)
    else
        G_LangManager:setLang(G_LangManager.LANGUAGE.EN)
    end
end

return MainScene