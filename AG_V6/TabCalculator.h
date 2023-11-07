#pragma once

class TabCalculator
{

public:
    virtual double calculateTab(double subtotal, double outstandingTabAmount) = 0;

    virtual double calculateSubtotal(double subtotal) = 0;
    virtual double applyTaxes(double total);
};
