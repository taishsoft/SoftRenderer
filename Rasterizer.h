#pragma once

#include "CommonDef.h"
#include "Base/Color.h"
#include "Shape/Line2d.h"

class Rasterizer
{
public:
	Rasterizer(RenderContext *pContext);
	~Rasterizer();

	void DrawPixel(int x, int y, Color& c);
	void DrawLine(Line2d *line, Color c);
	void DrawLine1(Line2d *line, Color c);
	void DrawLine2(Line2d *line, Color c);

	/// <summary>
	/// Cohen-Sutherland算法，对线段编码，按照左、右、下、上的顺序
	/// </summary>
	/// <param name="pos"></param>
	/// <param name="min"></param>
	/// <param name="max"></param>
	/// <returns></returns>
	int Encode(Vector2& pos, Vector2& min, Vector2& max);

	bool CohenSutherlandLineClip(Line2d *line, Vector2 min, Vector2 max);
	
private:
	RenderContext *renderContext;

};

