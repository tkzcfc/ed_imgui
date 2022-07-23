-- @Author: fangcheng
-- @Date:   2021-07-25 14:44:10
-- @remark: 主题管理

local themeCfg = {
    {name = "Default"       , call = function() Theme:styleDefault() end},
    {name = "DarkAndPurple" , call = function() Theme:styleDarkAndPurple() end},
    {name = "Blue"          , call = function() Theme:styleBlue() end},
    {name = "Red"           , call = function() Theme:styleRed() end},
    {name = "Brown"         , call = function() Theme:styleBrown() end},
    {name = "Aqua"          , call = function() Theme:styleAqua() end},
    {name = "Black"         , call = function() Theme:styleBlack() end},
    {name = "Purple"        , call = function() Theme:stylePurple() end},
    {name = "BlackOrange"   , call = function() Theme:styleBlackOrange() end},
    {name = "Cherry"        , call = function() Theme:styleCherry() end},
    {name = "Gold"          , call = function() Theme:styleGold() end},
    {name = "Yellow"        , call = function() Theme:styleYellow() end},
    {name = "Gray"          , call = function() Theme:styleGray() end},
    {name = "Dark"          , call = function() Theme:styleDark() end},
    {name = "Green"         , call = function() Theme:styleGreen() end},
}

local themeNames = {}
for k,cfg in pairs(themeCfg) do
    themeNames[k] = cfg.name
end



local ThemeManager = class("ThemeManager", import(".BaseManager"))

function ThemeManager:getNames()
    return themeNames
end

function ThemeManager:isSelect(name)
    return self.curThemeName == name
end

function ThemeManager:select(name)
    for k, cfg in pairs(themeCfg) do
        if cfg.name == name then
            cfg.call()

            self.curThemeName = name
            self:saveTheme()
            break
        end
    end
end

function ThemeManager:contain(name)
    for k,v in pairs(themeNames) do
        if v == name then return true end
    end
end

function ThemeManager:readTheme()
    self.curThemeName = _MyG.SysSetManager:getProperty("curThemeName")

    if not self:contain(self.curThemeName) then
        self.curThemeName = themeNames[#themeNames]
    end
    
    self:select(self.curThemeName)
end

function ThemeManager:saveTheme()
    _MyG.SysSetManager:setProperty("curThemeName", self.curThemeName)
    _MyG.SysSetManager:flush()
end

return ThemeManager

