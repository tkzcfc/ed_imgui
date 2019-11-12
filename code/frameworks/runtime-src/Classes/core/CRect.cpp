#include "CRect.h"
#include "imgui.h"

#define CRECT_VEC2_MUL_MAT(v, mat) 	v[0] = MatrixMutVec2(mat, v[0]); \
									v[1] = MatrixMutVec2(mat, v[1]); \
									v[2] = MatrixMutVec2(mat, v[2]); \
									v[3] = MatrixMutVec2(mat, v[3]); 

CRect::CRect()
{
	anchorPoint = Vec2(0.5f, 0.5f);
	scale = Vec2(1.0f, 1.0f);
	isdirty = true;
	angle = angle_ex = 0.0f;
	
	setColor(IM_COL32(255, 0, 0, 255));
	setVisible(true);
}

void CRect::setAnchorPoint(float x, float y)
{
	if (anchorPoint.x == x && anchorPoint.y == y)
		return;
	anchorPoint.x = x;
	anchorPoint.y = y;
	isdirty = true;
}

const Vec2& CRect::getAnchorPoint()
{
	return anchorPoint;
}

void CRect::setContentSize(float w, float h)
{
	if (size.x == w && size.y == h)
		return;
	size.x = w;
	size.y = h;
	isdirty = true;
}

const Vec2& CRect::getContentSize()
{
	return size;
}

void CRect::setPoint(float x, float y)
{
	if (origin.x == x && origin.y == y)
		return;
	origin.x = x;
	origin.y = y;
	isdirty = true;
}

const Vec2& CRect::getPoint()
{
	return origin;
}

void CRect::setScale(float scalex, float scaley)
{
	if (scale.x == scalex && scale.y == scaley)
		return;
	scale.x = scalex;
	scale.y = scaley;
	isdirty = true;
}

const Vec2& CRect::getScale()
{
	return scale;
}

void CRect::setRotation(float _angle)
{
	angle_ex = _angle;
	angle = MATH_DEG_TO_RAD(-_angle);
	isdirty = true;
}

float CRect::getRotation()
{
	return angle_ex;
}

// ÇÐ±ä
void CRect::setSkewX(float skewx)
{
	if (skew.x == skewx)
		return;
	skew.x = skewx;
	isdirty = true;
}

void CRect::setSkewY(float skewy)
{
	if (skew.y == skewy)
		return;
	skew.y = skewy;
	isdirty = true;
}

const Vec2& CRect::getSkew()
{
	return skew;
}

void CRect::apply()
{
	if (!isdirty)
		return;
	isdirty = false;
	getBaseVertex(vertex);

	Mat4 mat;

	Math::CreateTranslation(-origin.x, -origin.y, 0.0f, &mat);
	CRECT_VEC2_MUL_MAT(vertex, mat);

	// scale
	if (scale.x != 1.0f || scale.y != 1.0f)
	{
		Math::CreateScale(scale.x, scale.y, 1.0f, &mat);
		CRECT_VEC2_MUL_MAT(vertex, mat);
	}

	// skew
	bool needsSkewMatrix = (skew.x || skew.y);
	if (needsSkewMatrix)
	{
		Math::CreateSkewXY(skew.x, skew.y, &mat);
		CRECT_VEC2_MUL_MAT(vertex, mat);
	}

	// rotation
	if (angle != 0.0f)
	{
		Math::CreateRotationZ(angle, &mat);
		CRECT_VEC2_MUL_MAT(vertex, mat);
	}

	Math::CreateTranslation(origin.x, origin.y, 0.0f, &mat);
	CRECT_VEC2_MUL_MAT(vertex, mat);

	for (int i = 0; i < 4; ++i)
	{
		vertex_vec2_value[i].x = vertex[i].x;
		vertex_vec2_value[i].y = vertex[i].y;
	}
}

Vec2 CRect::MatrixMutVec2(const Mat4& mat, const Vec2& v)
{
	Vec4 v4(v.x, v.y, 1.0f, 1.0f);
	v4 = mat * v4;
	return Vec2(v4.x, v4.y);
}

void CRect::getBaseVertex(Vec2* pointArr)
{
	Vec2 tmp(size.x * anchorPoint.x, size.y * anchorPoint.y);
	tmp = origin - tmp;

	pointArr[0] = tmp;

	pointArr[1] = tmp;
	pointArr[1].x += size.x;

	pointArr[2] = tmp + size;

	pointArr[3] = tmp;
	pointArr[3].y += size.y;
}


const Vec2& CRect::getVertexByIndex(int index)
{
	CC_ASSERT(index >= 0 && index <= 3);
	apply();
	return vertex_vec2_value[index];
}

void CRect::debugDraw(DrawNode* pDrawNode)
{
	apply();
	if (!m_isVisible || pDrawNode == NULL)
	{
		return;
	}

	static int indexBuffer[][2] = { {0, 1},{ 1, 2 },{ 2, 3 },{ 3, 0 } };

	for (auto i = 0U; i < 4; ++i)
	{
		pDrawNode->drawLine(getVertexByIndex(indexBuffer[i][0]), getVertexByIndex(indexBuffer[i][1]), m_color);
	}
}

void CRect::setVisible(bool value)
{
	m_isVisible = value;
}

bool CRect::isVisible()
{
	return m_isVisible;
}

void CRect::setColor(unsigned int color)
{
	float sc = 1.0f / 255.0f;
	m_color.r = (float)((color >> IM_COL32_R_SHIFT) & 0xFF) * sc;
	m_color.g = (float)((color >> IM_COL32_G_SHIFT) & 0xFF) * sc;
	m_color.b = (float)((color >> IM_COL32_B_SHIFT) & 0xFF) * sc;
	m_color.a = (float)((color >> IM_COL32_A_SHIFT) & 0xFF) * sc;

	m_color_Uint = color;
}
