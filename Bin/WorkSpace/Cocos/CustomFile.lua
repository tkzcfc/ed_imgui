

local Result = {}

function Result.create()
	--Create Node
	local Node=cc.Node:create()
	Node:setName("Node")
	
	-- 自定义节点
	cc.SpriteFrameCache:getInstance():addSpriteFrames("king.plist")

	local frames = display.newFrames("loading_%02d.png", 1, 12, false)
	local animation, sprite = display.newAnimation(frames, 1 / 20)
	sprite:playAnimationForever(animation)
	Node:addChild(sprite)

	local result = {}
	result['root'] = Node
	return result;
end

return Result

