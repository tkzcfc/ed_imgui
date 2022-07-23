-- @Author : fc
-- @Date   : 2021-9-28 14:41:24
-- @remark : 角色编辑-添加新的技能


local RoleAddSkill = class("RoleAddSkill", require("app.imgui.Popup"))

function RoleAddSkill:ctor(name)
    RoleAddSkill.super.ctor(self, name)
    
    -- self:setWindowFlag(Tools:bor_int32(ImGuiWindowFlags_AlwaysAutoResize, ImGuiWindowFlags_NoMove))
    self:setWindowFlag(ImGuiWindowFlags_AlwaysAutoResize)
    -- 名称
    self.curText = ""
    -- 技能id
    self.curId = 0

    self.acts = {}
    
    self.loopCount = 1
    self.loopActionIndex = 1
    self.nextSkillId = -1
end

-- @override
function RoleAddSkill:iOnGUI()
    ---------------------------------------------------------------------- action id ----------------------------------------------------------------------
    -- action id
    local ok, id = ImGui.InputInt("id", self.curId)
    if ok then
        self.curId = id
    end
    
    -- id 不能为负数
    if self.curId < 0 then
        ImGui.TextDisabled(string.format("(%s)", STR("SkillCanNotBeNeg")))
    end

    if self:isIdRepeat(self.curId) then
        ImGui.TextDisabled(string.format("(%s)", STR("SkillIdRepeat")))
    end

    ---------------------------------------------------------------------- name ----------------------------------------------------------------------
    -- name
    local enter_true, inputName = Tools:imgui_inputText(STR("Name"), self.curText, 32, ImGuiInputTextFlags_EnterReturnsTrue)
    self.curText = inputName
    
    if self:isNameRepeat(inputName) then
        ImGui.TextDisabled(string.format("(%s)", STR("SkillNameRepeat")))
    end

    
    ---------------------------------------------------------------------- loop count ----------------------------------------------------------------------
    local ok, count = ImGui.InputInt("loop", self.loopCount)
    if ok then
        self.loopCount = count
    end

    ---------------------------------------------------------------------- loop with action index ----------------------------------------------------------------------
    local actCount = #self.acts
    if self.loopActionIndex == 0 then
        if actCount > 0 then
            self.loopActionIndex = 1
        end
    end
    if self.loopActionIndex > actCount then
        self.loopActionIndex = actCount
    end

    -- if self.loopCount ~= 1 then
    --     if actCount > 0 then

    --         local options = ""
    --         for k, v in pairs(self.acts) do
    --             options = options .. v.name .. "\0"
    --         end
    --         options = options .. "\0\0"
    --         local index = self.loopActionIndex - 1
    --         local newIndex = Tools:imguiCombo_OneLiner("cycle action", index, options)
    --         self.loopActionIndex = newIndex + 1
    --     end
    -- end
    ---------------------------------------------------------------------- next skill ----------------------------------------------------------------------
    -- local canSelectSkills = {}
    -- for k, v in pairs(self.skillInfo) do
    --     if self.curSkillData ~= v then
    --         table.insert(canSelectSkills, v)
    --     end
    -- end

    -- if #canSelectSkills > 0 then
    --     local index = 1
    --     local options = "<-NONE->\0"
    --     for k, v in pairs(canSelectSkills) do
    --         options = options .. v.name .. "\0"
    --         if v.id == self.nextSkillId then
    --             index = k + 1
    --         end
    --     end
    --     options = options .. "\0\0"
        
    --     local newIndex = Tools:imguiCombo_OneLiner(STR("NextSkill"), index - 1, options)
    --     local selectSkill = canSelectSkills[newIndex]
    --     if selectSkill then
    --         self.nextSkillId = selectSkill.id
    --     else
    --         self.nextSkillId = -1            
    --     end
    -- else
    --     self.nextSkillId = -1
    -- end
    
    ---------------------------------------------------------------------- add action ----------------------------------------------------------------------
    if ImGui.Button("+") then
        ImGui.OpenPopup("add_act_to_skill");
    end

    if ImGui.BeginPopup("add_act_to_skill") then
        for k, v in pairs(self.actInfo) do
            if ImGui.MenuItem(v.name) then
                table.insert(self.acts, v)
            end
        end
        ImGui.EndPopup()
    end
    
	ImGui.BeginChild("acts", cc.p(0, 150), true, 0)
        for k, v in pairs(self.acts) do
            ImGui.Selectable(v.name, false)
            -- 点击右键,弹出选项
            if ImGui.IsMouseReleased(1) and ImGui.IsItemHovered(ImGuiHoveredFlags_AllowWhenBlockedByPopup) then
                ImGui.OpenPopup("role_edit_skill_menu")
                self.curMenuItemIndex = k
            end
        end

        if ImGui.BeginPopup("role_edit_skill_menu") then
            if self.curMenuItemIndex > 1 then
                if ImGui.MenuItem(STR("MoveActUp")) then
                    local cur = self.acts[self.curMenuItemIndex]
                    self.acts[self.curMenuItemIndex] = self.acts[self.curMenuItemIndex - 1]
                    self.acts[self.curMenuItemIndex - 1] = cur
                end
            end

            if self.curMenuItemIndex < #self.acts then
                if ImGui.MenuItem(STR("MoveActDown")) then
                    local cur = self.acts[self.curMenuItemIndex]
                    self.acts[self.curMenuItemIndex] = self.acts[self.curMenuItemIndex + 1]
                    self.acts[self.curMenuItemIndex + 1] = cur
                end
            end
            if ImGui.MenuItem(STR("Delete")) then
                table.remove(self.acts, self.curMenuItemIndex)
            end
            ImGui.EndPopup()
        end
    ImGui.EndChild()

    if ImGui.Button("OK", cc.p(-1, 0)) then
        self:dispatchEvent()
    end
