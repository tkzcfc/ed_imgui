require("lfs")

local director = cc.Director:getInstance()



G_Helper.win_2_visible_x = function(value)
    -- 底层在窗口大小改变时会自动将设计分辨率设置为当前窗口分辨率,此处直接返回值即可
    return value
 --    local visibleSize = director:getVisibleSize()
 --    local winSize = Tools:getWindowSize()
	-- local scale = visibleSize.width / winSize.width
	-- return value * scale
end

G_Helper.win_2_visible_y = function(value)
    -- 底层在窗口大小改变时会自动将设计分辨率设置为当前窗口分辨率,此处直接返回值即可
    return value
 --    local visibleSize = director:getVisibleSize()
 --    local winSize = Tools:getWindowSize()
	-- local scale = visibleSize.height / winSize.height
	-- return value * scale
end

G_Helper.fmtPath = function(path)
	path = string.gsub(path, "\\", "/")
	path = string.gsub(path, "//", "/")
	return path
end

G_Helper.fmtDirPath = function(path)
    if path == "" then return path end
    
    path = G_Helper.fmtPath(path)
    if string.sub(path, -1) ~= "/" then
        return path .. "/"
    end
    return path
end

-- @brief 获取扩展名，且返回小写
-- @example xxx.ExportJson -> exportjson
G_Helper.getExtension = function(path)
	local ext = string.match(path, "%.(%w+)$")
    if ext == nil then
        return ""
    end
	return string.lower(ext)
end

-- @brief 获取文件名称
-- Abc.png -> Abc
G_Helper.getFileClsName = function(filename)
    local ext = string.match(filename, "(.+)%.%w+$")
    if ext == nil then
        assert(0)
    end
    return ext
end

-- @brief 获取文件目录
-- a/b/c/d.png -> a/b/c/   d.png
G_Helper.getFileDir = function(filePath)
	filePath = filePath:reverse()
	local sp = string.find(filePath, "[/\\]")
	if sp then
		local dir = string.sub(filePath, sp):reverse()
		local name = string.sub(filePath, 1, sp - 1):reverse()
        return dir, name
    end
end

-- @brief 获取路径中包含的最后的名称
-- a/b/c/d/e.png -> e.png
G_Helper.getLastName = function(path)
    path = string.reverse(path)
    local begin = string.find(path, "/")
    if begin == nil or begin <= 0 then
        return string.reverse(path)
    end
    path = string.sub(path, 1, begin - 1)
    return string.reverse(path)
end

G_Helper.doString = function(script)
	local func, errorstr = loadstring(script)
	if func == nil then
		logE(errorstr)
		_MyG.ShowTipBox("File loading failed. Please check the error information on the console")
		return
	end
	return func
end

G_Helper.curDir = function()
    return G_Helper.fmtPath(os.currentdir())
end

G_Helper.getClearDirPath = function(str)
    repeat
        if string.len(str) <= 0 then
            break
        end
        if string.sub(str, -1) == "/" then
            str = string.sub(str, 1, -2)
        else
            break
        end
    until(false)
    return str
end

function G_Helper.getLuaPath(path)
    path = Tools:replaceString(path, ".lua", "")
    path = Tools:replaceString(path, "/", ".")
    path = Tools:replaceString(path, "\\", ".")
    return path
end

function G_Helper.getNodeValidSize(root)
    local minPos = {}
    local maxPos = {}

    local function runPos(node, pos)
        pos = node:convertToWorldSpace(pos)

        if minPos.x then
            minPos.x = math.min(minPos.x, pos.x)
        else
            minPos.x = pos.x
        end

        if minPos.y then
            minPos.y = math.min(minPos.y, pos.y)
        else
            minPos.y = pos.y
        end
        
        if maxPos.x then
            maxPos.x = math.max(maxPos.x, pos.x)
        else
            maxPos.x = pos.x
        end
        
        if maxPos.y then
            maxPos.y = math.max(maxPos.y, pos.y)
        else
            maxPos.y = pos.y
        end
        
    end

    local function run(node)
        local size = node:getContentSize()

        runPos( node, cc.p(0, 0) )
        runPos( node, cc.p(size.width, size.height) )
        runPos( node, cc.p(size.width, 0) )
        runPos( node, cc.p(0, size.height) )

        local children = node:getChildren()
        for k,v in pairs(children) do
            run(v)
        end
    end

    run(root)

    return minPos, maxPos, cc.size(math.abs(maxPos.x - minPos.x), math.abs(maxPos.y - minPos.y))
