#pragma once

class Table; // Forward declaration

class Observer
{
public:
    virtual void update() = 0;
};
