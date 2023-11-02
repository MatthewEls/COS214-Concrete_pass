#include "OrderCommand.h"

OrderCommand::OrderCommand(Kitchen& k, Pizza* p) : kitchen(k), pizza(p) {}

void OrderCommand::execute() {

    kitchen.prepareOrder(pizza);
}
Pizza* OrderCommand::getPizza() const {
    return pizza;
}