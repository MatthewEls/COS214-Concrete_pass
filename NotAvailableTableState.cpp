// NotAvailableTableState.cpp
#include <iostream>
#include "NotAvailableTableState.h"
#include "AvailableTableState.h"
#include "Table.h"
using namespace std;

void NotAvailableTableState::seatTable(Table& table) {
    // Implement the behavior for seating a party at a not available table
    // Example: Provide a message or additional behavior
    // In a real system, you might check if joining tables is possible
    cout<<"THE TABLE IS ALREADY TAKEN"<<endl;
}

void NotAvailableTableState::freeTable(Table& table) {
    // Implement the behavior for freeing a table
    // Example: Update table status to available
    table.setState(new AvailableTableState());
}

bool NotAvailableTableState::isAvailable() {
    return false; // Not available state, return false
}
