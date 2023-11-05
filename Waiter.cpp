#include "Waiter.h"
//#include "Table.h"
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
    return type;
}

void Waiter::assignTable(Table* table){
    assignedTable = table;
}

// void Waiter::serveTable(){
//     std::cout<<"Waiter "<<type<<" is serving table "<<assignedTable->getName()<<std::endl;
// }

void Waiter::serveTable(Meal* m){
    cout<<"testing the Waiter Serve Table\n";
    //implimentaion for getting the meal to the table
}