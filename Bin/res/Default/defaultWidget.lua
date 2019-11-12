-- This file is generated automatically. Please do not change it
local M = {}
function M:loadNode()
local _root = cc.Node:create()
_root:setName("_root")

local Sprite_1 = cc.Sprite:create("Default/DefaultWidget.png")
Sprite_1:setName("Sprite_1")
Sprite_1:setAnchorPoint(cc.p(0.50, 0.50))
Sprite_1:setPosition(0.00, 0.00)
Sprite_1:setContentSize(cc.size(64.00, 64.00))
_root:addChild(Sprite_1)
return _root
end

M.bgCellData = {
    ["rect_data"] = {
        [1] = {
            ["points"] = {
                [1] = {
                    ["y"] = -28.381561279297,
                    ["x"] = -31.955932617188,
                },
                [2] = {
                    ["y"] = -28.381561279297,
                    ["x"] = 34.600036621094,
                },
                [3] = {
                    ["y"] = 31.520416259766,
                    ["x"] = 34.600036621094,
                },
                [4] = {
                    ["y"] = 31.520416259766,
                    ["x"] = -31.955932617188,
                },
            },
        },
    },
    ["referenceResources"] = {
        [1] = "Commons/Default/DefaultWidget.png",
    },
    ["line_data"] = {
    },
}
return M
