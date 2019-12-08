local Functions = {}

require "lfs"

local FileUtilsInstance = cc.FileUtils:getInstance()

function Functions:createProject(name)
	if name == "" then
	end
	for i,v in ipairs(_MyG.GlobalData.ProjectNameArr) do
		if v == name then
			_MyG.ShowBox(STR("PROJECT_EXISTS"))
			return
		end
	end
	local projpath = _MyG.GlobalData.ProjectsPath..name
	if FileUtilsInstance:isDirectoryExist(projpath) then
		_MyG.ShowBox(STR("PROJECT_CREATE_FAIL_EXIST"))
	else
		if FileUtilsInstance:createDirectory(projpath) then
			-- FileUtilsInstance:createDirectory(projpath.."/Resource")
			-- FileUtilsInstance:createDirectory(projpath.."/Files")
	
			local projectFileName = projpath .. "/" .. name .. "." .. _MyG.GlobalData:getFileTypeInfo("PROJECT").extension
			if self:writeScriptToFile("local M = {} return M", projectFileName) then
				self:changeToProject(projectFileName)
				_MyG.ShowBox(STR("PROJECT_CREATE_SUCCESS"))
			else
				_MyG.ShowBox(STR("PROJECT_CREATE_FAIL"))
			end
		else
			_MyG.ShowBox(STR("PROJECT_CREATE_FAIL"))
		end
	end
end

function Functions:changeToProject(projectName)
	G_SysEventEmitter:emit("onOpenProject", projectName)
end

function Functions:createFolder(rootpath, name)
	rootpath = rootpath .. "/" .. name
	rootpath = G_Helper.fmtPath(rootpath)
	if not FileUtilsInstance:createDirectory(rootpath) then
		_MyG.ShowBox(STR("FOLDER_CREATE_FAIL"))
		return false
	end

	self:autoUpdate(rootpath)

	return true
end

function Functions:autoUpdate(path)
	if path == nil then
		G_SysEventEmitter:emit("onAssetContentUpdate")
		return
	end
	if string.find(path, _MyG.GlobalData.CommonResourcePath) then
		-- 公共资源
		G_SysEventEmitter:emit("onAssetCommonUpdate")
	elseif string.find(path, _MyG.GlobalData.CocosResourcePath) then
		-- Cocos资源
		G_SysEventEmitter:emit("onAssetCocosUpdate")
	else
		G_SysEventEmitter:emit("onAssetContentUpdate")
	end
end

function Functions:createMap(filepath)
	if not self:createFileCheck(filepath) then
		return
	end
	self:writeScriptToFile("local M = {} return M", filepath)
end

function Functions:createWidget(filepath)
	if not self:createFileCheck(filepath) then
		return
	end
	self:writeScriptToFile("local M = {} return M", filepath)
end

function Functions:createLayer(filepath)
	if not self:createFileCheck(filepath) then
		return
	end
	self:writeScriptToFile("local M = {} return M", filepath)
end

function Functions:createFileCheck(filepath)
	if filepath == nil then
		logE("createFileCheck错误: filepath = nil")
		return false
	end
	if not FileUtilsInstance:isAbsolutePath(filepath) then
		logE("createFileCheck错误: 不是绝对路径", filepath)
		return false
	end
	if FileUtilsInstance:isFileExist(filepath) then
		logE(string.format("The document %q already exists", filepath))
		return false
	end

	local extension = G_Helper.getExtension(filepath)
	local clsPath = Tools:replaceString(filepath, extension, "")

	local fileTypeInfo = _MyG.GlobalData.fileTypeInfo
	for k,v in pairs(fileTypeInfo) do
		filepath = clsPath .. v.extension
		if FileUtilsInstance:isFileExist(filepath) then
			logE(string.format("createFileCheck错误: 文件名%q重名,文件%q已存在", clsPath, filepath))
			return false
		end
	end

	return true
end

function Functions:writeScriptToFile(str, filepath)
	return Functions:writeStringToFile(str, filepath)
end

function Functions:writePublishScriptToFile(str, filepath)
	return Functions:writeStringToFile(str, filepath)
end

