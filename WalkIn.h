#pragma once

#include <string>
#include "MaitreD.h"
#include "Table.h"

class WalkIn {
public:
    WalkIn(const std::string& name, int partySize,Table* table);

    bool makeWalkInReservation();
    std::string getName() const;
    std::string getPartySize()const;
    Table* getTable() const;

private:
    std::string getCurrentTime();

private:
    std::string name;
    int partySize;
    MaitreD* maitreD;
    std::string walkInTime;
    Table* table;
};

