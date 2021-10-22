#pragma once
#include <stdint.h>
#include <math.h>
#include "Mathf.h"

class Color
{
public:
	float r;
	float g;
	float b;
	float a;

	uint8_t uintR;
	uint8_t uintG;
	uint8_t uintB;
	uint8_t uintA;

	static Color red;
	static Color white;
	static Color green;
	static Color blue;
	static Color black;
	static Color yellow;

	Color();
	Color(float r, float g, float b, float a = 1);
	int GetUintR();
	int GetUintG();
	int GetUintB();
	int GetUintA();

	static Color RandomColor();

	static inline Color Lerp(const Color& c1, const Color& c2, float factor)
	{
		float r = Mathf::Lerp(c1.r, c2.r, factor);
		float g = Mathf::Lerp(c1.g, c2.g, factor);
		float b = Mathf::Lerp(c1.b, c2.b, factor);
		float a = Mathf::Lerp(c1.a, c2.a, factor);
		return Color(r, g, b, a);
	}
};