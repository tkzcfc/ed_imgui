-- This file is generated automatically. Please do not change it
-- Generated automatically by ed_imgui on 11/12/19 16:09:26.
local M = {}
function M:loadNode()
    local _root = cc.Node:create()
    _root:setName("_root")

    local CocostudioFile_1 = G_Helper.loadStudioFile("CustomFile")
    if CocostudioFile_1.animation then
        CocostudioFile_1.animation:gotoFrameAndPlay(0, true)
        CocostudioFile_1.root:runAction(CocostudioFile_1.animation)
    end
    CocostudioFile_1.root:setPosition(-5.06, 11.36)
    _root:addChild(CocostudioFile_1.root)
    return _root
end

M.bgCellData = {
    ["rect_data"] = {
        [1] = {
            ["points"] = {
                [1] = {["y"] = -43.467987060547, ["x"] = -22.109008789063},
                [2] = {["y"] = -43.467987060547, ["x"] = 26.250396728516},
                [3] = {["y"] = 84.446716308594, ["x"] = 26.250396728516},
                [4] = {["y"] = 84.446716308594, ["x"] = -22.109008789063}
            }
        }
    },
    ["referenceResources"] = {[1] = "king.plist"},
    ["line_data"] = {}
}
return M
