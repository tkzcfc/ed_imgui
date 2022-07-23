#include "GActorComponent.h"
#include "mugen/GGameDef.h"
#include "GAvatarComponent.h"


NS_G_BEGIN


GActorComponent::GActorComponent()
	: m_curSkill(NULL)
	, m_status(G_KEY_NONE)
{
	m_nextSkillId = INVALID_SKILL_ID;
	m_defaultSkillId = INVALID_SKILL_ID;
	m_orientation = GActorOrientation::RIGHT;

	lastKeyDown = curKeyDown = G_KEY_NONE;
}

GActorComponent::~GActorComponent()
{
	clearSkill();
}

/// GObject
void GActorComponent::serialize(GByteBuffer& byteBuffer)
{
	GComponent::serialize(byteBuffer);

	byteBuffer.writeInt32(m_defaultSkillId);
	byteBuffer.writeInt32(m_skills.size());

	for (auto it : m_skills)
	{
		it->serialize(byteBuffer);
	}
}

bool GActorComponent::deserialize(GByteBuffer& byteBuffer)
{
	do
	{
		G_BREAK_IF(!GComponent::deserialize(byteBuffer));

		G_BREAK_IF(!byteBuffer.getInt32(m_defaultSkillId));

		int32_t count = 0;
		G_BREAK_IF(!byteBuffer.getInt32(count));

		bool bRet = true;
		for (auto i = 0; i < count; ++i)
		{
			auto skill = new  GSkill();
			if (!skill->deserialize(byteBuffer))
			{
				delete skill;
				bRet = false;
				clearSkill();
				break;
			}
			addSkill(skill);
		}

		return bRet;
	} while (false);
	return false;
}

// GActionDelegate
void GActorComponent::onPlayAnimation(const std::string& name, int32_t frame)
{
	auto avatarComponent = G_GetComponent(this, GAvatarComponent);
	avatarComponent->playAnimation(name, frame);
}

void GActorComponent::clearSkill()
{
	for (auto it : m_skills)
	{
		delete it;
	}
	m_skills.clear();
}

void GActorComponent::addSkill(GSkill* skill)
{
#if G_DEBUG
	G_ASSERT(skill->getId() >= 0);
	for (auto& it : m_skills)
	{
		G_ASSERT(it->getId() != skill->getId());
	}
#endif

	skill->setActorComponent(this);
	skill->setActionDelegate(this);
	m_skills.push_back(skill);
}

void GActorComponent::onUpdate()
{
	auto avatarComponent = G_GetComponent(this, GAvatarComponent);
	this->transform.p = avatarComponent->getRenderPos();

	m_flags = 0;

	if (m_curSkill == NULL || m_curSkill->step())
	{
		m_curSkill = NULL;

		auto runId = m_defaultSkillId;

		if (m_nextSkillId != INVALID_SKILL_ID)
		{
			runId = m_nextSkillId;
			m_nextSkillId = INVALID_SKILL_ID;
		}

		doSkillEx(runId);
	}
}

void GActorComponent::doSkillEx(int32_t id)
{
	auto pSkill = getSkill(id);
	if (m_curSkill != pSkill)
	{
		m_curSkill = pSkill;
		m_curSkill->reset();
	}
}

GSkill* GActorComponent::getSkill(int32_t id)
{
	for (auto it : m_skills)
	{
		if (it->getId() == id)
		{
			return it;
		}
	}
	G_ASSERT(0);
	return NULL;
}

void GActorComponent::doSkill(int32_t id)
{
	if (m_curSkill)
	{
		m_curSkill->interrupt(GInterruptType::PROMPTLY);
	}
	m_nextSkillId = id;
}

// 按键按下
void GActorComponent::onKeyDown(G_BIT_TYPE key)
{
	switch (key)
	{
	case G_KEY_MOVE_LEFT:
	{
		if (G_BIT_NO_EQUAL(m_flags, Flag_Lock_Orientation))
		{
			m_orientation = GActorOrientation::LEFT;
		}
	}break;
	case G_KEY_MOVE_RIGHT:
	{
		if (G_BIT_NO_EQUAL(m_flags, Flag_Lock_Orientation))
		{
			m_orientation = GActorOrientation::RIGHT;
		}
	}break;
	default:
		break;
	}
}

// 按键持续按下
void GActorComponent::onKeepPress(G_BIT_TYPE key)
{}

// 按键抬起
void GActorComponent::onKeyUp(G_BIT_TYPE key)
{}

// 判断按键是否按下
bool GActorComponent::isKeyDown(G_BIT_TYPE key)
{
	return G_BIT_EQUAL(curKeyDown, key);
}

NS_G_END
