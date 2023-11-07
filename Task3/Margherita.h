#ifndef MARGHERITA_H
#define MARGHERITA_H

#include "Pizza.h"
#include "Toppings.h"

/**
 * @class Margherita
 * @brief A class representing a Margherita pizza with customizable toppings.
 */
class Margherita : public Pizza {
public:
    /**
     * Constructor for the Margherita class.
     * @param toppings Reference to the Toppings class to set up the Margherita pizza.
     */
    Margherita(Toppings& toppings);

    /**
     * Function to add a topping to the Margherita pizza.
     * @param topping The name of the topping to add.
     */
    void addTopping(const std::string& topping);

    /**
     * Function to remove a topping from the Margherita pizza.
     * @param topping The name of the topping to remove.
     */
    void removeTopping(const std::string& topping);

    /**
     * Function to list the toppings on the Margherita pizza.
     * @return A vector of strings containing the names of toppings.
     */
    std::vector<std::string> listToppings() const;
};

#endif
