#include "WalkInStrategy.h"
#include <iostream>

using namespace std;

WalkInStrategy::WalkInStrategy(const std::vector<Table>& tables)
    : tables(tables) {}

Table* WalkInStrategy::findAvailableTable(int partySize) {
    // Implement the strategy for walk-in customers
    // Similar to ReservationStrategy but with different logic

    // Example: Find available tables for walk-ins
    for (Table& table : tables) {
        if (table.isAvailable() && table.getMaxCapacity() >= partySize) {
            cout << "Table " << table.getName() << " is available for walk-in" << endl;
            table.seatTable(partySize);
            return &table;
        }
    }


 for (size_t i = 0; i < tables.size(); ++i)
    {
        int combinedCapacity = 0;
        vector<Table *> availableTables;

        // Find a group of available tables that can accommodate the party size
        for (size_t j = i; j < tables.size(); ++j)
        {
            if (tables[j].isAvailable()) /*&& (combinedCapacity + tables[j].getMaxCapacity()) >= partySize)*/
            {
                combinedCapacity += tables[j].getMaxCapacity();
                // cout<<"combinrd "<<combinedCapacity<<endl;
                availableTables.push_back(&tables[j]);
            }
            if (combinedCapacity >= partySize)
            {
                // cout<<"COMBINED CAPACITY: "<<combinedCapacity<<endl;
                break;
            }
            // else
            // {
            //     cout<<"COMBINED CAPACITY: "<<combinedCapacity<<endl;
            // }
        }

        // If we found a set of tables that can fit the party size, create a composite table
        if (combinedCapacity >= partySize)
        {
            TableComposite *compositeTable = new TableComposite("Composite Table");
            for (Table *table : availableTables)
            {
                compositeTable->addTable(table);
                // Seat each individual table in the composite
            }
            compositeTable->seatTable(partySize);

            cout << "Composite Table created by joining the following tables: ";
            for (Table *table : availableTables)
            {
                cout << table->getName() << " ";
            }
            cout << endl;

            return compositeTable;
        }
    }

    return nullptr; // Return nullptr if no table is available for walk-ins
}

void WalkInStrategy::addReservation(const Reservation& reservation) {
    reservations.push_back(reservation);
}

void WalkInStrategy::displayAvailableTables() {
    cout << "Available Tables:" << endl;
    for (Table& table : tables) {
        if (table.isAvailable()) {
            cout << table.getName() << "\t";
        }

    }
    cout<<endl;
}

// string WalkInStrategy::getCurrentTime() {
//     // Implement logic to get the current time (e.g., use a library to get the current time)
//     return "2023-10-31 19:45"; // Example time format
// }