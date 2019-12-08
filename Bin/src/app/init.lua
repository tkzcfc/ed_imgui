require("app.initcomlib")
require("app.common.HelperExt")
require("app.common.GameEx")

cc.exports._MyG = {}

cc.exports.G_ROOT_NODE_NAME = "_root"

cc.exports.G_AnalyStudioResource = require("app.logic.AnalyStudioResource")

cc.exports.G_GEN_COM_FILE_HEADER = function()
	local fmt = [[
-- This file is generated automatically.
-- Generated automatically by ed_imgui on %s.

]]
	return string.format(fmt, os.date())
end

-- _MyG.MouseEventDispatcher = require("app.common.MouseEventDispatcher").new()
_MyG.KeyboardStateMng = require("app.common.KeyboardStateMng").new()

function _MyG.require(_mname)
    package.loaded[_mname] = nil
    return require(_mname)
end

-- 是否使用系统字体
_MyG.UseSystemChineseFont = false
-- 中文字体名称
_MyG.ChineseFont = "jdht.TTF"
_MyG.ChineseFontSize = 15
_MyG.SupportChineseFont = false

require("app.imgui.ComWidget")

_MyG.Functions = require("app.common.Functions")
_MyG.GlobalData = require("app.common.GlobalData").new()
_MyG.ProjectData = require("app.common.ProjectData").new()


-- 设计分辨率
_MyG.Editor_DesignResolution = cc.size(1134, 750)

