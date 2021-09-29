#pragma once
#include <stdint.h>

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

	Color();
	Color(float r, float g, float b, float a = 1);
	int GetUintR();
	int GetUintG();
	int GetUintB();
	int GetUintA();

	static Color RandomColor();


};

