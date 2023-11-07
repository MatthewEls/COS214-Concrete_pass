#ifndef MEALBUILDER_H
#define MEALBUILDER_H

#include "Builder.h"
#include "Meal.h"
#include <string>
#include <vector>

using namespace std;

/**
 * @class MealBuilder
 * @brief Concrete Builder for Builder. Constructs and orders the construction of the Meal.
 */
class MealBuilder :public Builder {
    public:

        MealBuilder();
        void reset();
        void setType(string);
        string BuildBase();
        string BuildBase(string);
        string BuildSauce();
        string BuildSauce(string);
        string BuildCheese();
        string BuildToppings(vector<string>);
        Meal* getResults();

    private:
        Meal* result;

};

#endif
