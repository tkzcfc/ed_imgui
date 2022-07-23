-- @Author: fangcheng
-- @Date:   2021-07-24 16:43:38
-- @remark: asset file open

local Functions = _MyG.Functions


-- 单视口模式,同时只允许一个文件打开
local SINGLE_MODE = true

-- 打开文件时是否预加载资源
local IS_PRELOAD_RESOURCE = true


local function Lua_Error_hook(err)
    logE(debug.traceback(err, 3))
end

local OpenAsset = {}

local isFirst = true

function OpenAsset:openAsset(asset, createCall)
    local fullPath = asset:getFilePath()

    local data = asset.assetManager:getAssetData(fullPath)
    if not data then
        logE(string.format("[1]Failed to open resource %q", tostring(fullPath)))
        return
    end

    local docName = Tools:replaceString(fullPath, ".asset", "." .. data.type)
    docName = Functions:getRelativePath(docName)

    if _MyG.CenterDocumentManager:hasDocument(docName) then
        _MyG.CenterDocumentManager:setCurShowDocumentByName(docName)
    else
        -- 单视口模式
        if SINGLE_MODE then
            local documents = _MyG.CenterDocumentManager:getDocuments()

            local canRemoveDoc = nil
            for k, document in pairs(documents) do
                if document:canRemove() then
                    canRemoveDoc = document
                    break
                end
            end

            if canRemoveDoc then
                -- 订阅关闭相关事件
                local function removeAllListener()
                    G_SysEventEmitter:off(self.on_ON_DUCUMENT_CLOSED_handle)
                    G_SysEventEmitter:off(self.on_ON_DUCUMENT_CLOSE_CANCEL_handle)
                    self.on_ON_DUCUMENT_CLOSED_handle = nil
                    self.on_ON_DUCUMENT_CLOSE_CANCEL_handle = nil
                end

                removeAllListener()

                self.on_ON_DUCUMENT_CLOSED_handle = G_SysEventEmitter:once(SysEvent.ON_DUCUMENT_CLOSED, function()
                    removeAllListener()
                    self:openAsset(asset, createCall)
                end, self)
                self.on_ON_DUCUMENT_CLOSE_CANCEL_handle = G_SysEventEmitter:once(SysEvent.ON_DUCUMENT_CLOSE_CANCEL, function()
                    removeAllListener()
                end, self)

                -- 加入关闭队列
                _MyG.CenterDocumentManager:addCloseQueue(canRemoveDoc)
                return
            end
        end

        if IS_PRELOAD_RESOURCE then
            if isFirst then
                isFirst = false
                -- 现在有个Bug：异步加载资源后在打开第一个文件时内容不显示，鼠标放到中间窗口才显示,这儿做个处理第一次直接打开
                self:createContext(docName, fullPath, data, createCall)
            else
                _MyG.ShowLoading()

                -- 获取文件中的资源引用列表
                local refs = _MyG.Functions:getRefResourcesByAssetJsonData(data)

                -- 异步加载引用到的资源
                local loadAsync = G_Class.LoadAsync.new()

                for k, v in pairs(refs) do
                    loadAsync:addLoadResource(v, false)
                end

                loadAsync:start(function(taskPercent, totalPercent)
                    -- print(totalPercent)
                end,
                function()
                    -- 加载完成
                    local scheduleHandler
                    local sharedScheduler = cc.Director:getInstance():getScheduler()

                    scheduleHandler = sharedScheduler:scheduleScriptFunc(function()
                        sharedScheduler:unscheduleScriptEntry(scheduleHandler)
                        _MyG.HideLoading()
                        self:createContext(docName, fullPath, data, createCall)
                    end, 0, false)
                end,
                function(error_msg)
                    -- 加载出错
                    logE(error_msg)
                    _MyG.HideLoading()
                end)
            end
        else
            self:createContext(docName, fullPath, data, createCall)
        end
    end
end

-- @brief 通过data创建对应的编辑内容
function OpenAsset:createContext(docName, fullPath, data, createCall)
    local context = nil

    local status = xpcall(function() 
        context = createCall(docName, data)
    end, Lua_Error_hook)

    if not status or context == nil then
        logE(string.format("[2]Failed to open resource %q", tostring(fullPath)))
        return
    end

    _MyG.CenterDocumentManager:addDocument(context)
    _MyG.CenterDocumentManager:setCurShowDocumentByName(docName)
end

-- @brief widget 文件打开
function OpenAsset:openWidget(asset)
    self:openAsset(asset, function(docName, data)
        local context = require("app.document.context.EditorWidget").new(docName, asset)
        if context:deserialize(data.data) then
            return context
        end
        context:destroy()
    end)
end

-- @brief layer 文件打开
function OpenAsset:openLayer(asset)
    self:openAsset(asset, function(docName, data)
        local context = require("app.document.context.EditorLayer").new(docName, asset)
        if context:deserialize(data.data) then
            return context
        end
        context:destroy()
    end)
