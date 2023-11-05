#pragma once

#include "CustomerSubject.h"
#include <string>
#include <vector>

#include "Command.h"

class Customer:public CustomerSubject {
public:
    Customer(const std::string& name);

    const std::string& getName() const;;

//COMMAND STUFF
    void placeOrder(Command* command);
    void displayOrder();
    double getOrderTotal();

// Proxy Command
    // void ReceveMeal(Meal* m);
    void Test()override;
    void ReceveMeal(Meal* m) override;

private:
     // Use a pointer to MaitreD
    std::string name;
    int partySize;
    std::vector<Command*> orders;
};

