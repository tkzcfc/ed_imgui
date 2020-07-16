local GlobalData = class("GlobalData")

require "lfs"

local function file_exists(path)
  local file = io.open(path, "rb")
  if file then file:close() end
  return file ~= nil
end

--全局数据
function GlobalData:ctor()
	self.WorkSpaceDirName = "WorkSpace"
	self.ProjectsDirName = "Projects"
	self.CocosResourceDirName = "Cocos"

	self.ProjectExtension = "edproj"

	self.RootWritePath = lfs.currentdir() .. "/" ..self.WorkSpaceDirName.."/"
	self.ProjectsPath = self.RootWritePath..self.ProjectsDirName.."/"
	self.CocosResourcePath = self.RootWritePath..self.CocosResourceDirName.."/"

	self.RootWritePath = G_Helper.fmtPath(self.RootWritePath)
	self.ProjectsPath = G_Helper.fmtPath(self.ProjectsPath)
	self.CocosResourcePath = G_Helper.fmtPath(self.CocosResourcePath)

	--所有工程名称
	self.ProjectNameArr = {}
	self:initDir()
end

function GlobalData:getPublishPath(path)
	local publishFilePath = Tools:replaceString(path, ".asset", ".lua")
	return publishFilePath
end

function GlobalData:initDir()
	self:createDir(self.RootWritePath)
	self:createDir(self.ProjectsPath)
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
            	local projectFile = path .. "/" .. dirname .. "." .. self.ProjectExtension
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


