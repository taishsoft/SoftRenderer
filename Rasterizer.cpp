#include "Rasterizer.h"
#include <iostream>
#include <bitset>
using namespace std;

Rasterizer::Rasterizer(RenderContext *pContext)
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

/// <summary>
/// bresenham算法
/// https://zhuanlan.zhihu.com/p/43537323
/// </summary>
/// <param name="line"></param>
/// <param name="c"></param>
void Rasterizer::DrawLine(Line2d *line, Color c)
{
	if (!CohenSutherlandLineClip(line, Vector2(0, 0), Vector2(renderContext->width, renderContext->height)))
	{
		return;
	}
	int x1 = line->start.x;
	int y1 = line->start.y;
	int x2 = line->end.x;
	int y2 = line->end.y;

	int x, y = 0;
	int eps = 0;

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
		int dx = (x1 < x2) ? x2 - x1 : x1 - x2;
		int dy = (y1 < y2) ? y2 - y1 : y1 - y2;

		//slope < 1
		if (dx >= dy)
		{
			if (x1 > x2)
			{
				std::swap(x1, x2);
				std::swap(y1, y2);
			}
			for (x = x1, y = y1; x <= x2; x++)
			{
				DrawPixel(x, y, c);
				eps += dy;
				if (eps >= dx)
				{
					eps -= dx;
					y += (y2 >= y1) ? 1 : -1;
				}
			}
			//DrawPixel(x2, y2, c);
		}
		else
		{
			if (y1 > y2)
			{
				std::swap(x1, x2);
				std::swap(y1, y2);
			}
			for (x = x1, y = y1; y <= y2; y++)
			{
				DrawPixel(x, y, c);
				eps += dx;
				if (eps >= dy)
				{
					eps -= dy;
					x += (x2 >= x1) ? 1 : -1;
				}
			}
			//DrawPixel(x2, y2, c);
		}
	}
}

/// <summary>
/// b站：游戏中的AI算法（二）-Bresenham
/// 跟传统的bresenham算法略有不同
/// 初始参数：斜率k deltaY = k 中点middle = 0.5
/// 判别式：deltaY >= middle
/// 更新参数：x += 1; deltaY += k; 判别式成立则——y += 1; middle += 1
/// </summary>
/// <param name="line"></param>
/// <param name="c"></param>
void Rasterizer::DrawLine1(Line2d *line, Color c)
{
	if (!CohenSutherlandLineClip(line, Vector2(0, 0), Vector2(renderContext->width, renderContext->height)))
	{
		return;
	}
	int x1 = line->start.x;
	int y1 = line->start.y;
	int x2 = line->end.x;
	int y2 = line->end.y;

	int dx = abs(x2 - x1);
	int dy = abs(y2 - y1);
	bool interchange = false; //横纵轴交换标记
	if (dx < dy)
	{
		swap(dx, dy);
		interchange = true;
	}
	int deltaY = dy << 1;
	int middle = dx;
	int sign_x = (x2 > x1) ? 1 : -1;
	int sign_y = (y2 > y1) ? 1 : -1;
	int x = x1;
	int y = y1;
	while(x != x2 || y != y2)
	{
		DrawPixel(x, y, c);
		if (interchange)
		{
			y += sign_y;
		}
		else
		{
			x += sign_x;
		}
		
		if (deltaY >= middle)
		{
			if (interchange)
				x += sign_x;
			else
				y += sign_y;
			middle += (dx << 1);
		}
		deltaY += (dy << 1);
	}
}

