#ifndef WALKIN_H
#define WALKIN_H

#include "MaitreD.h"

class WalkIn {
public:
    WalkIn(const std::string& name, int partySize, MaitreD* maitreD);

    bool makeWalkInReservation();

private:
    std::string getCurrentTime();

private:
    std::string name;
    int partySize;
    MaitreD* maitreD;
    std::string walkInTime;
};

#endif
