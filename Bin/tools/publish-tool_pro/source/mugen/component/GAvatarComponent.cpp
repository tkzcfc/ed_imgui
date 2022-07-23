#include "GAvatarComponent.h"
#include "GRigidBodyComponent.h"
#include "GStaticDataComponent.h"
#include "mugen/base/GEntity.h"

#if RUNTIME_IN_COOCS
#include "mugen/logic/GGameWorld.h"
#endif

NS_G_BEGIN

// 获取动画名称
static std::string getArmatureName(std::string armatureFile)
{
	auto pos = armatureFile.find_last_of('/');
	if (pos == std::string::npos)
	{
		return "";
	}

	auto str = armatureFile.substr(pos + 1);
	str = str.substr(0, str.find_first_of('.'));
	return str;
}

GAvatarComponent::GAvatarComponent()
{
#if RUNTIME_IN_COOCS
	m_actorRender = NULL;
	m_rootNode = NULL;
#endif
}

GAvatarComponent::~GAvatarComponent()
{
}

void GAvatarComponent::onAdd()
{
#if RUNTIME_IN_COOCS
	m_rootNode = cocos2d::Node::create();
	m_rootNode->setScheduler(GGameWorld::getInstance()->getScheduler());
	GGameWorld::getInstance()->getMapLayer()->getActorNode()->addChild(m_rootNode);

	// 获取静态数据组件
	auto pStaticDataCom = G_GetComponent(this, GStaticDataComponent);
	cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(pStaticDataCom->armatureFile);

	// 创建动画对象
	m_actorRender = cocostudio::Armature::create();
	m_actorRender->setScheduler(GGameWorld::getInstance()->getScheduler());
	m_actorRender->init(getArmatureName(pStaticDataCom->armatureFile));
	m_rootNode->addChild(m_actorRender);
#endif
}

void GAvatarComponent::playAnimation(const std::string& name, int32_t frame)
{
#if RUNTIME_IN_COOCS
	auto animation = m_actorRender->getAnimation();
	animation->play(name, -1, 0);
	if (frame > 0)
	{
		animation->gotoAndPlay(frame);
	}
#endif
}

void GAvatarComponent::setPosition(const fixedPoint& posx, const fixedPoint& posy)
{
	auto rigidBodyComponent = G_GetComponent(this, GRigidBodyComponent);
	auto pStaticDataCom = G_GetComponent(this, GStaticDataComponent);

	auto& rigidPos = rigidBodyComponent->position;
	auto& size = rigidBodyComponent->size;

	fixedPoint ratio = PHYSICS_PIXEL_TO_METER;
	fixedPoint halfRatio = ratio * 0.5f;

	// x
	rigidPos.x = (posx - (size.x * halfRatio)) / ratio;

	// y
	auto jumpHeight = rigidPos.y * ratio;
	rigidPos.z = (posy - size.z * halfRatio - jumpHeight) / ratio;

	m_renderPos.x = posx;
	m_renderPos.y = posy + jumpHeight;
	
#if RUNTIME_IN_COOCS
	auto rx = m_renderPos.x + pStaticDataCom->offset.x;
	auto ry = m_renderPos.y + pStaticDataCom->offset.y;
	m_actorRender->setPosition(rx.to_float(), ry.to_float());
#endif
}

void GAvatarComponent::onUpdate()
{
	auto rigidBodyComponent = G_GetComponent(this, GRigidBodyComponent);
	auto pStaticDataCom = G_GetComponent(this, GStaticDataComponent);

	auto& rigidPos = rigidBodyComponent->position;
	auto& size = rigidBodyComponent->size;

	fixedPoint ratio = PHYSICS_PIXEL_TO_METER;
	fixedPoint halfRatio = ratio * 0.5f;

	auto x = rigidPos.x * ratio + size.x * halfRatio;
	auto jumpHeight = rigidPos.y * ratio;
	auto z = rigidPos.z* ratio + size.z * halfRatio;

	// 最终渲染坐标
	m_renderPos.x = x;
	m_renderPos.y = jumpHeight + z;

#if RUNTIME_IN_COOCS
	auto rx = m_renderPos.x + pStaticDataCom->offset.x;
	auto ry = m_renderPos.y + pStaticDataCom->offset.y;
	m_actorRender->setPosition(rx.to_float(), ry.to_float());
#endif
}

NS_G_END

