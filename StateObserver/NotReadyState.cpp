#include "NotReadyState.h"
#include "ReadyState.h"
#include "Table.h"
#include <iostream>

void NotReadyState::handle(Table *table)
{
    std::cout << "Customer is not ready to order. Waiter will come back later." << std::endl;
    table->changeState(new ReadyState); // Change state when ready to order
}
