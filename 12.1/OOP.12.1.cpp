#include "pch.h"
#include <iostream>
#include <Table.h>

int main()
{
	setlocale(LC_CTYPE, "rus");

	Table *output = new Table();

	Cell *menu = new Cell("Нажмите клавиши: ");
	Cell *pressed_buttons = new Cell("");
	Cell *cars_count = new Cell("0");
	Cell *pay_count = new Cell("0");
	Cell *no_pay_count = new Cell("0");
	Cell *profit = new Cell("0");

	output->add_row(new Row(output->Width))
		->add_cell(menu)
		->add_cell(new Cell("0 - для каждой машины без оплаты"));

	output->add_row(new Row(output->Width))
		->add_cell(new Cell("", menu->get_width()))
		->add_cell(new Cell("1 - для каждой оплачивающей машины"));
	output->add_row(new Row(output->Width))
		->add_cell(new Cell("", menu->get_width()))
		->add_cell(new Cell("ESC - для выхода"));
	output->add_row(new Row(output->Width));
	output->add_row(new Row(output->Width))
		->add_cell(pressed_buttons);
	output->add_row(new Row(output->Width));

	output->add_row(new Row(output->Width))
		->add_cell(new Cell("Количество проехавших машин: ", 30))
		->add_cell(cars_count);

	output->add_row(new Row(output->Width))
		->add_cell(new Cell("Из них: оплатили парковку: ", 30))
		->add_cell(pay_count);

	output->add_row(new Row(output->Width))
		->add_cell(new Cell("не оплатили парковку: ", 30))
		->add_cell(no_pay_count);

	output->add_row(new Row(output->Width));

	output->add_row(new Row(output->Width))
		->add_cell(new Cell("Общая сумма выручки: ", 30))
		->add_cell(profit);

	output->print();



}
