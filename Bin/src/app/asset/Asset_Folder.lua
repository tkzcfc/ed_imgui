-- @Author: fangcheng
-- @Date:   2020-04-11 10:20:23
-- @Description: 

local FileDialog = require("app.imgui.FileDialog")

local Asset = import(".Asset")
local Asset_File = import(".Asset_File")
local Asset_Png = import(".Asset_Png")
local Asset_Jpg = import(".Asset_Jpg")
local Asset_Widget = import(".Asset_Widget")
local Asset_Layer = import(".Asset_Layer")
local Asset_Map = import(".Asset_Map")
local Asset_Lua = import(".Asset_Lua")
local Asset_Plist = import(".Asset_Plist")
local Asset_ExportJson = import(".Asset_ExportJson")
local Asset_Spine = import(".Asset_Spine")
local Asset_Role = import(".Asset_Role")

local Asset_Folder = class("Asset_Folder", Asset_File)

local parseHook = nil
local FileUtilsInstance = cc.FileUtils:getInstance()


function Asset_Folder:init(fullPath)
	Asset_Folder.super.init(self, fullPath)

	self.ignoreList = {}

	fullPath = G_Helper.getClearDirPath(fullPath)
	self.property.fullPath = fullPath .. "/"
	self.property.showName = G_Helper.getLastName(fullPath)
	
	self.property.extension 		= ""
	self.property.showFolderMode 	= true
	self.property.thumbnailTexture 		= EditorIconContent:get(EditorIcon.ICON_FOLDER)
	self.property.resType 			= Asset.ResType.FOLDER

	self.property.isOpenFolder = self.assetManager:getOpenFolderStatus(self)

	Asset_Folder.regParse()
end

function Asset_Folder:_doSeek()
	local fullPath = self.property.fullPath

	local files = FileDialog.getFiles(fullPath)
	if #files <= 0 then
		return
	end

	for order,fileInfo in pairs(files) do
		fileInfo.order = order
	end

	table.sort(files, function(a, b)
		if a.isDir and b.isDir then
			return a.order < b.order
		end
		if not a.isDir and not b.isDir then
			return a.order < b.order
		end
		if a.isDir then
			return true
		end
		return false
	end)

	for _,fileInfo in pairs(files) do
		if fileInfo.isDir then
			self:addSubAsset(Asset_Folder.new(fileInfo.fullPath, self.assetManager))
		else
			local extension = G_Helper.getExtension(fileInfo.fullPath)
			self:doParseAsset(extension, fileInfo)
		end
	end
end

-- @brief 解析
function Asset_Folder:doParseAsset(extension, fileInfo)
	if self:isIgnoreFile(fileInfo.fullPath) then return end

	for k,v in pairs(parseHook) do
		if v[1] == extension and v[2] then
			v[2](self, fileInfo)
		end
	end
end

function Asset_Folder:isIgnoreFile(fileFullPath)
	for k, v in pairs(self.ignoreList) do
		if fileFullPath == v then
			return true
		end
	end
end

-- @brief 添加到忽略列表中
function Asset_Folder:addIgnore(fileFullPath)
	if self:isIgnoreFile(fileFullPath) then return end
	table.insert(self.ignoreList, fileFullPath)
end

-- @brief 忽略同一目录下的同名文件(效率非常非常非常非常非常低)
-- function Asset_Folder:ignoreSameNameFiles(filePath)
-- 	local dir, name = G_Helper.getFileDir(filePath)
-- 	if dir == nil then return end

-- 	name = G_Helper.getFileClsName(name)

-- 	local files = FileDialog.getFiles(dir)
-- 	for _,fileInfo in pairs(files) do
-- 		if not fileInfo.isDir then
-- 			if filePath ~= fileInfo.fullPath then
-- 				local _, curName = G_Helper.getFileDir(fileInfo.fullPath)
-- 				if curName and name == G_Helper.getFileClsName(curName) then
-- 					self:addIgnore(fileInfo.fullPath)
-- 				end
-- 			end
-- 		end
-- 	end	
-- end

