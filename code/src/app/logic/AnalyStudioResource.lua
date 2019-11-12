local function AnalyResource(str, regEx, out)
	local func = string.gmatch(str, regEx)
	local tmp

	repeat
	tmp = func()
	if tmp then
		table.insert(out, tmp)
	end
	until(tmp == nil)
end



local M = {}

function M:getReferenceResources(filepath)
	self.cache = self.cache or {}
	if not self.cache[filepath] then
		self.cache[filepath] = self:doAnalyResource(filepath)
	end
	return self.cache[filepath]
end

function M:doAnalyResource(filepath)
	local content = cc.FileUtils:getInstance():getStringFromFile(filepath)
	if content == nil or content == "" then
		return ""
	end

	local out = {}
	-- Image_BG:loadTexture("fangkuang222.png",0)
	AnalyResource(content, "loadTexture%(%\"+(.-)%\"+,0", out)

	-- cc.SpriteFrameCache:getInstance():addSpriteFrames("Res/xx.plist")
	AnalyResource(content, "cc.SpriteFrameCache:getInstance%(%):addSpriteFrames%(\"(.-)\"%)", out)

	-- cc.Sprite:create("disk.png")
	AnalyResource(content, "cc.Sprite:create%(\"(.-)\"%)", out)

	local tmp = out
	out = {}
	local valueBoolMap = {}

	for k,v in pairs(tmp) do
		if not valueBoolMap[v] then
			valueBoolMap[v] = true
			table.insert(out, v)
		end
	end

	return out
end

return M


--[[
匹配模式
字符类：
字符类 用于表示一个字符集合。 下列组合可用于字符类：

**x: *（这里 x 不能是 魔法字符 ^$()%.[]+-? 中的一员） 表示字符 x 自身。

**.: **（一个点）可表示任何字符。

**%a: **表示任何字母。

**%c: **表示任何控制字符。

**%d: **表示任何数字。

**%g: **表示任何除空白符外的可打印字符。

**%l: **表示所有小写字母。

**%p: **表示所有标点符号。

**%s: **表示所有空白字符。

**%u: **表示所有大写字母。

**%w: **表示所有字母及数字。

**%x: **表示所有 16 进制数字符号。

**%x: **（这里的 x 是任意非字母或数字的字符） 表示字符 x。 这是对魔法字符转义的标准方法。 所有非字母或数字的字符 （包括所有标点，也包括非魔法字符） 都可以用前置一个 '%' 放在模式串中表示自身。

**[set]: **表示 set　中所有字符的联合。 可以以 '-' 连接，升序书写范围两端的字符来表示一个范围的字符集。 上面提到的 %x 形式也可以在 set 中使用 表示其中的一个元素。 其它出现在 set 中的字符则代表它们自己。 例如，[%w_] （或 [_%w]） 表示所有的字母数字加下划线）， [0-7] 表示 8 进制数字， [0-7%l%-]　表示 8 进制数字加小写字母与 '-' 字符。

交叉使用类和范围的行为未定义。 因此，像 [%a-z] 或 [a-%%] 这样的模式串没有意义。

**[^set]: **表示 set 的补集， 其中 set 如上面的解释。

所有单个字母表示的类别（%a，%c，等）， 若将其字母改为大写，均表示对应的补集。 例如，%S 表示所有非空格的字符。

如何定义字母、空格、或是其他字符组取决于当前的区域设置。 特别注意：[a-z]　未必等价于 %l 。

模式条目：
模式条目 可以是

单个字符类匹配该类别中任意单个字符；
单个字符类跟一个 ''， 将匹配零或多个该类的字符。 这个条目总是匹配尽可能长的串*；
单个字符类跟一个 '+'， 将匹配一或更多个该类的字符。 这个条目总是匹配尽可能长的串；
单个字符类跟一个 '-'， 将匹配零或更多个该类的字符。 和 '' 不同， 这个条目总是匹配尽可能短的串*；
单个字符类跟一个 '?'， 将匹配零或一个该类的字符。 只要有可能，它会匹配一个；
%n， 这里的 n 可以从 1 到 9； 这个条目匹配一个等于 n 号捕获物（后面有描述）的子串。
%b_xy_， 这里的 x 和 y 是两个明确的字符； 这个条目匹配以 x 开始 y 结束， 且其中 x 和 y 保持 平衡 的字符串。 意思是，如果从左到右读这个字符串，对每次读到一个 x 就 +1 ，读到一个 y 就 -1， 最终结束处的那个y 是第一个记数到 0 的 y。 举个例子，条目 %b() 可以匹配到括号平衡的表达式。
%f[set]， 指 边境模式； 这个条目会匹配到一个位于 set 内某个字符之前的一个空串， 且这个位置的前一个字符不属于 set 。 集合 set 的含义如前面所述。 匹配出的那个空串之开始和结束点的计算就看成该处有个字符 '\0' 一样。
模式：
模式 指一个模式条目的序列。 在模式最前面加上符号 '^' 将锚定从字符串的开始处做匹配。 在模式最后面加上符号 '$' 将使匹配过程锚定到字符串的结尾。 如果 '^' 和 '$' 出现在其它位置，它们均没有特殊含义，只表示自身。
]]
