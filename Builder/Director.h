#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "Builder.h"
#include "Pizza.h"
#include <string>
/**
 * @brief Constructs an object using the Builder interface.
 */
class Director {
    public:

        Director(Builder* builder);
        void make(Pizza* pizza);
        

    private:
        Builder* builder;
    
};

#endif