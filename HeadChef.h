#ifndef HEADCHEF_H
#define HEADCHEF_H

#include "Employee.h"
#include <string>
/**
 * @brief Class representing a HeadChef in a restaurant.
 */
class HeadChef : public Employee {
public:
    /**
     * @brief Constructs a HeadChef object with a given name.
     * @param name The name of the headchef.
     */
    HeadChef(const std::string& name);

    /**
     * @brief Represents the work done by the chef (making food).
     */
    void work() override;

    /**
     * @brief Returns the type of the employee.
     * @return The type of the employee (e.g., "Chef").
     */
    std::string getType() const override;
};

#endif