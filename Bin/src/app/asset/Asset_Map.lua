-- @Author: fangcheng
-- @URL: github.com/tkzcfc
-- @Date:   2020-04-11 21:46:09
-- @Description: 

local Asset = import(".Asset")
local Asset_File = import(".Asset_File")
local Asset_Map = class("Asset_Map", Asset_File)

function Asset_Map:init(fullPath)
	Asset_Map.super.init(self, fullPath)

	self.property.resType 		= Asset.ResType.MAP

	local data = self.assetManager:getAssetData(fullPath)
	self.property.showName = Tools:replaceString(self.property.showName, ".asset", "." .. data.type)
end



return Asset_Map