-- @Author: fangcheng
-- @URL: github.com/tkzcfc
-- @Date:   2020-04-12 13:52:08
-- @Last Modified by:   fangcheng
-- @Last Modified time: 2020-05-07 22:21:50
-- @Description: 文件选择弹框


require("lfs")

local M = class("FileDialog")

M.FileDialogUsage_OpenFile 		= 0
M.FileDialogUsage_SaveFile 		= 1
M.FileDialogUsage_OpenFolder 	= 2

local ListType = 
{
	DISK = 1,
	FOLDER = 2,
	FILE = 3,
}

local diskIcon = Tools:getImguiTextureID("res/disk.png")
local fileIcon = Tools:getImguiTextureID("res/file.png")
local folderIcon = Tools:getImguiTextureID("res/folder.png")

local getIconByType = function(_type)
	if _type == ListType.DISK then
		return diskIcon
	elseif _type == ListType.FOLDER then
		return folderIcon
	else
		return fileIcon
	end
end

local function file_exists(path)
  local file = io.open(path, "rb")
  if file then file:close() end
  return file ~= nil
end

--------------------------------------------------------------------------------------------

-- function M:new(dlgName, curDir)
-- 	local R = {}
	
-- 	setmetatable(R, self)
-- 	self.__index = self
	
-- 	R:ctor(dlgName, curDir)

-- 	return R
-- end

function M:ctor(dlgName, curDir, usage)
	self.dlgName = dlgName or string.format("##%s", tostring(self))
	self.usage = usage or M.FileDialogUsage_OpenFile
	self.isOpen = false
	self.filters = {}

	if curDir == nil or curDir == "" then
		self.curDir = M.getCurrentDir()
		self.curEditDir = Tools:STU(self.curDir)
	else
		curDir = M.changePath(curDir)
		self.curDir = Tools:UTS(curDir)
		self.curEditDir = curDir
	end
	self.curEditFileName = ""

	self:setCanOverlap(true)
end

function M:setSelectSingle(isSingle)
	self.selectSingle = isSingle
end

function M:open(okCall, cancelCall)
	self.isOpen = true
	self.ok_callback = okCall
	self.cancel_callback = cancelCall
end

-- 格式：png
function M:addFilter(filter)
	table.insert(self.filters, filter)
end

function M:setFilter(filters)
	self.filters = filters
end

function M:setCanOverlap(value)
	self.isCanOverlap = value
end

function M:setPathConstraint(pathConstraint)
	if pathConstraint then
		pathConstraint = M.changePath(pathConstraint)
		if string.sub(pathConstraint, -1, -1) == "/" then
			pathConstraint = string.sub(pathConstraint, 1, -2)
		end
	end
	self.pathConstraint = pathConstraint
end

