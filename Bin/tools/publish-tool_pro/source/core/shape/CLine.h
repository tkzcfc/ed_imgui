﻿#pragma once


#include "../Cocos.h"
#include "LineValue.h"

class CLine
{
public:
	CLine();

	~CLine();
	
	void setPointDataByIndex(int index, float x, float y);

	int getPointCount();

	void setPointCount(int count);

	void removePointByIndex(int index);

	int getNormalCount();

	std::vector<Vec2> getAllNormal();

	std::vector<Vec2> getAllPoint();

	Vec2 getLastPoint();

	Vec2 getPointByIndex(int index);

	void apply();

	void setNormalLeft(bool isLeft);

	bool isLeftNormal();

	void setNormalScale(float scale);

	//void debugDraw(DrawNode* pDrawNode, bool forcedDisplay = false);

	void setAlpha(float alpha);

	void setLineCorlor(unsigned int color);

	void setNormalColor(unsigned int color);

	unsigned int getLineColor() { return m_lineColor_Uint; }

	unsigned int getNormalColor() { return m_normalColor_Uint; }

	void setVisible(bool value);

	bool isVisible();

protected:
	std::vector<Vec2> m_pointArr;
	bool m_isdirty;

	LineValue* m_normalLines;
	Vec2* m_normals;
	int m_normalCount;

	Color4F m_lineColor;
	Color4F m_normalColor;

	unsigned int m_lineColor_Uint;
	unsigned int m_normalColor_Uint;

	bool m_isLeftNormal;
	float m_normalScale;

	bool m_isVisible;
	float m_alpha;
};