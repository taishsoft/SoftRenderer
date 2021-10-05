#pragma once
#include <SDL.h>
#include <iostream>
#include "Color.h"
#include "../CommonDef.h"

//class RenderContext;

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
	void Clean(RenderContext* renderContext, Color color);
	void Quit(int code);
	void ToggleFullscreen();
	void HandleKeyEvent(SDL_Keysym* keysym);
	void HandleEvents();
	void CheckError(const char* msg);
	//void CheckSDLError(int line = -1);
	void SetDrawColor(Color color);

	void DrawPixel(int x, int y);
	void SwapBuffer(RenderContext* renderContext);

private:
	SDL_Window* mainWindow;
	SDL_Renderer* renderer;
	SDL_Surface* surface;
	SDL_Texture* mainRT;

	Uint32 rmask, gmask, bmask, amask;

	bool windowed;

	bool windowOK;
};