-- usage: (use instead of ant)
-- tolua++ "-L" "basic.lua" "-o" "ctest_tolua.cpp" -H "ctest_tolua.h" "CTest.pkg"
-- tolua++ "-L" "basic.lua" "-o" "ctest_tolua.cpp" "CTest.pkg"

_is_functions = _is_functions or {}
_to_functions = _to_functions or {}
_push_functions = _push_functions or {}

_disnabel_template_class_arr = {}

_is_enable_template_push_func = true
_is_enable_template_to_func = true
_is_enable_template_is_func = true

local old_get_push_function = get_push_function
local old_get_to_function = get_to_function
local old_get_is_function = get_is_function

if old_get_push_function == nil then

    old_get_push_function = function() return "tolua_pushusertype" end
end

if old_get_to_function == nil then
    old_get_to_function = function() return "tolua_tousertype" end
end

if old_get_is_function == nil then
    old_get_is_function = function() return "tolua_isusertype" end
end

-- 获取类名
function get_real_class_name(t)
    repeat
        oldt = t
        t = string.gsub(t, " $", "")
        t = string.gsub(t, "^ ", "")
    until(oldt == t)

    t = string.gsub(t, "^const ", "")
    t = string.gsub(t, " const$", "")
    t = string.gsub(t, "*const$", "")
    t = string.gsub(t, "&const$", "")

    repeat
        oldt = t
        t = string.gsub(t, "&$", "")
        t = string.gsub(t, "*$", "")
        t = string.gsub(t, " $", "")
        t = string.gsub(t, "^ ", "")
        t = string.gsub(t, " ", "")
    until(oldt == t)
    return t
end

-- 模板匹配
-- sss<aa,bb>
local function templateMatch(strValue)
    local func = string.gmatch(strValue, "(%w+%s*)<%s*(%w*%:*%.*%w*)%s*%**%s*%,*%s*(%w*%:*%.*%w*)%s*%**%s*>")
    if func then
        local templateContainer, arg1, arg2 = func()
        if templateContainer == nil or templateContainer == "" then
            return
        end
        return templateContainer, arg1, arg2
    end
end

function is_disnabel_template_class(t)
    t = get_real_class_name(t)
    for k, v in pairs(_disnabel_template_class_arr) do
        if v == t then
            return true
        end
    end
    return false
end

local replace_push_function_class_tab = {}


-- cc.XX的类名
function push_cc_class_name(className)
    cc_class_name_tab = cc_class_name_tab or {}

    local func = string.gmatch(className, "cc.(%w+)")
    if func then
        local ccName = func()
        if ccName and ccName ~= "" then
            cc_class_name_tab["cc." .. ccName] = ccName
        end
    end
end

function __get_push_function(t)
    local oldt = t
    t = get_real_class_name(t)
    push_cc_class_name(t)

    if not is_disnabel_template_class(t) then
        local func = old_get_push_function(t)
        if func == "tolua_pushusertype" then
            func = "tolua_ext_object_to_luaval"
            
            local templateContainer, arg1, arg2 = templateMatch(oldt)
            if templateContainer and templateContainer ~= "" then
                if templateContainer == "vector" then
                    return "tolua_ext_object_arr_to_luaval<" .. arg1 .. ">"
                elseif templateContainer == "map" then
                    if arg1 == "string" or  arg1 == "std::string" then
                        return "tolua_ext_map_string_object_to_luaval<" .. arg2 .. ">"
                    end
                end
            end
        end

        return func.."<"..t..">"
    end
    return old_get_push_function(t)
end

function get_push_function(t)
    local funcName = __get_push_function(t)
    if funcName ~= "tolua_pushusertype" then
        replace_push_function_class_tab[t] = funcName
    end
    return funcName
end

function __get_to_function(t)
    t = get_real_class_name(t)

    if not is_disnabel_template_class(t) then
        local func = old_get_to_function(t)
        if func == "tolua_tousertype" then
            local templateContainer, arg1, arg2 = templateMatch(oldt)
            if templateContainer and templateContainer ~= "" then
                if templateContainer == "vector" then
                    return "tolua_ext_luaval_to_ccvector<" .. arg1 .. ">"
                elseif templateContainer == "map" then
                    if arg1 == "string" or  arg1 == "std::string" then
                        return "tolua_ext_luaval_to_ccmap_string_key<" .. arg2 .. ">"
                    end
                end
            end
        end
    end

    return old_get_to_function(t)
