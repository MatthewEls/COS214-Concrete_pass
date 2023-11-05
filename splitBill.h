#ifndef SPLITBILL_H
#define SPLITBILL_H
#include "paymentMethod.h"

class splitBill: public paymentMethod{
    public:
        splitBill(int x) {};
        void pay(double amount);
        double calculateTotal(double subtotal, double) override;

    private:
        int div;
};
#endif