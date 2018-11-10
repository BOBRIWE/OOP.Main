#include "stdafx.h"
#include "Cell.h"
#include <iostream>


Cell::Cell(std::string msg, int width, std::string align)
{
	_msg = msg;
	_width = width;
	_align = align;
}


Cell::Cell(std::string msg) :Cell(msg, msg.length())
{
}


Cell::~Cell()
{
	std::cout << _msg;
}


void Cell::reset_width(int width)
{
	_width = width;
}


void Cell::reset_msg(std::string msg)
{
	_msg = msg;
}

int Cell::get_width()
{
	return _width;
}

std::string Cell::get_align()
{
	return _align;
}

std::string Cell::get_msg()
{
	return _msg;
}