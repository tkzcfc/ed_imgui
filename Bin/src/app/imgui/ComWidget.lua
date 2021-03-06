-- @Author: fangcheng
-- @URL: github.com/tkzcfc
-- @Date:   2020-04-12 13:52:08
-- @Last Modified by:   fangcheng
-- @Last Modified time: 2020-05-07 22:22:42
-- @Description: 通用UI


local MsgBoxShowTag = false
local LoadingShowTag = false


-- @brief loading 绘制逻辑
local loadingWindowFlag = ImGuiWindowFlags_NoTitleBar
loadingWindowFlag = Tools:bor_int32(loadingWindowFlag, ImGuiWindowFlags_NoMove)
loadingWindowFlag = Tools:bor_int32(loadingWindowFlag, ImGuiWindowFlags_AlwaysAutoResize)

local function drawLoading()
    if not MsgBoxShowTag then
    	ImGui.OpenPopup("Loading")
    	if ImGui.BeginPopupModal("Loading", true, loadingWindowFlag) then
    	    ImGui.Text("Loading...")
    	    ImGui.EndPopup()
    	end
    end

    if not LoadingShowTag then
        G_SysEventEmitter:removeListener("onGUI", drawLoading)
    end
end




-- @brief  message box 绘制逻辑
local msgWindowFlag = 0
msgWindowFlag = Tools:bor_int32(msgWindowFlag, ImGuiWindowFlags_NoMove)
msgWindowFlag = Tools:bor_int32(msgWindowFlag, ImGuiWindowFlags_AlwaysAutoResize)

local msgBox_WidgetSize = cc.p(0, 0)
local msgBox_ButtonCount = 1
local msgBox_LayoutSize = cc.p(0, 0)

local msgbox_args = {}
local function drawMsgbox()
    ImGui.OpenPopup("MessageBox")
    if ImGui.BeginPopupModal("MessageBox", true, msgWindowFlag) then
        ImGui.Text(msgbox_args.content)
        ImGui.Separator()

        msgBox_LayoutSize.x = ImGui.GetContentRegionAvailWidth()
        ImGui.BeginHorizontal("h1", msgBox_LayoutSize, 0)

        msgBox_WidgetSize.x = msgBox_LayoutSize.x / msgBox_ButtonCount

        if msgbox_args.oneButtontext and msgbox_args.oneButtontext ~= "" then
            if ImGui.Button(msgbox_args.oneButtontext, msgBox_WidgetSize) then
                if msgbox_args.onecall then
                    msgbox_args.onecall()
                end
                _MyG.HideBox()
            end
        end
        if msgbox_args.twoButtontext and msgbox_args.twoButtontext ~= "" then
            if ImGui.Button(msgbox_args.twoButtontext, msgBox_WidgetSize) then
                if msgbox_args.twocall then
                    msgbox_args.twocall()
                end
                _MyG.HideBox()
            end
        end
        if msgbox_args.threeButtontext and msgbox_args.threeButtontext ~= "" then
            if ImGui.Button(msgbox_args.threeButtontext, msgBox_WidgetSize) then
                if msgbox_args.threecall then
                    msgbox_args.threecall()
                end
                _MyG.HideBox()
            end
        end

		ImGui.EndHorizontal()
        ImGui.EndPopup()
    else
        if msgbox_args.defaultcall then
            msgbox_args.defaultcall()
            _MyG.HideBox()
        end
    end
end





-- @brief 显示通用loading
_MyG.ShowLoading = function()
    LoadingShowTag = true
    G_SysEventEmitter:on("onGUI", drawLoading)
end

-- @brief 隐藏通用loading
_MyG.HideLoading = function()
    LoadingShowTag = false
end


-- @brief 弹出选项框
_MyG.ShowBox = function(content, okcall, cancelcall, defaultcall)
    if defaultcall then
        if cancelcall then
            _MyG.ShowThreeButton(content, "OK", "Cancel", nil, okcall, cancelcall, nil, defaultcall)
        else
            _MyG.ShowThreeButton(content, "OK", nil, nil, okcall, nil, nil, defaultcall)
        end
    else
        if cancelcall then
            _MyG.ShowThreeButton(content, "OK", "Cancel", nil, okcall, cancelcall, nil, cancelcall)
        else
            _MyG.ShowThreeButton(content, "OK", nil, nil, okcall, nil, nil, nil)
        end
    end
end

-- @brief 显示三个选项的选项框
_MyG.ShowThreeButton = function(content, oneButtontext, twoButtontext, threeButtontext, onecall, twocall, threecall, defaultcall)
    content = "\t" .. content .. "\t"
    msgbox_args = {}
    msgbox_args["content"] = content
    msgbox_args["oneButtontext"] = oneButtontext
    msgbox_args["twoButtontext"] = twoButtontext
    msgbox_args["threeButtontext"] = threeButtontext
    msgbox_args["onecall"] = onecall
    msgbox_args["twocall"] = twocall
    msgbox_args["threecall"] = threecall
    msgbox_args["defaultcall"] = defaultcall

    msgBox_ButtonCount = 0
    if oneButtontext then
    	msgBox_ButtonCount = msgBox_ButtonCount + 1
    end
    if twoButtontext then
    	msgBox_ButtonCount = msgBox_ButtonCount + 1
    end
    if threeButtontext then
    	msgBox_ButtonCount = msgBox_ButtonCount + 1
    end
    msgBox_ButtonCount = math.max(msgBox_ButtonCount, 1)

    G_SysEventEmitter:on("onGUI", drawMsgbox)
    MsgBoxShowTag = true
end

-- @brief 隐藏弹出框
_MyG.HideBox = function()
    G_SysEventEmitter:removeListener("onGUI", drawMsgbox)
    MsgBoxShowTag = false
end







