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

	/// <summary>
	/// 插值函数，以factor为因子对自己和目标vertex进行线性插值
	/// </summary>
	/// <param name="vertex"></param>
	/// <param name="factor"></param>
	/// <returns></returns>
	Vertex2D interpolate(const Vertex2D &vertex, float factor) const
	{
		Vector2 p = Vector2::Lerp(position, vertex.position, factor);
		Color c = Color::Lerp(color, vertex.color, factor);
		return Vertex2D(p, c);
	}
};