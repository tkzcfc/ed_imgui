local Tree = require("app.imgui.CustomTree")
local FileDialog = require("app.imgui.FileDialog")

local AssetContent = class("AssetContent", Tree)

function AssetContent:ctor(name)
	AssetContent.super.ctor(self, name)

	self.dragEndCallback = function(pos, item)
		pos = G_Helper.win_2_visible_pos(pos)
		G_SysEventEmitter:emit("onDragAssetItem", pos, item.fullPath, 0)
	end

	self.leftDoubleClickCall = function(item)
		if item.noOpen then
			G_SysEventEmitter:emit("onOpenAssetItem", item.fullPath, 0)
		end
	end

	self.onItemHoveredCallback = function(item)

		if not _MyG.Functions:isTexture(item.fullPath) then
			return
		end

		if self.cache_last_ItemHovered_item ~= item then
			self.cache_last_ItemHovered_item = item
			self.cache_last_ItemHovered_time = os.clock()
			self.cache_show_image_data = nil
			return
		end

		if self.cache_show_image_data == nil then
			local fullPath = item.fullPath
			local textureID = Tools:getImguiTextureID(fullPath)
			if textureID == nil then
				return
			end
			self.cache_show_image_data = {}

			local imageW = Tools:getImguiTextureWidth(fullPath)
			local imageH = Tools:getImguiTextureHeight(fullPath)
			local showTextureInfo = string.format("%d*%d", imageW, imageH)
			local maxValue = math.max(imageW, imageH)
			if maxValue > 500 then
				local scale = 500 / maxValue
				imageW = imageW * scale
				imageH = imageH * scale
			end
			self.cache_show_image_data["textureInfo"] = showTextureInfo
			self.cache_show_image_data["textureID"] = textureID
			self.cache_show_image_data["imageSize"] = cc.p(imageW, imageH)
		end
		if os.clock() - self.cache_last_ItemHovered_time > 0.2 then
			ImGui.BeginTooltip()
			ImGui.Text(self.cache_show_image_data.textureInfo)
			ImGui.Image(self.cache_show_image_data.textureID, self.cache_show_image_data.imageSize)
			ImGui.EndTooltip()
		end
	end
	
	self.rightClickCall = function(item)
		self.isOpenPopupTag = true
		self.rightClickData = item
	end

	self.onAssetContentUpdateHandle = function()
		self:updateContentExt()
	end
	G_SysEventEmitter:on("onAssetContentUpdate", self.onAssetContentUpdateHandle)
end

