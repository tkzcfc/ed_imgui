-- @Author: fangcheng
-- @Date:   2021-11-11 17:00:46
-- @remark: spine动画

local Asset_File = import(".Asset_File")
local Asset_Spine = class("Asset_Spine", Asset_File)

function Asset_Spine:init(fullPath)
    Asset_Spine.super.init(self, fullPath)

    self.property.resType       = Asset.ResType.SPINE
    self.property.thumbnailTexture      = EditorIconContent:get(EditorIcon.ICON_SKELETON)
end


return Asset_Spine