function Functions:writeStringToFile(str, filepath)
	if not FileUtilsInstance:isAbsolutePath(filepath) then
		logW("writeStringToFile警告: 不是绝对路径", filepath)
	end

	if FileUtilsInstance:writeStringToFile(str, filepath) then
		self:fmtLuaScript(filepath)
		self:autoUpdate(filepath)
	else
		logE("writeStringToFile错误:文件写入失败", filepath)
		logE("str:", str)
		return false
	end
	return true
end

-- 格式化lua代码
function Functions:fmtLuaScript(filepath)
	local fullFilePath = FileUtilsInstance:fullPathForFilename(filepath)
	local fullExePath

	if G_MAC.IS_WINDOWS then
		fullExePath = _MyG.GlobalData.CurExePath .. "res/lua-format/win32/lua-format.exe"
	elseif G_MAC.IS_IOS then
		fullExePath = _MyG.GlobalData.CurExePath .. "res/lua-format/darwin/lua-format"
	else
		return
	end
	fullExePath = FileUtilsInstance:fullPathForFilename(fullExePath)

	if not FileUtilsInstance:isFileExist(fullExePath) then
		logW("File '%s' does not exist", fullExePath)
		return
	end

	local cmd = string.format("%s %q", fullExePath, fullFilePath)
	local subfile = io.popen(cmd, "r")
	if subfile then
		local r = subfile:read("*a")
		subfile:close()
		if type(r) == "string" and r ~= "" then
			logW(r)
		end
	else
		logW("Failed to execute command %q", cmd)
	end
end

function Functions:openMap(fullPath)
	local docName = self:getRelativePath(fullPath)
	if not _MyG.TopDocumentManager:hasDocument(docName) then
    	local context = require("app.document.MapEditContext").new(docName, fullPath)
    	local bgCell = require("app.cell.MapBGCell").new(context)
	
    	context:initWithData(bgCell)
    	context:deserialize(cc.FileUtils:getInstance():getStringFromFile(fullPath))
    	_MyG.TopDocumentManager:addDocument(context)
    else
    	logI(string.format("%q opened", docName))
	end
	_MyG.TopDocumentManager:setCurShowDocumentByName(docName)
end

function Functions:openWidget(fullPath)
	local docName = self:getRelativePath(fullPath)
	if not _MyG.TopDocumentManager:hasDocument(docName) then
    	local context = require("app.document.EditContext").new(docName, fullPath)
    	local bgCell = require("app.cell.LineBGCell").new(context)
	
    	context:initWithData(bgCell)
    	context:deserialize(cc.FileUtils:getInstance():getStringFromFile(fullPath))
    	_MyG.TopDocumentManager:addDocument(context)
    else
    	logI(string.format("%q opened", docName))
	end
	_MyG.TopDocumentManager:setCurShowDocumentByName(docName)
end

function Functions:openLayer(fullPath)
	local docName = self:getRelativePath(fullPath)
	if not _MyG.TopDocumentManager:hasDocument(docName) then
    	local context = require("app.document.LayerEditContext").new(docName, fullPath)
    	local bgCell = require("app.cell.LayerBGCell").new(context)
	
    	context:initWithData(bgCell)
    	context:deserialize(cc.FileUtils:getInstance():getStringFromFile(fullPath))
    	_MyG.TopDocumentManager:addDocument(context)
    else
    	logI(string.format("%q opened", docName))
	end
	_MyG.TopDocumentManager:setCurShowDocumentByName(docName)
end

local drawFunc

