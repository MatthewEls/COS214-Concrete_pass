#ifndef PIZZA_H
#define PIZZA_H

#include "Menu.h"
#include "Toppings.h"
#include <vector>
#include <string>

/**
 * @class Pizza
 * @brief A class representing a pizza menu item.
 */
class Pizza : public MenuItem {
public:
    /**
     * Constructor for Pizza class.
     * @param itemType The type of pizza (e.g., "Margherita").
     * @param basePrice The base price of the pizza.
     * @param toppings Reference to the Toppings class to query topping prices.
     */
    Pizza(const std::string& itemType, double basePrice, Toppings& toppings);

    /**
     * Get the description of the pizza.
     * @return The type of pizza (e.g., "Margherita").
     */
    std::string getItemType() const override;

    /**
     * Get the price of the pizza.
     * @return The total price of the pizza including toppings.
     */
    double getPrice() const override;
    double getPriceTotal() const;

    /**
     * Function to add a topping to the pizza.
     * @param topping The name of the topping to add.
     */
    void addTopping(const std::string& topping);

    /**
     * Function to remove a topping from the pizza.
     * @param topping The name of the topping to remove.
     */
    void removeTopping(const std::string& topping);

    /**
     * Function to list the toppings on the pizza.
     * @return A vector of strings containing the names of toppings.
     */
    std::vector<std::string> listToppings() const;

private:
    std::string itemType; /**< The type of pizza. */
    double basePrice; /**< The base price of the pizza. */
    std::vector<std::string> pizzaToppings; /**< The list of toppings on the pizza. */
    Toppings& toppings; /**< Reference to the Toppings class for topping prices. */
};

#endif
