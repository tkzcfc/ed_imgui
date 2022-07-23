-- @Author: fangcheng
-- @Date:   2020-05-06 21:42:34
-- @Description: 

	local MINSIZE_W = 100
	local MINSIZE_H = 100

local ArmatureRender = require("app.render.ArmatureRender")

local NodeElement = import(".NodeElement")
local CocoStudioElement = import(".CocoStudioElement")
local SpriteElement = import(".SpriteElement")
local ImageElement = import(".ImageElement")
local ArmatureElement = import(".ArmatureElement")

local WidgetElement = class("WidgetElement", NodeElement)

WidgetElement.type = "Widget"
WidgetElement.defaultFileName = "Default/defaultWidget.asset"


local function Error_hook(err)
	logE(debug.traceback(err, 3))
end

function WidgetElement:ctor(context)
	WidgetElement.super.ctor(self, context)

	self.assetFile = WidgetElement.defaultFileName
	self.dragDropKey_WIDGET = "drag" .. Asset.ResType.WIDGET

	self.sysRecipient 	= G_Class.Recipient.new(G_SysEventEmitter)
	self.sysRecipient:on(SysEvent.CONTENT_ON_CONTENT_CHANGE, function(asset)
		if asset  and asset.property.relativePath == self.assetFile then
			self.context:needRefreshOnShow()
		end
	end)

	self.referenceResources = {}
end

function WidgetElement:onDestroy()
    self.sysRecipient:clear()
	WidgetElement.super.onDestroy(self)
end

-- @brief 序列化
function WidgetElement:doSerialize()
	local out = WidgetElement.super.doSerialize(self)
	
	-- widget 不允许旋转
	out.anchorPoint = nil
	out.rotation = nil
	out.scaleX = nil
	out.scaleY = nil
	out.opacity = nil
	out.color = nil

	out.assetFile = self.assetFile

	return out
end

-- @brief 反序列化
function WidgetElement:doDeserialize(data)
	if data and data.assetFile then
		self.assetFile = data.assetFile
	else
		self.assetFile = self.defaultFileName
	end

	if not _MyG.Functions:isFileExist(self.assetFile) then
		self.assetFile = self.defaultFileName
	end

	-- 创建node
	if not WidgetElement.super.doDeserialize(self, data) then
		return false
	end

	return self:deserializeFromFile(self.assetFile)
end

