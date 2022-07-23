-- @Author: fangcheng
-- @Date:   2020-04-25 21:14:05
-- @Description: 编辑器逻辑根节点

local BaseElement = import(".BaseElement")
local EdRootNodeElement = class("EdRootNodeElement", BaseElement)

EdRootNodeElement.type = "LogicRootNode"


function EdRootNodeElement:ctor(context)
	EdRootNodeElement.super.ctor(self, context)

	self:setRenderNode(cc.Node:create())
end

function EdRootNodeElement:setRenderNode(renderNode)
	assert(self.renderNode == nil, "renderNode already exist")
	self.renderNode = renderNode
	self.renderNode.element = self
end

return EdRootNodeElement