#ifndef SOUSCHEF_H
#define SOUSCHEF_H

#include "Chef.h"
#include <string>
/**
 * @brief Class representing a sous chef.
 */
class SousChef : public Chef {
public:
    /**
     * @brief Constructs a SousChef object with a given name.
     * @param name The name of the sous chef.
     */
    SousChef(const std::string& type);

    /**
     * @brief Returns the type of the employee.
     * @return The type of the employee (e.g., "Sous Chef").
     */
    std::string getType() const override;
};

#endif