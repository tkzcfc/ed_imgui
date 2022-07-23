#include "LineValue.h"


LineValue::LineValue(float _x1, float _y1, float _x2, float _y2)
{
	set(_x1, _y1, _x2, _y2);
}

LineValue::LineValue()
{
	x1 = y1 = x2 = y2 = 0.0f;
}

void LineValue::set(float _x1, float _y1, float _x2, float _y2)
{
	x1 = _x1;
	y1 = _y1;
	x2 = _x2;
	y2 = _y2;
}