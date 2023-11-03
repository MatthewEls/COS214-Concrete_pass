#include "paymentMethod.h"
#include <iostream>

class oneBill : public paymentMethod
{
public:
    void pay(double amount) override
    {
        std::cout << "One person pays R" << amount << std::endl;
    }
};