#include "splitBill.h"
#include <iostream>


splitBill::splitBill(int x ){ div = x;};

void splitBill::pay(double amount)
    {
        std::cout << "The bill is split, each person pays R" << amount/ div << std::endl;
    }



    double splitBill::calculateTotal(double subtotal, double out)
    {
        return subtotal * 1.1;
    }
