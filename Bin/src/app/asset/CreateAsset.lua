-- @Author: fangcheng
-- @Date:   2021-07-24 16:47:47
-- @remark: 

---------------------------------------------------------- [data] ----------------------------------------------------------

local FILE_EMPTY_DATA = {
    children = {},
    context = {
        plugins = {},
    }
}

-- widget 文件初始数据结构
local FILE_EMPTY_DATA_WIDGET = clone(FILE_EMPTY_DATA)
FILE_EMPTY_DATA_WIDGET.context.plugins = {
    PluginLineRect = {
        rect_data = {},
        line_data = {},
    },
}

-- layer 文件初始数据结构
local FILE_EMPTY_DATA_LAYER = clone(FILE_EMPTY_DATA)
FILE_EMPTY_DATA_LAYER.context.plugins = {
    PluginLayerSize = {
        size = cc.p(_MyG.Editor_DesignResolution.width, _MyG.Editor_DesignResolution.height),
        color = cc.c4f(0.9, 0, 1, 1),
    }
}

-- map 文件初始数据结构
local FILE_EMPTY_DATA_MAP = clone(FILE_EMPTY_DATA)


-- role 文件初始数据结构
local FILE_EMPTY_ROLE = clone(FILE_EMPTY_DATA)

local role = {}
-- 动画文件
role.resFile = "Default/DemoPlayer.ExportJson"
-- 渲染时偏移值
role.offset = {x = 0, y = 0}
-- 半径
role.radius = 15
-- 体积
-- x: 身体宽度X轴
-- y: 身高
-- z: 身体宽度Y轴(主要用于移动是的碰撞判断，真正的Y轴范围攻击判定是半径radius)
role.roleSize = {x = 50, y = 85, z = 10}
-- 质量
role.mass = 1
-- 移动速度
role.velocity = {x = 10, y = 10, z = 0}
-- 跳跃冲力(只有y有效)
role.impulsion = {x = 0, y = 10, z = 0}
-- 资源朝向
role.directionLeft = false
FILE_EMPTY_ROLE.context.role = role

---------------------------------------------------------- [data] ----------------------------------------------------------


local Functions = _MyG.Functions

local AssetCreate = {}

-- 资源创建
function AssetCreate:createAsset(path, createCall, finishCall)
    local FileDialog = require("app.imgui.FileDialog")

    local dilog = Functions:createDilog(FileDialog.FileDialogUsage_SaveFile, path, function(value)
        if value == nil then
            return
        end

        local data = nil
        if createCall then
            data = createCall()
        end

        local ret = _MyG.ProjectAssetManager:writeAssetData(value[1].fullPath, data, true)
        if finishCall then
            finishCall(ret)
        end
    end)
    dilog:addFilter("asset")
    dilog:setCanOverlap(false)
end

-- 地图创建
function AssetCreate:createMap(path, finishCall)
    self:createAsset(path, function()
        return {
            type = "map",
            data = FILE_EMPTY_DATA_MAP,
        }
    end, finishCall)
end

-- Widget 创建
function AssetCreate:createWidget(path, finishCall)
    self:createAsset(path, function()
        return {
            type = "widget",
            data = FILE_EMPTY_DATA_WIDGET,
        }
    end, finishCall)
end

-- Layer 创建
function AssetCreate:createLayer(path, finishCall)
    self:createAsset(path, function()
        return {
            type = "layer",
            data = FILE_EMPTY_DATA_LAYER,
        }
    end, finishCall)
end

-- role 创建
function AssetCreate:createRole(path, finishCall)
    self:createAsset(path, function()
        return {
            type = "role",
            data = FILE_EMPTY_ROLE,
        }
    end, finishCall)
end

function AssetCreate:create(assetType, path, finishCall)
    if assetType == Asset.ResType.WIDGET then
        self:createWidget(path, finishCall)
    elseif assetType == Asset.ResType.LAYER then
        self:createLayer(path, finishCall)
    elseif assetType == Asset.ResType.MAP then
        self:createMap(path, finishCall)
    elseif assetType == Asset.ResType.ROLE then
        self:createRole(path, finishCall)
    end
end



return AssetCreate
