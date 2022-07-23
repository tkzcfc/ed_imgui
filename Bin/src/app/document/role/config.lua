



-- 无效文本颜色
cc.exports.INVALID_TEXT_COLOR = ImVec4(1.0, 0, 0, 1.0)

-- 通道颜色块
cc.exports.CHANNEL_EVENT_COLOR = ImVec4(0.51, 1, 0.5, 1)

-- 普通事件块颜色
cc.exports.TRANCK_EVENT_COLOR = ImVec4(150 / 255, 255 / 255, 150 / 255, 1.0)
cc.exports.TRANCK_EVENT_COLOR_MAP = {
    -- 攻击型事件块颜色
	[GFrameType.ATT_COLLISION_FRAME] = ImVec4(1, 0, 0, 0.8),
    -- 防御型事件块颜色
	[GFrameType.DEF_COLLISION_FRAME] = ImVec4(150 / 255, 200 / 255, 1, 1),
    -- 音频
    [GFrameType.AUDIO_FRAME] = ImVec4(150 / 255, 150 / 255, 255 / 255, 1.0),
    -- 音频
    [GFrameType.SCRIPT_FRAME] = ImVec4(255 / 255, 150 / 255, 100 / 255, 1.0),
}


