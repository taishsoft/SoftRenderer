#pragma once

#include "CommonDef.h"
#include "Base/Color.h"
#include "Shape/Line2d.h"

class Rasterizer
{
public:
	Rasterizer(RenderContext *pContext);
	~Rasterizer();

	void DrawPixel(int x, int y, Color& c);
	void DrawLine(Line2d *line, Color c);
	void DrawLine1(Line2d *line, Color c);
	void DrawLine2(Line2d *line, Color c);

	/// <summary>
	/// Cohen-Sutherland�㷨�����߶α��룬�������ҡ��¡��ϵ�˳��
	/// </summary>
	/// <param name="pos"></param>
	/// <param name="min"></param>
	/// <param name="max"></param>
	/// <returns></returns>
	int Encode(Vector2& pos, Vector2& min, Vector2& max);

	bool CohenSutherlandLineClip(Line2d *line, Vector2 min, Vector2 max);
	
private:
	RenderContext *renderContext;

};

