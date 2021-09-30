#include "Csdl.h"

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
		mainWindow = SDL_CreateWindow("SoftRenderer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
		if (mainWindow == NULL)
		{
			CheckError("Window could not be created!");
		}
		else
		{
			//Create renderer for window
			renderer = SDL_CreateRenderer(mainWindow, -1, SDL_RENDERER_ACCELERATED);
			if (renderer == NULL)
			{
				CheckError("Renderer could not be created! ");
			}
		}
	}
}

void CSDL::CheckError(const char* msg)
{
	std::cout << ("%s : %s\n", msg, SDL_GetError()) << std::endl;
	SDL_Quit();
	exit(1);
}