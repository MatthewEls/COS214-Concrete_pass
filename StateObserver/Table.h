// Table.h
#pragma once
#include <string>
#include <vector>
#include "TableState.h"
#include "Waiter.h"
#include "Observer.h"
#include "CustomerState.h"

/**
 * @class Table
 * @brief Represents a table in a restaurant.
 */

class Waiter;

class Table {

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
    int getMaxCapacity() const;

    /**
     * @brief Set the state of the table.
     * @param newState The new state to set.
     */
    void setState(TableState* newState);


    virtual void seatTableComp(int partySize);

    /**
     * @brief Destructor for the Table class.
     */
    ~Table();

    ///Observr desgin pattern
    Table();
    void addObserver(Observer *observer);
    void changeState(CustomerState *newState);
    void notifyWaiters();
    void setBillAmount(double amount); // New method to set the bill amount

  private:
    TableState *state;         /**< The current state of the table. */
    std::string name;          /**< The name of the table. */
    const int maxCapacity = 4; /**< The maximum party size this table can accommodate. */

//     /// @brief Observer Pattern
//     tState* st;
//     std::vector<Waiter*> waiters;
     double billAmount;
    CustomerState *cState;
    std::vector<Observer *> observers;
};

// class Table::tState
// {
// public:
//     virtual void handle(Table *table) = 0;
// };

// class ReadyState : public Table::tState
// {
// public:
//     void handle(Table *table) override;
// };

// class NotReadyState : public Table::tState
// {
// public:
//     void handle(Table *table) override;
// };