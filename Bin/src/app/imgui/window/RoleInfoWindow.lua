-- @Author : fc
-- @Date   : 2021-9-22 11:08:13
-- @remark : 角色信息窗口

local RoleInfoWindow = class("RoleInfoWindow", require("app.imgui.Window"))


------------------------------------------------ Role Action Document ------------------------------------------------
local RoleActionDoc = class("RoleActionDoc", require("app.imgui.Document"))

function RoleActionDoc:onGUI()
    RoleActionDoc.super.onGUI(self)
    G_SysEventEmitter:emit(SysEvent.ON_WINDOW_GUI_ROLE_ACTION)
end

function RoleActionDoc:canClose()
	return false
end

function RoleActionDoc:canRemove()
	return false
end

function RoleActionDoc:onShow()
    RoleActionDoc.super.onShow(self)
    G_SysEventEmitter:emit(SysEvent.ON_SHOW_BOTTOM_DOCUMENT, "timeline")
end


------------------------------------------------ Role Skill Document ------------------------------------------------
local RoleSkillDoc = class("RoleSkillDoc", require("app.imgui.Document"))

function RoleSkillDoc:onGUI()
    RoleSkillDoc.super.onGUI(self)
    G_SysEventEmitter:emit(SysEvent.ON_WINDOW_GUI_ROLE_SKILL)
end

function RoleSkillDoc:canClose()
	return false
end

function RoleSkillDoc:canRemove()
	return false
end

function RoleSkillDoc:onShow()
    RoleSkillDoc.super.onShow(self)
    G_SysEventEmitter:emit(SysEvent.ON_SHOW_BOTTOM_DOCUMENT, "timeline")
end




function RoleInfoWindow:ctor(...)
    RoleInfoWindow.super.ctor(self, ...)
    self.docMng = require("app.imgui.DocumentManager").new()
    self.docMng:addDocument(RoleActionDoc.new(RoleDocName[RoleDocType.ACTION]))
    self.docMng:addDocument(RoleSkillDoc.new(RoleDocName[RoleDocType.SKILL]))
    self.docMng:setClickDocumentCall(function(doc)
        G_SysEventEmitter:emit(SysEvent.ON_ROLE_TIMELINE_DOC_CHANGE, doc:getFullName())
    end)

    G_SysEventEmitter:on(SysEvent.ON_WINDOW_ROLE_DOC_CHANGE, function(docName)
        self.docMng:setCurShowDocumentByName(docName)
    end, self)
end

function RoleInfoWindow:onGUI_Window()
    self.docMng:onGUI()
end

return RoleInfoWindow