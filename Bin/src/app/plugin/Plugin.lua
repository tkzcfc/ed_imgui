-- @Author: fangcheng
-- @URL: github.com/tkzcfc
-- @Date:   2020-05-05 16:23:42
-- @Last Modified by:   fangcheng
-- @Last Modified time: 2020-05-30 21:34:24
-- @Description: 插件

local Plugin = class("Plugin")

Plugin.isPluginType = true

function Plugin:ctor()
	self.onUserdataValueChange = function()
		self:onAttributeChange("change_userdata")
	end
end

function Plugin:attach(edContext)
	self.context = edContext
end

function Plugin:detach()
end

function Plugin:onAttributeContent_GUI()
	if ImGui.CollapsingHeader(self.__cname, ImGuiTreeNodeFlags_DefaultOpen) then
		self:onAttributeGUI()
	end
end

function Plugin:onAttributeGUI()
	self:onGUI_UserData()
end

function Plugin:onGUI_UserData()
	ImGui.PushID(self.__cname)
	if ImGui.TreeNode(STR("EA_USER_DATA")) then
		_MyG.Functions:onGUI_UserData(self, self.onUserdataValueChange)
		ImGui.TreePop()
	end
	ImGui.PopID()
end

-- @brief 是否阻断元素的Touch事件
function Plugin:isBlockEleTouchEvent()
	return false
end

function Plugin:serialize()
	local output = {}
	output[self.__cname] = self:doSerialize()
	return output
end

function Plugin:doSerialize()
	return {
		userdata = self.userdata
	}
end

function Plugin:deserialize(data)
	if not data then
		return true
	end
	
	local curdata = data[self.__cname]
	if curdata then
		return self:doDeserialize(curdata)
	end
	return true
end

function Plugin:doDeserialize(data)
	self.userdata = data.userdata
	return true
end

-- @brief 属性改变时调用
function Plugin:onAttributeChange(attributeName)
	local mem = self:doPartMementoGen(attributeName)
	if mem ~= nil then
		self.context:saveSnapshot(self, true, attributeName, mem)
	else
		self.context:saveSnapshot(self, true, attributeName, self:serialize())
	end
end

function Plugin:doPartMementoGen(attributeName)
	if attributeName == "change_userdata" then
		return self.userdata or {}
	else
		return self:serialize()
	end
end

-- @brief 撤销属性改变
function Plugin:revokeAttributeChange(attributeName, data)
	if attributeName == "change_userdata" then
		self.userdata = data
	else
		return self:deserialize(data)
	end
end

-- @brief 预制体拖拽
function Plugin:onDragPreWidgetDragEnd(typeName, pos)
end

-- @brief 
function Plugin:onEditorDraw()
end

function Plugin:onMouseMove(event)
end

function Plugin:onMouseScroll(event)
end

function Plugin:onMouseDown(event)
end

function Plugin:onMouseUp(event)
end

function Plugin:onTouchBegan(touch, event)
	return false
end

function Plugin:onTouchMoved(touch, event)
end

function Plugin:onTouchEnded(touch, event)
end

function Plugin:onTouchCancelled(touch, event)
end

function Plugin:onKeyBoardDelete()
end

return Plugin
