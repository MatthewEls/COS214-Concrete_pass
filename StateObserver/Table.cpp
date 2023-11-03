// Table.cpp
#include <iostream>
#include "Table.h"
#include "AvailableTableState.h"
#include "NotReadyState.h"

using namespace std;
Table::Table(const std::string& tableName) : name(tableName), state(new AvailableTableState()) {}

void Table::seatTable(int partySize) {
    if (partySize <= maxCapacity) {
        state->seatTable(*this);
        cout<<"Table "<<name<<" is now occupied by a party of "<<partySize<<"."<<endl;
    } else {
        std::cout << "Party size exceeds the maximum capacity of this table." << std::endl;
    }
}
void Table::seatTableComp(int partySize) {
   
        state->seatTable(*this);
       
}

void Table::freeTable() {
    state->freeTable(*this);
    cout<<"Table: "<<this->getName()<<" is now free"<<endl;

}

bool Table::isAvailable() {
    return state->isAvailable();
}

const std::string& Table::getName() const {
    return name;
}

int Table::getMaxCapacity() const {
    return maxCapacity;
}

void Table::setState(TableState* newState) {
    delete state; // Cleanup old state
    state = newState;
}

Table::~Table() {
    // Clean up any resources if needed
     // Assuming that state needs to be cleaned up
     
}

void Table::setBillAmount(double am){
    billAmount = am;
}


Table::Table() : cState(new NotReadyState) {}

void Table::addObserver(Observer *observer)
{
    observers.push_back(observer);
}

void Table::changeState(CustomerState *newState)
{
    cState = newState;
    notifyWaiters();
}

void Table::notifyWaiters()
{
    for (Observer *observer : observers)
    {
        observer->update();
    }
}

// // Implement ReadyState and NotReadyState methods
// void ReadyState::handle(Table *table)
// {
//     std::cout << "Customer is ready to order. Waiter takes the order." << std::endl;
//     table->notifyWaiters();
// }

// void NotReadyState::handle(Table *table)
// {
//     std::cout << "Customer is not ready to order. Waiter will come back later." << std::endl;
//     table->notifyWaiters();
// }

// Table::Table(const std::string &tableName) : name(tableName), st(nullptr), billAmount(0.0), state(new AvailableTableState()) {}

// void Table::changeState(tState *newState)
// {
//     if (st)
//     {
//         delete st;
//     }
//     st = newState;
// }

// // Table::tState* Table::getS() const
// // {
// //     return st;
// // }

// void Table::setBillAmount(double amount)
// {
//     billAmount = amount;
// }

// void Table::addObserver(Waiter *waiter)
// {
//     waiters.push_back(waiter);
// }

// void Table::removeObserver(Waiter *waiter)
// {
//     waiters.erase(std::remove(waiters.begin(), waiters.end(), waiter), waiters.end());
// }

// void Table::notifyWaiters()
// {
//     for (Waiter *waiter : waiters)
//     {
//         waiter->takeOrder(this);
//     }
// }

// // const std::string &Table::getName() const
// // {
// //     return name;
// // }

// std::string Table::getStateAsString() const
// {
//     if (st)
//     {
//         return st->getSt(); // Assuming TableState has a getState method
//     }
//     return "Unknown";
// }

// tState *Table::getSt() const
// {
//     return st;
// }