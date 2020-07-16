-- @Author : fangcheng
-- @Date   : 2020-05-11 11:00:00
-- @remark : asset文件导出到lua

require("lfsex")
local json = require("cjson")

local fmtpath = os.fmtpath
local strFmt = string.format

local cacheDir = os.currentdir() .. ".cache/"

-----------------------------------------------------------------------------------

local g_current_file = ""

-----------------------------------------------------------------------------------

local output_content = ""
local function output(line)
	output_content = output_content .. line .. "\n"
end

local function output_fmt(...)
	output(strFmt(...))
end

local function output_begin()
	output_content = "-- Auto Generate, Don't try to modify!\n\n"
end

-- 保留小数点后四位精度
local function fmt_float(float)
	-- return strFmt("%.4f", tonumber(float) or 0)
	return tostring( math.floor(float * 10000 + 0.5) * 0.0001 )
end

local function fmt_require(name)
	name = string.gsub(name, ".asset", "")
	name = string.gsub(name, "/", ".")
	name = string.gsub(name, "\\", ".")
	return name
end

local function fmt_require_lua(name)
	name = string.gsub(name, ".lua", "")
	name = string.gsub(name, "/", ".")
	name = string.gsub(name, "\\", ".")
	return name
end

local function fmt_luafile(filepath)
	local fullExePath = os.currentdir() .. "lua-format/win32/lua-format.exe"

	local cmd = strFmt("%s %q", fullExePath, filepath)
	local subfile = io.popen(cmd, "r")
	if subfile then
		local r = subfile:read("*a")
		subfile:close()
		if type(r) == "string" and r ~= "" then
			logW(r)
		end
	else
		logW(strFmt(STR("EXECUTE_COMMAND_FAILE"), cmd))
	end
end

local function is_empty_table(tb)
	if type(tb) == "table" then
		for k,v in pairs(tb) do
			return false
		end
	end
	return true
end


local M = {}
M.__index = M
------------------------------------------------------------------ public ------------------------------------------------------------------

function M.new(...)
	local t = setmetatable({}, M)
	t:ctor(...)
	return t
end

function M:publish()
	assert(self.projectDir ~= nil)
	assert(self.exportDir ~= nil)

	os.rmdir(self.exportCacheDir)

	if self.projectDir == "" then
		logE(STR("PROJECT_PATH_EMPTY"))
		return
	end

	if not self:seekFile() then
		logE(string.format(STR("TRAVERSE_DIR_FAILED"), tostring(self.projectDir)))
		return		
	end

	if not self:readAll() then
		logE(STR("READ_FILE_FAILED"))
		return
	end

	if not self:checkAll() then
		logE(STR("DETECTION_FILE_FAILED"))
		return
	end

	if not self:exportAll() then
		logE(STR("EXPORT_FILE_FAILED"))
		return
	end

	if not self:copyAll() then
		logE(STR("COPY_FILE_FAILED"))
		return
	end

	os.rmdir(self.exportCacheDir)

	return true
end

------------------------------------------------------------------ private ------------------------------------------------------------------

function M:ctor(projectDir, exportDir)
	self.files = {}
	self.projectDir = os.fmtpath(projectDir, true)
	self.exportDir = os.fmtpath(exportDir, true)
	self.exportCacheDir = cacheDir

	self.publishSucFiles = {}
end

