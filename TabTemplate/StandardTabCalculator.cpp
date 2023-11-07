#include "StandardTabCalculator.h"
#include <iostream>
#include <string>

double StandardTabCalculator::calculateTab(double subtotal, double outstandingTabAmount)
{
    double total = calculateSubtotal(subtotal) + outstandingTabAmount;
    return (total > 5000) ? subtotal : total;
}

double StandardTabCalculator::calculateSubtotal(double subtotal)
{
    return subtotal;
}