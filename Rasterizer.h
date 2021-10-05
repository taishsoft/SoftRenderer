#pragma once

#include "CommonDef.h"
#include "Base/Color.h"
#include "Shape/Line2d.h"

class Rasterizer
{
public:
	Rasterizer(RenderContext* pContext);
	~Rasterizer();

	void DrawPixel(int x, int y, Color& c);
	void DrawLine(Line2d* line, Color c);

private:
	RenderContext *renderContext;

};

