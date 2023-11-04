#pragma once
#include "TableState.h"

/**
 * @class AvailableTableState
 * @brief Represents the available state of a table.
 */
class AvailableTableState : public TableState {
public:
    void seatTable(Table& table) override;
    void freeTable(Table& table) override;
    bool isAvailable() override;
};