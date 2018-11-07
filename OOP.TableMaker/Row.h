#pragma once
#include "Cell.h"
#include <vector>

class Row
{
public:
	Row(int width);

	std::vector<Cell*> Cells;
	Row* add_cell(Cell *cell);

private:
	int _width;
	int _available_width;

};

