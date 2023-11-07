#include "Tab.h"
#include "TabCalculator.h"
#include <iostream>

double Tab::calculateTotal(double subtotal, double out) 
{
    if (tabCalculator)
    {
        return tabCalculator->calculateTab(subtotal, out);
    }
    else
    {
        // std::cerr << "Tab calculator not set." << std::endl;
        return subtotal;
    }
}

void Tab::setTabCalculator(TabCalculator *calculator)
{
    tabCalculator = calculator;
}

