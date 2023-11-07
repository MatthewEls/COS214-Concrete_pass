#include "MaitreD.h"
#include "Table.h"
#include "TableComposite.h"
#include "Reservation.h" // Include Reservation's full definition#
#include "ReservationStrategy.h"
#include "WalkIn.h"
#include <iostream>
using namespace std;

MaitreD::MaitreD(BookingStrategy* strategy)
    : strategy(strategy) {}

MaitreD::MaitreD() {}

Table* MaitreD::findAvailableTable(int partySize) {
return strategy->findAvailableTable(partySize);
}
    

void MaitreD::addCustomerWithReservation(const Reservation& reservation) {
    reservations.push_back(reservation);
}

void MaitreD::addCustomerWithWalkIn(const WalkIn& walkIn) {
    walkIns.push_back(walkIn);
}

void MaitreD::displayAvailableTables() {
    strategy->displayAvailableTables();
}

void MaitreD::displayWalkIns() const {
    cout << "Walk Ins:" << endl;
    for (const WalkIn& walkIn : walkIns) {
        cout << "Name: " << walkIn.getName() << ", Party Size: " << walkIn.getPartySize() << endl;
    }
}

void MaitreD::displayReservations() const {
    cout << "Reservations:" << endl;
    for (const Reservation& reservation : reservations) {
        cout << "Table: " << reservation.getTable()->getName() << ", Time: " << reservation.getReservationTime() << endl;
    }
}

