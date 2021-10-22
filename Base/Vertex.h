#pragma once

#include "Vector3.h"
#include "Vector2.h"
#include "Color.h"

class Vertex
{
public:
	float u;
	float v;
	float w;
	Color color;

	Vector3 position;
	Vector3 normal;

	Vertex()
	{

	}

	//position需要引用？
	Vertex(const Vector3 &position, const Vector3 normal, float u, float v, const Color &color = Color())
	{
		this->position = position;
		this->normal = normal;
		this->u = u;
		this->v = v;
		this->w = w;
		this->color = color;
	}

	Vertex interpolate(const Vertex &vertex, float factor) const
	{
		//todo
		return vertex;
	}
};

class Vertex2D
{
public:
	Vector2 position;
	Vector2 uv;
	Color color;

	Vertex2D()
	{

	}

	Vertex2D(const Vector2 &position, const Color &color = Color())
	{
		this->position = position;
		this->color = color;
	}

	//插值函数，不可以修改类成员
	Vertex2D interpolate(const Vertex2D &vertex, float t) const
	{
		Vector2 p = Vector2::Lerp(position, vertex.position, t);
		Color c = Color::Lerp(color, vertex.color, t);
		return Vertex2D(p, c);
	}
};