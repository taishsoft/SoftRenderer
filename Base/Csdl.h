#pragma once
#include <SDL.h>


class RenderContext;

//封装一层SDL
class CSDL
{
public:
	int screenWidth;
	int screenHeight;

	CSDL();
	CSDL(int width, int height, const char* windowName);
	~CSDL();

	void Render();
	void Clean(RenderContext* renderContext);
	void Quit(int code);
	void ToggleFullscreen();
	void HandleKeyEvent(SDL_Keysym* keysym);
};

