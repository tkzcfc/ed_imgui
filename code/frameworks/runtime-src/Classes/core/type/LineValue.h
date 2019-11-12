#pragma once


class LineValue
{
public:
	float x1;
	float y1;
	float x2;
	float y2;

	LineValue(float _x1, float _y1, float _x2, float _y2);

	LineValue();

	void set(float _x1, float _y1, float _x2, float _y2);
};


