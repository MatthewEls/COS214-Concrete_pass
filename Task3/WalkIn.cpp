#include "WalkIn.h"
#include "Table.h"
#include "TableComposite.h"
#include <iostream>
using namespace std;

WalkIn::WalkIn(const std::string& name, int partySize, Table* table)
    : name(name), partySize(partySize), table(table){}

bool WalkIn::makeWalkInReservation() {
    return true;
    
}

std::string WalkIn::getCurrentTime() {
    // Implement logic to get the current time (e.g., use a library to get the current time)
    return "2023-10-31 19:45"; // Example time format
}

string WalkIn::getName()const {
    return name;
}

string WalkIn::getPartySize() const {
    return to_string(partySize);
}

Table* WalkIn::getTable() const {
    return table;
}
