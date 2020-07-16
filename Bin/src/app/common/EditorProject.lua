-- @Author: fangcheng
-- @URL: github.com/tkzcfc
-- @Date:   2020-04-06 21:08:55
-- @Last Modified by:   fangcheng
-- @Last Modified time: 2020-05-04 22:06:29
-- @Description: 工程管理

local EditorProject = class("EditorProject")

local NewProjectData = {
}

local function Error_hook(err)
	logE(debug.traceback(err, 3))
end

function EditorProject:ctor()
	-- 项目名称
	self.name = ""
	-- 项目文件路径
	self.proFilePath = ""
	-- 项目配置
	self.config = {}
	-- 项目根目录
	self.projectDirPath = ""
	-- 是否打开项目了
	self.isOpened = false

	G_SysEventEmitter:on("onEditorContentSave", function()
		self:save()
	end)

	G_SysEventEmitter:on("onKeyBoardSave", function()
		self:save()
	end)
end

-- @brief 打开
function EditorProject:open(fullPath)
	if self.proFilePath == fullPath then
		logI("Project opened")
		return true
	end

	return xpcall(function() 
		self:save()

		self.name = G_Helper.getLastName(fullPath)
		self.projectDirPath = Tools:replaceString(fullPath, self.name, "")

		local content = cc.FileUtils:getInstance():getStringFromFile(fullPath)
		if content == "" then
			self.config = {}
		else
			self.config = json.decode(content)
		end

		_MyG.ProjectAssetManager:open(self.projectDirPath)

		-- cc.exports.G_uniqueSeed = self.config.uniqueSeed or 0

		self.isOpened = true
		self.proFilePath = fullPath
	end, Error_hook)
end

-- @brief 保存
function EditorProject:save()
	if not self.isOpened then
		return true
	end


	-- if G_uniqueSeed then
	-- 	self.config.uniqueSeed = G_uniqueSeed
	-- else
	-- 	self.config.uniqueSeed = 0
	-- end

	_MyG.ProjectAssetManager:save()
	if _MyG.Functions:writeTableToFile(self.config, self.proFilePath) then
		logI(string.format("Project %q saved successfully", tostring(self.name)))
		return true
	else
		logE(string.format("Failed to save project %q", tostring(self.name)))
		return false
	end
end

-- @brief 组装工程文件名全路径
function EditorProject:assembleProjectFileFullName(projDir, projName)
	return projDir .. "/" .. projName .. "." .. _MyG.GlobalData.ProjectExtension
end

-- @brief 工程创建
function EditorProject:createProj(projDir, projName)
	local FileUtilsInstance = cc.FileUtils:getInstance()

	if FileUtilsInstance:isDirectoryExist(projDir) then
		return 1
	end

	if not FileUtilsInstance:createDirectory(projDir) then
		return 2
	end

	NewProjectData.projName = projName

	local fullPath = self:assembleProjectFileFullName(projDir, projName)
	if _MyG.Functions:writeTableToFile(NewProjectData, fullPath) then
		return 0
	else
		return 2
	end
end

-- @brief 是否有效
function EditorProject:isValid()
	return self.isOpened
end

return EditorProject
