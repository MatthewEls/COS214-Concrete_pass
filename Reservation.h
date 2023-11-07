/**
 * @file Reservation.h
 * @brief This file contains the declaration of the Reservation class, which represents a reservation made by a customer for a table at a restaurant.
 */

#pragma once

#include <string>
#include "Table.h"

class Customer; // Forward declaration of Customer class

/**
 * @brief The Reservation class represents a reservation made by a customer for a table at a restaurant.
 */
class Reservation {
public:
    /**
     * @brief Constructs a new Reservation object.
     * 
     * @param customer A pointer to the Customer who made the reservation.
     * @param table A pointer to the Table that was reserved.
     * @param reservationTime The time at which the reservation was made.
     */
    Reservation(Customer* customer, Table* table, const std::string& reservationTime);
    
    /**
     * @brief Returns a const pointer to the Customer who made the reservation.
     * 
     * @return const Customer* A const pointer to the Customer who made the reservation.
     */
    const Customer* getCustomer() const;
    
    /**
     * @brief Returns a pointer to the Table that was reserved.
     * 
     * @return Table* A pointer to the Table that was reserved.
     */
    Table* getTable() const;
    
    /**
     * @brief Returns a const reference to the time at which the reservation was made.
     * 
     * @return const std::string& A const reference to the time at which the reservation was made.
     */
    const std::string& getReservationTime() const;

private:
    Customer* customer; /**< A pointer to the Customer who made the reservation. */
    Table* table; /**< A pointer to the Table that was reserved. */
    std::string reservationTime; /**< The time at which the reservation was made. */
};
