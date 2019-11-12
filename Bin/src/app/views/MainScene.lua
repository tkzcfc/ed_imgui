
local MainWindow = require("app.window.MainWindow")

local MainScene = class("MainScene", cc.load("mvc").ViewBase)

function MainScene:onCreate()
    _MyG.MainScene = self
    self:initImGUI()
end

function MainScene:onEnter()
    self:initWindow()
    self:initBGGrid()

    require("app.logic.Menu")
    require("app.logic.MenuItem")
end

function MainScene:initImGUI()
    local ilayer = ILayer:create()
    ilayer:registerLuaHandle("onInit", function()

        if _MyG.UseSystemChineseFont then
            if ilayer:setSystemChineseFont(_MyG.ChineseFont, _MyG.ChineseFontSize) then
                _MyG.SupportChineseFont = true
            else
                _MyG.SupportChineseFont = false
            end
        else
            if ilayer:setChineseFont(_MyG.ChineseFont, _MyG.ChineseFontSize) then
                _MyG.SupportChineseFont = true
            else
                _MyG.SupportChineseFont = false
            end
        end

        local loadChineseFont = false
        if G_LangManager:isFirstStart() then
            loadChineseFont = true
        else
            if G_LangManager:getLang() == G_LangManager.LANGUAGE.CH then
                loadChineseFont = true
            end
        end

        if loadChineseFont and _MyG.SupportChineseFont then
            G_LangManager:setLang(G_LangManager.LANGUAGE.CH)
        else
            G_LangManager:setLang(G_LangManager.LANGUAGE.EN)
        end
    end)
    ilayer:registerLuaHandle("onGUI", function()
        G_SysEventEmitter:emit("onGUI")
    end)
    self:addChild(ilayer, 0xffffff)
    self.ilayer = ilayer
end

function MainScene:initWindow()
    self.mainWindow = MainWindow.new()

    local content

    content = require("app.document.AssetContent").new("content")
    _MyG.LeftDocumentManager:addDocument(content)

    content = require("app.document.CommonContent").new("common")
    _MyG.LeftDocumentManager:addDocument(content)

    content = require("app.document.CocosContent").new("cocos")
    _MyG.LeftDocumentManager:addDocument(content)

    content = require("app.document.WidgetContent").new()
    _MyG.LeftDocumentManager:addDocument(content)


    local log = require("app.document.Log").new()
    _MyG.BottomDocumentManager:addDocument(log)

    local node = require("app.document.NodeContent").new()
    _MyG.BottomDocumentManager:addDocument(node)
    self.NodeContent = node    

    local attribute = require("app.document.AttributeContent").new()
    _MyG.RightDocumentManager:addDocument(attribute)
end

function MainScene:initBGGrid()
    local style = ImGui.GetStyle()
    local visibleSize = cc.Director:getInstance():getVisibleSize()

    local imgui_w = G_Helper.win_2_visible_x(MainWindow.getImguiWindowTotalWidth())
    local imgui_h = G_Helper.win_2_visible_y(MainWindow.getImguiWindowTotalHeight())

    local padding = G_Helper.win_2_visible_y(style.FramePadding.y + style.WindowPadding.y + style.ChildBorderSize * 3 + MainWindow.topWindow_h)

    local bgSize = {}
    bgSize.width = visibleSize.width - imgui_w
    bgSize.height = visibleSize.height - imgui_h

    self.Panel_BG = ccui.Layout:create()
    self.Panel_BG:ignoreContentAdaptWithSize(false)
    self.Panel_BG:setClippingEnabled(true)
    self.Panel_BG:setContentSize(bgSize)
    self.Panel_BG:setAnchorPoint(0.5000, 1.0)
    self.Panel_BG:setPosition(visibleSize.width * 0.5, visibleSize.height - padding)
    self:addChild(self.Panel_BG)

    local gridNode = cc.Node:create()
    self.Panel_BG:addChild(gridNode, -1)

    local gridtemplate = cc.Sprite:create("Res/grid.png")
    local size = gridtemplate:getContentSize()

    local panelSize = bgSize
    size.width = size.width * 5
    size.height = size.height * 5

    local count = 0
    for i=0,panelSize.height / size.height do
        for j = 0, panelSize.width / size.width do
            count = count + 1
            local grid = cc.Sprite:create("Res/grid.png")
            grid:setPosition(j * size.width, i * size.height)
            grid:setScale(5)
            gridNode:addChild(grid)
        end
    end
end

return MainScene
