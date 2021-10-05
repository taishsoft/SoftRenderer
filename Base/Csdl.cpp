#include "Csdl.h"
#include <SDL_endian.h>
CSDL::CSDL()
{

}

CSDL::CSDL(int width, int height, const char* windowName)
{
	screenWidth = width;
	screenHeight = height;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		CheckError("SDL could not initialize!");
	}
	else
	{
		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		//Create window
		mainWindow = SDL_CreateWindow(windowName, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
		if (mainWindow == NULL)
		{
			CheckError("Window could not be created!");
		}
		else
		{
			windowed = true;

			//Create renderer for window
			renderer = SDL_CreateRenderer(mainWindow, -1, SDL_RENDERER_ACCELERATED);
			if (renderer == NULL)
			{
				CheckError("Renderer could not be created! ");
			}
		}

		//SDL_PIXELFORMAT_ABGR8888不能用这个啊，这会导致渲染红色结果却是蓝色的情况，因为我们是通过位移操作来控制rgb的
		mainRT = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, width, height);

		surface = SDL_GetWindowSurface(mainWindow);

		//测试大小端
#if SDL_BYTEORDER == SDL_BIG_ENDIAN
		std::cout << "SDL_BIG_ENDIAN" << std::endl;

#else
		std::cout << "SDL_LITTLE_ENDIAN" << std::endl;

#endif
	}
}

CSDL::~CSDL()
{
	//todo
}

void CSDL::Quit(int code)
{
	SDL_Quit();
	exit(code);
}

void CSDL::HandleEvents()
{
	//Event handler
	SDL_Event e;

	//Handle events on queue
	while (SDL_PollEvent(&e) != 0)
	{
		switch (e.type)
		{
		case SDL_KEYDOWN:
			HandleKeyEvent(&e.key.keysym);
			break;
		case SDL_QUIT:
			Quit(0);
			break;
		case SDL_WINDOWEVENT:
			if (e.window.event == SDL_WINDOWEVENT_RESIZED)
			{
				if (mainWindow)
				{
					int tempx, tempy;
					SDL_GetWindowSize(mainWindow, &tempx, &tempy);
				}
			}
			SDL_GL_SwapWindow(mainWindow);
			break;
		}
	}
}

void CSDL::Render()
{
	//Update screen
	SDL_RenderPresent(renderer);
}

void CSDL::HandleKeyEvent(SDL_Keysym* keysym)
{
	switch (keysym->sym)
	{
	case SDLK_ESCAPE:
		Quit(0);
		break;
	case SDLK_SPACE:
		break;
	case SDLK_F1:
		ToggleFullscreen();
		break;
	case SDLK_r:
		std::cout << "hehe" << std::endl;
		break;
	default:
		break;
	}
}

void CSDL::ToggleFullscreen()
{
	if (windowed == true)
	{
		int result = SDL_SetWindowFullscreen(mainWindow, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN);
		if (result < 0)//there is an error
		{
			windowOK = false;
			return;
		}
		windowed = false;
	}
	else if (windowed == false)
	{
		SDL_SetWindowSize(mainWindow, screenWidth, screenHeight);
		windowed = true;
	}
}

void CSDL::SetDrawColor(Color color)
{
	SDL_SetRenderDrawColor(renderer, color.GetUintR(), color.GetUintG(), color.GetUintB(), color.GetUintA());
}

void CSDL::DrawPixel(int x, int y)
{
	SDL_RenderDrawPoint(renderer, x, y);
}

void CSDL::SwapBuffer(RenderContext* renderContext)
{
	void* pixels;
	int pitch;

	SDL_LockTexture(mainRT, NULL, &pixels, &pitch);

	//copy loaded/formatted surface pixels
	memcpy(pixels, renderContext->backBuffer, surface->pitch * surface->h);

	SDL_UnlockTexture(mainRT);

	SDL_RenderCopy(renderer, mainRT, NULL, NULL);
	SDL_RenderPresent(renderer);
}

void CSDL::Clean(RenderContext* renderContext, Color color)
{
	int col = (color.GetUintA() << 24 | color.GetUintR() << 16 | color.GetUintG() << 8 | color.GetUintB() << 0);
	memset(renderContext->backBuffer, col, renderContext->width * renderContext->height * renderContext->bpp);
	std::fill(renderContext->depthBuffer, renderContext->depthBuffer + renderContext->width * renderContext->height, FLT_MAX);
}

void CSDL::CheckError(const char* msg)
{
	std::cout << ("%s : %s\n", msg, SDL_GetError()) << std::endl;
	SDL_Quit();
	exit(1);
}