-- @Author: fangcheng
-- @Date:   2020-04-11 14:28:58
-- @Description: 

local Asset = import(".Asset")
local Asset_File = class("Asset_File", Asset)

function Asset_File:destroy()
	Asset_File.super.destroy(self)
	self:clearPopupGUIHandle()
end

function Asset_File:clearPopupGUIHandle()
	G_SysEventEmitter:offByTag(self)
end

-- 鼠标右键单击
function Asset_File:_onRightClick()
	self:clearPopupGUIHandle()

	G_SysEventEmitter:once(SysEvent.ON_GUI, function()
		ImGui.OpenPopup("assetContent_popup")
	end, self)

	G_SysEventEmitter:on(SysEvent.ON_GUI, function()
		if ImGui.BeginPopup("assetContent_popup") then
			G_SysEventEmitter:emit(SysEvent.ASSET_MENU_ONGUI, self)
			ImGui.EndPopup()
		else
			self:clearPopupGUIHandle()
		end
	end, self)
end

return Asset_File
