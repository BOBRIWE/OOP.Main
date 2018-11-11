#pragma once
#include <string>
#include <conio.h>
#include <Table.h>

class Checkpoint
{
private:
	int _pay_count;
	int _no_pay_count;
	int _price;
	std::string _history;
public:
	Cell *History;
	Cell *Cars_count;
	Cell *Pay_count;
	Cell *No_pay_count;
	Cell *Profit;

	Checkpoint()
	{
		_price = 50;
		_pay_count = 0;
		_no_pay_count = 0;
		_history = "";

		History = new Cell("");
		Cars_count = new Cell("0");
		Pay_count = new Cell("0");
		No_pay_count = new Cell("0");
		Profit = new Cell("0");
	}

	int get_pay_count()
	{
		return _pay_count;
	}

	int get_no_pay_count()
	{
		return _no_pay_count;
	}

	std::string get_history()
	{
		return _history;
	}

	void add_pay()
	{
		_history += "1";
		_pay_count += 1;

		Pay_count->reset_msg(std::to_string(_pay_count));
		Profit->reset_msg(std::to_string(_pay_count * _price));
		Cars_count->reset_msg(std::to_string(_pay_count + _no_pay_count));
		History->reset_msg(_history);
	}

	void add_no_pay()
	{
		_history += "0";
		_no_pay_count += 1;

		No_pay_count->reset_msg(std::to_string(_no_pay_count));
		Cars_count->reset_msg(std::to_string(_pay_count + _no_pay_count));
		History->reset_msg(_history);
	}
};
