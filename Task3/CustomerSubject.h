#ifndef CUSTOMERSUBJECT_H
#define CUSTOMERSUBJECT_H

#include "Meal.h"
#include <string>
#include <iostream>

class Meal; //forward decloration of Meal class
/**
 * @brief Class acting as the subject for the Customer.
 */
class CustomerSubject{
public:

    /**
     * @brief Represents the actions taken once the customer has receved the food.
     * @param m The Meal the Customer will consume apon arival.
     */
    virtual void ReceveMeal(Meal* m)=0;
    virtual void Test()=0;
    
};

#endif