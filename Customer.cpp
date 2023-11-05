#include "Customer.h"
#include "OrderCommand.h" // Include Reservation's full definition
#include <iostream>
using namespace std;

Customer::Customer(const std::string& name) : name(name){}

const std::string& Customer::getName() const {
    return name;
}

void Customer::Test(){
    cout<<"Testing the Proxy!";
}

void Customer::ReceveMeal(Meal* m){
    //teminal example text <3
    cout<<"\nThey consumed a meal with the contents:\n";
    m->outputContents();
    cout<<"YUM<3\n";
    delete m;
}

void Customer::placeOrder(Command* command) {
    if (command == nullptr) {
        std::cout << "Cannot place a null order." << std::endl;
        return;
    }

    orders.push_back(command);

    if (orders.size() > 0) {
        std::cout << "Order placed successfully." << std::endl;}

    
    command->execute();
    cout << "Command Executed." << endl;
}

void Customer::displayOrder() {
    if (orders.empty()) {
        std::cout << "No orders placed yet." << std::endl;
    } else {
        std::cout << "Current Order:" << std::endl;
        double total = 0.0;
        for (const Command* order : orders) {
            const OrderCommand* orderCommand = dynamic_cast<const OrderCommand*>(order);
            if (orderCommand) {
                std::cout << "Pizza: " << orderCommand->getPizza()->getItemType() << " - Price: R" << orderCommand->getPizza()->getPrice() << std::endl;
                total += orderCommand->getPizza()->getPrice();
            }
        }
        std::cout << "Total Price: R" << total << std::endl;
    }
}

double Customer::getOrderTotal() {
    double total = 0.0;
    for (const Command* order : orders) {
        const OrderCommand* orderCommand = dynamic_cast<const OrderCommand*>(order);
        if (orderCommand) {
            total += orderCommand->getPizza()->getPrice();
        }
    }
    return total;
}

