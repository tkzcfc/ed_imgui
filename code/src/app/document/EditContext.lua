local Document = require("app.imgui.Document")

local EditContext = class("EditContext", Document)

function EditContext:ctor(name, fullPath)
	EditContext.super.ctor(self, name)
	self.isVisible = false
	self.focusCells = {}
	self.uniqueID = 0
	self.cells = {}

	self.fullPath = fullPath

	self.recipient = G_Class.Recipient.new(G_SysEventEmitter)
end

function EditContext:onGUI()
	if not self.isVisible then
		self.isVisible = true
		self:onShow()
	end
end

function EditContext:destroy()
	if self.bgCell then
		self.bgCell:onRemove()
	end

	for k,v in pairs(self.cells) do
		v:onRemove()
	end
	self.cells = nil

	self.recipient:clear()
	self.bgNode:removeFromParent()
	self.bgNode = nil
	self.nodeContentContext = nil
	_MyG.MainScene.NodeContent:setRootNode(nil)
	_MyG.MainScene.NodeContent.canDoMoveOperationHook = nil
	print("destroy file: " .. self.filename)
end

function EditContext:onShow()
	self:initEvent()
	if self.bgNode then
		self.bgNode:setVisible(true)
	end
	_MyG.MainScene.NodeContent.onNodeFilter = function(node) return self:onNodeFilter(node) end
	_MyG.MainScene.NodeContent.onNodeIsFocus = function(node)
		local cell = self:getCellByNode(node)
		if cell then
			return self:isFocusCell(cell)
		end
		return false
	end
	_MyG.MainScene.NodeContent.onSelectFocusCell = function(node)
		local cell = self:getCellByNode(node)
		if cell then
			self:changeFocusCell(cell)
		end
	end
	_MyG.MainScene.NodeContent:setRootNode(self.rootNode)
	_MyG.MainScene.NodeContent:popContext(self.nodeContentContext)
end

function EditContext:getCellByNode(node)
	if node.cell then
		return node.cell
	end
	for k,v in pairs(self.cells) do
		if v.renderNode == node then
			return v
		end
	end
end

function EditContext:onNodeFilter(node)
	if self.cache_validNode == nil then
		self:updateValidNodeCache()
	end
	return self.cache_validNode[node]
end

function EditContext:updateValidNodeCache()
	self.cache_validNode = {}
	for k, v in pairs(self.cells) do
		if v:isNode() and v.renderNode then
			self.cache_validNode[v.renderNode] = true
		end
	end
end

function EditContext:onNodeChange()
	self:updateValidNodeCache()
	G_SysEventEmitter:emit("onNodeContentUpdate", self.rootNode)
end

function EditContext:onHide()
	self.isVisible = false
	self.recipient:clear()

	if self.bgNode then
		self.bgNode:setVisible(false)
	end
	self.nodeContentContext = _MyG.MainScene.NodeContent:pushContext()
	_MyG.MainScene.NodeContent:setRootNode(nil)
	_MyG.MainScene.NodeContent.canDoMoveOperationHook = nil
end

function EditContext:initEvent()
	self.recipient:on("onAttributeContent_GUI", function()
		if #self.focusCells == 1 then
			self.focusCells[1]:onGUI()
		else
			if self.bgCell then
				self.bgCell:onGUI()
			end
		end
	end)

	self.recipient:on("onDragAssetItem", function(pos, resPath, resType)
		if self.rootNode == nil then
			return
		end

		if not self:checkMouseIsInCurNode(pos.x, pos.y) then
			return
		end

		pos = self.rootNode:convertToNodeSpace(pos)
		resPath = _MyG.Functions:getRelativePath(resPath)
		local ext = G_Helper.getExtension(resPath)

		self:onDragAssetFnihshFunc(ext, resPath, resType, pos)
	end)

	self.recipient:on("onDragPreWidget", function(pos, name)
		if self.rootNode == nil then
			return
		end

		if not self:checkMouseIsInCurNode(pos.x, pos.y) then
			return
		end

		pos = self.rootNode:convertToNodeSpace(pos)
		self:onDragPreWidgetFnihshFunc(name, pos)
	end)

	self.recipient:on("onEditorContentSave", function()
		print("save", self.name)
		self:save()
	end)

	self.recipient:on("onKeyBoardSave", function()
		print("save", self.name)
		self:save()
	end)

	self.recipient:on("onKeyBoard_Single", function(keyCode)
		-- Delete
		if keyCode == 23 then
			self:deleteFocusCell()
		end
	end)

	self.recipient:on("onNodeZOrderUpdate", function() 
		self.dirty = true
	end)
