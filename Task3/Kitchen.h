#pragma once
#include <string>
#include "Pizza.h"
#include "Meal.h"
#include "HeadChefHandler.h"
#include "WaiterHandler.h"
#include "CustomerHandler.h"
#include "CustomerProxy.h"
#include "Pizza.h"

class Kitchen {
public:
     Kitchen(HeadChef* gordon);
     ~Kitchen();
     void prepareOrder(Pizza* pizza, Waiter* waiter, CustomerProxy* customer);
private:
     Waiter* fetch;
     HeadChef* headChef;
     HeadChefHandler* chain;
     CustomerProxy* orderer;
};
