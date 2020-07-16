-- @Author : fangcheng
-- @Date   : 2020-05-11 18:23:44
-- @remark : 

local ENABLE_TEST = false


local function init()
	require("functions")
	local Lang = require("WDConfig.Lang")
	
	STR = function(key)
		local data = Lang.getData(key)
		if data then
			if G_Lang == "cn" then
				return data.cn
			end
			return data.en
		end
		return key
	end
end

local function doExport()
	local export = require("export")
	local M = export.new(G_Input, G_Output)

	if M:publish() then
		logI(STR("PUBLISH_SUCCESS"))
		os.exit(0)
	else
		logI(STR("PUBLISH_FAILED"))
		os.exit(1)
	end
end

local function main()
	init()

	if ENABLE_TEST then
		G_Input 	= "./../test/"
		G_Output 	= "./../export/"
		G_Lang		= "en"
	else
		args = args or {}
		if #args < 3 then
			logE("Incoming args error")
			return
		end

		G_Input  = args[2]
		G_Output = args[3]
		G_Lang	 = args[4] or "en"
	end

	doExport()
end

xpcall(main, function(err)
    local msg = debug.traceback(err, 3)
    logE(msg)
    os.exit(2)
end)
