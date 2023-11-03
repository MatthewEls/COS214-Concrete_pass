#ifndef MEAL_H
#define MEAL_H

using namespace std;
#include "Toppings.h"
#include <string>
#include <vector>
/**
 * @brief The PRodct of the builder Pattern
 */
class Meal {
    public:
    /**
        * Get the description of the menu item.
        * @return A string describing the menu item.
        */
        Meal();
        void setBase(string);
        void setSauce(string);
        void setCheese(bool);
        void addToppings(string);
        
        
    private:
        string base;
        string sauce;
        bool cheese;
        vector<string> toppings;

    
};

#endif
