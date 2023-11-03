#ifndef BUILDER_H
#define BUILDER_H

#include "Builder.h"
#include "Meal.h"
#include <string>
#include <vector>

using namespace std;


class MealBuilder :public Builder {
    public:

        MealBuilder();
        ~MealBuilder();
        void reset();
        string BuildBase(string s = "Normal");
        string BuildSauce(string s = "Tomato");
        string BuildCheese();
        string BuildToppings(vector<string>);
        Meal* getResults();

    private:
        Meal* result;

};

#endif
