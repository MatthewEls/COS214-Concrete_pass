// Table.h
#pragma once
#include <string>
#include "TableState.h"
//#include "Waiter.h"
class Waiter;
/**
 * @class Table
 * @brief Represents a table in a restaurant.
 */
class Table {
private:
    TableState* state; /**< The current state of the table. */
    std::string name; /**< The name of the table. */
    int maxCapacity = 4; /**< The maximum party size this table can accommodate. */
    Waiter* servingWaiter;
    
public:
    /**
     * @brief Constructor for the Table class.
     * @param tableName The name of the table.
     */
    Table(const std::string& tableName);

    /**
     * @brief Attempt to seat a party at the table.
     * @param partySize The size of the party to be seated.
     */
    virtual void seatTable(int partySize);

    /**
     * @brief Mark the table as free.
     */
    virtual void freeTable();

    /**
     * @brief Check if the table is available for seating.
     * @return true if the table is available, false otherwise.
     */
    virtual bool isAvailable();

    /**
     * @brief Get the name of the table.
     * @return The name of the table.
     */
    const std::string& getName() const;

    /**
     * @brief Get the maximum party size this table can accommodate.
     * @return The maximum party size.
     */
    int getMaxCapacity();

    /**
     * @brief Set the state of the table.
     * @param newState The new state to set.
     */
    void setState(TableState* newState);

    void setWaiter(Waiter* waiter);
    bool isWaiterAssigned();
    Waiter* getWaiter();

    virtual void seatTableComp(int partySize);

    /**
     * @brief Destructor for the Table class.
     */
    ~Table();


    // Custom assignment operator
    Table& operator=(const Table& other) {
        if (this == &other) {
            // Self-assignment, no need to do anything
            return *this;
        }

        // Copy non-static const members
        this->maxCapacity = other.maxCapacity;
        
        // Copy other members as well
        // Make sure to copy all members individually
        
        return *this;
    }
};
