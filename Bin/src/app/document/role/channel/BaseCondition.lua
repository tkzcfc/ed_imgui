-- @Author : fc
-- @Date   : 2022-1-30 16:51:03
-- @remark : 通道条件基类

local BaseCondition = class("BaseCondition")

-- 类型名称
BaseCondition.NameLang = ""
-- 类型
BaseCondition.Type = -1

-- @interface
-- @brief 创建新的条件
function BaseCondition:newCondition(cb)
    asset(0)
end

-- @interface
-- @brief 
function BaseCondition:onGUI_ConditionInfo(curCondition, onChangeChannelPreCB, roleSkillContext)
end

return BaseCondition