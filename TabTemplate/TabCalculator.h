#pragma once

class TabCalculator
{



public:
     virtual double calculateTab(double subtotal, double outstandingTabAmount) = 0;

public:
    virtual double calculateSubtotal(double subtotal) = 0;
    virtual double applyTaxes(double total);
};
