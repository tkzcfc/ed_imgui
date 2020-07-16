-- @Author: fangcheng
-- @URL: github.com/tkzcfc
-- @Date:   2020-04-12 14:13:28
-- @Last Modified by:   fangcheng
-- @Last Modified time: 2020-05-30 22:04:47
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
