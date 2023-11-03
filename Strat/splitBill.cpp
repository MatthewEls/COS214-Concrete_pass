#include "paymentMethod.h"
#include <iostream>

class splitBill : public paymentMethod
{
public:
    splitBill(int x ){ div = x;};

    void pay(double amount) override
    {
        std::cout << "The bill is split, each person pays R" << amount/ div << std::endl;
    }

    //Maybe we could add a cin so that we can dynamically


private: 
int div;
};