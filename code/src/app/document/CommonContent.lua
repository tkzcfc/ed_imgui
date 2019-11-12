local AssetContent = require("app.document.AssetContent")
local CommonContent = class("CommonContent", AssetContent)

function CommonContent:ctor(name)
	CommonContent.super.ctor(self, name)

	G_SysEventEmitter:removeListener("onAssetContentUpdate", self.onAssetContentUpdateHandle)
	G_SysEventEmitter:on("onAssetCommonUpdate", self.onAssetContentUpdateHandle)
end

function CommonContent:updateContent()
	self:initFilters()

	local rootPath = _MyG.GlobalData.CommonResourcePath

	local showData = {}
	showData.name = _MyG.GlobalData.CommonResourceDirName
	showData.noOpen = false
	showData.noDrag = true
	showData.dataDirty = true
	showData.fullPath = rootPath
	self:setShowData(showData)
end

return CommonContent
