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

enum RenderState
{
	RENDER_STATE_WIREFRAME = 1,
	RENDER_STATE_TEXTURE = 2,
	RENDER_STATE_COLOR = 4,
	RENDER_STATE_POINT = 8,
};