function AssetContent:cosutomDrawItem(item, noDrag)
	AssetContent.super.cosutomDrawItem(self, item, noDrag)
	if noDrag then
		return
	end

	if item.filetype == "png" then
		if ImGui.BeginDragDropSource(ImGuiDragDropFlags_None) then
        	ImGui.SetDragDropPayload("DRAG_MOVE_CELL_IMAGE_PNG", item.fullPath, #item.fullPath)
        	AssetContent.super.cosutomDrawItem(self, item, true)
        	self.cache_drag_item = item
        	ImGui.EndDragDropSource()
    	end
	elseif item.filetype == "lua" then
		if ImGui.BeginDragDropSource(ImGuiDragDropFlags_None) then
        	ImGui.SetDragDropPayload("DRAG_MOVE_CELL_LUA", item.fullPath, #item.fullPath)
        	AssetContent.super.cosutomDrawItem(self, item, true)
        	self.cache_drag_item = item
        	ImGui.EndDragDropSource()
    	end
	elseif item.filetype == "layer" then
		if ImGui.BeginDragDropSource(ImGuiDragDropFlags_None) then
        	ImGui.SetDragDropPayload("DRAG_MOVE_CELL_LAYER", item.fullPath, #item.fullPath)
        	AssetContent.super.cosutomDrawItem(self, item, true)
        	self.cache_drag_item = item
        	ImGui.EndDragDropSource()
    	end
	elseif item.filetype == "widget" then
		if ImGui.BeginDragDropSource(ImGuiDragDropFlags_None) then
        	ImGui.SetDragDropPayload("DRAG_MOVE_CELL_WIDGET", item.fullPath, #item.fullPath)
        	AssetContent.super.cosutomDrawItem(self, item, true)
        	self.cache_drag_item = item
        	ImGui.EndDragDropSource()
    	end
	end
end

function AssetContent:updateContentExt()

	local openTagMap = {}

	local function push(item)
		if item == nil then
			return
		end
		if item.__isOpen then
			openTagMap[item.fullPath] = true
		end
		if item.items then
			for k,v in pairs(item.items) do
				push(v)
			end
		end
	end

	local function pop(item)
		if item == nil then
			return
		end
		if openTagMap[item.fullPath] then
			item.__isOpen = true
		end
		if item.dataDirty then
			item.dataDirty = false
			self:doseek(item)
		end
		if item.items then
			for k,v in pairs(item.items) do
				pop(v)
			end
		end
	end

	push(self.showData)
	self:updateContent()
	pop(self.showData)
end

function AssetContent:getPath(fullPath)
	local filename = Tools:getFilename(fullPath)
	local path = string.sub(fullPath, 1, -#filename - 1)
	return path
end

function AssetContent:onGUI()
	self.cache_drag_item_last = self.cache_drag_item
	self.cache_drag_item = nil

	AssetContent.super.onGUI(self)

	if self.cache_drag_item == nil then
		if self.cache_drag_item_last then
			self.dragEndCallback(self.img_ui_io.MousePos, self.cache_drag_item_last)
		end
	end

	if self.isOpenPopupTag then
		ImGui.OpenPopup("assetContent_popup")
		self.isOpenPopupTag = false
	end
	if ImGui.BeginPopup("assetContent_popup") then
		self:Menu_OnGUI()
		ImGui.EndPopup()
	end
end

function AssetContent:Menu_OnGUI()
	if ImGui.MenuItem(STR("Import")) then
		if self.rightClickData.noOpen then
			_MyG.Functions:importResource("*.png", self:getPath(self.rightClickData.fullPath))
		else
			_MyG.Functions:importResource("*.png", self.rightClickData.fullPath)
		end
	end

	if ImGui.BeginMenu(STR("New")) then
		if ImGui.MenuItem(STR("Folder")) then
			if self.rightClickData.noOpen then
				G_SysEventEmitter:emit("Menu/File/New/Folder", self:getPath(self.rightClickData.fullPath))
			else
				G_SysEventEmitter:emit("Menu/File/New/Folder", self.rightClickData.fullPath)
			end
		end
		if ImGui.MenuItem(STR("Map")) then
			if self.rightClickData.noOpen then
				G_SysEventEmitter:emit("Menu/File/New/Map", self:getPath(self.rightClickData.fullPath))
			else
				G_SysEventEmitter:emit("Menu/File/New/Map", self.rightClickData.fullPath)
			end
		end
		if ImGui.MenuItem(STR("Widget")) then
			if self.rightClickData.noOpen then
				G_SysEventEmitter:emit("Menu/File/New/Widget", self:getPath(self.rightClickData.fullPath))
			else
				G_SysEventEmitter:emit("Menu/File/New/Widget", self.rightClickData.fullPath)
			end
		end
		if ImGui.MenuItem(STR("Layer")) then
			if self.rightClickData.noOpen then
				G_SysEventEmitter:emit("Menu/File/New/Layer", self:getPath(self.rightClickData.fullPath))
			else
				G_SysEventEmitter:emit("Menu/File/New/Layer", self.rightClickData.fullPath)
			end
		end
		ImGui.EndMenu()
	end

	if self.rightClickData.noOpen then
		if ImGui.MenuItem(STR("Delete")) then
			_MyG.Functions:removeFile(self.rightClickData.fullPath)
		end
	end

	if ImGui.MenuItem(STR("Update")) then
		self:updateContentExt()
	end
end

function AssetContent:updateContent()
	self:initFilters()

	local rootPath = _MyG.ProjectData.projectDirPath
	if rootPath == nil then
		return
	end

	local showData = {}
	showData.name = _MyG.ProjectData.projectName
	showData.noOpen = false
	showData.noDrag = true
	showData.dataDirty = true
	showData.fullPath = rootPath
	self:setShowData(showData)
end

function AssetContent:initFilters()
	self.filters = 
	{
		"png",
		"widget",
		"map",
		"layer",
	}
end

function AssetContent:doseek(tab)
	local path = tab.fullPath
	local files = FileDialog.getFiles(path)
	if #files <= 0 then
		return
	end
	tab.items = {}

	for _,fileInfo in pairs(files) do
		local t = {}
		t.name = fileInfo.name
		t.noOpen = not fileInfo.isDir
		t.noDrag = fileInfo.isDir
		t.fullPath = fileInfo.fullPath
		t.filetype = string.match(fileInfo.name, "%.(%w+)$")

		if fileInfo.isDir then
			t.dataDirty = true
			table.insert(tab.items, t)
		else
			if self:filterTest(t.name) then
				table.insert(tab.items, t)
			end
		end
	end
end

function AssetContent:filterTest(name)
	if #self.filters <= 0 then
		return true
	end

	local ext = string.match(name, "%.(%w+)$")
	for k, v in pairs(self.filters) do
		if v == ext then
			return true
		end
	end
	return false
end

return AssetContent

