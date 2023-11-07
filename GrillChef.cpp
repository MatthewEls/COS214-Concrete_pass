#include "GrillChef.h"
#include <iostream>

GrillChef::GrillChef(const std::string& type) : Chef(type) {}

std::string GrillChef::getType() const {
    return "Grill Chef";
}