-- @Author: fangcheng
-- @Date:   2020-05-05 14:56:19
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
	
	if self.isPlist then
		Tools:imgui_inputText(STR("EA_RESOURCE"), string.format("%s @ [%s]", self.textureName, self.plistFileName), 512, ImGuiInputTextFlags_ReadOnly)
	else
		Tools:imgui_inputText(STR("EA_RESOURCE"), self.textureName, 512, ImGuiInputTextFlags_ReadOnly)
	end

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
    	self:onAttributeChange(EditorEvent.ON_CHANGE_IMAGE_USE_TEX_SIZE)
    	self.renderNode:ignoreContentAdaptWithSize(boolValue)
    end

    ImGui.Separator()
end

-- @brief 切换图片资源
function ImageElement:changeAssetImg(dragData)
	local asset = _MyG.Functions:getAssetByID(dragData)
	G_SysEventEmitter:emit(SysEvent.DO_CHANGE_ASSET, self, asset, true)
end

-- @brief override 资源对比
function ImageElement:isAssetEqual(asset)
	local property = asset.property

	-- 资源相同
	if self.isPlist == property.isPlist then
		if self.isPlist then
			if self.plistFileName == property.relativePath and self.textureName == property.textureName then
				return true
			end
		else
			if self.textureName == property.relativePath then
				return true
			end
		end
	end

	return false
end

-- @brief override 资源切换
function ImageElement:onDoChangeAsset(asset, canUndo)
	ImageElement.super.onDoChangeAsset(self, asset, canUndo)
	if canUndo then
		self:onAttributeChange(EditorEvent.ON_CHANGE_SPRITERESOURCE)
	end

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
	if attributeName == EditorEvent.ON_CHANGE_IMAGE_USE_TEX_SIZE then
		return self.renderNode:isIgnoreContentAdaptWithSize()
	elseif attributeName == EditorEvent.ON_CHANGE_SPRITERESOURCE then
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
	if attributeName == EditorEvent.ON_CHANGE_IMAGE_USE_TEX_SIZE then
		self.renderNode:ignoreContentAdaptWithSize(data)
	elseif attributeName == EditorEvent.ON_CHANGE_SPRITERESOURCE then
		self.isPlist = data.isPlist
		self.textureName = data.textureName
		self.plistFileName = data.plistFileName
		self:refreshImg()
	else
		ImageElement.super.revokeAttributeChange(self, attributeName, data)
	end
end

return ImageElement