function M:onGUI()
	if not self.isOpen then
		return
	end
	ImGui.OpenPopup(self.dlgName)

	self:updateShowList()

	local visible, call_ok, enter_true
	visible, self.isOpen = ImGui.BeginPopupModal(self.dlgName, self.isOpen, ImGuiWindowFlags_AlwaysAutoResize)
	if visible then
		ImGui.Text(STR("路径"))
		ImGui.SameLine()
		ImGui.PushItemWidth(280)
		if self.pathConstraint then
			enter_true, self.curEditDir = Tools:imgui_inputText("", self.curEditDir, 512, ImGuiInputTextFlags_ReadOnly)
		else
			enter_true, self.curEditDir = Tools:imgui_inputText("", self.curEditDir, 512, ImGuiInputTextFlags_EnterReturnsTrue)
		end
		if enter_true then
			self:jump()
		end
		ImGui.PopItemWidth()

		ImGui.SameLine()
		if ImGui.ArrowButton(STR("向上"), ImGuiDir_Up) then
			self:up()
		end

		ImGui.SameLine()
		if ImGui.Button(STR("新建")) then
			self.newFolderName = ""
			ImGui.OpenPopup("##create folder")
		end

		-- 新建文件夹窗口逻辑
		if ImGui.BeginPopupModal("##create folder", true, ImGuiWindowFlags_AlwaysAutoResize) then
			ImGui.Text(STR("文件夹名字"))
			ImGui.SameLine()
			enter_true, self.newFolderName = Tools:imgui_inputText("", self.newFolderName, 64, 0)
			ImGui.Spacing()
			ImGui.Separator()

			local width = ImGui.GetContentRegionAvailWidth()
			ImGui.BeginHorizontal("h1", {x = width, y = 40}, 0.5)

			if ImGui.Button(STR("确定"), {x = width / 2, y = 0}) and #self.newFolderName > 0 then
				local path = self.curDir .. "/" .. Tools:UTS(self.newFolderName)
				local ret, err = lfs.mkdir(path)
				if ret then
					self:updateShowList(true)
					ImGui.CloseCurrentPopup()
				else
					print("err", err)
				end
			end
			if ImGui.Button(STR("取消"), {x = width / 2, y = 0}) then
				ImGui.CloseCurrentPopup()
			end

			ImGui.EndHorizontal()
			ImGui.EndPopup()
		end

		local childWidth = 400

		ImGui.PushStyleVar(ImGuiStyleVar_ChildRounding, 5.0)
		ImGui.BeginChild("Sub2", {x = childWidth, y = 300}, true)

		for k, v in pairs(self.showList) do
			ImGui.Image(getIconByType(v.type), {x = 32, y = 32})
			ImGui.SameLine()
			if ImGui.Selectable(v.name_utf8, v.isSelect, ImGuiSelectableFlags_AllowDoubleClick, {x = 0, y = 32}) then
				-- 双击跳转
				if ImGui.IsMouseDoubleClicked(0) then
					if v.type == ListType.DISK or v.type == ListType.FOLDER then
						self:to(v.fullPath)
					end
				-- 单击选中/取消
				else
					if self:canSelect(v) then
						v.isSelect = not v.isSelect
						self.curEditFileName = self:getShowSelectStr()
					end
				end
			end
		end

		ImGui.EndChild()
		
		ImGui.Separator()
		ImGui.PushItemWidth(childWidth)
		if self.usage == M.FileDialogUsage_SaveFile then
			if #self.filters > 0 then
				if self.cache_filter_input == nil then
					self.cache_filter_input = "." .. self.filters[1]
				end
				enter_true,self.curEditFileName = Tools:imgui_inputText(self.cache_filter_input, self.curEditFileName, 512)
			else
				enter_true,self.curEditFileName = Tools:imgui_inputText("##cur_filename_savefile", self.curEditFileName, 512)
			end
		else
			enter_true,self.curEditFileName = Tools:imgui_inputText("##cur_filename_openfile", self.curEditFileName, 512, ImGuiInputTextFlags_ReadOnly)
		end
		ImGui.PopItemWidth()

		ImGui.PushStyleVar(ImGuiStyleVar_ItemSpacing, {x = 8, y = 0})
		ImGui.BeginHorizontal("h1", {x = childWidth, y = 40}, 0.5)

		local buttonW = childWidth / 2

		if self.usage == M.FileDialogUsage_OpenFolder then
			if ImGui.Button(STR("打开"), {x = buttonW, y = 0}) then
				self:do_callback()
				call_ok = true
				self.isOpen = false
			end
		elseif self.usage == M.FileDialogUsage_OpenFile then
			if ImGui.Button(STR("打开"), {x = buttonW, y = 0}) then
				self:do_callback()
				call_ok = true
				self.isOpen = false
			end
		else
			if ImGui.Button(STR("保存"), {x = buttonW, y = 0}) then
				if self.curEditFileName ~= "" then
					-- 判断文件后缀
					local validExt = false
					if #self.filters > 0 then
						local ext = string.match(self.curEditFileName, "%.(%w+)$")
						if ext == self.filters[1] then
							validExt = true
						else
							if ext == nil or ext == "" then
								self.curEditFileName = self.curEditFileName .. "." .. self.filters[1]
								validExt = false
							end
						end
					end
					if validExt then
						local fullPath = self.curDir .. "/" .. Tools:UTS(self.curEditFileName)
						if file_exists(fullPath) then
							self.file_exists_tag = true
						else
							self:do_callback()
							call_ok = true
							self.isOpen = false
						end
					end
				end
			end
		end

		if ImGui.Button(STR("取消"), {x = buttonW, y = 0}) then
			self.isOpen = false
		end

		ImGui.EndHorizontal()
		ImGui.PopStyleVar()

		if self.file_exists_tag then
			if not ImGui.IsPopupOpen("##file_exists tip") then
				ImGui.OpenPopup("##file_exists tip")
			end

			visible, self.file_exists_tag = ImGui.BeginPopupModal("##file_exists tip", true, ImGuiWindowFlags_AlwaysAutoResize)
			if visible then
				if self.isCanOverlap then
					ImGui.Text(STR("文件已经存在，是否替换"))
					ImGui.Separator()
					if ImGui.Button(STR("是"), {x = 60, y = 24}) then
						self.file_exists_tag = false
						ImGui.CloseCurrentPopup()
						self:do_callback()
						call_ok = true
						self.isOpen = false
					end
					ImGui.SameLine()
					if ImGui.Button(STR("否"), {x = 60, y = 24}) then
						self.file_exists_tag = false
						ImGui.CloseCurrentPopup()
					end
				else
					ImGui.Text(STR("文件已经存在"))
					ImGui.Separator()
					if ImGui.Button(STR("是"), {x = 60, y = 24}) then
						self.file_exists_tag = false
						ImGui.CloseCurrentPopup()
					end
				end
				ImGui.EndPopup()
			end
		end

		if not self.isOpen then
			ImGui.CloseCurrentPopup()
		end

		ImGui.PopStyleVar()
		ImGui.EndPopup()
	end

	if not call_ok and not self.isOpen then
		self:do_cancel_callback()
	end
