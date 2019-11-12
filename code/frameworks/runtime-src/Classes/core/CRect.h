#pragma once

#include "cocos2d.h"
#include "Math.h"
#include "type/Vec2Value.h"

using namespace cocos2d;

class CRect
{
public:

	CRect();

	void setAnchorPoint(float x, float y);

	const Vec2& getAnchorPoint();

	void setContentSize(float w, float h);

	const Vec2& getContentSize();

	void setPoint(float x, float y);

	const Vec2& getPoint();

	void setScale(float scalex, float scaley);

	const Vec2& getScale();

	void setRotation(float _angle);

	float getRotation();

	// ÇÐ±ä
	void setSkewX(float skewx);

	void setSkewY(float skewy);

	const Vec2& getSkew();

	void apply();

	const Vec2& getVertexByIndex(int index);

	inline int getVertexCount() { return 4; }

	void debugDraw(DrawNode* pDrawNode);

	void setVisible(bool value);

	bool isVisible();

	void setColor(unsigned int color);

	unsigned int getColor() { return m_color_Uint; }

private:
	Vec2 MatrixMutVec2(const Mat4& mat, const Vec2& v);

	void getBaseVertex(Vec2* pointArr);

protected:
	Vec2 vertex_vec2_value[4];
	Vec2 vertex[4];
	Vec2 scale;
	Vec2 skew;
	float angle;
	float angle_ex;
	bool isdirty;

	bool m_isVisible;

	Vec2 origin;
	Vec2 size;
	Vec2 anchorPoint;

	Color4F m_color;
	unsigned int m_color_Uint;
};