#pragma once

#include "CommonDef.h"
#include "Base/Color.h"

class Rasterizer
{
public:
	Rasterizer(RenderContext* pContext);
	~Rasterizer();

	void DrawPixel(int x, int y, Color& c);

private:
	RenderContext *renderContext;

};

