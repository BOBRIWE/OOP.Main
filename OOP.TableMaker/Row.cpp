#include "stdafx.h"
#include "Row.h"


Row::Row(int width)
{
	_width = width;
	_available_width = width;
}


Row* Row::add_cell(Cell* cell)
{
	if (_available_width < cell->get_width()) {
		cell->reset_width(_available_width);
		cell->reset_msg(cell->get_msg().substr(0, _available_width));
	}

	_available_width = (_available_width > cell->get_width()) ? _available_width - cell->get_width() : 0;

	Cells.push_back(cell);
	return this;
}
