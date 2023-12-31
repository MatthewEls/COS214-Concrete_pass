#pragma once

#include <vector>
#include <string>
#include "Table.h"
#include "Reservation.h" 
#include "ReservationStrategy.h" // Include Reservation's full definition
//#include "WalkIn.h"
class WalkIn;
/**
 * @brief The MaitreD class represents the restaurant manager who manages the tables and reservations.
 * 
 */
class MaitreD {
public:
    /**
     * @brief Construct a new Maitre D object with the given tables.
     * 
     * @param tables The vector of tables to be managed.
     */
    MaitreD(BookingStrategy* strategy);
    MaitreD();

    /**
     * @brief Find an available table for a given party size.
     * 
     * @param partySize The size of the party.
     * @return Table* A pointer to the available table, or nullptr if no table is available.
     */
    Table* findAvailableTable(int partySize);

    /**
     * @brief Add a customer with a reservation to the list of reservations.
     * 
     * @param reservation The reservation to be added.
     */
    void addCustomerWithReservation(const Reservation& reservation);

    void addCustomerWithWalkIn(const WalkIn& walkIn);

    /**
     * @brief Display the available tables.
     * 
     */
    void displayAvailableTables();

    /**
     * @brief Display the list of reservations.
     * 
     */
    void displayReservations() const;
    void displayWalkIns() const;

private:
    std::vector<Table> tables; ///< The vector of tables managed by the MaitreD.
    std::vector<Reservation> reservations; ///< The vector of reservations managed by the MaitreD.
    BookingStrategy* strategy;
    std::vector<WalkIn> walkIns;
};
