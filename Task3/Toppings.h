#ifndef TOPPINGS_H
#define TOPPINGS_H

#include <string>
#include <vector>
#include <map>

/**
 * @class Toppings
 * @brief A class to manage and describe a list of pizza toppings.
 */
class Toppings {
public:
    /**
     * Constructor for Toppings class.
     */
    Toppings();

    /**
     * Function to add a topping to the list of available toppings.
     * @param topping The name of the topping to add.
     * @param price The price of the topping.
     */
    void addTopping(const std::string& topping, double price);

    /**
     * Function to remove a topping from the list of available toppings.
     * @param topping The name of the topping to remove.
     */
    void removeTopping(const std::string& topping);

    /**
     * Function to list the available toppings.
     * @return A vector of strings containing the names of available toppings.
     */
    std::vector<std::string> listToppings() const;

    /**
     * Function to get the description of a topping.
     * @param topping The name of the topping for which you want the description.
     * @return A string describing the specified topping.
     */
    std::string getToppingDescription(const std::string& topping) const;

    /**
     * Function to get the price of a topping.
     * @param topping The name of the topping for which you want the price.
     * @return The price of the specified topping.
     */
    double getToppingPrice(const std::string& topping) const;
    void displayToppingPrices() const;


private:
    std::vector<std::string> availableToppings;
    std::map<std::string, std::string> toppingDescriptions;
    std::map<std::string, double> toppingPrices;
    //Toppings toppings;


};

#endif
