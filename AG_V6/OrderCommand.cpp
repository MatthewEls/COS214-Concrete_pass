#include "OrderCommand.h"

OrderCommand::OrderCommand(Kitchen& k, Pizza* p, Waiter* w, Customer* c) : kitchen(k), pizza(p), waiter(w), customer(c) {}

void OrderCommand::execute() {
    CustomerProxy proxy(customer);
    kitchen.prepareOrder(pizza,waiter, &proxy);
}

Pizza* OrderCommand::getPizza() const {
    return pizza;
}