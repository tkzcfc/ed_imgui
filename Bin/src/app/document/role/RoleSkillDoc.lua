-- @Author : fc
-- @Date   : 2022-1-29 17:34:26
-- @remark : 

local RoleSkillCommonDoc = class("RoleSkillCommonDoc", require("app.imgui.Document"))

function RoleSkillCommonDoc:onGUI()
    RoleSkillCommonDoc.super.onGUI(self)
    self.onGUI_cb()
end

function RoleSkillCommonDoc:canClose()
	return false
end

function RoleSkillCommonDoc:canRemove()
	return false
end

function RoleSkillCommonDoc:setGUICallback(cb)
    self.onGUI_cb = cb
end

return RoleSkillCommonDoc