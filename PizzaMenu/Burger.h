#ifndef BURGER_H
#define BURGER_H

#include "Menu.h"

/**
 * @class Burger
 * @brief A class representing a burger menu item.
 */
class Burger : public MenuItem {
public:
    /**
     * Constructor for Burger class.
     * @param description The description of the burger.
     * @param basePrice The base price of the burger.
     */
    Burger(std::string ItemType, double basePrice);

    /**
     * Get the description of the burger.
     * @return A string describing the burger.
     */
    std::string getItemType() const override;

    /**
     * Get the price of the burger.
     * @return The price of the burger.
     */
    double getPrice() const override;
private:
    std::string ItemType; /**< The description of the burger. */
    double basePrice; /**< The base price of the burger. */
};

#endif
