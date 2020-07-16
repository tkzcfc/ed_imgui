-- @Author: fangcheng
-- @URL: github.com/tkzcfc
-- @Date:   2019-10-17 21:26:05
-- @Last Modified by:   fangcheng
-- @Last Modified time: 2020-02-28 21:26:16
-- @Description: commonlib初始化

-- 全局函数导入
require("commonlib.global.function")

-- 宏定义
cc.exports.G_MAC = require("commonlib.global.GameMacros")

-- msg 模块
-- cc.exports.G_MSG = require("commonlib.msg.InitMsgModule")

-- oRoutine
require("commonlib.global.oRoutine")

-- 系统设置
cc.exports.G_LangManager = require("commonlib.global.LangManager").new()

-- Helper
cc.exports.G_Helper = require("commonlib.global.Helper")

-- ui管理
cc.exports.G_PopViewManager = require("commonlib.global.PopViewManager").new()

-- class导出
local class = {}
class.EventEmitter = require("commonlib.class.EventEmitter")
class.Recipient = require("commonlib.class.Recipient")
class.LoadAsync = require("commonlib.class.LoadAsync")
class.Vector = require("commonlib.class.Vector")
class.PopView = require("commonlib.class.PopView")
-- class.MsgListen = require("commonlib.msg.MsgListen")		-- 监听消息继承此类

cc.exports.G_Class = class


cc.exports.G_NetEventEmitter = G_Class.EventEmitter.new()
cc.exports.G_SysEventEmitter = G_Class.EventEmitter.new()
