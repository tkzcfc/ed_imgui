-- local subprocess = require("subprocess")

local Functions = {}


local function Lua_Error_hook(err)
	logE(debug.traceback(err, 3))
end

require "lfs"
local FileDialog = require("app.imgui.FileDialog")
local FileUtilsInstance = cc.FileUtils:getInstance()

-- brief 创建工程
function Functions:createProject(name)
	if name == "" then
		return
	end

	for i,v in ipairs(_MyG.GlobalData.ProjectNameArr) do
		if v == name then
			_MyG.ShowTipBox(STR("PROJECT_EXISTS"))
			return
		end
	end

	local projpath = _MyG.GlobalData.ProjectsPath .. name
	local status = _MyG.EditorProject:createProj(projpath, name)

	if status == 0 then
		_MyG.ShowTipBox(STR("PROJECT_CREATE_SUCCESS"), function()
			self:openProject(_MyG.EditorProject:assembleProjectFileFullName(projpath, name))
		end)
	elseif status == 1 then
		_MyG.ShowTipBox(STR("PROJECT_CREATE_FAIL_EXIST"))
	elseif status == 2 then
		_MyG.ShowTipBox(STR("PROJECT_CREATE_FAIL"))
	end
end

-- @brief 打开工程
function Functions:openProject(projectFileName)
	if _MyG.EditorProject:getProFilePath() == projectFileName then
		logI("Project opened")
		return 
	end

	local function processCallback(taskPercent, totalPercent)
		_MyG:PercentLoading(totalPercent)
	end

	local function finishCallback()
		_MyG:HideLoading()
	end
	
	local function errorCallback(msg)
		logE(msg)
		_MyG:HideLoading()
		_MyG.ShowTipBox(STR("PROJECT_OPEN_FAIL"))
	end

	local pipe = G_Class.TaskFlowPipe.new()
	pipe:pushTask(require("app.task.TaskOpenProject").new(projectFileName))
	pipe:pushTask(require("app.task.TaskUpdateAsset").new(projectFileName))
	pipe:start(processCallback, finishCallback, errorCallback)

	_MyG.ShowLoading()
end

-- @brief 将lua的table序列化成json并写入文件中
function Functions:writeTableToFile(tab, filePath)
	local success, ok = xpcall(function()
		local content = Functions:encodeJson(tab)
		-- content = Tools:prettyJson(content)
		if not Functions:writeToFile(content, filePath) then
			logE(string.format("Failed to write file %q", tostring(filePath)))
			return false
		end
		return true
	end, Lua_Error_hook)

	return success and ok
end

-- @brief 写入字符串到文件中
function Functions:writeToFile(content, filePath)
	if FileUtilsInstance:writeStringToFile(content, filePath) then
		return true
	else
		logE("write string to file failed", filePath)
		logE("str:", tostring(content))
		return false
	end
end

function Functions:autoUpdate(path)
	if path == nil then
		G_SysEventEmitter:emit(SysEvent.ON_ASSET_CONTENT_UPDATE)
		return
	end
	if string.find(path, _MyG.GlobalData.CocosResourcePath) then
		-- Cocos资源
		G_SysEventEmitter:emit(SysEvent.ON_ASSET_COCOS_UPDATE)
	else
		G_SysEventEmitter:emit(SysEvent.ON_ASSET_CONTENT_UPDATE)
	end
end

-- @brief 文件拷贝
-- @param from 起始地址
-- @param to 目的地址
function Functions:doCopy(from, to)
	from = G_Helper.fmtPath(from)
	if Tools:copyFile(from, to, false) then
		logL(string.format("Copy %q to %q succeeded", from, to))
	else
		logW(string.format("Failed to copy %q to %q", from, to))
	end
end

