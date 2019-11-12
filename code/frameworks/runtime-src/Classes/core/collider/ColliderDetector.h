#pragma once

#include <vector>
#include "ColliderBody.h"

class ColliderDetector
{
public:
	ColliderDetector();
	~ColliderDetector();

	void addColliderBody(ColliderBody* InBody);

	void removeColliderBody(ColliderBody* InBody);

	const std::vector<ColliderBody*>& getColliderBodyList();

	void clear();

	inline int getColliderBodyCount() { return (int)m_colliderBodyList.size(); }

	inline ColliderBody* getColliderBodyByIndex(int InIndex) { return m_colliderBodyList[InIndex]; }

private:
	std::vector<ColliderBody*> m_colliderBodyList;
};
