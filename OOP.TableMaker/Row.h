#pragma once
#include "Cell.h"
#include <vector>

class Row
{
public:
	Row(int width);
	~Row();

	std::vector<Cell> Cells;
	void add_cell(Cell cell);

private:
	int _width;
};

