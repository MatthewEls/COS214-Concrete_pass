#ifndef CHEF_H
#define CHEF_H

#include "Employee.h"
#include <string>
/**
 * @brief Class representing a chef in a restaurant.
 */
class Chef : public Employee {
public:
    /**
     * @brief Constructs a Chef object with a given name.
     * @param name The name of the chef.
     */
    Chef(const std::string& type);

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