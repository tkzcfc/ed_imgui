local BackgroundCell = require("app.cell.BackgroundCell")

local MapBGCell = class("MapBGCell", BackgroundCell)




local LayerEditInfo = 
{
    {RESOURCE_KEY = "EA_RESOURCE_MAP_BG_LAYER", VISIBLE_CKBOX_KEY = "EA_VISIBLE_CKBOX_MAP_BG_LAYER", Zorder = 1, LayerKey = "backgroundLayer"},
    {RESOURCE_KEY = "EA_RESOURCE_MAP_GM_LAYER", VISIBLE_CKBOX_KEY = "EA_VISIBLE_CKBOX_MAP_GM_LAYER", Zorder = 2, LayerKey = "gameLayer"},
    {RESOURCE_KEY = "EA_RESOURCE_MAP_FG_LAYER", VISIBLE_CKBOX_KEY = "EA_VISIBLE_CKBOX_MAP_FG_LAYER", Zorder = 3, LayerKey = "foregroundLayer"},
}

local retTmp


function MapBGCell:ctor(context)
	MapBGCell.super.ctor(self, context)

	self.context:freezeCell(true)

    self.layerVisibleTagArr = {}
    for k,v in pairs(LayerEditInfo) do
        self.layerVisibleTagArr[k] = true
    end
end

function MapBGCell:onGUI()
	self:onGUI_MapLayer(1, self.context.backgroundLayer)
	self:onGUI_MapLayer(2, self.context.gameLayer)
	self:onGUI_MapLayer(3, self.context.foregroundLayer)

    local isVisible = self.context.isHideAllRevivePoint
    retTmp, isVisible = ImGui.Checkbox(STR("EA_IS_HIDE_ALL_REVIVEPOINT"), isVisible)
    if retTmp then
        self.context:setIsHideAllRevivePoint(isVisible)
        self:dataDirty()
    end
end

function MapBGCell:onGUI_MapLayer(key, layer)
	local curLayerInfo = LayerEditInfo[key]
	local layer = self.context[curLayerInfo.LayerKey]

	if layer then
		Tools:imgui_inputText(STR(curLayerInfo["RESOURCE_KEY"]), layer.resPath, 512, ImGuiInputTextFlags_ReadOnly)
	else
		Tools:imgui_inputText(STR(curLayerInfo["RESOURCE_KEY"]), "", 512, ImGuiInputTextFlags_ReadOnly)
	end

	if ImGui.BeginDragDropTarget() then
    	if Tools:check_AcceptDragDropPayload("DRAG_MOVE_CELL_LAYER") then
    		local dragPath = Tools:AcceptDragDropPayload("DRAG_MOVE_CELL_LAYER")
    		dragPath = _MyG.Functions:getRelativePath(dragPath)

    		if layer then
    			local resPath_Lua = Tools:replaceString(dragPath, _MyG.GlobalData:getFileFullExtension("LAYER"), ".lua")
            	if not cc.FileUtils:getInstance():isFileExist(resPath_Lua) then
            	    logE(string.format("文件%q不存在，请先保存%q", resPath_Lua, dragPath))
            	else
					layer:setResource(dragPath)
                	layer:updateDrawBase()
            	end
    		else
    			local cell = self.context:createLayer(dragPath, 0, cc.p(0, 0))
    			if cell then
                    cell:setVisiblePublishLR(key == 2)
    				cell.renderNode:setLocalZOrder(curLayerInfo.Zorder)
    				self.context[curLayerInfo.LayerKey] = cell
    				self.context:changeFocusCell()
    			end
    		end
    	end
    	ImGui.EndDragDropTarget()
    end

    if layer then
        retTmp, self.layerVisibleTagArr[key] = ImGui.Checkbox(STR(curLayerInfo["VISIBLE_CKBOX_KEY"]), self.layerVisibleTagArr[key])
        if retTmp then
            layer.renderNode:setVisible(self.layerVisibleTagArr[key])
            self:dataDirty()
        end
    end
end

-- 序列化
function MapBGCell:serialize()
    local t = MapBGCell.super.serialize(self)
    t.layerVisibleTagArr = self.layerVisibleTagArr
    return t
end

-- 反序列化
function MapBGCell:deserialize(data)
    if data == nil then
        return
    end
    MapBGCell.super.deserialize(self, data)
    self.layerVisibleTagArr = data.layerVisibleTagArr

    for key,v in pairs(self.layerVisibleTagArr) do
        local curLayerInfo = LayerEditInfo[key]
        local layer = self.context[curLayerInfo.LayerKey]
        if layer then
            layer.renderNode:setVisible(self.layerVisibleTagArr[key])
        end
    end
end

-- 发布
function MapBGCell:publish()
    local t = MapBGCell.super.publish(self)

    local function copyTable(srcTab, dstTab)
        if srcTab == nil then
            return
        end
        for k,v in pairs(srcTab) do
            table.insert(dstTab, v)
        end
    end

    if self.context.gameLayer then
        local bgCellData = self.context.gameLayer.bgCellData
        local line_data = bgCellData.line_data
        local child_line_data = bgCellData.child_line_data
        local rect_data = bgCellData.rect_data
        local child_rect_data = bgCellData.child_rect_data

        local out_line_data = {}
        copyTable(line_data, out_line_data)
        copyTable(child_line_data, out_line_data)

        local out_rect_data = {}
        copyTable(rect_data, out_rect_data)
        copyTable(child_rect_data, out_rect_data)

        t.line_data = out_line_data
        t.rect_data = out_rect_data
    else
        t.line_data = {}
        t.rect_data = {}
    end

    return t
end

return MapBGCell
