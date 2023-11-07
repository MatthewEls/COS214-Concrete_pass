#ifndef SPLITBILL_H
#define SPLITBILL_H
#include "paymentMethod.h"

class splitBill{
    public:
        splitBill(int x) {};
        void pay(double amount);

    private:
        int div;
};
#endif