end

function EditContext:initWithData(bgCell)
    if self.isInit then
        return
    end
    self.isInit = true

    self.editSize = _MyG.MainScene.Panel_BG:getContentSize()

    self.bgNode = cc.Node:create()
    self.bgNode:setContentSize(self.editSize)
    self.bgNode:setVisible(self.isVisible)
    _MyG.MainScene.Panel_BG:addChild(self.bgNode)

    self.rootNode = cc.Node:create()
    self.rootNode:setAnchorPoint(0.5, 0.5)
    self.rootNode:setPosition(self.editSize.width * 0.5, self.editSize.height * 0.5)
    self.rootNode:setName(G_ROOT_NODE_NAME)
    self.bgNode:addChild(self.rootNode)

    self.zTopNode = cc.Node:create()
    self.rootNode:addChild(self.zTopNode, 0xffffff)

    --坐标轴
    local defaultW = 500000
    local defaultH = 30000
    self.coordinateNode = cc.DrawNode:create()
    self.coordinateNode:drawLine({x = -defaultW, y = 0}, {x = defaultW, y = 0}, cc.c4f(1.0, 1.0, 1.0, 1.0))
    self.coordinateNode:drawLine({x = 0, y = -defaultH}, {x = 0, y = defaultH}, cc.c4f(1.0, 1.0, 1.0, 1.0))
    self.rootNode:addChild(self.coordinateNode, -0xffff)

    bgCell:onAdd()
    self.bgCell = bgCell

    self:initTouch()
    self:initMouseListener()
end

function EditContext:initTouch()
    local function onTouchBegin(touch,event)
		if not self.isVisible or _MyG.MainScene.ilayer:IsAnyWindowHovered() then
			return false
		end

    	self:onTouchBegin(touch,event)

    	return true
    end

    local function onTouchMove(touch,event)
    	self:onTouchMove(touch,event)
    end

    local function onTouchEnd(touch,event)
    	self:onTouchEnd(touch,event)
    end

    local listener = cc.EventListenerTouchOneByOne:create();
    listener:setSwallowTouches(true)
    listener:registerScriptHandler(onTouchBegin,cc.Handler.EVENT_TOUCH_BEGAN);
    listener:registerScriptHandler(onTouchMove,cc.Handler.EVENT_TOUCH_MOVED);
    listener:registerScriptHandler(onTouchEnd,cc.Handler.EVENT_TOUCH_ENDED);
    listener:registerScriptHandler(onTouchEnd,cc.Handler.EVENT_TOUCH_CANCELLED);
    cc.Director:getInstance():getEventDispatcher():addEventListenerWithSceneGraphPriority(listener, self.bgNode)
end

function EditContext:initMouseListener()
	local function onMouseMove(event)
		-- 拦截左键，左键使用touch方法
		if event:getMouseButton() == 0 then
			return
		end

		if not self.isVisible or _MyG.MainScene.ilayer:IsAnyWindowHovered() then
			return
		end
		if self:checkMouseIsInCurNode_MouseEvent(event) then
			self:onMouseMove(event)
		end
    end

	local function onMouseScroll(event)
		if not self.isVisible or _MyG.MainScene.ilayer:IsAnyWindowHovered() then
			return
		end
		if self:checkMouseIsInCurNode_MouseEvent(event) then
			self:onMouseScroll(event)
		end
    end

	local function onMouseDown(event)
		if event:getMouseButton() == 0 then
			return
		end
		if not self.isVisible or _MyG.MainScene.ilayer:IsAnyWindowHovered() then
			return
		end
		if self:checkMouseIsInCurNode_MouseEvent(event) then
			self:onMouseDown(event)
		end
    end

	local function onMouseUp(event)
		if event:getMouseButton() == 0 then
			return
		end
		if not self.isVisible or _MyG.MainScene.ilayer:IsAnyWindowHovered() then
			return
		end
		self:onMouseUp(event)
    end

    local mouseListener = cc.EventListenerMouse:create()
    mouseListener:registerScriptHandler(onMouseMove,cc.Handler.EVENT_MOUSE_MOVE )
    mouseListener:registerScriptHandler(onMouseScroll,cc.Handler.EVENT_MOUSE_SCROLL )
    mouseListener:registerScriptHandler(onMouseDown,cc.Handler.EVENT_MOUSE_DOWN )
    mouseListener:registerScriptHandler(onMouseUp,cc.Handler.EVENT_MOUSE_UP )
    cc.Director:getInstance():getEventDispatcher():addEventListenerWithSceneGraphPriority(mouseListener, self.bgNode)
