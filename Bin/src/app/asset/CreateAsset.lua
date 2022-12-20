-- @Author: fangcheng
-- @Date:   2021-07-24 16:47:47
-- @remark: 

local Asset = require("app.asset.Asset")

local AssetCreate = {}

-- 资源创建
function AssetCreate:createAsset(path, createCall, finishCall)
    local FileDialog = require("app.imgui.FileDialog")

    local dilog = _MyG.Functions:createDilog(FileDialog.FileDialogUsage_SaveFile, path, function(value)
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

local typeMap = {
    [Asset.ResType.WIDGET] = "widget",
    [Asset.ResType.LAYER] = "layer",
    [Asset.ResType.MAP] = "map",
    [Asset.ResType.ROLE] = "role",
}

function AssetCreate:create(assetType, path, finishCall)
    local name = typeMap[assetType]

    if name then
        self:createAsset(path, function()
            local templateFile = string.format("res/template/%s.asset", name)
            return json.decode(cc.FileUtils:getInstance():getStringFromFile(templateFile))
        end, finishCall)
    end
end

return AssetCreate
