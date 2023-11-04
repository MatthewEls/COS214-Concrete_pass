#include "HeadChef.h"
#include <iostream>

HeadChef::HeadChef(const std::string& type) : Employee(type) {}

void HeadChef::work() {
    std::cout << "HeadChef " << type << " is making food." << std::endl;
    // Additional functionality for food preparation
}

std::string HeadChef::getType() const {
    return "HeadChef";
}