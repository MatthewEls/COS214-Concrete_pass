#include "OrderCommand.h"

OrderCommand::OrderCommand(Kitchen& k, Pizza* p, Waiter* w, Customer* c) : kitchen(k), pizza(p), waiter(w), customer(c) {}

void OrderCommand::execute() {
    kitchen.prepareOrder(pizza,waiter, customer);
}

Pizza* OrderCommand::getPizza() const {
    return pizza;
}