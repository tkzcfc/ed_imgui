-- @Author: fangcheng
-- @URL: github.com/tkzcfc
-- @Date:   2020-04-15 22:07:43
-- @Last Modified by:   fangcheng
-- @Last Modified time: 2020-05-07 22:16:50
-- @Description: 元素工厂

local ElementFactory = class("ElementFactory")

function ElementFactory:ctor()
	self.eleGenFunc = {}
end

-- @brief 注册元素创建方法
function ElementFactory:register(name, genFunc)
	self.eleGenFunc[name] = genFunc
end

-- @brief 创建元素
function ElementFactory:spawn(name, data, context)
	local genFunc = self.eleGenFunc[name]
	if genFunc == nil then
		logE("Unknown elements", name)
		return
	end
	return genFunc(data, context)
end

return ElementFactory