function Functions:openImage(fullPath)
	if self.curShowImageWindow_FullPath and self.curShowImageWindow_FullPath == fullPath then
		return
	end

	local textureID = Tools:getImguiTextureID(fullPath)
	if textureID == nil then
		logE("openImage错误:打开文件失败", fullPath)
		return
	end

	self.curShowImageWindow_FullPath = fullPath

	local winSize = Tools:getWindowSize()
	local maxWindW = winSize.width * 0.7
	local maxWindH = winSize.height * 0.7

	local windW = Tools:getImguiTextureWidth(fullPath)
	local windH = Tools:getImguiTextureHeight(fullPath)
	local imageSize = cc.p(windW, windH)
	windW = windW + 40
	windH = windH + 80
	windW = math.max(windW, 100)
	windH = math.max(windH, 100)
	windW = math.min(windW, maxWindW)
	windH = math.min(windH, maxWindH)

	local windSize = cc.p(windW, windH)
	local windPivot = cc.p(0.5, 0.5)
	local windPos = cc.p(winSize.width * 0.5, winSize.height * 0.5)
	local scrolling_size = cc.p(0, 0)

	local showTextureInfo = string.format("%d*%d", windW, windH)

	local flags = 0
	flags = Tools:bor_int32(flags, ImGuiWindowFlags_NoSavedSettings)

	local tmp
	local isShow = true

	if drawFunc then
		G_SysEventEmitter:removeListener("onGUI", drawFunc)
		drawFunc = nil
	end

	drawFunc = function()
		ImGui.SetNextWindowSize(windSize, ImGuiCond_Appearing)
		ImGui.SetNextWindowPos(windPos, ImGuiCond_Appearing, windPivot)
		tmp, isShow = ImGui.Begin("Image", isShow, flags)
			ImGui.BeginChild("scrolling", scrolling_size, false, ImGuiWindowFlags_HorizontalScrollbar)
			ImGui.Text(showTextureInfo)
			ImGui.Image(textureID, imageSize)
			ImGui.EndChild()
		ImGui.End()

		if not isShow then
			G_SysEventEmitter:removeListener("onGUI", drawFunc)
			self.curShowImageWindow_FullPath = nil
			drawFunc = nil
		end
	end
	G_SysEventEmitter:on("onGUI", drawFunc)
end

function Functions:getRelativePath(fullPath)
	if FileUtilsInstance:isAbsolutePath(fullPath) then
		if string.find(fullPath, _MyG.GlobalData.CocosResourcePath) then
			fullPath = Tools:replaceString(fullPath, _MyG.GlobalData.CocosResourcePath, "")
		else
			fullPath = Tools:replaceString(fullPath, _MyG.GlobalData.RootWritePath, "")
		end
	else
		logW("getRelativePath警告:", fullPath, "不是绝对路径")
	end	
	return fullPath
end

function Functions:importResource(filter, rootPath)
	logI(rootPath)
	if type(filter) ~= "string" or type(rootPath) ~= "string" then
		logW("调用Functions:importResource函数时参数不合法")
		return
	end
	if filter == "" or rootPath == "" then
		logW("调用Functions:importResource函数时参数不合法")
		return
	end

	if string.sub(rootPath, -1, -1) ~= "/" then
		rootPath = rootPath .. "/"
	end

	self.loadingFileList = {}
	self.curLoadCount = 0
	self.copyRootPath = rootPath

	local paths = StringArray:new()
	Tools:openFileMultiSelect(filter, paths)
	for i=0,paths:getValueCount() - 1 do
		table.insert(self.loadingFileList, paths:getValueByIndex(i))
	end
	if #self.loadingFileList > 0 then
		self.copyFileFinishCallFunc = function()
			self:stopUpdate()
			self:autoUpdate(rootPath)
		end
		self:startScheduler()
    	_MyG.ShowLoading()
	end
end

function Functions:removeFile(filepath)

	local docName = self:getRelativePath(filepath)
	if _MyG.TopDocumentManager:hasDocument(docName) then
		_MyG.ShowBox(STR("DLG_DEL_FILE_NO_CLOSE"))
		logW(STR("DLG_DEL_FILE_NO_CLOSE"))
		return
	end

	_MyG.ShowBox(STR("DLG_IS_DEL_FILE"), 
	function()
		if FileUtilsInstance:removeFile(filepath) then
			local publishFilePath = _MyG.GlobalData:getPublishPath(filepath)
			if FileUtilsInstance:isFileExist(publishFilePath) then
				if not FileUtilsInstance:removeFile(publishFilePath) then
					logE(STR("FAILE_DEL_PUB_FILE"), publishFilePath)
				end
			end

			self:autoUpdate(filepath)
		else
			logE(STR("FAILE_DEL_FILE"), filepath)
		end
	end,
	function() end)
end

function Functions:isTexture(path)
	if path == nil or path == "" then
		return false
	end
	local fileExtension = FileUtilsInstance:getFileExtension(path)
	if fileExtension == ".png" or 
		fileExtension == ".jpg" or
		fileExtension == ".bmp" then
		return true
	end
	return false
end

