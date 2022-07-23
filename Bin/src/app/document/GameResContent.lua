local AssetContent = require("app.document.AssetContent")
local GameResContent = class("GameResContent", AssetContent)


local FileUtilsInstance = cc.FileUtils:getInstance()

local function fmt_search_path(path)
    if path == nil or path == "" then return "" end
    if FileUtilsInstance:isAbsolutePath(path) then
        return path
    end
    return os.currentdir() .. "/" .. path
end



function GameResContent:ctor(name, assetManager)
	GameResContent.super.ctor(self, name, assetManager)
	self:initEvent()
end

local function clearRepeat(t)
    local map = {}
    local out = {}
    for k, v in pairs(t) do
        if not map[v] then
            map[v] = true
            table.insert(out, G_Helper.fmtPath(v))
        end 
    end
    return out
end

function GameResContent:initEvent()
    -- 游戏目录监听切换事件
	G_SysEventEmitter:on(SysEvent.SET_GAME_RES_DIR, function(dirPath)
        -- 打开的相同目录
        if self.assetManager:isEqualRootPath(dirPath) then return end
        
        local oldPath = self.assetManager:getRootPath()
        
        -- 重新打开新的目录
        self.assetManager:open(dirPath)
		self:updateAsset()

        local paths = FileUtilsInstance:getSearchPaths()
        -- 移除之前的搜索路径
        oldPath = fmt_search_path(oldPath)
        for k, v in pairs(paths) do
            if v == oldPath then
                table.remove(paths, k)
                break
            end
        end
        
        -- 搜索路径添加
        local path = fmt_search_path(self.assetManager:getRootPath())
        if path ~= "" then
            table.insert(paths, path)
        end
        
        paths = clearRepeat(paths)
        FileUtilsInstance:setSearchPaths(paths)

        for k, v in pairs(paths) do
            print(k, v)
        end
	end, self)

    
	self:regAssetOnItemHoveredEvent()
	self:regAssetOnLeftDoubleClick()
	self:regAssetOnRightClick()
	self:regAssetMenu_OnGUI()
end

function GameResContent:regAssetOnItemHoveredEvent()
	-- G_SysEventEmitter:on(SysEvent.ASSET_ON_ITEM_HOVERED, function(asset)
	-- 	if asset.assetManager ~= self.assetManager then
	-- 		return
	-- 	end
	-- end, self)
end

function GameResContent:regAssetOnLeftDoubleClick()
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

function GameResContent:regAssetOnRightClick()
	-- G_SysEventEmitter:on(SysEvent.ASSET_ON_RIGHT_CLICK, function(asset)
	-- 	if asset.assetManager ~= self.assetManager then
	-- 		return
	-- 	end
	-- 	asset:breakImplement()
	-- end, self)
end


function GameResContent:regAssetMenu_OnGUI()
	G_SysEventEmitter:on(SysEvent.ASSET_MENU_ONGUI, function(asset)
		if asset.assetManager ~= self.assetManager then
			return
		end
		self:Menu_OnGUI(asset)
	end, self)
end


function GameResContent:Menu_OnGUI(asset)
	if ImGui.MenuItem(STR("Update")) then
		asset:refreshSameLevel()
	end
end


return GameResContent
