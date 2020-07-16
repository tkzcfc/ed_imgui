-- @Author: fangcheng
-- @Date:   2020-06-04 19:23:58
-- @remark: 


local WidgetElement = import(".WidgetElement")
local CocoStudioElement = import(".CocoStudioElement")
local SpriteElement = import(".SpriteElement")
local ImageElement = import(".ImageElement")

local LayerElement = class("LayerElement", WidgetElement)

local FileUtilsInstance = cc.FileUtils:getInstance()

local function Error_hook(err)
	logE(debug.traceback(err, 3))
end

LayerElement.type = "Layer"
LayerElement.defaultFileName = "Default/defaultLayer.asset"

function LayerElement:ctor(context)
	LayerElement.super.ctor(self, context)

	self.assetFile = ""
	self.dragDropKey_LAYER = "drag" .. Asset.ResType.LAYER
end

-- @brief 序列化
function LayerElement:doSerialize()
	local out = LayerElement.super.doSerialize(self)
	
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
function LayerElement:doDeserialize(data)

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

function LayerElement:deserializeFromFile(filename)

	self.referenceResources = {}

	-- 解析json
	local jsonData = nil
	local suc = xpcall(function()
		local content = FileUtilsInstance:getStringFromFile(filename)
		if content == "" then
			jsonData = {}
		else
			jsonData = json.decode(content)
		end
	end, Error_hook)

	if not suc then
		return
	end

	jsonData = jsonData or {}

	if jsonData.type ~= "layer" then
		logE(string.format("Illegal type %q, expected type %q", tostring(jsonData.type), "layer"))
		return false
	end

	if not jsonData.data then
		logE("Field 'data' is empty")
		return false
	end

	if jsonData.data.context and jsonData.data.context.plugins then
		local refResources = jsonData.data.context.plugins.PluginRefResources or {}
		local refs = {}
		G_Helper.getTableStringValue(refs, refResources)
		for k,v in pairs(refs) do
			self.referenceResources[v] = true
		end
	end

	-- 根据json数据创建节点
	local rootNode = cc.Node:create()
	local children = jsonData.data.children
	for k,v in pairs(children or {}) do
		self:autoSpawn(rootNode, v)
	end

	-- local minPos, maxPos, box = G_Helper.getNodeValidSize(rootNode)
	-- rootNode:setPosition(cc.p(-minPos.x, -minPos.y))

	-- local width = box.width
	-- local height = box.height

	-- minPos.x = math.abs(minPos.x)
	-- minPos.y = math.abs(minPos.y)

	if self.widgetRootNode == nil then
		self.widgetRootNode = cc.Node:create()
		self.renderNode:addChild(self.widgetRootNode)
	else
		self.widgetRootNode:removeAllChildren()
	end
	self.widgetRootNode:addChild(rootNode)

	-- -- 设置锚点
	-- local anchor = cc.p(0, 0)
	-- if width > 0 then
	-- 	anchor.x = minPos.x / width
	-- end
	-- if height > 0 then
	-- 	anchor.y = minPos.y / height
	-- end

	-- self.renderNode:setAnchorPoint(anchor)
	-- self.renderNode:setContentSize(cc.size(width, height))

	-- -- 线段，矩形绘制
	-- local contextData = jsonData.data.context
	-- if contextData and contextData.plugin and contextData.plugin.PluginLineRect then
	-- 	self:showLineRect(rootNode, contextData.plugin.PluginLineRect)
	-- end

	return true
end

-- @brief 创建Image
function LayerElement:spawn_Widget(rootNode, data)
	local filename = WidgetElement:checkResource(data.assetFile)

-- 解析json
	local jsonData = nil
	local suc = xpcall(function()
		local content = FileUtilsInstance:getStringFromFile(filename)
		if content == "" then
			jsonData = {}
		else
			jsonData = json.decode(content)
		end
	end, Error_hook)

	if not suc then
		return
	end

	jsonData = jsonData or {}

	if jsonData.type ~= "widget" then
		logE(string.format("Illegal type %q, expected type %q", tostring(jsonData.type), "widget"))
		return
	end

	if not jsonData.data then
		logE("Field 'data' is empty")
		return
	end

	local node = cc.Node:create()

	local children = jsonData.data.children

	for k,v in pairs(children or {}) do
		self:autoSpawn(node, v)
	end

	self:setNodeAttribute(node, data)
	rootNode:addChild(node)

	return rootNode
end

-- @brief 切换资源
function LayerElement:changeAssetLayer(dragData)
	local asset = _MyG.Functions:getAssetByID(dragData)

	if asset then
		local property = asset.property
		if property.relativePath == self.assetFile then
			return
		end
		self:onAttributeChange("change_PrefabResource")

		self.assetFile = property.relativePath
		self:deserializeFromFile(self.assetFile)
	end
end

function LayerElement:changeAssetLayerByFileName(filename)
	if filename == self.assetFile then
		return
	end
	self.assetFile = filename
	self:deserializeFromFile(self.assetFile)
end

-- @brief 
function LayerElement:onAttributeGUI()
	if not ImGui.CollapsingHeader(STR("EA_FEATURES"), ImGuiTreeNodeFlags_DefaultOpen) then
		return
	end

	self:onAttributeGUI_Resource()

    ImGui.Separator()
end

function LayerElement:onAttributeGUI_Resource()
	Tools:imgui_inputText(STR("EA_RESOURCE"), self.assetFile, 512, ImGuiInputTextFlags_ReadOnly)

    if ImGui.BeginDragDropTarget() then
    	if Tools:check_AcceptDragDropPayload(self.dragDropKey_LAYER) then
    		local dragData = Tools:AcceptDragDropPayload(self.dragDropKey_LAYER)
    		self:changeAssetLayer(dragData)
    	end
    	ImGui.EndDragDropTarget()
    end
end

-- @brief 节点显示GUI逻辑
function LayerElement:onNodeContentGUI(nodeContent)
end

function LayerElement:doPartMementoGen(attributeName)
	if attributeName == "change_PrefabResource" then
		return self.assetFile
	else
		return LayerElement.super.doPartMementoGen(self, attributeName)
	end
end

-- @brief 撤销属性改变
function LayerElement:revokeAttributeChange(attributeName, data)
	if attributeName == "change_PrefabResource" then
		self.assetFile = data
		self:deserializeFromFile(self.assetFile)
	else
		LayerElement.super.revokeAttributeChange(self, attributeName, data)
	end
end

return LayerElement
