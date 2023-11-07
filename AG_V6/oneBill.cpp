#include "OneBill.h"
#include <iostream>
#include <iomanip>

void oneBill::pay(double amount) 
    {
        std::cout << std::setprecision(2)<<std::fixed;
        std::cout << "One person pays R" << amount << std::endl;
    }


double oneBill::calculateTotal(double subtotal, double out)
{
    return subtotal * 1.1;
}
