-- @Author: fangcheng
-- @Date:   2021-06-21 21:02:11
-- @remark: 编辑器内置资源


local EditorIcon = enum {
    "THUMBNAIL_DISK",
    "THUMBNAIL_FOLDER",
    "THUMBNAIL_FILE",
    "THUMBNAIL_PNG",
    "THUMBNAIL_PLIST",
    "PANEL_COLLAPSED_ARROW",
    "PANEL_EXPANDED_ARROW",

    "DEFAULT_SPRITE",
    "DEFAULT_IMAGE",
    "DEFAULT_REVIVEPOINT",

    "ICON_SKELETON",

    -- Overload Icons
    "BUTTON_PAUSE",
    "BUTTON_STOP",
    "BUTTON_PRE",
    "BUTTON_NEXT",
    "BUTTON_REFRESH",
    "BUTTON_PLAY",
    "ICON_FILE",
    "ICON_FOLDER",
    "ICON_TEXTURE",
    "ICON_MODEL",
    "ICON_SHADER",
    "ICON_MATERIAL",
    "ICON_SCENE",
    "ICON_SOUND",
    "ICON_SCRIPT",
    "ICON_FONT",
    "BILL_PLIGHT",
    "BILL_SLIGHT",
    "BILL_DLIGHT",
    "BILL_ABLIGHT",
    "BILL_ASLIGHT",
}

local EditorIconContent = {}

function EditorIconContent:load()
    local t = {}
    t[EditorIcon.THUMBNAIL_DISK]            = self:loadTexture("disk.png")
    t[EditorIcon.THUMBNAIL_FOLDER]          = self:loadTexture("folder.png")
    t[EditorIcon.THUMBNAIL_FILE]            = self:loadTexture("file.png")
    t[EditorIcon.THUMBNAIL_PNG]             = self:loadTexture("plist.png")
    t[EditorIcon.THUMBNAIL_PLIST]           = self:loadTexture("plist.png")
    t[EditorIcon.PANEL_COLLAPSED_ARROW]     = self:loadTexture("panel_collapsed_arrow.png")
    t[EditorIcon.PANEL_EXPANDED_ARROW]      = self:loadTexture("panel_expanded_arrow.png")


    t[EditorIcon.DEFAULT_SPRITE]            = self:loadTexture("Sprite.png")
    t[EditorIcon.DEFAULT_IMAGE]             = self:loadTexture("ImageFile.png")
    t[EditorIcon.DEFAULT_REVIVEPOINT]       = self:loadTexture("RevivePoint.png")

    t[EditorIcon.ICON_SKELETON]             = self:loadTexture("skeleton.png")

    t[EditorIcon.BUTTON_PAUSE]              = self:loadTexture("Button_Pause.png")
    t[EditorIcon.BUTTON_STOP]               = self:loadTexture("Button_Stop.png")
    t[EditorIcon.BUTTON_PRE]                = self:loadTexture("Button_Pre.png")
    t[EditorIcon.BUTTON_NEXT]               = self:loadTexture("Button_Next.png")
    t[EditorIcon.BUTTON_REFRESH]            = self:loadTexture("Button_Refresh.png")
    t[EditorIcon.BUTTON_PLAY]               = self:loadTexture("Button_Play.png")
    t[EditorIcon.ICON_FILE]                 = self:loadTexture("Icon_Unknown.png")
    t[EditorIcon.ICON_FOLDER]               = self:loadTexture("Icon_Folder.png")
    t[EditorIcon.ICON_TEXTURE]              = self:loadTexture("Icon_Texture.png")
    t[EditorIcon.ICON_MODEL]                = self:loadTexture("Icon_Model.png")
    t[EditorIcon.ICON_SHADER]               = self:loadTexture("Icon_Shader.png")
    t[EditorIcon.ICON_MATERIAL]             = self:loadTexture("Icon_Material.png")
    t[EditorIcon.ICON_SCENE]                = self:loadTexture("Icon_Scene.png")
    t[EditorIcon.ICON_SOUND]                = self:loadTexture("Icon_Sound.png")
    t[EditorIcon.ICON_SCRIPT]               = self:loadTexture("Icon_Script.png")
    t[EditorIcon.ICON_FONT]                 = self:loadTexture("Icon_Font.png")
    t[EditorIcon.BILL_PLIGHT]               = self:loadTexture("Bill_Point_Light.png")
    t[EditorIcon.BILL_SLIGHT]               = self:loadTexture("Bill_Spot_Light.png")
    t[EditorIcon.BILL_DLIGHT]               = self:loadTexture("Bill_Directional_Light.png")
    t[EditorIcon.BILL_ABLIGHT]              = self:loadTexture("Bill_Ambient_Box_Light.png")
    t[EditorIcon.BILL_ASLIGHT]              = self:loadTexture("Bill_Ambient_Sphere_Light.png")

    self.cacheTexture = t
end

function EditorIconContent:loadTexture(name)
    local path = string.format("res/Built-in/%s", name)
    local textureId = Tools:getImguiTextureID(path)
    return textureId
end

function EditorIconContent:get(key)
    local textureId = self.cacheTexture[key]
    assert(textureId ~= nil)
    return textureId
end

EditorIconContent:load()

cc.exports.EditorIcon = EditorIcon
cc.exports.EditorIconContent = EditorIconContent



