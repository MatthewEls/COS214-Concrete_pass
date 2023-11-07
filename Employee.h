#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
/**
 * @brief Abstract base class for employees in a restaurant.
 */
class Employee {
protected:
    std::string type;

public:
    Employee(const std::string& type);
    
    /**
     * @brief Virtual function representing the work done by the employee.
     */
    virtual void work() = 0;

    /**
     * @brief Returns the type of the employee.
     * @return The type of the employee (e.g., "Employee").
     */
    virtual std::string getType() const;

};

#endif