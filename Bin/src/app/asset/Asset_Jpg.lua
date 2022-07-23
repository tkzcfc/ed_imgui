-- @Author: fangcheng
-- @Date:   2020-04-11 10:47:32
-- @Description: 
local Asset = import(".Asset")
local Asset_Texture = import(".Asset_Texture")
local Asset_Jpg = class("Asset_Jpg", Asset_Texture)

function Asset_Jpg:init(fullPath)
	Asset_Jpg.super.init(self, fullPath)
	
	self.property.resType 		= Asset.ResType.JPG
end

return Asset_Jpg