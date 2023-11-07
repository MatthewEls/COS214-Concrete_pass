#include "Tab.h"
#include "TabCalculator.h"

#include <iostream>

void Tab::pay(double amount) {
        std::cout << "The bill is added to the tab" << std::endl;
    }

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
