// softrender.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

//#include <iostream>
//
//int main()
//{
//    std::cout << "Hello World!\n";
//}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件


//#include <stdio.h>
//#include <stdlib.h>
//
//#include "SDL.h"
//#include "SDL_revision.h"
//
//int main(int argc, char* argv[])
//{
//	SDL_version compiled;
//	SDL_version linked;
//
//	/* Enable standard application logging */
//	SDL_LogSetPriority(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO);
//
//#if SDL_VERSION_ATLEAST(2, 0, 0)
//	SDL_Log("Compiled with SDL 2.0 or newer\n");
//#else
//	SDL_Log("Compiled with SDL older than 2.0\n");
//#endif
//	SDL_VERSION(&compiled);
//	SDL_Log("Compiled version: %d.%d.%d.%d (%s)\n",
//		compiled.major, compiled.minor, compiled.patch,
//		SDL_REVISION_NUMBER, SDL_REVISION);
//	SDL_GetVersion(&linked);
//	SDL_Log("Linked version: %d.%d.%d.%d (%s)\n",
//		linked.major, linked.minor, linked.patch,
//		SDL_GetRevisionNumber(), SDL_GetRevision());
//	SDL_Quit();
//	return (0);
//}

#include <SDL.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include "CommonDef.h"
#include "Rasterizer.h"
#include "Base/Csdl.h"
#include "Base/Color.h"
#include "Math/Mathf.h"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Frees media and shuts down SDL
void close();

void close()
{
	//Destroy window    
	//SDL_DestroyRenderer(gRenderer);
	//SDL_DestroyWindow(gWindow);
	//gWindow = NULL;
	//gRenderer = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}

int main(int argc, char* args[])
{
	RenderContext renderContext;
	renderContext.width = SCREEN_WIDTH;
	renderContext.height = SCREEN_HEIGHT;
	renderContext.bpp = sizeof(uint32);
	renderContext.backBuffer = new uint32[renderContext.width * renderContext.height];
	renderContext.depthBuffer = new float[renderContext.width * renderContext.height];

	Rasterizer rasterizer(&renderContext);
	//Color tempColor = Color::black;
	CSDL* sdl = new CSDL(SCREEN_WIDTH, SCREEN_HEIGHT, "SoftRenderer");

	while (true)
	{
		sdl->HandleEvents();
		sdl->Clean(&renderContext, Color::black);
		//for (int i = 0; i < 100; i++)
		//{
		//	rasterizer.DrawPixel(SCREEN_WIDTH * Math::Value(), SCREEN_HEIGHT * Math::Value(), Color::red);
		//}

		//屏幕中间画条直线
		/*for (int j = 0; j < SCREEN_HEIGHT / 2; j++)
		{
			rasterizer.DrawPixel(SCREEN_WIDTH / 2, j, Color::red);
		}*/

		//两点画直线
		/*Line2d* line = new Line2d(Vector2(0.0f, 0.0f),
			Vector2(SCREEN_WIDTH, 300.0f));
		rasterizer.DrawLine2(line, Color::blue);*/

		//随机线条
		/*
		for (int i = 0; i < 1; i++)
		{
			//Line2d *line = new Line2d(Vector2(SCREEN_WIDTH * Mathf::Value(), SCREEN_HEIGHT * Mathf::Value()),
				//Vector2(SCREEN_WIDTH * Mathf::Value(), SCREEN_HEIGHT * Mathf::Value()));

			Line2d* line = new Line2d(Vector2(SCREEN_WIDTH * Mathf::Range(-1.0f, 1.0f), SCREEN_HEIGHT * Mathf::Range(-1.0f, 1.0f)),
				Vector2(SCREEN_WIDTH * Mathf::Range(-1.0f, 1.0f), SCREEN_HEIGHT * Mathf::Range(-1.0f, 1.0f)));
			rasterizer.DrawLine2(line, Color::RandomColor());
		}
		*/

		//for (int i = 0; i < 10; i++)
		{
			//Vector2 v0(SCREEN_WIDTH * Mathf::Value(), SCREEN_HEIGHT * Mathf::Value());
			//Vector2 v1(SCREEN_WIDTH * Mathf::Value(), SCREEN_HEIGHT * Mathf::Value());
			//Vector2 v2(SCREEN_WIDTH * Mathf::Value(), SCREEN_HEIGHT * Mathf::Value());
			//Color col0 = Color::RandomColor();
			//Color col1 = Color::RandomColor();
			//Color col2 = Color::RandomColor();
			Vector2 v0(120.0f, 20.0f);
			Vector2 v1(40.0f, 150.0f);
			Vector2 v2(280.0f, 400.0f);
			Color col0 = Color::red;
			Color col1 = Color::blue;
			Color col2 = Color::yellow;
			
			rasterizer.DrawTriangle2D(Vertex2D(v0, col0), Vertex2D(v1, col1), Vertex2D(v2, col2));
		}
		sdl->SwapBuffer(&renderContext);
	}

	delete[] renderContext.backBuffer;
	delete[] renderContext.depthBuffer;

	//Free resources and close SDL
	close();

	return 0;
}