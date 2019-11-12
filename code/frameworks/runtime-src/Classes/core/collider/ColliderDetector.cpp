#include "ColliderDetector.h"

ColliderDetector::ColliderDetector()
{}

ColliderDetector::~ColliderDetector()
{
	clear();
}

void ColliderDetector::addColliderBody(ColliderBody* InBody)
{
	m_colliderBodyList.push_back(InBody);
}

void ColliderDetector::removeColliderBody(ColliderBody* InBody)
{
	auto it = std::find(m_colliderBodyList.begin(), m_colliderBodyList.end(), InBody);
	if (it != m_colliderBodyList.end())
	{
		delete InBody;
		m_colliderBodyList.erase(it);
	}
}

const std::vector<ColliderBody*>& ColliderDetector::getColliderBodyList()
{
	return m_colliderBodyList;
}

void ColliderDetector::clear()
{
	if (m_colliderBodyList.empty())
		return;
	for (auto& it : m_colliderBodyList)
	{
		delete it;
	}
	m_colliderBodyList.clear();
}
