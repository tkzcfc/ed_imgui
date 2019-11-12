
cc.FileUtils:getInstance():setPopupNotify(false)
cc.FileUtils:getInstance():addSearchPath("src/")
cc.FileUtils:getInstance():addSearchPath("res/")

require "config"
require "cocos.init"

local function main()
    cc.exports.logL = print
	cc.exports.logI = print
	cc.exports.logW = print
	cc.exports.logE = print
	require("app.init")
    require("app.MyApp"):create():run()
    cc.Director:getInstance():setAnimationInterval(1 / 30)
end

__G__TRACKBACK__ = function(msg)
    local msg = debug.traceback(msg, 3)
    logE(msg)
    return msg
end

local status, msg = xpcall(main, __G__TRACKBACK__)
if not status then
    logE(msg)
end
