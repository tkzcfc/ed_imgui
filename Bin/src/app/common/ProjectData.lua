local ProjectData = class("ProjectData")

require "lfs"

--当前工程数据
function ProjectData:ctor()
	--资源路径
	self.projectResourceArr = {}
	self.validtag = false

	G_SysEventEmitter:on("onOpenProject", function(projectFullName)
		self:readProjectFile(projectFullName)
	end)
end

function ProjectData:readProjectFile(projectFullName)
	if self.projectFullName == projectFullName then
		logI("工程已打开")
		return
	end
	local name = Tools:getFilename(projectFullName)
	local ext = cc.FileUtils:getInstance():getFileExtension(projectFullName)

	self.projectDirPath = Tools:replaceString(projectFullName, name, "")
	self.projectName = Tools:replaceString(name, ext, "")
	self.projectFileName = name
	self.projectFullName = projectFullName
	G_SysEventEmitter:emit("onAssetContentUpdate", self.projectDirPath)

	self.validtag = true
end

function ProjectData:isValid()
	return self.validtag
end

return ProjectData

