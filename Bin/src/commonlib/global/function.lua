-- @Author: fangcheng
-- @URL: github.com/tkzcfc
-- @Date:   2019-10-17 21:26:05
-- @Last Modified by:   fangcheng
-- @Last Modified time: 2020-02-29 21:45:09
-- @Description: 全局函数定义

local M = {}

-- 必须定义在M里面且不能为:
-- 示例
-- function M.globalTest()
-- end

-- 设置table只读
function M.read_only(inputTable)
    local travelled_tables = {}
    local function __read_only(tbl)
        if not travelled_tables[tbl] then
            local tbl_mt = getmetatable(tbl)
            if not tbl_mt then
                tbl_mt = {}
                setmetatable(tbl, tbl_mt)
            end

            local proxy = tbl_mt.__read_only_proxy
            if not proxy then
                proxy = {}
                tbl_mt.__read_only_proxy = proxy
                local proxy_mt = {
                    __index = tbl,
                    __newindex = function (t, k, v) error("error write to a read-only table with key = " .. tostring(k)) end,
                    __pairs = function (t) return pairs(tbl) end,
                    -- __ipairs = function (t) return ipairs(tbl) end,  
                    __len = function (t) return #tbl end,
                    __read_only_proxy = proxy
                }
                setmetatable(proxy, proxy_mt)
            end
            travelled_tables[tbl] = proxy
            for k, v in pairs(tbl) do
                if type(v) == "table" then
                    tbl[k] = __read_only(v)
                end
            end
        end
        return travelled_tables[tbl]
    end
    return __read_only(inputTable)
end

local set_msg_new_tab_mt = nil
function M.set_msg_new_tab(tabData, msgName)

    local msgName = msgName or tabData.__MsgName__

	if type(msgName) ~= "string" then error("消息tab 没有消息名称:" .. tostring(msgName)) end

	if not set_msg_new_tab_mt then
	    set_msg_new_tab_mt = { }

		set_msg_new_tab_mt.__index = function(tab, key)
			error("消息[" .. msgName .. "] 访问不存在的成员变量:" .. key)
		end

		set_msg_new_tab_mt.__newindex = function(tab, key, val)
			if type(key) == "number" then
				rawset(tab, key, val)
			else
				error("消息[" .. msgName .. "] 写入不存在的成员变量:" .. key)
			end
		end
	end

    setmetatable(tabData, set_msg_new_tab_mt)

    for k, v in pairs(tabData) do
        if (type(v) == "table") then
            set_msg_new_tab(v, msgName .. "::" .. k )
        end
    end
end

function M.set_on_msg_tab(tabData, msgName)

    local msgName = msgName or tabData.__MsgName__

	if type(msgName) ~= "string" then error("消息tab 没有消息名称" .. tostring(msgName)) end

	if not set_on_msg_tab_mt then
	    set_on_msg_tab_mt = { }

		set_on_msg_tab_mt.__index = function(tab, key)
			error("消息[" .. msgName .. "] 访问不存在的成员变量:" .. key)
		end

		set_on_msg_tab_mt.__newindex = function(tab, key, val)
				error("消息[" .. msgName .. "] 写入不存在的成员变量:" .. key)
		end
	end

    setmetatable(tabData, set_on_msg_tab_mt)

    for k, v in pairs(tabData) do
        if (type(v) == "table") then
            set_on_msg_tab(v, msgName .. "::" .. k )
        end
    end
end

-- 格式化lua值
function M.format_lua_value(inValue, maxCallCount)
    if type(inValue) ~= "table" then
        return tostring(inValue)
    end

    -- 递归次数，防止循环引用时无限递归
    local callCount = 0
    maxCallCount = maxCallCount or 1000

    local formatting = "{\n"

    local function format_lua_table (lua_table, indent)
    	callCount = callCount + 1
        if callCount > maxCallCount then
        	error("lua_table中有循环引用现象")
        	return
        end

        indent = indent or 0
        
        for k, v in pairs(lua_table) do
            if type(k) == "string" then
                k = string.format("%q", k)
            end
            local szSuffix = ""
            if type(v) == "table" then
                szSuffix = "{"
            end
            local szPrefix = string.rep("    ", indent)
            formatting = formatting .. szPrefix.."["..k.."]".." = "..szSuffix
            if type(v) == "table" then
                formatting = formatting.."\n"
                format_lua_table(v, indent + 1)
                formatting = formatting .. szPrefix.."},\n"
            else
                local szValue = ""
                if type(v) == "string" then
                    szValue = string.format("%q", v)
                else
                    szValue = tostring(v)
                end
                formatting = formatting..szValue..",\n"
            end
        end
    end
    format_lua_table(inValue, 1)
    return formatting.."}"
end

-- 输出lua值
function M.print_lua_value(inValue)
	if G_MAC.DEBUG then
		print(M.format_lua_value(inValue))
	end
end

-- 退出游戏
function M.appExit()
    G_SysEventEmitter:emit("event_appWillExit")
    if G_MAC.IS_IOS then
        os.exit(0)
    else
        cc.Director:getInstance():endToLua()
    end
end

-------------------------------------------------------------------------------------------------------------

for k,v in pairs(M) do
	cc.exports[k] = v
end

