local Lang = {}

function Lang:loadText(textRoot, language)
	if self[language] then
		return
	end

	self[language] = require(string.format("%s.%s.Text", textRoot, language))
end

return Lang