local FileDialog = require("app.imgui.FileDialog")


-- imgui demo
local isShowImguiDemo = false
G_SysEventEmitter:on("onGUI", function()
    if isShowImguiDemo then
        isShowImguiDemo = ImGui.ShowDemoWindow(isShowImguiDemo)
    end
end)

local function showMainMenuBar()
    if ImGui.BeginMenu(STR("File")) then
		if ImGui.BeginMenu(STR("New")) then
            G_SysEventEmitter:emit("onGUI_MainMenuBar_File_New")
            ImGui.EndMenu()
        end

        if ImGui.BeginMenu(STR("Open")) then
            G_SysEventEmitter:emit("onGUI_MainMenuBar_File_Open")
            ImGui.EndMenu()
        end

        if ImGui.MenuItem(STR("Save")) then
            G_SysEventEmitter:emit("Menu/File/Save")
        end

        if ImGui.MenuItem(STR("SaveAll")) then
            G_SysEventEmitter:emit("Menu/File/SaveAll")
        end
        G_SysEventEmitter:emit("onGUI_MainMenuBar_File")
        ImGui.EndMenu()
    end

    if ImGui.BeginMenu(STR("Tool")) then
        if ImGui.MenuItem("ImguiDemo", "", isShowImguiDemo, true) then
            isShowImguiDemo = not isShowImguiDemo
        end
        if ImGui.MenuItem(STR("Publish")) then
            _MyG.Functions:publishResource()
        end
        G_SysEventEmitter:emit("onGUI_MainMenuBar_Tool")
        ImGui.EndMenu()
    end

    if ImGui.BeginMenu(STR("Project")) then
        G_SysEventEmitter:emit("onGUI_MainMenuBar_Project")
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
                end
            end
        end

        ImGui.EndMenu()
    end
end
G_SysEventEmitter:on("onGUI_MainMenuBar", showMainMenuBar)



G_SysEventEmitter:on("onGUI_MainMenuBar_File_Open", function()
    if ImGui.BeginMenu(STR("Project")) then
        if ImGui.MenuItem(STR("Other")) then
            G_SysEventEmitter:emit("Menu/File/Open/Project")
        end
        
        local nameArr = _MyG.GlobalData.ProjectNameArr
        for k, v in pairs(nameArr) do
            if ImGui.MenuItem(v) then
                G_SysEventEmitter:emit("Menu/File/Open/Project", _MyG.GlobalData.ProjectsPath .. "/" .. v)
            end
        end
        ImGui.EndMenu()
    end
end)

G_SysEventEmitter:on("onGUI_MainMenuBar_File_New", function()
    if ImGui.MenuItem(STR("Project")) then
        G_SysEventEmitter:emit("Menu/File/New/Project", _MyG.GlobalData.ProjectsDirName)
    end
end)


G_SysEventEmitter:on("onGUI_MainMenuBar_Project", function()
    if ImGui.MenuItem(STR("Project settings"), "", false, _MyG.EditorProject:isValid()) then
        G_SysEventEmitter:emit("Menu/Project/Project settings")
    end
end)
