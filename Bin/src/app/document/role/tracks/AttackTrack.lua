-- @Author : fc
-- @Date   : 2021-12-28 17:43:35
-- @remark : 攻击轨道

local TrackHelper = import(".TrackHelper")
local AttackTrack = class("AttackTrack", import(".BaseTrack"))


AttackTrack.NameLang = "GFrameType.ATT_COLLISION_FRAME"
AttackTrack.Type = GFrameType.ATT_COLLISION_FRAME

local GFrameTypeNames = enum_names("GFrameType")

-- 支持的形状类型
local SupportShapeType = {
    {
        name = ShapeTypeNameLang[ShapeType.RECT],
        value = ShapeType.RECT,
    },
    {
        name = ShapeTypeNameLang[ShapeType.POLYGON],
        value = ShapeType.POLYGON,
    },
    {
        name = ShapeTypeNameLang[ShapeType.CIRCLE],
        value = ShapeType.CIRCLE,
    }
}

AttackTrack.SupportShapeType = SupportShapeType


-- 红色
local COLOR_RED = IM_COL32(255, 0, 0, 150)

-- 攻击矩形颜色
local ATT_RECT_COLOR = IM_COL32(255, 0, 0, 150) 
-- 防御矩形颜色
-- local DEF_RECT_COLOR = IM_COL32(30, 144, 255, 150) 
local DEF_RECT_COLOR = IM_COL32(150, 200, 255, 150) 


-- 攻击多边形颜色
-- local ATT_POLYGON_COLOR = IM_COL32(200, 40, 40, 150) 
local ATT_POLYGON_COLOR = IM_COL32(255, 0, 0, 150) 
-- 防御多边形颜色
local DEF_POLYGON_COLOR = IM_COL32(150, 200, 255, 150) 



-- 攻击圆形颜色
local ATT_CIRCLE_COLOR = IM_COL32(255, 0, 0, 150) 
-- 防御圆形颜色
local DEF_CIRCLE_COLOR = IM_COL32(150, 200, 255, 150) 




local function getShapeColor(frameType, shapeType)
    if shapeType == ShapeType.RECT then
        if frameType == GFrameType.ATT_COLLISION_FRAME then
            return ATT_RECT_COLOR
        end
        return DEF_RECT_COLOR
    elseif shapeType == ShapeType.POLYGON then
        if frameType == GFrameType.ATT_COLLISION_FRAME then
            return ATT_POLYGON_COLOR
        end
        return DEF_POLYGON_COLOR
    elseif shapeType == ShapeType.CIRCLE then
        if frameType == GFrameType.ATT_COLLISION_FRAME then
            return ATT_CIRCLE_COLOR
        end
        return DEF_CIRCLE_COLOR
    end
    return COLOR_RED
end



-- @brief 创建新的轨道
function AttackTrack:newTrack(cb)
    -- 轨道名称
    local curText = ""
    -- 形状类型下标
    local shapeTypeIndex = 1
    -- 多边形顶点数量
    local polygonVertexCount = 3

    -- 形状选择
    local shapeNames_imguiCombo = ""
    for k, v in pairs(self.SupportShapeType) do
        shapeNames_imguiCombo = shapeNames_imguiCombo .. STR(v.name) .. "\0"
    end
    shapeNames_imguiCombo = shapeNames_imguiCombo .. "\0\0"

    local popup = require("app.imgui.Popup").new()
    popup:setWindowFlag(ImGuiWindowFlags_AlwaysAutoResize)
    popup:setGUICallback(function()
        -- 形状
        local newIndex = Tools:imguiCombo_OneLiner("shape", shapeTypeIndex - 1, shapeNames_imguiCombo)
        shapeTypeIndex = newIndex + 1
    
        -- 多边形
        if SupportShapeType[shapeTypeIndex].value == ShapeType.POLYGON then
    
            local ok, count = ImGui.SliderInt("vertex count", polygonVertexCount, 3, PolygonMaxVertex, "%d")
            if ok then
                if count < 3 then count = 3 end
                if count > PolygonMaxVertex then count = PolygonMaxVertex end
                polygonVertexCount = count
            end
        end
    
        -- name
        local enter_true, inputName = Tools:imgui_inputText(STR("Name"), curText, 32, ImGuiInputTextFlags_EnterReturnsTrue)
        curText = inputName
        
        ImGui.Separator()
    
        if ImGui.Button("OK", cc.p(-1, 0)) then
            -- 关闭弹窗
            popup:close()

            local track = {
                name = curText,
                shape = self.SupportShapeType[shapeTypeIndex].value,
                type = self.Type,
                frames = {}
            }

            table.insert(track.frames, self:newFrame(track, polygonVertexCount))

            if cb then
                cb(track)
            end
        end
    end)
    _MyG.PopupManager:addPopup(popup)
end

