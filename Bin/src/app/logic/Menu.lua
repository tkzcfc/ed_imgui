local FileDialog = require("app.imgui.FileDialog")

local function showMainMenuBar()
    if ImGui.BeginMenu(STR("File")) then
		if ImGui.BeginMenu(STR("New")) then
            G_SysEventEmitter:emit(SysEvent.ON_GUI_MAIN_MENUBAR_FILE_NEW)
            ImGui.EndMenu()
        end

        if ImGui.BeginMenu(STR("Open")) then
            G_SysEventEmitter:emit(SysEvent.ON_GUI_MAIN_MENUBAR_FILE_OPEN)
            ImGui.EndMenu()
        end

        if ImGui.MenuItem(STR("Save")) then
            G_SysEventEmitter:emit(SysEvent.ON_MENU_FILE_SAVE)
        end

        if ImGui.MenuItem(STR("SaveAll")) then
            G_SysEventEmitter:emit(SysEvent.ON_MENU_FILE_SAVEALL)
        end
        G_SysEventEmitter:emit(SysEvent.ON_GUI_MAIN_MENUBAR_FILE)
        ImGui.EndMenu()
    end

    if ImGui.BeginMenu(STR("Tool")) then
        if ImGui.MenuItem(STR("Publish")) then
            G_SysEventEmitter:emit(SysEvent.ON_MENU_FILE_SAVEALL)
            _MyG.Functions:publishResource()
        end
        if ImGui.MenuItem(STR("Relaunch")) then
            Tools:relaunch()
        end
        G_SysEventEmitter:emit(SysEvent.ON_GUI_MAIN_MENUBAR_TOOL)
        ImGui.EndMenu()
    end

    if ImGui.BeginMenu(STR("Windows")) then
        for k, win in pairs(_MyG.WindowManager:getWindows()) do
            if ImGui.MenuItem(win:getWinName(), "", win:isWindowVisible(), true) then
                win:setWindowVisible(not win:isWindowVisible())
            end
        end
        ImGui.EndMenu()
    end

    if ImGui.BeginMenu(STR("Project")) then
        G_SysEventEmitter:emit(SysEvent.ON_GUI_MAIN_MENUBAR_PROJECT)
        ImGui.EndMenu()
    end

    if ImGui.BeginMenu(STR("Language")) then
        if not _MyG.SupportChineseFont then
            if ImGui.MenuItem(G_LangManager:getLanguageName(), "", true, true) then
            end
        else
            for k, v in pairs(G_LangManager.LANG_NAME) do
                if ImGui.MenuItem(v, "", G_LangManager:getLanguageName() == v, true) then
                    G_LangManager:setLangByName(v)
                    G_SysEventEmitter:emit(SysEvent.ON_CHANGE_LANG)
                end
            end
        end

        ImGui.EndMenu()
    end

    if ImGui.BeginMenu(STR("settings")) then
        if ImGui.MenuItem(STR("ZoomSettings")) then
            _MyG.WindowManager:showWindow(WinTag.GLOBAL_SCALE, true)
        end
        if ImGui.MenuItem(STR("FontSettings")) then
            _MyG.WindowManager:showWindow(WinTag.FONT_SETTING, true)
        end
        ImGui.EndMenu()
    end

    if ImGui.BeginMenu(STR("Theme")) then
        for k, v in pairs(_MyG.ThemeManager:getNames()) do
            if ImGui.MenuItem(v, "", _MyG.ThemeManager:isSelect(v), true) then
                _MyG.ThemeManager:select(v)
            end
        end
        ImGui.EndMenu()
    end
end
G_SysEventEmitter:on(SysEvent.ON_GUI_MAIN_MENUBAR, showMainMenuBar, SysEvent.TAG)



G_SysEventEmitter:on(SysEvent.ON_GUI_MAIN_MENUBAR_FILE_OPEN, function()
    if ImGui.BeginMenu(STR("Project")) then
        if ImGui.MenuItem(STR("Other")) then
            G_SysEventEmitter:emit(SysEvent.ON_MENU_FILE_OPEN_PROJECT)
        end
        
        local nameArr = _MyG.GlobalData.ProjectNameArr
        for k, v in pairs(nameArr) do
            if ImGui.MenuItem(v) then
                G_SysEventEmitter:emit(SysEvent.ON_MENU_FILE_OPEN_PROJECT, _MyG.GlobalData.ProjectsPath .. "/" .. v)
            end
        end
        ImGui.EndMenu()
    end
end, SysEvent.TAG)

G_SysEventEmitter:on(SysEvent.ON_GUI_MAIN_MENUBAR_FILE_NEW, function()
    if ImGui.MenuItem(STR("Project")) then
        G_SysEventEmitter:emit(SysEvent.ON_MENU_FILE_NEW_PROJECT, _MyG.GlobalData.ProjectsDirName)
    end
end, SysEvent.TAG)


G_SysEventEmitter:on(SysEvent.ON_GUI_MAIN_MENUBAR_PROJECT, function()
    if ImGui.MenuItem(STR("Project settings"), "", false, _MyG.EditorProject:isValid()) then
        G_SysEventEmitter:emit(SysEvent.ON_MENU_PROJECT_PROJECT_SETTINGS)
    end
end, SysEvent.TAG)
