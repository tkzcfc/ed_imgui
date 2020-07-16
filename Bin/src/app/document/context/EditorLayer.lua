-- @Author: fangcheng
-- @URL: github.com/tkzcfc
-- @Date:   2020-05-07 21:23:11
-- @Last Modified by:   fangcheng
-- @Last Modified time: 2020-05-30 22:04:53
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

-- Asset.ResType = {
--     NONE            = -1,           -- 无效资源
--     PNG             = 0,            -- png
--     JPG             = 1,            -- jpg
--     LUA             = 2,            -- lua文件
--     FOLDER          = 3,            -- 文件夹
--     PLIST           = 4,            -- plist文件
--     PLIST_SUBGRAPH  = 5,            -- plist子图
--     WIDGET          = 6,            -- widget
--     LAYER           = 7,            -- 地图层
--     MAP             = 8,            -- 地图
-- }


-- @brief 元素改变父节点回调
function EditorLayer:elementChangeParentHook(tar, newParent)
    logW(STR("CAN_NOT_CHANGE_PARENT_WIDGET"))
    return false
    -- if tar.type == "Widget" then
    --     logW(STR("CAN_NOT_CHANGE_PARENT_WIDGET"))
    --     return false
    -- end
    -- return true
end

return EditorLayer
