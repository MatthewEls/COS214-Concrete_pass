#include "HappyHourTabCalculator.h"
#include <iostream>
#include <string>

double HappyHourTabCalculator::calculateTab(double subtotal, double outstandingTabAmount)
{
    double total = calculateSubtotal(subtotal) + outstandingTabAmount;
    return (total > 5000) ? subtotal : total;
}

double HappyHourTabCalculator::calculateSubtotal(double subtotal)
{
    return subtotal * 0.5; // 50% discount for happy hour
}