#include "stdafx.h"
#include "Cell.h"


Cell::Cell(std::string msg, int width)
{
	_msg = msg;
	_width = width;
}


Cell::Cell(std::string msg)
{
	Cell(msg, msg.length());
}


Cell::~Cell()
{
}


void Cell::reset_width(int width)
{
	_width = width;
}


void Cell::reset_msg(std::string msg)
{
	_msg = msg;
}