end

function RoleAddSkill:setShowData(roleInfo, callback)
    self.skillInfo = roleInfo.skillInfo
    self.actInfo = roleInfo.actInfo

    self.onConformCallback = callback

    self.curId = 0
    repeat
        if not self:isIdRepeat(self.curId) then
            break
        end
        self.curId = self.curId + 1
    until(false)
end

-- @brief id重复检测
function RoleAddSkill:isIdRepeat(id)
    for k, v in pairs(self.skillInfo) do
        if v.id == self.curId then
            return true
        end
    end

    return false
end

-- @brief 名称重复检测
function RoleAddSkill:isNameRepeat(name)
    for k, v in pairs(self.skillInfo) do
        if v.name == name then
            return true
        end
    end

    return false
end

function RoleAddSkill:dispatchEvent()

    if self.curText == "" then
        _MyG.ShowTipBox(STR("ActNameCanNotEmpty"))
        return
    end

    -- 动作名称重复检测
    if self:isNameRepeat(self.curText) then
        -- 动作名已存在
        _MyG.ShowTipBox(STR("ActNameRepeat"))
        return
    end

    -- id不能小于0
    if self.curId < 0 then
        _MyG.ShowTipBox(STR("SkillCanNotBeNeg"))
        return
    end

    -- Id重复检测
    if self:isIdRepeat(self.curId) then
        -- id已存在
        _MyG.ShowTipBox(STR("ActIdRepeat"))
        return
    end

    -- 动作列表为空检测
    if #self.acts <= 0 then
        _MyG.ShowTipBox(STR("ActListIsEmptyInSkill"))
        return
    end
    
    self:close()

    local arrActInfo = {}
    for k, v in pairs(self.acts) do
        table.insert(arrActInfo, {
            id = v.id,
            loopCount = 1,
        })
    end


    if self.onConformCallback then
    
        local skillInfo = {}
        skillInfo.name = self.curText
        skillInfo.id = self.curId
        skillInfo.arrActInfo = arrActInfo
        skillInfo.tracks = {}
        skillInfo.nextSkillId = self.nextSkillId
        skillInfo.loopCount = self.loopCount
        skillInfo.loopActionIndex = self.loopActionIndex
        skillInfo.tracks = {}
    
        self.onConformCallback(skillInfo)
    end
end

return RoleAddSkill
