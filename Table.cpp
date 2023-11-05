// Table.cpp
#include <iostream>
#include "Table.h"
#include "AvailableTableState.h"
#include "Waiter.h"

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

int Table::getMaxCapacity() {
    return maxCapacity;
}

void Table::setState(TableState* newState) {
    delete state; // Cleanup old state
    state = newState;
}
void Table::setWaiter(Waiter* waiter){
    servingWaiter = waiter;
}

bool Table::isWaiterAssigned(){
    if(servingWaiter == nullptr){
        return false;
    }
    else{
        return true;
    }
}

Waiter* Table::getWaiter(){
    return servingWaiter;
}

Table::~Table() {
    // Clean up any resources if needed
     // Assuming that state needs to be cleaned up
}
