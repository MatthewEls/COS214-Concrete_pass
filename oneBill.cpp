#include "OneBill.h"
#include <iostream>


void oneBill::pay(double amount) 
    {
        std::cout << "One person pays R" << amount * 1.1 << std::endl;
    }


double oneBill::calculateTotal(double subtotal, double out)
{
    return subtotal * 1.1;
}