end

function get_to_function(t)
    local funcName = __get_to_function(t)
    get_push_function(t)
    return funcName
end

function get_is_function(t)
    t = get_real_class_name(t)

    if not is_disnabel_template_class(t) then
        local func = old_get_is_function(t)
        if func == "tolua_isusertype" then
            local templateContainer, arg1, arg2 = templateMatch(oldt)
            if templateContainer and templateContainer ~= "" then
                if templateContainer == "vector" then
                    return "tolua_ext_check_is_table"
                elseif templateContainer == "map" then
                    return "tolua_ext_check_is_table"
                end
            end
        end
    end

    return old_get_is_function(t)
end


_push_functions["LuaFunction"] = "tolua_ext_function_to_luaval"
_push_functions["std::map<std::string,std::string>"] = "tolua_ext_map_string_string_to_luaval"
_push_functions["std::map<std::string,int>"] = "tolua_ext_map_string_int_to_luaval"
_push_functions["std::map<std::string,float>"] = "tolua_ext_map_string_float_to_luaval"
_push_functions["std::map<std::string,double>"] = "tolua_ext_map_string_double_to_luaval"
_push_functions["std::vector<std::string>"] = "tolua_ext_vector_string_to_luaval"
_push_functions["std::vector<int>"] = "tolua_ext_vector_int_to_luaval"
_push_functions["std::vector<float>"] = "tolua_ext_vector_float_to_luaval"
_push_functions["std::vector<double>"] = "tolua_ext_vector_double_to_luaval"
_push_functions["std::vector<Vec2>"] = "tolua_ext_vector_vec2_to_luaval"
_push_functions["Vec2"] = "tolua_ext_vec2_value_to_luaval"
_push_functions["Vec3"] = "tolua_ext_vec3_value_to_luaval"
_push_functions["Size"] = "tolua_ext_size_value_to_luaval"
_push_functions["Rect"] = "tolua_ext_rect_value_to_luaval"
_push_functions["ImColor"] = "tolua_ext_imcolor_value_to_luaval"
_push_functions["ImVec2"] = "tolua_ext_imvec2_value_to_luaval"
_push_functions["ImVec4"] = "tolua_ext_imvec4_value_to_luaval"


_to_functions["LuaFunction"] = "LuaFunction"
_to_functions["std::map<std::string,std::string>"] = "tolua_ext_luaval_to_map_string_string"
_to_functions["std::map<std::string,int>"] = "tolua_ext_luaval_to_map_string_int"
_to_functions["std::map<std::string,float>"] = "tolua_ext_luaval_to_map_string_float"
_to_functions["std::map<std::string,double>"] = "tolua_ext_luaval_to_map_string_double"
_to_functions["std::vector<std::string>"] = "tolua_ext_luaval_to_vector_string"
_to_functions["std::vector<int>"] = "tolua_ext_luaval_to_vector_int"
_to_functions["std::vector<float>"] = "tolua_ext_luaval_to_vector_float"
_to_functions["std::vector<double>"] = "tolua_ext_luaval_to_vector_double"
_to_functions["std::vector<Vec2>"] = "tolua_ext_luaval_to_vector_vec2"
_to_functions["Vec2"] = "tolua_ext_luaval_to_vec2_value"
_to_functions["Vec3"] = "tolua_ext_luaval_to_vec3_value"
_to_functions["Size"] = "tolua_ext_luaval_to_size_value"
_to_functions["Rect"] = "tolua_ext_luaval_to_rect_value"
_to_functions["ImColor"] = "tolua_ext_luaval_to_imcolor_value"
_to_functions["ImVec2"] = "tolua_ext_luaval_to_imvec2_value"
_to_functions["ImVec4"] = "tolua_ext_luaval_to_imvec4_value"


