#include "Miami.h"

Miami::Miami(Toppings& toppings) : Pizza("Miami Pizza", 110.50, toppings) {
    // Set the description and base price using the base class constructor.

    // Initialize the hardcoded toppings.
    addTopping("Bacon");
    addTopping("Feta");
}

void Miami::addTopping(const std::string& topping) {
    // Allow adding new toppings to the Miami pizza.
    Pizza::addTopping(topping);
}

void Miami::removeTopping(const std::string& topping) {
    // Allow removing toppings from the Miami pizza.
    Pizza::removeTopping(topping);
}

std::vector<std::string> Miami::listToppings() const {
    // List toppings on the Miami pizza.
    return Pizza::listToppings();
}
