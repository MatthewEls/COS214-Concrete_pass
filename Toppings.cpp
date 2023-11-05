#include "Toppings.h"
#include <algorithm> // Include this for std::find

Toppings::Toppings() {
    // Initialize the list of available toppings, their descriptions, and prices.
    availableToppings = {
        "Mozzarella",
        "Mince",
        "Mayo",
        "BBQ Sauce",
        "Napolitana Sauce",
        "Bacon",
        "Feta",
        "Figs",
        "Mushrooms",
        "Olives",
        "Garlic"
    };

    toppingDescriptions = {
        {"Mozzarella", "Fresh mozzarella cheese"},
        {"Mince", "Ground beef or meat"},
        {"Mayo", "Mayonnaise"},
        {"BBQ Sauce", "Barbecue sauce"},
        {"Napolitana Sauce", "Napolitana tomato sauce"},
        {"Bacon", "Crispy bacon strips"},
        {"Feta", "Crumbled feta cheese"},
        {"Figs", "Fresh figs"},
        {"Mushrooms", "Sliced mushrooms"},
        {"Olives", "Assorted olives"},
        {"Garlic", "Roasted garlic cloves"}
    };

    toppingPrices = {
        {"Mozzarella", 8.0},
        {"Mince", 20.0},
        {"Mayo", 3.5},
        {"BBQ Sauce", 3.5},
        {"Napolitana Sauce", 3.0},
        {"Bacon", 15.8},
        {"Feta", 8.0},
        {"Figs", 26.17},
        {"Mushrooms", 18.5},
        {"Olives", 6.26},
        {"Garlic", 3.14}
    };
}


void Toppings::addTopping(const std::string& topping, double price) {
    // Check if the topping is not already in the list.
    if (std::find(availableToppings.begin(), availableToppings.end(), topping) == availableToppings.end()) {
        availableToppings.push_back(topping);
        // Optionally, you can provide a default description for the new topping here.
        toppingDescriptions[topping] = "Custom topping";
        // Set the price for the new topping.
        toppingPrices[topping] = price;
    }
}


void Toppings::removeTopping(const std::string& topping) {
    auto it = std::find(availableToppings.begin(), availableToppings.end(), topping);
    if (it != availableToppings.end()) {
        // Remove the topping from the list of available toppings.
        availableToppings.erase(it);
        // Remove the corresponding description and price.
        toppingDescriptions.erase(topping);
        toppingPrices.erase(topping);
    }
}



std::vector<std::string> Toppings::listToppings() const {
    return availableToppings;
}



std::string Toppings::getToppingDescription(const std::string& topping) const {
    // Retrieve the description for the specified topping.
    auto it = toppingDescriptions.find(topping);
    if (it != toppingDescriptions.end()) {
        return it->second;
    }
    return "Description not available for this topping.";
}



double Toppings::getToppingPrice(const std::string& topping) const {
    // Retrieve the price for the specified topping.
    auto it = toppingPrices.find(topping);
    if (it != toppingPrices.end()) {
        return it->second;
    }
    return 0.0; // Return 0.0 if the price is not found.
}

