// Table.cpp
#include <iostream>
#include "Table.h"
#include "AvailableTableState.h"
#include "Waiter.h"
#include "TableComposite.h"
#include "NotReadyState.h"

using namespace std;

Table::Table(const std::string& tableName) : name(tableName), state(new AvailableTableState()),cState(new NotReadyState) {
    cout<<"Table "<<tableName<<" available for shift" << endl;
}

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

bool Table::isComposite() const {
    return false;
}

Table* Table::getSubTable() const {
    return nullptr;
}


//observer stuff
void Table::addObserver(Observer *observer)
{
    observers.push_back(observer);
    int i=0;
    if (observers.size() >i)
    {
        /* code */
        cout<<"OBSERVER ADDED"<<endl;
        i++;
    }
    
}

void Table::changeState(CustomerState *newState)
{
    cout<<"CHANGING STATE"<<endl;
    cState = newState;
    notifyWaiters();
}

void Table::notifyWaiters()
{
    for (Observer *observer : observers)
    {
        cout<<"NOTIFYING WAITERS"<<endl;
        observer->update();
        
    }
}




Table::~Table() {
    // Clean up any resources if needed
     // Assuming that state needs to be cleaned up
}
