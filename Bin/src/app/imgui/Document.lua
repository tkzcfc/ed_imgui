local Document = class("Document")

function Document:ctor(filename)
	self.filename = filename
	self.name = self:getClearName()
	self.dirty = false
	self.isOpen = true
end

function Document:destroy()
end

function Document:onGUI()
end

function Document:onHide()
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

function Document:canClose()
	return true
end

return Document