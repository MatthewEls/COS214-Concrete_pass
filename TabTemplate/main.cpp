#include "Customer.h"
#include "PaymentStrategy.h"
#include "OneBill.h"
#include "SplitBill.h"
#include "Tab.h"
#include "TabCalculator.h"
#include "StandardTabCalculator.h"
#include "HappyHourTabCalculator.h"
#include <iostream>
#include <string>




int main()
{
    std::string reservationTime;
    std::cout << "Does the customer have a reservation? (yes/no): ";
    std::string hasReservationInput;
    std::cin >> hasReservationInput;
    double out;
    bool hasReservation = (hasReservationInput == "yes");
    bool tab = false;

    if (hasReservation)
    {
        std::cout << "Enter the reservation time (e.g., 2023-10-31 18:30): ";
        // std::cin.ignore(); // Ignore newline character from previous input
        // std::getline(std::cin, reservationTime);
        std::cin >> reservationTime;

    }

    Customer customer(hasReservation, reservationTime);

    customer.checkTime(reservationTime);
    if(hasReservation){
        tab = customer.hasTab();
    }

    PaymentStrategy *strategy = nullptr;
    TabCalculator *tabCalculator = nullptr;

    std::cout << "Choose a payment method:" << std::endl;
    std::cout << "1. One person pays the whole amount" << std::endl;
    std::cout << "2. Split the bill" << std::endl;
    std::cout << "3. Tab" << std::endl;
    int paymentChoice;
    std::cin >> paymentChoice;

    if (paymentChoice == 1)
    {
        strategy = new OneBill();
    }
    else if (paymentChoice == 2)
    {
        strategy = new SplitBill();
    }
    else if (paymentChoice == 3)
    {
        tab = customer.hasTab();
         if (tab)
        {
            std::cout << tab << std::endl;

            std::cout << "Choose another payment method:" << std::endl;
            std::cout << "1. One person pays the whole amount" << std::endl;
            std::cout << "2. Split the bill" << std::endl;
            int otherpaymentChoice;
            std::cin >> otherpaymentChoice;
            if (otherpaymentChoice == 1)
            {
                out =0;
                strategy = new OneBill();
            }
            else if (otherpaymentChoice == 2)
            {
                out =0;
                strategy = new SplitBill();
            }
        }

        else{
            strategy = new Tab();
            std::cout << "What is customers outstanding amount:" << std::endl;
          
            std::cin >> out;
            customer.setOutstandingTab(out);
            if (hasReservation && customer.isDuringHappyHour())
            {
                tabCalculator = new HappyHourTabCalculator();
            }
            else
            {
                tabCalculator = new StandardTabCalculator();
            }
        }
    }
    else
    {
        std::cout << "Invalid payment method. No payment strategy set." << std::endl;
    }

    customer.setPaymentStrategy(strategy);
    if (tabCalculator != nullptr)
    {
        customer.setTabCalculator(tabCalculator);
    }

    double subtotal;
    std::cout << "Enter the subtotal: ";
    std::cin >> subtotal;

    double total = customer.calculateTab(subtotal, out);

    std::cout << "Total bill: R" << total << std::endl;

    // Clean up resources
    delete strategy;
    delete tabCalculator;

    return 0;
}


