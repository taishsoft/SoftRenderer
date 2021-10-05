#include "Rasterizer.h"
#include <iostream>
#include <bitset>

Rasterizer::Rasterizer(RenderContext* pContext)
{
	renderContext = pContext;
}

Rasterizer::~Rasterizer()
{

}

void Rasterizer::DrawPixel(int x, int y, Color& c)
{
	//32位颜色表示 argb oxffffffff
	//uint32 color = (c.GetUintA() << 24) | (c.GetUintR() << 16) | (c.GetUintG() << 8) | (c.GetUintB() << 0);
	//std::cout << std::bitset<32>(color) << std::endl;

	renderContext->backBuffer[x + y * renderContext->width] = (c.GetUintA() << 24) | (c.GetUintR() << 16) | (c.GetUintG() << 8) | (c.GetUintB() << 0);
}

void Rasterizer::DrawLine(Line2d* line, Color c)
{
	int x1 = line->start.x;
	int y1 = line->start.y;
	int x2 = line->end.x;
	int y2 = line->end.y;

	int x, y = 0;

	//line is a pixel
	if (x1 == x2 && y1 == y2)
	{
		DrawPixel(x1, y1, c);
	}
	//vertical line
	else if (x1 == x2)
	{
		int inc = (y1 <= y2) ? 1 : -1;
		for (y = y1; y <= y2; y += inc)
		{
			DrawPixel(x1, y, c);
		}
	}
	//horizontal line
	else if (y1 == y2)
	{
		int inc = (x1 <= x2) ? 1 : -1;
		for (x = x1; x <= x2; x += inc)
		{
			DrawPixel(x, y1, c);
		}
	}
	else
	{

	}
}
