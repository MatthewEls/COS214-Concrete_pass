#include "HeadChef.h"
#include <iostream>
#include <cstdlib>  // For system function
#include <unistd.h> // For sleep function

const std::string MAGENTA = "\033[35m";
const std::string RESET = "\033[0m";

HeadChef::HeadChef(const std::string& type) : Employee(type) {}

void HeadChef::work() {
    std::cout<<MAGENTA << "\t\t\t\tHeadChef " << type << " is making food." <<RESET<< std::endl;
    // Additional functionality for food preparation
}

std::string HeadChef::getType() const {
    return "HeadChef";
}

void HeadChef::decorate(Meal*m){
    cout<<MAGENTA<<"\t\t\t\tHeadchef plating meal\n"<<RESET;
    sleep(3);
    //implimintaion here (this is called for the chain, if changes please chains HeadChefHandler handle<3)

}