function M:seekFile()
	self.files = {}
	self.copyfiles = {}

	local function doSeek(rootpath)
		local dirs = {}

		rootpath = os.fmtpath(rootpath, true)
    	for entry in lfs.dir(rootpath) do  
    	    if entry ~= '.' and entry ~= '..' then
    	        local path = rootpath .. entry  
    	        local attr = lfs.attributes(path)
	
    	        if attr.mode == "directory" then
    	        	dirs[#dirs + 1] = fmtpath(path)
    	        else
    	        	if string.len(entry) > 6 and string.sub(entry, -6, -1) == ".asset" then
    	        		self.files[#self.files + 1] = fmtpath(path)
    	        	else
    	        		self.copyfiles[#self.copyfiles + 1] = fmtpath(path)
    	        	end
    	        end
    	    end  
    	end

    	for _, v in pairs(dirs) do
    		doSeek(v)
    	end
	end

	doSeek(fmtpath(self.projectDir))

	if #self.files <= 0 then
		logE(STR("DIR_EMPTY_OR_ILLEGAL_PATH"))
		return false
	end
	return true
end

function M:readAll()
	self.cache_fileData = {}
	local noErr = true

	for k,v in pairs(self.files) do
		local ok, content = self:read(v)
		if not ok then
			logE(string.format(STR("PARS_FILE_FAILED"), tostring(v)))
			logE(tostring(content) .. "\n")
			noErr = false
		else
			self.cache_fileData[#self.cache_fileData + 1] = {file = v, content = content, order = k}
		end
	end

	return noErr
end

function M:read(filename)
	filename = tostring(filename)

	local content = os.readfile(filename)

	if content == "" then
		return false, string.format(STR("FILE_IS_EMPTY"), filename)
	end

	local data = nil
	local err = ""
	local ok = xpcall(
	function()
		data = json.decode(content)
	end, 
	function(msg)
		err = tostring(msg) .. tostring(debug.traceback("", 2))
	end)

	if not ok then
		return false, err
	end
	return true, data
end

function M:checkAll()
	local noErr = true
	for k,v in pairs(self.cache_fileData) do
		if not self:check(v) then
			noErr = false
		end
	end
	return noErr
end

function M:check(data)
	local file 		= data.file
	local content 	= data.content

	if not content.data then
		logE(fmt(STR("FIELD_MISS_FORM_FILE"), "data", file))
		return
	end

	local context 	= content.data.context
	if type(context) ~= "table" then
		logE(fmt(STR("FIELD_MISS_FORM_FILE"), "data.context", file))
		return
	end

	local plugin 	= context.plugins
	if type(plugin) ~= "table" then
		logE(fmt(STR("FIELD_MISS_FORM_FILE"), "data.context.plugins", file))
		return
	end

	local children 	= content.data.children
	if type(children) ~= "table" then
		logE(fmt(STR("FIELD_MISS_FORM_FILE"), "data.children", file))
		return
	end

	return true
end

function M:exportAll()
	local noErr = true
	for k,v in pairs(self.cache_fileData) do
		g_current_file = v.file
		if not self:exportToLua(v) then
			logE(fmt(STR("PUBLISH_FILE_FAILED"), v.file))
			noErr = false
		else
			local fullpath = self.exportCacheDir .. string.sub(v.file, #self.projectDir + 1)
			fullpath = string.gsub(fullpath, ".asset", ".lua")
			if not os.writefile(fullpath, output_content) then
				logE(fmt(STR("WRITE_FILE_FAILED"), fullpath))
				logE(fmt(STR("PUBLISH_FILE_FAILED_AND_WRITE"), v.file))
				return false
			else
				table.insert(self.publishSucFiles, fullpath)
				fmt_luafile(fullpath)
				logI(fmt(STR("PUBLISH_FILE_SUCCESS"), v.file))
			end
		end
	end
	return noErr
end

----------------------------------------------------------------------------------------------

function M:exportToLua(data)

	local curType = tostring(data.content.type)
	curType = string.lower(curType)

	if curType == "widget" then
		return self:export_Widget_ToLua(data)
	end

	if curType == "layer" then
		return self:export_Layer_ToLua(data)
	end

	if curType == "map" then
		return self:export_Map_ToLua(data)
	end

	logW(fmt(STR("EXPORT_FILE_FAILED_UNKNOWN_TYPE"), data.file, tostring(curType)))

	return true
end

function M:export_Widget_ToLua(data)
	local file 		= data.file
	local content 	= data.content

	local children 	= content.data.children
	local context 	= content.data.context
	local plugins 	= context.plugins

	output_begin()
	output("local M = {}")
	
	-- loadNode
	output("")
	output("-- 节点加载")
	output("function M:loadNode()")
	output("local _rootNode = cc.Node:create()\n")

	for k,v in pairs(children) do
		self:_fmtToLua_Auto("_rootNode", v)
	end

	output("return _rootNode")
	output("end\n")

	-- plugins
	self:fmt_plugin_Auto(plugins)


	output("return M")

	return true
end

function M:export_Layer_ToLua(data)
	local file 		= data.file
	local content 	= data.content

	local children 	= content.data.children
	local context 	= content.data.context
	local plugins 	= context.plugins

	output_begin()

	output([[
local function copyTable(object)
    local lookup_table = {}
    local function _copy(object)
        if type(object) ~= "table" then
            return object
        elseif lookup_table[object] then
            return lookup_table[object]
        end
        local newObject = {}
        lookup_table[object] = newObject
        for key, value in pairs(object) do
            newObject[_copy(key)] = _copy(value)
        end
        return newObject
    end
    return _copy(object)
end
]])


	output("local M = {}")
	output("M.widgets = {}")
	
	-- loadNode
	output("")
	output("-- 节点加载")
	output("function M:loadNode()")
	output("local _rootNode = cc.Node:create()\n")

	for k,v in pairs(children) do
		self:_fmtToLua_Auto("_rootNode", v)
	end

	output("return _rootNode")
	output("end\n")

	-- 收集所有 widget
	output([[function M:onSpawnWidget(widget)
	self.widgets[#self.widgets + 1] = widget
end
]])

	-- 加载所有 widget的线段和矩形
	output([[function M:loadAllWidgetLine_Rect()
    if self.widget_line_rect_data then return self.widget_line_rect_data end

    local t_lines = {}
    local t_rects = {}
    for k, widget in pairs(self.widgets) do
        local offsetx, offsety = widget:getPosition()
        local luaFileInfo = widget.luaFileInfo
        local lines = copyTable(luaFileInfo.PluginLineRect.line_data)
        local rects = copyTable(luaFileInfo.PluginLineRect.rect_data)

        for _, line in pairs(lines) do
            for __, p in pairs(line.points) do
                p.x = p.x + offsetx
                p.y = p.y + offsety
            end
            t_lines[#t_lines + 1] = line
        end

        for _, rect in pairs(rects) do
            for __, p in pairs(rect.points) do
                p.x = p.x + offsetx
                p.y = p.y + offsety
            end
            t_rects[#t_rects + 1] = rect
        end
    end

    self.widgets = nil

    self.widget_line_rect_data = {}
    self.widget_line_rect_data["line_data"] = t_lines
    self.widget_line_rect_data["rect_data"] = t_rects

    return self.widget_line_rect_data
end
]])

	-- plugins
	self:fmt_plugin_Auto(context.plugins)

	output("return M")

	return true
end

function M:export_Map_ToLua(data)
	local file 		= data.file
	local content 	= data.content or {}

	content.data 	= content.data or {}
	local context 	= content.data.context or {}
	local plugins 	= context.plugins or {}


	local PluginMapLayer = plugins.PluginMapLayer or {}


	output_begin()
	output("local M = {}")


	-- loadBGNode
	output("")
	output("-- 背景节点加载")
	output("function M:loadBGNode()")
	if PluginMapLayer.backgroundAssets and #PluginMapLayer.backgroundAssets > 0 then
		output("local M = {}")
		output("local luafile, node\n")
		for k,v in pairs(PluginMapLayer.backgroundAssets) do
			output_fmt("luafile = require(%q)", fmt_require(v))
			output_fmt("node = luafile:loadNode()")
			output_fmt("node.luaFileInfo = luafile")
			output_fmt("M[#M + 1] = node\n")
		end
		output_fmt("return M")
	end
	output("end\n")

	-- loadGameNode
	output("")
	output("-- 游戏节点加载")
	output("function M:loadGameNode()")
	if PluginMapLayer.gameLayerAsset then
		output_fmt("local luafile = require(%q)", fmt_require(PluginMapLayer.gameLayerAsset))
		output_fmt("local node = luafile:loadNode()")
		output_fmt("node.luaFileInfo = luafile")
		output_fmt("return node")
	end
	output("end\n")

	-- loadFGNode
	output("")
	output("-- 前景节点加载")
	output("function M:loadFGNode()")
	if PluginMapLayer.foregroundAssets and #PluginMapLayer.foregroundAssets > 0 then
		output("local M = {}")
		output("local luafile, node\n")
		for k,v in pairs(PluginMapLayer.backgroundAssets) do
			output_fmt("luafile = require(%q)", fmt_require(v))
			output_fmt("node = luafile:loadNode()")
			output_fmt("node.luaFileInfo = luafile")
			output_fmt("M[#M + 1] = node\n")
		end
		output_fmt("return M")
	end
	output("end\n")

	-- plugins
	self:fmt_plugin_Auto(context.plugins)
	
	output("return M")

	return true
end

----------------------------------------------- element  begin -----------------------------------------------

function M:_fmtToLua_Auto(parentName, data, fullNodeTreePath)
	local curType = data.type
	curType = tostring(curType)
	curType = string.lower(curType)

	fullNodeTreePath = fullNodeTreePath or ""
	if fullNodeTreePath == "" then
		fullNodeTreePath = data.data.name
	else
		fullNodeTreePath = fullNodeTreePath .. "/" .. data.data.name
	end

	if self["fmtToLua_" .. curType] then
		self["fmtToLua_" .. curType](self, parentName, data.data, tostring(data.type), fullNodeTreePath)
		output("")
	end

	for k,v in pairs(data.child) do
		self:_fmtToLua_Auto(data.data.name, v, fullNodeTreePath)
	end
end


function M:fmt_Node(parentName, data, curType, fullNodeTreePath)
	local curName = tostring(data.name)

	if data.anchorPoint then
		if data.anchorPoint.x == 0.5 and data.anchorPoint.y == 0.5 then
		else
			output_fmt("%s:setAnchorPoint(cc.p(%s, %s))", curName, fmt_float(data.anchorPoint.x), fmt_float(data.anchorPoint.y))
		end
	end

	if data.position then
		if data.position.x == 0 and data.position.y == 0 then
		else
			output_fmt("%s:setPosition(%s, %s)", curName, fmt_float(data.position.x), fmt_float(data.position.y))
		end
	end

	if data.rotation and data.rotation ~= 0 then
		output_fmt("%s:setRotation(%s)", curName, fmt_float(data.rotation))
	end

	if data.scaleX and data.scaleX ~= 1 then
		output_fmt("%s:setScaleX(%s)", curName, fmt_float(data.scaleX))
	end

	if data.scaleX and data.scaleY ~= 1 then
		output_fmt("%s:setScaleX(%s)", curName, fmt_float(data.scaleY))
	end

	if data.name then
		output_fmt("%s:setName(\"%s\")", curName, data.name)
	end

	if data.opacity and data.opacity ~= 255 then
		output_fmt("%s:setOpacity(%d)", curName, data.opacity)
	end

	if data.color then
		if data.color.r == 255 and data.color.g == 255 and data.color.b == 255 then
		else
			output_fmt("%s:setColor(cc.c3b(%d, %d, %d))", curName, data.color.r, data.color.g, data.color.b)
		end
	end

	if data.contentSize then
		if data.contentSize.width == 0 and data.contentSize.height == 0 then
		else
			output_fmt("%s:setContentSize(cc.size(%s, %s))", curName, fmt_float(data.contentSize.width), fmt_float(data.contentSize.height))
		end
	end

	if data.aabb then
		output_fmt("%s.aabb = %s", curName, format_lua_value(data.aabb))
	end

	if not is_empty_table(data.userdata) then
		local ud = self:fmt_Userdata(data.userdata, fullNodeTreePath)
		output_fmt("%s.userdata = %s", curName, format_lua_value(ud))
	end

	output_fmt("%s.edType = %q", curName, curType)

	output_fmt("%s:addChild(%s)", parentName, curName)
end

-- widget
function M:fmtToLua_widget(parentName, data, curType, fullNodeTreePath)
	-- "assetFile": "xx.asset",

	local varFileName = string.format("%s_luafile", data.name)
	output_fmt("local %s = require(%q)", varFileName, fmt_require(data.assetFile))
	output_fmt("local %s = %s:loadNode()", data.name, varFileName)
	output_fmt("%s.luaFileInfo = %s", data.name, varFileName)

	self:fmt_Node(parentName, data, curType, fullNodeTreePath)

	output_fmt("self:onSpawnWidget(%s)\n", data.name)
end

-- sprite
function M:fmtToLua_sprite(parentName, data, curType, fullNodeTreePath)
	-- "textureName": "Projects/test/Loading.png",
	-- "plistFileName": "",
	-- "isPlist": false,

	if data.isPlist then
		output_fmt("cc.SpriteFrameCache:getInstance():addSpriteFrames(%q)", data.plistFileName)
		output_fmt("local %s = cc.Sprite:createWithSpriteFrameName(%q)", data.name, data.textureName)
	else
		output_fmt("local %s = cc.Sprite:create(%q)", data.name, data.textureName)
	end

	self:fmt_Node(parentName, data, curType, fullNodeTreePath)
end

-- image
function M:fmtToLua_image(parentName, data, curType, fullNodeTreePath)
	-- "textureName": "Projects/test/Loading.png",
	-- "plistFileName": "",
	-- "isPlist": false,

	if data.isPlist then
		output_fmt("cc.SpriteFrameCache:getInstance():addSpriteFrames(%q)", data.plistFileName)
		output_fmt("local %s = ccui.ImageView:create()", data.name)
		output_fmt("%s:loadTexture(%q, 1)", data.name, data.textureName)
	else
		output_fmt("local %s = ccui.ImageView:create()", data.name)
		output_fmt("%s:loadTexture(%q, 0)", data.name, data.textureName)
	end

	if data.ignoreContent ~= nil then
		if data.ignoreContent then
			output_fmt("%s:ignoreContentAdaptWithSize(true)", data.name)
		else
			output_fmt("%s:ignoreContentAdaptWithSize(false)", data.name)
		end
	end

	self:fmt_Node(parentName, data, curType, fullNodeTreePath)
end

-- -- CocostudioFile
function M:fmtToLua_cocostudiofile(parentName, data, curType, fullNodeTreePath)
	-- "scriptFile": "CustomFile.lua",

	local name_lua = data.name .. "_lua"

	output_fmt("local %s = require('%s')", name_lua, fmt_require_lua(data.scriptFile))

	output_fmt("if %s.animation then", name_lua)
	output_fmt("	%s.animation:gotoFrameAndPlay(0, true)", name_lua)
	output_fmt("	%s.root:runAction(%s.animation)", name_lua, name_lua)
	output_fmt("end")

	output_fmt("local %s = %s.root", data.name, name_lua)

	self:fmt_Node(parentName, data, curType, fullNodeTreePath)
end

----------------------------------------------- plugin  begin -----------------------------------------------

function M:fmt_plugin_Auto(plugins)
	for k,plugin in pairs(plugins or {}) do
		local curFunc = "fmt_plugin_" .. string.lower(k)
		if self[curFunc] then
			self[curFunc](self, plugin, k)
			output("\n")
		else
			logW(fmt(STR("PUB_PLUGIN_FAIL_NO_IMP"), tostring(k)))
		end
	end
end

-- 插件 line_rect
function M:fmt_plugin_pluginlinerect(data, pluginName)
	local lines = {}
	for k, v in pairs(data.line_data or {}) do
		local line = CLine:new_local()
		line:deserialize(v)

		local publishData = line:publish()

		if not is_empty_table(line.userdata) then
			local ud = self:fmt_Userdata(line.userdata, fmt("{0} -> line{1}", pluginName, k))
			publishData.userdata = ud
		else
			publishData.userdata = nil
		end

		lines[#lines + 1] = publishData
	end

	local rects = {}
	for k, v in pairs(data.rect_data or {}) do
		local rect = CRect:new_local()
		rect:deserialize(v)

		local publishData = rect:publish()

		if not is_empty_table(rect.userdata) then
			local ud = self:fmt_Userdata(rect.userdata, fmt("{0} -> line{1}", pluginName, k))
			publishData.userdata = ud
		else
			publishData.userdata = nil
		end

		rects[#rects + 1] = publishData
	end

	local line_data = fmt("M.{0}.line_data = {1}", pluginName, format_lua_value(lines))
	local rect_data = fmt("M.{0}.rect_data = {1}", pluginName, format_lua_value(rects))

	output(fmt("M.{0} = {}", pluginName))
	output(line_data)
	output(rect_data)

	if not is_empty_table(data.userdata) then
		local ud = self:fmt_Userdata(data.userdata, fmt("{0} -> userdata", pluginName))
		output(fmt("M.{0}.userdata = {1}", pluginName, format_lua_value(ud) ))
	end
end

-- 插件 PluginLayerSize
function M:fmt_plugin_pluginlayersize(data, pluginName)
	local out_data = fmt("M.{0}.size = {1}", pluginName, format_lua_value(data.size))
	output(fmt("M.{0} = {}", pluginName))
	output(out_data)

	if not is_empty_table(data.userdata) then
		local ud = self:fmt_Userdata(data.userdata, fmt("{0} -> userdata", pluginName))
		output(fmt("M.{0}.userdata = {1}", pluginName, format_lua_value(ud) ))
	end
end

-- 插件 PluginRevivePoint
function M:fmt_plugin_pluginrevivepoint(data, pluginName)
	local out_data = fmt("M.{0}.revivePoints = {1}", pluginName, format_lua_value(data.revivePoints or {}))
	output(fmt("M.{0} = {}", pluginName))
	output(out_data)

	if not is_empty_table(data.userdata) then
		local ud = self:fmt_Userdata(data.userdata, fmt("{0} -> userdata", pluginName))
		output(fmt("M.{0}.userdata = {1}", pluginName, format_lua_value(ud) ))
	end
end

-- 插件 PluginRefResources
function M:fmt_plugin_pluginrefresources(data, pluginName)
	local out_data = fmt("M.{0}.refResources = {1}", pluginName, format_lua_value(data.refs or {}))
	output(fmt("M.{0} = {}", pluginName))
	output(out_data)

	if not is_empty_table(data.userdata) then
		local ud = self:fmt_Userdata(data.userdata, fmt("{0} -> userdata", pluginName))
		output(fmt("M.{0}.userdata = {1}", pluginName, format_lua_value(ud) ))
	end
end

-- 插件 PluginMapLayer
-- 在 export_Map_ToLua 函数里面已经实现了该插件发布，此处指定义一个空函数避免警告
function M:fmt_plugin_pluginmaplayer(data, pluginName)
end

----------------------------------------------- plugin  end -----------------------------------------------

function M:copyAll()
	local noErr = true

	for k,file in pairs(self.publishSucFiles) do
		local newFile = string.sub(file, #self.exportCacheDir + 1)
		if not os.copyfile(file, self.exportDir .. newFile) then
			noErr = false
			logI(fmt(STR("COPY_FILE_FAILED_FMT"), newFile))
		else
			logI(fmt(STR("COPY_FILE_SUC_FMT"), newFile))
		end
	end

	for k,file in pairs(self.copyfiles) do
		local newFile = string.sub(file, #self.projectDir + 1)
		if not os.copyfile(file, self.exportDir .. newFile) then
			noErr = false
			logI(fmt(STR("COPY_FILE_FAILED_FMT"), newFile))
		else
			logI(fmt(STR("COPY_FILE_SUC_FMT"), newFile))
		end
	end
	return noErr
end

function M:fmt_Userdata(userdata, fullNodeTreePath)
	local loc = g_current_file
	if fullNodeTreePath and fullNodeTreePath ~= "" then
		loc = fmt("{0} : [{1}]", g_current_file, fullNodeTreePath)
	end

	loc = loc .. " -> userdata"

	userdata = userdata or {}

	-- 重复key检查
	local keyCheck = {}
	for k,v in pairs(userdata) do
		if v.name ~= "" then
			if keyCheck[v.name] then
				keyCheck[v.name] = keyCheck[v.name] + 1
			else
				keyCheck[v.name] = 0
			end
		end
	end

	-- 警告重复key
	for k,v in pairs(keyCheck) do
		if v > 0 then
			logW(fmt(STR("UD_DUPLICATE_KEY"), v, loc))
		end
	end

	local ud = {}
	for k,v in pairs(userdata) do
		if v.name == "" then
			logW(fmt(STR("UD_EMPTY_KEY"), loc))
		else
			-- 数字,不支持浮点数， 3.14 这种直接转换为 3
			if tonumber(v.name) then
				local numValue = tonumber(v.name)
				if math.ceil(numValue) ~= math.floor(numValue) then
					logW(fmt(STR("UD_FLOAT_KEY_WARN"), loc, numValue, math.floor(numValue)))
				end
				ud[math.floor(numValue)] = v.data
			-- 字符串
			else
				ud[v.name] = v.data
			end
		end
	end

	return ud
end

return M
