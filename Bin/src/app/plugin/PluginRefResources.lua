-- @Author: fangcheng
-- @Date:   2020-06-21 20:25:03
-- @remark: 资源引用分析

local Plugin = import(".Plugin")
local PluginRefResources = class("PluginRefResources", Plugin)

function PluginRefResources:doSerialize()
	local output = PluginRefResources.super.doSerialize(self)


	local M = {}
    self.context.rootElement:forEachChildren(function(ele)
        local refs = ele:getReferenceResources()
        for k,v in pairs(refs) do
        	M[v] = true
        end
    end)

	local refs = self:getMapRefResources()
	for k,v in pairs(refs) do
		M[v] = true
	end

	local outRefs = {}
    for k,v in pairs(M) do
    	if k ~= "" then
    		outRefs[#outRefs + 1] = k
    	end
    end
    output.refs = outRefs

	return output
end

function PluginRefResources:doDeserialize(data)
	if not PluginRefResources.super.doDeserialize(self, data) then
		return false
	end
	return true
end

function PluginRefResources:getMapRefResources()
	local PluginMapLayer = self.context:getPlugin("PluginMapLayer")
	if not PluginMapLayer then
		return {}
	end

	local refs = {}
	for k,v in pairs(PluginMapLayer.backgroundAssets or {}) do
		local M = self:getFileRefResources(v)
		G_Helper.getTableStringValue(refs, M)
	end

	for k,v in pairs(PluginMapLayer.foregroundAssets or {}) do
		local M = self:getFileRefResources(v)
		G_Helper.getTableStringValue(refs, M)
	end

	local M = self:getFileRefResources(PluginMapLayer.gameLayerAsset)
	G_Helper.getTableStringValue(refs, M)

	return refs
end

function PluginRefResources:getFileRefResources(filename)
	return _MyG.Functions:getFileRefResources(filename)
end

return PluginRefResources
