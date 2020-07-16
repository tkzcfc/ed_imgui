-- @Author: fangcheng
-- @URL: github.com/tkzcfc
-- @Date:   2020-04-11 21:46:01
-- @Description: 

local Asset = import(".Asset")
local Asset_File = import(".Asset_File")
local Asset_Layer = class("Asset_Layer", Asset_File)

function Asset_Layer:init(fullPath)
	Asset_Layer.super.init(self, fullPath)
	
	self.property.resType 		= Asset.ResType.LAYER

	local data = self.assetManager:getAssetData(fullPath)
	self.property.showName = Tools:replaceString(self.property.showName, ".asset", "." .. data.type)
end



return Asset_Layer