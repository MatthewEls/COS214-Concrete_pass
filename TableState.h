// TableState.h
#pragma once

class Table;

/**
 * @class TableState
 * @brief Abstract base class for table states.
 */
class TableState {
public:
    /**
     * @brief Attempt to seat a party at the table.
     * @param table The table to seat.
     */
    virtual void seatTable(Table& table) = 0;

    /**
     * @brief Mark the table as free.
     * @param table The table to free.
     */
    virtual void freeTable(Table& table) = 0;

    /**
     * @brief Check if the table is available for seating.
     * @return true if the table is available, false otherwise.
     */
    virtual bool isAvailable() = 0;

    
};