end

-- @brief map 文件打开
function OpenAsset:openMap(asset)
    self:openAsset(asset, function(docName, data)
        local context = require("app.document.context.EditorMap").new(docName, asset)
        if context:deserialize(data.data) then
            return context
        end
        context:destroy()
    end)
end

-- @brief role 文件打开
function OpenAsset:openRole(asset)
    self:openAsset(asset, function(docName, data)
        local context = require("app.document.context.EditorRole").new(docName, asset)
        if context:deserialize(data.data) then
            return context
        end
        context:destroy()
    end)
end

-- @brief 打开图片
function OpenAsset:openTexture(asset)
    self:openImage(asset:getFilePath(), false)
end

-- @brief 打开图集子图
function OpenAsset:openPlistTexture(asset)
	if asset:isGenTexture() then
		self:openImage(asset:getGenTextureName(), false)
	end
end


-- @brief 图片预览
-- @param imgPath 纹理路径
-- @param isPlist 是否是plist文件
-- @param plistFile plist文件名
local openImageDrawHandler = nil
function OpenAsset:openImage(imgPath, isPlist, plistFile)
    if self.curShowImageWindow_FullPath and self.curShowImageWindow_FullPath == imgPath then
        return
    end

    if isPlist then
        cc.SpriteFrameCache:getInstance():addSpriteFrames(plistFile)
    end

    local textureID = Tools:getImguiTextureID(imgPath, isPlist)
    if textureID == nil then
        logE("Failed to get '%s' texture", imgPath)
        return
    end
    Tools:retainImageuiTexture(textureID)

    self.curShowImageWindow_FullPath = imgPath

    local winSize = Tools:getWindowSize()
    local maxWindW = winSize.width * 0.7
    local maxWindH = winSize.height * 0.7

    local windW = Tools:getImguiTextureWidth(imgPath)
    local windH = Tools:getImguiTextureHeight(imgPath)
    local imageSize = cc.p(windW, windH)
    windW = windW + 40
    windH = windH + 80
    windW = math.max(windW, 100)
    windH = math.max(windH, 100)
    windW = math.min(windW, maxWindW)
    windH = math.min(windH, maxWindH)

    local windSize = cc.p(windW, windH)
    local windPivot = cc.p(0.5, 0.5)
    local windPos = cc.p(winSize.width * 0.5, winSize.height * 0.5)
    local scrolling_size = VecZero

    local showTextureInfo = string.format("%d*%d", windW, windH)

    local flags = 0
    flags = Tools:bor_int32(flags, ImGuiWindowFlags_NoSavedSettings)

    local tmp
    local isShow = true

    if openImageDrawHandler then
        G_SysEventEmitter:off(openImageDrawHandler)
        openImageDrawHandler = nil
    end

    openImageDrawHandler = G_SysEventEmitter:on(SysEvent.ON_GUI, function()
        ImGui.SetNextWindowSize(windSize, ImGuiCond_Appearing)
        ImGui.SetNextWindowPos(windPos, ImGuiCond_Appearing, windPivot)
        tmp, isShow = ImGui.Begin("Image", isShow, flags)
            ImGui.BeginChild("scrolling", scrolling_size, false, ImGuiWindowFlags_HorizontalScrollbar)
            ImGui.Text(showTextureInfo)
            ImGui.Image(textureID, imageSize)
            ImGui.EndChild()
        ImGui.End()

        if not isShow then
            G_SysEventEmitter:off(openImageDrawHandler)
            Tools:freeImageuiTexture(textureID)
            self.curShowImageWindow_FullPath = nil
            openImageDrawHandler = nil
            textureID = nil
            textureCleanup()
        end
    end, SysEvent.TAG)
end







local openSwitch = {
    [Asset.ResType.WIDGET] = function(asset)
        OpenAsset:openWidget(asset)
    end,
    [Asset.ResType.LAYER] = function(asset)
        OpenAsset:openLayer(asset)
    end,
    [Asset.ResType.MAP] = function(asset)
        OpenAsset:openMap(asset)
    end,
    [Asset.ResType.ROLE] = function(asset)
        OpenAsset:openRole(asset)
    end,
    [Asset.ResType.PNG] = function(asset)
        OpenAsset:openTexture(asset)
    end,
    [Asset.ResType.JPG] = function(asset)
        OpenAsset:openTexture(asset)
    end,
    [Asset.ResType.PLIST_SUBGRAPH] = function(asset)
        OpenAsset:openPlistTexture(asset)
    end,
}


function OpenAsset:canOpen(asset)
    local resType = asset.property.resType
    
    return openSwitch[resType] ~= nil
end

function OpenAsset:open(asset)
    local resType = asset.property.resType
    openSwitch[resType](asset)
end


return OpenAsset


