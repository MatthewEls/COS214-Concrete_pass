#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "Builder.h"
#include "MealBuilder.h"
#include "Pizza.h"
#include <string>
/**
 * @brief Constructs an object using the Builder interface.
 */
class Director {
    public:
        /**
         * Constructor for Director class.
         * @param builder The concrete Builder that will build obect (e.g., "MealBuilder").
         */
        Director(Builder* builder);
        ~Director();
        void make(Pizza* pizza);
        
        

    private:
        Builder* builder;
    
};

#endif