/// <summary>
/// bresenham算法
/// https://www.zhihu.com/search?type=content&q=bresenham
/// https://github.com/ssloy/tinyrenderer/wiki/Lesson-1:-Bresenham%E2%80%99s-Line-Drawing-Algorithm
/// </summary>
/// <param name="line"></param>
/// <param name="c"></param>
void Rasterizer::DrawLine2(Line2d *line, Color c)
{
	if (!CohenSutherlandLineClip(line, Vector2(0, 0), Vector2(renderContext->width, renderContext->height)))
	{
		return;
	}
	int x1 = line->start.x;
	int y1 = line->start.y;
	int x2 = line->end.x;
	int y2 = line->end.y;
	
	bool steep = false;
	//slope > 1
	if (abs(x1 - x2) < abs(y1 - y2))
	{
		std::swap(x1, y1);
		std::swap(x2, y2);
		steep = true;
	}
	if (x1 > x2)
	{
		std::swap(x1, x2);
		std::swap(y1, y2);
	}

	int x, y = 0;
	int eps = 0;

	int dx = x2 - x1;
	int dy = y2 - y1;
	y = y1;
	int yi = 1;

	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}

	//int err = dy * 2;
	for (x = x1; x <= x2; x++)
	{
		if (steep)
		{
			DrawPixel(y, x, c);
		}
		else
		{
			DrawPixel(x, y, c);
		}

		eps += dy;
		//eps += err;
		if ((eps << 1) >= dx)
		//if(eps > dx)
		{
			y = y + yi;
			eps -= dx;
			//eps -= (dx << 1);
		}
	}
}

int Rasterizer::Encode(Vector2& pos, Vector2& min, Vector2& max)
{
	int code = LINE_INSIDE;
	if (pos.x < min.x)
	{
		code |= LINE_LEFT;
	}
	else if (pos.x > max.x)
	{
		code |= LINE_RIGHT;
	}

	if (pos.y < min.y)
	{
		code |= LINE_BOTTOM;
	}
	else if (pos.y > max.y)
	{
		code |= LINE_TOP;
	}

	return code;
}

/// <summary>
/// Cohen-Sutherland线段裁剪算法
/// 编码顺序：left right bottom top
///	1001|  1000 | 1010
/// ----|-------|------
///	0001|  0000	| 0010
/// ----|-------|------
///	0101|  0100	| 0110
/// </summary>
/// <param name="line"></param>
/// <param name="min"></param>
/// <param name="max"></param>
/// <returns></returns>
bool Rasterizer::CohenSutherlandLineClip(Line2d *line, Vector2 min, Vector2 max)
{
	int x1 = line->start.x;
	int y1 = line->start.y;
	int x2 = line->end.x;
	int y2 = line->end.y;

	int code1 = Encode(line->start, min, max);
	int code2 = Encode(line->end, min, max);
	int code;
	
	bool bAccept = false;
	double x, y, k;
	Vector2 tmpVec2;

	while (true)
	{
		//先判断窗口内部的点
		if ((code1 | code2) == 0)
		{
			bAccept = true;
			break;
		}
		//再判断窗口外部的点
		else if (code1 & code2)
		{
			break;
		}
		else
		{
			//遍历两个点，至少有一个在窗口外面
			code = code1 ? code1 : code2;
			
			//求交点，公式为：由(y2-y1)/(x2-x1)=(y-y1)/(x-x1)推导出:
			//y = y1 + k*(x - x1),x = x1 + (1/k)*(y - y1)，k为斜率
			k = (y2 - y1) / (x2 - x1);
			if (code & LINE_LEFT)
			{
				x = min.x;
				y = y1 + k * (min.x - x1);
			}
			else if (code & LINE_RIGHT)
			{
				x = max.x;
				y = y1 + k * (max.x - x1);
			}
			else if (code & LINE_BOTTOM)
			{
				x = x1 + (1 / k) * (min.y - y1);
				y = min.y;
			}
			else if (code & LINE_TOP)
			{
				x = x1 + (1 / k) * (max.y - y1);
				y = max.y;
			}

			//裁剪交点外线段
			if (code == code1)//start point
			{
				x1 = x;
				y1 = y;
				tmpVec2.x = x1;
				tmpVec2.y = y1;
				code1 = Encode(tmpVec2, min, max);
			}
			else//end point
			{
				x2 = x;
				y2 = y;
				tmpVec2.x = x2;
				tmpVec2.y = y2;
				code2 = Encode(tmpVec2, min, max);
			}
		}
	}

	if (bAccept)
	{
		line->start.x = x1;
		line->start.y = y1;
		line->end.x = x2;
		line->end.y = y2;
	}
	return bAccept;
}
