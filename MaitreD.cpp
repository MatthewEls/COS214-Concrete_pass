#include "MaitreD.h"
#include <iostream>

// MaitreD class implementation
MaitreD::MaitreD(const std::string& type) : Employee(type) {}

void MaitreD::assignWaiterToTable(Waiter* waiter, int tableNumber) {
    
}

void MaitreD::work() {
    std::cout << "MaitreD " << type << " is managing the restaurant." << std::endl;
    // Additional functionality for restaurant management
}

std::string MaitreD::getType() const {
    return "MaitreD";
}
