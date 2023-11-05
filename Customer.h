#pragma once

#include <string>
#include <vector>

#include "Command.h"

 // Forward declaration

class Customer {
public:
    Customer(const std::string& name);

    const std::string& getName() const;;

//COMMAND STUFF
    void placeOrder(Command* command);
    void displayOrder();
    double getOrderTotal();

private:
     // Use a pointer to MaitreD
    std::string name;
    int partySize;
    std::vector<Command*> orders;
};

