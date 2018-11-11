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
		_pt[0] = base_point;

		_pt[1].x = base_point.x + width;
		_pt[1].y = base_point.y;

		_pt[2].x = base_point.x + width;;
		_pt[2].y = base_point.y + height;

		_pt[3].x = base_point.x;
		_pt[3].y = base_point.y + height;
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
};

//
//HPEN hPolygonPen;
//COLORREF qPolygonColor;
//qPolygonColor = RGB(255, 0, 0);
//hPolygonPen = CreatePen(PS_SOLID, 7, qPolygonColor);
//
//POINT Pt[4];
//Pt[0].x = 10;
//Pt[0].y = 20;
//
//Pt[1].x = 100;
//Pt[1].y = 0;
//
//Pt[2].x = 100;
//Pt[2].y = 100;
//
//Pt[3].x = 0;
//Pt[3].y = 100;
//
//
//Polygon(hdc, Pt, 4);
//
//SelectObject(hdc, hPenOld);
//DeleteObject(hPolygonPen);