#ifndef WAITERHANDLER_H
#define WAITERHANDLER_H

#include <string>
#include "Handler.h"
#include "Waiter.h"

class WaiterHandler: public Handler{

public:
    WaiterHandler(Waiter* hc);
    // void handle(Meal* m);
    void handle(Meal* m) override;
private:
    Waiter *waiter;
};

#endif
