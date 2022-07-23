-- @Author: fangcheng
-- @Date:   2020-04-08 21:35:46
-- @Description: 


local Asset = import(".Asset")
local Asset_Texture = import(".Asset_Texture")
local Asset_Png = class("Asset_Png", Asset_Texture)

function Asset_Png:init(fullPath)
	Asset_Png.super.init(self, fullPath)
	
	self.property.resType 		= Asset.ResType.PNG
end

return Asset_Png
