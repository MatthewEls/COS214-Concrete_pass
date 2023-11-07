#include "ReadyState.h"
#include "Table.h"
#include <iostream>

void ReadyState::handle(Table *table)
{
    std::cout << "Customer is ready to order. Waiter takes the order." << std::endl;
}
