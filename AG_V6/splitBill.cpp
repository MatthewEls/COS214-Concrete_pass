#include "paymentMethod.h"
#include "splitBill.h"
#include <iostream>
#include <iomanip>

splitBill::splitBill(int x)
{
    this->div = x;
}

void splitBill::pay(double amount)
{
    std::cout << std::setprecision(2)<<std::fixed;
    std::cout << "The bill is split, each person pays R" << amount / div << std::endl;
}

double splitBill::calculateTotal(double subtotal, double out)
{
    return subtotal * 1.1;
}
