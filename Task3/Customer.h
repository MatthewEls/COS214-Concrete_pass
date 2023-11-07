#pragma once

#include <string>
#include <vector>
#include "Reservation.h"  // Include Reservation's full definition
#include "WalkIn.h"
#include "Command.h"
#include "paymentMethod.h"
#include "Meal.h"
#include "CustomerSubject.h"

class MaitreD;  // Forward declaration

class Customer:public CustomerSubject {
public:
    Customer(const std::string& name, int partySize, MaitreD* maitreD);

    const std::string& getName() const;
    int getPartySize() const;
    const std::vector<Reservation>& getReservations() const;
    const std::vector<WalkIn>& getWalkIns() const;
    void makeReservation(int partySize, const std::string& reservationTime);
    void walkIn(const std::string& name, int partySize);
    void viewReservations() const;
    void Leave();

//COMMAND STUFF
    void placeOrder(Command* command);
    void displayOrder();
    double getOrderTotal();

//Bill payment startegy
    void setPaymentMethod(paymentMethod*);
    void payOrder(double amount);

//Proxy Stuff
    void Test()override;
    void ReceveMeal(Meal* m) override;

private:
    MaitreD* maitreD;  // Use a pointer to MaitreD
    std::string name;
    int partySize;
    std::vector<Reservation> reservations;
     std::vector<Command*> orders;
     std::vector<WalkIn> walkIns;

//STRATETGY STUFF
    bool ready;
    paymentMethod *strat;
};
