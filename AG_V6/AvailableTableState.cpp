// AvailableTableState.cpp
#include <iostream>
#include "AvailableTableState.h"
#include "NotAvailableTableState.h"
#include "Table.h"
using namespace std;

/**
 * This method is responsible for seating a party at an available table.
 * It updates the table status to "Not Available" by changing the state of the table to NotAvailableTableState.
 * It also outputs a message to the console indicating that the table is now not available.
 * 
 * @param table The table to be seated.
 */
void AvailableTableState::seatTable(Table &table)
{
    // Implement the behavior for seating a party at an available table
    // Example: Update table status
    table.setState(new NotAvailableTableState());
    cout << "TABLE NOW NOT AVAILABLE" << endl;
}

/**
 * @brief Frees a table by updating its status to available.
 * 
 * @param table The table to be freed.
 */
void AvailableTableState::freeTable(Table &table)
{
    // Implement the behavior for freeing a table
    // Example: Update table status to available
    table.setState(this); // Set the state back to available
}

bool AvailableTableState::isAvailable()
{
    return true; // Available state, return true
}
