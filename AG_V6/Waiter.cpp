#include "Waiter.h"
//#include "Table.h"
#include <iostream>

const std::string RESET = "\033[0m";
const std::string YELLOW = "\033[33m";

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
    std::cout <<YELLOW<< "\t\t\t\tWaiter " << type << " is taking care of a table." << RESET<<std::endl;
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
    std::cout<<YELLOW<<"\t\t\t\tWaiter "<<type<<" is serving table."<<assignedTable->getName()<<RESET<<std::endl;
}

Table* Waiter::getTable(){
    return assignedTable;
}

void Waiter::returnMeal(Meal* m){
    cout<<YELLOW<<"\t\t\t\tWaiter is bringing food to table\n"<<RESET;
    //implimentaion for getting the meal to the table
}

void Waiter::update()
{
    std::cout << "Waiter " << type << " receives an update." << std::endl;
    // Add logic here to take the customer's order if needed
}