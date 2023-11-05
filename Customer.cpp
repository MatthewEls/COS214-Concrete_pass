#include "Customer.h"
#include "MaitreD.h"
#include "Table.h"
#include "Reservation.h"  // Include Reservation's full definition
#include "oneBill.h"
#include "TabCalculator.h"
#include "StandardTabCalculator.h"
#include "HappyHourTabCalculator.h"
#include <string>
#include <regex>
#include <sstream>

#include <iostream>
using namespace std;

Customer::Customer(const std::string& name, int partySize, MaitreD* maitreD) : name(name), partySize(partySize), maitreD(maitreD) {}

const std::string& Customer::getName() const {
    return name;
}

int Customer::getPartySize() const {
    return partySize;
}

const std::vector<Reservation>& Customer::getReservations() const {
    return reservations;
}

void Customer::makeReservation(int partySize, const std::string& reservationTime) {
    // Find an available table for the given party size
    Table* table = maitreD->findAvailableTable(partySize);
    
    if (table) {
        // Create a reservation and add it to the customer's list
        Reservation reservation(this, table, reservationTime);
        reservations.push_back(reservation);
        
        // Notify the MaitreD to add the customer to the list of reservations
        maitreD->addCustomerWithReservation(reservation);
    } else {
        std::cout << "No available table for the specified party size." << std::endl;
    }
}

void Customer::viewReservations() const {
    if (reservations.empty()) {
        std::cout << "You have no reservations." << std::endl;
    } else {
        std::cout << "Reservations for " << name << ":" << std::endl;
        for (const Reservation& reservation : reservations) {
            std::cout << "Table: " << reservation.getTable()->getName() << ", Time: " << reservation.getReservationTime() << std::endl;
        }
    }
}

void Customer::walkIn(const std::string& name, int partySize, MaitreD* maitreD) {
    WalkIn walkIn(name, partySize, maitreD);
    walkIn.makeWalkInReservation();
}


///Payment strat
void Customer:: setPaymentMethod(paymentMethod* paymentMethod) {
    strat = paymentMethod;
}

void Customer::payOrder(double amount){
    if (strat)
    {
        strat->pay(amount);
    }
    else
    {
        std::cout << "No payment strategy set." << std::endl;
    }
}

Customer::Customer(bool hasReservation, const std::string &reservationTime)
    : hasReservation(hasReservation), reservationTime(reservationTime), strat(0),
      tabCalculator(nullptr), hasOutstandingTab(false), outstandingTabAmount(0.0) {}

void Customer::setPaymentStrategy(paymentMethod *strategy)
{
    strat = strategy;
}

double Customer::calculateTab(double subtotal, double os)
{
    // os = outstandingTabAmount;
    //  TabCalculator *tabCalculator = getTabCalculator();
    //  return tabCalculator->calculateTab(subtotal);
    if (strat)
    {
        double total = strat->calculateTotal(subtotal, os);
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
