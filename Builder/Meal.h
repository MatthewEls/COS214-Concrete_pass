#ifndef MEAL_H
#define MEAL_H

using namespace std;
#include <string>
#include <vector>
/**
 * @brief The PRodct of the builder Pattern
 */
class Meal {
    public:
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