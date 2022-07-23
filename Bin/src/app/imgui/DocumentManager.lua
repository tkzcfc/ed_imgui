-- @Author: fangcheng
-- @Date:   2020-04-12 13:52:08
-- @Description: 


local Document = require("app.imgui.Document")
local DocumentManager = class("DocumentManager", Document)

function DocumentManager:ctor(name)
	if name == nil or name == "" then
		name = "##" .. tostring(self)
	end

	DocumentManager.super.ctor(self, name)

	self.documents = {}
	self.curShowDoc = nil
	self.waitCloseQue = {}

	self.tab_bar_flags = 0
	self.tab_bar_flags = Tools:bor_int32(self.tab_bar_flags, ImGuiTabBarFlags_FittingPolicyDefault_)
	self.tab_bar_flags = Tools:bor_int32(self.tab_bar_flags, ImGuiTabBarFlags_Reorderable)
end

function DocumentManager:destroy()
	for k,v in pairs(self.documents) do
		v:destroy()
	end
	self.documents = nil
end

function DocumentManager:count()
	return #self.documents
end

function DocumentManager:getDocuments()
	return self.documents
end

function DocumentManager:tryHideTitle(isHide)
	self.tryHideTitleTag = isHide
end

function DocumentManager:onGUI()
	if #self.documents < 1 then
		return
	end

	if self.tryHideTitleTag then
		if #self.documents == 1 then
			self.documents[1]:onGUI()
		else
			self:draw()
		end
	else
		self:draw()
	end
end

function DocumentManager:setCurShowDocumentByName(docName)
	for k, v in pairs(self.documents) do
		if v:getFullName() == docName then
			self.willShowDocument = v
			return
		end
	end
end

function DocumentManager:setCurShowDocument(doc)
	if self.curShowDoc ~= doc then
		self.willShowDocument = doc
	end
end

function DocumentManager:draw()
	self:updateName()

	local visible, tab_flags, isOpenTag
	if ImGui.BeginTabBar(self.name, self.tab_bar_flags) then
		for k, document in pairs(self.documents) do
			if document.dirty then
				tab_flags = ImGuiTabItemFlags_UnsavedDocument
			else
				tab_flags = 0
			end

			if self.willShowDocument == document then
				self.willShowDocument = nil
				tab_flags = Tools:bor_int32(tab_flags, ImGuiTabItemFlags_SetSelected)
			end

			if document:canClose() then
				visible, isOpenTag = ImGui.BeginTabItem(document.name, document.isOpen, tab_flags)
			else
				visible = Tools:BeginTabItem_NoClose(document.name, tab_flags)
				isOpenTag = true
			end
			if visible then
				if self.curShowDoc and self.curShowDoc ~= document then
					self.curShowDoc:onHide()
				end
				document:onGUI()
				ImGui.EndTabItem()
				
				if self.curShowDoc ~= document then
					self.curShowDoc = document
					if  self.onClickDocCall then
						self.onClickDocCall(self.curShowDoc)
					end
				end
			end
			if not isOpenTag and isOpenTag ~= document.isOpen then
				table.insert(self.waitCloseQue, document)
			end
		end
		ImGui.EndTabBar()
	end

	self:closeLogic()
end

-- @brief 加入关闭队列
function DocumentManager:addCloseQueue(document)
	table.insert(self.waitCloseQue, document)
end


local buttonSize = {x = 80, y = 0}

