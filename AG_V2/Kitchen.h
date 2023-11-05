#pragma once
#include <string>
#include "Pizza.h"
#include "Meal.h"
#include "HeadChefHandler.h"
#include "WaiterHandler.h"
#include "CustomerHandler.h"

class Kitchen {
public:
     Kitchen(HeadChef* gordon);
     ~Kitchen();
     void prepareOrder(Pizza* pizza, Waiter* waiter, Customer* customer);
private:
     Waiter* fetch;
     HeadChef* headChef;
     HeadChefHandler* chain;
     Customer* orderer;
};
