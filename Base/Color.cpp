#include "Color.h"
#include "Mathf.h"

Color Color::red(1, 0, 0, 1);
Color Color::white(1, 1, 1, 1);
Color Color::green(0, 1, 0, 1);
Color Color::blue(0, 0, 1, 1);
Color Color::black(0, 0, 0, 1);
Color Color::yellow(1, 1, 0, 1);

Color::Color()
{

}

Color::Color(float _r, float _g, float _b, float _a)
{
	r = _r;
	g = _g;
	b = _b;
	a = _a;

	uintR = (uint8_t)(r * 255);
	uintG = (uint8_t)(g * 255);
	uintB = (uint8_t)(b * 255);
	uintA = (uint8_t)(a * 255);
}

int Color::GetUintR()
{
	return (int)(r * 255);
}

int Color::GetUintG()
{
	return (int)(g * 255);
}

int Color::GetUintB()
{
	return (int)(b * 255);
}

int Color::GetUintA()
{
	return (int)(a * 255);
}

Color Color::RandomColor()
{
	return Color(Mathf::Value(), Mathf::Value(), Mathf::Value(), 1);
}

Color& Color::operator*=(float num)
{
	r *= num;
	g *= num;
	b *= num;
	a *= num;
	return *this;
}

Color Color::operator*(float num)
{
	return Color(r * num, g * num, b * num, a * num);
}

Color& Color::operator/=(float num)
{
	r /= num;
	g /= num;
	b /= num;
	a /= num;
	return *this;
}

Color& Color::operator+=(const Color &c)
{
	r += c.r;
	g += c.g;
	b += c.b;
	a += c.a;
	return *this;
}

Color Color::operator+(const Color& c)
{
	return Color(r + c.r, g + c.g, b + c.b, a + c.a);
}

Color& Color::operator*=(const Color& c)
{
	r *= c.r;
	g *= c.g;
	b *= c.b;
	a *= c.a;
	return *this;
}

Color& Color::operator-=(const Color& c)
{
	r -= c.r;
	g -= c.g;
	b -= c.b;
	a -= c.a;
	return *this;
}