local WidgetBaseCell = require("app.cell.WidgetBaseCell")
local CocostudioCell = class("CocostudioCell", WidgetBaseCell)

local FileUtilsInstance = cc.FileUtils:getInstance()

function CocostudioCell:ctor(context, resPath, pos)
	CocostudioCell.super.ctor(self, context)
    self.resType = 0
    self:setResource(resPath, pos)

    self.onAssetContentUpdateHandle = function(key)
        if key and key == self.resPath then
            self:setResource(self.resPath)
            self:dataDirty()
            print("update asset", key)
        end
    end
    G_SysEventEmitter:on("onAssetContentUpdate", self.onAssetContentUpdateHandle)
end

function CocostudioCell:setResource(resPath, pos)
    self.resPath = resPath
    if resPath ~= nil and not FileUtilsInstance:isFileExist(resPath) then
        logE(resPath, "文件不存在")
        self.resPath = "Default/DefaultStudioFile.lua"
        self:dataDirty()
    end

    local studio_ui = G_Helper.loadStudioFile(self:getLuaPath(self.resPath))
    
    if studio_ui.animation then
        studio_ui.animation:gotoFrameAndPlay(0, true)
        studio_ui.root:runAction(studio_ui.animation)
    end

    self:setupNode(studio_ui.root, pos)
end

function CocostudioCell:setupNode(inNode, pos)
    if pos == nil then
        pos = cc.p(self:getPosition())
    end

    self:disEnableTouch(inNode)

    self.nodeMinPos, self.nodeMaxPos, self.nodeContentSize = G_Helper.getNodeValidSize(inNode)

    local renderNode = self.renderNode

    if renderNode == nil then
        renderNode = cc.Node:create()
        self:setRenderNode(renderNode)
    end

    if self.cache_studio_node then
        self.cache_studio_node:removeFromParent()
        self.cache_studio_node = nil
    end
    self.cache_studio_node = inNode

    local children = renderNode:getChildren()
    for k,v in pairs(children) do
        v:retain()
    end
    renderNode:removeAllChildren()
    renderNode:addChild(inNode)

    for k,v in pairs(children) do
        renderNode:addChild(v)
        v:release()
    end

    renderNode:setContentSize(self.nodeContentSize)
    renderNode:setAnchorPoint(cc.p(0, 0))

    self:setPosition(pos.x, pos.y)
end

function CocostudioCell:getReferenceResources()
    return G_AnalyStudioResource:getReferenceResources(self.resPath)
end

function CocostudioCell:onRemove()
    G_SysEventEmitter:removeListener("onAssetContentUpdate", self.onAssetContentUpdateHandle)
    self.onAssetContentUpdateHandle = nil
    CocostudioCell.super.onRemove(self)
end

function CocostudioCell:updateDrawBase()
    if self.renderNode == nil then
        return
    end
    if self.drawBaseNode == nil then
        WidgetBaseCell.updateDrawBase(self)
    end

    self.drawBaseNode:clear()
    self.drawBaseNode:drawPoint(cc.p(0, 0), 5, WidgetBaseCell.PointColor)
    self.drawBaseNode:drawRect(self.nodeMinPos, self.nodeMaxPos, WidgetBaseCell.LineColor)
end

function CocostudioCell:getLuaPath(path)
    path = Tools:replaceString(path, ".lua", "")
    path = Tools:replaceString(path, "/", ".")
    path = Tools:replaceString(path, "\\", ".")
    return path
end

function CocostudioCell:disEnableTouch(root)
    local function run(node)
        if node.setTouchEnabled then
            node:setTouchEnabled(false)
        end
        self:bindFocusCall(node)
        local children = node:getChildren()
        for k,v in pairs(children) do
            run(v)
        end
    end

    run(root)
end

function CocostudioCell:getTypeName()
	return "CocostudioFile"
end

function CocostudioCell:bool_can_edit_size()
    return false
end

