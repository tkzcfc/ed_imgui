-- @Author: fangcheng
-- @URL: github.com/tkzcfc
-- @Date:   2020-05-30 22:10:45
-- @Last Modified by:   fangcheng
-- @Last Modified time: 2020-06-01 22:34:32
-- @Description: cocostudio

local NodeElement = import(".NodeElement")
local CocoStudioElement = class("CocoStudioElement", NodeElement)

CocoStudioElement.type = "CocostudioFile"
CocoStudioElement.defaultFileName = "Default/DefaultStudioFile.lua"

-- @brief 
function CocoStudioElement:ctor(context)
	CocoStudioElement.super.ctor(self, context)

	self.scriptFile = CocoStudioElement.defaultFileName

	self.dragDropKey_LUA = "drag" .. Asset.ResType.LUA
end

function CocoStudioElement:bool_can_edit_size()
	return false
end

-- @brief 序列化
function CocoStudioElement:doSerialize()
	local out = CocoStudioElement.super.doSerialize(self)

	-- 不保存 contentSize
	out.contentSize = nil

	out.scriptFile = self.scriptFile

	return out
end

-- @brief 反序列化
function CocoStudioElement:doDeserialize(data)

	self.scriptFile = self:checkResource(data.scriptFile)

	-- 创建node
	if not CocoStudioElement.super.doDeserialize(self, data) then
		return false
	end

	self:genRenderNode()

	return true
end

-- @brief 获取引用资源
function CocoStudioElement:getReferenceResources()
	local refs = CocoStudioElement.super.getReferenceResources(self)
	
	local M = G_AnalyStudioResource:getReferenceResources(self.scriptFile)

	for k,v in pairs(M) do
		refs[#refs + 1] = v
	end

	return refs
end

function CocoStudioElement:genRenderNode()
    local studio_ui = G_Helper.loadStudioFile(G_Helper.getLuaPath(self.scriptFile))

    if studio_ui.animation then
    	studio_ui.animation:gotoFrameAndPlay(0, true)
    	studio_ui.root:runAction(studio_ui.animation)
	end

    local rootNode = studio_ui.root

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
end

-- @brief 
function CocoStudioElement:onAttributeGUI()
	CocoStudioElement.super.onAttributeGUI(self)

	if not ImGui.CollapsingHeader(STR("EA_FEATURES"), ImGuiTreeNodeFlags_DefaultOpen) then
		return
	end

	Tools:imgui_inputText(STR("EA_RESOURCE"), self.scriptFile, 512, ImGuiInputTextFlags_ReadOnly)

    if ImGui.BeginDragDropTarget() then
    	if Tools:check_AcceptDragDropPayload(self.dragDropKey_LUA) then
    		local dragData = Tools:AcceptDragDropPayload(self.dragDropKey_LUA)
    		self:changeAssetLua(dragData)
    	end
    	ImGui.EndDragDropTarget()
    end

    ImGui.Separator()
end

-- @brief 元素基本属性GUI逻辑 （attribute面板展示）
local tmpTabNumArr = {}
function CocoStudioElement:onGUI_Base()
	local positionx, positiony = self.renderNode:getPosition()
	local size = self.renderNode:getContentSize()


    tmpTabNumArr[1] = positionx
    tmpTabNumArr[2] = positiony
    if ImGui.DragFloat2(STR("EA_POS"), tmpTabNumArr, 1) then
    	self:onAttributeChange("change_position")
    	self.renderNode:setPosition(tmpTabNumArr[1], tmpTabNumArr[2])
    end

    tmpTabNumArr[1] = size.width
    tmpTabNumArr[2] = size.height
    ImGui.InputFloat2(STR("EA_SIZE"), tmpTabNumArr, "%.3f", ImGuiInputTextFlags_ReadOnly)
end

-- @brief 切换图片资源
function CocoStudioElement:changeAssetLua(dragData)
	local asset = _MyG.Functions:getAssetByID(dragData)

	if asset then
		self:onAttributeChange("change_PrefabResource")
		local property = asset.property
		self.scriptFile = property.relativePath

		self:genRenderNode()
	end
end

function CocoStudioElement:doPartMementoGen(attributeName)
	if attributeName == "change_PrefabResource" then
		return self.scriptFile
	else
		return CocoStudioElement.super.doPartMementoGen(self, attributeName)
	end
end

-- @brief 撤销属性改变
function CocoStudioElement:revokeAttributeChange(attributeName, data)
	if attributeName == "change_PrefabResource" then
		self.scriptFile = data
		self:genRenderNode()
	else
		CocoStudioElement.super.revokeAttributeChange(self, attributeName, data)
	end
end

return CocoStudioElement

