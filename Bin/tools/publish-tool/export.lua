-- @Author : fangcheng
-- @Date   : 2020-05-11 11:00:00
-- @remark : asset文件导出到lua

require("lfsex")

local json = require("cjson")

local strFmt = string.format


----------------------------------------------------------------- 工具方法 -----------------------------------------------------------------

-- @brief 格式化lua文件
local function fmt_luafile(filepath)
	-- logI("fmt_luafile---------->>", filepath)
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


local M = {}
M.__index = M
------------------------------------------------------------------ public ------------------------------------------------------------------

function M.new(...)
	local t = setmetatable({}, M)
	t:ctor(...)
	return t
end

function M:ctor(projectDir, exportDir, copyResource)
	-- 要发布的项目目录
	self.projectDir 	= os.fmtpath(projectDir, true)
	-- 发布目录
	self.exportDir 		= os.fmtpath(exportDir, true)
	-- 发布缓存目录
	self.exportCacheDir = os.currentdir() .. ".cache/"

	-- 是否拷贝其他资源到发布路径去
	self.copyResource = copyResource

	-- 项目名称
	self.projectName = string.match(self.projectDir, "([^/\\]*)[/\\]*$")
	self.projectName = self.projectName or ""

	-- 所有的asset文件
	self.allAssetFiles = {}
	-- 除了asset文件之外的其他文件
	self.allOtherFiles = {}

	-- 当前正在执行发布的文件
	self.current_file = ""
	-- 当前文件发布生成的内容
	self.output_content = ""
end

-- @brief 开始发布
function M:publish()
	assert(self.projectDir ~= nil)
	assert(self.exportDir ~= nil)

	os.rmdir(self.exportCacheDir)

	if self.projectDir == "" then
		logE(STR("PROJECT_PATH_EMPTY"))
		return
	end

	-- 文件查找
	if not self:seekFile() then
		logE(strFmt(STR("TRAVERSE_DIR_FAILED"), tostring(self.projectDir)))
		return		
	end

	if self:check_error() then return end

	-- 文件内容读取
	if not self:readAll() then
		logE(STR("READ_FILE_FAILED"))
		return
	end

	if self:check_error() then return end

	-- 文件内容检查
	if not self:checkAll() then
		logE(STR("DETECTION_FILE_FAILED"))
		return
	end
	
	if self:check_error() then return end

	-- 文件导出
	if not self:exportAll() then
		logE(STR("EXPORT_FILE_FAILED"))
		return
	end
	
	if self:check_error() then return end

	-- 拷贝文件
	if not self:copyAll() then
		logE(STR("COPY_FILE_FAILED"))
		return
	end
	
	if self:check_error() then return end

	-- 清空缓存目录
	os.rmdir(self.exportCacheDir)

	return true
end

function M:check_error()
	if G_HasError then
		os.rmdir(self.exportCacheDir)		
		return true
	end
	return false
end

------------------------------------------------------------------ private ------------------------------------------------------------------