end

function EditContext:onMouseMove(event)
	if #self.focusCells > 0 then
		local isBreak = false
		for k, v in pairs(self.focusCells) do
			if v:onMouseMove(event) then
				isBreak = true
			end
		end
		if not isBreak then
			self.bgCell:onMouseMove(event)
		end
	else
		self.bgCell:onMouseMove(event)
	end
end

function EditContext:onMouseScroll(event)
	if #self.focusCells > 0 then
		local isBreak = false
		for k, v in pairs(self.focusCells) do
			if v:onMouseScroll(event) then
				isBreak = true
			end
		end
		if not isBreak then
			self.bgCell:onMouseScroll(event)
		end
	else
		self.bgCell:onMouseScroll(event)
	end
end

function EditContext:onMouseDown(event)
	if #self.focusCells > 0 then
		local isBreak = false
		for k, v in pairs(self.focusCells) do
			if v:onMouseDown(event) then
				isBreak = true
			end
		end
		if not isBreak then
			self.bgCell:onMouseDown(event)
		end
	else
		self.bgCell:onMouseDown(event)
	end
end

function EditContext:onMouseUp(event)
	if #self.focusCells > 0 then
		local isBreak = false
		for k, v in pairs(self.focusCells) do
			if v:onMouseUp(event) then
				isBreak = true
			end
		end
		if not isBreak then
			self.bgCell:onMouseUp(event)
		end
	else
		self.bgCell:onMouseUp(event)
	end
end

function EditContext:onTouchBegin(touch, event)
	if not self.fixFocusCellTag then
		self:changeFocusCell()
	end
	if #self.focusCells > 0 then
		for k, v in pairs(self.focusCells) do
			v:onTouchBegin(touch, event)
		end
	else
		self.bgCell:onTouchBegin(touch, event)
	end
end

function EditContext:onTouchMove(touch, event)
	if #self.focusCells > 0 then
		for k, v in pairs(self.focusCells) do
			v:onTouchMove(touch, event)
		end
	else
		self.bgCell:onTouchMove(touch, event)
	end

	if self.cacheFocusCell then
		self.cacheFocusCell = nil
	end
end

function EditContext:onTouchEnd(touch, event)
	if #self.focusCells > 0 then
		for k, v in pairs(self.focusCells) do
			v:onTouchEnd(touch, event)
		end
	else
		self.bgCell:onTouchEnd(touch, event)
	end

	self.fixFocusCellTag = false
	if self:isValidCell(self.cacheFocusCell) then
		self:changeFocusCell(self.cacheFocusCell)
		self.cacheFocusCell = nil
	end
end

-- forceSingle：是否强制单选
function EditContext:changeFocusCell(cell, forceSingle)
	local contain = self:isFocusCell(cell)

	if not forceSingle and self:isCtrl() and contain and self.fixFocusCellTag then
		self.cacheFocusCell = cell
		return
	end

	if cell == nil then
		if self:isCtrl() then
			return
		end
		for k,v in pairs(self.focusCells) do
			v:onLoseFocus()
		end
		self.focusCells = {}
		return
	end

	if not self:isCtrl() then
		forceSingle = true
	end

	if forceSingle then
		for k,v in pairs(self.focusCells) do
			if v ~= cell then
				v:onLoseFocus()
			end
		end
		self.focusCells = {}
		self.focusCells[1] = cell
		if not contain then
			cell:onFocus()
		end
		return
	end

	if self:isCtrl() then
		if contain then
			for k, v in pairs(self.focusCells) do
				if v == cell then
					table.remove(self.focusCells, k)
					cell:onLoseFocus()
					return
				end
			end
		else
			table.insert(self.focusCells, cell)
			cell:onFocus()
		end
	end
end

function EditContext:isCtrl()
	return _MyG.KeyboardStateMng:keyCodeIsPressed(14) or _MyG.KeyboardStateMng:keyCodeIsPressed(15)
end

function EditContext:isMultiSelect()
	return #self.focusCells > 1
end

function EditContext:isFocusCell(cell)
	for k,v in pairs(self.focusCells) do
		if v == cell then
			return true
		end
	end
	return false
end

function EditContext:isValidCell(cell)
	if cell == nil then
		return false
	end
	for k, v in pairs(self.cells) do
		if v == cell then
			return true
		end
	end
end

function EditContext:deleteFocusCell(cell)
	if cell == nil then
		for k,v in pairs(self.focusCells) do
			self:deleteCell(v)
		end
		self.focusCells = {}
		return
	end

	self:deleteCell(cell)
	for k,v in pairs(self.focusCells) do
		if v == cell then
			table.remove(k)
			return
		end
	end
