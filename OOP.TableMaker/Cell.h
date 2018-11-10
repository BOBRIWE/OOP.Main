#pragma once
#include <string>

class Cell
{
public:
	Cell(std::string msg, int width, std::string align = "left");
	Cell(std::string msg);
	~Cell();

	void reset_width(int width);
	void reset_msg(std::string msg);
	int get_width();
	std::string get_align();
	std::string get_msg();

private:
	std::string _msg;
	int _width;
	std::string _align;

};

