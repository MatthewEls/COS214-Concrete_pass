#include "Customer.h"
#include "MaitreD.h"
#include "Table.h"
#include "Reservation.h"  // Include Reservation's full definition
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

