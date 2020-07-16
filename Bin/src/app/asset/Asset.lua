-- @Author: fangcheng
-- @URL: github.com/tkzcfc
-- @Date:   2020-04-08 20:59:16
-- @Description: 

local Asset = class("Asset")

Asset.ResType = {
	NONE 			= -1,			-- 无效资源
	PNG 			= 0,			-- png
	JPG 			= 1,			-- jpg
	LUA 			= 2,			-- lua文件
	FOLDER 			= 3,			-- 文件夹
	PLIST 			= 4,			-- plist文件
	PLIST_SUBGRAPH 	= 5,			-- plist子图
	WIDGET			= 6,			-- widget
	LAYER			= 7,			-- 地图层
	MAP				= 8,			-- 地图
}

-- 唯一标识
local uniqueIDGen = 0

-- 绘制图标大小
local iconSize = cc.p(20, 20)
local treeNodeSpacing = 20
local nodeSelectable = cc.p(0, 18)

local cache_drag_item_last  = nil
local cache_drag_item = nil


G_SysEventEmitter:on("onGUIBegin", function()
	cache_drag_item_last = cache_drag_item
	if cache_drag_item_last then
	end
	cache_drag_item = nil
end)


G_SysEventEmitter:on("onGUIEnd", function()
	if cache_drag_item == nil then
		if cache_drag_item_last then
			G_SysEventEmitter:emit("onAssetDragEnd", cache_drag_item_last)
			print("drag", cache_drag_item_last.property.fullPath)
			cache_drag_item_last = nil
		end
	end
end)

-------------------------------------------------------------------------------------------------------
function Asset:ctor(fullPath, assetManager)
	self.property = {
		showFolderMode 	= false,	-- 显示为文件夹模式
		isOpenFolder 	= false,	-- 如果是文件夹模式是否打开状态
		isPlist 		= false,	-- 是否为plist
		extension		= "",		-- 后缀（不带点，如png）
		fullPath		= "",		-- 路径
		thumbnail		= "",		-- 缩略图
		showName		= "",		-- 显示名
		resType			= Asset.ResType.NONE,		-- 资源类型
		thumbnailTexture= nil,		-- 缩略图纹理
		relativePath	= "",		-- 资源相对路径
		uuid			= "",		-- uuid
	}

	uniqueIDGen = uniqueIDGen + 1
	self.uniqueID = uniqueIDGen
	self.uniqueIDStr = tostring(self.uniqueID)

	self.cache_doSeekTag = false
	self.children = {}
	self.parentID = {}
	self.assetManager = assetManager

	self:init(fullPath)
	self:initDragDropData()

	-- 检测资源是否有效
	if self:checkValid() then
		self.property.thumbnailTexture = Tools:getImguiTextureID(self.property.thumbnail)
		if not self.property.thumbnailTexture then
			self.property.thumbnailTexture = Tools:getImguiTextureID("res/file.png")
		end
		assetManager:add(self)
	else
		logW("无效资源", tostring(fullPath))
		self.assetManager = nil
	end
end

-- 初始化拖拽所用的变量
function Asset:initDragDropData()
	self.dragDropKey = "drag" .. self.property.resType
	self.dragDropData = self.uniqueIDStr
end

function Asset:destroy()
	print("Asset destroy:", self.uniqueID)
	self.assetManager = nil
	self.children = nil
end

-- 是否是有效资源
function Asset:checkValid()
	return self.property.resType ~= Asset.ResType.NONE
end

function Asset:init(fullPath)
	fullPath = G_Helper.fmtPath(fullPath)
	self.property.extension = G_Helper.getExtension(fullPath)
	self.property.thumbnail = "res/file.png"
	self.property.fullPath = fullPath
	self.property.showName = G_Helper.getLastName(fullPath)
	self.property.relativePath = _MyG.Functions:getRelativePath(fullPath)
	self.property.uuid = G_Helper.md5(fullPath)
end

-- 资源唯一标识
function Asset:getUniqueID()
	return self.uniqueID
end