end

function M:getSelectCount()
	local count = 0
	for k, v in pairs(self.showList) do
		if v.isSelect then
			count = count + 1
		end
	end
	return count
end

function M:getShowSelectStr()
	local str = ""
	local count = 0
	for k, v in pairs(self.showList) do
		if v.isSelect then
			if count > 0 then
				str = str .. "|"
			end
			str = str .. v.name_utf8
			count = count + 1
		end
	end
	return str
end

function M:unSelectAll()
	for k, v in pairs(self.showList) do
		v.isSelect = false
	end
end

function M:canSelect(itemData)
	if itemData.isSelect then
		-- 保存文件只能单选
		if self.selectSingle or self.usage == M.FileDialogUsage_SaveFile then
			self:unSelectAll()
		end
		return true
	end

	if self.usage == M.FileDialogUsage_OpenFolder then
		if itemData.type ~= ListType.FILE then
			if self.selectSingle then
				return self:getSelectCount() <= 0
			end
			return true
		end
	else
		if itemData.type == ListType.FILE then
			-- 保存文件只能单选
			if self.selectSingle or self.usage == M.FileDialogUsage_SaveFile then
				self:unSelectAll()
			end
			return true
		end
	end
	return false
end

function M:jump()
	self.curDir = Tools:UTS(self.curEditDir)
end

function M:to(path)
	self.curDir = path
	self.curEditDir = Tools:STU(path)
end

function M:up()
	local dir = self:fmt(self.curEditDir)
	if dir == "" then
		return
	end
	local str = string.reverse(dir)
	local pos = string.find(str, "/")
	if pos then
		dir = string.sub(dir, 1, -pos - 1)
	else
		dir = ""
	end

	if self.pathConstraint then
		if not string.find(dir, self.pathConstraint) then
			return
		end
		self.curEditDir = dir
	else
		self.curEditDir = dir
	end

	self:jump()
