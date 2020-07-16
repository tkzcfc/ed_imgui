local FileDialog = require("app.imgui.FileDialog")


local function createDilog(usage, path, callback)
    local dilog = FileDialog.new(STR("Open"), path, usage)

    local drawfunc = function()
        dilog:onGUI()
    end
    G_SysEventEmitter:on("onGUI", drawfunc)

    local okCall = function(value)
        G_SysEventEmitter:removeListener("onGUI", drawfunc)
        if callback then
            callback(value)
        end
    end
    local cancelCall = function()
        G_SysEventEmitter:removeListener("onGUI", drawfunc)
    end

    if _MyG.EditorProject:isValid() then
        dilog:setPathConstraint(_MyG.EditorProject.projectDirPath)
    else
        dilog:setPathConstraint(path)
    end
    
    dilog:open(okCall, cancelCall)

    return dilog
end


G_SysEventEmitter:on("Menu/File/New/Project", function(path)
    local newFolderName = ""
    local enter_true, drawfunc

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
                G_SysEventEmitter:removeListener("onGUI", drawfunc)
                createFunc(newFolderName)
            end
            ImGui.Separator()
            if ImGui.Button("OK", cc.p(-1, 0)) then
                ImGui.CloseCurrentPopup()
                G_SysEventEmitter:removeListener("onGUI", drawfunc)
                createFunc(newFolderName)
            end
            ImGui.EndPopup()
        else
            G_SysEventEmitter:removeListener("onGUI", drawfunc)
        end
    end

    G_SysEventEmitter:on("onGUI", drawfunc)
end)

G_SysEventEmitter:on("Menu/File/New/Folder", function(rootpath)
    _MyG.Functions:createFolder(rootpath, function(status)
        if status == 0 then
            local rootAsset = _MyG.ProjectAssetManager.rootAsset
            if rootAsset == nil then
                return
            end
            rootAsset:refreshSameLevel()
        end
    end)
end)

G_SysEventEmitter:on("Menu/File/Save", function()
    G_SysEventEmitter:emit("onEditorContentSave")
end)

G_SysEventEmitter:on("Menu/File/SaveAll", function()
    local documents = _MyG.CenterDocumentManager:getDocuments()
    for k,document in pairs(documents) do
        document:save()
    end
end)

G_SysEventEmitter:on("Menu/File/Open/Project", function(path)
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
end)












local settingsDilogShow = true
local function proSettingDilog()
    if ImGui.OpenPopup(STR("Project settings")) then
        ImGui.EndPopup()
    end

    

    local visible, enter_true
    visible, settingsDilogShow = ImGui.BeginPopupModal(STR("Project settings"), settingsDilogShow, ImGuiWindowFlags_AlwaysAutoResize)
    if visible then
        local edConfig = _MyG.EditorProject.config
        edConfig.publishDir = edConfig.publishDir or ""


        ImGui.Text(STR("PUBLISH_DIR"))
        ImGui.SameLine()

        ImGui.PushItemWidth(280)
        enter_true, edConfig.publishDir = Tools:imgui_inputText("", edConfig.publishDir, 512, ImGuiInputTextFlags_EnterReturnsTrue)
        ImGui.PopItemWidth()

        -- ImGui.SameLine()
        -- if ImGui.Button(STR("SELECT")) then
        -- end

        ImGui.Separator()
        if ImGui.Button(STR("Save")) then
            _MyG.EditorProject:save()
            ImGui.CloseCurrentPopup()
            settingsDilogShow = false
        end

        ImGui.EndPopup()
    end


    if not settingsDilogShow then
        G_SysEventEmitter:removeListener("onGUI", proSettingDilog)
    end
end

G_SysEventEmitter:on("Menu/Project/Project settings", function(path)
    settingsDilogShow = true
    ImGui.OpenPopup(STR("Project settings"))
    G_SysEventEmitter:on("onGUI", proSettingDilog)
end)
