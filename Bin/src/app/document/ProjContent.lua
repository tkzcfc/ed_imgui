-- @Author: fangcheng
-- @URL: github.com/tkzcfc
-- @Date:   2020-04-12 11:19:41
-- @Last Modified by:   fangcheng
-- @Last Modified time: 2020-05-07 21:36:29
-- @Description: 
local AssetContent = require("app.document.AssetContent")
local ProjContent = class("ProjContent", AssetContent)

function ProjContent:ctor(name, assetManager)
	ProjContent.super.ctor(self, name, assetManager)

	self:initEvent()
end

function ProjContent:initEvent()
	self.onAssetContentUpdateHandle = function()
		self:updateAsset()
	end
	G_SysEventEmitter:on("onAssetCocosUpdate", self.onAssetContentUpdateHandle)

	self:regAssetOnItemHoveredEvent()
	self:regAssetOnLeftDoubleClick()
	self:regAssetOnRightClick()
	self:regAssetMenu_OnGUI()
end

function ProjContent:regAssetOnItemHoveredEvent()
	-- G_SysEventEmitter:on("asset_onItemHovered", function(asset)
	-- 	if asset.assetManager ~= self.assetManager then
	-- 		return
	-- 	end
	-- end)
end

function ProjContent:regAssetOnLeftDoubleClick()
	G_SysEventEmitter:on("asset_onLeftDoubleClick", function(asset)
		if asset.assetManager ~= self.assetManager then
			return
		end

		local resType = asset.property.resType
		if resType == Asset.ResType.WIDGET then
			_MyG.Functions:openWidget(asset)
			asset:breakImplement()
		elseif resType == Asset.ResType.LAYER then
			_MyG.Functions:openLayer(asset)
			asset:breakImplement()
		elseif resType == Asset.ResType.MAP then
			_MyG.Functions:openMap(asset)
			asset:breakImplement()
		end
	end)
end

function ProjContent:regAssetOnRightClick()
	-- G_SysEventEmitter:on("asset_onRightClick", function(asset)
	-- 	if asset.assetManager ~= self.assetManager then
	-- 		return
	-- 	end
	-- end)
end

function ProjContent:regAssetMenu_OnGUI()
	G_SysEventEmitter:on("asset_Menu_OnGUI", function(asset)
		if asset.assetManager ~= self.assetManager then
			return
		end
		self:Menu_OnGUI(asset)
	end)
end

function ProjContent:Menu_OnGUI(asset)
	if ImGui.MenuItem(STR("Import")) then
		_MyG.Functions:importResource("*.png", asset:getDirPath(), function()
			asset:refreshSameLevel()
		end)
	end

	if ImGui.BeginMenu(STR("New")) then
		if ImGui.MenuItem(STR("Folder")) then
			_MyG.Functions:createFolder(asset:getDirPath(), function(status)
				if status == 0 then
					asset:refreshSameLevel()
				end
			end)
		end
		if ImGui.MenuItem(STR("Map")) then
			_MyG.Functions:createMap(asset:getDirPath(), function(success)
				if success then
					asset:refreshSameLevel()
				end
			end)
		end
		if ImGui.MenuItem(STR("Widget")) then
			_MyG.Functions:createWidget(asset:getDirPath(), function(success)
				if success then
					asset:refreshSameLevel()
				end
			end)
		end
		if ImGui.MenuItem(STR("Layer")) then
			_MyG.Functions:createLayer(asset:getDirPath(), function(success)
				if success then
					asset:refreshSameLevel()
				end
			end)
		end
		ImGui.EndMenu()
	end

	-- if asset.property.resType ~= Asset.ResType.FOLDER then
	-- 	if ImGui.MenuItem(STR("Delete")) then
	-- 		_MyG.Functions:removeFile(asset:getFilePath())
	-- 	end
	-- end

	if ImGui.MenuItem(STR("Update")) then
		asset:refreshSameLevel()
	end
end

return ProjContent