-- @brief 查找工作目录下的所有文件并将其归类
function M:seekFile()
	local list = os.seek_dir(self.projectDir, true)

	for k, v in pairs(list) do
		if not v.isdir then
			local path = v.path
			if string.len(path) > 6 and string.sub(path, -6, -1) == ".asset" then
        		self.allAssetFiles[#self.allAssetFiles + 1] = path
        	else
        		self.allOtherFiles[#self.allOtherFiles + 1] = path
        	end
		end
	end

	if #self.allAssetFiles <= 0 and #self.allOtherFiles <= 0 then
		logE(STR("DIR_EMPTY_OR_ILLEGAL_PATH"))
		return false
	end
	return true
end

-- @brief 读取所有assert文件内容,并转换为table类型格式
function M:readAll()
	self.cache_AssetFileData = {}
	local noErr = true

	for k,v in pairs(self.allAssetFiles) do
		local ok, content = self:read(v)
		if not ok then
			logE(strFmt(STR("PARS_FILE_FAILED"), tostring(v)))
			logE(tostring(content) .. "\n")
			noErr = false
		else
			self.cache_AssetFileData[#self.cache_AssetFileData + 1] = {file = v, content = content, order = k}
		end
	end

	return noErr
end

-- @brief 读取文件并将内容装换为table类型格式
function M:read(filename)
	filename = tostring(filename)

	local content = os.readfile(filename)

	if content == "" then
		return false, strFmt(STR("FILE_IS_EMPTY"), filename)
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

-- @brief 检查所有内容
function M:checkAll()
	local noErr = true
	for k,v in pairs(self.cache_AssetFileData) do
		if not self:check(v) then
			noErr = false
		end
	end
	return noErr
end

-- @brief 内容检查，可自定义检查规则
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

-- @brief 获取输出文件
-- @param assetFile asset文件路径
-- @param newExtension 输出文件扩展名
function M:getOutputFile(assetFile, newExtension)
	local fullpath = self.exportCacheDir .. string.sub(assetFile, #self.projectDir + 1)
	fullpath = string.gsub(fullpath, ".asset", newExtension)
	return fullpath
end

-- @brief 禁用自动输出到lua文件
function M:disableAutoWriteToLua()
	self.disableAutoWriteToLuaTag = true
end

-- @brief 导出所有文件
function M:exportAll()
	local noErr = true
	for k,v in pairs(self.cache_AssetFileData) do

		-- 当前文件
		self.current_file = v.file
		-- 默认启用
		self.disableAutoWriteToLuaTag = false

		if not self:exportToLua(v) then
			logE(fmt(STR("PUBLISH_FILE_FAILED"), v.file))
			noErr = false
		else
			if not self.disableAutoWriteToLuaTag then
				local fullpath = self:getOutputFile(v.file, ".lua")
				if not os.writefile(fullpath, self.output_content) then
					logE(fmt(STR("WRITE_FILE_FAILED"), fullpath))
					logE(fmt(STR("PUBLISH_FILE_FAILED_AND_WRITE"), v.file))
					return false
				else
					fmt_luafile(fullpath)
					-- logI(fmt(STR("PUBLISH_FILE_SUCCESS"), v.file))
				end
			end
		end
	end
	return noErr
end

-- @brief 拷贝所有文件到目标目录
function M:copyAll()
	local noErr = true

	-- 拷贝发布后的资源
	local list = os.seek_dir(self.exportCacheDir, true)
	for k, v in pairs(list) do
		if not v.isdir then
			local file = v.path
			local newFile = string.sub(file, #self.exportCacheDir + 1)

			-- 使用rename移动文件
			local USE_RENAME = false

			if USE_RENAME then
				os.remove(self.exportDir .. newFile)
				if not os.movefile(file, self.exportDir .. newFile) then
					noErr = false
					logE(fmt(STR("COPY_FILE_FAILED_FMT"), newFile))
				end
			else
				if not os.copyfile(file, self.exportDir .. newFile) then
					noErr = false
					logE(fmt(STR("COPY_FILE_FAILED_FMT"), newFile))
				end
			end
		end
	end

	-- 不拷贝其他资源
	if not self.copyResource then return noErr end

	local file_edproj = self.projectName .. ".edproj"
	local file_udf = self.projectName .. ".udf"

	-- 拷贝其他文件到发布目录
	for k,file in pairs(self.allOtherFiles) do
		local clearFileName = string.match(file, "([^/\\]-)$")
		if clearFileName == file_edproj or clearFileName == file_udf then
			-- 编辑器相关的文件，忽略
		else
			local newFile = string.sub(file, #self.projectDir + 1)
			if not os.copyfile(file, self.exportDir .. newFile) then
				noErr = false
				logE(fmt(STR("COPY_FILE_FAILED_FMT"), newFile))
			else
				-- logI(fmt(STR("COPY_FILE_SUC_FMT"), newFile))
			end
		end
	end
	return noErr
end

------------------------------------------------------------------------------------------------------------------------

function M:output_begin()
	self.output_content = "-- Auto Generate, Don't try to modify!\n\n"
end

function M:output_end()
end

function M:output(line)
	self.output_content = self.output_content .. line .. "\n"
end

function M:output_fmt(...)
	self:output(strFmt(...))
end

------------------------------------------------------------------------------------------------------------------------

require("export_impl.export")(M)

return M
