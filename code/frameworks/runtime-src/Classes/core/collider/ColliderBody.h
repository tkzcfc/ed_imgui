#pragma once

#include <cocos2d.h>

using namespace cocos2d;

enum ColliderShapeType
{
	CS_POINT,
	CS_LINE,
	CS_TRIANGLE,
	CS_RECT,
	CS_CUSTOM
};

class ColliderBody
{
public:

	inline ColliderShapeType getType() { return m_type; }

protected:
	ColliderShapeType m_type;
};