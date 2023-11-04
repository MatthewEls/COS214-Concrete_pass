#include "DrinksChef.h"
#include <iostream>

DrinksChef::DrinksChef(const std::string& type) : Chef(type) {}

std::string DrinksChef::getType() const {
    return "Drinks Chef";
}