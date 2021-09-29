#pragma once

typedef unsigned int uint32;

struct RenderContext
{
	int width;
	int height;
	int bpp;
	uint32* backBuffer;
	float* depthBuffer;
};