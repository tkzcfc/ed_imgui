-- @Author: fangcheng
-- @Date:   2020-04-11 14:29:16
-- @Description: 


local Asset_File = import(".Asset_File")
local Asset_Texture = class("Asset_Texture", Asset_File)


function Asset_Texture:init(fullPath)
	Asset_Texture.super.init(self, fullPath)
	
	self.property.thumbnailTexture 		= EditorIconContent:get(EditorIcon.ICON_TEXTURE)
end


local cache = {}
function Asset_Texture:_onItemHovered()
	local fullPath = self.property.fullPath
	local textureID = Tools:getImguiTextureID(fullPath)
	if textureID == nil then
		return
	end

	if cache.textureID ~= textureID then
		if cache.textureID ~= nil then
			Tools:freeImageuiTexture(cache.textureID)
		end
		Tools:retainImageuiTexture(textureID)
		textureCleanup()

		local imageW = Tools:getImguiTextureWidth(fullPath)
		local imageH = Tools:getImguiTextureHeight(fullPath)
		local showTextureInfo = string.format("%d*%d", imageW, imageH)
		local maxValue = math.max(imageW, imageH)
		if maxValue > 500 then
			local scale = 500 / maxValue
			imageW = imageW * scale
			imageH = imageH * scale
		end
		cache["textureInfo"] = showTextureInfo
		cache["textureID"] = textureID
		cache["imageSize"] = cc.p(imageW, imageH)
	end

	ImGui.BeginTooltip()
	ImGui.Text(cache.textureInfo)
	ImGui.Image(cache.textureID, cache.imageSize)
	ImGui.EndTooltip()
end

return Asset_Texture
