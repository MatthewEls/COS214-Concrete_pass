#include "SousChef.h"
#include <iostream>

SousChef::SousChef(const std::string& type) : Chef(type) {}

std::string SousChef::getType() const {
    return "Sous Chef";
}