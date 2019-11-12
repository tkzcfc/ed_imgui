local LangManager = class("LangManager")

local Lang = require("commonlib.lang.Lang") 

local LANGUAGE = {}
LANGUAGE.EN = "en"
LANGUAGE.CH = "ch"

local LANG_NAME = {}
LANG_NAME[LANGUAGE.CH] = "简体中文"
LANG_NAME[LANGUAGE.EN] = "English"

LangManager.LANGUAGE = LANGUAGE
LangManager.LANG_NAME = LANG_NAME

local curLanguage

function LangManager:ctor()
end

function LangManager:initWithTextRoot(textRoot, defaultLang)
	self.textRoot = textRoot
	self.initTag = true
	self.firstStartTag = true

	local langValue = cc.UserDefault:getInstance():getStringForKey("lang")
	if langValue == nil or #langValue == 0 then
		if defaultLang then
			langValue = defaultLang
		else
			local lang_code = cc.Application:getInstance():getCurrentLanguage()
			langValue = LangManager.getLangByCode(lang_code)
		end
	else
		self.firstStartTag = false
	end
	
	self:setLang(langValue)
end

function LangManager:getLang()
	return self.language
end

function LangManager:setLang(lang)
	assert(self.initTag)
	
	self.language = lang
	curLanguage = lang
	Lang:loadText(self.textRoot, lang)
	cc.UserDefault:getInstance():setStringForKey("lang", lang)
end

function LangManager:isFirstStart()
	return self.firstStartTag
end

function LangManager.getLangByCode(lang_code)
    local lang_str = "ch"
    -- if lang_code == cc.LANGUAGE_ENGLISH then
    --     lang_str = "en"
    -- elseif lang_code == cc.LANGUAGE_CHINESE then
    --     lang_str = "ch"
    -- end
    return lang_str
end

function LangManager:getLanguageName()
	return self.LANG_NAME[self.language]
end

function LangManager:getLangByName(languageName)
	for k, v in pairs(self.LANG_NAME) do
		if v == languageName then
			return k
		end
	end
	error(languageName .. "不存在")
end

function LangManager:setLangByName(languageName)
	for k, v in pairs(self.LANG_NAME) do
		if v == languageName then
			self:setLang(k)
			return
		end
	end
	error(languageName .. "不存在")
end

------------------------------------------------------------------------------------------------

if G_MAC.DEBUG then
	STR = function(key)
		assert(curLanguage)
	
		local t = Lang[curLanguage]
		if t == nil then
			print(string.format("警告：语言%q未定义", curLanguage))
			return key
		end
		if t[key] then
			return t[key]
		end
		print(string.format("警告：Lang文件中不存在含有%q的字段", key))
		return key
	end
else
	STR = function(key)
		local t = Lang[curLanguage]
		if t == nil then
			return key
		end
		if t[key] then
			return t[key]
		end
		return key
	end
end

return LangManager
