-- @Author: fangcheng
-- @Date:   2020-05-30 22:48:07
-- @Description: 

local Asset_File = import(".Asset_File")
local Asset_Lua = class("Asset_Lua", Asset_File)

function Asset_Lua:init(fullPath)
	Asset_Lua.super.init(self, fullPath)

	self.property.resType 		= Asset.ResType.LUA
    self.property.thumbnailTexture = EditorIconContent:get(EditorIcon.ICON_SCRIPT)
end


return Asset_Lua