_is_functions["LuaFunction"] = "tolua_ext_check_isfunction"
_is_functions["std::map<std::string,std::string>"] = "tolua_ext_check_is_table"
_is_functions["std::map<std::string,int>"] = "tolua_ext_check_is_table"
_is_functions["std::map<std::string,float>"] = "tolua_ext_check_is_table"
_is_functions["std::map<std::string,double>"] = "tolua_ext_check_is_table"
_is_functions["std::vector<std::string>"] = "tolua_ext_check_is_table"
_is_functions["std::vector<int>"] = "tolua_ext_check_is_table"
_is_functions["std::vector<float>"] = "tolua_ext_check_is_table"
_is_functions["std::vector<double>"] = "tolua_ext_check_is_table"
_is_functions["std::vector<Vec2>"] = "tolua_ext_check_is_table"
_is_functions["Vec2"] = "tolua_ext_check_is_table"
_is_functions["Vec3"] = "tolua_ext_check_is_table"
_is_functions["Size"] = "tolua_ext_check_is_table"
_is_functions["Rect"] = "tolua_ext_check_is_table"
_is_functions["ImColor"] = "tolua_ext_check_is_table"
_is_functions["ImVec2"] = "tolua_ext_check_is_table"
_is_functions["ImVec4"] = "tolua_ext_check_is_table"

_disnabel_template_class_arr = {}

for k, v in pairs(_is_functions) do
    table.insert(_disnabel_template_class_arr, k)
end


local toWrite = {}
local currentString = ''
local out
local WRITE, OUTPUT = write, output

function output(s)
    out = _OUTPUT
    output = OUTPUT -- restore
    output(s)
end

