// TableComposite.cpp
#include "TableComposite.h"
#include <iostream>
using namespace std;

TableComposite::TableComposite(const std::string &name) : Table(name) {}

void TableComposite::addTable(Table *table)
{
    if (table->isAvailable())
    {
        /* code */
        joinedTables.push_back(table);
        cout << "Tables: ";
        for (const Table *table : joinedTables)
        {
            cout << table->getName() << ", ";
        }
        cout << "are now joined to composite table " <<this->getName() << "." << endl;
    }
    else
    {
        cout<<"TABLE: "<<this->getName()<<" NOT AVAILABLE"<<endl;
    }
     
}

std::string TableComposite::getName() const
{
    Table* c=getSubTable();
    return c->getName();
}



void TableComposite::seatTable(int partySize)
{
    if (canJoin(partySize))
    {
        // Check if the composite table is available
        if (isAvailable())
        {
            for (Table *table : joinedTables)
            {
                // Check if the individual table is available
                table->seatTableComp(partySize);
            }
        }
        // Seat the party at the composite table
        // Table::seatTable(partySize);
        
    }
    else
    {
        std::cout << "The composite table is already occupied." << std::endl;
    }
}

void TableComposite::freeTable()
{
    for (Table *table : joinedTables)
    {
        table->freeTable();
        joinedTables.pop_back();
       

    }
    cout<<"COMPOSITE TABLE: "<< this->getName()<<" HAS NO TABLES"<<endl;
    
}

bool TableComposite::isAvailable()
{
    for (Table *table : joinedTables)
    {
        if (!table->isAvailable())
        {
            return false;
        }
    }
    return Table::isAvailable();
}

// TableComposite.cpp

// ...

bool TableComposite::canJoin(int partySize) const
{
    // Check if the party size exceeds the combined capacity of the joined tables
    int combinedCapacity = getMaxCapacity();
    for (Table *table : joinedTables)
    {
        if (!table->isAvailable())
        {
            cout << "A TABLE " << table->getName() << " IS OCCUPIED" << endl;
        }
        else
        {
            combinedCapacity += table->getMaxCapacity();
        }
    }
    return partySize <= combinedCapacity;
}

Table* TableComposite::getSubTable() const {

    return joinedTables[0];
}
// ...
bool TableComposite::isComposite() const {
    return true;
}

TableComposite::~TableComposite()
{
}
