local EditContext = require("app.document.EditContext")

local LayerEditContext = class("LayerEditContext", EditContext)

function LayerEditContext:ctor(name, fullPath)
	LayerEditContext.super.ctor(self, name, fullPath)
end

function LayerEditContext:onShow()
	LayerEditContext.super.onShow(self)

	_MyG.MainScene.NodeContent.canDoMoveOperationHook = function()
		-- 用于准确计算box
		print("不允许添加子节点，请在widget文件中添加复杂节点")
		return false
	end
end

function LayerEditContext:onDragAssetFnihshFunc(ext, resPath, resType, pos)
	LayerEditContext.super.onDragAssetFnihshFunc(self, ext, resPath, resType, pos)
	if ext == "widget" then
		self:createWidget(resPath, resType, pos)
	end
end

-- 检测含有碰撞数据节点的父节点是否改变了影响碰撞数据计算的 旋转 缩放等属性
function LayerEditContext:collisionDataPreCheck()

	local function checkEx(curNode, endNode, beginNode)
		local p = curNode:getParent()
		if p == endNode then
			return true
		end

		if p:getRotation() ~= 0 then
			logE(string.format("保存失败，节点%q子节点(%q)中含有碰撞数据", p:getName(), beginNode:getName()))
			logE(string.format("节点%q修改了rotation属性，会影响碰撞数据计算", p:getName()))
			return false
		end

		if p:getScaleX() ~= 1.0 then
			logE(string.format("保存失败，节点%q子节点(%q)中含有碰撞数据", p:getName(), beginNode:getName()))
			logE(string.format("节点%q修改了scalex属性，会影响碰撞数据计算", p:getName()))
			return false
		end

		if p:getScaleY() ~= 1.0 then
			logE(string.format("保存失败，节点%q子节点(%q)中含有碰撞数据", p:getName(), beginNode:getName()))
			logE(string.format("节点%q修改了scaley属性，会影响碰撞数据计算", p:getName()))
			return false
		end

		return checkEx(p, endNode, beginNode)
	end

	local needCheck = false

	for k,v in pairs(self.cells) do
		needCheck = false
		if v.renderNode and v.bgCellData then

			if v.bgCellData.rect_data and #v.bgCellData.rect_data > 0 then
				needCheck = true
			end
			if v.bgCellData.line_data and #v.bgCellData.line_data > 0 then
				needCheck = true
			end
			if v.bgCellData.child_rect_data and #v.bgCellData.child_rect_data > 0 then
				needCheck = true
			end
			if v.bgCellData.child_line_data and #v.bgCellData.child_line_data > 0 then
				needCheck = true
			end

			if needCheck then
				if not checkEx(v.renderNode, self.rootNode, v.renderNode) then
					return
				end
			end
		end
	end

	return true
end

function LayerEditContext:save()
	if not self:collisionDataPreCheck() then
		return
	end

	return LayerEditContext.super.save(self)
end

return LayerEditContext