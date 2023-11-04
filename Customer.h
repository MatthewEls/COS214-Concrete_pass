#pragma once

#include <string>
#include <vector>
#include "Reservation.h"  // Include Reservation's full definition
#include "WalkIn.h"
#include "Order.h"
#include "paymentMethod.h"

class MaitreD;  // Forward declaration

class Customer {
public:
    Customer(const std::string& name, int partySize, MaitreD* maitreD);

    const std::string& getName() const;
    int getPartySize() const;
    const std::vector<Reservation>& getReservations() const;
    void makeReservation(int partySize, const std::string& reservationTime);
    void walkIn(const std::string& name, int partySize, MaitreD* maitreD);
    void viewReservations() const;


    //Bill payment startegy
    void setPaymentMethod(paymentMethod*);
    void payOrder(double amount);

private:
    MaitreD* maitreD;  // Use a pointer to MaitreD
    std::string name;
    int partySize;
    std::vector<Reservation> reservations;

    Table* table;
    Order *order;
    bool ready;
    paymentMethod *strat;
};
