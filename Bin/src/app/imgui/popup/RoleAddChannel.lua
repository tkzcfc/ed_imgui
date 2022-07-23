-- @Author : fc
-- @Date   : 2021-9-8 18:00:32
-- @remark : 角色编辑-技能-添加新的转换通道


local RoleAddChannel = class("RoleAddChannel", require("app.imgui.Popup"))

local checkTypeOptions = enum_options("GChannelCheckType")
local interruptTypeOptions = enum_options("GInterruptType")

G_SysEventEmitter:on(SysEvent.ON_CHANGE_LANG, function()
    checkTypeOptions = enum_options("GChannelCheckType")
    interruptTypeOptions = enum_options("GInterruptType")
end, SysEvent.TAG)


function RoleAddChannel:ctor(name)
    RoleAddChannel.super.ctor(self, name)
    
    self:setWindowFlag(ImGuiWindowFlags_AlwaysAutoResize)
    -- 名称
    self.curText = ""
    
    self.nextSkillId = -1
    self.nextSkillIndex = 1

    self.checkType = GChannelCheckType.Continuous
    self.interruptType = GInterruptType.PROMPTLY
end

-- @override
function RoleAddChannel:iOnGUI()
    ---------------------------------------------------------------------- name ----------------------------------------------------------------------
    -- name
    local enter_true, inputName = Tools:imgui_inputText(STR("Name"), self.curText, 128, ImGuiInputTextFlags_EnterReturnsTrue)
    self.curText = inputName
    
    if self:isNameRepeat(inputName) then
        ImGui.TextDisabled(string.format("(%s)", STR("ChannelNameRepeat")))
    end

    ---------------------------------------------------------------------- next skill ----------------------------------------------------------------------
    local newIndex = Tools:imguiCombo_OneLiner(STR("NextSkill"), self.nextSkillIndex - 1, self.skillOptions)
    self.nextSkillIndex = newIndex + 1
    local selectSkill = self.canSelectSkills[self.nextSkillIndex]
    if selectSkill then
        self.nextSkillId = selectSkill.id
    else
        self.nextSkillId = -1            
    end

    ---------------------------------------------------------------------- 通道检测类型 ----------------------------------------------------------------------
    self.checkType = Tools:imguiCombo_OneLiner(STR("GChannelCheckType"), self.checkType, checkTypeOptions)
    
    ---------------------------------------------------------------------- 通道检测类型 ----------------------------------------------------------------------
    self.interruptType = Tools:imguiCombo_OneLiner(STR("GInterruptType"), self.interruptType, interruptTypeOptions)

    if ImGui.Button("OK", cc.p(-1, 0)) then
        self:dispatchEvent()
    end
end

function RoleAddChannel:setShowData(roleInfo, curSkillIndex, callback)
    self.skillInfo = roleInfo.skillInfo
    self.curSkill = self.skillInfo[curSkillIndex]

    -- 筛选可以选择的技能类型
    local canSelectSkills = {}
    for k, v in pairs(self.skillInfo) do
        -- if self.curSkill ~= v then
            table.insert(canSelectSkills, v)
        -- end
    end

    self.canSelectSkills = canSelectSkills

    -- 技能选项
    if #canSelectSkills <= 0 then
        self.skillOptions = "<-NONE->\0\0"
    else
        self.skillOptions = ""
        for k, v in pairs(canSelectSkills) do
            self.skillOptions = self.skillOptions .. v.name .. "\0"
        end
        self.skillOptions = self.skillOptions .. "\0\0"
    end

    self.onConformCallback = callback
end

function RoleAddChannel:isNameRepeat(name)
    for k, v in pairs(self.curSkill.channels) do
        if v.name == name then return true end
    end
    return false
end

function RoleAddChannel:dispatchEvent()

    if self.curText == "" then
        _MyG.ShowTipBox(STR("ChannelNameCanNotEmpty"))
        return
    end

    -- 名称重复检测
    if self:isNameRepeat(self.curText) then
        _MyG.ShowTipBox(STR("ChannelNameRepeat"))
        return
    end

    if self.nextSkillIndex == -1 then
        -- 下一个技能不存在
        _MyG.ShowTipBox(STR("ChannelNextSkillNoExist"))
        return        
    end
    
    self:close()

    if self.onConformCallback then    
        local channel = {}
        channel.name = self.curText
        channel.nextSkillId = self.nextSkillId
        channel.conditions = {}
        channel.checkType = self.checkType
        channel.interruptType = self.interruptType
        self.onConformCallback(channel)
    end
end

return RoleAddChannel