function write(a)
    -- print(a .. "\n\n")
    if out == _OUTPUT then
        currentString = currentString .. a
        if string.sub(currentString,-1) == '\n'  then
            toWrite[#toWrite+1] = currentString
            currentString = ''
        end
    else
        WRITE(a)
    end
end

function post_output_hook(package)
    local result = table.concat(toWrite)
    local function replace(pattern, replacement)
        local k = 0
        local nxt, currentString = 1, ''
        repeat
            local s, e = string.find(result, pattern, nxt, true)
            if e then
                currentString = currentString .. string.sub(result, nxt, s-1) .. replacement
                nxt = e + 1
                k = k + 1
            end
        until not e
        result = currentString..string.sub(result, nxt)
        -- if k == 0 then print('Pattern not replaced', pattern) end
    end

      replace([[*((LuaFunction*)]], [[(]])
      
      

      replace('\t', '    ')


    for k, v in pairs(replace_push_function_class_tab) do
        local pattern = string.format([[#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((%s)(tolua_ret));
     %s(tolua_S,tolua_obj,"%s");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(%s));
     %s(tolua_S,tolua_obj,"%s");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif]], k, v, k, k, v, k)
        local replacement = string.format([[   %s(tolua_S, tolua_ret, "%s");]], v, k)
        replace(pattern, replacement)

        replace(string.format("*((%s*)", k), "(")

        replace(v .. "(tolua_S,(void*)&self->", v.. "(tolua_S,self->")

        -- -- 匹配 : std::vector<std::string> invalue = *((std::vector<std::string>*)  tolua_ext_luaval_to_vector_string(tolua_S,2,0)); 格式
        -- -- 替换为 std::vector<std::string> invalue = tolua_ext_luaval_to_vector_string(tolua_S,2,0);
        -- toFunName = get_to_function(k)
        -- local matchKey = k .. "%s*%w+%s*=%s*%*%(%(" .. k .. "%*%)%s*" .. toFunName ..  "%(tolua_S,%d,%d%)%);"
        -- local func = string.gmatch(result, matchKey)
        -- if func then
        --     repeat
        --         local findStr = func()
        --         if findStr == nil or findStr == "" then
        --             break
        --         end

        --         -- 查找变量名及参数
        --         matchKey = k .. "%s*(%w+)%s*=%s*%*%(%(" .. k .. "%*%)%s*" .. toFunName ..  "%(tolua_S,(%d),(%d)%)%)"
        --         local varName, num1, num2 = string.gmatch(findStr, matchKey)()

        --         replacement = string.format("  %s %s = %s(tolua_S,%d,%d);", k, varName, toFunName, num1, num2)
        --         replace(findStr, replacement)
        --     until false
        -- end

        -- -- 匹配 : self->m_floatArr = *((std::vector<float>*)  tolua_ext_luaval_to_vector_float(tolua_S,2,0))
        -- -- 替换为 self->m_floatArr = tolua_ext_luaval_to_vector_float(tolua_S,2,0))
        -- local matchKey = "%w+ = %*%(%(" .. k .. "%*%)%s*" .. toFunName .. "%(tolua_S,%d,%d%)%)\n;"
        -- local func = string.gmatch(result, matchKey)
        -- if func then
        --     repeat
        --         local findStr = func()
        --         if findStr == nil or findStr == "" then
        --             break
        --         end

        --         -- 查找变量名及参数
        --         matchKey = "(%w+) = %*%(%(" .. k .. "%*%)%s*" .. toFunName .. "%(tolua_S,(%d),(%d)%)%)"
        --         local varName, num1, num2 = string.gmatch(findStr, matchKey)()

        --         replacement = string.format("%s = %s(tolua_S,%d,%d);", varName, toFunName, num1, num2)
        --         replace(findStr, replacement)
        --     until false
        -- end
    end

    replace("(void*)&", "&")
    replace("#ifndef TOLUA_RELEASE", "#if COCOS2D_DEBUG >= 1")


    cc_class_name_tab = cc_class_name_tab or {}
    for k, v in pairs(cc_class_name_tab) do
        replace(string.format("tolua_ext_object_arr_to_luaval<%s>", k), string.format("tolua_ext_object_arr_to_luaval<%s>", v))
        replace(string.format("tolua_ext_object_to_luaval<%s>", k), string.format("tolua_ext_object_to_luaval<%s>", v))
        replace(string.format("tolua_ext_map_string_object_to_luaval<%s>", k), string.format("tolua_ext_map_string_object_to_luaval<%s>", v))
        replace(string.format("tolua_ext_luaval_to_ccvector<%s>", k), string.format("tolua_ext_luaval_to_ccvector<%s>", v))
        replace(string.format("tolua_ext_luaval_to_ccmap_string_key<%s>", k), string.format("tolua_ext_luaval_to_ccmap_string_key<%s>", v))


        replace(string.format("%s*", k), string.format("%s*", v))


        replace(string.format([["std::vector<%s*>"]], v), string.format([["std::vector<%s*>"]], k))
        replace(string.format([["std::map<std::string,%s*>"]], v), string.format([["std::map<std::string,%s*>"]], k))


        replace(string.format([[tolua_collect_std__vector_%s__]], k), string.format([[tolua_collect_std__vector_cc_%s__]], v))
        replace(string.format([[tolua_collect_std__map_std__string_%s__]], k), string.format([[tolua_collect_std__map_std__string_cc_%s__]], v))


        replace(string.format("(const std::vector<%s*>*)", v), "")
        replace(string.format("const std::vector<%s*>*", v), string.format("const std::vector<%s*>&", v))
        replace(string.format("(std::vector<%s*>*)", v), "")
        replace(string.format("std::vector<%s*>*", v), string.format("std::vector<%s*>&", v))


        replace(string.format("(const std::map<std::string,%s*>*)", v), "")
        replace(string.format("const std::map<std::string,%s*>*", v), string.format("const std::map<std::string,%s*>&", v))
        replace(string.format("(std::map<std::string,%s*>*)", v), "")
        replace(string.format("std::map<std::string,%s*>*", v), string.format("std::map<std::string,%s*>&", v))

    end

--             replace(
-- [[
-- #ifndef __cplusplus
-- #include "stdlib.h"
-- #endif
-- #include "string.h"

-- #include "tolua++.h"
-- ]],
-- [[
-- #ifndef __cplusplus
-- #include "stdlib.h"
-- #endif
-- #include "string.h"

-- #include "tolua++.h"
-- #include "scripting/lua-bindings/manual/tolua_fix.h"
-- #include <string>
-- ]])

    WRITE(result)
end
