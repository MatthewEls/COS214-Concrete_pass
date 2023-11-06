#pragma once
#include "BookingStrategy.h"
#include "Table.h"
#include "TableComposite.h"
#include "Reservation.h"
#include "ReservationStrategy.h"
#include <vector>
#include <string>

class WalkInStrategy : public BookingStrategy
{

public:
    WalkInStrategy(const std::vector<Table> &tables);
    Table *findAvailableTable(int partySize) override;
    void addReservation(const Reservation &reservation) override;
    void displayAvailableTables() override;
    //string getCurrentTime();

    


private:
    std::vector<Table> tables;
    std::vector<Reservation> reservations;
};