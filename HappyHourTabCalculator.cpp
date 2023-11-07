#include "HappyHourTabCalculator.h"
#include <iostream>
#include <string>

double HappyHourTabCalculator::calculateTab(double subtotal, double outstandingTabAmount)
{
    std::cout<< "Yay its happy hour!" << std::endl;
    std::cout <<"Your discounted total: " << calculateSubtotal(subtotal) << std::endl;
    double total = calculateSubtotal(subtotal) + outstandingTabAmount;
    return total;
}

double HappyHourTabCalculator::calculateSubtotal(double subtotal)
{
    double dis = subtotal * 0.25;
    return subtotal - dis; // 50% discount for happy hour
}