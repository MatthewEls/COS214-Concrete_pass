#pragma once
#include "PaymentStrategy.h"

class SplitBill : public PaymentStrategy
{
public:
    double calculateTotal(double subtotal, double) override;
};