function DocumentManager:closeLogic()
	if #self.waitCloseQue <= 0 then
		return
	end

	local curDoc = self.waitCloseQue[1]
	if not curDoc.dirty then
		table.remove(self.waitCloseQue, 1)
		self:closeDocument(curDoc)
		G_SysEventEmitter:emit(SysEvent.ON_DUCUMENT_CLOSED, curDoc)
		return
	end





	if self.showBoxTag then
		return
	end

	self.showBoxTag = true

	local save_call = function()
		if curDoc:save() then
			table.remove(self.waitCloseQue, 1)
			self:closeDocument(curDoc)
			G_SysEventEmitter:emit(SysEvent.ON_DUCUMENT_CLOSED, curDoc)
		else
			self.waitCloseQue = {}
			G_SysEventEmitter:emit(SysEvent.ON_DUCUMENT_CLOSE_CANCEL, curDoc)
		end
		self.showBoxTag = false
	end

	local no_call = function()
		self.showBoxTag = false
		table.remove(self.waitCloseQue, 1)
		self:closeDocument(curDoc)
		G_SysEventEmitter:emit(SysEvent.ON_DUCUMENT_CLOSED, curDoc)
	end

	local cancel_call = function()
		self.waitCloseQue = {}
		self.showBoxTag = false
		G_SysEventEmitter:emit(SysEvent.ON_DUCUMENT_CLOSE_CANCEL, curDoc)
	end

	local msgBox = require("app.imgui.popup.MessageBox").new()
    msgBox:setContent(STR("DLG_IS_SVAE_ITEM"))
    msgBox:addBtn(STR("Yes"), save_call)
    msgBox:addBtn(STR("No"), no_call)
    msgBox:addBtn(STR("Cancel"), cancel_call)
    msgBox:setDefaultCloseCall(cancel_call)
    _MyG.PopupManager:addPopup(msgBox)



	-- local popupName = "Close '" .. curDoc.name .. "'"

	-- if not ImGui.IsPopupOpen(popupName) then
	-- 	ImGui.OpenPopup(popupName)
	-- end

	-- local needRemove = false
	-- if ImGui.BeginPopupModal(popupName, true) then
	-- 	ImGui.Text("Save change to the following items?")

	-- 	if ImGui.Button("Yes", buttonSize) then
	-- 		if curDoc:save() then
	-- 			table.remove(self.waitCloseQue, 1)
	-- 			needRemove = true
	-- 		else
	-- 			self.waitCloseQue = {}
	-- 		end
	-- 		ImGui.CloseCurrentPopup()
	-- 	end

	-- 	ImGui.SameLine()
	-- 	if ImGui.Button("No", buttonSize) then
	-- 		table.remove(self.waitCloseQue, 1)
	-- 		needRemove = true
	-- 		ImGui.CloseCurrentPopup()
	-- 	end

	-- 	ImGui.SameLine()
	-- 	if ImGui.Button("Cancel", buttonSize) then
	-- 		self.waitCloseQue = {}
	-- 		ImGui.CloseCurrentPopup()
	-- 	end
	-- 	ImGui.EndPopup()
	-- end
	-- if needRemove then
	-- 	self:closeDocument(curDoc)
	-- end
end

function DocumentManager:closeDocument(document)
	if document:canRemove() then
		for k, v in pairs(self.documents) do
			if v == document then
				v.ownerDocument = nil
				v:destroy()
				table.remove(self.documents, k)

				if v == self.curShowDoc then
					self.curShowDoc = nil
				end
				return
			end
		end
	else
		document.isOpen = false
	end
end

function DocumentManager:addDocument(doc)
	for k, v in pairs(self.documents) do
		if v.filename == doc.filename then
			doc.ownerDocument = nil
			doc:destroy()
			print(v.name .. "已存在")
			return
		end
	end

	doc.ownerDocument = self
	table.insert(self.documents, doc)

	self:updateName()
	return doc
end

function DocumentManager:hasDocument(docName)
	for k, v in pairs(self.documents) do
		if v.filename == docName then
			return true
		end
	end
	return false
end

function DocumentManager:showDoc(filename)
	for k, v in pairs(self.documents) do
		if v.filename == filename then
			v.isOpen = true
			return true
		end
	end
	return false
end

function DocumentManager:getCurDocument()
	return self.curShowDoc
end

function DocumentManager:save()
	for _, doc in pairs(self.documents) do
		if not doc:save() then
			return false
		end
	end
	return true
end

function DocumentManager:updateName()
	local t = {}
	for k, v in pairs(self.documents) do
		v.__uniqueKeyName = v:getClearName()
		if v.isOpen then
			if t[v.__uniqueKeyName] == nil then
				t[v.__uniqueKeyName] = 0
			else
				t[v.__uniqueKeyName] = t[v.__uniqueKeyName] + 1
			end
		end
	end

	for k, v in pairs(self.documents) do
		if t[v.__uniqueKeyName] and t[v.__uniqueKeyName] > 0 then
			if not v.__isFullName then
				v.name = v.filename
				v.__isFullName = true
			end
		else
			if v.__isFullName then
				v.name = v:getClearName()
				v.__isFullName = false
			end
		end
	end
end

function DocumentManager:setClickDocumentCall(call)
	self.onClickDocCall = call
end

return DocumentManager