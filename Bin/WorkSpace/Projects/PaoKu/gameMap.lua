-- This file is generated automatically. Please do not change it
-- Generated automatically by ed_imgui on 11/12/19 16:10:51.
local M = {}

function M:loadBackgroundNode()
    local _root = cc.Node:create()
    _root:setName("_root")

    local Layer_11_luafile = require("Projects.PaoKu/game")
    local Layer_11 = Layer_11_luafile:loadNode()
    Layer_11.LuaFileInfo = Layer_11_luafile
    Layer_11:setLocalZOrder(1)
    _root:addChild(Layer_11)
    return _root
end

function M:loadGameNode()
    local _root = cc.Node:create()
    _root:setName("_root")

    local Layer_1_luafile = require("Projects.PaoKu/test")
    local Layer_1 = Layer_1_luafile:loadNode()
    Layer_1.LuaFileInfo = Layer_1_luafile
    Layer_1:setLocalZOrder(2)
    _root:addChild(Layer_1)
    return _root
end

function M:loadForegroundNode() end

M.bgCellData = {
    ["rect_data"] = {
        [1] = {
            ["points"] = {
                [4] = {["y"] = 302.21655273438, ["x"] = 1307.5637207031},
                [1] = {["y"] = 131.66491699219, ["x"] = 1307.5637207031},
                [2] = {["y"] = 131.66491699219, ["x"] = 1623.7087402344},
                [3] = {["y"] = 302.21655273438, ["x"] = 1623.7087402344}
            }
        }
    },
    ["referenceResources"] = {
        [1] = "Projects/PaoKu/Bg_game2.png",
        [2] = "Projects/PaoKu/Bg_game.png",
        [3] = "Res/gem_icon/icon_4.png",
        [4] = "Default/ImageFile.png",
        [5] = "Default/Sprite.png",
        [6] = "king.plist"
    },
    ["line_data"] = {
        [1] = {
            ["points"] = {
                [2] = {["y"] = 801.39807128906, ["x"] = 454.80603027344},
                [5] = {["y"] = 414.53430175781, ["x"] = 2484.8015136719},
                [3] = {["y"] = 797.23645019531, ["x"] = 879.10717773438},
                [7] = {["y"] = 439.49255371094, ["x"] = 417.35681152344},
                [1] = {["y"] = 451.97155761719, ["x"] = 425.68017578125},
                [4] = {["y"] = 788.91882324219, ["x"] = 2493.11328125},
                [6] = {["y"] = 506.04968261719, ["x"] = 1428.1989746094}
            },
            ["normals"] = {
                [2] = {["y"] = 0.99995183944702, ["x"] = 0.0098076621070504},
                [5] = {["y"] = -0.99627006053925, ["x"] = -0.086289763450623},
                [3] = {["y"] = 0.99998670816422, ["x"] = 0.0051532927900553},
                [1] = {["y"] = 0.083065196871758, ["x"] = -0.99654412269592},
                [4] = {["y"] = -0.02219564281404, ["x"] = 0.99975377321243},
                [6] = {["y"] = -0.99783933162689, ["x"] = 0.065701022744179}
            }
        }
    }
}

M.revivePoints = {
    [1] = {["y"] = 473.17599487305, ["x"] = 251.19519042969},
    [2] = {["y"] = 479.21868896484, ["x"] = 614.91412353516},
    [3] = {["y"] = 476.58236694336, ["x"] = 876.66912841797},
    [4] = {["y"] = 465.92367553711, ["x"] = 1151.5935058594}
}

return M
