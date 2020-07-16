-- @Author: fangcheng
-- @Date:   2020-06-02 21:55:02
-- @remark: 

local BaseEditor = import(".BaseEditor")
local EditorLayer = import(".EditorLayer")
local EditorMap = class("EditorMap", EditorLayer)

function EditorMap:ctor(name, asset)
	EditorMap.super.ctor(self, name, asset)
    self:removePluginByName("PluginLineRect")
    self:removePluginByName("PluginLayerSize")
    self:addPlugin(require("app.plugin.PluginMapLayer").new())
    self:addPlugin(require("app.plugin.PluginRevivePoint").new())
end

-- @brief 资源拖拽
function EditorMap:onAssetDragEnd(assetItem, pos)
end

-- @brief ctrl + a
function EditorMap:onKeyBoardAll()
end

-- @brief delete按键事件回调
function EditorMap:onKeyBoardDelete()
	BaseEditor.onKeyBoardDelete(self)
end

-- @brief 元素改变父节点回调
function EditorMap:elementChangeParentHook(tar, newParent)
	return false
end

return EditorMap

