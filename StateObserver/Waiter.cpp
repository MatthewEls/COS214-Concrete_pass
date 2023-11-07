#include "Waiter.h"
#include <iostream>

Waiter::Waiter(const std::string& type, double salary) : Employee(type), salary(salary), tips(0.0) {}

void Waiter::setTips(double tips) {
    this->tips = tips;
}

double Waiter::getTotalEarnings() const {
    return salary + tips;
}

void Waiter::work() {
    std::cout << "Waiter " << type << " is taking care of a table." << std::endl;
    // Additional functionality to take an order and serve an order
}

std::string Waiter::getType() const {
    return "Waiter";
}

Waiter::Waiter(const std::string &waiterName) : name(waiterName) {}

void Waiter::update()
{
    std::cout << "Waiter " << name << " receives an update." << std::endl;
    // Add logic here to take the customer's order if needed
}
