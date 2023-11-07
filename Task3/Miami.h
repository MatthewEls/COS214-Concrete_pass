#ifndef MIAMI_H
#define MIAMI_H

#include "Pizza.h"
#include "Toppings.h"

/**
 * @class Miami
 * @brief A class representing a Miami pizza with customizable toppings.
 */
class Miami : public Pizza {
public:
    /**
     * Constructor for the Miami class.
     * @param toppings Reference to the Toppings class to set up the Miami pizza.
     */
    Miami(Toppings& toppings);

    /**
     * Function to add a topping to the Miami pizza.
     * @param topping The name of the topping to add.
     */
    void addTopping(const std::string& topping);

    /**
     * Function to remove a topping from the Miami pizza.
     * @param topping The name of the topping to remove.
     */
    void removeTopping(const std::string& topping);

    /**
     * Function to list the toppings on the Miami pizza.
     * @return A vector of strings containing the names of toppings.
     */
    std::vector<std::string> listToppings() const;
};

#endif
