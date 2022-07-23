-- @Author: fangcheng
-- @Date:   2021-06-26 18:23:48
-- @remark: cocostudio骨骼动画

local Asset_File = import(".Asset_File")
local Asset_ExportJson = class("Asset_ExportJson", Asset_File)

function Asset_ExportJson:init(fullPath)
    Asset_ExportJson.super.init(self, fullPath)

    self.property.resType       = Asset.ResType.EXPORTJSON
    self.property.thumbnailTexture      = EditorIconContent:get(EditorIcon.ICON_SKELETON)
end


return Asset_ExportJson
