local MainWindow = class("MainWindow")

MainWindow.window_w = 280
MainWindow.window_h = 200
MainWindow.topWindow_h = 30

function MainWindow.getImguiWindowTotalWidth()
    local style = ImGui.GetStyle()
    return (MainWindow.window_w + style.WindowPadding.x) * 2
end

function MainWindow.getImguiWindowTotalHeight()
    local style = ImGui.GetStyle()
    return (MainWindow.window_h + style.WindowPadding.y + MainWindow.topWindow_h)
end


function MainWindow:ctor()
    local DocumentManager = require("app.imgui.DocumentManager")
    _MyG.TopDocumentManager = DocumentManager.new()
    _MyG.LeftDocumentManager = DocumentManager.new()
    _MyG.RightDocumentManager = DocumentManager.new()
    _MyG.BottomDocumentManager = DocumentManager.new()

    local winSize = Tools:getWindowSize()

    local windoFlag = 0
    windoFlag = Tools:bor_int32(windoFlag, ImGuiWindowFlags_NoMove)
    windoFlag = Tools:bor_int32(windoFlag, ImGuiWindowFlags_NoResize)
    windoFlag = Tools:bor_int32(windoFlag, ImGuiWindowFlags_NoTitleBar)
    windoFlag = Tools:bor_int32(windoFlag, ImGuiWindowFlags_NoSavedSettings)

    local topwinFlag = windoFlag
    topwinFlag = Tools:bor_int32(topwinFlag, ImGuiWindowFlags_NoScrollbar)
    topwinFlag = Tools:bor_int32(topwinFlag, ImGuiWindowFlags_NoScrollWithMouse)
    topwinFlag = Tools:bor_int32(topwinFlag, ImGuiWindowFlags_NoBringToFrontOnFocus)



    local style = ImGui.GetStyle()
    local io = ImGui.GetIO()

    local beginy = 20

    local leftPos = cc.p(0.0, beginy)
    local leftPivot = cc.p(0.0, 0.0)
    local leftSize = cc.p(MainWindow.window_w, winSize.height - MainWindow.window_h - beginy - 2)

    local rightPos = cc.p(winSize.width, beginy)
    local rightPivot = cc.p(1.0, 0.0)
    local rightSize = leftSize

    local topPos = cc.p(winSize.width * 0.5, beginy)
    local topPivot = cc.p(0.5, 0.0)
    local topSize = cc.p(winSize.width - MainWindow.window_w * 2, MainWindow.topWindow_h)

    local bottomPos = cc.p(winSize.width * 0.5, winSize.height)
    local bottomPivot = cc.p(0.5, 1.0)
    local bottomSize = cc.p(winSize.width - style.DisplaySafeAreaPadding.x * 2, MainWindow.window_h)

    G_SysEventEmitter:on("onGUI", function()
        if ImGui.BeginMainMenuBar() then
            G_SysEventEmitter:emit("onGUI_MainMenuBar")
            ImGui.EndMainMenuBar()
        end

        ImGui.SetNextWindowPos(leftPos, ImGuiCond_Always, leftPivot)
        ImGui.SetNextWindowSize(leftSize, ImGuiCond_Always)
        if Tools:BeginWindow_NoClose("LeftDocumentManager", windoFlag) then
            _MyG.LeftDocumentManager:onGUI()
            ImGui.End()
        end

        ImGui.SetNextWindowPos(topPos, ImGuiCond_Always, topPivot)
        ImGui.SetNextWindowSize(topSize, ImGuiCond_Always)
        if Tools:BeginWindow_NoClose("TopDocumentManager", windoFlag) then
            _MyG.TopDocumentManager:onGUI()
            ImGui.End()
        end

        ImGui.SetNextWindowPos(rightPos, ImGuiCond_Always, rightPivot)
        ImGui.SetNextWindowSize(rightSize, ImGuiCond_Always)
        if Tools:BeginWindow_NoClose("RightDocumentManager", windoFlag) then
            _MyG.RightDocumentManager:onGUI()
            ImGui.End()
        end

        ImGui.SetNextWindowPos(bottomPos, ImGuiCond_Always, bottomPivot)
        ImGui.SetNextWindowSize(bottomSize, ImGuiCond_Always)
        if Tools:BeginWindow_NoClose("BottomDocumentManager", windoFlag) then
            _MyG.BottomDocumentManager:onGUI()
            ImGui.End()
        end
    end)
end

-- function MainWindow:ctor()
--     local DocumentManager = require("app.imgui.DocumentManager")
--     _MyG.TopDocumentManager = DocumentManager.new()
--     _MyG.LeftDocumentManager = DocumentManager.new()
--     _MyG.RightDocumentManager = DocumentManager.new()
--     _MyG.BottomDocumentManager = DocumentManager.new()

--     local winSize = Tools:getWindowSize()
--     local style = ImGui.GetStyle()

--     local windoFlag = 0
--     windoFlag = Tools:bor_int32(windoFlag, ImGuiWindowFlags_NoMove)
--     windoFlag = Tools:bor_int32(windoFlag, ImGuiWindowFlags_NoResize)

--     local space = winSize.width - MainWindow.window_w - style.WindowPadding.x

--     local top_win_width = winSize.width - MainWindow.window_w * 2 - style.WindowPadding.x * 4

--     local top_win_size = cc.p(top_win_width, winSize.height - MainWindow.window_h)
--     local left_win_size = cc.p(MainWindow.window_w, winSize.height - MainWindow.window_h)
--     local right_win_size = cc.p(MainWindow.window_w, winSize.height - MainWindow.window_h)
--     local bottom_win_size = cc.p(0, 0)

--     G_SysEventEmitter:on("onGUI", function()
--         if ImGui.BeginMainMenuBar() then
--             G_SysEventEmitter:emit("onGUI_MainMenuBar")
--             ImGui.EndMainMenuBar()
--         end

--         if ImGui.BeginChild("LeftDocumentManager", left_win_size, true, 0) then
--             _MyG.LeftDocumentManager:onGUI()
--             ImGui.EndChild()
--         end

--         ImGui.SameLine()

--         if ImGui.BeginChild("TopDocumentManager", top_win_size, true, 0) then
--             _MyG.TopDocumentManager:onGUI()
--             ImGui.EndChild()
--         end

--         ImGui.SameLine(space)

--         if ImGui.BeginChild("RightDocumentManager", right_win_size, true, 0) then
--             _MyG.RightDocumentManager:onGUI()
--             ImGui.EndChild()
--         end

--         if ImGui.BeginChild("BottomDocumentManager", bottom_win_size, true, 0) then
--             _MyG.BottomDocumentManager:onGUI()
--             ImGui.EndChild()
--         end
--     end)
-- end

return MainWindow