-- 发布资源
function Functions:publishResource()
	if self.scriptEntryID_publishResource then
		logW("publish...")
		return
	end

	local pbCo = coroutine.create(function()
		self:publishResourceLogic()
	end)

	local scheduler=cc.Director:getInstance():getScheduler()
	self.scriptEntryID_publishResource = scheduler:scheduleScriptFunc(function()
		if not coroutine.resume(pbCo) then
			scheduler:unscheduleScriptEntry(self.scriptEntryID_publishResource)
			self.scriptEntryID_publishResource = nil
			_MyG.HideLoading()
			logI("publish completed")
		end
	end,1 / 20.0,false)
end

function Functions:publishResourceLogic()
	local function copyFiles(path, srcRootDir, dstDir)
		local tarDir = Tools:replaceString(path, srcRootDir, dstDir)
		if not FileUtilsInstance:isDirectoryExist(tarDir) then
			FileUtilsInstance:createDirectory(tarDir)
		end

		for entry in lfs.dir(path) do  
		    if entry ~= '.' and entry ~= '..' then
		        local path = path .. '/' .. entry  
		        path = G_Helper.fmtPath(path)
		        local attr = lfs.attributes(path)
		        local newPath = Tools:replaceString(path, srcRootDir, dstDir)
				
				if attr.mode == "directory" then
					copyFiles(path, srcRootDir, dstDir)
				else
					local ext = G_Helper.getExtension(path)
					if ext ~= _MyG.GlobalData:getFileExtension("MAP") and
						ext ~= _MyG.GlobalData:getFileExtension("WIDGET") and
						ext ~= _MyG.GlobalData:getFileExtension("LAYER") and
						ext ~= _MyG.GlobalData:getFileExtension("PROJECT") then

						if not Tools:copyFile(path, newPath) then
							logE(string.format("Write file %q failed", newPath))
						else
							print(string.format("Copy %q to %q succeeded", path, newPath))
						end

						coroutine.yield()
						

					end
				end
			end
		end
	end

	local publishDir = _MyG.GlobalData.PublishProjectsPath
	FileUtilsInstance:createDirectory(publishDir)

	copyFiles(_MyG.GlobalData.CommonResourcePath, _MyG.GlobalData.RootWritePath, publishDir)
	copyFiles(_MyG.GlobalData.ProjectsPath, _MyG.GlobalData.RootWritePath, publishDir)
end
------------------------------------------Private
function Functions:copyFileUpdate()
	if self.curLoadCount >= #self.loadingFileList then
		logI("Copy of resources completed")
		if self.copyFileFinishCallFunc == nil then
			self:stopUpdate()
		else
			self.copyFileFinishCallFunc()
			self.copyFileFinishCallFunc = nil
		end
		return
	end

	self.curLoadCount = self.curLoadCount + 1
	local filename = Tools:getFilename(self.loadingFileList[self.curLoadCount])
	
	local f1 = self.loadingFileList[self.curLoadCount]
	local f2 = self.copyRootPath..filename

	if FileUtilsInstance:isFileExist(f2) then
		self:stopScheduler()

		local filename = Tools:getFilename(f2)
		local showText = string.format(STR("FILE_EXIST_FMT"), filename)
		_MyG.ShowBox(showText, 
		function()
			self:doCopy(f1, f2)
			self:startScheduler()
		end, 
		function()
			logI(string.format("Cancel copy of %q file", f1))
			self:startScheduler()
		end)
	else
		self:doCopy(f1, f2)
	end
end

function Functions:doCopy(f1, f2)
	if Tools:copyFile(f1, f2, false) then
		logL(string.format("Copy %q to %q succeeded", f1, f2))
	else
		logW(string.format("Failed to copy %q to %q", f1, f2))
	end
end

function Functions:startScheduler()
	self:stopScheduler()
	local scheduler=cc.Director:getInstance():getScheduler()
	self.scriptEntryID = scheduler:scheduleScriptFunc(function(...) self:copyFileUpdate(...) end,1 / 10.0,false)
end

function Functions:stopScheduler()
	if self.scriptEntryID ~= nil then
		local scheduler=cc.Director:getInstance():getScheduler()
		scheduler:unscheduleScriptEntry(self.scriptEntryID)
	end
	self.scriptEntryID = nil
end

function Functions:stopUpdate()
	self:stopScheduler()
	_MyG.HideLoading()
end

-------------------------------------------------文件保存-------------------------------------------------

function Functions:formatTableToString(t)
    return format_lua_value(t)
end

return Functions
