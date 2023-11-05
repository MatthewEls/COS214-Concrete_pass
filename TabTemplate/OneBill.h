#pragma once
#include "PaymentStrategy.h"

class OneBill : public PaymentStrategy
{
public:
    double calculateTotal(double subtotal, double) override;
};
