#include "color.h"

Color::Color(int r, int g, int b) : Color(r, g, b, 255) {}
Color::Color(int r, int g, int b, int a) : Color(r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f) {}
Color::Color(float r, float g, float b) : Color(r, g, b, 1.0f) {}
Color::Color(float r, float g, float b, float a)
{
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
}

Color::~Color()
{
}