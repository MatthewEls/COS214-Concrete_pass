#ifndef CUSTOMERHANDLER_H
#define CUSTOMERHANDLER_H

#include <string>
#include "Handler.h"
#include "Customer.h"
#include "CustomerProxy.h"

class CustomerHandler: public Handler{

public:
    CustomerHandler(CustomerProxy* c);
    void handle(Meal* m) override;

private:
    CustomerProxy* customer;
};

#endif
