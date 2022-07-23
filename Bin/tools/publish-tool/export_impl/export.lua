-- @Author : fangcheng
-- @Date   : 2021-07-08 17:15:48
-- @remark : asset文件导出到lua具体实现

local json = require("cjson")
local strFmt = string.format
-----------------------------------------------------------------------------------

-- @brief 格式化浮点数,保留小数点后四位精度
local function fmt_float(float)
    -- return strFmt("%.4f", tonumber(float) or 0)
    return tostring( math.floor(float * 10000 + 0.5) * 0.0001 )
end

-- @brief 格式化require asset文件
-- a/b/c.asset -> a.b.c
local function fmt_require(name)
    name = string.gsub(name, ".asset", "")
    name = string.gsub(name, "/", ".")
    name = string.gsub(name, "\\", ".")
    return name
end

-- @brief 格式化require lua文件
-- a/b.c.lua -> a.b.c
local function fmt_require_lua(name)
    name = string.gsub(name, ".lua", "")
    name = string.gsub(name, "/", ".")
    name = string.gsub(name, "\\", ".")
    return name
end

-- @brief 判断是否是空的table
local function is_empty_table(tb)
    if type(tb) == "table" then
        for k,v in pairs(tb) do
            return false
        end
    end
    return true
end


----------------------------------------------------------------------------------------------
local M = {}

-- @brief 导出数据到lua
function M:exportToLua(data)

    local curType = tostring(data.content.type)
    curType = string.lower(curType)

    if curType == "widget" then
        return self:export_Widget_ToLua(data)
    end

    if curType == "layer" then
        return self:export_Layer_ToLua(data)
    end

    if curType == "map" then
        return self:export_Map_ToLua(data)
    end
    
    if curType == "role" then
        return self:export_Role(data)
    end

    logE(fmt(STR("EXPORT_FILE_FAILED_UNKNOWN_TYPE"), data.file, tostring(curType)))

    return true
end

function M:export_Widget_ToLua(data)
    local file      = data.file
    local content   = data.content

    local children  = content.data.children
    local context   = content.data.context
    local plugins   = context.plugins

    self:output_begin()
    self:output("local M = {}")
    
    -- loadNode
    self:output("")
    self:output("-- 节点加载")
    self:output("function M:loadNode()")
    self:output("local _rootNode = cc.Node:create()\n")

    for k,v in pairs(children) do
        self:_fmtToLua_Auto("_rootNode", v)
    end

    self:output("return _rootNode")
    self:output("end\n")

    -- plugins
    self:fmt_plugin_Auto(plugins)


    self:output("return M")
    self:output_end()

    return true
end

