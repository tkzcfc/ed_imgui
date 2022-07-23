-- @Author: fangcheng
-- @Date:   2020-04-12 14:13:28
-- @Description: widget编辑

local BaseEditorCocos = import(".BaseEditorCocos")
local CoordinateAxis = require("app.common.CoordinateAxis")

local EditorWidget = class("EditorWidget", BaseEditorCocos)

function EditorWidget:ctor(name, asset)
	EditorWidget.super.ctor(self, name, asset)

    --坐标轴
    local coord = CoordinateAxis:create()
    coord:setLineLength(10000)
    self.render:addChild(coord)


    self:addPlugin(require("app.plugin.PluginLineRect").new())
    self:addPlugin(require("app.plugin.PluginRefResources").new())
end

return EditorWidget
