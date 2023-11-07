#pragma once

class Table; // Forward declaration

class CustomerState
{
public:
    virtual void handle(Table *table) = 0;
};
