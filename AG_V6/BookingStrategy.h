// ReservationStrategy.h
#pragma once

class Reservation;
class Table;

class BookingStrategy {
public:
    virtual Table* findAvailableTable(int partySize) = 0;
    virtual void addReservation(const Reservation& reservation) = 0;
    virtual void displayAvailableTables() = 0;
};
