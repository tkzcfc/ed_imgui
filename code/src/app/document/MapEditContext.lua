local LayerEditContext = require("app.document.LayerEditContext")

local MapEditContext = class("MapEditContext", LayerEditContext)

function MapEditContext:ctor(name, fullPath)
	MapEditContext.super.ctor(self, name, fullPath)

	self.backgroundLayer = nil
	self.gameLayer = nil
	self.foregroundLayer = nil

	self.isHideAllRevivePoint = false
end

function MapEditContext:setIsHideAllRevivePoint(value)
	if self.isHideAllRevivePoint == value then
		return
	end
	self.isHideAllRevivePoint = value
	value = not value
	for k,v in pairs(self.cells) do
		if v:getTypeName() == "RevivePointCell" and v.renderNode then
			v.renderNode:setVisible(value)
		end
	end
end

function MapEditContext:onDragAssetFnihshFunc(ext, resPath, resType, pos)
end

function MapEditContext:onDragPreWidgetFnihshFunc(name, pos)
	if name == "WC_RevivePoint" then
		self:setIsHideAllRevivePoint(false)
		self:createRevivePoint(pos)
	end
end

function MapEditContext:onNodeFilter(node)
	return false
end

function MapEditContext:getAllRevivePointCell()
	local t = {}
	for k,v in pairs(self.cells) do
		if v:getTypeName() == "RevivePointCell" then
			table.insert(t, v)
		end
	end

	table.sort(t, function(a, b)
		return a:getPositionX() < b:getPositionX()
	end)

	return t
end

function MapEditContext:serialize()
	local output = G_GEN_COM_FILE_HEADER()
	
	output = output .. "local M = {}\n"
	output = output .. "\nfunction M:load(context)\n"
	output = output .. string.format("context.uniqueID = %d\n", self.uniqueID)

	if self.backgroundLayer then
		output = output .. self:serializeNode(self.backgroundLayer.renderNode)
		output = output .. string.format("context.backgroundLayer = %s\n", self.backgroundLayer:getName())
		output = output .. string.format("context.backgroundLayer:setVisiblePublishLR(false)\n")
	end

	if self.gameLayer then
		output = output .. self:serializeNode(self.gameLayer.renderNode)
		output = output .. string.format("context.gameLayer = %s\n", self.gameLayer:getName())
	end

	if self.foregroundLayer then
		output = output .. self:serializeNode(self.foregroundLayer.renderNode)
		output = output .. string.format("context.foregroundLayer = %s\n", self.foregroundLayer:getName())
		output = output .. string.format("context.foregroundLayer:setVisiblePublishLR(false)\n")
	end

	output = output .. "\nself:gemLoad(context)\n"

	output = output .. "end\n"

	-- 序列化所有复活点
	output = output .. "\nfunction M:gemLoad(context)\n"
	output = output .. "local revivePointCellTmp\n"

	local rpCells = self:getAllRevivePointCell()
	for k,v in pairs(rpCells) do
		output = output .. v:serialize()
	end

	output = output .. "end\n"

	-- 是否隐藏所有复活点
	output = output .. string.format("\nM.isHideAllRevivePoint = %s\n", tostring(self.isHideAllRevivePoint))

	local bgCellData = self.bgCell:serialize()
	output = output .. string.format("\nM.bgCellData = %s\n", format_lua_value(bgCellData))

	output = output .. "return M\n"

	return output
end


function MapEditContext:deserializeEx(t)
	MapEditContext.super.deserializeEx(self, t)
	self:setIsHideAllRevivePoint(t.isHideAllRevivePoint)
end

function MapEditContext:publish()
	local output = G_GEN_COM_FILE_HEADER()

	output = output .. "local M = {}\n"

	output = output .. "\nfunction M:loadBackgroundNode()\n"
	if self.backgroundLayer then
		output = output .. self:publishLayer(self.backgroundLayer)
	end
	output = output .. "end\n"

	output = output .. "\nfunction M:loadGameNode()\n"
	if self.gameLayer then
		output = output .. self:publishLayer(self.gameLayer)
	end
	output = output .. "end\n"

	output = output .. "\nfunction M:loadForegroundNode()\n"
	if self.foregroundLayer then
		output = output .. self:publishLayer(self.foregroundLayer)
	end
	output = output .. "end\n"

	local bgCellData = self.bgCell:publish()
	output = output .. string.format("\nM.bgCellData = %s\n", format_lua_value(bgCellData))

	-- 序列化所有复活点
	local revivePoints = {}
	local rpCells = self:getAllRevivePointCell()
	for k,v in pairs(rpCells) do
		table.insert(revivePoints, v:publish())
	end
	output = output .. string.format("\nM.revivePoints = %s\n", format_lua_value(revivePoints))

	output = output .. "\nreturn M\n"

	return output
end

function MapEditContext:publishLayer(layer)
	local output = ""

	-- output = output .. string.format("local %s = cc.Node:create()\n", G_ROOT_NODE_NAME)
	-- output = output .. string.format("%s:setName(%q)\n", G_ROOT_NODE_NAME, G_ROOT_NODE_NAME)
	-- output = output .. self:publishNode(layer.renderNode)
	-- output = output .. string.format("return %s\n", G_ROOT_NODE_NAME)

	-- print_lua_value(layer.bgCellData.workSpace)
	-- local workSpace = layer.bgCellData.workSpace

	local src = string.format("_root:addChild(%s)", layer:getName())
	local tar = string.format("%s:setContentSize(cc.size(%s.LuaFileInfo.bgCellData.workSpace[1], %s.LuaFileInfo.bgCellData.workSpace[2]))\n\treturn %s", layer:getName(), layer:getName(), layer:getName(), layer:getName())
	output = output .. self:publishNode(layer.renderNode)
	output = Tools:replaceString(output, src, tar)
	return output
end

return MapEditContext