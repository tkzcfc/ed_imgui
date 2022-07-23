
-------------------------------------------------------------------- mugen enums begin --------------------------------------------------------------------

-- 形状类型
cc.exports.ShapeType = enum {
    "UNKNOWN",
    "RECT",
    "POLYGON",
    "CIRCLE"
}

-- // 帧类型
cc.exports.GFrameType = enum {
    -- 攻击
	"ATT_COLLISION_FRAME",
    -- 防御
	"DEF_COLLISION_FRAME",
    -- 物理相关力施加
    "PHYSICAL_FORCE_FRAME",
    -- 事件帧
	"EVENT_FRAME",
    -- 音频帧
	"AUDIO_FRAME",
    -- 自定义脚本
	"SCRIPT_FRAME",
    -- 标记修改
	"MODIFY_FLAGS_FRAME",
    -- 未知类型
	"UNKNOWN_FRAME"
}

cc.exports.ShapeTypeNameLang = {
    [ShapeType.RECT] = "Rect",  -- STR("Rect")
    [ShapeType.POLYGON] = "Polygon",-- STR("Polygon")
    [ShapeType.CIRCLE] = "Circle",-- STR("Polygon")
}

-- 多边形最大顶点数量
cc.exports.PolygonMaxVertex = 8

cc.exports.RoleDocType = enum {
    "ACTION",
    "SKILL"
}

cc.exports.RoleDocName = {
    [RoleDocType.ACTION] = "Action",
    [RoleDocType.SKILL] = "Skill",
}


-- // 值类型定义
cc.exports.GValueType = enum {
	-- // 百分比
	"VALUE_PERCENTAGE",
	-- // 绝对值
	"VALUE_ABSOLUTE",
}

-- // 条件类型
cc.exports.GConditionType = enum {
    -- // 自定义脚本条件
    "SCRIPT_CONDITION",

    -- 未知类型<不可选>
	-- "NONE",
}

-- // 通道检测类型
cc.exports.GChannelCheckType = enum{
    -- // 持续检测
    "Continuous",	
    -- // 触发之后不再检测
    "Once" 
}

-- // 中断类型
cc.exports.GInterruptType = enum {
    -- // 延迟中断等待本次循环执行完毕
	"DELAY", 
    -- // 立即中断
	"PROMPTLY", 
    
    -- // 不中断
	-- "NONE",	
}

cc.exports.GForceOrientation = enum {
    -- // 正方向(actor面向的方向)
	"Positive_Direction",
    -- // 反方向(actor背面的方向)
	"Negative_Direction",
}

cc.exports.GPhysicalForceType = enum {
	-- // 力
	"FORCE",
	-- // 冲力
	"IMPULSE",
	-- // 匀速移动
	"MOVEMENT",
}

local format = string.format
local sort_func = function(a, b)
    return a.value < b.value
end

cc.exports.enum_options = function(enumName)
    local enums = _G[enumName]

    local t = {}
    for k, v in pairs(enums) do
        table.insert(t, {
            name = k,
            value = v
        })
    end

    table.sort(t, sort_func)

    local options = ""
    for k, v in pairs(t) do
        local key = format("%s.%s", enumName, v.name)
        options = options .. STR(key) .. "\0" 
    end
    options = options .. "\0\0"
    return options
end

cc.exports.enum_names = function(enumName)
    local enums = _G[enumName]

    local names = {}
    for k, v in pairs(enums) do
        local key = format("%s.%s", enumName, k)
        names[v] = STR(key)
    end
    return names
end


cc.exports.enum_name = function(enumName, filedName)
    local key = format("%s.%s", enumName, filedName)
    return STR(key)
end



-------------------------------------------------------------------- mugen enums end --------------------------------------------------------------------

cc.exports.VecZero = cc.p(0, 0)