-- @brief 导入资源
-- @param filter 过滤器
-- @param toDir 导入目录
-- @param finishCall 完成回调
function Functions:importResource(filter, toDir, finishCall)
	if type(filter) ~= "string" or type(toDir) ~= "string" then
		logW("调用Functions:importResource函数时参数不合法")
		return
	end
	if filter == "" or toDir == "" then
		logW("调用Functions:importResource函数时参数不合法")
		return
	end

	if string.sub(toDir, -1, -1) ~= "/" then
		toDir = toDir .. "/"
	end

	local paths = StringArray:new()
	Tools:openFileMultiSelect(filter, paths)

	_MyG.ShowLoading()

	oRoutine(o_once(function()
		local loadingFileList = {}
		for i=0,paths:getValueCount() - 1 do
			loadingFileList[#loadingFileList + 1] = paths:getValueByIndex(i)
		end
		paths:delete()

		for k, v in pairs(loadingFileList) do
			local filename = Tools:getFilename(v)

			local from = v
			local to = toDir .. filename

			-- 判断文件是否存在
			if FileUtilsInstance:isFileExist(to) then

				local usChoice = 0
				local showText = string.format(STR("FILE_EXIST_FMT"), filename)

				local function cover()
					usChoice = 1
				end

				local function cancel()
					usChoice = 2
					logI(string.format("Cancel copy of %q file", from))
				end

				-- 提示用户是否需要覆盖
				local msgBox = require("app.imgui.popup.MessageBox").new()
				msgBox:setContent(showText)
				msgBox:addBtn("OK", cover)
				msgBox:addBtn("Cancel", cancel)
				msgBox:setDefaultCloseCall(cancel)
				_MyG.PopupManager:addPopup(msgBox)

				repeat
					if usChoice ~= 0 then
						break
					end
					coroutine.yield()
				until(false)

				-- 覆盖
				if usChoice == 1 then
					self:doCopy(from, to)
				end
			else
				self:doCopy(from, to)
			end
		end

		if finishCall then
			finishCall()
		end
		_MyG.HideLoading()
	end))
end

function Functions:beginWith(str, begin)
	local pos, _ = string.find(str, begin)
	return pos and pos == 1
end

function Functions:beginWithAndSubStr(str, begin)
	local bpos, epos = string.find(str, begin)
	if bpos and bpos == 1 then
		return true, string.sub(str, epos + 1)
	end
end

-- @brief 获取相对路径
function Functions:getRelativePath(fullPath)
	local ok, newPath
	local gameResDir = _MyG.EditorProject:getGameResDir()
	
	if FileUtilsInstance:isAbsolutePath(fullPath) then
		ok, newPath = self:beginWithAndSubStr(fullPath, _MyG.GlobalData.CocosResourcePath)
		if ok then return newPath end
		
		ok, newPath = self:beginWithAndSubStr(fullPath, _MyG.GlobalData.ProjectsPath)
		if ok then return newPath end
		
		ok, newPath = self:beginWithAndSubStr(fullPath, gameResDir)
		if ok then return newPath end
	else
		ok, newPath = self:beginWithAndSubStr(fullPath, gameResDir)
		if ok then return newPath end
		
		logW(string.format("Calling function getrelativepath parameter '%s' is not an absolute path", tostring(fullPath)))
	end	
	return fullPath
end

-- @brief 移除文件
function Functions:removeFile(filepath)

	local docName = self:getRelativePath(filepath)
	if _MyG.TopDocumentManager:hasDocument(docName) then
		_MyG.ShowTipBox(STR("DLG_DEL_FILE_NO_CLOSE"))
		logW(STR("DLG_DEL_FILE_NO_CLOSE"))
		return
	end


	local function okCall()
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
	end

	-- 提示是否删除文件
	local msgBox = require("app.imgui.popup.MessageBox").new()
	msgBox:setContent(STR("DLG_IS_DEL_FILE"))
	msgBox:addBtn("OK", okCall)
	msgBox:addBtn("Cancel")
	_MyG.PopupManager:addPopup(msgBox)
end

-- @brief 文件夹创建
-- @param rootpath 根目录
-- @param call 回调
function Functions:createFolder(rootpath, call)

	if rootpath == nil or rootpath == "" then
		logE(string.format("Illegal parameter 'rootpath':%q", tostring(rootpath)))
		return
	end

    local input = require("app.imgui.popup.InputText").new()
	input:setDefaultCloseCall(function()
    	print("cancel")
		-- 用户取消
		call(2)
	end)
	input:setInputTextCallback(function(name)
    	print("name", name)
    	-- 用户取消
        if name == "" then
			if call then
				call(2)
			end
            return
        end
		rootpath = rootpath .. "/" .. name
		rootpath = G_Helper.fmtPath(rootpath)

		if FileUtilsInstance:isDirectoryExist(rootpath) then
			_MyG.ShowTipBox(STR("DIR_EXIST"))
			-- 文件夹已存在
			if call then
				call(1)
			end
			return
		end

		if FileUtilsInstance:createDirectory(rootpath) then
			-- 创建成功
			if call then
				call(0)
			end
		else
			logW(string.format("Failed to create folder %q", tostring(rootpath)))
			_MyG.ShowTipBox(STR("FOLDER_CREATE_FAIL"))
        	-- 创建失败
			if call then
				call(1)
			end
		end
    end)
    _MyG.PopupManager:addPopup(input)
end

-- 创建带输入框的弹窗
function Functions:createDilog(usage, path, callback)
    local dilog = FileDialog.new(STR("Open"), path, usage)

    local handler = G_SysEventEmitter:on(SysEvent.ON_GUI, function()
        dilog:onGUI()
    end, SysEvent.TAG)

    local okCall = function(value)
        G_SysEventEmitter:off(handler)
        if callback then
            callback(value)
        end
    end
    local cancelCall = function()
        G_SysEventEmitter:off(handler)
    end

	if _MyG.EditorProject:isValid() then
	    dilog:setPathConstraint(_MyG.EditorProject.projectDirPath)
	else
	    dilog:setPathConstraint(path)
	end

    dilog:open(okCall, cancelCall)

    return dilog
end

function Functions:isFileExist(filepath)
	if filepath == nil or filepath == "" then
		return false
	end
	return FileUtilsInstance:isFileExist(filepath)
end

-- 获取asset
function Functions:getAssetByID(id)
	id = tonumber(id)

	if id then
		local asset = _MyG.ProjectAssetManager:get(id)
		if asset == nil then
			asset = _MyG.CocosAssetManager:get(id)
		end
		if asset == nil then
			asset = _MyG.GameAssetManager:get(id)
		end
		return asset
	end
end

local function print_lines(lines)
	local logTagI = "[Info]"
	local logTagW = "[Warning]"
	local logTagE = "[Error]"
	
	local lineInfo = {}
	for k, v in ipairs(lines) do
	    local t = {}
	    
	    if string.sub(v, 1, #logTagI) == logTagI then
	        t.level = 0
	        t.content = string.sub(v, #logTagI + 1)
	    elseif string.sub(v, 1, #logTagW) == logTagW then
	        t.level = 1
	        t.content = string.sub(v, #logTagW + 1)
	    elseif string.sub(v, 1, #logTagE) == logTagE then
	        t.level = 2
	        t.content = string.sub(v, #logTagE + 1)
	    else
	        if #lineInfo > 0 then
	            t.level = lineInfo[#lineInfo].level
	        else
	            t.level = 0
	        end
	        t.content = v
	    end
	
	    lineInfo[#lineInfo + 1] = t
	end
	
	for k,v in pairs(lineInfo) do
	    local level = v.level
	    if level == 0 then
	        logI(v.content)
	    elseif level == 1 then
	        logW(v.content)
	    elseif level == 2 then
	        logE(v.content)
	    end
	end
end


-- @brief  工程发布
--  使用 CProcess 新的进程管理
function Functions:publishResource()
	if not _MyG.EditorProject:isValid() then
		return
	end

	local edConfig = _MyG.EditorProject.config
	edConfig.publishDir = edConfig.publishDir or ""
	if edConfig.publishDir == "" then
		logE(STR("PUBLISH_PATH_EMPTY"))
		return
	end

	local outputdir = edConfig.publishDir

	if not FileUtilsInstance:isAbsolutePath(edConfig.publishDir) then
		outputdir = os.currentdir() .. edConfig.publishDir
	end

	outputdir = outputdir .. "/"
	outputdir = outputdir .. _MyG.EditorProject.projectNme
	outputdir = G_Helper.fmtPath(outputdir)

	local cwd = os.currentdir() .. "tools/publish-tool"
	local executable = os.currentdir() .. "tools/publish-tool/publish-tool.exe"
	local projectdir = _MyG.EditorProject.projectDirPath
	local lang = "en"

	if G_LangManager:getLang() == G_LangManager.LANGUAGE.CN then
		lang = "cn"
	end

	local copyResource = ""
	if edConfig.isPublishResource then
		copyResource = "copyResource"
	end

	print("executable", executable)
	print("projectdir", projectdir)
	print("outputdir", outputdir)

	local command = string.format("%s %s %s %s %s", executable, projectdir, outputdir, lang, copyResource)
	local outputData = ""

	logW(command)

	local pPublish = CProcess:new_local()
	pPublish:registerLuaHandle("read_stdout", function(data)
		outputData = outputData .. data
	end)
	pPublish:registerLuaHandle("read_stderr", function(data)
	    logE(data)
	end)
	pPublish:start(command, cwd)

	logI("publish start--------------------------------------->")
    oRoutine(o_loop(function()
        local ret, exit_status = pPublish:try_get_exit_status(1)
        if ret then
			-- 等待read_stdout函数全部返回
			o_wait(o_seconds(0.5))
			print_lines(string.split(outputData, "\n"))
			_MyG.HideLoading()
			logI("publish end--------------------------------------->", exit_status)
            pPublish = nil
            return true
        end
    end))

	-- local proc = subprocess.popen({
	-- 	executable = executable, 
	-- 	executable, 
	-- 	projectdir, 
	-- 	outputdir, 
	-- 	lang,
	-- 	stdin = subprocess.PIPE, 
	-- 	stdout = subprocess.PIPE, 
	-- 	stderr = subprocess.STDOUT,
	-- 	cwd = cwd})

	-- local lines = {}

	-- logI("publish start--------------------------------------->")

	-- _MyG.ShowLoading()
	-- oRoutine(o_loop(function()
	-- 	if proc:poll() then
	-- 		-- local exitcode = proc.exitcode

	-- 		local lines = {}
	-- 		local call = nil
	-- 		if proc.stdout then
	-- 			call = proc.stdout:lines()
	-- 		end
	-- 		if call then
	-- 			while true do
	-- 				local line = call()
	-- 				if line then
	-- 					lines[#lines + 1] = line
	-- 				else
	-- 					break
	-- 				end
	-- 			end
	-- 		end
	-- 		_MyG.HideLoading()
			
	-- 		print_lines(lines)
	-- 		logI("publish end--------------------------------------->")
			
	-- 		return true
	-- 	end
	-- end))
end

function Functions:onGUI_UserData(target, onBeforeValueChange)
	target.userdata = target.userdata or {}

	local userdata = target.userdata
	local deleteIndex = nil
	local retTmp, newData

	local contentRegionAvailX = ImGui.GetContentRegionAvail().x

	-- "int", "bool", "string", "float"
	for k,v in pairs(userdata) do
		ImGui.PushID(tostring(k))

		-------------------------------------------------------- type name --------------------------------------------------------

		ImGui.SetNextItemWidth(70)
		newData = Tools:imguiComboUserdata("##combo_userdata" .. k, v.type)
		if newData ~= v.type then
			if onBeforeValueChange then
				onBeforeValueChange()
			end
			v.type = newData
			if v.type == 0 then -- int
				v.data = 0
			elseif v.type == 1 then -- bool
				v.data = true
			elseif v.type == 2 then -- string
				v.data = ""
			elseif v.type == 3 then -- float
				v.data = 0
			end
		end

		ImGui.SameLine()
		Tools:helpMarker("Varname")
		ImGui.SameLine()

		v.name = v.name or ""
		ImGui.SetNextItemWidth(-1)
		retTmp, newData = Tools:imgui_inputText("##Parameter", v.name, 512)
		if newData ~= v.name then
			if onBeforeValueChange then
				onBeforeValueChange()
			end
			v.name = newData
		end

		-------------------------------------------------------- data --------------------------------------------------------
		newData = v.data

		ImGui.SetNextItemWidth(contentRegionAvailX - 30)
		if v.type == 0 then -- int
			retTmp, newData = ImGui.InputInt("##input_userdata_int" .. k, v.data)
		elseif v.type == 1 then -- bool
			newData = Tools:imguiComboBool("##input_userdata_bool" .. k, v.data)
			retTmp = newData ~= v.data
		elseif v.type == 2 then -- string
			retTmp, newData = Tools:imgui_inputText("##input_userdata_string" .. k, v.data, 512)
		elseif v.type == 3 then -- float
			retTmp, newData = ImGui.InputFloat("##input_userdata_float" .. k, v.data)
		end

		if retTmp then
			if onBeforeValueChange then
				onBeforeValueChange()
			end
			v.data = newData
		end

		ImGui.SameLine()
		if ImGui.SmallButton("x##userdata_remove") then
			deleteIndex = k
		end

		ImGui.NewLine()
		ImGui.PopID()
	end

	if deleteIndex ~= nil then
		if onBeforeValueChange then
			onBeforeValueChange()
		end
		table.remove(userdata, deleteIndex)
	end

	if ImGui.SmallButton("+##userdata_add") then
		if onBeforeValueChange then
			onBeforeValueChange()
		end
		table.insert(userdata, {type = 0, data = 0})
	end
end

-- @brief 通过asset文件序列化成json数据
function Functions:getJsonDataByAssetFile(filename)
	-- 解析json
	local jsonData = nil
	local suc = xpcall(function()
		local FileUtilsInstance = cc.FileUtils:getInstance()
		local content = FileUtilsInstance:getStringFromFile(filename)
		if content == "" then
			jsonData = {}
		else
			jsonData = self:decodeJson(content)
		end
	end, Lua_Error_hook)

	if not suc then
		logE("Deserializing JSON failed", filename)
	end

	return suc, jsonData
end

-- @brief 通过asset文件获取对应资源引用
function Functions:getFileRefResources(filename)
	local ok, jsonData = self:getJsonDataByAssetFile(filename)

	if not ok then
		return {}
	end

	return self:getRefResourcesByAssetJsonData(jsonData)
end

-- @brief 通过asset资源的json数据获取对应的资源引用
function Functions:getRefResourcesByAssetJsonData(jsonData)
	if not jsonData or not jsonData.data then
		return {}
	end

	if jsonData.data.context and jsonData.data.context.plugins then
		local pluginData = jsonData.data.context.plugins.PluginRefResources or {}
		return pluginData.refs or {}
	end
	return {}
end

local cjson = require("cjson")
function Functions:encodeJson(data)
    return cjson.encode(data)
end

function Functions:decodeJson(content)
    return cjson.decode(content)
end

return Functions
