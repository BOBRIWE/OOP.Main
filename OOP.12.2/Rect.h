#pragma once
#include "Shape.h"
class Rect :public Shape
{
private:
	POINT _pt[4];
public:
	Rect(HDC hdc, COLORREF color, POINT point, int width, int height) :Shape(hdc, color, point)
	{
		set_height(height);
		set_width(width);
		reset_base_point(base_point);
	}

	void draw()
	{
		SelectObject(hdc, brush);
		Polygon(hdc, _pt, 4);
		DeleteObject(brush);

		SelectObject(hdc, pen);
		Polygon(hdc, _pt, 4);
		DeleteObject(pen);
	}

	void reset_width(int w)
	{
		width = w;
		reset_base_point(base_point);
	}

	void reset_height(int h)
	{
		height = h;
		reset_base_point(base_point);
	}

	void reset_color(COLORREF c)
	{
		color = c;
		pen = CreatePen(PS_SOLID, 7, color);
		brush = CreateSolidBrush(color);
	}

	void reset_base_point(POINT pt)
	{
		base_point = pt;
		_pt[0] = base_point;

		_pt[1].x = base_point.x + width;
		_pt[1].y = base_point.y;

		_pt[2].x = base_point.x + width;;
		_pt[2].y = base_point.y + height;

		_pt[3].x = base_point.x;
		_pt[3].y = base_point.y + height;
	}
};
