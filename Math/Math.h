#pragma once
#include <cmath>
#include <cfloat>

class Math
{
public:
	Math() {}
	~Math() {}

	static float Pi;
	static float Rad2Deg;
	static float Deg2Rad;
	static float Infinity;
	static float NegativeInfinity;
	static float EPSILON;
	static float Clamp(float x, float min = 0, float max = 1)
	{
		return fmin(max, fmax(x, min));
	}

	static float Min(float a, float b)
	{
		return fmin(a, b);
	}

	static float Max(float a, float b)
	{
		return fmax(a, b);
	}

	static float Acos(float theta)
	{
		return acos(theta);
	}
};

