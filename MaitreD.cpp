#include "MaitreD.h"
#include "Table.h"
#include "TableComposite.h"
#include "Reservation.h"  // Include Reservation's full definition
#include <iostream>
using namespace std;

MaitreD::MaitreD(){}

MaitreD::MaitreD(const std::vector<Table>& tables) : tables(tables) {}

// Add tables to MaitreD
void MaitreD::addTablesToMaitreD(const std::vector<Table>& tables) {
    this->tables = tables;
}



Table* MaitreD::findAvailableTable(int partySize) {
    // First, let's find a single available table that can accommodate the party size
    for (Table& table : tables) {
        if (table.isAvailable() && table.getMaxCapacity() >= partySize) {
            cout << "Table " << table.getName() << " is available" << endl;
            table.seatTable(partySize); 
            return &table;
        }
    }

   for (size_t i = 0; i < tables.size(); ++i) {
    int combinedCapacity = 0;
    vector<Table*> availableTables;

    // Find a group of available tables that can accommodate the party size
    for (size_t j = i; j < tables.size(); ++j) {
        if (tables[j].isAvailable()) /*&& (combinedCapacity + tables[j].getMaxCapacity()) >= partySize)*/ {
            combinedCapacity += tables[j].getMaxCapacity();
            //cout<<"combinrd "<<combinedCapacity<<endl;
            availableTables.push_back(&tables[j]);
        }
        if (combinedCapacity >= partySize) {
            //cout<<"COMBINED CAPACITY: "<<combinedCapacity<<endl;
            break;
        }
        // else
        // {
        //     cout<<"COMBINED CAPACITY: "<<combinedCapacity<<endl;
        // }
        
    }

    // If we found a set of tables that can fit the party size, create a composite table
    if (combinedCapacity >= partySize) {
        TableComposite* compositeTable = new TableComposite("Composite Table");
        for (Table* table : availableTables) {
            compositeTable->addTable(table);
            // Seat each individual table in the composite
        }
         compositeTable->seatTable(partySize);

        cout << "Composite Table created by joining the following tables: ";
        for (Table* table : availableTables) {
            cout << table->getName() << " ";
        }
        cout << endl;

        return compositeTable;
    }
}


    // If no available tables can accommodate the party size, return nullptr
    cout << "No table available for a party of " << partySize << endl;
    return nullptr;
}

void MaitreD::addCustomerWithReservation(const Reservation& reservation) {
    reservations.push_back(reservation);
}

void MaitreD::displayAvailableTables() {
    cout << "Available Tables:" << endl;
    for (Table& table : tables) {
        if (table.isAvailable()) {
            cout << table.getName() << endl;
        }
    }
}

void MaitreD::displayReservations() const {
    cout << "Reservations:" << endl;
    for (const Reservation& reservation : reservations) {
        cout << "Table: " << reservation.getTable()->getName() << ", Time: " << reservation.getReservationTime() << endl;
    }
}
#include "Customer.h"