end

function G_Helper.getBox(node)
    local anchorPoint = node:getAnchorPoint()
    local positionx, positiony = node:getPosition()
    local size = node:getContentSize()

    local rect = CRect:new_local()
    rect:setAnchorPoint(anchorPoint.x, anchorPoint.y)
    rect:setContentSize(size.width, size.height)
    rect:setPoint(positionx, positiony)
    rect:setScale(node:getScaleX(), node:getScaleY())
    rect:setRotation(node:getRotation())
    rect:apply()

    local p1 = rect:getVertexByIndex(0)
    local p2 = rect:getVertexByIndex(1)
    local p3 = rect:getVertexByIndex(2)
    local p4 = rect:getVertexByIndex(3)

    local minPos = {}
    local maxPos = {}

    local function del_pos(pos)
        minPos.x = math.min(minPos.x, pos.x)
        minPos.y = math.min(minPos.y, pos.y)
        maxPos.x = math.max(maxPos.x, pos.x)
        maxPos.y = math.max(maxPos.y, pos.y)
    end

    minPos = cc.p(p1.x, p1.y)
    maxPos = cc.p(p1.x, p1.y)

    del_pos(p2)
    del_pos(p3)
    del_pos(p4)

    return cc.rect(minPos.x, minPos.y, maxPos.x - minPos.x, maxPos.y - minPos.y)
end

--[[
bl               br
 _________________
|                |
|                |
|                |
|                |
|________________|
tl                tr
]]
function G_Helper.obbApplyMatrix (rect, mat4, out_bl, out_tl, out_tr, out_br)
    local x = rect.x
    local y = rect.y
    local width = rect.width
    local height = rect.height

    local mat4m = mat4
    local m00, m01, m04, m05 = mat4m[1], mat4m[2], mat4m[5], mat4m[6]
    local m12, m13 = mat4m[13], mat4m[14]

    local tx = m00 * x + m04 * y + m12
    local ty = m01 * x + m05 * y + m13
    local xa = m00 * width
    local xb = m01 * width
    local yc = m04 * height
    local yd = m05 * height

    out_tl.x = tx
    out_tl.y = ty
    out_tr.x = xa + tx
    out_tr.y = xb + ty
    out_bl.x = yc + tx
    out_bl.y = yd + ty
    out_br.x = xa + yc + tx
    out_br.y = xb + yd + ty
end

function G_Helper.getPolygonAABB(aabb, points)
    local minPosX, minPosY, maxPosX, maxPosY = 1e10, 1e10, -1e10, -1e10
    for k,v in pairs(points) do
        if v.x < minPosX then
            minPosX = v.x
        end
        if v.y < minPosY then
            minPosY = v.y
        end
        if maxPosX < v.x then
            maxPosX = v.x
        end

        if maxPosY < v.y then
            maxPosY = v.y
        end
    end

    aabb.x = minPosX
    aabb.y = minPosY
    aabb.width = maxPosX - minPosX
    aabb.height = maxPosY - minPosY
end

local identityMat = cc.mat4.createIdentity()
function G_Helper.mat4_transformVector(pos, mat)
    pos.z = 0
    pos.w = 1
    return mat4_transformVector(mat, pos, identityMat)
end


-- 多边形与点碰撞测试
function G_Helper.pointInPolygon(point, polygon)
    local inside = false
    local x, y = point.x, point.y
    local length = #polygon
    
    local j = length
    for i = 1, length do
        local xi, yi = polygon[i].x, polygon[i].y
        local xj, yj = polygon[j].x, polygon[j].y
        local intersect = ((yi > y) ~= (yj > y)) and (x < (xj - xi) * (y - yi) / (yj - yi) + xi)
        if intersect then
            inside = not inside
        end
        j = i
    end

    return inside
end

function G_Helper.getTableStringValue(out, tab)
    for k,v in pairs(tab) do
        if type(v) == "table" then
            G_Helper.getTableStringValue(out, v)
        elseif type(v) == "string" then
            out[#out + 1] = v
        end
    end
end
