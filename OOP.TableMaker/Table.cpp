#include "stdafx.h"
#include "Table.h"

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