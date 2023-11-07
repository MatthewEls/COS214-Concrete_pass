#pragma once
#include "paymentMethod.h"

class oneBill : public paymentMethod
{
public:
    double calculateTotal(double subtotal, double) override;
    void pay(double amount) override;
};
