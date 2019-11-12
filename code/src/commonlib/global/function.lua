-- 全局函数定义

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


-------------------------------------------------------------------------------------------------------------

for k,v in pairs(M) do
	cc.exports[k] = v
end

