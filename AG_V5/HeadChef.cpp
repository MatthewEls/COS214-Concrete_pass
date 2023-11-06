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

void HeadChef::decorate(Meal*m){
    cout<<"testing the function for HeadChef\n";
    //implimintaion here (this is called for the chain, if changes please chains HeadChefHandler handle<3)

}