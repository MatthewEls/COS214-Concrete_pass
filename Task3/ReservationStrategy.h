#pragma once
#include <vector>
#include "BookingStrategy.h"
#include "Table.h"
#include "TableComposite.h"
#include "Reservation.h"

class ReservationStrategy : public BookingStrategy
{

public:
    ReservationStrategy(const std::vector<Table> &tables);
    Table *findAvailableTable(int partySize) override;
    void addReservation(const Reservation &reservation) override;
    void displayAvailableTables() override;

private:
    std::vector<Table> tables;
    std::vector<Reservation> reservations;
};