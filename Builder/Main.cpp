#include <iostream>
#include "Builder.h"
#include "Director.h"
#include "Meal.h"
#include "MealBuilder.h"
#include "Menu.h"
#include "Pizza.h"
#include "Toppings.h"
#include "Godfather.h"

int main(){
    Toppings toppings;
    Godfather godfatherPizza(toppings);
    MealBuilder b=new MealBuilder();
    Director d(b);
    d.make(&godfatherPizza);
    Meal m=b.getResults();
}