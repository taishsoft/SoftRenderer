#pragma once

typedef unsigned int uint32;

const int LINE_INSIDE = 0; //0000
const int LINE_LEFT = 1; //0001
const int LINE_RIGHT = 2; //0010
const int LINE_BOTTOM = 4; //0100
const int LINE_TOP = 8; //1000


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