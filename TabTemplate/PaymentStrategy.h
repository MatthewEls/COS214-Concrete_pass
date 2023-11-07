#pragma once

class PaymentStrategy
{
public:
    virtual double calculateTotal(double subtotal, double out) = 0;
};
