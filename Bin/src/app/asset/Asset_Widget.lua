-- @Author: fangcheng
-- @URL: github.com/tkzcfc
-- @Date:   2020-04-11 21:41:57
-- @Description: 

local Asset = import(".Asset")
local Asset_File = import(".Asset_File")
local Asset_Widget = class("Asset_Widget", Asset_File)

function Asset_Widget:init(fullPath)
	Asset_Widget.super.init(self, fullPath)

	self.property.resType 		= Asset.ResType.WIDGET
	
	local data = self.assetManager:getAssetData(fullPath)
	self.property.showName = Tools:replaceString(self.property.showName, ".asset", "." .. data.type)
end



return Asset_Widget