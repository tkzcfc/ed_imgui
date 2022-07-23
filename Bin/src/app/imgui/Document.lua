local Document = class("Document")

function Document:ctor(filename)
	self.filename = filename
	self.name = self:getClearName()
	self.dirty = false
	self.isOpen = true
end

function Document:destroy()
end

function Document:dataDirty()
	self.dirty = true
end

function Document:isDirty()
	return self.dirty
end

function Document:onGUI()
	if not self.__isVisibleTag then
		self.__isVisibleTag = true
		self:onShow()
	end
end

function Document:onHide()
	self.__isVisibleTag = false
end

function Document:onShow()
end

function Document:isVisible()
	return self.__isVisibleTag
end

function Document:save()
	return true
end

function Document:canRemove()
	return true
end

function Document:getClearName()
	-- return string.match(self.filename, "(%w+%.*%w*)$")
	return self.filename
end

function Document:getFullName()
	return self.filename
end

function Document:canClose()
	return true
end

return Document