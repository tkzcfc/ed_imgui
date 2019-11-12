#include "Vec2Value.h"

Vec2Value::Vec2Value(float _x, float _y)
{
	set(_x, _y);
}

Vec2Value::Vec2Value()
{
	x = y = 0.0f;
}

void Vec2Value::set(float _x, float _y)
{
	x = _x;
	y = _y;
}

