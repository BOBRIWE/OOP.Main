#include "pch.h"
#include <iostream>
#include <Table.h>

int main()
{
	Table *table = new Table();

    std::cout << table->get_hello(); 
}
