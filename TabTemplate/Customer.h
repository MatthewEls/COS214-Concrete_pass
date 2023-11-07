#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "PaymentStrategy.h"
#include "TabCalculator.h"
#include <string>

class Customer
{
private:
    PaymentStrategy *paymentStrategy;
    bool hasReservation;
    std::string reservationTime;
    TabCalculator *tabCalculator;
    bool happyH;
    bool hasOutstandingTab;      // New attribute
    double outstandingTabAmount; // New attribute

public:
    /// @brief Constructor for a Customer
    /// @param hasReservation states wether the client that the customer has a reservation
    /// @param reservationTime what time whe rservation was made for
    Customer(bool hasReservation, const std::string &reservationTime);
   
    

        /// @brief set which payment strategy was sleceted for the customer
        /// @param strategy an interface for payment strategies
        void setPaymentStrategy(PaymentStrategy * strategy);

        /// @brief the function that will be implemented differrently depending on whether a customer paying by tab has a reservation and if it was made during happy hour
        /// @param subtotal
        /// @return return double returned by a specific tab calculator
        double calculateTab(double subtotal, double outstandingTabAmount);

        /// @brief fucntion to gove us access to the tabe calculator
        /// @return concrete tab calculator
        TabCalculator *getTabCalculator();

        /// @brief if the customer hs a reservation was it made for durong happy hour(17:00 and 18:00)
        /// @return bool
        bool isDuringHappyHour();

        /// @brief set the customers concrete tab calculator depending on whether the reservation was made for during happy hour
        /// @param calculator
        void setTabCalculator(TabCalculator * calculator);

        /// @brief compares the time the user put in to the happy hour
        /// @param time
        /// @return wether the customer has a reservation between 5 and 6
        bool checkTime(std::string time);

        void setOutstandingTab(double amount);
        double getOutstandingTabAmount() const;
        bool hasTab() const;
    };

#endif
