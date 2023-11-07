#ifndef MEAL_H
#define MEAL_H

using namespace std;
#include "Toppings.h"
#include <string>
#include <vector>
#include <iostream>
/**
 * @class Meal
 * @brief The PRodct of the builder Pattern and the meal the customer will be served
 */
class Meal {
    public:
    /**
        * Get the description of the menu item.
        * @return A string describing the menu item.
        */
        Meal();
        void setType(string);
        void setBase(string);
        void setSauce(string);
        void setCheese(bool);
        void addToppings(string);

        void outputContents();
        
        
    private:
        string type;
        string base;
        string sauce;
        bool cheese;
        vector<string> toppings;

    
};

#endif