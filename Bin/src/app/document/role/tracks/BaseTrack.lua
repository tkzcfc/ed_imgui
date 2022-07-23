-- @Author : fc
-- @Date   : 2021-12-28 17:44:12
-- @remark : 轨道基类

local TrackHelper = import(".TrackHelper")
local BaseTrack = class("BaseTrack")

-- 类型名称
BaseTrack.NameLang = "GFrameType.UNKNOWN_FRAME"
-- 类型
BaseTrack.Type = GFrameType.UNKNOWN_FRAME

-- @interface
-- @brief 创建新的轨道
function BaseTrack:newTrack(cb)
    asset(0)
end

-- @interface
function BaseTrack:newDefaultFrame(trackData)
    asset(0)
end


function BaseTrack:getNearFrame(frames, curTime)
    local count = #frames
    local frame = TrackHelper:getCurFrame(frames, curTime)
    if frame then return frame end

    for k, v in pairs(frames) do
        if curTime < v.time then
            return v
        end
    end
    return frames[count]
end

function BaseTrack:onGUI_TrackFramesMng(track, curTime, onChangePreCB, onChangeFinishCB, context)
    local canAddFrame = true
    local canDeleteFrame = false

    -- 获取当前帧
    local frame = TrackHelper:getCurFrame(track.frames, curTime)
    if frame then
        if frame.len < 1 then
            canAddFrame = frame.time ~= curTime
        else
            canAddFrame = false
        end
        canDeleteFrame = true
    end

    if canDeleteFrame then
        ImGui.SameLine()
        if ImGui.Button("delete frame") then
            -- 提示是否删除当前帧
            _MyG.ShowOptBox(STR("DelActionFrameTip"), function()
                onChangePreCB()

                for k, v in pairs(track.frames) do
                    if v == frame then
                        table.remove(track.frames, k)
                        break
                    end
                end
                onChangeFinishCB()
            end)
        end
    end
    
    if canAddFrame then
        ImGui.SameLine()
        if ImGui.Button("add frame") then
            onChangePreCB()

            local frame = self:getNearFrame(track.frames, curTime)
            local newFrame
            if frame then
                newFrame = clone(frame)
            else
                newFrame = self:newDefaultFrame(track)
            end

            newFrame.time = curTime

            table.insert(track.frames, newFrame)
            table.sort(track.frames, function(a, b)
                return a.time < b.time
            end)

            onChangeFinishCB()
        end
    end
end

return BaseTrack

