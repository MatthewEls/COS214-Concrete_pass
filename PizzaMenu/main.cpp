#include <iostream>
#include "Menu.h"
#include "Toppings.h"
#include "Pizza.h"
#include "Godfather.h"
#include "Margherita.h"
#include "Miami.h"

int main() {
    // Create a Toppings object to manage toppings.
    Toppings toppings;

    // Create instances of different pizza types.
    Godfather godfatherPizza(toppings);
    Margherita margheritaPizza(toppings);
    Miami miamiPizza(toppings);

    std::cout << "Instantiation/Creation of the 3 different base pizza types. " <<std::endl;
    std::cout << std::endl;

    Menu menu;
    menu.addItem(&godfatherPizza);
    menu.addItem(&margheritaPizza);
    menu.addItem(&miamiPizza);
    menu.displayMenu();
    std::cout << std::endl;

    // Add additional toppings to the pizzas.
    std::cout << "Adding additional toppings." <<std::endl;
    std::cout << std::endl;

    godfatherPizza.addTopping("Olives");
    margheritaPizza.addTopping("Basil");
    miamiPizza.addTopping("Mushrooms");

    // Display the menu, with the new toppings
    menu.addItem(&godfatherPizza);
    menu.addItem(&margheritaPizza);
    menu.addItem(&miamiPizza);
    menu.displayMenu();
    std::cout << std::endl;
    

    // Example: Get the description, price, and toppings of a specific pizza.
    std::cout << std::endl;
    std::cout << "\nDescription: " << godfatherPizza.getItemType() << std::endl;
    std::vector<std::string> godfatherToppings = godfatherPizza.listToppings();
    std::cout << "Additional Toppings (included in current price):\n";
    for (const std::string& topping : godfatherToppings) {
        double toppingPrice = toppings.getToppingPrice(topping); // Get the topping price.
        std::cout << topping << " (+ R" << toppingPrice << ")\n";
    }
    std::cout << std::endl;

    return 0;
}
