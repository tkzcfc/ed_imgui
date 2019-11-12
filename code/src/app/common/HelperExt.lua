
local visibleSize = cc.Director:getInstance():getVisibleSize()
local winSize = Tools:getWindowSize()

G_Helper.win_2_visible_x = function(value)
	local scale = visibleSize.width / winSize.width
	return value * scale
end

G_Helper.win_2_visible_y = function(value)
	local scale = visibleSize.height / winSize.height
	return value * scale
end

G_Helper.visible_2_win_x = function(value)
	local scale = winSize.width / visibleSize.width
	return value * scale
end

G_Helper.visible_2_win_y = function(value)
	local scale = winSize.height / visibleSize.height
	return value * scale
end


G_Helper.win_2_visible_pos = function(pos)
	pos.y = winSize.height - pos.y
	pos.x = G_Helper.win_2_visible_x(pos.x)
	pos.y = G_Helper.win_2_visible_x(pos.y)
	return pos
end

G_Helper.fmtPath = function(path)
	path = string.gsub(path, "\\", "/")
	path = string.gsub(path, "//", "/")
	return path
end

G_Helper.getExtension = function(path)
	local ext = string.match(path, "%.(%w+)$")
	return ext
end

G_Helper.doString = function(script)
	local func, errorstr = loadstring(script)
	if func == nil then
		logE(errorstr)
		_MyG.ShowBox("文件加载失败,请在控制台查看详细信息")
		return
	end
	return func
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

