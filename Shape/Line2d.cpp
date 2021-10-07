#include "Line2d.h"

Line2d::Line2d()
{
	Vector2 zero = { 0, 0 };
	start = zero;
	end = zero;
}

Line2d::Line2d(Vector2 _start, Vector2 _end)
{
	start = _start;
	end = _end;

	if(start.x < 0.0f || start.y < 0.0f)
		std::cout << ("%f : %f\n", start.x, start.y) << std::endl;
	if (end.x < 0.0f || end.y < 0.0f)
		std::cout << ("%f : %f\n", end.x, end.y) << std::endl;
}

Line2d::~Line2d()
{

}