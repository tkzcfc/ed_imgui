-- @Author: fangcheng
-- @URL: github.com/tkzcfc
-- @Date:   2020-04-11 11:00:10
-- @Last Modified by:   fangcheng
-- @Last Modified time: 2020-04-12 11:20:39
-- @Description: 
local Document = require("app.imgui.Document")
local FileDialog = require("app.imgui.FileDialog")

local AssetContent = class("AssetContent", Document)

local scrolling_size = cc.p(0, 0)
local scrolling_flag = ImGuiWindowFlags_HorizontalScrollbar

function AssetContent:ctor(name, assetManager)
	AssetContent.super.ctor(self, name)
	self.assetManager = assetManager
end

function AssetContent:onGUI()
	if self.assetManager == nil then
		return
	end

	if self.img_ui_io == nil then
		self.img_ui_io = ImGui.GetIO()
	end

	local rootAsset = self.assetManager.rootAsset

	if rootAsset == nil then
		return
	end

	ImGui.BeginChild("scrolling", scrolling_size, false, scrolling_flag)
	rootAsset:onGUI()
	ImGui.EndChild()
end

function AssetContent:updateAsset()
	local rootAsset = self.assetManager.rootAsset

	if rootAsset == nil then
		return
	end

	rootAsset:refreshAll()
end

function AssetContent:canRemove()
	return false
end

function AssetContent:canClose()
	return false
end

return AssetContent

