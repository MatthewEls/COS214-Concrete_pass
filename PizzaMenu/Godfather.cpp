#include "Godfather.h"

/*Godfather::Godfather() : Pizza("The Godfather Pizza", 140.70) {
    // Set the description and base price using the base class constructor.
    // The base class constructor now requires itemType and basePrice as parameters.

    // Initialize the hardcoded toppings.
    addTopping("Mince");
    addTopping("BBQ Sauce");
    addTopping("Mushrooms");
    addTopping("Mozzarella");
}*/

Godfather::Godfather(Toppings& toppings) : Pizza("The Godfather Pizza", 140.70, toppings) {
    // Set the description and base price using the base class constructor.

    // Initialize the hardcoded toppings.
    addTopping("Mozzarella");
    addTopping("BBQ Sauce");
    addTopping("Mushrooms");
    addTopping("Mince");
}

void Godfather::addTopping(const std::string& topping) {
    // Allow adding new toppings to the Godfather pizza.
    Pizza::addTopping(topping);
}

void Godfather::removeTopping(const std::string& topping) {
    // Allow removing toppings from the Godfather pizza.
    Pizza::removeTopping(topping);
}

std::vector<std::string> Godfather::listToppings() const {
    // List toppings on the Godfather pizza.
    return Pizza::listToppings();
}
