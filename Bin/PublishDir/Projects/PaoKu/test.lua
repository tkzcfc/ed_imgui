-- This file is generated automatically. Please do not change it
-- Generated automatically by ed_imgui on 11/12/19 16:11:12.
local M = {}
function M:loadNode()
    local _root = cc.Node:create()
    _root:setName("_root")

    local CocostudioFile_1 = G_Helper.loadStudioFile("CocoStudioFile")
    if CocostudioFile_1.animation then
        CocostudioFile_1.animation:gotoFrameAndPlay(0, true)
        CocostudioFile_1.root:runAction(CocostudioFile_1.animation)
    end
    CocostudioFile_1.root:setPosition(648.00, 615.17)
    CocostudioFile_1.boxData = {
        ["y"] = 427.13220214844,
        ["x"] = 433.87812805176,
        ["height"] = 376.08770751953,
        ["width"] = 428.26220703125
    }
    _root:addChild(CocostudioFile_1.root)

    local CocostudioFile_2 = G_Helper.loadStudioFile("CocoStudioFile")
    if CocostudioFile_2.animation then
        CocostudioFile_2.animation:gotoFrameAndPlay(0, true)
        CocostudioFile_2.root:runAction(CocostudioFile_2.animation)
    end
    CocostudioFile_2.root:setPosition(2268.91, 610.64)
    CocostudioFile_2.boxData = {
        ["y"] = 422.59490966797,
        ["x"] = 2054.7840118408,
        ["height"] = 376.08770751953,
        ["width"] = 428.26220703125
    }
    _root:addChild(CocostudioFile_2.root)

    local CocostudioFile_3 = G_Helper.loadStudioFile("CocoStudioFile")
    if CocostudioFile_3.animation then
        CocostudioFile_3.animation:gotoFrameAndPlay(0, true)
        CocostudioFile_3.root:runAction(CocostudioFile_3.animation)
    end
    CocostudioFile_3.root:setPosition(3339.78, 510.94)
    CocostudioFile_3.boxData = {
        ["y"] = 322.90231323242,
        ["x"] = 3125.6607208252,
        ["height"] = 376.08770751953,
        ["width"] = 428.26220703125
    }
    _root:addChild(CocostudioFile_3.root)

    local Image_4 = ccui.ImageView:create()
    Image_4:ignoreContentAdaptWithSize(false)
    Image_4:loadTexture("Default/ImageFile.png", 0)
    Image_4:setName("Image_4")
    Image_4:setAnchorPoint(cc.p(0.50, 0.50))
    Image_4:setPosition(462.97, 348.40)
    Image_4:setContentSize(cc.size(46.00, 46.00))
    Image_4.boxData = {
        ["y"] = 325.40142822266,
        ["x"] = 439.97109985352,
        ["height"] = 46,
        ["width"] = 46
    }
    _root:addChild(Image_4)

    local Sprite_5 = cc.Sprite:create("Default/Sprite.png")
    Sprite_5:setName("Sprite_5")
    Sprite_5:setAnchorPoint(cc.p(0.50, 0.50))
    Sprite_5:setPosition(393.79, 293.26)
    Sprite_5:setContentSize(cc.size(46.00, 46.00))
    Sprite_5:setColor(cc.c3b(200, 11, 152))
    Sprite_5.boxData = {
        ["y"] = 270.259765625,
        ["x"] = 370.78680419922,
        ["height"] = 46,
        ["width"] = 46
    }
    _root:addChild(Sprite_5)

    local CocostudioFile_11 = G_Helper.loadStudioFile("CustomFile")
    if CocostudioFile_11.animation then
        CocostudioFile_11.animation:gotoFrameAndPlay(0, true)
        CocostudioFile_11.root:runAction(CocostudioFile_11.animation)
    end
    CocostudioFile_11.root:setPosition(206.35, 453.16)
    CocostudioFile_11.boxData = {
        ["y"] = 381.15594482422,
        ["x"] = 134.34959411621,
        ["height"] = 144,
        ["width"] = 144
    }
    _root:addChild(CocostudioFile_11.root)
    return _root
end

M.bgCellData = {
    ["child_rect_data"] = {},
    ["child_line_data"] = {},
    ["line_data"] = {
        [1] = {
            ["points"] = {
                [1] = {["y"] = 451.97155761719, ["x"] = 425.68017578125},
                [2] = {["y"] = 801.39807128906, ["x"] = 454.80603027344},
                [3] = {["y"] = 797.23645019531, ["x"] = 879.10717773438},
                [4] = {["y"] = 788.91882324219, ["x"] = 2493.11328125},
                [5] = {["y"] = 414.53430175781, ["x"] = 2484.8015136719},
                [6] = {["y"] = 506.04968261719, ["x"] = 1428.1989746094},
                [7] = {["y"] = 439.49255371094, ["x"] = 417.35681152344}
            },
            ["normals"] = {
                [1] = {["y"] = 0.083065196871758, ["x"] = -0.99654412269592},
                [2] = {["y"] = 0.99995183944702, ["x"] = 0.0098076621070504},
                [3] = {["y"] = 0.99998670816422, ["x"] = 0.0051532927900553},
                [4] = {["y"] = -0.02219564281404, ["x"] = 0.99975377321243},
                [5] = {["y"] = -0.99627006053925, ["x"] = -0.086289763450623},
                [6] = {["y"] = -0.99783933162689, ["x"] = 0.065701022744179}
            }
        }
    },
    ["rect_data"] = {
        [1] = {
            ["points"] = {
                [1] = {["y"] = 131.66491699219, ["x"] = 1307.5637207031},
                [2] = {["y"] = 131.66491699219, ["x"] = 1623.7087402344},
                [3] = {["y"] = 302.21655273438, ["x"] = 1623.7087402344},
                [4] = {["y"] = 302.21655273438, ["x"] = 1307.5637207031}
            }
        }
    },
    ["referenceResources"] = {
        [1] = "Res/gem_icon/icon_4.png",
        [2] = "Default/ImageFile.png",
        [3] = "Default/Sprite.png",
        [4] = "king.plist"
    }
}
return M
