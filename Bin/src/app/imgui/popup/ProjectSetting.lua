-- @Author : fc
-- @Date   : 2021-10-21 15:04:16
-- @remark : 项目设置弹窗


local ProjectSetting = class("ProjectSetting", require("app.imgui.Popup"))

function ProjectSetting:ctor(name)
    ProjectSetting.super.ctor(self, name)
    
    self:setWindowFlag(ImGuiWindowFlags_AlwaysAutoResize)

    
    self.edConfig = clone(_MyG.EditorProject.config)
end

-- @override
function ProjectSetting:iOnGUI()
    local edConfig = self.edConfig

    -- 设置发布路径
    edConfig.publishDir = edConfig.publishDir or ""
    ImGui.Text(STR("PUBLISH_DIR"))
    ImGui.SameLine()

    ImGui.PushItemWidth(280)
    local _, newText = Tools:imgui_inputText("##publish_dir", edConfig.publishDir, 512, 0)
    edConfig.publishDir = Tools:replaceString(newText, "\\", "/")
    ImGui.PopItemWidth()

    -- 设置游戏资源目录
    edConfig.gameResDir = edConfig.gameResDir or ""
    ImGui.Text(STR("GAME_RES_DIR"))
    ImGui.SameLine()

    ImGui.PushItemWidth(280)
    _, newText = Tools:imgui_inputText("##game_res", edConfig.gameResDir, 512, 0)
    edConfig.gameResDir = Tools:replaceString(newText, "\\", "/")
    ImGui.PopItemWidth()

    -- 设置发布时是否拷贝资源文件
    local ok, value = ImGui.Checkbox(STR("PUBLISH_COPY_RES"), edConfig.isPublishResource)
    if ok then
        edConfig.isPublishResource = value
    end

    ImGui.Separator()
    if ImGui.Button(STR("Save")) then
        self.edConfig.gameResDir = G_Helper.fmtDirPath(self.edConfig.gameResDir)

        _MyG.EditorProject.config = self.edConfig
        _MyG.EditorProject:save()
        self:close()
        G_SysEventEmitter:emit(SysEvent.SET_GAME_RES_DIR, self.edConfig.gameResDir)
    end
end

return ProjectSetting
