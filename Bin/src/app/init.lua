require("app.initcomlib")
require("app.common.lfsex")
require("app.common.HelperExt")
require("app.common.GameEx")
require("app.common.Event")
require("app.common.Enum")

-- 内置缩略图加载
require("app.common.EditorIconContent")

cc.exports._MyG = {}

cc.exports.G_ROOT_NODE_NAME = "_root"

cc.exports.G_AnalyStudioResource = require("app.logic.AnalyStudioResource")

_MyG.MouseEventDispatcher = require("app.common.MouseEventDispatcher").new()
_MyG.KeyboardStateMng = require("app.common.KeyboardStateMng").new()

function _MyG.require(_mname)
    package.loaded[_mname] = nil
    return require(_mname)
end


_MyG.SupportFonts = {}
-- 获取res目录路径
local fullPath = cc.FileUtils:getInstance():fullPathForFilename("LuaExtend.lua")
if fullPath ~= "" then
    local resRoot =  G_Helper.getFileDir(fullPath)
    local files = os.seek_dir(resRoot .. "font", false, function(path, isdir)
        if isdir then return false end

        return G_Helper.getExtension(path) == "ttf"
    end)

    for k, v in pairs(files) do
        local filePath = Tools:GbkToUtf8(v.path)
        local path, name = G_Helper.getFileDir(filePath)
        table.insert(_MyG.SupportFonts, {
            fullPath = filePath,
            fontSize = 15,
            fontName = name,
            path = path,
        })
    end

    table.sort(_MyG.SupportFonts, function(a, b)
        return a.fontName < b.fontName
    end)

    print_lua_value(_MyG.SupportFonts)
end

_MyG.SupportChineseFont = false


-- 设计分辨率
_MyG.Editor_DesignResolution = cc.size(1134, 750)

require("app.manager.init")
require("app.imgui.ComWidget")

_MyG.Functions      = require("app.common.Functions")
_MyG.GlobalData     = require("app.common.GlobalData").new()
_MyG.EditorProject  = require("app.common.EditorProject").new()
_MyG.CreateAsset    = require("app.asset.CreateAsset")

_MyG.ProjectAssetManager = require("app.asset.AssetManager").new()
_MyG.CocosAssetManager   = require("app.asset.AssetManager").new(_MyG.GlobalData.CocosResourcePath)
_MyG.GameAssetManager    = require("app.asset.AssetManager").new()

_MyG.OpenAsset      = require("app.asset.OpenAsset")


-- 是不是序列化到本地文件
_MyG.IsLocalizeMode = false

require("app.elements.init")

cc.FileUtils:getInstance():setWritablePath(os.currentdir())


local director = cc.Director:getInstance()
local textureCache = director:getTextureCache()
-- -- 监听窗口大小改变
-- local listener = cc.EventListenerCustom:create("glview_window_resized", function()
--     G_SysEventEmitter:emit(SysEvent.EVENT_WINDOW_RESIZED)
-- end)
-- director:getEventDispatcher():addEventListenerWithFixedPriority(listener, -1)

-- @brief 纹理清理函数
local cache_textureNum = 0
cc.exports.textureCleanup = function()
    -- logW(textureCache:getCachedTextureInfo())
    -- logW("removeUnusedSpriteFrames--->")

    -- <TextureCache | Number of textures = 14>
    -- 获取描述中的纹理数量
    local info = textureCache:getDescription()
    local textureNum = string.match(info, "(%d+)%>$")
    if textureNum then textureNum = tonumber(textureNum) end

    if textureNum then
        -- 超过上次一定数量之后才清理
        if textureNum - cache_textureNum > 20 then
            cache_textureNum = textureNum
            display.removeUnusedSpriteFrames()
            -- print("removeUnusedSpriteFrames--------->>")
        end
    else
        -- 资源清理
        display.removeUnusedSpriteFrames()
        -- print("removeUnusedSpriteFrames--------->>")
    end


    -- logW(textureCache:getCachedTextureInfo())
end

_MyG.sysStorage = G_Class.StorageObject.new("sys_set")

