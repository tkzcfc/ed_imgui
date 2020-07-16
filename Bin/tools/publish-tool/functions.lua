-- @Author : fangcheng
-- @Date   : 2020-05-11 18:08:15
-- @remark : 

function format_lua_value(inValue)
    if type(inValue) ~= "table" then
        return tostring(inValue)
    end

    local formatting = "{\n"

    local function format_lua_table (lua_table, indent)
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
                elseif type(v) == "number" then
                    if math.floor(v) < v then -- float
                        szValue = string.format("%.4f", v)
                    else
                        szValue = tostring(v)
                    end
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

-- fmt( "%{%{1}} = {0} + {0}", 100, 200)
-- {200} = 100 + 100
function fmt(format, ...)
    local args = {...}

    format = string.gsub(format, "({%d+})", function(arg)
        local idx = string.match(arg, "{(%d+)}")
        idx = idx + 1
        return tostring(args[idx])
    end)

    format = string.gsub(format, "%%{%%", "{")
    format = string.gsub(format, "%%}%%", "}")

    return format
end

------------------------------------------------------------------------------------

local function fmt_print(...)
	local t = {...}
	return table.concat(t, " ")
end

logI = function(...)
	print("[Info]", fmt_print(...))
end

logW = function(...)
	print("[Warning]", fmt_print(...))
end

logE = function(...)
	print("[Error]", fmt_print(...))
end





-- line
function CLine:serialize()
    self:apply()
    local t = {}
    t.points = self:getAllPoint()
    t.isLeftNormal = self:isLeftNormal()
    t.isVisible = self:isVisible()
    t.lineColor = self:getLineColor()
    t.normalColor = self:getNormalColor()
    t.userdata = self.userdata or {}
    return t
end

function CLine:deserialize(data)
    if data == nil then
        return
    end
    self.userdata = data.userdata or {}
    self:setPointCount(#data.points)
    for idx, pos in pairs(data.points) do
        self:setPointDataByIndex(idx - 1, pos.x, pos.y)
    end

    self:setNormalLeft(data.isLeftNormal)
    self:setVisible(data.isVisible)
    self:setLineCorlor(data.lineColor)
    self:setNormalColor(data.normalColor)
    self:apply()
end

function CLine:publish()
    self:apply()
    local t = {}
    t.points = self:getAllPoint()
    t.normals = self:getAllNormal()
    t.userdata = self.userdata or {}
    return t
end


-- rect
function CRect:serialize()
    self:apply()
    local t = {}
    t.anchorPoint = self:getAnchorPoint()
    t.contentSize = self:getContentSize()
    t.point = self:getPoint()
    t.scale = self:getScale()
    t.rotation = self:getRotation()
    t.skew = self:getSkew()
    t.isVisible = self:isVisible()
    t.color = self:getColor()
    t.userdata = self.userdata or {}
    return t
end

function CRect:deserialize(data)
    if data == nil then
        return
    end

    self.userdata = data.userdata or {}
    self:setAnchorPoint(data.anchorPoint.x, data.anchorPoint.y)
    self:setContentSize(data.contentSize.x, data.contentSize.y)
    self:setPoint(data.point.x, data.point.y)
    self:setScale(data.scale.x, data.scale.y)
    self:setRotation(data.rotation)
    self:setSkewX(data.skew.x)
    self:setSkewY(data.skew.y)
    self:setVisible(data.isVisible)
    self:setColor(data.color)
    self:apply()
end


function CRect:publish()
    self:apply()
    local t = {}
    t.points = {}
    for i=1,self:getVertexCount() do
        t.points[i] = self:getVertexByIndex(i - 1)
    end
    t.userdata = self.userdata or {}
    return t
end

