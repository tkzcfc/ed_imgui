-- @Author : fc
-- @Date   : 2021-9-28 15:42:41
-- @remark : 角色编辑-编辑技能信息

-- 红色
local COLOR_RED = {x = 1.0, y = 0, z = 0, w = 1.0}

local RoleEditSkill = class("RoleEditSkill", require("app.imgui.Popup"))

function RoleEditSkill:ctor(name)
    RoleEditSkill.super.ctor(self, name)
    
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
function RoleEditSkill:iOnGUI()
    ---------------------------------------------------------------------- action id ----------------------------------------------------------------------
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

    ---------------------------------------------------------------------- add action ----------------------------------------------------------------------
    if ImGui.Button("+") then
        ImGui.OpenPopup("add_act_to_skill");
    end

    if ImGui.BeginPopup("add_act_to_skill") then
        for k, v in pairs(self.actInfo) do
            if ImGui.MenuItem(v.name) then
                table.insert(self.acts, {
                    info = v,
                    loopCount = 1,
                })
            end
        end
        ImGui.EndPopup()
    end
    
	ImGui.BeginChild("acts", cc.p(0, 150), true, 0)
        for k, v in pairs(self.acts) do
            if v.info.invalid then
                ImGui.PushStyleColor(ImGuiCol_Text, COLOR_RED)
            end

            ImGui.Selectable(v.info.name, false)

            if v.info.invalid then
                ImGui.PopStyleColor()
            end

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

function RoleEditSkill:setShowData(roleInfo, curSkillData, callback)
    self.curSkillData = curSkillData
    self.skillInfo = roleInfo.skillInfo
    self.actInfo = roleInfo.actInfo

    self.onConformCallback = callback

    self.curId = curSkillData.id
    self.curText = curSkillData.name
    self.loopCount = curSkillData.loopCount
    self.loopActionIndex = curSkillData.loopActionIndex
    self.nextSkillId = curSkillData.nextSkillId
    
    self.acts = {}

    for k, v in pairs(curSkillData.arrActInfo or {}) do
        local find = false
        for _, info in pairs(self.actInfo) do
            if v.id == info.id then
                table.insert(self.acts, {
                    info = info,
                    loopCount = v.loopCount
                })
                find = true
            end
        end

        if not find then
            table.insert(self.acts, {
                info = {
                    name = string.format("invalid action(id:%d)", id),
                    invalid = true
                },
                loopCount = v.loopCount
            })
        end
    end  
end

-- @brief id重复检测
function RoleEditSkill:isIdRepeat(id)
    if self.curSkillData.id == id then return false end

    for k, v in pairs(self.skillInfo) do
        if v.id == self.curId then
            return true
        end
    end

    return false
end

-- @brief 名称重复检测
function RoleEditSkill:isNameRepeat(name)
    if self.curSkillData.name == name then return false end
    
    for k, v in pairs(self.skillInfo) do
        if v.name == name then
            return true
        end
    end

    return false
end

function RoleEditSkill:dispatchEvent()

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

    for k, v in pairs(self.acts) do
        if v.info.invalid then
            _MyG.ShowTipBox(STR("SkillContainInvalidAction"))
            break
        end
    end
    
    self:close()

    local arrActInfo = {}
    for k, v in pairs(self.acts) do
        table.insert(arrActInfo, {
            id = v.info.id,
            loopCount = v.loopCount
        })
    end

    if self.onConformCallback then
        self.onConformCallback(self.curText, self.curId, arrActInfo)
    end
end

return RoleEditSkill
