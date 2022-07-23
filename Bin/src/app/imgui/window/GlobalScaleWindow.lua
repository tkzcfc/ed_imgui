-- @Author : fc
-- @Date   : 2021-12-23 11:01:13
-- @remark : 全局缩放设置 DPI适配

local GlobalScaleWindow = class("GlobalScaleWindow", require("app.imgui.Window"))

-- 全局缩放范围
local MIN_VALUE = 1
local MAX_VALUE = 3

-- 字体缩放范围
local FONT_MIN_VALUE = 0.5
local FONT_MAX_VALUE = 5


-- DPI缩放规则
-- DPI    缩放因子
-- 96        100%
-- 120       125%
-- 144       150%
-- 192       200%
local DPI_SCALE_FACTOR = {
    {96, 1},
    {120, 1.25},
    {144, 1.5},
    {192, 2},
}


local function lerp(p1, p2, alpha)
    return p1 * (1 - alpha) + p2 * alpha
end


---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
function GlobalScaleWindow:ctor(...)
    GlobalScaleWindow.super.ctor(self, ...)

    local flags = 0
    flags = Tools:bor_int32(flags, ImGuiWindowFlags_NoSavedSettings)
    
    self:setWindowFlags(flags)

    self.oldScale = 1
    self.lastValue = 1
    
    -- 用户自定义
    if _MyG.sysStorage["bScaleUserDefined"] then
        self:setUIScale(_MyG.sysStorage["fUIZoom"])
        ImGui.GetIO().FontGlobalScale = _MyG.sysStorage["fFontZoom"]
    else
        -- 自动缩放
        self:autoScale()
    end
end

function GlobalScaleWindow:onGUI_Window()
    local ret, value

    -- UI缩放
    ret, value = ImGui.DragFloat(STR("UIZoom"), self.oldScale, 0.1, MIN_VALUE, MAX_VALUE)
    if ret then
        if value < MIN_VALUE then value = MIN_VALUE end
        if value > MAX_VALUE then value = MAX_VALUE end

        self:setUIScale(value)
        _MyG.sysStorage["fUIZoom"] = self.oldScale
        _MyG.sysStorage["bScaleUserDefined"] = true
    end

    -- 字体缩放
    ret, value = ImGui.DragFloat(STR("FontScale"), ImGui.GetIO().FontGlobalScale, 0.1, FONT_MIN_VALUE, FONT_MAX_VALUE)
    if ret then
        if value < FONT_MIN_VALUE then value = FONT_MIN_VALUE end
        if value > FONT_MAX_VALUE then value = FONT_MAX_VALUE end
        ImGui.GetIO().FontGlobalScale = value
        _MyG.sysStorage["fFontZoom"] = value
        _MyG.sysStorage["bScaleUserDefined"] = true
    end

    -- 自动缩放
    if ImGui.Button(STR("AutoZoom")) then
        self:autoScale()
    end
end

-- @brief 设置UI缩放
function GlobalScaleWindow:setUIScale(scale)
    scale = math.floor(scale * 100) / 100

    if self.oldScale == scale then return end
    self.oldScale = scale

    Tools:setImgUIGlobalScale(scale)
end

-- @brief 自动适配缩放
function GlobalScaleWindow:autoScale()
    local dpi = Tools:getDPI()

    local scaleFactorMin = DPI_SCALE_FACTOR[#DPI_SCALE_FACTOR]
    local scaleFactorMax = DPI_SCALE_FACTOR[#DPI_SCALE_FACTOR]

    -- 找到合适的缩放规则
    for k, v in pairs(DPI_SCALE_FACTOR) do
        if dpi <= v[1] then
            scaleFactorMax = v
            if k == 1 then
                scaleFactorMin = v
            else
                scaleFactorMin = DPI_SCALE_FACTOR[k - 1]
            end
            break
        end
    end

    local scale = scaleFactorMax[2]

    -- 根据dpi值自动缩放
    if scaleFactorMax[1] ~= scaleFactorMin[1] then
        local alpha = (dpi - scaleFactorMin[1]) / (scaleFactorMax[1] - scaleFactorMin[1])
        scale = lerp(scaleFactorMin[2], scaleFactorMax[2], alpha)
    end
    
    -- 保留两位小数
    scale = math.floor(scale * 100) / 100

    self:setUIScale(scale)
    ImGui.GetIO().FontGlobalScale = scale
    _MyG.sysStorage["bScaleUserDefined"] = false
end


return GlobalScaleWindow