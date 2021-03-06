#include "pch.h"
#include <iostream>
#include <Table.h>
#include "Checkpoint.h"

class Checpoint 
{
};

int main()
{
	setlocale(LC_CTYPE, "rus");

	Table *output = new Table();
	Checkpoint *checkpoint = new Checkpoint();

	Cell *menu = new Cell("Нажмите клавиши: ");
	//Cell *history = new Cell("");
	//Cell *cars_count = new Cell("0");
	//Cell *pay_count = new Cell("0");
	//Cell *no_pay_count = new Cell("0");
	//Cell *profit = new Cell("0");

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
		->add_cell(checkpoint->History);
	output->add_row(new Row(output->Width));

	output->add_row(new Row(output->Width))
		->add_cell(new Cell("Количество проехавших машин: ", 30))
		->add_cell(checkpoint->Cars_count);

	output->add_row(new Row(output->Width))
		->add_cell(new Cell("Из них: оплатили парковку: ", 30))
		->add_cell(checkpoint->Pay_count);

	output->add_row(new Row(output->Width))
		->add_cell(new Cell("не оплатили парковку: ", 30))
		->add_cell(checkpoint->No_pay_count);

	output->add_row(new Row(output->Width));

	output->add_row(new Row(output->Width))
		->add_cell(new Cell("Общая сумма выручки: ", 30))
		->add_cell(checkpoint->Profit);

	output->print();



	char ch = _getch();
	while (ch != 27)
	{
		switch (ch)
		{
		case 48:
			system("cls");
			checkpoint->add_no_pay();
			output->print();
			break;
		case 49:
			system("cls");
			checkpoint->add_pay();
			output->print();
			break;
		}

		ch = _getch();
	}
}
