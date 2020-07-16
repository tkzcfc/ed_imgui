-- @Author: fangcheng
-- @URL: github.com/tkzcfc
-- @Date:   2020-04-11 10:20:23
-- @Description: 

local FileDialog = require("app.imgui.FileDialog")
local Asset = import(".Asset")
local Asset_File = import(".Asset_File")
local Asset_Folder = class("Asset_Folder", Asset_File)

local parseHook = nil

local FileUtilsInstance = cc.FileUtils:getInstance()

function Asset_Folder:init(fullPath)
	Asset_Folder.super.init(self, fullPath)


	fullPath = G_Helper.getClearDirPath(fullPath)
	self.property.fullPath = fullPath .. "/"
	self.property.showName = G_Helper.getLastName(fullPath)
	
	self.property.extension 		= ""
	self.property.showFolderMode 	= true
	self.property.thumbnail 		= "res/folder.png"
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
			if parseHook[extension] then
				parseHook[extension](self, fileInfo)
			end
		end
	end
end


local Asset_Png = import(".Asset_Png")
local Asset_Jpg = import(".Asset_Jpg")
local Asset_Widget = import(".Asset_Widget")
local Asset_Layer = import(".Asset_Layer")
local Asset_Map = import(".Asset_Map")
local Asset_Lua = import(".Asset_Lua")
local Asset_Plist = import(".Asset_Plist")

function Asset_Folder.regParse()
	if parseHook then
		return
	end

	parseHook = {}

	parseHook["png"] = function(this, fileInfo)
		local plistFile = string.gsub(fileInfo.fullPath, ".png$", ".plist")
		if not FileUtilsInstance:isFileExist(plistFile) then
			this:addSubAsset(Asset_Png.new(fileInfo.fullPath, this.assetManager))
		end
	end

	parseHook["jpg"] = function(this, fileInfo)
		this:addSubAsset(Asset_Jpg.new(fileInfo.fullPath, this.assetManager))
	end

	parseHook["lua"] = function(this, fileInfo)
		this:addSubAsset(Asset_Lua.new(fileInfo.fullPath, this.assetManager))
	end

	parseHook["plist"] = function(this, fileInfo)
		local pngFile = string.gsub(fileInfo.fullPath, ".plist$", ".png")
		if FileUtilsInstance:isFileExist(pngFile) then
			this:addSubAsset(Asset_Plist.new(fileInfo.fullPath, this.assetManager))
		end
	end


	---------------------------------------------------- [.asset] ----------------------------------------------------

	parseHook["asset"] = function(this, fileInfo)
		local info = this.assetManager:getAssetData(fileInfo.fullPath)
		if info and info.type and parseHook[info.type] then
			parseHook[info.type](this, fileInfo)
		end
	end

	parseHook["widget"] = function(this, fileInfo)
		this:addSubAsset(Asset_Widget.new(fileInfo.fullPath, this.assetManager))
	end

	parseHook["layer"] = function(this, fileInfo)
		this:addSubAsset(Asset_Layer.new(fileInfo.fullPath, this.assetManager))
	end

	parseHook["map"] = function(this, fileInfo)
		this:addSubAsset(Asset_Map.new(fileInfo.fullPath, this.assetManager))
	end
end

return Asset_Folder