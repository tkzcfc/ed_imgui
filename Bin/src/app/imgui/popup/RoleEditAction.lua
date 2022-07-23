-- @Author : fc
-- @Date   : 2021-9-13 16:30:30
-- @remark : 角色编辑-编辑动作


local RoleEditAction = class("RoleEditAction", require("app.imgui.Popup"))

function RoleEditAction:ctor(name)
    RoleEditAction.super.ctor(self, name)
    
    -- self:setWindowFlag(Tools:bor_int32(ImGuiWindowFlags_AlwaysAutoResize, ImGuiWindowFlags_NoMove))
    self:setWindowFlag(ImGuiWindowFlags_AlwaysAutoResize)
    -- 动作名称
    self.curText = ""
    -- 动画动作下标
    self.curArmatureIndex = -1
    -- 动作id
    self.curId = 0
    -- 循环次数
    self.loopCount = 0
end

-- @override
function RoleEditAction:iOnGUI()
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

-- @brief 设置显示数据
-- @param actInfo
-- @param armatureRender 动画渲染
-- @param editIndex 要编辑的下标
function RoleEditAction:setShowData(actInfo, armatureRender, editIndex, callback)
    self.actInfo = actInfo
    self.armatureRender = armatureRender
    self.onConformCallback = callback
    self.editIndex = editIndex

    -- 当前编辑的动作信息
    self.curEditAct = self.actInfo[self.editIndex]

    -- 当前id
    self.curId = self.curEditAct.id
    -- 当前名称
    self.curText = self.curEditAct.name
    -- 循环次数
    self.loopCount = self.curEditAct.loopCount

    -- 当前playName
    local playNames = self.armatureRender:getPlayNames()
    if #playNames > 0 then
        self.curArmatureIndex = 1

        for k, v in pairs(playNames) do
            if v == self.curEditAct.playName then
                self.curArmatureIndex = k
                break
            end 
        end
    end
end

-- @brief id重复检测
function RoleEditAction:isActIdRepeat(id)
    for k, v in pairs(self.actInfo) do
        if self.curEditAct ~= v and v.id == self.curId then
            return true
        end
    end

    return false
end

-- @brief 名称重复检测
function RoleEditAction:isActNameRepeat(name)
    for k, v in pairs(self.actInfo) do
        if self.curEditAct ~= v and v.name == name then
            return true
        end
    end

    return false
end

function RoleEditAction:dispatchEvent(name)
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

    if self.onConformCallback and self:isChange() then
        local playName = self.armatureRender:getPlayNameByIndex(self.curArmatureIndex)
        self.onConformCallback(name, playName, self.curId)
    end
end

-- @brief 判断数据是否发生改变
function RoleEditAction:isChange()
    -- 对比名称
    if self.curEditAct.name ~= self.curText then return true end

    -- 对比id
    if self.curEditAct.id ~= self.curId then return true end

    -- 对比循环次数
    if self.curEditAct.loopCount ~= self.loopCount then return true end

    -- 对比动画名
    local playName = self.armatureRender:getPlayNameByIndex(self.curArmatureIndex)
    if self.curEditAct.playName ~= playName then return true end

    return false
end

return RoleEditAction
