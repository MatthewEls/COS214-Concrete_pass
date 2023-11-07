#pragma once
#include "paymentMethod.h"
#include "TabCalculator.h"

class Tab : public paymentMethod
{
private:
    TabCalculator *tabCalculator;

public:
    double calculateTotal(double subtotal, double out) override;
    // Tab(TabCalculator &calculator) : tabCalculator(calculator) {}
    Tab() {}
    void setTabCalculator(TabCalculator *calculator);
    void pay(double amount) override;
};
