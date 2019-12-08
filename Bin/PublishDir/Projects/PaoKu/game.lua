-- This file is generated automatically.
-- Generated automatically by ed_imgui on 12/08/19 12:51:35.
local M = {}
function M:loadNode()
    local _root = cc.Node:create()
    _root:setName("_root")

    local Sprite_1 = cc.Sprite:create("Projects/PaoKu/Bg_game.png")
    Sprite_1:setName("Sprite_1")
    Sprite_1:setAnchorPoint(cc.p(0.00, 0.00))
    Sprite_1:setPosition(0.00, 0.00)
    Sprite_1:setContentSize(cc.size(2048.00, 1024.00))
    Sprite_1.boxData = {
        ["y"] = 0,
        ["x"] = 0,
        ["height"] = 1024,
        ["width"] = 2048
    }
    _root:addChild(Sprite_1)

    local Sprite_2 = cc.Sprite:create("Projects/PaoKu/Bg_game2.png")
    Sprite_2:setName("Sprite_2")
    Sprite_2:setAnchorPoint(cc.p(0.00, 0.00))
    Sprite_2:setPosition(2048.00, 0.00)
    Sprite_2:setContentSize(cc.size(2048.00, 1024.00))
    Sprite_2.boxData = {
        ["y"] = 0,
        ["x"] = 2048,
        ["height"] = 1024,
        ["width"] = 2048
    }
    _root:addChild(Sprite_2)
    return _root
end

M.bgCellData = {
    ["child_rect_data"] = {},
    ["line_data"] = {},
    ["child_line_data"] = {},
    ["workSpace"] = {[2] = 1024, [1] = 4069},
    ["rect_data"] = {},
    ["referenceResources"] = {
        [1] = "Projects/PaoKu/Bg_game.png",
        [2] = "Projects/PaoKu/Bg_game2.png"
    }
}
return M
