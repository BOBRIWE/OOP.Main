#pragma once
#include "stdafx.h"

class Shape
{
public:
	Shape(HDC hdc, COLORREF color, POINT base_point)
	{
		Shape::hdc = hdc;
		Shape::color = color;
		Shape::base_point = base_point;

		pen = CreatePen(PS_SOLID, 7, color);
		brush = CreateSolidBrush(color);
	}

	void set_width(int w) {
		width = w;
	}

	void set_height(int h) {
		height = h;
	}

protected:
	int width;
	int height;
	HDC hdc;
	HPEN pen;
	HBRUSH brush;
	COLORREF color;
	POINT base_point;
};
