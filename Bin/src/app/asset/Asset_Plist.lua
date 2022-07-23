-- @Author: fangcheng
-- @Date:   2020-06-22 22:22:47
-- @remark: 

local Asset = import(".Asset")
local Asset_File = import(".Asset_File")
local Asset_PlistSub = import(".Asset_PlistSub")
local Asset_Plist = class("Asset_Plist", Asset_File)

local parseHook = nil

local FileUtilsInstance = cc.FileUtils:getInstance()

function Asset_Plist:init(fullPath)
	Asset_Plist.super.init(self, fullPath)

	self.property.showName = G_Helper.getLastName(fullPath)
	
	self.property.extension 		= ""
	self.property.showFolderMode 	= true
	self.property.thumbnailTexture 		= EditorIconContent:get(EditorIcon.THUMBNAIL_PLIST)
	self.property.resType 			= Asset.ResType.PLIST

	self.property.isOpenFolder = self.assetManager:getOpenFolderStatus(self)
end

function Asset_Plist:_doSeek()
	local fullPath = self.property.fullPath
	-- local relativePath = self.property.relativePath

	local frames = Tools:splitPlist(fullPath)

	for i = 1, #frames do
		local frame = frames[i]
		self:addSubAsset(Asset_PlistSub.new(fullPath, frame, self.assetManager))
	end
end

return Asset_Plist
