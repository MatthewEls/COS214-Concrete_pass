#include "Employee.h"
#include <iostream>

// Employee class implementation
Employee::Employee(const std::string& type) : type(type) {}

std::string Employee::getType() const {
    return "Employee";
}
