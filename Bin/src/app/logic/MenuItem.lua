local FileDialog = require("app.imgui.FileDialog")


local function createDilog(usage, path, callback)
    local dilog = FileDialog.new(STR("Open"), path, usage)

    local handle = G_SysEventEmitter:on(SysEvent.ON_GUI, function()
        dilog:onGUI()
    end, SysEvent.TAG)

    local okCall = function(value)
        G_SysEventEmitter:off(handle)
        if callback then
            callback(value)
        end
    end
    local cancelCall = function()
        G_SysEventEmitter:off(handle)
    end

    if _MyG.EditorProject:isValid() then
        dilog:setPathConstraint(_MyG.EditorProject.projectDirPath)
    else
        dilog:setPathConstraint(path)
    end
    
    dilog:open(okCall, cancelCall)

    return dilog
end


G_SysEventEmitter:on(SysEvent.ON_MENU_FILE_NEW_PROJECT, function(path)
    local newFolderName = ""
    local enter_true, drawfunc, handle

    local createFunc = function(name)
        if name == nil or name == "" then
            return
        end
        _MyG.Functions:createProject(name)
    end

    drawfunc = function()
        ImGui.OpenPopup("##NewProject")
        if ImGui.BeginPopupModal("##NewProject", true, Tools:bor_int32(ImGuiWindowFlags_AlwaysAutoResize, ImGuiWindowFlags_NoMove)) then
            enter_true, newFolderName = Tools:imgui_inputText("ProjectName", newFolderName, 32, ImGuiInputTextFlags_EnterReturnsTrue)
            if enter_true then
                ImGui.CloseCurrentPopup()
                G_SysEventEmitter:off(handle)
                createFunc(newFolderName)
            end
            ImGui.Separator()
            if ImGui.Button("OK", cc.p(-1, 0)) then
                ImGui.CloseCurrentPopup()
                G_SysEventEmitter:off(handle)
                createFunc(newFolderName)
            end
            ImGui.EndPopup()
        else
            G_SysEventEmitter:off(handle)
        end
    end

    handle = G_SysEventEmitter:on(SysEvent.ON_GUI, drawfunc, SysEvent.TAG)
end, SysEvent.TAG)

G_SysEventEmitter:on(SysEvent.ON_MENU_FILE_NEW_FOLDER, function(rootpath)
    _MyG.Functions:createFolder(rootpath, function(status)
        if status == 0 then
            local rootAsset = _MyG.ProjectAssetManager.rootAsset
            if rootAsset == nil then
                return
            end
            rootAsset:refreshSameLevel()
        end
    end)
end, SysEvent.TAG)

G_SysEventEmitter:on(SysEvent.ON_MENU_FILE_SAVE, function()
    G_SysEventEmitter:emit(SysEvent.CONTENT_ON_EDITOR_CONTENT_SAVE)
end, SysEvent.TAG)

G_SysEventEmitter:on(SysEvent.ON_MENU_FILE_SAVEALL, function()
    local documents = _MyG.CenterDocumentManager:getDocuments()
    for k,document in pairs(documents) do
        document:save()
    end
end, SysEvent.TAG)

G_SysEventEmitter:on(SysEvent.ON_MENU_FILE_OPEN_PROJECT, function(path)
    if path == nil then
        local dilog = createDilog(FileDialog.FileDialogUsage_OpenFile, _MyG.GlobalData.ProjectsPath, function(value)
            if value then
                _MyG.Functions:openProject(value[1].fullPath)
            end
        end)
        dilog:addFilter(_MyG.GlobalData.ProjectExtension)
        dilog:setSelectSingle(true)
    else
        _MyG.Functions:openProject(path)
    end
end, SysEvent.TAG)


G_SysEventEmitter:on(SysEvent.ON_MENU_PROJECT_PROJECT_SETTINGS, function()
    _MyG.PopupManager:addPopup(require("app.imgui.popup.ProjectSetting").new())
end, SysEvent.TAG)
