#ifndef DRINKSCHEF_H
#define DRINKSCHEF_H

#include "Chef.h"
#include <string>
/**
 * @brief Class representing a drinks chef.
 */
class DrinksChef : public Chef {
public:
    /**
     * @brief Constructs a DrinksChef object with a given name.
     * @param name The name of the drinks chef.
     */
    DrinksChef(const std::string& type);

    /**
     * @brief Returns the type of the employee.
     * @return The type of the employee (e.g., "Drinks Chef").
     */
    std::string getType() const override;
};

#endif