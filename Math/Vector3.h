#pragma once

#include <math.h>
#include <assert.h>

using namespace std;

class Vector3
{
public:
	float x;
	float y;
	float z;

	Vector3();
	Vector3(float _x, float _y, float _z);
	Vector3(float value);
	~Vector3();
	bool HasNaNs() const;
	void set(float _x, float _y, float _z);

	static Vector3 back;
	static Vector3 down;
	static Vector3 forward;
	static Vector3 left;
	static Vector3 right;
	static Vector3 up;
	static Vector3 zero;
	static Vector3 one;

	float magnitude() const;
	float sqrtMagnitude() const;
	Vector3 normalized();
	void Normalize();

	//运算符重载
	Vector3 operator+(const Vector3 &v) const;
	Vector3 operator-(const Vector3 &v) const;
	Vector3 operator/(float num) const;
	Vector3 &operator+=(const Vector3 &v);
	Vector3 &operator-=(const Vector3 &v);
	Vector3 &operator*=(float num);

	friend Vector3 operator * (const Vector3 &lhs, double rhs);
	friend Vector3 operator * (double lhs, const Vector3 &rhs);

	Vector3 &operator/=(float num);
	bool operator!=(Vector3 &v) const;

	//插值函数
	static inline Vector3 Lerp(const Vector3& v1, const Vector3& v2, float factor)
	{
		return v1 + (v2 - v1) * factor;
	}
};