function M:export_Layer_ToLua(data)
    local file      = data.file
    local content   = data.content

    local children  = content.data.children
    local context   = content.data.context
    local plugins   = context.plugins

    self:output_begin()

    self:output([[
local function copyTable(object)
    local lookup_table = {}
    local function _copy(object)
        if type(object) ~= "table" then
            return object
        elseif lookup_table[object] then
            return lookup_table[object]
        end
        local newObject = {}
        lookup_table[object] = newObject
        for key, value in pairs(object) do
            newObject[_copy(key)] = _copy(value)
        end
        return newObject
    end
    return _copy(object)
end
]])


    self:output("local M = {}")
    
    -- loadNode
    self:output("")
    self:output("-- 节点加载")
    self:output("function M:loadNode()")
    self:output("self.widgets = {}")
    self:output("local _rootNode = cc.Node:create()\n")

    for k,v in pairs(children) do
        self:_fmtToLua_Auto("_rootNode", v)
    end

    self:output("return _rootNode")
    self:output("end\n")

    -- 收集所有 widget
    self:output([[function M:onSpawnWidget(widget)
    self.widgets[#self.widgets + 1] = widget
end
]])

    -- 加载所有 widget的线段和矩形
    self:output([[function M:loadAllWidgetLine_Rect()
    if self.widget_line_rect_data then return self.widget_line_rect_data end

    local t_lines = {}
    local t_rects = {}
    for k, widget in pairs(self.widgets) do
        local offsetx, offsety = widget:getPosition()
        local luaFileInfo = widget.luaFileInfo
        local lines = copyTable(luaFileInfo.PluginLineRect.line_data)
        local rects = copyTable(luaFileInfo.PluginLineRect.rect_data)

        for _, line in pairs(lines) do
            for __, p in pairs(line.points) do
                p.x = p.x + offsetx
                p.y = p.y + offsety
            end
            t_lines[#t_lines + 1] = line
        end

        for _, rect in pairs(rects) do
            for __, p in pairs(rect.points) do
                p.x = p.x + offsetx
                p.y = p.y + offsety
            end
            t_rects[#t_rects + 1] = rect
        end
    end

    self.widgets = {}

    self.widget_line_rect_data = {}
    self.widget_line_rect_data["line_data"] = t_lines
    self.widget_line_rect_data["rect_data"] = t_rects

    return self.widget_line_rect_data
end
]])

    -- plugins
    self:fmt_plugin_Auto(context.plugins)

    self:output("return M")
    self:output_end()

    return true
end

function M:export_Map_ToLua(data)
    local file      = data.file
    local content   = data.content or {}

    content.data    = content.data or {}
    local context   = content.data.context or {}
    local plugins   = context.plugins or {}


    local PluginMapLayer = plugins.PluginMapLayer or {}


    self:output_begin()
    self:output("local M = {}")


    -- loadBGNode
    self:output("")
    self:output("-- 背景节点加载")
    self:output("function M:loadBGNode()")
    if PluginMapLayer.backgroundAssets and #PluginMapLayer.backgroundAssets > 0 then
        self:output("local M = {}")
        self:output("local luafile, node\n")
        for k,v in pairs(PluginMapLayer.backgroundAssets) do
            self:output_fmt("luafile = require(%q)", fmt_require(v))
            self:output_fmt("node = luafile:loadNode()")
            self:output_fmt("node.luaFileInfo = luafile")
            self:output_fmt("M[#M + 1] = node\n")
        end
        self:output_fmt("return M")
    end
    self:output("end\n")

    -- loadGameNode
    self:output("")
    self:output("-- 游戏节点加载")
    self:output("function M:loadGameNode()")
    if PluginMapLayer.gameLayerAsset then
        self:output_fmt("local luafile = require(%q)", fmt_require(PluginMapLayer.gameLayerAsset))
        self:output_fmt("local node = luafile:loadNode()")
        self:output_fmt("node.luaFileInfo = luafile")
        self:output_fmt("return node")
    end
    self:output("end\n")

    -- loadFGNode
    self:output("")
    self:output("-- 前景节点加载")
    self:output("function M:loadFGNode()")
    if PluginMapLayer.foregroundAssets and #PluginMapLayer.foregroundAssets > 0 then
        self:output("local M = {}")
        self:output("local luafile, node\n")
        for k,v in pairs(PluginMapLayer.backgroundAssets) do
            self:output_fmt("luafile = require(%q)", fmt_require(v))
            self:output_fmt("node = luafile:loadNode()")
            self:output_fmt("node.luaFileInfo = luafile")
            self:output_fmt("M[#M + 1] = node\n")
        end
        self:output_fmt("return M")
    end
    self:output("end\n")

    -- plugins
    self:fmt_plugin_Auto(context.plugins)
    
    self:output("return M")
    self:output_end()

    return true
end

function M:export_Role(data)
    local file      = data.file
    local content   = data.content or {}

    content.data    = content.data or {}
    local context   = content.data.context or {}
    local plugins   = context.plugins or {}

    -- 禁用输出到lua
    self:disableAutoWriteToLua()

    local binaryFile = self:getOutputFile(file, ".bytes")

    if not os.mkdirpath(binaryFile) then return false end

    local ok = MugenHelper:serializeRoleToFile(json.encode(context.role), binaryFile)

    local warings = MugenHelper:warings()
    for k, v in pairs(warings) do
        logW(v)
    end

    local errors = MugenHelper:errors()
    for k,v in pairs(errors) do
        logE(v)
    end

    if not ok or #errors > 0 then
        return false
    end

    return true
end

----------------------------------------------- element  begin -----------------------------------------------

function M:_fmtToLua_Auto(parentName, data, fullNodeTreePath)
    local curType = data.type
    curType = tostring(curType)
    curType = string.lower(curType)

    fullNodeTreePath = fullNodeTreePath or ""
    if fullNodeTreePath == "" then
        fullNodeTreePath = data.data.name
    else
        fullNodeTreePath = fullNodeTreePath .. "/" .. data.data.name
    end

    if self["fmtToLua_" .. curType] then
        self["fmtToLua_" .. curType](self, parentName, data.data, tostring(data.type), fullNodeTreePath)
        self:output("")
    else
        logE(fmt(STR("PUB_FILE_FAIL_NO_IMP"), self.current_file, curType))
    end

    for k,v in pairs(data.child) do
        self:_fmtToLua_Auto(data.data.name, v, fullNodeTreePath)
    end
end


function M:fmt_Node(parentName, data, curType, fullNodeTreePath)
    local curName = tostring(data.name)

    if data.anchorPoint then
        if data.anchorPoint.x == 0.5 and data.anchorPoint.y == 0.5 then
        else
            self:output_fmt("%s:setAnchorPoint(cc.p(%s, %s))", curName, fmt_float(data.anchorPoint.x), fmt_float(data.anchorPoint.y))
        end
    end

    if data.position then
        if data.position.x == 0 and data.position.y == 0 then
        else
            self:output_fmt("%s:setPosition(%s, %s)", curName, fmt_float(data.position.x), fmt_float(data.position.y))
        end
    end

    if data.rotation and data.rotation ~= 0 then
        self:output_fmt("%s:setRotation(%s)", curName, fmt_float(data.rotation))
    end

    if data.scaleX and data.scaleX ~= 1 then
        self:output_fmt("%s:setScaleX(%s)", curName, fmt_float(data.scaleX))
    end

    if data.scaleX and data.scaleY ~= 1 then
        self:output_fmt("%s:setScaleY(%s)", curName, fmt_float(data.scaleY))
    end

    if data.name then
        self:output_fmt("%s:setName(\"%s\")", curName, data.name)
    end

    if data.opacity and data.opacity ~= 255 then
        self:output_fmt("%s:setOpacity(%d)", curName, data.opacity)
    end

    if data.color then
        if data.color.r == 255 and data.color.g == 255 and data.color.b == 255 then
        else
            self:output_fmt("%s:setColor(cc.c3b(%d, %d, %d))", curName, data.color.r, data.color.g, data.color.b)
        end
    end

    if data.contentSize then
        if data.contentSize.width == 0 and data.contentSize.height == 0 then
        else
            self:output_fmt("%s:setContentSize(cc.size(%s, %s))", curName, fmt_float(data.contentSize.width), fmt_float(data.contentSize.height))
        end
    end

    if data.aabb then
        self:output_fmt("%s.aabb = %s", curName, format_lua_value(data.aabb))
    end

    if not is_empty_table(data.userdata) then
        local ud = self:fmt_Userdata(data.userdata, fullNodeTreePath)
        self:output_fmt("%s.userdata = %s", curName, format_lua_value(ud))
    end

    -- self:output_fmt("%s.edType = %q", curName, curType)

    self:output_fmt("%s:addChild(%s)", parentName, curName)
end

-- widget
function M:fmtToLua_widget(parentName, data, curType, fullNodeTreePath)
    -- "assetFile": "xx.asset",

    local varFileName = strFmt("%s_luafile", data.name)
    self:output_fmt("local %s = require(%q)", varFileName, fmt_require(data.assetFile))
    self:output_fmt("local %s = %s:loadNode()", data.name, varFileName)
    self:output_fmt("%s.luaFileInfo = %s", data.name, varFileName)

    self:fmt_Node(parentName, data, curType, fullNodeTreePath)

    self:output_fmt("self:onSpawnWidget(%s)\n", data.name)
end

-- sprite
function M:fmtToLua_sprite(parentName, data, curType, fullNodeTreePath)
    -- "textureName": "Projects/test/Loading.png",
    -- "plistFileName": "",
    -- "isPlist": false,

    if data.isPlist then
        self:output_fmt("cc.SpriteFrameCache:getInstance():addSpriteFrames(%q)", data.plistFileName)
        self:output_fmt("local %s = cc.Sprite:createWithSpriteFrameName(%q)", data.name, data.textureName)
    else
        self:output_fmt("local %s = cc.Sprite:create(%q)", data.name, data.textureName)
    end

    self:fmt_Node(parentName, data, curType, fullNodeTreePath)
end

-- image
function M:fmtToLua_image(parentName, data, curType, fullNodeTreePath)
    -- "textureName": "Projects/test/Loading.png",
    -- "plistFileName": "",
    -- "isPlist": false,

    if data.isPlist then
        self:output_fmt("cc.SpriteFrameCache:getInstance():addSpriteFrames(%q)", data.plistFileName)
        self:output_fmt("local %s = ccui.ImageView:create()", data.name)
        self:output_fmt("%s:loadTexture(%q, 1)", data.name, data.textureName)
    else
        self:output_fmt("local %s = ccui.ImageView:create()", data.name)
        self:output_fmt("%s:loadTexture(%q, 0)", data.name, data.textureName)
    end

    if data.ignoreContent ~= nil then
        if data.ignoreContent then
            self:output_fmt("%s:ignoreContentAdaptWithSize(true)", data.name)
        else
            self:output_fmt("%s:ignoreContentAdaptWithSize(false)", data.name)
        end
    end

    self:fmt_Node(parentName, data, curType, fullNodeTreePath)
end

-- -- CocostudioFile
function M:fmtToLua_cocostudiofile(parentName, data, curType, fullNodeTreePath)
    -- "scriptFile": "CustomFile.lua",

    local name_lua = data.name .. "_lua"

    self:output_fmt("local %s = require('%s').create()", name_lua, fmt_require_lua(data.scriptFile))

    self:output_fmt("if %s.animation then", name_lua)
    self:output_fmt("    %s.animation:gotoFrameAndPlay(0, true)", name_lua)
    self:output_fmt("    %s.root:runAction(%s.animation)", name_lua, name_lua)
    self:output_fmt("end")

    self:output_fmt("local %s = %s.root", data.name, name_lua)

    self:fmt_Node(parentName, data, curType, fullNodeTreePath)
end

-- armaturefile
function M:fmtToLua_armaturefile(parentName, data, curType, fullNodeTreePath)
    local name = data.name

    self:output_fmt("local %s = ccs.Armature:create()", name)

    self:output_fmt("ccs.ArmatureDataManager:getInstance():addArmatureFileInfo(\"%s\")", data.resFile)

    -- 获取动画名
    local filename = getLastName(data.resFile)
    local clsName = getFileClsName(filename)

    self:output_fmt("%s:init(\"%s\")", name, clsName)
    if data.playLoop then
        self:output_fmt("%s:getAnimation():play(\"%s\", -1, 1)", name, data.playAniName)
    else
        self:output_fmt("%s:getAnimation():play(\"%s\", -1, 0)", name, data.playAniName)
    end

    -- 不导出锚点信息
    data.anchorPoint = nil

    self:fmt_Node(parentName, data, curType, fullNodeTreePath)
end

----------------------------------------------- plugin  begin -----------------------------------------------

function M:fmt_plugin_Auto(plugins)
    for k,plugin in pairs(plugins or {}) do
        local curFunc = "fmt_plugin_" .. string.lower(k)
        if self[curFunc] then
            self[curFunc](self, plugin, k)
            self:output("\n")
        else
            logE(fmt(STR("PUB_PLUGIN_FAIL_NO_IMP"), tostring(k)))
        end
    end
end

-- 插件 line_rect
function M:fmt_plugin_pluginlinerect(data, pluginName)
    local lines = {}
    for k, v in pairs(data.line_data or {}) do
        local line = CLine:new_local()
        line:deserialize(v)

        local publishData = line:publish()

        if not is_empty_table(line.userdata) then
            local ud = self:fmt_Userdata(line.userdata, fmt("{0} -> line{1}", pluginName, k))
            publishData.userdata = ud
        else
            publishData.userdata = nil
        end

        lines[#lines + 1] = publishData
    end

    local rects = {}
    for k, v in pairs(data.rect_data or {}) do
        local rect = CRect:new_local()
        rect:deserialize(v)

        local publishData = rect:publish()

        if not is_empty_table(rect.userdata) then
            local ud = self:fmt_Userdata(rect.userdata, fmt("{0} -> line{1}", pluginName, k))
            publishData.userdata = ud
        else
            publishData.userdata = nil
        end

        rects[#rects + 1] = publishData
    end

    local line_data = fmt("M.{0}.line_data = {1}", pluginName, format_lua_value(lines))
    local rect_data = fmt("M.{0}.rect_data = {1}", pluginName, format_lua_value(rects))

    self:output(fmt("M.{0} = {}", pluginName))
    self:output(line_data)
    self:output(rect_data)

    if not is_empty_table(data.userdata) then
        local ud = self:fmt_Userdata(data.userdata, fmt("{0} -> userdata", pluginName))
        self:output(fmt("M.{0}.userdata = {1}", pluginName, format_lua_value(ud) ))
    end
end

-- 插件 PluginLayerSize
function M:fmt_plugin_pluginlayersize(data, pluginName)
    local out_data = fmt("M.{0}.size = {1}", pluginName, format_lua_value(data.size))
    self:output(fmt("M.{0} = {}", pluginName))
    self:output(out_data)

    if not is_empty_table(data.userdata) then
        local ud = self:fmt_Userdata(data.userdata, fmt("{0} -> userdata", pluginName))
        self:output(fmt("M.{0}.userdata = {1}", pluginName, format_lua_value(ud) ))
    end
end

-- 插件 PluginRevivePoint
function M:fmt_plugin_pluginrevivepoint(data, pluginName)
    local out_data = fmt("M.{0}.revivePoints = {1}", pluginName, format_lua_value(data.revivePoints or {}))
    self:output(fmt("M.{0} = {}", pluginName))
    self:output(out_data)

    if not is_empty_table(data.userdata) then
        local ud = self:fmt_Userdata(data.userdata, fmt("{0} -> userdata", pluginName))
        self:output(fmt("M.{0}.userdata = {1}", pluginName, format_lua_value(ud) ))
    end
end

-- 插件 PluginRefResources
function M:fmt_plugin_pluginrefresources(data, pluginName)
    local out_data = fmt("M.{0}.refResources = {1}", pluginName, format_lua_value(data.refs or {}))
    self:output(fmt("M.{0} = {}", pluginName))
    self:output(out_data)

    if not is_empty_table(data.userdata) then
        local ud = self:fmt_Userdata(data.userdata, fmt("{0} -> userdata", pluginName))
        self:output(fmt("M.{0}.userdata = {1}", pluginName, format_lua_value(ud) ))
    end
end

-- 插件 PluginMapLayer
-- 在 export_Map_ToLua 函数里面已经实现了该插件发布，此处指定义一个空函数避免警告
function M:fmt_plugin_pluginmaplayer(data, pluginName)
end

----------------------------------------------- plugin  end -----------------------------------------------

function M:fmt_Userdata(userdata, fullNodeTreePath)
    local loc = self.current_file
    if fullNodeTreePath and fullNodeTreePath ~= "" then
        loc = fmt("{0} : [{1}]", self.current_file, fullNodeTreePath)
    end

    loc = loc .. " -> userdata"

    userdata = userdata or {}

    -- 重复key检查
    local keyCheck = {}
    for k,v in pairs(userdata) do
        if v.name ~= "" then
            if keyCheck[v.name] then
                keyCheck[v.name] = keyCheck[v.name] + 1
            else
                keyCheck[v.name] = 0
            end
        end
    end

    -- 警告重复key
    for k,v in pairs(keyCheck) do
        if v > 0 then
            logW(fmt(STR("UD_DUPLICATE_KEY"), v, loc))
        end
    end

    local ud = {}
    for k,v in pairs(userdata) do
        if v.name == "" then
            logW(fmt(STR("UD_EMPTY_KEY"), loc))
        else
            -- 数字,不支持浮点数， 3.14 这种直接转换为 3
            if tonumber(v.name) then
                local numValue = tonumber(v.name)
                if math.ceil(numValue) ~= math.floor(numValue) then
                    logW(fmt(STR("UD_FLOAT_KEY_WARN"), loc, numValue, math.floor(numValue)))
                end
                ud[math.floor(numValue)] = v.data
            -- 字符串
            else
                ud[v.name] = v.data
            end
        end
    end

    return ud
end

return function(T)
    for k,v in pairs(M) do
        T[k] = v
    end
end
