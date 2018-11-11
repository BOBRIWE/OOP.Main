#pragma once
#include <Shape.h>
#include <math.h>

class Circle :public Shape
{
public:
	Circle(HDC hdc, COLORREF color, POINT center, int radius) :Shape(hdc, color, center)
	{
		set_height(radius * 2);
		set_width(radius * 2);
		_radius = radius;
		reset_base_point(center);
	};

	void draw()
	{
		SelectObject(hdc, brush);
		Polygon(hdc, _pt, 360);
		DeleteObject(brush);

		SelectObject(hdc, pen);
		Polygon(hdc, _pt, 360);
		DeleteObject(pen);
	}

	void reset_base_point(POINT pt)
	{
		base_point = pt;

		for (int i = 0; i < 360; i++)
		{
			_pt[i].x = base_point.x + _radius * cos(_PI / 180 * i);
			_pt[i].y = base_point.y + _radius * sin(_PI / 180 * i);
		}
	}

private:
	POINT _pt[360];
	int _radius;
	const double _PI = 3.141592653589793238463;
};
