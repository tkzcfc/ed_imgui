local subprocess = require("subprocess")

local Functions = {}


local function Lua_Error_hook(err)
	logE(debug.traceback(err, 3))
end

require "lfs"
local FileDialog = require("app.imgui.FileDialog")
local FileUtilsInstance = cc.FileUtils:getInstance()



local FILE_TMPTY_DATA = {
	children = {},
	context = {
		plugins = {},
	}
}

local FILE_TMPTY_DATA_WIDGET = clone(FILE_TMPTY_DATA)
FILE_TMPTY_DATA_WIDGET.context.plugins = {
	PluginLineRect = {
		rect_data = {},
		line_data = {},
	},
}

local FILE_TMPTY_DATA_LAYER = clone(FILE_TMPTY_DATA)
FILE_TMPTY_DATA_LAYER.context.plugins = {
	PluginLayerSize = {
		size = cc.p(_MyG.Editor_DesignResolution.width, _MyG.Editor_DesignResolution.height),
		color = cc.c4f(0.9, 0, 1, 1),
	}
}


local FILE_TMPTY_DATA_MAP = clone(FILE_TMPTY_DATA)


-- brief 创建工程
function Functions:createProject(name)
	if name == "" then
		return
	end

	for i,v in ipairs(_MyG.GlobalData.ProjectNameArr) do
		if v == name then
			_MyG.ShowBox(STR("PROJECT_EXISTS"))
			return
		end
	end

	local projpath = _MyG.GlobalData.ProjectsPath .. name
	local status = _MyG.EditorProject:createProj(projpath, name)

	if status == 0 then
		_MyG.ShowBox(STR("PROJECT_CREATE_SUCCESS"), function()
			self:openProject(_MyG.EditorProject:assembleProjectFileFullName(projpath, name))
		end)
	elseif status == 1 then
		_MyG.ShowBox(STR("PROJECT_CREATE_FAIL_EXIST"))
	elseif status == 2 then
		_MyG.ShowBox(STR("PROJECT_CREATE_FAIL"))
	end
end

-- @brief 打开工程
function Functions:openProject(projectFileName)
	if _MyG.EditorProject:open(projectFileName) then
	else
		_MyG.ShowBox(STR("PROJECT_OPEN_FAIL"))
	end
end

