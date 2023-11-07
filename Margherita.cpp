#include "Margherita.h"

Margherita::Margherita(Toppings& toppings) : Pizza("Margherita Pizza", 93.90, toppings) {
    // Set the description and base price using the base class constructor.

    // Initialize the hardcoded toppings.
    addTopping("Mozzarella");
    addTopping("Napolitana Sauce");
    addTopping("Feta");
    addTopping("Garlic");
}

void Margherita::addTopping(const std::string& topping) {
    // Allow adding new toppings to the Margherita pizza.
    Pizza::addTopping(topping);
}

void Margherita::removeTopping(const std::string& topping) {
    // Allow removing toppings from the Margherita pizza.
    Pizza::removeTopping(topping);
}

std::vector<std::string> Margherita::listToppings() const {
    // List toppings on the Margherita pizza.
    return Pizza::listToppings();
}
