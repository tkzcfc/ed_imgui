local GlobalData = class("GlobalData")

require "lfs"

local function delExtension(extension)
	if extension == nil or extension == "" then
		error(extension .. "非法")
	end
	local t = string.sub(extension, 1, 1)
	if t == "." then
		t = string.sub(extension, 2, -1)
		return t
	end
	return extension
end

local function file_exists(path)
  local file = io.open(path, "rb")
  if file then file:close() end
  return file ~= nil
end

--全局数据
function GlobalData:ctor()
	self.WorkSpaceDirName = "WorkSpace"
	self.CommonResourceDirName = "Commons"
	self.ProjectsDirName = "Projects"
	self.PublishProjectsDirName = "PublishDir"
	self.CocosResourceDirName = "Cocos"

	self.fileTypeInfo = {}

	self:addFileType("PROJECT", ".proj", ".lua")
	self:addFileType("COCOSTUDIO", ".lua", ".lua")
	self:addFileType("MAP", ".map", ".lua")
	self:addFileType("WIDGET", ".widget", ".lua")
	self:addFileType("LAYER", ".layer", ".lua")

	self.RootWritePath = lfs.currentdir() .. "/" ..self.WorkSpaceDirName.."/"
	self.CommonResourcePath = self.RootWritePath..self.CommonResourceDirName.."/"
	self.ProjectsPath = self.RootWritePath..self.ProjectsDirName.."/"
	self.PublishProjectsPath = lfs.currentdir() .. "/"..self.PublishProjectsDirName.."/"
	self.CocosResourcePath = self.RootWritePath..self.CocosResourceDirName.."/"

	self.RootWritePath = G_Helper.fmtPath(self.RootWritePath)
	self.CommonResourcePath = G_Helper.fmtPath(self.CommonResourcePath)
	self.ProjectsPath = G_Helper.fmtPath(self.ProjectsPath)
	self.PublishProjectsPath = G_Helper.fmtPath(self.PublishProjectsPath)
	self.CocosResourcePath = G_Helper.fmtPath(self.CocosResourcePath)

	--所有工程名称
	self.ProjectNameArr = {}
	self.CurProjectName = nil
	self:initDir()
end

function GlobalData:addFileType(filetype, extension, pushlishExtension)
	if self.fileTypeInfo[filetype] then
		error(filetype .. "重复")
		return
	end

	extension = delExtension(extension)
	pushlishExtension = delExtension(pushlishExtension)

	local t = {}
	t.extension = extension
	t.pushlishExtension = pushlishExtension
	t.filetype = filetype
	self.fileTypeInfo[filetype] = t
end

function GlobalData:getPublishPath(path)
	local ext = G_Helper.getExtension(path)
	for k,v in pairs(self.fileTypeInfo) do
		if v.extension == ext then
			local publishFilePath = Tools:replaceString(path, "." .. ext, "." .. v.pushlishExtension)
			print("publishFilePath", publishFilePath)
			return publishFilePath
		end
	end
	logI("getPublishPath", path, "failed")
	return Tools:replaceString(path, "." .. ext, ".lua")
end

function GlobalData:getFileTypeInfo(filetype)
	return self.fileTypeInfo[filetype]
end

function GlobalData:getFileExtension(filetype)
	return self.fileTypeInfo[filetype].extension
end

function GlobalData:getFileFullExtension(filetype)
	return "." .. self.fileTypeInfo[filetype].extension
end

function GlobalData:getFilePublishFullExtension(filetype)
	return "." .. self.fileTypeInfo[filetype].pushlishExtension
end

function GlobalData:initDir()
	self:createDir(self.RootWritePath)
	self:createDir(self.ProjectsPath)
    self:createDir(self.CommonResourcePath)
    -- self:createDir(self.PublishProjectsPath)
    self:createDir(self.CocosResourcePath)

    local paths = cc.FileUtils:getInstance():getSearchPaths()
    table.insert(paths, self.RootWritePath)
    table.insert(paths, self.CocosResourcePath)
    cc.FileUtils:getInstance():setSearchPaths(paths)

    self:updateProjectList()
end

function GlobalData:updateProjectList()
	--遍历项目录，查找项目
	local rootpath = self.ProjectsPath
	for entry in lfs.dir(rootpath) do  
        if entry ~= '.' and entry ~= '..' then  
            local path = rootpath .. entry
            local attr = lfs.attributes(path)
            if attr.mode == 'directory' then

            	path = G_Helper.fmtPath(path)
            	local dirname = Tools:getFilename(path)
            	local projectFile = path .. "/" .. dirname .. "." .. self:getFileTypeInfo("PROJECT").extension
            	projectFile = G_Helper.fmtPath(projectFile)
            	if file_exists(projectFile) then
            		projectFile = Tools:replaceString(projectFile, self.ProjectsPath, "")
            		table.insert(self.ProjectNameArr, projectFile)
            	else
            		logI("警告:", path .. "是非法工程文件")
            	end

            end
        end  
    end
end

function GlobalData:createDir(dirpath)
	if not cc.FileUtils:getInstance():isDirectoryExist(dirpath) then
		cc.FileUtils:getInstance():createDirectory(dirpath)
	end
end


return GlobalData 


