-- @Author: fangcheng
-- @Date:   2020-06-02 22:00:11
-- @remark: map中layer管理

local LayerElement = require("app.elements.LayerElement")
local Plugin = import(".Plugin")
local PluginMapLayer = class("PluginMapLayer", Plugin)

function PluginMapLayer:ctor()
	PluginMapLayer.super.ctor(self)

	self.backgroundAssets = {}
	self.foregroundAssets = {}
	self.gameLayerAsset = ""
end

-- @brief 是否阻断元素的Touch事件
function PluginMapLayer:isBlockEleTouchEvent()
	if PluginMapLayer.super.isBlockEleTouchEvent(self) then
		return true
	end

	-- 不允许widget被选中
	return true
end

function PluginMapLayer:doSerialize()
	local output = PluginMapLayer.super.doSerialize(self)
	output.backgroundAssets = self.backgroundAssets
	output.foregroundAssets = self.foregroundAssets
	output.gameLayerAsset	= self.gameLayerAsset
	return output
end

function PluginMapLayer:doDeserialize(data)
	if not PluginMapLayer.super.doDeserialize(self, data) then
		return false
	end

	self.backgroundAssets = data.backgroundAssets or {}
	self.foregroundAssets = data.foregroundAssets or {}
	self.gameLayerAsset	  = data.gameLayerAsset or ""

	self:updateGameLayer()

	return true
end

function PluginMapLayer:updateGameLayer()
	if not self.context then
		return
	end

	local rootElement = self.context.rootElement
	if not rootElement then
		return
	end

	local gameLayerEle = rootElement:getChildByName("gameLayer")
	if gameLayerEle == nil then
		local ele = LayerElement.new(self.context)
		if not ele:deserialize({}) then
			ele:onDestroy()
			
			logE(format_lua_value(data))
			logE("deserialize fail")
		end
		ele:setName("gameLayer")
		gameLayerEle = ele
		rootElement:addChild(gameLayerEle)
	end
	gameLayerEle:changeAssetLayerByFileName(self.gameLayerAsset)
	if self.gameLayerAsset ~= gameLayerEle.assetFile then
		self.gameLayerAsset = gameLayerEle.assetFile
		self:onAttributeChange(EditorEvent.ON_CHANGE_BG_LAYER_ASSET)
	end
end

function PluginMapLayer:onAttributeGUI()
	local newFile = nil

	for k, v in pairs(self.backgroundAssets) do
		newFile = self:onGUI_Child(v, STR("EA_RESOURCE_MAP_BG_LAYER") .. k)
		if newFile then
			self:onAttributeChange(EditorEvent.ON_CHANGE_BG_LAYER_ASSET)
			self.backgroundAssets[k] = newFile
		end
	end

	if #self.backgroundAssets > 1 then
		if ImGui.SmallButton("-##bg_layer_sub") then
			self:onAttributeChange(EditorEvent.ON_CHANGE_BG_LAYER_ASSET)
			self.backgroundAssets[#self.backgroundAssets] = nil
		end
		ImGui.SameLine()
	end
	if ImGui.SmallButton("+##bg_layer_add") then
		self:onAttributeChange(EditorEvent.ON_CHANGE_BG_LAYER_ASSET)
		self.backgroundAssets[#self.backgroundAssets + 1] = ""
	end

	ImGui.Separator()

	newFile = self:onGUI_Child(self.gameLayerAsset, STR("EA_RESOURCE_MAP_GM_LAYER"))
	if newFile then
		if self.gameLayerAsset == "" then
			self.context:dataDirty()
		else
			self:onAttributeChange(EditorEvent.ON_CHANGE_GM_LAYER_ASSET)
		end
		self.gameLayerAsset = newFile
		self:updateGameLayer()
	end

	ImGui.Separator()
	for k, v in pairs(self.foregroundAssets) do
		newFile = self:onGUI_Child(v, STR("EA_RESOURCE_MAP_FG_LAYER") .. k)
		if newFile then
			self:onAttributeChange(EditorEvent.ON_CHANGE_FG_LAYER_ASSET)
			self.foregroundAssets[k] = newFile
		end
	end
	if #self.foregroundAssets > 1 then
		if ImGui.SmallButton("-##fg_layer_sub") then
			self:onAttributeChange(EditorEvent.ON_CHANGE_FG_LAYER_ASSET)
			self.foregroundAssets[#self.foregroundAssets] = nil
		end
		ImGui.SameLine()
	end
	if ImGui.SmallButton("+##fg_layer_add") then
		self:onAttributeChange(EditorEvent.ON_CHANGE_FG_LAYER_ASSET)
		self.foregroundAssets[#self.foregroundAssets + 1] = ""
	end
end

local dragDropKey_LAYER = "drag" .. Asset.ResType.LAYER

function PluginMapLayer:onGUI_Child(assetFile, name)
	local changeValue = nil

	ImGui.PushID(name)
	Tools:imgui_inputText(name, assetFile, 512, ImGuiInputTextFlags_ReadOnly)

    if ImGui.BeginDragDropTarget() then
    	if Tools:check_AcceptDragDropPayload(dragDropKey_LAYER) then
    		local dragData = Tools:AcceptDragDropPayload(dragDropKey_LAYER)
    		local asset = _MyG.Functions:getAssetByID(dragData)
			if asset then
				local property = asset.property
				if property.relativePath ~= assetFile then
					changeValue = property.relativePath
				end
			end
    	end
    	ImGui.EndDragDropTarget()
    end

    ImGui.PopID()

    return changeValue
end

return PluginMapLayer
