-- @Author: fangcheng
-- @Date:   2021-06-26 20:25:53
-- @remark: 动画渲染

local TYPE = enum {
    "EXPORTJSON",   -- cocos自带骨骼动画
    "SPINE",        -- spine动画
    "UNKNOWN",      -- 未知类型
}

local ArmatureRender = class("ArmatureRender", cc.Node)

ArmatureRender.TYPE = TYPE


local FileUtilsInstance = cc.FileUtils:getInstance()

function ArmatureRender:ctor()
    -- 是否循环播放
    self.bLoop = false
    -- 正在播放的动作名
    self.curPlayname = ""
    -- 正在播放的动作名下标
    self.iCurPlayIndex = 0
    -- 动作列表
    self.playNames = {}

    -- 当前动画类型
    self.curType = TYPE.UNKNOWN
end

function ArmatureRender:initWithFile(file, index, loop)
    -- 创建对应的动画渲染节点
    if self.render == nil or self.resFile ~= file then
        self.resFile = file

        if self.render then
            self.render:setVisible(false)

            -- 延迟删除,cocos自带的Armature动画立即删除会造成崩溃
            self.render:runAction(cc.Sequence:create(
                cc.DelayTime:create(2),
                cc.RemoveSelf:create()
            ))
            self.render = nil
        end

        -- 更新类型
        self:updateType()

        -- cocos 自带的Armature动画
        if self.curType == TYPE.EXPORTJSON then
            display.loadSpriteFrames("rect_collide.plist", "rect_collide.png")

            local filename = G_Helper.getLastName(self.resFile)
            local clsName = G_Helper.getFileClsName(filename)

            if ccs.ArmatureDataManager:getInstance():getArmatureData(clsName) == nil then
                ccs.ArmatureDataManager:getInstance():addArmatureFileInfo(self.resFile)
            end

            self.render = ccs.Armature:create()
            self.render:init(clsName)
            self:addChild(self.render)
        -- spine
        elseif self.curType == TYPE.SPINE then
			local atlasFile = string.gsub(self.resFile, ".json$", ".atlas")
            self.render = sp.SkeletonAnimation:create(self.resFile, atlasFile)
            self:addChild(self.render)
        else
            -- 不支持的动画格式
            assert(0)
        end

        -- 更新动作名称
        self:updatePlayNames()
    end

    -- 播放对应动画
    if index then
        self:playWithIndex(index, loop)
    else
        self:play(self:getDefaultPlayName())
    end
end

-- @brief 更新骨骼动画类型
function ArmatureRender:updateType()
    local extension = G_Helper.getExtension(self.resFile)
    self.fileExtension = extension

    -- cocos 自带的Armature动画
    if extension == "exportjson" then
        self.curType = TYPE.EXPORTJSON
    elseif extension == "json" then
        local atlasFile = string.gsub(self.resFile, ".json$", ".atlas")
        if FileUtilsInstance:isFileExist(atlasFile) then
            self.curType = TYPE.SPINE
        end
    elseif extension == "bytes" then
        local atlasFile = string.gsub(self.resFile, ".bytes$", ".atlas")
        if FileUtilsInstance:isFileExist(atlasFile) then
            self.curType = TYPE.SPINE
        end
    elseif extension == "skel" then
        local atlasFile = string.gsub(self.resFile, ".skel$", ".atlas")
        if FileUtilsInstance:isFileExist(atlasFile) then
            self.curType = TYPE.SPINE
        end        
    else
        self.curType = TYPE.UNKNOWN
        -- 不支持的动画格式
        assert(0)
    end
end

-- @brief 动画播放
function ArmatureRender:play(name, loop)
    if loop == nil then loop = false end
    if name == nil then
        logE("ArmatureRender:play invalid argument")
        return
    end

    -- 查找对应Index
    self.iCurPlayIndex = -1
    for k,v in pairs(self.playNames) do
        if v == name then
            self.iCurPlayIndex = k
            break
        end
    end
    if self.iCurPlayIndex == -1 then
        self.iCurPlayIndex = 0
        logE("No corresponding animation found", name)
        return
    end

    -- 
    if self.bLoop == loop and self.curPlayname == name then
        return
    end
    self.bLoop = loop
    self.curPlayname = name

    if self.curType == TYPE.EXPORTJSON then
        if self.bLoop then
            self.render:getAnimation():play(name, -1, 1)
        else
            self.render:getAnimation():play(name, -1, 0)
        end
    -- spine
    elseif self.curType == TYPE.SPINE then
        
    end
end

-- @brief 动画播放
function ArmatureRender:playWithIndex(index, loop)
    -- 找不到对应的动画名,切换至默认动画
    if self.playNames[index] == nil then
        self:play(self:getDefaultPlayName(), loop)

        logW(string.format(STR("PLAY_NO_FOUND_IDX"), index), self.resFile)
    else
        self:play(self.playNames[index], loop)
    end
end

-- @brief 通过下标获取动画名
function ArmatureRender:getPlayNameByIndex(index)
    return self.playNames[index]
end

-- @brief 
function ArmatureRender:hasPlayName(name)
    for k, v in pairs(self.playNames) do
        if v == name then return true end
    end
end

-- @brief 获取播放动画名称列表
function ArmatureRender:getPlayNames()
    return self.playNames
end

-- @brief 获取动画对应的播放时长
function ArmatureRender:getPlayDuration(index)
    return self.playDurations[index]
end

-- @brief 获取动画对应的播放时长
function ArmatureRender:getPlayDurationByName(name)
    if name == nil then
        name = self:getCurPlayName()
    end
    for k, v in pairs(self.playNames) do
        if v == name then
            return self.playDurations[k]
        end
    end
    assert(0)
end

-- @brief 当前播放的动画下标
function ArmatureRender:getCurPlayIndex()
    return self.iCurPlayIndex
end

-- @brief 当前播放的动画名称
function ArmatureRender:getCurPlayName()
    return self:getPlayNameByIndex(self.iCurPlayIndex)
end

-- @brief 是否循环播放
function ArmatureRender:isPlayLoop()
    return self.bLoop
end

-- @brief 获取当前碰撞矩形
function ArmatureRender:getBox()
    return self.render:getBoundingBox()
end

-- @brief
function ArmatureRender:getPlayNames_imguiCombo()
    return self.playNames_imguiCombo
end

-- @brief 获取默认播放动画名称
function ArmatureRender:getDefaultPlayName()
    local list = self:getPlayNames()
    local find = false
    for k,v in pairs(list) do
        if v == self.curPlayname then
            find = true
            break
        end
    end

    if find then
        return self.curPlayname
    end
    return list[1]
end

-- @brief 更新播放列表
function ArmatureRender:updatePlayNames()
    self.iCurPlayIndex = 0
    self.bLoop = false
    self.playNames = {}
    self.playDurations = {}
    if self.curType == TYPE.EXPORTJSON then
        self.playNames = Tools:getArematureMovementNames(self.render)
        self.playDurations = Tools:getArematureMovementDurations(self.render)
    -- spine
    elseif self.curType == TYPE.SPINE then
        
    end

    self.playNames_imguiCombo = table.concat(self.playNames, "\0")
    self.playNames_imguiCombo = self.playNames_imguiCombo .. "\0\0"
end

return ArmatureRender