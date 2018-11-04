#include "stdafx.h"
#include "Row.h"


Row::Row(int width)
{
	_width = width;
}


Row::~Row()
{
}


void Row::add_cell(Cell cell)
{
	Cells.push_back(cell);
}
