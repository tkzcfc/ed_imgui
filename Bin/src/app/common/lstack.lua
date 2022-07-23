-- @Author : fangcheng
-- @Date   : 2020-05-13 10:58:05
-- @remark : 带有本地缓存的stack

-- require("lfsex")
local cjson = require("cjson")


local FileUtilsInstance = cc.FileUtils:getInstance()

local lstack = {}

lstack.__index = lstack
-- 单个文件最大存储数量(分片大小)
lstack.fragmentSize = 100
-- 缓存阈值
lstack.cacheSize = 50

function lstack.new(...)
	local t = setmetatable({}, lstack)
	t:ctor(...)
	return t
end

function lstack:ctor(name, enable, cachadir)
	if enable == nil then
		enable = true
	end

	self.name = name
	-- 是否启用本地缓存
	self.enableLocal = enable
	-- 缓存目录
	self.cachadir = cachadir or ".cache"
	self.cachadir = os.fmtpath(self.cachadir, true)

	-- 缓存文件名称
	if self.name == nil or self.name == "" then
		self.name = tostring(self)
	end

	self:clear()
end

-- @brief 数据入栈
function lstack:push(data)
	self.curOpIdx = self.curOpIdx + 1
	self.stack[#self.stack + 1] = data
	self:writeLocal()
end

-- @brief 返回最后一个数据,并且将其弹出栈
function lstack:pop()
	local idx = self.curOpIdx - 1
	if idx < 0 then
		return
	end

	self:readLocal()
	self.curOpIdx = idx

	-- 读取本地缓存失败
	local size = #self.stack
	if size <= 0 then
		self:clear()
		return
	end

	local data = self.stack[size]
	self.stack[size] = nil

	return data
end

-- @brief 清除所有
function lstack:clear()
	self.curOpIdx = 0
	self.stack = {}
	local dirname = self:cacheDir()

	if FileUtilsInstance:isDirectoryExist(dirname) then
		FileUtilsInstance:removeDirectory(dirname)
	end
end

-- @brief 写入本地文件
function lstack:writeLocal()
	if not self.enableLocal then
		return
	end

	if #self.stack - self.cacheSize >= self.fragmentSize then
		local idx = self.curOpIdx - self.cacheSize
		idx = math.floor(idx / self.fragmentSize)

		local stack1 = {}
		local stack2 = {}

		for k,v in pairs(self.stack) do
			if k <= self.fragmentSize then
				stack1[#stack1 + 1] = v
			else
				stack2[#stack2 + 1] = v
			end
		end

		if os.writefile(self:cacheFile(idx), cjson.encode(stack1)) then
			self.stack = stack2
		else
			self.enableLocal = false
		end
	end
end

-- @brief 读取本地文件
function lstack:readLocal()
	if #self.stack <= 0 then
		local idx = self.curOpIdx
		idx = math.floor(idx / self.fragmentSize)

		local content = os.readfile(self:cacheFile(idx))
		self.stack = cjson.decode(content)
	end
end

function lstack:cacheDir()
	return self.cachadir .. self.name .. "/"
end

function lstack:cacheFile(idx)
	return self:cacheDir() .. idx .. ".cache"
end

return lstack


-- local m = lstack.new("test1", true)

-- m.fragmentSize = 10
-- m.cacheSize = 5

-- local loopCount = 30
-- for i=1,loopCount do
-- 	m:push({index = i, data = {age = i + 1}})
-- end

-- for i=1,loopCount do
-- 	local data = m:pop()
-- 	local idx = loopCount - i + 1
-- 	if data.index ~= idx or data.data.age ~= idx + 1 then
-- 		print("pop", data.index, data.data.name)
-- 	end
-- end
