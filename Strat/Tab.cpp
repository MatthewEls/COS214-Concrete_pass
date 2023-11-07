#include "paymentMethod.h"
#include <iostream>

class Tab : public paymentMethod
{
public:
    void pay(double amount) override{
        std::cout << "The bill is added to the tab" << std::endl;
    }
};

//Check what the tabbing logic will be like.
// For example do we forfeit tab option when it gets to a certian amount