-- 资源所处文件夹路径
function Asset:getDirPath()
	if self.property.resType == Asset.ResType.FOLDER then
		return self.property.fullPath
	end

	local fullPath = self.property.fullPath
	local filename = Tools:getFilename(fullPath)
	local path = string.sub(fullPath, 1, -#filename - 1)
	return path
end

-- 资源文件路径
function Asset:getFilePath()
	return self.property.fullPath
end

-- 添加子资源
function Asset:addSubAsset(asset)
	if not asset:checkValid() then
		return
	end
	asset.parentID = self:getUniqueID()
	self.children[#self.children + 1] = asset
end

-- 资源刷新
function Asset:refresh()
	self.cache_doSeekTag = false
end

-- 刷新同一等级的资源
function Asset:refreshSameLevel()
	if self.property.showFolderMode then
		self:refresh()
	else
		local asset = self.assetManager:get(self.parentID)
		if asset then
			asset:refresh()
		end
	end
end

-- 刷新自己包括所有子节点资源
function Asset:refreshAll()
	function _refresh(asset)
		asset.cache_doSeekTag = false
		for k,v in pairs(asset.children or {}) do
			_refresh(v)
		end
	end
	_refresh(self)
end

-- 销毁所有的子节点
function Asset:destroyAllChildren()
	local list = {}
	local function ergodicChildren(root)
		list[#list + 1] = root
		for k,v in pairs(root.children) do
			list[#list + 1] = v
		end
	end

	for k,v in pairs(self.children) do
		ergodicChildren(v)
	end
	
	self.children = {}

	self.assetManager:delayDestructionAssets(list)
end

function Asset:doSeek()
	if not self.cache_doSeekTag then
		self:destroyAllChildren()
		self:_doSeek()
		self.cache_doSeekTag = true
	end
	return self.children
end

-- 是否可以拖动
function Asset:canDrag()
	return true
end

-- 子类重载此函数
function Asset:_doSeek()
	-- body
end

----------------------------------------------------------------- GUI-----------------------------------------------------------------

-- 中断执行子类默认操作
function Asset:breakImplement()
	self.continueTag = false
end

-- 鼠标悬停在资源上
function Asset:onItemHovered()
	self.continueTag = true

	G_SysEventEmitter:emit("asset_onItemHovered", self)

	if self.continueTag then
		self:_onItemHovered()
	end
end

-- 子类继承，实现默认效果
function Asset:_onItemHovered()
end

-- 鼠标左键双击
function Asset:onLeftDoubleClick()
	self.continueTag = true
	
	G_SysEventEmitter:emit("asset_onLeftDoubleClick", self)

	if self.continueTag then
		self:_onLeftDoubleClick()
	end
end

-- 子类继承，实现默认效果
function Asset:_onLeftDoubleClick()
end

-- 鼠标右键单击
function Asset:onRightClick()
	self.continueTag = true
	
	G_SysEventEmitter:emit("asset_onRightClick", self)

	if self.continueTag then
		self:_onRightClick()
	end
end

-- 子类继承，实现默认效果
function Asset:_onRightClick()
end

-- 资源绘制
function Asset:onGUI()

	local property = self.property

	if property.showFolderMode then
		if property.isOpenFolder then
			if ImGui.ArrowButton(self.uniqueIDStr, ImGuiDir_Down) then
				property.isOpenFolder = not property.isOpenFolder
				self.assetManager:cacheOpenFolderStatus(self)
			end
		else
			if ImGui.ArrowButton(self.uniqueIDStr, ImGuiDir_Right) then
				property.isOpenFolder = not property.isOpenFolder
				self.assetManager:cacheOpenFolderStatus(self)
			end
		end
		ImGui.SameLine()
		self:drawItem()

		if property.isOpenFolder then
			self:doSeek()
			if #self.children > 0 then
				ImGui.Indent(treeNodeSpacing)
					for k, v in pairs(self.children) do
						v:onGUI()
					end
				ImGui.Unindent(treeNodeSpacing)
			end
		end
	else
		self:drawItem()
	end
end

function Asset:drawItem()
	self:_drawItem(false)

	if self:canDrag() and ImGui.BeginDragDropSource(ImGuiDragDropFlags_None) then
		ImGui.SetDragDropPayload(self.dragDropKey, self.dragDropData, #self.dragDropData)
		self:_drawItem(true)
		ImGui.EndDragDropSource()
		cache_drag_item = self
	end
end

function Asset:_drawItem(noDrag)
	local property = self.property
	ImGui.Image(property.thumbnailTexture, iconSize)
	ImGui.SameLine()

	if noDrag then
		return ImGui.Selectable(property.showName, false, ImGuiSelectableFlags_AllowDoubleClick, nodeSelectable)
	end

	if ImGui.Selectable(property.showName, false, ImGuiSelectableFlags_AllowDoubleClick, nodeSelectable) then
		if ImGui.IsMouseDoubleClicked(0) then
			if property.showFolderMode then
				property.isOpenFolder = not property.isOpenFolder
				self.assetManager:cacheOpenFolderStatus(self)
			else
				self:onLeftDoubleClick()
			end
		end
	end

	if ImGui.IsItemHovered() then
		self:onItemHovered()
		-- 右键点击
		if ImGui.IsMouseClicked(1) then
			self:onRightClick()
		end
	end
end

cc.exports.Asset = Asset

return Asset
