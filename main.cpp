#include "Employee.h"
#include "Chef.h"
#include "DrinksChef.h"
#include "GrillChef.h"
#include "SousChef.h"
#include "MaitreD.h"
#include "HeadChef.h"
#include "Waiter.h"
#include <iostream>

int main() {
    Waiter waiter("Alice", 1000.0);
    waiter.setTips(200.0);

    /////////////
    /*
    Note that names were used for testing purposes,
    if we want to add names to the different employees, we have to expand on the current code.
    */
    Chef chef("Bob");
    DrinksChef drinksChef("Charlie");
    GrillChef grillChef("David");
    SousChef sousChef("Eve");
    ///////////////////////

    std::cout << "Type of Waiter: " << waiter.getType() << std::endl;
    std::cout << "Type of Chef: " << chef.getType() << std::endl;
    std::cout << "Type of Drinks Chef: " << drinksChef.getType() << std::endl;
    std::cout << "Type of Grill Chef: " << grillChef.getType() << std::endl;
    std::cout << "Type of Sous Chef: " << sousChef.getType() << std::endl;

    waiter.work();
    chef.work();
    drinksChef.work();
    grillChef.work();
    sousChef.work();

    std::cout << "Total earnings of " << waiter.getType() << ": R" << waiter.getTotalEarnings() << std::endl;

    return 0;
}
