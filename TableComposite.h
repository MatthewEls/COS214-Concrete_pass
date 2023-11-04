// TableComposite.h
#pragma once
#include <vector>
#include "Table.h"

/**
 * @class TableComposite
 * @brief Represents a group of joined tables as a composite table.
 */
class TableComposite : public Table {
private:
    std::vector<Table*> joinedTables; /**< The individual tables that form the composite table. */

public:
    /**
     * @brief Constructor for the TableComposite class.1
     * @param name The name of the composite table.
     */
    TableComposite(const std::string& name);

    /**
     * @brief Add an individual table to the composite table.
     * @param table The individual table to add.
     */
    void addTable(Table* table);

    /**
     * @brief Attempt to seat a party at the composite table.
     * @param partySize The size of the party to be seated.
     */
    void seatTable(int partySize) override;

    /**
     * @brief Mark the composite table as free.
     */
    void freeTable() override;

    /**
     * @brief Check if the composite table is available for seating.
     * @return true if the composite table is available, false otherwise.
     */
    bool isAvailable() override;

    /**
     * @brief Check if the composite table can accommodate a party of a given size.
     * @param partySize The size of the party to be seated.
     * @return true if the party can be accommodated, false otherwise.
     */
    bool canJoin(int partySize) const;
      ~TableComposite();
};