function AttackTrack:newFrame(trackData, polygonVertexCount)
    local frameType = trackData.type
    local shapeType = trackData.shape
    -- 多边形顶点数量
    local vertexCount = polygonVertexCount
    if vertexCount == nil then
        if shapeType == ShapeType.POLYGON then
            vertexCount = #trackData.frames[#trackData.frames].shapeData.vertex
        end
    end
    vertexCount = vertexCount or 3


    local frame = {}
    -- 矩形
    if shapeType == ShapeType.RECT then
        local rect = CRect:new_local()
        rect:setAnchorPoint(0.5, 0.5)
        rect:setContentSize(100, 100)
        rect:setPoint(0, 0)
        rect:setColor(getShapeColor(frameType, shapeType))

        frame.time = 0
        frame.len = -1
        frame.shapeData = rect:serialize()
    -- 多边形
    elseif shapeType == ShapeType.POLYGON then
        local polygon = CPolygon:new_local()
        polygon:setVertexCount(vertexCount)
        polygon:setColor(getShapeColor(frameType, shapeType))

        local step = 360 / vertexCount
        local radius = 200
        for i = 1, vertexCount do
            local angle = step * (i - 1)
            local radian = math.angle2radian(360 - angle)
            local pos = cc.p(math.cos(radian) * radius, math.sin(radian) * radius)
            polygon:setVertex(pos, i - 1)
        end

        frame.time = 0
        frame.len = -1
        frame.shapeData = polygon:serialize()
    -- 圆形
    elseif shapeType == ShapeType.CIRCLE then
        local rect = CCircle:new_local()
        rect:setCenter(0, 0)
        rect:setRadius(100)
        rect:setColor(getShapeColor(frameType, shapeType))

        frame.time = 0
        frame.len = -1
        frame.shapeData = rect:serialize()
    else
        asset(false)
    end

    return frame
end

function AttackTrack:newDefaultFrame(trackData)
    return self:newFrame(trackData, 3)
end

function AttackTrack:onGUI_TrackInfo(track, curTime, maxTime, onChangePreCB, onChangeFinishCB, context)
    self:onGUI_TrackFramesMng(track, curTime, onChangePreCB, onChangeFinishCB, context)

    -- 分割线
    ImGui.Separator()

    -- track info
    ImGui.Text(GFrameTypeNames[track.type])
    ImGui.Text(STR(ShapeTypeNameLang[track.shape]))

    local frame = TrackHelper:getCurFrame(track.frames, curTime)
    if frame == nil then return end

    -- 分割线
    ImGui.Separator()

    ImGui.Text(string.format("begin time:%d", frame.time))

    local vec2_tmp = {0, 0}
    local vec2Value

    -- 矩形信息展示
    if track.shape == ShapeType.RECT then

        local retTmp
        local rotation = frame.shapeData.rotation
        retTmp, vec2Value = ImGui.DragFloat(STR("EA_ROTATION"), rotation, 1)
        if retTmp then
            onChangePreCB()
            frame.shapeData.rotation = vec2Value
            onChangeFinishCB()
        end

        vec2Value = frame.shapeData.point
        vec2_tmp[1] = vec2Value.x
        vec2_tmp[2] = vec2Value.y
        if ImGui.DragFloat2(STR("EA_POS"), vec2_tmp, 1) then
            onChangePreCB()
            vec2Value.x = vec2_tmp[1]
            vec2Value.y = vec2_tmp[2]
            onChangeFinishCB()
        end
        
        vec2Value = frame.shapeData.contentSize
        vec2_tmp[1] = vec2Value.x
        vec2_tmp[2] = vec2Value.y
        if ImGui.DragFloat2(STR("EA_SIZE"), vec2_tmp, 1) then
            local w = math.max(vec2_tmp[1], 0)
            local h = math.max(vec2_tmp[2], 0)

            if vec2Value.x ~= w or vec2Value.y ~= h then
                onChangePreCB()
                vec2Value.x = w
                vec2Value.y = h
                onChangeFinishCB()
            end
        end
    elseif track.shape == ShapeType.POLYGON then
        local vertexCount = #frame.shapeData.vertex
        -- 多边形信息展示
        for k, vertex in pairs(frame.shapeData.vertex) do
            vec2_tmp[1] = vertex.x
            vec2_tmp[2] = vertex.y
            if ImGui.DragFloat2(STR("EA_POS") .. k, vec2_tmp, 1) then
                onChangePreCB()
                vertex.x = vec2_tmp[1]
                vertex.y = vec2_tmp[2]
                onChangeFinishCB()
            end

            if vertexCount > 3 then
                ImGui.SameLine()
                if ImGui.Button("X##" .. k) then
                    onChangePreCB()
                    table.remove(frame.shapeData.vertex, k)
                    onChangeFinishCB()
                end
            end
        end

        if vertexCount < PolygonMaxVertex then
            if ImGui.Button("+") then
                onChangePreCB()

                local vCount = #frame.shapeData.vertex
                local p = cc.pLerp(frame.shapeData.vertex[vCount - 1], frame.shapeData.vertex[vCount], 0.5)

                table.insert(frame.shapeData.vertex, clone(frame.shapeData.vertex[vCount]))
                frame.shapeData.vertex[vCount] = p

                onChangeFinishCB()
            end
        end
    -- 圆形信息展示
    elseif track.shape == ShapeType.CIRCLE then

        local retTmp
        local radius = frame.shapeData.radius
        retTmp, vec2Value = ImGui.DragFloat(STR("Radius"), radius, 1)
        if retTmp then
            onChangePreCB()
            frame.shapeData.radius = vec2Value
            onChangeFinishCB()
        end

        vec2Value = frame.shapeData.center
        vec2_tmp[1] = vec2Value.x
        vec2_tmp[2] = vec2Value.y
        if ImGui.DragFloat2(STR("Center"), vec2_tmp, 1) then
            onChangePreCB()
            vec2Value.x = vec2_tmp[1]
            vec2Value.y = vec2_tmp[2]
            onChangeFinishCB()
        end
    end

end

return AttackTrack
