#include "Customer.h"
#include "OneBill.h"
#include "TabCalculator.h"
#include "StandardTabCalculator.h"
#include "HappyHourTabCalculator.h"
#include <string>
#include <iostream>
#include <regex>
#include <sstream>

Customer::Customer(bool hasReservation, const std::string &reservationTime)
    : hasReservation(hasReservation), reservationTime(reservationTime), paymentStrategy(0), 
    tabCalculator(nullptr), hasOutstandingTab(false), outstandingTabAmount(0.0) {}

void Customer::setPaymentStrategy(PaymentStrategy *strategy)
{
    paymentStrategy = strategy;
}

double Customer::calculateTab(double subtotal, double os)
{
    //os = outstandingTabAmount;
        // TabCalculator *tabCalculator = getTabCalculator();
        // return tabCalculator->calculateTab(subtotal);
        if (paymentStrategy)
    {
        double total = paymentStrategy->calculateTotal(subtotal, os);
        if (tabCalculator)
        {
            total = tabCalculator->calculateTab(total, os);
        }
        return total;
    }
    else
    {
        std::cerr << "Payment strategy not set." << std::endl;
        return 0.0;
    }
}

TabCalculator *Customer::getTabCalculator()
{
    if (hasReservation && isDuringHappyHour())
    {
        return new HappyHourTabCalculator();
    }
    else
    {
        return new StandardTabCalculator();
    }
}

bool Customer::isDuringHappyHour()
{
    // Check the time and date for happy hour
    // Return true if it's within the happy hour timeframe
    return happyH;
}

void Customer::setTabCalculator(TabCalculator *calculator)
{
    tabCalculator = calculator;
}

bool Customer::checkTime(std::string time)
{
    // {
    //     // Ensure the time string is in the "HH:MM" format
    //     std::regex timeRegex(R"(\d{2}:\d{2})");

    //     if (!std::regex_match(time, timeRegex))
    //     {
    //         std::cerr << "Invalid time format: " << time << std::endl;
    //         return false;
    //     }

    //     // Split the time string into hours and minutes
    //     std::istringstream iss(time);
    //     std::string hours_str, minutes_str;
    //     std::getline(iss, hours_str, ':');
    //     std::getline(iss, minutes_str);

    //     int hours = std::stoi(hours_str);
    //     int minutes = std::stoi(minutes_str);

    //     // Check if the reservation time is between 17:00 and 18:00
    //     return (hours == 17 && minutes >= 0 && minutes <= 59) ||
    //            (hours == 18 && minutes == 0);
    std::regex timeRegex("((17:\\d{2})|(18:00))"); // Matches times between 17:00 and 18:00
    happyH = std::regex_search(time, timeRegex);
    return happyH;
}

void Customer::setOutstandingTab(double amount)
{
    if (hasTab())
    {
        outstandingTabAmount = amount;
    }
    else
    {
        std::cerr << "Customer does not have a tab." << std::endl;
    }
}

double Customer::getOutstandingTabAmount() const
{
    return outstandingTabAmount;
}

bool Customer::hasTab() const
{
    // return hasOutstandingTab;
    return false;
}