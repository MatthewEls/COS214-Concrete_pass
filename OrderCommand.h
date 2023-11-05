#pragma once
#include "Command.h"
#include "Kitchen.h"
#include "Pizza.h"
#include "Waiter.h"
#include "CustomerProxy.h"

class OrderCommand : public Command {
private:
    Kitchen& kitchen;
    Pizza* pizza;
    Waiter* waiter;
    Customer * customer;

public:
    OrderCommand(Kitchen& k, Pizza* p, Waiter* w, Customer* c);
    Pizza* getPizza() const;
    void execute() override;

};
