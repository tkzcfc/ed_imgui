-- @Author : fc
-- @Date   : 2021-9-8 18:00:32
-- @remark : 角色编辑-添加新的动作


local RoleAddAction = class("RoleAddAction", require("app.imgui.Popup"))

function RoleAddAction:ctor(name)
    RoleAddAction.super.ctor(self, name)
    
    -- self:setWindowFlag(Tools:bor_int32(ImGuiWindowFlags_AlwaysAutoResize, ImGuiWindowFlags_NoMove))
    self:setWindowFlag(ImGuiWindowFlags_AlwaysAutoResize)
    -- 动作名称
    self.curText = ""
    -- 动画动作下标
    self.curArmatureIndex = -1
    -- 动作id
    self.curId = 0
    -- 循环次数
    self.loopCount = 1
end

-- @override
function RoleAddAction:iOnGUI()
    if self.curArmatureIndex == -1 then
        Tools:imguiCombo_OneLiner("action", 0, "-NONE-")
    else
        local newIndex = Tools:imguiCombo_OneLiner("action", self.curArmatureIndex - 1, self.armatureRender:getPlayNames_imguiCombo())
        self.curArmatureIndex = newIndex + 1
    end

    -- action id
    local ok, id = ImGui.InputInt("id", self.curId)
    if ok then
        self.curId = id
    end
    if self:isActIdRepeat(self.curId) then
        ImGui.TextDisabled(string.format("(%s)", STR("ActIdRepeat")))
    end

    -- action name
    local enter_true, inputName = Tools:imgui_inputText(STR("Name"), self.curText, 32, ImGuiInputTextFlags_EnterReturnsTrue)
    self.curText = inputName
    
    if self:isActNameRepeat(inputName) then
        ImGui.TextDisabled(string.format("(%s)", STR("ActNameRepeat")))
    end
    
    ---------------------------------------------------------------------- loop count ----------------------------------------------------------------------
    local ok, count = ImGui.InputInt("loop", self.loopCount)
    if ok then
        self.loopCount = count
    end

    -- 点击回车
    -- if enter_true then
    --     self:dispatchEvent(self.curText)
    -- end
    ImGui.Separator()

    if ImGui.Button("OK", cc.p(-1, 0)) then
        self:dispatchEvent(self.curText)
    end
end

function RoleAddAction:setShowData(actInfo, armatureRender, callback)
    self.actInfo = actInfo
    self.armatureRender = armatureRender
    self.onConformCallback = callback

    self.curId = 0
    repeat
        if not self:isActIdRepeat(self.curId) then
            break
        end
        self.curId = self.curId + 1
    until(false)

    if #self.armatureRender:getPlayNames() > 0 then
        self.curArmatureIndex = 1
    end
end

-- @brief id重复检测
function RoleAddAction:isActIdRepeat(id)
    for k, v in pairs(self.actInfo) do
        if v.id == self.curId then
            return true
        end
    end

    return false
end

-- @brief 名称重复检测
function RoleAddAction:isActNameRepeat(name)
    for k, v in pairs(self.actInfo) do
        if v.name == name then
            return true
        end
    end

    return false
end

function RoleAddAction:dispatchEvent(name)
    if self.curArmatureIndex == -1 then
        -- 此动画一个动作都没有
        _MyG.ShowTipBox(STR("ArmaturePlayListEmty"))
        return
    end

    if name == "" then
        _MyG.ShowTipBox(STR("ActNameCanNotEmpty"))
        return
    end

    -- 动作名称重复检测
    if self:isActNameRepeat(name) then
        -- 动作名已存在
        _MyG.ShowTipBox(STR("ActNameRepeat"))
        return
    end

    -- Id重复检测
    if self:isActIdRepeat(self.curId) then
        -- id已存在
        _MyG.ShowTipBox(STR("ActIdRepeat"))
        return
    end
    
    self:close()

    if self.onConformCallback then
        local playName = self.armatureRender:getPlayNameByIndex(self.curArmatureIndex)

        local act = {}
        act.name = name
        act.playName = playName
        act.id = self.curId
        act.loopCount = self.loopCount
        act.tracks = {}
        act.min = 0
        act.max = 1
        self.onConformCallback(act)
    end
end

return RoleAddAction
