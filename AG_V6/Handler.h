#ifndef HANDLER_H
#define HANDLER_H
#include "Meal.h"
#include "Employee.h"
class Handler{
protected:
    Handler* next=nullptr;
    Employee* worker;

public:
    ~Handler();
    void setNext(Handler*);
    virtual void handle(Meal*);

};

#endif
