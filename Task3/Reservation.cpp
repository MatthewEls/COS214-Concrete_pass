#include "Reservation.h"
#include "Customer.h" // Include the full Customer.h for definition
#include "Table.h"

Reservation::Reservation(Customer* customer, Table* table, const std::string& reservationTime)
    : customer(customer), table(table), reservationTime(reservationTime) {}

const Customer* Reservation::getCustomer() const {
    return customer;
}

Table* Reservation::getTable() const {
    return table;
}

const std::string& Reservation::getReservationTime() const {
    return reservationTime;
}


