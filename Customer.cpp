#include "Customer.h"
// #include "MaitreD.h"
#include "Table.h"
#include "Reservation.h"
#include "OrderCommand.h" // Include Reservation's full definition
#include "oneBill.h"
#include "TabCalculator.h"
#include "StandardTabCalculator.h"
#include "HappyHourTabCalculator.h"
#include <iostream>
#include <string>
#include <regex>
#include <sstream>

using namespace std;

Customer::Customer(const std::string &name, int partySize, MaitreD *maitreD) : name(name), partySize(partySize), maitreD(maitreD) {}

const std::string &Customer::getName() const
{
    return name;
}

int Customer::getPartySize() const
{
    return partySize;
}

const std::vector<Reservation> &Customer::getReservations() const
{
    return reservations;
}

const std::vector<WalkIn> &Customer::getWalkIns() const
{
    return walkIns;
}

void Customer::makeReservation(int partySize, const std::string &reservationTime)
{
    // Find an available table for the given party size
    Table *table = maitreD->findAvailableTable(partySize);

    if (table)
    {
        // Create a reservation and add it to the customer's list
        Reservation reservation(this, table, reservationTime);
        reservations.push_back(reservation);

        // Notify the MaitreD to add the customer to the list of reservations
        maitreD->addCustomerWithReservation(reservation);
        hasReservation = true;
    }
    else
    {
        std::cout << "No available table for the specified party size." << std::endl;
    }
}



void Customer::viewReservations() const
{
    if (reservations.empty())
    {
        std::cout << "You have no reservations." << std::endl;
    }
    else
    {
        std::cout << "Reservations for " << name << ":" << std::endl;
        for (const Reservation &reservation : reservations)
        {
            std::cout << "Table: " << reservation.getTable()->getName() << ", Time: " << reservation.getReservationTime() << std::endl;
        }
    }
}

void Customer::walkIn(const std::string &name, int partySize)
{
    Table *table = maitreD->findAvailableTable(partySize);

    if (table)
    {
        // table->seatTable(partySize);
        WalkIn walkIn(name, partySize, table);
        walkIns.push_back(walkIn);

        maitreD->addCustomerWithWalkIn(walkIn);
        std::cout << "Table " << table->getName() << " has been seated." << std::endl;
    }
    else
    {
        std::cout << "No available table for the specified party size." << std::endl;
    }
}

void Customer::Leave()
{
    // Iterate through the reservations of this customer
    for (Reservation &reservation : reservations)
    {
        cout << "Table: " << reservation.getTable()->getName() << endl;
        if (!reservation.getTable()->isAvailable() && reservation.getCustomer()->getName() == this->getName())
        {
            reservation.getTable()->freeTable();
            std::cout << "Table " << reservation.getTable()->getName() << " has been freed." << std::endl;
            // Remove the reservation from the customer's list
            // reservations.erase(std::remove(reservations.begin(), reservations.end(), reservation), reservations.end());
            return;
        }
    }

    for (WalkIn &walkIn : walkIns)
    {
        if (!walkIn.getTable()->isAvailable() && walkIn.getName() == this->getName())
        {
            walkIn.getTable()->freeTable();
            std::cout << "Table " << walkIn.getTable()->getName() << " has been freed." << std::endl;
            return;
        }
    }
    std::cout << "You have no occupied tables." << std::endl;
}

// void Customer::placeOrder(Command *command)
// {
//     orders.push_back(command);
//     command->execute();
// }

void Customer::placeOrder(Command* command) {
    if (command == nullptr) {
        std::cout << "Cannot place a null order." << std::endl;
        return;
    }

    orders.push_back(command);

    if (orders.size() > 0) {
        std::cout << "Order placed successfully." << std::endl;}

    
    command->execute();
    cout << "Command Executed." << endl;
}


void Customer::displayOrder()
{
    if (orders.empty())
    {
        std::cout << "No orders placed yet." << std::endl;
    }
    else
    {
        std::cout << "Current Order:" << std::endl;
        getOrderTotal();
        // double total= getOrderTotal();
        // std::cout << "Total Price: R" << total << std::endl;
    }
}


double Customer::getOrderTotal()
{
    double total = 0.0;
    for (const Command *order : orders)
    {
        const OrderCommand *orderCommand = dynamic_cast<const OrderCommand *>(order);
        if (orderCommand)
        {
            std::cout << "Pizza: " << orderCommand->getPizza()->getItemType() << " - Price: R" << orderCommand->getPizza()->getPriceTotal() << std::endl;

            total += orderCommand->getPizza()->getPriceTotal();
        }
    }
    return total;
}

///Payment strat
void Customer:: setPaymentMethod(paymentMethod* paymentMethod) {
    strat = paymentMethod;
}

void Customer::payOrder(double amount){
    if (strat)
    {
        strat->pay(amount);
    }
    else
    {
        std::cout << "No payment strategy set." << std::endl;
    }
}


void Customer::Test(){
    cout<<"Testing the Proxy!";
}

void Customer::ReceveMeal(Meal* m){
    //teminal example text <3
    cout<<"\nThey consumed a meal with the contents:\n";
    m->outputContents();
    cout<<"YUM<3\n";
    delete m;
}

Customer::Customer(bool hasReservation, const std::string &reservationTime)
    : hasReservation(hasReservation), reservationTime(reservationTime), strat(0),
      tabCalculator(nullptr), hasOutstandingTab(false), outstandingTabAmount(0.0) {}

void Customer::setPaymentStrategy(paymentMethod *strategy)
{
    strat = strategy;
}

double Customer::calculateTab(double subtotal, double os)
{

    if (strat)
    {
        double total = strat->calculateTotal(subtotal, os);
        if (tabCalculator)
        {
            total = tabCalculator->calculateTab(total, os);
        }
        return total;
    }
    else
    {
        std::cerr << "Payment strategy not set." << std::endl;
        return 0.0;
    }
}

TabCalculator *Customer::getTabCalculator()
{
    if (hasReservation && isDuringHappyHour())
    {
        return new HappyHourTabCalculator();
    }
    else
    {
        return new StandardTabCalculator();
    }
}

bool Customer::isDuringHappyHour()
{
    // Check the time and date for happy hour
    // Return true if it's within the happy hour timeframe
    return happyH;
}

void Customer::setTabCalculator(TabCalculator *calculator)
{
    tabCalculator = calculator;
}

bool Customer::checkTime(std::string time)
{
    // Define a regex pattern to match the time part "HH:mm" in a timestamp format "YYYY-MM-DD HH:mm"
    std::regex timeRegex("((17:\\d{2})|(18:00))"); // Matches times between 17:00 and 18:00
    happyH = std::regex_search(time, timeRegex);
    return happyH;
}

void Customer::setOutstandingTab(double amount)
{
    if (hasOutstandingTab)
    {
        outstandingTabAmount = amount;
    }
    else
    {
        std::cerr << "Customer does not have a tab." << std::endl;
    }
}

double Customer::getOutstandingTabAmount() const
{
    return outstandingTabAmount;
}

bool Customer::hasTab()
{
    return hasOutstandingTab;
}

void Customer::setHasTab(bool hasTabStatus)
{
    hasOutstandingTab = hasTabStatus;
}

bool Customer::hasRes(){
    return hasReservation;
}