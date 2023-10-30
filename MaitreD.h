#ifndef MAITRED_H
#define MAITRED_H

#include "Employee.h"
#include "Waiter.h"
#include <string>

/**
 * @brief Class representing a MaitreD in a restaurant.
 */
class MaitreD : public Employee {
public:
    /**
     * @brief Constructs a MaitreD object with a given name.
     * @param name The name of the MaitreD.
     */
    MaitreD(const std::string& type);

    /**
     * @brief Assigns a waiter to a table.
     * @param waiter The waiter to be assigned.
     * @param tableNumber The table number.
     */
    void assignWaiterToTable(Waiter* waiter, int tableNumber);

    /**
     * @brief Represents the work done by the MaitreD.
     */
    void work() override;

    /**
     * @brief Gets the type of the maitreD.
     * @return The type of the maitreD.
     */
    std::string getType() const override;
};

#endif
