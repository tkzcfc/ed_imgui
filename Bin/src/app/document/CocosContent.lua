local AssetContent = require("app.document.AssetContent")
local CocosContent = class("CocosContent", AssetContent)

function CocosContent:ctor(name, assetManager)
	CocosContent.super.ctor(self, name, assetManager)
	self:initEvent()
end

function CocosContent:initEvent()
	G_SysEventEmitter:on(SysEvent.ON_ASSET_COCOS_UPDATE, function()
		self:updateAsset()
	end, self)

	self:regAssetOnItemHoveredEvent()
	self:regAssetOnLeftDoubleClick()
	self:regAssetOnRightClick()
	self:regAssetMenu_OnGUI()
end

function CocosContent:regAssetOnItemHoveredEvent()
	-- G_SysEventEmitter:on(SysEvent.ASSET_ON_ITEM_HOVERED, function(asset)
	-- 	if asset.assetManager ~= self.assetManager then
	-- 		return
	-- 	end
	-- end, self)
end

function CocosContent:regAssetOnLeftDoubleClick()
	G_SysEventEmitter:on(SysEvent.ASSET_ON_LEFT_DOUBLE_CLICK, function(asset)
		if asset.assetManager ~= self.assetManager then
			return
		end

		if _MyG.OpenAsset:canOpen(asset) then
			asset:breakImplement()
			_MyG.OpenAsset:open(asset)
		else
			logW(string.format(STR("CANNOT_OPEN_FAIL"), asset:getFilePath()))
		end
		
	end, self)
end

function CocosContent:regAssetOnRightClick()
	-- G_SysEventEmitter:on(SysEvent.ASSET_ON_RIGHT_CLICK, function(asset)
	-- 	if asset.assetManager ~= self.assetManager then
	-- 		return
	-- 	end
	-- 	asset:breakImplement()
	-- end, self)
end


function CocosContent:regAssetMenu_OnGUI()
	G_SysEventEmitter:on(SysEvent.ASSET_MENU_ONGUI, function(asset)
		if asset.assetManager ~= self.assetManager then
			return
		end
		self:Menu_OnGUI(asset)
	end, self)
end


function CocosContent:Menu_OnGUI(asset)
	if ImGui.MenuItem(STR("Update")) then
		asset:refreshSameLevel()
	end
end


return CocosContent
