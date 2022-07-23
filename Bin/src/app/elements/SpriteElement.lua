-- @Author: fangcheng
-- @Date:   2020-04-15 22:13:07
-- @Description: 精灵


local NodeElement = import(".NodeElement")
local SpriteElement = class("SpriteElement", NodeElement)

SpriteElement.type = "Sprite"
SpriteElement.defaultFileName = "Default/DefaultWidget.png"

-- @brief 
function SpriteElement:ctor(context)
	SpriteElement.super.ctor(self, context)

	self.textureName = ""
	self.isPlist = false
	self.plistFileName = ""

	self.dragDropKey_PNG = "drag" .. Asset.ResType.PNG
	self.dragDropKey_JPG = "drag" .. Asset.ResType.JPG
	self.dragDropKey_PlistSub = "drag" .. Asset.ResType.PLIST_SUBGRAPH
end

function SpriteElement:bool_can_edit_size()
	return false
end

-- @brief 序列化
function SpriteElement:doSerialize()
	local out = SpriteElement.super.doSerialize(self)

	-- 精灵不保存 contentSize
	out.contentSize = nil

	out.textureName = self.textureName
	out.isPlist = self.isPlist
	out.plistFileName = self.plistFileName

	return out
end

-- @brief 反序列化
function SpriteElement:doDeserialize(data)

	local textureName, plistFileName, isPlist = self:checkResource(data.textureName, data.plistFileName, data.isPlist)

	self.textureName = textureName
	self.plistFileName = plistFileName
	self.isPlist = isPlist

	if self.isPlist then
		cc.SpriteFrameCache:getInstance():addSpriteFrames(plistFileName)
		self:setRenderNode(cc.Sprite:createWithSpriteFrameName(textureName))
	else
		self:setRenderNode(cc.Sprite:create(textureName))
	end

	SpriteElement.super.doDeserialize(self, data)

	return true
end

-- @brief 获取引用资源
function SpriteElement:getReferenceResources()
	local refs = SpriteElement.super.getReferenceResources(self)
	if self.isPlist then
		refs[#refs + 1] = self.plistFileName
	else
		refs[#refs + 1] = self.textureName
	end
	return refs
end

-- @brief 
function SpriteElement:onAttributeGUI()
	SpriteElement.super.onAttributeGUI(self)

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
end


-- @brief 切换图片资源
function SpriteElement:changeAssetImg(dragData)
	local asset = _MyG.Functions:getAssetByID(dragData)
	G_SysEventEmitter:emit(SysEvent.DO_CHANGE_ASSET, self, asset, true)
end

-- @brief override 资源对比
function SpriteElement:isAssetEqual(asset)
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
function SpriteElement:onDoChangeAsset(asset, canUndo)
	SpriteElement.super.onDoChangeAsset(self, asset, canUndo)
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

	self:refreshSprite()
end


function SpriteElement:refreshSprite()
	if self.isPlist then
		cc.SpriteFrameCache:getInstance():addSpriteFrames(self.plistFileName)
		self.renderNode:setSpriteFrame(self.textureName)
	else
		self.renderNode:setTexture(self.textureName)
	end
end

function SpriteElement:checkResource(textureName, plistFileName, isPlist)
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

function SpriteElement:doPartMementoGen(attributeName)
	if attributeName == EditorEvent.ON_CHANGE_SPRITERESOURCE then
		return {
			isPlist = self.isPlist,
			textureName = self.textureName,
			plistFileName = self.plistFileName
		}
	else
		return SpriteElement.super.doPartMementoGen(self, attributeName)
	end
end

-- @brief 撤销属性改变
function SpriteElement:revokeAttributeChange(attributeName, data)
	if attributeName == EditorEvent.ON_CHANGE_SPRITERESOURCE then
		self.isPlist = data.isPlist
		self.textureName = data.textureName
		self.plistFileName = data.plistFileName
		self:refreshSprite()
	else
		SpriteElement.super.revokeAttributeChange(self, attributeName, data)
	end
end

return SpriteElement