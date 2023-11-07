#ifndef GODFATHER_H
#define GODFATHER_H

#include "Pizza.h"
#include "Toppings.h"

/**
 * @class Godfather
 * @brief A class representing a Godfather pizza with customizable toppings.
 */
class Godfather : public Pizza {
public:
    /**
     * Constructor for the Godfather class.
     * @param toppings Reference to the Toppings class to set up the Godfather pizza.
     */
    Godfather(Toppings& toppings);

    /**
     * Function to add a topping to the Godfather pizza.
     * @param topping The name of the topping to add.
     */
    void addTopping(const std::string& topping);

    /**
     * Function to remove a topping from the Godfather pizza.
     * @param topping The name of the topping to remove.
     */
    void removeTopping(const std::string& topping);

    /**
     * Function to list the toppings on the Godfather pizza.
     * @return A vector of strings containing the names of toppings.
     */
    std::vector<std::string> listToppings() const;
};

#endif
