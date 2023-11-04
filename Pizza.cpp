#include "Pizza.h"
#include <algorithm>

/**
 * Constructor for the Pizza class.
 * @param itemType The type of pizza (e.g., "Margherita").
 * @param basePrice The base price of the pizza.
 * @param toppings Reference to the Toppings class to query topping prices.
 */
Pizza::Pizza(const std::string& itemType, double basePrice, Toppings& toppings)
    : itemType(itemType), basePrice(basePrice), toppings(toppings) {
    // Constructor to set the type and base price.
}

/**
 * Get the description of the pizza.
 * @return The type of pizza (e.g., "Margherita").
 */
std::string Pizza::getItemType() const {
    return itemType;
}

/**
 * Get the price of the pizza.
 * @return The total price of the pizza including toppings.
 */
double Pizza::getPrice() const {
    // Calculate the total price by adding the base price and the prices of toppings.
    double totalPrice = basePrice;
    for (const std::string& topping : pizzaToppings) {
        // Retrieve the topping price from the Toppings class.
        double toppingPrice = toppings.getToppingPrice(topping);
        totalPrice += toppingPrice;
    }
    return totalPrice;
}

/**
 * Function to add a topping to the pizza.
 * @param topping The name of the topping to add.
 */
void Pizza::addTopping(const std::string& topping) {
    // Add the specified topping to the pizza.
    pizzaToppings.push_back(topping);
}

/**
 * Function to remove a topping from the pizza.
 * @param topping The name of the topping to remove.
 */
void Pizza::removeTopping(const std::string& topping) {
    // Remove the specified topping from the pizza.
    auto it = std::find(pizzaToppings.begin(), pizzaToppings.end(), topping);
    if (it != pizzaToppings.end()) {
        pizzaToppings.erase(it);
    }
}

/**
 * Function to list the toppings on the pizza.
 * @return A vector of strings containing the names of toppings.
 */
std::vector<std::string> Pizza::listToppings() const {
    // Return the list of toppings on the pizza.
    return pizzaToppings;
}
