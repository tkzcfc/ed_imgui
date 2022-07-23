-- @Author: fangcheng
-- @Date:   2021-08-07 21:07:10
-- @remark: 

local Asset = import(".Asset")
local Asset_File = import(".Asset_File")
local Asset_Role = class("Asset_Role", Asset_File)

function Asset_Role:init(fullPath)
    Asset_Role.super.init(self, fullPath)
    
    self.property.resType       = Asset.ResType.ROLE

    local data = self.assetManager:getAssetData(fullPath)
    self.property.showName = Tools:replaceString(self.property.showName, ".asset", "." .. data.type)
    self.property.thumbnailTexture = EditorIconContent:get(EditorIcon.ICON_SCENE)
end



return Asset_Role