-- @brief 将lua的table序列化成json并写入文件中
function Functions:writeTableToFile(tab, filePath)
	local success, ok = xpcall(function()
		local content = json.encode(tab)
		content = Tools:prettyJson(content)
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
		logE("writeStringToFile错误:文件写入失败", filePath)
		logE("str:", tostring(content))
		return false
	end
end

function Functions:autoUpdate(path)
	if path == nil then
		G_SysEventEmitter:emit("onAssetContentUpdate")
		return
	end
	if string.find(path, _MyG.GlobalData.CocosResourcePath) then
		-- Cocos资源
		G_SysEventEmitter:emit("onAssetCocosUpdate")
	else
		G_SysEventEmitter:emit("onAssetContentUpdate")
	end
end

function Functions:openAsset(asset, createCall)
	local fullPath = asset:getFilePath()

	local data = asset.assetManager:getAssetData(fullPath)
	if not data then
		logE(string.format("[1]Failed to open resource %q", tostring(fullPath)))
		return
	end

	fullPath = Tools:replaceString(fullPath, ".asset", "." .. data.type)
	local docName = self:getRelativePath(fullPath)

	if _MyG.CenterDocumentManager:hasDocument(docName) then
		_MyG.CenterDocumentManager:setCurShowDocumentByName(docName)
	else
		local context = nil

    	local status = xpcall(function() 
    		context = createCall(docName, data)
		end, Lua_Error_hook)

		if not status or context == nil then
			logE(string.format("[2]Failed to open resource %q", tostring(fullPath)))
			return
		end

		_MyG.CenterDocumentManager:addDocument(context)
		_MyG.CenterDocumentManager:setCurShowDocumentByName(docName)
	end
end

function Functions:openWidget(asset)
	Functions:openAsset(asset, function(docName, data)
		local context = require("app.document.context.EditorWidget").new(docName, asset)
		if context:deserialize(data.data) then
			return context
		end
		context:destroy()
	end)
end

function Functions:openLayer(asset)
	Functions:openAsset(asset, function(docName, data)
		local context = require("app.document.context.EditorLayer").new(docName, asset)
		if context:deserialize(data.data) then
			return context
		end
		context:destroy()
	end)
end

function Functions:openMap(asset)
	Functions:openAsset(asset, function(docName, data)
		local context = require("app.document.context.EditorMap").new(docName, asset)
		if context:deserialize(data.data) then
			return context
		end
		context:destroy()
	end)
end

-- @brief 图片预览
-- @param imgPath 纹理路径
-- @param isPlist 是否是plist文件
-- @param plistFile plist文件名
local openImageDrawFunc = nil
function Functions:openImage(imgPath, isPlist, plistFile)
	if self.curShowImageWindow_FullPath and self.curShowImageWindow_FullPath == imgPath then
		return
	end

	if isPlist then
		cc.SpriteFrameCache:getInstance():addSpriteFrames(plistFile)
	end

	local textureID = Tools:getImguiTextureID(imgPath, isPlist)
	if textureID == nil then
		logE("Failed to get '%s' texture", imgPath)
		return
	end

	self.curShowImageWindow_FullPath = imgPath

	local winSize = Tools:getWindowSize()
	local maxWindW = winSize.width * 0.7
	local maxWindH = winSize.height * 0.7

	local windW = Tools:getImguiTextureWidth(imgPath)
	local windH = Tools:getImguiTextureHeight(imgPath)
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

	if openImageDrawFunc then
		G_SysEventEmitter:removeListener("onGUI", openImageDrawFunc)
		openImageDrawFunc = nil
	end

	openImageDrawFunc = function()
		ImGui.SetNextWindowSize(windSize, ImGuiCond_Appearing)
		ImGui.SetNextWindowPos(windPos, ImGuiCond_Appearing, windPivot)
		tmp, isShow = ImGui.Begin("Image", isShow, flags)
			ImGui.BeginChild("scrolling", scrolling_size, false, ImGuiWindowFlags_HorizontalScrollbar)
			ImGui.Text(showTextureInfo)
			ImGui.Image(textureID, imageSize)
			ImGui.EndChild()
		ImGui.End()

		if not isShow then
			G_SysEventEmitter:removeListener("onGUI", openImageDrawFunc)
			self.curShowImageWindow_FullPath = nil
			openImageDrawFunc = nil
		end
	end
	G_SysEventEmitter:on("onGUI", openImageDrawFunc)
end

-- @brief 文件拷贝
-- @param from 起始地址
-- @param to 目的地址
function Functions:doCopy(from, to)
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

				-- 提示用户是否需要覆盖
				_MyG.ShowBox(showText, 
				function()
					usChoice = 1
				end, 
				function()
					usChoice = 2
					logI(string.format("Cancel copy of %q file", from))
				end)

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

-- @brief 获取相对路径
function Functions:getRelativePath(fullPath)
	if FileUtilsInstance:isAbsolutePath(fullPath) then
		if string.find(fullPath, _MyG.GlobalData.CocosResourcePath) then
			fullPath = Tools:replaceString(fullPath, _MyG.GlobalData.CocosResourcePath, "")
		else
			fullPath = Tools:replaceString(fullPath, _MyG.GlobalData.RootWritePath, "")
		end
	else
		logW(string.format("Calling function getrelativepath parameter '%s' is not an absolute path", tostring(fullPath)))
	end	
	return fullPath
end

-- @brief 移除文件
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

-- @brief 文件夹创建
-- @param rootpath 根目录
-- @param call 回调
function Functions:createFolder(rootpath, call)

	if rootpath == nil or rootpath == "" then
		logE(string.format("Illegal parameter 'rootpath':%q", tostring(rootpath)))
		return
	end

    local newFolderName = ""
    local enter_true, drawfunc

    local createFunc = function(name)
    	print("name", name)
    	-- 用户取消
        if name == nil or name == "" then
			if call then
				call(2)
			end
            return
        end
		rootpath = rootpath .. "/" .. name
		rootpath = G_Helper.fmtPath(rootpath)

		if FileUtilsInstance:createDirectory(rootpath) then
			-- 创建成功
			if call then
				call(0)
			end
		else
			logW(string.format("Failed to create folder %q", tostring(rootpath)))
			_MyG.ShowBox(STR("FOLDER_CREATE_FAIL"))
        	-- 创建失败
			if call then
				call(1)
			end
		end
    end

    drawfunc = function()
        ImGui.OpenPopup("##NewFolder")
        if ImGui.BeginPopupModal("##NewFolder", true, Tools:bor_int32(ImGuiWindowFlags_AlwaysAutoResize, ImGuiWindowFlags_NoMove)) then
            enter_true, newFolderName = Tools:imgui_inputText("Name", newFolderName, 32, ImGuiInputTextFlags_EnterReturnsTrue)
            if enter_true then
                ImGui.CloseCurrentPopup()
                G_SysEventEmitter:removeListener("onGUI", drawfunc)
                createFunc(newFolderName)
            end
            ImGui.Separator()
            if ImGui.Button("OK", cc.p(-1, 0)) then
                ImGui.CloseCurrentPopup()
                G_SysEventEmitter:removeListener("onGUI", drawfunc)
                createFunc(newFolderName)
            end
            ImGui.EndPopup()
        else
            G_SysEventEmitter:removeListener("onGUI", drawfunc)
        end
    end

    G_SysEventEmitter:on("onGUI", drawfunc)
end

-- 创建带输入框的弹窗
function Functions:createDilog(usage, path, callback)
    local dilog = FileDialog.new(STR("Open"), path, usage)

    local drawfunc = function()
        dilog:onGUI()
    end
    G_SysEventEmitter:on("onGUI", drawfunc)

    local okCall = function(value)
        G_SysEventEmitter:removeListener("onGUI", drawfunc)
        if callback then
            callback(value)
        end
    end
    local cancelCall = function()
        G_SysEventEmitter:removeListener("onGUI", drawfunc)
    end

	if _MyG.EditorProject:isValid() then
	    dilog:setPathConstraint(_MyG.EditorProject.projectDirPath)
	else
	    dilog:setPathConstraint(path)
	end

    dilog:open(okCall, cancelCall)

    return dilog
end

-- 资源创建
function Functions:createAsset(path, createCall, finishCall)
    local dilog = Functions:createDilog(FileDialog.FileDialogUsage_SaveFile, path, function(value)
    	if value == nil then
    		return
    	end

    	local data = nil
        if createCall then
        	data = createCall()
        end

        local ret = _MyG.ProjectAssetManager:writeAssetData(value[1].fullPath, data, true)
        if finishCall then
        	finishCall(ret)
        end
    end)
    dilog:addFilter("asset")
    dilog:setCanOverlap(false)
end

-- 地图创建
function Functions:createMap(path, finishCall)
	Functions:createAsset(path, function()
		return {
			type = "map",
			data = FILE_TMPTY_DATA_MAP,
		}
	end, finishCall)
end

-- Widget 创建
function Functions:createWidget(path, finishCall)
	Functions:createAsset(path, function()
		return {
			type = "widget",
			data = FILE_TMPTY_DATA_WIDGET,
		}
	end, finishCall)
end

-- Layer 创建
function Functions:createLayer(path, finishCall)
	Functions:createAsset(path, function()
		return {
			type = "layer",
			data = FILE_TMPTY_DATA_LAYER,
		}
	end, finishCall)
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


-- 发布资源
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
	outputdir = outputdir .. string.gsub(_MyG.EditorProject.projectDirPath, _MyG.GlobalData.RootWritePath, "")
	outputdir = G_Helper.fmtPath(outputdir)

	local cwd = os.currentdir() .. "tools/publish-tool"
	local executable = os.currentdir() .. "tools/publish-tool/publish-tool.exe"
	local projectdir = _MyG.EditorProject.projectDirPath
	local lang = "en"

	if G_LangManager:getLang() == G_LangManager.LANGUAGE.CN then
		lang = "cn"
	end

	print("executable", executable)
	print("executable", projectdir)
	print("executable", outputdir)

	local proc = subprocess.popen({
		executable = executable, 
		executable, 
		projectdir, 
		outputdir, 
		lang,
		stdin = subprocess.PIPE, 
		stdout = subprocess.PIPE, 
		stderr = subprocess.STDOUT,
		cwd = cwd})

	local lines = {}

	logI("publish start--------------------------------------->")

	_MyG.ShowLoading()
	oRoutine(o_loop(function()
		if proc:poll() then
			-- local exitcode = proc.exitcode

			local lines = {}
			local call = nil
			if proc.stdout then
				call = proc.stdout:lines()
			end
			if call then
				while true do
					local line = call()
					if line then
						lines[#lines + 1] = line
					else
						break
					end
				end
			end
			_MyG.HideLoading()
			
			print_lines(lines)
			logI("publish end--------------------------------------->")
			
			return true
		end
	end))
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

return Functions
