#pragma once
#include <string>

class Cell
{
public:
	Cell(std::string msg, int width);
	Cell(std::string msg);
	~Cell();

	void reset_width(int width);
	void reset_msg(std::string msg);

private:
	std::string _msg;
	int _width;
};

