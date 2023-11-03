#ifndef MEALBUILDER_H
#define MEALBUILDER_H

#include "Builder.h"
#include "Meal.h"
#include <string>
#include <vector>

using namespace std;


class MealBuilder :public Builder {
    public:

        MealBuilder();
        void reset();
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
