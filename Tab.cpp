#include "Tab.h"
#include "TabCalculator.h"

#include <iostream>

void Tab::pay(double amount) {

        std::cout << "The bill is added to the tab" << std::endl;
        std::cout << "Current Tab: " << std::endl;
        calculateTotal(amount, getOutstandingAmountFromTextFile(fname, cname));
        std::cout << total << std::endl;
    }

    double Tab::calculateTotal(double subtotal, double out)
    { 
        double tempTot = subtotal;
        if (tabCalculator)
        {
            tempTot = tabCalculator->calculateTab(subtotal, out);
            return tempTot;
        }
       total = tempTot;
        return tempTot;
        
        
    }

    void Tab::setTabCalculator(TabCalculator *calculator)
    {
        tabCalculator = calculator;
    }

    double Tab::getOutstandingAmountFromTextFile(const std::string &filename, const std::string &customerName)
    {
        std::ifstream file(filename);

        if (!file.is_open())
        {
            std::cerr << "Failed to open file." << std::endl;
            return 0.0; // Return 0.0 to indicate an error or no outstanding amount.
        }

        double outstandingAmount = 0.0;
        std::string line;

        while (std::getline(file, line))
        {
            std::istringstream iss(line);
            std::string name;

            if (iss >> name >> outstandingAmount)
            {
                if (customerName == name)
                {
                    file.close();
                    return outstandingAmount; // Return the outstanding amount if the customer is found.
                }
            }
        }

        file.close();

        // If the customer was not found in the file, return 0.0 or another suitable value.
        return 0.0;
    }