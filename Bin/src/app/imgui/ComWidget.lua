-- @Author: fangcheng
-- @Date:   2020-04-12 13:52:08
-- @Description: 通用UI


-- @brief 弹出提示框
-- @param content 提示内容
-- @param closeCall 弹窗关闭回调
_MyG.ShowTipBox = function(content, closeCall)
    local msgBox = require("app.imgui.popup.MessageBox").new()
    msgBox:setContent(content)
    msgBox:addBtn("OK", closeCall)
    msgBox:setDefaultCloseCall(closeCall)
    _MyG.PopupManager:addPopup(msgBox)
    return msgBox
end

-- @brief 弹出选项框
_MyG.ShowOptBox = function(content, okcall, cancelcall, closecall)
    local msgBox = require("app.imgui.popup.MessageBox").new()
    msgBox:setContent(content)
    msgBox:addBtn("OK", okcall)
    msgBox:addBtn("Cancel", cancelcall)
    msgBox:setDefaultCloseCall(closecall)
    _MyG.PopupManager:addPopup(msgBox)
    return msgBox
end



local curLoading = nil

-- @brief 显示通用loading
function _MyG:ShowLoading(percent)
    curLoading = require("app.imgui.popup.Loading").new()
    _MyG.PopupManager:addPopup(curLoading)
end

-- @brief 隐藏通用loading
function _MyG:HideLoading()
    if curLoading then
        curLoading:close()
        curLoading = nil
    end
end

function _MyG:PercentLoading(percent)
    if curLoading then
        curLoading:setPercent(percent)
    end
end
