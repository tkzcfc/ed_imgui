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
	local M = export.new(G_Input, G_Output, G_CopyResource)

	if M:publish() then
		logI(STR("PUBLISH_SUCCESS"))
		os.exit(0)
	else
		logE(STR("PUBLISH_FAILED"))
		os.exit(1)
	end
end

local function main()
	init()

	if ENABLE_TEST then
		--[[
"E:/fc_test/git_pro/editor_img/bin/tools/publish-tool_pro/build/Debug/publish-tool.exe 
E:/fc_test/git_pro/editor_img/test/alpha/
E:/fc_test/git_pro/editor_img/test/out/alpha/ en
"

E:/fc_test/git_pro/editor_img/bin/tools/publish-tool/publish-tool.exe 
E:/fc_test/git_pro/editor_img/bin/workspace/assets//alpha/ 
E:/fc_test/git_pro/editor_img/bin/publish/assets/alpha/ cn
]]
		G_Input 	= "E:/fc_test/git_pro/editor_img/bin/workspace/assets//alpha/"
		G_Output 	= "E:/fc_test/git_pro/editor_img/bin/publish/assets/alpha/"
		G_Lang		= "en"
		G_CopyResource = false
	else
		args = args or {}
		if #args < 3 then
			logE("Incoming args error")
			return
		end

		G_Input  = args[2]
		G_Output = args[3]
		G_Lang	 = args[4] or "en"

		G_CopyResource = false
		for k, v in pairs(args) do
			if v == "copyResource" then
				G_CopyResource = true
			end
		end
	end

	doExport()
end

xpcall(main, function(err)
    local msg = debug.traceback(err, 3)
    logE(msg)
    os.exit(2)
end)
