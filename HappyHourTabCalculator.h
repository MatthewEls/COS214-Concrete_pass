#pragma once
#include "TabCalculator.h"

class HappyHourTabCalculator : public TabCalculator
{
protected:
    double calculateSubtotal(double subtotal) override;
    double calculateTab(double subtotal, double outstandingTabAmount) override;
};
