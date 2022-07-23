-- @Author: fangcheng
-- @Date:   2020-04-06 21:08:55
-- @Description: 工程管理

local EditorProject = class("EditorProject")

local NewProjectData = {
}

local function Error_hook(err)
	logE(debug.traceback(err, 3))
end

function EditorProject:ctor()
	-- 项目文件名称: xxx.edproj
	self.projectFileName = ""
	-- 项目名称(纯名字xxx)
	self.projectNme = ""
	-- 项目文件全路径
	self.proFileFullPath = ""
	-- 项目配置
	self.config = {}
	-- 项目根目录
	self.projectDirPath = ""
	-- 是否打开项目了
	self.isOpened = false

	-- 用户临时数据
	self.userTmpData = {}
	-- 用户临时数据存放路径
	self.userTmpDataFilePath = ""

	G_SysEventEmitter:on(SysEvent.CONTENT_ON_EDITOR_CONTENT_SAVE, function()
		self:save()
	end, self)

	G_SysEventEmitter:on(SysEvent.ON_KEY_BOARD_SAVE, function()
		self:save()
	end, self)

	G_SysEventEmitter:on(SysEvent.ON_PRJ_USER_TMP_DATA_CHANGE, function()
		if not self.isOpened then return end
		-- 下一帧在保存
		oRoutine(o_once(function()
			self:saveUserTmpData()
		end))
	end, self)
end

-- @brief 获取用户临时数据
function EditorProject:getUserTmpData()
	return self.userTmpData
end

-- @brief 获取pro文件路径
function EditorProject:getProFilePath()
	return self.proFileFullPath
end

-- @brief 打开
function EditorProject:open(fullPath)
	if self.proFileFullPath == fullPath then
		error("Project opened")
	end

	self:save()

	self.projectDirPath, self.projectFileName = self:genProjectDir(fullPath)
	self.projectNme = G_Helper.getFileClsName(self.projectFileName)

	-- 工程数据读取
	local content = cc.FileUtils:getInstance():getStringFromFile(fullPath)
	if content == "" then
		self.config = {}
	else
		self.config = _MyG.Functions:decodeJson(content)
	end

	self.isOpened = true
	-- 工程文件路径
	self.proFileFullPath = fullPath

	-- 临时数据读取
	local filepath = string.gsub(fullPath, "(.+)(%.[a-zA-Z_-]+)$", "%1.udf")
	self:readUserTmpData(filepath)

	self.config.gameResDir = G_Helper.fmtDirPath(self.config.gameResDir or "")

	G_SysEventEmitter:emit(SysEvent.SET_GAME_RES_DIR, self.config.gameResDir)
end

-- @brief 工程路径
function EditorProject:genProjectDir(fullPath)
	local name = G_Helper.getLastName(fullPath)
	local projectDirPath = Tools:replaceString(fullPath, name, "")
	return projectDirPath, name
end

-- @brief 临时数据读取
function EditorProject:readUserTmpData(fullPath)
	-- 工程用户临时数据路径
	self.userTmpDataFilePath = fullPath
	self.userTmpData = {}

	if not cc.FileUtils:getInstance():isFileExist(fullPath) then return end

	local content = cc.FileUtils:getInstance():getStringFromFile(fullPath)
	if content ~= "" then
		local udData = {}
		-- 解析临时数据
		local ok = pcall(function()
			udData = _MyG.Functions:decodeJson(content)
		end)
		if ok then
			self.userTmpData = udData
		end
	end
end

-- @brief 临时数据保存
function EditorProject:saveUserTmpData()
	_MyG.Functions:writeTableToFile(self.userTmpData, self.userTmpDataFilePath)
end

-- @brief 保存
function EditorProject:save()
	if not self.isOpened then
		return true
	end

	self:saveUserTmpData()

	if _MyG.Functions:writeTableToFile(self.config, self.proFileFullPath) then
		logI(string.format("Project %q saved successfully", tostring(self.projectFileName)))
		return true
	else
		logE(string.format("Failed to save project %q", tostring(self.projectFileName)))
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

function EditorProject:getGameResDir()
	if self:isValid() then
		return self.config.gameResDir or ""
	end
	return ""
end

return EditorProject
