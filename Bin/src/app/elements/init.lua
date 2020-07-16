-- @Author: fangcheng
-- @URL: github.com/tkzcfc
-- @Date:   2020-04-15 22:12:07
-- @Last Modified by:   fangcheng
-- @Last Modified time: 2020-05-30 22:11:49
-- @Description: 

local BaseElement = import(".BaseElement")
local ElementFactory = import(".ElementFactory")


local factory = ElementFactory.new()
_MyG.ElementFactory = factory

-- @brief 注册元素
local function reg_ele(ele)
	factory:register(ele.type, function(data, context)
		local o = ele.new(context)
		if o:deserialize(data) then
			return o
		else
			o:onDestroy()
			
			logE(format_lua_value(data))
			logE("deserialize fail")
		end
	end)
end

reg_ele(import(".NodeElement"))
reg_ele(import(".SpriteElement"))
reg_ele(import(".ImageElement"))
reg_ele(import(".EdRootNodeElement"))
reg_ele(import(".CocoStudioElement"))
reg_ele(import(".WidgetElement"))
reg_ele(import(".LayerElement"))


