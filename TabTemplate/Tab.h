#pragma once
#include "PaymentStrategy.h"
#include "TabCalculator.h"

class Tab : public PaymentStrategy
{
    private:
    TabCalculator* tabCalculator;
public:
    double calculateTotal(double subtotal, double out) override;
    //Tab(TabCalculator &calculator) : tabCalculator(calculator) {}
    Tab(){}
    void setTabCalculator(TabCalculator *calculator);
 
};
