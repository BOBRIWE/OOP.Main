#pragma once
#include <string>
#include <windows.h>
#include "Row.h"

class Table
{
public:
	Table();
	~Table();

	int Width, Height;
	Row* add_row(Row* row);
	std::vector<Row*> Rows;
	void print();

private:
	CONSOLE_SCREEN_BUFFER_INFO _csbi;
	int _get_console_width();
	int _get_console_height();

};

