-- @Author: fangcheng
-- @URL: github.com/tkzcfc
-- @Date:   2020-04-11 14:29:16
-- @Description: 


local Asset_File = import(".Asset_File")
local Asset_Texture = class("Asset_Texture", Asset_File)

local cache = {}

function Asset_Texture:_onItemHovered()
	local fullPath = self.property.fullPath
	local textureID = Tools:getImguiTextureID(fullPath)
	if textureID == nil then
		return
	end

	if cache.textureID ~= textureID then
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

function Asset_Texture:_onLeftDoubleClick()
	_MyG.Functions:openImage(self:getFilePath(), false)
end

return Asset_Texture