function CocostudioCell:onGUI()
	CocostudioCell.super.onGUI(self)

	if not ImGui.CollapsingHeader(STR("EA_FEATURES"), ImGuiTreeNodeFlags_DefaultOpen) then
		return
	end
    
	Tools:imgui_inputText(STR("EA_RESOURCE"), self.resPath, 512, ImGuiInputTextFlags_ReadOnly)

    if ImGui.BeginDragDropTarget() then
    	if Tools:check_AcceptDragDropPayload("DRAG_MOVE_CELL_LUA") then
    		local dragPath = Tools:AcceptDragDropPayload("DRAG_MOVE_CELL_LUA")
    		dragPath = _MyG.Functions:getRelativePath(dragPath)
            self:setResource(dragPath)
            self:dataDirty()
            self:updateDrawBase()
    	end
    	ImGui.EndDragDropTarget()
    end
end

local tmpTabNumArr = {}
local retTmp

function CocostudioCell:onGUI_Base()
    tmpTabNumArr[1], tmpTabNumArr[2] = self:getPosition()

    if ImGui.DragFloat2(STR("EA_POS"), tmpTabNumArr, 1) then
        self:setPosition(tmpTabNumArr[1], tmpTabNumArr[2])
        self:dataDirty()
    end

    local zorder = self.renderNode:getLocalZOrder()
    retTmp, zorder = ImGui.DragInt(STR("EA_Z_ORDER"), zorder, 1)
    if retTmp then
        self.renderNode:setLocalZOrder(zorder)
        self:dataDirty()
    end
end

function CocostudioCell:serialize()
    local positionx, positiony = self:getPosition()
    local zOrder = self.renderNode:getLocalZOrder()

    local output = ""
    output = output .. string.format("\nlocal %s = require(\"app.cell.CocostudioCell\").new(context, %q, cc.p(%f, %f))\n", self.name, self.resPath, positionx, positiony)
    output = output .. string.format("%s:setName(%q)\n", self.name, self.name)
	output = output .. string.format("%s.renderNode:setLocalZOrder(%d)\n", self.name, zOrder)
	output = output .. string.format("context:addCell(%s)\n", self.name)

    local parentName = self:getCocosParentNodeVarName()
    if parentName ~= G_ROOT_NODE_NAME then
        output = output .. string.format("%s.renderNode:retain()\n", self.name)
        output = output .. string.format("%s.renderNode:removeFromParent()\n", self.name)
        output = output .. string.format("%s.renderNode:addChild(%s.renderNode)\n", parentName, self.name)
        output = output .. string.format("%s.renderNode:release()\n", self.name)
    end

    return output
end

function CocostudioCell:publish()
    local zOrder = self.renderNode:getLocalZOrder()
    local parentName = self:getCocosParentNodeVarName()
    local positionx, positiony = self:getPosition()

	local output = ""
	output = output .. string.format("\nlocal %s = G_Helper.loadStudioFile(%q)\n", self.name, self:getLuaPath(self.resPath))

    output = output .. string.format("if %s.animation then\n", self.name)
    output = output .. string.format("%s.animation:gotoFrameAndPlay(0, true)\n", self.name)
    output = output .. string.format("%s.root:runAction(%s.animation)\n", self.name, self.name)
    output = output .. string.format("end\n")

    if zOrder ~= 0 then
        output = output .. string.format("%s.root:setLocalZOrder(%d)\n", self.name, zOrder)
    end

    if positionx ~= 0 or positiony ~= 0 then
        output = output .. string.format("%s.root:setPosition(%.02f,%.02f)\n", self.name, positionx, positiony)
    end

    if self.context.__cname == "LayerEditContext" and parentName == G_ROOT_NODE_NAME then
        output = output .. string.format("%s.boxData = %s\n", self.name, format_lua_value(self:getBox()))
    end

    output = output .. string.format("%s:addChild(%s.root)\n", parentName, self.name)
	return output
end

-- 获取碰撞矩形
function CocostudioCell:getBox()
    local posx = self.nodeMinPos.x + self.renderNode:getPositionX()
    local posy = self.nodeMinPos.y + self.renderNode:getPositionY()
    return cc.rect(posx, posy, self.nodeContentSize.width, self.nodeContentSize.height)
end

return CocostudioCell

