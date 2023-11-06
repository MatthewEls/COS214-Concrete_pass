#ifndef BUILDER_H
#define BUILDER_H

//#include "Meal.h"

#include <string>
#include <vector>
using namespace std;
/**
 * @class Builder
 * @brief Specifies an abstract interface for creating parts of the Product object.
 */
class Builder {
public:

    virtual ~Builder(){};
    virtual void reset()=0;
    virtual void setType(string)=0; 
    virtual string BuildBase() = 0;
    virtual string BuildBase(string) = 0;
    virtual string BuildSauce() = 0;
    virtual string BuildSauce(string) = 0;
    virtual string BuildCheese()=0;
    virtual string BuildToppings(vector<string>)=0;

    
};

#endif