end

function EditContext:addCell(cell)
	for k,v in pairs(self.cells) do
		if v == cell then
			assert(0)
			return
		end
	end
	cell:onAdd()
	table.insert(self.cells, cell)
	self:onNodeChange()
end

function EditContext:deleteCell(cell)
	if cell == nil then
		return
	end

	local function removeFunc(tar, broadcast)
		for k, v in pairs(self.cells) do
			if v == tar then
				v:onRemove()
				table.remove(self.cells, k)
				self.dirty = true
				if broadcast then
					self:onNodeChange()
				end
				return
			end
		end
	end

	if cell.renderNode then
		local tarCells = {}
		for k,v in pairs(self.cells) do
			if v:isNode() and v.renderNode and self:isChild(cell.renderNode, v.renderNode) then
				table.insert(tarCells, v)
			end
		end
		for k,v in pairs(tarCells) do
			removeFunc(v)
		end
	end

	removeFunc(cell, true)
	print("cells count", #self.cells)
end

function EditContext:isChild(root, tar)
	local function doFunc(node, tar)
		if node == nil or node == tar then
			return false
		end

		if node == nil or node:getChildrenCount() <= 0 then
			return false
		end
	
		local children = node:getChildren()
		for k,v in pairs(children) do
			if v == tar or doFunc(v, tar) then
				return true
			end
		end
		return false
	end
	return doFunc(root, tar)
end

function EditContext:disenableAllCellTouch()
	for k,v in pairs(self.cells) do
		v:disenableTouch()
	end
end

function EditContext:enableAllCellTouch()
	for k,v in pairs(self.cells) do
		v:enableTouch()
	end
end

function EditContext:freezeCell(value)
	self.isFreezeCellTag = value
end

function EditContext:checkMouseIsInCurNode_MouseEvent(event)
	return self:checkMouseIsInCurNode(event:getCursorX(), event:getCursorY())
end

function EditContext:checkMouseIsInCurNode(posx, posy)
	return Tools:isInRect(self.bgNode, posx, posy)
end

function EditContext:getUniqueID()
	self.uniqueID = self.uniqueID + 1
	return self.uniqueID
end

function EditContext:serialize()
	local output = G_GEN_COM_FILE_HEADER()
	
	output = output .. "local M = {}\n"
	output = output .. "function M:load(context)\n"
	output = output .. string.format("context.uniqueID = %d\n", self.uniqueID)
	output = output .. self:serializeNode(self.rootNode)
	output = output .. "end\n"

	local bgCellData = self.bgCell:serialize()
	output = output .. string.format("\nM.bgCellData = %s\n", format_lua_value(bgCellData))

	output = output .. "return M\n"

	return output
end

-- 发序列化
function EditContext:deserialize(data)
	if data == "" then
		return
	end
	local func = G_Helper.doString(data)
	if func == nil then
		return
	end

	local t = func()
	if t.load then
		t:load(self)
	end
	if t.bgCellData then
		self.bgCell:deserialize(t.bgCellData)
	end

	self:deserializeEx(t)
end

function EditContext:deserializeEx(t)
end

-- 发布
function EditContext:publish()
	local output = G_GEN_COM_FILE_HEADER()

	output = output .. "local M = {}\n"
	output = output .. "function M:loadNode()\n"
	output = output .. string.format("local %s = cc.Node:create()\n", G_ROOT_NODE_NAME)
	output = output .. string.format("%s:setName(%q)\n", G_ROOT_NODE_NAME, G_ROOT_NODE_NAME)
	output = output .. self:publishNode(self.rootNode)
	output = output .. string.format("return %s\n", G_ROOT_NODE_NAME)
	output = output .. "end\n"

	local bgCellData = self.bgCell:publish()
	output = output .. string.format("\nM.bgCellData = %s\n", format_lua_value(bgCellData))

	output = output .. "return M\n"

	return output
end

function EditContext:save()
	if self:duplicateNameDetection() then
		logE("节点重名，保存失败")
		return
	end
	self.dirty = false
	local data = self:serialize()
	local boolValue = _MyG.Functions:writeScriptToFile(data, self.fullPath)
	if not boolValue then
		logE("保存文件失败")
		return boolValue
	end

	data = self:publish()
	local fullPath = _MyG.GlobalData:getPublishPath(self.fullPath)
	boolValue = _MyG.Functions:writeScriptToFile(data, fullPath)
	if not boolValue then
		logE("保存发布文件失败")
	end

	if boolValue then
		G_SysEventEmitter:emit("onAssetContentUpdate", _MyG.Functions:getRelativePath(self.fullPath))
	end

	return boolValue
end

-- 节点重名检测
function EditContext:duplicateNameDetection()
	local t = {}
	local d = {}
	local b = false

	t[G_ROOT_NODE_NAME] = 1

	for k,v in pairs(self.cells) do
		if v:isNode() then
			if t[v.name] then
				b = true
				d[v.name] = true
			end
			t[v.name] = true
		end
	end

	if b then
		local str = "重名节点:\n{\n"
		for k,v in pairs(d) do
			str = str .. k .. "\n"
		end
		str = str .. "}"
		logE(str)
	end

	return b
end

function EditContext:serializeNode(node)
	local outputNodeData = ""
	local function serializeNodeEx(node)
		if node == nil then
			return
		end
		local cell = self:getCellByNode(node)
		if cell and cell:isNode() then
			local str = cell:serialize()
			outputNodeData = outputNodeData .. str
		end

		local children = node:getChildren()
		for k,v in pairs(children) do
			cell = self:getCellByNode(v)
			if cell then
				serializeNodeEx(cell.renderNode)
			end
		end
	end
	serializeNodeEx(node)
	return outputNodeData
end

function EditContext:publishNode(node)
	local outputNodeData = ""
	local function publishNodeEx(node)
		if node == nil then
			return
		end
		local cell = self:getCellByNode(node)
		if cell and cell:isNode() then
			local str = cell:publish()
			outputNodeData = outputNodeData .. str
		end

		local children = node:getChildren()
		for k,v in pairs(children) do
			cell = self:getCellByNode(v)
			if cell then
				publishNodeEx(cell.renderNode)
			end
		end
	end
	publishNodeEx(node)
	return outputNodeData
end

---------------------------------------------------------------------------------------------------------

function EditContext:onDragAssetFnihshFunc(ext, resPath, resType, pos)
	if ext == "png" then
		self:createSprite(resPath, resType, pos)
	elseif ext == "lua" then
		self:createCocostudio(resPath, resType, pos)
	end
end

function EditContext:onDragPreWidgetFnihshFunc(name, pos)
	if name == "WC_Image" then
		self:createImage("Default/ImageFile.png", 0, pos)
	elseif name == "WC_Sprite" then
		self:createSprite("Default/Sprite.png", 0, pos)
	end
end
-- 
function EditContext:createImage(resPath, resType, pos)
	local cell = require("app.cell.ImageCell").new(self, resPath, resType, pos)
    self:addCell(cell)
    self:changeFocusCell(cell, true)
    
    self.dirty = true
    return cell
end

function EditContext:createSprite(resPath, resType, pos)
	local cell = require("app.cell.SpriteCell").new(self, resPath, resType, pos)
    self:addCell(cell)
    self:changeFocusCell(cell, true)
    
    self.dirty = true
    return cell
end

function EditContext:createCocostudio(resPath, resType, pos)
	local cell = require("app.cell.CocostudioCell").new(self, resPath, pos)
    self:addCell(cell)
    self:changeFocusCell(cell, true)
    
    self.dirty = true
    return cell
end

function EditContext:createWidget(resPath, resType, pos)
	local resPath_Lua = Tools:replaceString(resPath, _MyG.GlobalData:getFileFullExtension("WIDGET"), ".lua")
	if not cc.FileUtils:getInstance():isFileExist(resPath_Lua) then
		logE(string.format("文件%q不存在，请先保存%q", resPath_Lua, resPath))
		return
	end

	local cell = require("app.cell.WidgetCell").new(self, resPath, pos)
    self:addCell(cell)
    self:changeFocusCell(cell, true)

    self.dirty = true
    return cell
end

function EditContext:createLayer(resPath, resType, pos)
	local resPath_Lua = Tools:replaceString(resPath, _MyG.GlobalData:getFileFullExtension("LAYER"), ".lua")
	if not cc.FileUtils:getInstance():isFileExist(resPath_Lua) then
		logE(string.format("文件%q不存在，请先保存%q", resPath_Lua, resPath))
		return
	end

	local cell = require("app.cell.LayerCell").new(self, resPath, pos)
    self:addCell(cell)
    self:changeFocusCell(cell, true)

    self.dirty = true
    return cell
end

function EditContext:createRevivePoint(pos)
	local cell = require("app.cell.RevivePointCell").new(self, pos)
    self:addCell(cell)
    self:changeFocusCell(cell, true)

    self.dirty = true
    return cell
end

return EditContext