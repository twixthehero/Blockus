#pragma once
class Color
{
public:
	Color(int, int, int);
	Color(int, int, int, int);
	Color(float, float, float);
	Color(float, float, float, float);
	~Color();

	float r;
	float g;
	float b;
	float a;
};