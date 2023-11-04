#include "Chef.h"
#include <iostream>

Chef::Chef(const std::string& type) : Employee(type) {}

void Chef::work() {
    std::cout << "Chef " << type << " is making food." << std::endl;
    // Additional functionality for food preparation
}

std::string Chef::getType() const {
    return "Chef";
}