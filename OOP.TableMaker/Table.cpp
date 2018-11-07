#include "stdafx.h"
#include "Table.h"
#include <iostream>
#include <iomanip>
#include <cstring>

Table::Table()
{
	Width = Table::_get_console_width();
	Height = Table::_get_console_height();
}

Table::~Table()
{
}


int Table::_get_console_width()
{
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &_csbi);
	int width = _csbi.srWindow.Right - _csbi.srWindow.Left + 1;
	return width;
}

int Table::_get_console_height()
{
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &_csbi);
	int height = _csbi.srWindow.Bottom - _csbi.srWindow.Top + 1;
	return height;
}

Row* Table::add_row(Row *row)
{
	Rows.push_back(row);
	return row;
}

void Table::print()
{
	for (Row* row : Rows)
	{
		for (Cell* cell : row->Cells) {
			std::string align = cell->get_align();
			if (align == "left")
			{
				std::cout << std::left;
			}
			else if (align == "right")
			{
				std::cout << std::right;
			}
			else
			{
				std::cout << std::internal;
			}

			std::cout << std::setw(cell->get_width()) << cell->get_msg();
		}

		std::cout << std::endl;
	}
}