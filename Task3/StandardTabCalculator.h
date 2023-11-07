#pragma once
#include "TabCalculator.h"

class StandardTabCalculator : public TabCalculator
{
protected:
    double calculateTab(double subtotal, double outstandingTabAmount) override;
    double calculateSubtotal(double subtotal) override;
};
