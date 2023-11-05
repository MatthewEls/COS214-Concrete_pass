#ifndef CUSTOMERHANDLER_H
#define CUSTOMERHANDLER_H

#include <string>
#include "Handler.h"
#include "Customer.h"

class CustomerHandler: public Handler{

public:
    CustomerHandler(Customer* c);
    void handle(Meal* m) override;

private:
    Customer* customer;
};

#endif
