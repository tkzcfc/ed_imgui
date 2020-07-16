local AssetContent = require("app.document.AssetContent")
local CocosContent = class("CocosContent", AssetContent)

function CocosContent:ctor(name, assetManager)
	CocosContent.super.ctor(self, name, assetManager)
	self:initEvent()
end

function CocosContent:initEvent()
	self.onAssetContentUpdateHandle = function()
		self:updateAsset()
	end
	G_SysEventEmitter:on("onAssetCocosUpdate", self.onAssetContentUpdateHandle)

	self:regAssetOnItemHoveredEvent()
	self:regAssetOnLeftDoubleClick()
	self:regAssetOnRightClick()
	self:regAssetMenu_OnGUI()
end

function CocosContent:regAssetOnItemHoveredEvent()
	-- G_SysEventEmitter:on("asset_onItemHovered", function(asset)
	-- 	if asset.assetManager ~= self.assetManager then
	-- 		return
	-- 	end
	-- end)
end

function CocosContent:regAssetOnLeftDoubleClick()
	G_SysEventEmitter:on("asset_onLeftDoubleClick", function(asset)
		if asset.assetManager ~= self.assetManager then
			return
		end

		local resType = asset.property.resType

		if resType == Asset.ResType.PNG or
		resType == Asset.ResType.JPG or
		resType == Asset.ResType.PLIST_SUBGRAPH then
		else
			asset:breakImplement()
		end
	end)
end

function CocosContent:regAssetOnRightClick()
	-- G_SysEventEmitter:on("asset_onRightClick", function(asset)
	-- 	if asset.assetManager ~= self.assetManager then
	-- 		return
	-- 	end
	-- 	asset:breakImplement()
	-- end)
end


function CocosContent:regAssetMenu_OnGUI()
	G_SysEventEmitter:on("asset_Menu_OnGUI", function(asset)
		if asset.assetManager ~= self.assetManager then
			return
		end
		self:Menu_OnGUI(asset)
	end)
end


function CocosContent:Menu_OnGUI(asset)
	if ImGui.MenuItem(STR("Update")) then
		asset:refreshSameLevel()
	end
end


return CocosContent
