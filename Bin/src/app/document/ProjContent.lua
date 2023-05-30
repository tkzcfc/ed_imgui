-- @Author: fangcheng
-- @Date:   2020-04-12 11:19:41
-- @Description: 
local AssetContent = require("app.document.AssetContent")
local ProjContent = class("ProjContent", AssetContent)

function ProjContent:ctor(name, assetManager)
	ProjContent.super.ctor(self, name, assetManager)

	self:initEvent()
end

function ProjContent:initEvent()
	G_SysEventEmitter:on(SysEvent.ON_ASSET_CONTENT_UPDATE, function()
		self:updateAsset()
	end, self)

	self:regAssetOnItemHoveredEvent()
	self:regAssetOnLeftDoubleClick()
	self:regAssetOnRightClick()
	self:regAssetMenu_OnGUI()
end

function ProjContent:regAssetOnItemHoveredEvent()
	-- G_SysEventEmitter:on(SysEvent.ASSET_ON_ITEM_HOVERED, function(asset)
	-- 	if asset.assetManager ~= self.assetManager then
	-- 		return
	-- 	end
	-- end, self)
end

function ProjContent:regAssetOnLeftDoubleClick()
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

function ProjContent:regAssetOnRightClick()
	-- G_SysEventEmitter:on(SysEvent.ASSET_ON_RIGHT_CLICK, function(asset)
	-- 	if asset.assetManager ~= self.assetManager then
	-- 		return
	-- 	end
	-- end, self)
end

function ProjContent:regAssetMenu_OnGUI()
	G_SysEventEmitter:on(SysEvent.ASSET_MENU_ONGUI, function(asset)
		if asset.assetManager ~= self.assetManager then
			return
		end
		self:Menu_OnGUI(asset)
	end, self)
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
			_MyG.CreateAsset:create(Asset.ResType.MAP, asset:getDirPath(), function(success)
				if success then
					asset:refreshSameLevel()
				end
			end)
		end
		if ImGui.MenuItem(STR("Widget")) then
			_MyG.CreateAsset:create(Asset.ResType.WIDGET, asset:getDirPath(), function(success)
				if success then
					asset:refreshSameLevel()
				end
			end)
		end
		if ImGui.MenuItem(STR("Layer")) then
			_MyG.CreateAsset:create(Asset.ResType.LAYER, asset:getDirPath(), function(success)
				if success then
					asset:refreshSameLevel()
				end
			end)
		end

		if ImGui.MenuItem(STR("Role")) then
			_MyG.CreateAsset:create(Asset.ResType.ROLE, asset:getDirPath(), function(success)
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
	
	if _MyG.OpenAsset:canOpen(asset) then
		if ImGui.MenuItem(STR("Duplicate")) then
			asset:getAssetManager():duplicate(asset)
		end
		if ImGui.MenuItem(STR("Open")) then
			_MyG.OpenAsset:open(asset)
		end
	end

	if asset.property.resType == Asset.ResType.PLIST then
		if ImGui.MenuItem(STR("Disassembly")) then
			local fullPath = asset.property.fullPath
			local frames = Tools:splitPlist(fullPath)

			cc.SpriteFrameCache:getInstance():addSpriteFrames(asset.property.relativePath)

			async_run(function()
				_MyG.ShowLoading()
				async_yield()
				for k, textureName in pairs(frames) do
					local saveToFileName = self:genPlistSubFilePath(asset.property.relativePath, textureName)

					-- 缓存全路径
					local cacheTextureName = cc.FileUtils:getInstance():getWritablePath() .. saveToFileName

					local baseName = G_Helper.getLastName(cacheTextureName)
					local cacheTextureDirName = string.sub(cacheTextureName, 1, #cacheTextureName - #baseName)

					-- 创建对应目录
					os.mkdirpath(cacheTextureDirName)

					-- plist子图渲染
					do
						local sp = cc.Sprite:createWithSpriteFrameName(textureName)
						sp:setAnchorPoint(VecZero)
						sp:setPosition(0, 0)
						
						local size = sp:getContentSize()
						
						local renderTexture = cc.RenderTexture:create(size.width, size.height)
						
						-- render
						renderTexture:beginWithClear(0,0,0,0)
						sp:visit()
						renderTexture:endToLua()
						
						renderTexture:saveToFile(saveToFileName, cc.IMAGE_FORMAT_PNG, true)
					end

					async_yield(1 / 30)
					_MyG:PercentLoading(k / #frames)
				end
				async_yield()
				_MyG:HideLoading()
			end)
		end
	end
end

-- @brief 
function ProjContent:genPlistSubFilePath(plistFile, pngName)
	-- 缓存路径
	local baseName = string.gsub(plistFile, ".plist$", "")
	baseName = G_Helper.fmtPath(baseName)

	-- 调用saveToFile时候，会在此路径前面加上 cc.FileUtils:getInstance():getWritablePath(),所以此处写相对路径
	return ".cache_plist/" .. baseName .. "/" .. pngName
end

return ProjContent
