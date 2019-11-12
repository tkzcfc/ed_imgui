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

    if string.find(path, _MyG.GlobalData.CommonResourcePath) then
        dilog:setPathConstraint(_MyG.GlobalData.CommonResourcePath)
    else
        if _MyG.ProjectData:isValid() then
            dilog:setPathConstraint(_MyG.ProjectData.projectDirPath)
        else
            dilog:setPathConstraint(path)
        end
    end

    
    dilog:open(okCall, cancelCall)

    return dilog
end




G_SysEventEmitter:on("Menu/File/New/Map", function(path)
    local dilog = createDilog(FileDialog.FileDialogUsage_SaveFile, path, function(value)
        _MyG.Functions:createMap(value[1].fullPath)
    end)
    dilog:addFilter(_MyG.GlobalData:getFileTypeInfo("MAP").extension)
    dilog:setCanOverlap(false)
end)

G_SysEventEmitter:on("Menu/File/New/Widget", function(path)
    local dilog = createDilog(FileDialog.FileDialogUsage_SaveFile, path, function(value)
        _MyG.Functions:createWidget(value[1].fullPath)
    end)
    dilog:addFilter(_MyG.GlobalData:getFileTypeInfo("WIDGET").extension)
    dilog:setCanOverlap(false)
end)

G_SysEventEmitter:on("Menu/File/New/Layer", function(path)
    local dilog = createDilog(FileDialog.FileDialogUsage_SaveFile, path, function(value)
        _MyG.Functions:createLayer(value[1].fullPath)
    end)
    dilog:addFilter(_MyG.GlobalData:getFileTypeInfo("LAYER").extension)
    dilog:setCanOverlap(false)
end)


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
    local newFolderName = ""
    local enter_true, drawfunc

    local createFunc = function(name)
        if name == nil or name == "" then
            return
        end
        _MyG.Functions:createFolder(rootpath, name)
    end

    drawfunc = function()
        ImGui.OpenPopup("##NewFolder")
        if ImGui.BeginPopupModal("##NewFolder", true, Tools:bor_int32(ImGuiWindowFlags_AlwaysAutoResize, ImGuiWindowFlags_NoMove)) then
            enter_true, newFolderName = Tools:imgui_inputText("Name", newFolderName, 32, ImGuiInputTextFlags_EnterReturnsTrue)
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

G_SysEventEmitter:on("Menu/File/Save", function()
    G_SysEventEmitter:emit("onEditorContentSave")
end)

G_SysEventEmitter:on("Menu/File/Open/Project", function(path)
    if path == nil then
        local dilog = createDilog(FileDialog.FileDialogUsage_OpenFile, _MyG.GlobalData.ProjectsPath, function(value)
            if value then
                _MyG.Functions:changeToProject(value[1].fullPath)
            end
        end)
        dilog:addFilter(_MyG.GlobalData:getFileTypeInfo("PROJECT").extension)
        dilog:setSelectSingle(true)
    else
        _MyG.Functions:changeToProject(path)
    end
end)

G_SysEventEmitter:on("Menu/File/Open/Map", function(path)
    local dilog = createDilog(FileDialog.FileDialogUsage_OpenFile, path, function(value)
        _MyG.Functions:openMap(value[1].fullPath)
    end)
    dilog:setSelectSingle(true)
    dilog:addFilter(_MyG.GlobalData:getFileTypeInfo("MAP").extension)
end)

G_SysEventEmitter:on("Menu/File/Open/Widget", function(path)
    local dilog = createDilog(FileDialog.FileDialogUsage_OpenFile, path, function(value)
        _MyG.Functions:openWidget(value[1].fullPath)
    end)
    dilog:setSelectSingle(true)
    dilog:addFilter(_MyG.GlobalData:getFileTypeInfo("WIDGET").extension)
end)












G_SysEventEmitter:on("onOpenAssetItem", function(resPath, resType)
    local ext = G_Helper.getExtension(resPath)
    if ext == _MyG.GlobalData:getFileTypeInfo("MAP").extension then
        _MyG.Functions:openMap(resPath)
    elseif ext == _MyG.GlobalData:getFileTypeInfo("WIDGET").extension then
        _MyG.Functions:openWidget(resPath)
    elseif ext == _MyG.GlobalData:getFileTypeInfo("LAYER").extension then
        _MyG.Functions:openLayer(resPath)
    -- elseif ext == "png" then
    --     _MyG.Functions:openImage(resPath)
    end
end)










