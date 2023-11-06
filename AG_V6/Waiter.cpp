#include "Waiter.h"
//#include "Table.h"
#include <iostream>

Waiter::Waiter(const std::string& type, double salary) : Employee(type), salary(salary), tips(0.0) {
    cout<<"Waiter "<<type<<" has been added for the shift, Salary is R"<<salary<<endl;
}

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
    std::cout<<"Waiter "<<type<<" is assigned table "<<assignedTable->getName()<<std::endl;
}

void Waiter::serveTable(){
    std::cout<<"Waiter "<<type<<" is serving table "<<assignedTable->getName()<<std::endl;
}

Table* Waiter::getTable(){
    return assignedTable;
}

void Waiter::returnMeal(Meal* m){
    cout<<"testing the Waiter Serve Table\n";
    //implimentaion for getting the meal to the table
}

void Waiter::update()
{
    std::cout << "Waiter " << type << " receives an update." << std::endl;
    // Add logic here to take the customer's order if needed
}