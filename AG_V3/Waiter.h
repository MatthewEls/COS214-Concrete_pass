#ifndef WAITER_H
#define WAITER_H

#include "Employee.h"
#include "Table.h"
#include "Meal.h"

//class Table;THIS
#include <string>
/**
 * @brief Class representing a waiter in a restaurant.
 */
class Waiter : public Employee , public Observer{
private:
    double salary;
    double tips;
    Table* assignedTable;

public:
    /**
     * @brief Constructs a Waiter object with a given name and salary.
     * @param name The name of the waiter.
     * @param salary The salary of the waiter.
     */
    Waiter(const std::string& type, double salary);

    /**
     * @brief Sets the tips earned by the waiter.
     * @param tips The tips earned by the waiter.
     */
    void setTips(double tips);

    void assignTable(Table* table);

    /**
     * @brief Gets the total earnings of the waiter (salary + tips).
     * @return The total earnings of the waiter.
     */
    double getTotalEarnings() const;

    /**
     * @brief Represents the work done by the waiter (taking care of a table).
     */
    void work() override;

    /**
     * @brief Returns the type of the employee.
     * @return The type of the employee (e.g., "Waiter").
     */
    std::string getType() const override;
    void serveTable();
    void returnMeal(Meal*m);
    Table* getTable();
    void update() override;
    
};

#endif