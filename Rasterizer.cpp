#include "Rasterizer.h"

Rasterizer::Rasterizer(RenderContext* pContext)
{
	renderContext = pContext;
}

Rasterizer::~Rasterizer()
{

}

void Rasterizer::DrawPixel(int x, int y, Color& c)
{
	//左移位数？
	renderContext->backBuffer[x + y * renderContext->width] = (c.GetUintA() << 24) | (c.GetUintR() << 16) | (c.GetUintG() << 8) | (c.GetUintB() << 0);
}