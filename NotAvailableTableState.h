#pragma once
#include "TableState.h"

/**
 * @class NotAvailableTableState
 * @brief Represents the not available state of a table.
 */
/**
 * @brief The NotAvailableTableState class represents the state of a table that is not available for seating.
 * 
 */
class NotAvailableTableState : public TableState {
public:
    /**
     * @brief Seats the table.
     * 
     * @param table The table to be seated.
     */
    void seatTable(Table& table) override;

    /**
     * @brief Frees the table.
     * 
     * @param table The table to be freed.
     */
    void freeTable(Table& table) override;

    /**
     * @brief Checks if the table is available.
     * 
     * @return false, as the table is not available.
     */
    bool isAvailable() override;
};