end

function M:fmt(path)
	path = string.gsub(path, "\\", "/")
	if string.sub(path, -1, -1) == "/" then
		path = string.sub(path, 1, -2)
	end
	return path
end

function M:do_callback()
	if self.curEditFileName == "" then
		self:do_cancel_callback()
		return
	end
	self:do_ok_callback()
end

function M:do_ok_callback()
	local ts = {}
	if self.usage == M.FileDialogUsage_SaveFile then
		local name = Tools:UTS(self.curEditFileName)
		local t = {}
		t.name = name
		t.name_utf8 = self.curEditFileName
		t.fullPath = self:fmt(self.curDir .. "/" .. name)
		table.insert(ts, t)
	else
		if self:getSelectCount() <= 0 then
			self:do_cancel_callback()
			return
		end
		for k, v in pairs(self.showList) do
			if v.isSelect then
				local t = {}
				t.name = v.name
				t.name_utf8 = v.name_utf8
				t.fullPath = self:fmt(v.fullPath)
				table.insert(ts, t)
			end
		end
	end

	if self.ok_callback then
		self.ok_callback(ts)
	end
end

function M:do_cancel_callback()
	if self.cancel_callback then
		self.cancel_callback(ts)
	end
end

function M:updateShowList(forceUpdate)
	if not forceUpdate and self.curDir == self.lastUpdateDir then
		return
	end
	self.lastUpdateDir = self.curDir

	self.curEditFileName = ""
	self.showList = {}

	if self.curDir == "" then
		local logicDrives = Tools:getLogicalDriveStrings()
		for k,v in pairs(logicDrives) do
			local t = {}
			t.name = v
			t.name_utf8 = v
			t.fullPath = self:fmt(v)
			t.type = ListType.DISK
			table.insert(self.showList, t)
		end
	else
		self.curDir = self:fmt(self.curDir)
		local rootpath = self.curDir

    	for entry in lfs.dir(rootpath) do  
    	    if entry ~= '.' and entry ~= '..' then
    	        local path = rootpath .. '/' .. entry  
    	        local attr = lfs.attributes(path)
    	        if attr then
    	        	local t = {}
    	        	t.name = entry
    	        	t.name_utf8 = Tools:STU(entry)
					t.fullPath = path
					if attr.mode == "directory" then
						t.type = ListType.FOLDER
					else
						t.type = ListType.FILE
					end

					if self.usage == M.FileDialogUsage_OpenFolder then
						if t.type == ListType.FOLDER then
							table.insert(self.showList, t)
						end
					else
						if t.type == ListType.FOLDER then
							table.insert(self.showList, t)
						else
							if self:filterTest(entry) then
								table.insert(self.showList, t)
							end
						end
					end
    	        end
    	    end  
    	end
	end
end

function M:filterTest(name)
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

-----------------------------------------------------------------------------------------------

function M.getCurrentDir()
	return M.changePath(lfs.currentdir())
end

function M.changePath(path)
	path = string.gsub(path, "\\", "/")

	local ret
	repeat
		path, ret = string.gsub(path, "//", "/")
	until(ret == 0)

	return path
end

function M.getFiles(rootpath)
	rootpath = M.changePath(rootpath)
	local filesTab = {}

    for entry in lfs.dir(rootpath) do  
        if entry ~= '.' and entry ~= '..' then
            local path = rootpath .. '/' .. entry  
            local attr = lfs.attributes(path)

            local fileInfo = {}
            fileInfo.fullPath = M.changePath(path)
            fileInfo.name = entry
            fileInfo.isDir = attr.mode == "directory"
            table.insert(filesTab, fileInfo)
        end  
    end

    return filesTab
end

return M