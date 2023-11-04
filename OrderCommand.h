#pragma once
#include "Command.h"
#include "Kitchen.h"
#include "Pizza.h"

class OrderCommand : public Command {
private:
    Kitchen& kitchen;
    std::string item;
    Pizza* pizza;

public:
    OrderCommand(Kitchen& k, Pizza* p);
    Pizza* getPizza() const;
    void execute() override;
};
