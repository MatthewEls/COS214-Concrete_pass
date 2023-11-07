#include "paymentMethod.h"
#include "splitBill.h"
#include <iostream>

splitBill::splitBill(int x)
{
    this->div = x;
}

void splitBill::pay(double amount)
{
    std::cout << "The bill is split, each person pays R" << (amount / div) * 1.1 << std::endl; // apply taxes
}

double splitBill::calculateTotal(double subtotal, double out)
{
    return subtotal * 1.1;
}
