#include "CLine.h"
#include "imgui.h"

CLine::CLine()
{
	m_alpha = 1.0f;
	m_pointArr.reserve(10);

	m_isdirty = false;
	m_isLeftNormal = false;

	m_normals = NULL;
	m_normalLines = NULL;
	m_normalCount = 0;
	m_normalScale = 10.0f;

	this->setLineCorlor(IM_COL32(255, 0, 0, 255));
	this->setNormalColor(IM_COL32(255, 0, 0, 200));

	setVisible(true);
}

CLine::~CLine()
{
	CC_SAFE_DELETE_ARRAY(m_normalLines);
	CC_SAFE_DELETE_ARRAY(m_normals);
}

int CLine::getPointCount()
{
	return (int)m_pointArr.size();
}

void CLine::setPointCount(int count)
{
	while (m_pointArr.size() > count)
	{
		m_isdirty = true;
		m_pointArr.pop_back();
	}
	while (m_pointArr.size() < count)
	{
		m_isdirty = true;
		m_pointArr.push_back(Vec2::ZERO);
	}
}

void CLine::removePointByIndex(int index)
{
	if (index >= m_pointArr.size())
	{
		assert(0);
		return;
	}
	m_pointArr.erase(m_pointArr.begin() + index);
	m_isdirty = true;
}

void CLine::setPointDataByIndex(int index, float x, float y)
{
	if (index < m_pointArr.size())
	{
		if (!m_isdirty)
		{
			if (fabs(m_pointArr[index].x - x) < 0.00001f && fabs(m_pointArr[index].y - y) < 0.00001f)
			{
				return;
			}
			m_isdirty = true;
		}
		m_pointArr[index].x = x;
		m_pointArr[index].y = y;
	}
	else
	{
		m_isdirty = true;
		m_pointArr.push_back(Vec2(x, y));
	}
}

void CLine::setNormalLeft(bool isLeft)
{
	if (m_isLeftNormal == isLeft)
		return;
	m_isLeftNormal = isLeft;
	m_isdirty = true;
}

bool CLine::isLeftNormal()
{
	return m_isLeftNormal;
}

int CLine::getNormalCount()
{
	apply();
	return m_normalCount;
}

std::vector<Vec2> CLine::getAllNormal()
{
	std::vector<Vec2> vec;
	for (auto i = 0U; i < m_normalCount; ++i)
	{
		vec.push_back(m_normals[i]);
	}
	return vec;
}


std::vector<Vec2> CLine::getAllPoint()
{
	return m_pointArr;
}

Vec2  CLine::getLastPoint()
{
	return m_pointArr.back();
}

Vec2  CLine::getPointByIndex(int index)
{
	return m_pointArr[index];
}

void CLine::setNormalScale(float scale)
{
	m_normalScale = scale;
}

void CLine::debugDraw(DrawNode* pDrawNode, bool forcedDisplay/* = false*/)
{
	apply();

	if (m_pointArr.size() <= 1)
	{
		return;
	}

	if (!forcedDisplay && !isVisible())
	{
		return;
	}

	Color4F lineColor = m_lineColor;
	lineColor.a *= m_alpha;

	for (auto i = 1U; i < m_pointArr.size(); ++i)
	{
		pDrawNode->drawLine(m_pointArr[i - 1], m_pointArr[i], lineColor);
	}

	Color4F normalColor = m_normalColor;
	normalColor.a *= m_alpha;
	for (auto i = 0U; i < m_normalCount; ++i)
	{
		pDrawNode->drawLine(Vec2(m_normalLines[i].x1, m_normalLines[i].y1), Vec2(m_normalLines[i].x2, m_normalLines[i].y2), normalColor);
	}
}

void CLine::setAlpha(float alpha)
{
	m_alpha = alpha;
}

void CLine::setLineCorlor(unsigned int color)
{
	float sc = 1.0f / 255.0f;
	m_lineColor.r = (float)((color >> IM_COL32_R_SHIFT) & 0xFF) * sc;
	m_lineColor.g = (float)((color >> IM_COL32_G_SHIFT) & 0xFF) * sc;
	m_lineColor.b = (float)((color >> IM_COL32_B_SHIFT) & 0xFF) * sc;
	m_lineColor.a = (float)((color >> IM_COL32_A_SHIFT) & 0xFF) * sc;

	m_lineColor_Uint = color;
}

void CLine::setNormalColor(unsigned int color)
{
	float sc = 1.0f / 255.0f;
	m_normalColor.r = (float)((color >> IM_COL32_R_SHIFT) & 0xFF) * sc;
	m_normalColor.g = (float)((color >> IM_COL32_G_SHIFT) & 0xFF) * sc;
	m_normalColor.b = (float)((color >> IM_COL32_B_SHIFT) & 0xFF) * sc;
	m_normalColor.a = (float)((color >> IM_COL32_A_SHIFT) & 0xFF) * sc;

	m_normalColor_Uint = color;
}

void CLine::setVisible(bool value)
{
	m_isVisible = value;
}

bool CLine::isVisible()
{
	return m_isVisible;
}

void CLine::apply()
{
	if (!m_isdirty)
		return;
	m_isdirty = false;

	int preCount = m_normalCount;
	m_normalCount = MAX(m_pointArr.size() - 1, 0);
	if (preCount != m_normalCount)
	{
		CC_SAFE_DELETE_ARRAY(m_normals);
		CC_SAFE_DELETE_ARRAY(m_normalLines);
	}
	if (m_normalCount <= 0)
	{
		return;
	}
	if (m_normalLines == NULL)
	{
		m_normalLines = new LineValue[m_normalCount];
	}
	if (m_normals == NULL)
	{
		m_normals = new Vec2[m_normalCount];
	}

	Vec2 v;
	float halfx, halfy;

	static float line_sin_90 = std::sin(MATH_DEG_TO_RAD(90.0f));
	static float line_cos_90 = std::cos(MATH_DEG_TO_RAD(90.0f));

	float sin90 = m_isLeftNormal ? line_sin_90 : -line_sin_90;
	float cos90 = m_isLeftNormal ? line_cos_90 : -line_cos_90;

	for (size_t i = 1; i < m_pointArr.size(); i++)
	{
		v = m_pointArr[i - 1] - m_pointArr[i];
		v.normalize();
		float tmpx = v.x;
		v.x = v.x * cos90 - v.y * sin90;
		v.y = tmpx * sin90 + v.y * cos90;
		
		m_normals[i - 1].x = v.x;
		m_normals[i - 1].y = v.y;

		v = v * m_normalScale;

		halfx = (m_pointArr[i - 1].x + m_pointArr[i].x) * 0.5f;
		halfy = (m_pointArr[i - 1].y + m_pointArr[i].y) * 0.5f;

		m_normalLines[i - 1].x1 = halfx;
		m_normalLines[i - 1].y1 = halfy;		
		m_normalLines[i - 1].x2 = halfx + v.x;
		m_normalLines[i - 1].y2 = halfy + v.y;
	}
}
