-- @Author: fangcheng
-- @Date:   2020-05-07 21:23:11
-- @Description: layer编辑

local EditorWidget = import(".EditorWidget")
local EditorLayer = class("EditorLayer", EditorWidget)

function EditorLayer:ctor(name, asset)
	EditorLayer.super.ctor(self, name, asset)

    -- self:removePluginByName("PluginLineRect")
    self:addPlugin(require("app.plugin.PluginLayerSize").new())
end

-- @brief 资源拖拽
function EditorLayer:onAssetDragEnd(assetItem, pos)
	EditorLayer.super.onAssetDragEnd(self, assetItem, pos)

    local property  = assetItem.property
    local resType = property.resType

    if resType == Asset.ResType.WIDGET then
        self:genElement(function()
            local data = {
                position = pos,
                assetFile = property.relativePath,
            }
    
            return _MyG.ElementFactory:spawn("Widget", {data = data}, self)
        end)
    end
end

-- @brief 元素改变父节点回调
function EditorLayer:elementChangeParentHook(tar, newParent)
    logW(STR("CAN_NOT_CHANGE_PARENT_IN_LAYER"))
    return false
    -- if tar.type == "Widget" then
    --     logW(STR("CAN_NOT_CHANGE_PARENT_WIDGET"))
    --     return false
    -- end
    -- return true
end

return EditorLayer
