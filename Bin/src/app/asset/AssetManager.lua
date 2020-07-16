-- @Author: fangcheng
-- @URL: github.com/tkzcfc
-- @Date:   2020-04-06 21:25:47
-- @Description: 资产管理

local Asset_Folder = import(".Asset_Folder")
local AssetManager = class("AssetManager")

local FileUtilsInstance = cc.FileUtils:getInstance()

local function Error_hook(err)
	logE(debug.traceback(err, 3))
end

function AssetManager:ctor(rootPath)
	self.openFolderStatusCache = {}
	self:open(rootPath)
end

-- @brief 添加资源到资源管理
function AssetManager:add(asset)
	self.assetMap[asset.uniqueID] = asset
end

-- @brief 获取资源
function AssetManager:get(assetUniqueID)
	return self.assetMap[assetUniqueID]
end

-- @brief 缓存文件夹打开状态
function AssetManager:cacheOpenFolderStatus(asset)
	self.openFolderStatusCache[asset.property.relativePath] = asset.property.isOpenFolder
end

-- @brief 获取文件夹打开状态
function AssetManager:getOpenFolderStatus(asset)
	return self.openFolderStatusCache[asset.property.relativePath] 
end

-- @brief 获取资源数据
function AssetManager:getAssetData(path)
	if self.dataCache[path] then
		return self.dataCache[path]
	end
	local suc = xpcall(function()
		local content = FileUtilsInstance:getStringFromFile(path)
		if content == "" then
			self.dataCache[path] = {}
		else
			self.dataCache[path] = json.decode(content)
		end
	end, Error_hook)

	if not suc then
		self.dataCache[path] = {}
	end
	return self.dataCache[path]
end

function AssetManager:writeAssetData(path, data, isCreate)
    if data == nil or data.type == nil or data.type == "" then
    	-- 写入失败，内容非法
    	xpcall(function() 
    		local content = json.encode(data)
    		logE(string.format("Write failed, illegal content: %q", tostring(content)))
		end, function()
			logE(string.format("Write failed, illegal content: %q", tostring(data)))
		end)
    	
    	return false
    end

    if _MyG.Functions:writeTableToFile(data, path) then
		if not isCreate then
			self.dataCache[path] = data
		end
		return true
    end
    return false
end

function AssetManager:saveAsset(asset, content)
	if asset == nil then
		logE("saveAsset failed (asset == nil)")
		return
	end

	local data = self:getAssetData(asset.property.fullPath)
	data.data = content
	return self:writeAssetData(asset.property.fullPath, data)
end

function AssetManager:isValid()
	return self.rootAsset ~= nil
end

-- 延迟销毁
function AssetManager:delayDestructionAssets(list)
	if list == nil then
		return
	end
	oRoutine(o_once(function()
		o_wait(o_seconds(1))

		for k,asset in pairs(list) do
			if self.assetMap[asset.uniqueID] then
				self.assetMap[asset.uniqueID] = nil
				asset:destroy()
			end
		end
	end))
end

function AssetManager:open(rootPath)
	self.rootPath = nil
	self.rootAsset = nil
	self.dataCache = {}
	self.assetMap = {}

	self.openFolderStatusCache = {}

	if self.rootAsset then
		local t = {}
		t[#t + 1] = self.rootAsset
		self:delayDestructionAssets(t)
		self.rootAsset:destroyAllChildren()
	end

	if type(rootPath) == "string" and rootPath ~= "" then

		local edCfg = _MyG.EditorProject.config
		if edCfg and type(edCfg.openFolderStatusCache) == "table" then
			self.openFolderStatusCache = edCfg.openFolderStatusCache
		end

		local rootAsset = Asset_Folder.new(rootPath, self)
		if rootAsset:checkValid() then
			self.rootAsset = rootAsset
			self.rootPath = rootPath
		end
	end
end

function AssetManager:save()
	local edCfg = _MyG.EditorProject.config
	if edCfg then
		edCfg.openFolderStatusCache = self.openFolderStatusCache
	end
end

return AssetManager