-- @brief 忽略同一目录下的同名文件
function Asset_Folder:ignoreSameNameFilesQuick(filePath, extensions)
	local dir, name = G_Helper.getFileDir(filePath)
	if dir == nil then return end

	name = G_Helper.getFileClsName(name)

	for k, v in pairs(extensions) do
		local file = string.format("%s%s%s", dir, name, v)
		if FileUtilsInstance:isFileExist(file) then
			self:addIgnore(file)
		end
	end
end



function Asset_Folder.regParse()
	if parseHook then
		return
	end

	parseHook = {}

	local function add_reg(t)
		table.insert(parseHook, t)
	end 

	
	add_reg {
		"exportjson",
		function(this, fileInfo)
			this:addSubAsset(Asset_ExportJson.new(fileInfo.fullPath, this.assetManager))
			this:ignoreSameNameFilesQuick(fileInfo.fullPath, {".plist", ".png"})
		end
	}
	
	add_reg {
		"json",
		function(this, fileInfo)
			local atlasFile = string.gsub(fileInfo.fullPath, ".json$", ".atlas")
			if FileUtilsInstance:isFileExist(atlasFile) then
				this:addSubAsset(Asset_Spine.new(fileInfo.fullPath, this.assetManager))
			end
		end
	}
	
	add_reg {
		"bytes",
		function(this, fileInfo)
			local atlasFile = string.gsub(fileInfo.fullPath, ".bytes$", ".atlas")
			if FileUtilsInstance:isFileExist(atlasFile) then
				this:addSubAsset(Asset_Spine.new(fileInfo.fullPath, this.assetManager))
			end
		end
	}

	add_reg {
		"skel",
		function(this, fileInfo)
			local atlasFile = string.gsub(fileInfo.fullPath, ".skel$", ".atlas")
			if FileUtilsInstance:isFileExist(atlasFile) then
				this:addSubAsset(Asset_Spine.new(fileInfo.fullPath, this.assetManager))
			end
		end
	}	

	add_reg {
		"plist",
		function(this, fileInfo)
			local pngFile = string.gsub(fileInfo.fullPath, ".plist$", ".png")
			if FileUtilsInstance:isFileExist(pngFile) then
				this:addSubAsset(Asset_Plist.new(fileInfo.fullPath, this.assetManager))
				this:addIgnore(pngFile)
			end
		end
	}
	
	add_reg {
		"png",
		function(this, fileInfo)
			this:addSubAsset(Asset_Png.new(fileInfo.fullPath, this.assetManager))
		end
	}

	add_reg {
		"jpg",
		function(this, fileInfo)
			this:addSubAsset(Asset_Jpg.new(fileInfo.fullPath, this.assetManager))
		end
	}

	
	add_reg {
		"lua",
		function(this, fileInfo)
			this:addSubAsset(Asset_Lua.new(fileInfo.fullPath, this.assetManager))
		end
	}






	---------------------------------------------------- [.asset] ----------------------------------------------------
	add_reg {
		"asset",
		function(this, fileInfo)
			local info = this.assetManager:getAssetData(fileInfo.fullPath)
			if info and info.type then
				Asset_Folder.doParseAsset(this, info.type, fileInfo)
			end
		end
	}

	add_reg {
		"widget",
		function(this, fileInfo)
			this:addSubAsset(Asset_Widget.new(fileInfo.fullPath, this.assetManager))
		end
	}
	
	add_reg {
		"layer",
		function(this, fileInfo)
			this:addSubAsset(Asset_Layer.new(fileInfo.fullPath, this.assetManager))
		end
	}
	
	add_reg {
		"map",
		function(this, fileInfo)
			this:addSubAsset(Asset_Map.new(fileInfo.fullPath, this.assetManager))
		end
	}

	add_reg {
		"role",
		function(this, fileInfo)
			this:addSubAsset(Asset_Role.new(fileInfo.fullPath, this.assetManager))
		end
	}
end

return Asset_Folder