-- This file is generated automatically.
-- Generated automatically by ed_imgui on 12/08/19 12:51:32.
local M = {}
function M:loadNode()
    local _root = cc.Node:create()
    _root:setName("_root")

    local Sprite_1 = cc.Sprite:create("Projects/PaoKu/bomb_red.png")
    Sprite_1:setName("Sprite_1")
    Sprite_1:setAnchorPoint(cc.p(0.50, 0.50))
    Sprite_1:setPosition(0.00, 0.00)
    Sprite_1:setContentSize(cc.size(107.00, 32.00))
    _root:addChild(Sprite_1)
    return _root
end

M.bgCellData = {
    ["rect_data"] = {
        [1] = {
            ["points"] = {
                [1] = {["y"] = -16.377075195313, ["x"] = -53.66552734375},
                [2] = {["y"] = -16.377075195313, ["x"] = 46.171936035156},
                [3] = {["y"] = 16.069702148438, ["x"] = 46.171936035156},
                [4] = {["y"] = 16.069702148438, ["x"] = -53.66552734375}
            }
        }
    },
    ["referenceResources"] = {[1] = "Projects/PaoKu/bomb_red.png"},
    ["line_data"] = {}
}
return M
