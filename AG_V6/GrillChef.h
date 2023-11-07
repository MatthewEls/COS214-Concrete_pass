#ifndef GRILLCHEF_H
#define GRILLCHEF_H

#include "Chef.h"
#include <string>
/**
 * @brief Class representing a grill chef.
 */
class GrillChef : public Chef {
public:
    /**
     * @brief Constructs a GrillChef object with a given name.
     * @param name The name of the grill chef.
     */
    GrillChef(const std::string& type);

    /**
     * @brief Returns the type of the employee.
     * @return The type of the employee (e.g., "Grill Chef").
     */
    std::string getType() const override;
};

#endif