-- @brief 获取引用资源
function WidgetElement:getReferenceResources()
	local refs = WidgetElement.super.getReferenceResources(self)

	for k,v in pairs(self.referenceResources or {}) do
		refs[#refs + 1] = k
	end

	return refs
end

function WidgetElement:deserializeFromFile(filename)

	self.referenceResources = {}

	local ok, jsonData = _MyG.Functions:getJsonDataByAssetFile(filename)
	if not ok then
		return
	end

	if jsonData.type ~= "widget" then
		logE(string.format("Illegal type %q, expected type %q", tostring(jsonData.type), "widget"))
		return false
	end

	if not jsonData.data then
		logE("Field 'data' is empty")
		return false
	end

	local refs = {}
	G_Helper.getTableStringValue(refs, _MyG.Functions:getRefResourcesByAssetJsonData(jsonData))
	for k,v in pairs(refs) do
		self.referenceResources[v] = true
	end

	-- 根据json数据创建节点
	local rootNode = cc.Node:create()
	local children = jsonData.data.children

	for k,v in pairs(children or {}) do
		self:autoSpawn(rootNode, v)
	end

	local minPos, maxPos, box = G_Helper.getNodeValidSize(rootNode)
	rootNode:setPosition(cc.p(-minPos.x, -minPos.y))


	local width = box.width
	local height = box.height

	minPos.x = math.abs(minPos.x)
	minPos.y = math.abs(minPos.y)

	if self.widgetRootNode == nil then
		self.widgetRootNode = cc.Node:create()
		self.renderNode:addChild(self.widgetRootNode)
	else
		self.widgetRootNode:removeAllChildren()
	end
	self.widgetRootNode:addChild(rootNode)

	-- 设置锚点
	local anchor = cc.p(0, 0)
	if width > 0 then
		anchor.x = minPos.x / width
	end
	if height > 0 then
		anchor.y = minPos.y / height
	end

	self.renderNode:setAnchorPoint(anchor)
	self.renderNode:setContentSize(cc.size(width, height))

	-- 线段，矩形绘制
	local contextData = jsonData.data.context
	if contextData and contextData.plugins and contextData.plugins.PluginLineRect then
		self:showLineRect(rootNode, contextData.plugins.PluginLineRect)
	end

	return true
end

-- @brief 自动根据子元素类型创建对应节点
function WidgetElement:autoSpawn(rootNode, data)
	local genFunc = "spawn_" .. data.type
	if self[genFunc] then
		local node = self[genFunc](self, rootNode, data.data)
		if node then
			for k,v in pairs(data.child or {}) do
				self:autoSpawn(node, v)
			end
		end
	else
		logE(string.format("WidgetElement method %q does not exist", genFunc))
	end
end

-- @brief 创建Sprite
function WidgetElement:spawn_Sprite(rootNode, data)
	local textureName, plistFileName, isPlist = SpriteElement:checkResource(data.textureName, data.plistFileName, data.isPlist)

	if isPlist then
		cc.SpriteFrameCache:getInstance():addSpriteFrames(plistFileName)
	end

	local node = nil
	if isPlist then
		node = cc.Sprite:createWithSpriteFrameName(textureName)
	else
		node = cc.Sprite:create(textureName)
	end

	if not node then
		logE("create sprite is null !!!!!!!!!!!!!!!!")
		return
	end

	self:setNodeAttribute(node, data)
	rootNode:addChild(node)

	return node
end

-- @brief 创建Image
function WidgetElement:spawn_Image(rootNode, data)
	local textureName, plistFileName, isPlist = ImageElement:checkResource(data.textureName, data.plistFileName, data.isPlist)

	if isPlist then
		cc.SpriteFrameCache:getInstance():addSpriteFrames(plistFileName)
	end

	local Image = ccui.ImageView:create()
	Image:loadTexture(textureName, isPlist and UI_TEX_TYPE_PLIST or UI_TEX_TYPE_LOCAL)

	self:setNodeAttribute(Image, data)
	rootNode:addChild(Image)

	return Image
end

-- @brief 创建Sprite
function WidgetElement:spawn_CocostudioFile(rootNode, data)
	local scriptFile = CocoStudioElement:checkResource(data.scriptFile)

	local studio_ui = G_Helper.loadStudioFile(G_Helper.getLuaPath(scriptFile))
	if studio_ui.animation then
    	studio_ui.animation:gotoFrameAndPlay(0, true)
    	studio_ui.root:runAction(studio_ui.animation)
	end

	self:setNodeAttribute(studio_ui.root, data)
	rootNode:addChild(studio_ui.root)

	return studio_ui.root
end

-- @brief 创建动画
function WidgetElement:spawn_ArmatureFile(rootNode, data)
	local resFile = ArmatureElement:checkResource(data.resFile)
	
	local render = ArmatureRender.new()
	render:initWithFile(resFile, data.playIndex, data.playLoop)

	self:setNodeAttribute(render, data)
	rootNode:addChild(render)

	return render
end

function WidgetElement:showLineRect(rootNode, pluginData)
	local lines = {}
	local rects = {}

	for k,v in pairs(pluginData.line_data or {}) do
		local line = CLine:new_local()
		line:deserialize(v)
		table.insert(lines, line)
	end

	for k,v in pairs(pluginData.rect_data or {}) do
		local rect = CRect:new_local()
		rect:deserialize(v)
		table.insert(rects, rect)
	end

	local drawNode = cc.DrawNode:create()
	drawNode:setAnchorPoint(cc.p(0, 0))
	drawNode:setPosition(0, 0)
	drawNode:setOpacity(100)
	rootNode:addChild(drawNode, 0xff)

	for k,v in pairs(lines) do
		v:setAlpha(0.3)
		v:debugDraw(drawNode)
	end
	for k,v in pairs(rects) do
		v:setAlpha(0.3)
		v:debugDraw(drawNode)
	end
end

-- @brief 设置节点基本属性
function WidgetElement:setNodeAttribute(node, data)

	if not node or not data then
		logE("setNodeAttribute Error !!!!!")
		return
	end

	if data.anchorPoint then
		node:setAnchorPoint(data.anchorPoint)
	end
	
	if data.position then
		node:setPosition(data.position)
	end

	-- if data.contentSize then
	-- 	node:setContentSize(data.contentSize)
	-- end

	if data.rotation then
		node:setRotation(data.rotation)
	end

	if data.scaleX then
		node:setScaleX(data.scaleX)
	end

	if data.scaleY then
		node:setScaleY(data.scaleY)
	end

	if data.opacity then
		node:setOpacity(data.opacity)
	end

	if data.color then
		node:setColor(data.color)
	end

	if data.name then
		node:setName(data.name)
	end
end


-- @brief 
function WidgetElement:onAttributeGUI()
	WidgetElement.super.onAttributeGUI(self)


	if not ImGui.CollapsingHeader(STR("EA_FEATURES"), ImGuiTreeNodeFlags_DefaultOpen) then
		return
	end

	Tools:imgui_inputText(STR("EA_RESOURCE"), self.assetFile, 512, ImGuiInputTextFlags_ReadOnly)

    if ImGui.BeginDragDropTarget() then
    	if Tools:check_AcceptDragDropPayload(self.dragDropKey_WIDGET) then
    		local dragData = Tools:AcceptDragDropPayload(self.dragDropKey_WIDGET)
    		self:changeAssetWidget(dragData)
    	end
    	ImGui.EndDragDropTarget()
    end

    ImGui.Separator()
end

-- @brief 元素基本属性GUI逻辑 （attribute面板展示）
local tmpTabNumArr = {}
function WidgetElement:onGUI_Base()
	local positionx, positiony = self.renderNode:getPosition()
	local size = self.renderNode:getContentSize()


    tmpTabNumArr[1] = positionx
    tmpTabNumArr[2] = positiony
    if ImGui.DragFloat2(STR("EA_POS"), tmpTabNumArr, 1) then
    	self:onAttributeChange(EditorEvent.ON_CHANGE_POSITION)
    	self.renderNode:setPosition(tmpTabNumArr[1], tmpTabNumArr[2])
    end

    tmpTabNumArr[1] = size.width
    tmpTabNumArr[2] = size.height
    ImGui.InputFloat2(STR("EA_SIZE"), tmpTabNumArr, "%.3f", ImGuiInputTextFlags_ReadOnly)
end

-- @brief 切换资源
function WidgetElement:changeAssetWidget(dragData)
	local asset = _MyG.Functions:getAssetByID(dragData)
	G_SysEventEmitter:emit(SysEvent.DO_CHANGE_ASSET, self, asset, true)
end

-- @brief override 资源对比
function WidgetElement:isAssetEqual(asset)
	local property = asset.property
	if property.relativePath == self.assetFile then
		return true
	end
	return false
end

-- @brief override 资源切换
function WidgetElement:onDoChangeAsset(asset, canUndo)
	WidgetElement.super.onDoChangeAsset(self, assert, canUndo)
	if canUndo then
		self:onAttributeChange(EditorEvent.ON_CHANGE_PREFABRESOURCE)
	end

	local property = asset.property
	self.assetFile = property.relativePath
	self:deserializeFromFile(self.assetFile)
end

function WidgetElement:checkResource(assetFile)
	if _MyG.Functions:isFileExist(assetFile) then
		return assetFile
	end
	return WidgetElement.defaultFileName
end

function WidgetElement:doPartMementoGen(attributeName)
	if attributeName == EditorEvent.ON_CHANGE_PREFABRESOURCE then
		return self.assetFile
	else
		return WidgetElement.super.doPartMementoGen(self, attributeName)
	end
end

-- @brief 撤销属性改变
function WidgetElement:revokeAttributeChange(attributeName, data)
	if attributeName == EditorEvent.ON_CHANGE_PREFABRESOURCE then
		self.assetFile = data
		self:deserializeFromFile(self.assetFile)
	else
		WidgetElement.super.revokeAttributeChange(self, attributeName, data)
	end
end

return WidgetElement

