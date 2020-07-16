-- @Author: fangcheng
-- @Date:   2020-07-02 21:14:25
-- @remark: 

local Asset_File = import(".Asset_File")
local Asset_PlistSub = class("Asset_PlistSub", Asset_File)

function Asset_PlistSub:ctor(plistFile, textureName, assetManager)
	self.textureName = textureName
	Asset_PlistSub.super.ctor(self, plistFile, assetManager)
end

function Asset_PlistSub:init(fullPath)
	fullPath = G_Helper.fmtPath(fullPath)
	self.property.extension = G_Helper.getExtension(fullPath)
	self.property.thumbnail = "res/file.png"
	self.property.fullPath = fullPath
	self.property.relativePath = _MyG.Functions:getRelativePath(fullPath)


	self.property.uuid = G_Helper.md5(fullPath .. self.textureName)
	self.property.resType 		= Asset.ResType.PLIST_SUBGRAPH
	self.property.textureName 	= self.textureName
	self.property.showName 		= self.textureName
	self.property.isPlist 		= true

	-- 缓存路径
	local baseName = self.property.relativePath
	baseName = string.gsub(baseName, ".plist$", "")
	baseName = G_Helper.fmtPath(baseName)

	-- 调用saveToFile时候，会在此路径前面加上 cc.FileUtils:getInstance():getWritablePath(),所以此处写相对路径
	self.saveToFileName = ".cache_plist/" .. baseName .. "/" .. self.textureName

	-- 在读取图片时加上 WritablePath
	self.cacheTextureName = cc.FileUtils:getInstance():getWritablePath() .. self.saveToFileName

	baseName = G_Helper.getLastName(self.cacheTextureName)
	self.cacheTextureDirName = string.sub(self.cacheTextureName, 1, #self.cacheTextureName - #baseName)
end


local cache = {}

local shareTextureCache = cc.TextureCache:getInstance()

function Asset_PlistSub:_onItemHovered()
	local textureName = self.cacheTextureName

	if self.genTextureTag then
		local textureID = Tools:getImguiTextureID(textureName)
		if textureID == nil then
			return
		end

		if cache.textureID ~= textureID then
			local imageW = Tools:getImguiTextureWidth(textureName)
			local imageH = Tools:getImguiTextureHeight(textureName)
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
	else
		self.genTextureTag = true

		local texture = shareTextureCache:getTextureForKey(textureName)
		if not texture then
			os.mkdirpath(self.cacheTextureDirName)

			cc.SpriteFrameCache:getInstance():addSpriteFrames(self.property.relativePath)

			local sp = cc.Sprite:createWithSpriteFrameName(self.property.textureName)
			sp:setAnchorPoint(cc.p(0, 0))
			sp:setPosition(0, 0)
			
			local size = sp:getContentSize()
			
			local renderTexture = cc.RenderTexture:create(size.width, size.height)
			
			-- render
			renderTexture:beginWithClear(0,0,0,0)
			sp:visit()
			renderTexture:endToLua()
			
			renderTexture:saveToFile(self.saveToFileName, cc.IMAGE_FORMAT_PNG, true)
		end
	end
end

function Asset_PlistSub:_onLeftDoubleClick()
	-- _MyG.Functions:openImage(self:getFilePath(), false)
end

return Asset_PlistSub
