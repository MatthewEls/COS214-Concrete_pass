#include "TabCalculator.h"
#include <iostream>
#include <string>

// double TabCalculator::calculateTab(double subtotal)
// {
//     double total = calculateSubtotal(subtotal);
//     std::cout << "calTab "<< total << std::endl;
//     total = applyTaxes(total);
//     std::cout << "apply tax "<< total << std::endl;
//     return total;
// }

double TabCalculator::applyTaxes(double total)
{
    return total * 1.1; // 10% tax by default
}
