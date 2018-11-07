#include "pch.h"
#include <iostream>
#include <Table.h>

int main()
{
	Table *table = new Table();

	table->add_row(new Row(table->Width))
		->add_cell(new Cell("msg", table->Width/2))
		->add_cell(new Cell("msg", table->Width / 2 - 1, "right"))
		->add_cell(new Cell("last", table->Width / 2, "right"));

	table->print();
}
