local AssetContent = require("app.document.AssetContent")
local CocosContent = class("CocosContent", AssetContent)

function CocosContent:ctor(name)
	CocosContent.super.ctor(self, name)

	G_SysEventEmitter:removeListener("onAssetContentUpdate", self.onAssetContentUpdateHandle)
	G_SysEventEmitter:on("onAssetCocosUpdate", self.onAssetContentUpdateHandle)
end

function CocosContent:initFilters()
	self.filters = 
	{
		"png",
		"lua",
	}
end

function CocosContent:updateContent()
	self:initFilters()

	local rootPath = _MyG.GlobalData.CocosResourcePath

	local showData = {}
	showData.name = _MyG.GlobalData.CocosResourceDirName
	showData.noOpen = false
	showData.noDrag = true
	showData.dataDirty = true
	showData.fullPath = rootPath
	self:setShowData(showData)
end

function CocosContent:Menu_OnGUI()
	if ImGui.MenuItem(STR("Update")) then
		self:updateContentExt()
	end
end

return CocosContent
