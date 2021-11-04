#pragma once
#include <cmath>
#include <cfloat>
#include <stdlib.h>
class Mathf
{
public:
	Mathf() {}
	~Mathf() {}

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

	static void SetSeed(int seed)
	{
		srand(seed);
	}

	static float Range(float min, float max)
	{
		float r = (float)rand() / (float)RAND_MAX;
		return min + r * (max - min);
	}

	static float Range(int min, int max)
	{
		return min + (rand() % (max - min + 1));
	}

	/// <summary>
	/// return random value between[0, 1]
	/// </summary>
	/// <returns></returns>
	static double Value()
	{
		return (double)rand() / RAND_MAX;
	}

	static inline float Lerp(float a, float b, float factor)
	{
		return a + (b - a) * factor;
	}

	/// <summary>
	/// abs 和 fabs都是求绝对值，abs一般是对整数求绝对值，而fabs主要是对精度要求更高的double float，其实如果float用abs的话，abs底层还是会调用到fabs
	/// </summary>
	/// <param name="a"></param>
	/// <returns></returns>
	static inline int Abs(int a)
	{
		return std::abs(a);
	}

	static inline float Fabs(float a)
	{
		return fabs(a);
	}
};

