-- @Author : fc
-- @Date   : 2021-07-09 16:55:31
-- @remark : 



-- local arg = "E:/fc_test/git_pro/editor_img/bin/tools/publish-tool_pro/build/Debug/publish-tool.exe E:/fc_test/git_pro/editor_img/test/alpha/ E:/fc_test/git_pro/editor_img/test/out/alpha/ en"
-- os.execute(arg)


local str = "E:/fc_test/git_pro/editor_img/bin/workspace/assets/alpha.png"
print(string.match(str, "([^/\\]-)$"))



-- local str = [[
-- [Warning]       Key in "E:/fc_test/git_pro/editor_img/bin/workspace/assets/alpha/map.asset : [PluginRevivePoint -> userdata] -> userdata" is empty
-- [Warning]       Key in "E:/fc_test/git_pro/editor_img/bin/workspace/assets/alpha/map.asset : [PluginRevivePoint -> userdata] -> userdata" is empty
-- [Warning]       Export of file "E:/fc_test/git_pro/editor_img/bin/workspace/assets/alpha/role_1.asset" failed, unknown type "role"
-- [Info]  publish finished
-- ]]


-- local func = string.gmatch(str, "()")

-- print(func())
