#include "WalkIn.h"
#include "Table.h"
#include "TableComposite.h"
#include <iostream>
using namespace std;

WalkIn::WalkIn(const std::string& name, int partySize, MaitreD* maitreD)
    : name(name), partySize(partySize), maitreD(maitreD), walkInTime(getCurrentTime()) {}

bool WalkIn::makeWalkInReservation() {
    Table* availableTable = maitreD->findAvailableTable(partySize);

    if (availableTable) {
        std::cout << "Walk-in customer " << name << " seated at " << availableTable->getName() << " at " << walkInTime << std::endl;
        return true;
    } else {
        //std::cout << "No available table for a party of " << partySize << std::endl;
        return false;
    }
}

std::string WalkIn::getCurrentTime() {
    // Implement logic to get the current time (e.g., use a library to get the current time)
    return "2023-10-31 19:45"; // Example time format
}
