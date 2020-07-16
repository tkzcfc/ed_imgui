-- @Author: fangcheng
-- @URL: github.com/tkzcfc
-- @Date:   2020-04-11 14:28:58
-- @Description: 

local Asset = import(".Asset")
local Asset_File = class("Asset_File", Asset)

function Asset_File:destroy()
	Asset_File.super.destroy(self)
	self:clearPopupGUIHandle()
end

function Asset_File:clearPopupGUIHandle()
	if self.popup_gui_handle then
		G_SysEventEmitter:removeListener("onGUI", self.popup_gui_handle)
		self.popup_gui_handle = nil
	end
end

-- 鼠标右键单击
function Asset_File:_onRightClick()
	self:clearPopupGUIHandle()

	self.popup_gui_handle = function()
		if ImGui.BeginPopup("assetContent_popup") then
			G_SysEventEmitter:emit("asset_Menu_OnGUI", self)
			ImGui.EndPopup()
		else
			self:clearPopupGUIHandle()
		end
	end

	G_SysEventEmitter:once("onGUI", function()
		ImGui.OpenPopup("assetContent_popup")
	end)

	G_SysEventEmitter:on("onGUI", self.popup_gui_handle)
end

return Asset_File
