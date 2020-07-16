-- @Author: fangcheng
-- @URL: github.com/tkzcfc
-- @Date:   2020-05-05 14:56:19
-- @Last Modified by:   fangcheng
-- @Last Modified time: 2020-06-01 22:35:42
-- @Description: 


local NodeElement = import(".NodeElement")
local ImageElement = class("ImageElement", NodeElement)

ImageElement.type = "Image"
ImageElement.defaultFileName = "Default/DefaultWidget.png"

function ImageElement:ctor(context)
	ImageElement.super.ctor(self, context)

	self.textureName = ""
	self.isPlist = false
	self.plistFileName = ""

	self.dragDropKey_PNG = "drag" .. Asset.ResType.PNG
	self.dragDropKey_JPG = "drag" .. Asset.ResType.JPG
	self.dragDropKey_PlistSub = "drag" .. Asset.ResType.PLIST_SUBGRAPH

end

function ImageElement:bool_can_edit_size()
	return not self.renderNode:isIgnoreContentAdaptWithSize()
end

-- @brief  序列化
function ImageElement:doSerialize()
	local out = ImageElement.super.doSerialize(self)

	-- 不保存 contentSize
	if self.renderNode:isIgnoreContentAdaptWithSize() then
		out.contentSize = nil
	end

	out.textureName = self.textureName
	out.isPlist = self.isPlist
	out.plistFileName = self.plistFileName
	out.ignoreContent = self.renderNode:isIgnoreContentAdaptWithSize()

	return out
end

-- @brief 反序列化
function ImageElement:doDeserialize(data)
	local textureName, plistFileName, isPlist = self:checkResource(data.textureName, data.plistFileName, data.isPlist)

	self.textureName = textureName
	self.plistFileName = plistFileName
	self.isPlist = isPlist

	if self.isPlist then
		cc.SpriteFrameCache:getInstance():addSpriteFrames(plistFileName)
	end

	local Image = ccui.ImageView:create()
	Image:loadTexture(self.textureName, self.isPlist and UI_TEX_TYPE_PLIST or UI_TEX_TYPE_LOCAL)
	Image:setAnchorPoint(0.5, 0.5)
	Image:setTouchEnabled(false)
	self:setRenderNode(Image)

	ImageElement.super.doDeserialize(self, data)

	if data.ignoreContent ~= nil then
		self.renderNode:ignoreContentAdaptWithSize(data.ignoreContent)
		if not data.ignoreContent and data.contentSize then
			self.renderNode:setContentSize(data.contentSize)
		end
	end

	return true
end

-- @brief 获取引用资源
function ImageElement:getReferenceResources()
	local refs = ImageElement.super.getReferenceResources(self)
	if self.isPlist then
		refs[#refs + 1] = self.plistFileName
	else
		refs[#refs + 1] = self.textureName
	end
	return refs
end

-- @brief 
function ImageElement:onAttributeGUI()
	ImageElement.super.onAttributeGUI(self)

	if not ImGui.CollapsingHeader(STR("EA_FEATURES"), ImGuiTreeNodeFlags_DefaultOpen) then
		return
	end

	Tools:imgui_inputText(STR("EA_RESOURCE"), self.textureName, 512, ImGuiInputTextFlags_ReadOnly)

    if ImGui.BeginDragDropTarget() then
    	if Tools:check_AcceptDragDropPayload(self.dragDropKey_PNG) then
    		local dragData = Tools:AcceptDragDropPayload(self.dragDropKey_PNG)
    		self:changeAssetImg(dragData)
    	end
    	ImGui.EndDragDropTarget()
    end

    if ImGui.BeginDragDropTarget() then
    	if Tools:check_AcceptDragDropPayload(self.dragDropKey_JPG) then
    		local dragData = Tools:AcceptDragDropPayload(self.dragDropKey_JPG)
    		self:changeAssetImg(dragData)
    	end
    	ImGui.EndDragDropTarget()
    end

	if ImGui.BeginDragDropTarget() then
    	if Tools:check_AcceptDragDropPayload(self.dragDropKey_PlistSub) then
    		local dragData = Tools:AcceptDragDropPayload(self.dragDropKey_PlistSub)
    		self:changeAssetImg(dragData)
    	end
    	ImGui.EndDragDropTarget()
    end


    ImGui.Separator()

    local retTmp
    local boolValue = self.renderNode:isIgnoreContentAdaptWithSize()
    retTmp, boolValue = ImGui.Checkbox(STR("EA_USE_TEXTURE_SIZE"), boolValue)
    if retTmp then
    	self:onAttributeChange("change_Image_Use_Tex_Size")
    	self.renderNode:ignoreContentAdaptWithSize(boolValue)
    end

    ImGui.Separator()
end

-- @brief 切换图片资源
function ImageElement:changeAssetImg(dragData)
	local asset = _MyG.Functions:getAssetByID(dragData)

	if asset then
		self:onAttributeChange("change_SpriteResource")

		local property = asset.property
		self.isPlist = property.isPlist
		self.textureName = property.relativePath

		if property.isPlist then
			self.plistFileName = property.relativePath
			self.textureName = property.textureName
		else
			self.plistFileName = ""
		end
		self:refreshImg()
	end
end

function ImageElement:refreshImg()
	if self.isPlist then
		cc.SpriteFrameCache:getInstance():addSpriteFrames(self.plistFileName)
		self.renderNode:loadTexture(self.textureName, UI_TEX_TYPE_PLIST)
	else
		self.renderNode:loadTexture(self.textureName, UI_TEX_TYPE_LOCAL)
	end
end

function ImageElement:checkResource(textureName, plistFileName, isPlist)
	if isPlist then
		if _MyG.Functions:isFileExist(plistFileName) then
			return textureName, plistFileName, isPlist
		end
		logE(string.format(STR("NO_RES_USE_DEFAILT_FMT"), tostring(plistFileName), tostring(self.defaultFileName)))
		return self.defaultFileName, "", false
	else
		if _MyG.Functions:isFileExist(textureName) then
			return textureName, plistFileName, isPlist
		end
		logE(string.format(STR("NO_RES_USE_DEFAILT_FMT"), tostring(textureName), tostring(self.defaultFileName)))
		return self.defaultFileName, "", false
	end
end

function ImageElement:doPartMementoGen(attributeName)
	if attributeName == "change_Image_Use_Tex_Size" then
		return self.renderNode:isIgnoreContentAdaptWithSize()
	elseif attributeName == "change_SpriteResource" then
		return {
			isPlist = self.isPlist,
			textureName = self.textureName,
			plistFileName = self.plistFileName
		}
	else
		return ImageElement.super.doPartMementoGen(self, attributeName)
	end
end

-- @brief 撤销属性改变
function ImageElement:revokeAttributeChange(attributeName, data)
	if attributeName == "change_Image_Use_Tex_Size" then
		self.renderNode:ignoreContentAdaptWithSize(data)
	elseif attributeName == "change_SpriteResource" then
		self.isPlist = data.isPlist
		self.textureName = data.textureName
		self.plistFileName = data.plistFileName
		self:refreshImg()
	else
		ImageElement.super.revokeAttributeChange(self, attributeName, data)
	end
end

return ImageElement