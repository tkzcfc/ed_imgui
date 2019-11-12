
local M = {}

-- 三个平台判断
local TARGET_PALTFORM = cc.Application:getInstance():getTargetPlatform()

M.TARGET_PALTFORM = TARGET_PALTFORM
M.IS_IOS = TARGET_PALTFORM == cc.PLATFORM_OS_IPHONE or TARGET_PALTFORM == cc.PLATFORM_OS_IPAD or TARGET_PALTFORM == cc.PLATFORM_OS_MAC 
M.IS_ANDROID = TARGET_PALTFORM == cc.PLATFORM_OS_ANDROID
M.IS_WINDOWS = TARGET_PALTFORM == cc.PLATFORM_OS_WINDOWS
M.IS_PC = TARGET_PALTFORM == cc.PLATFORM_OS_WINDOWS or TARGET_PALTFORM == cc.PLATFORM_OS_MAC

-- 默认字体相关
M.DEFAULT_SYSTEM_FONT = "Helvetica"

-- 屏幕宽高
M.SCREEN_WIDTH =(cc.Director:getInstance():getOpenGLView():getVisibleSize().width)
M.SCREEN_HEIGHT =(cc.Director:getInstance():getOpenGLView():getVisibleSize().height)


M.DEBUG = M.IS_PC

return M
