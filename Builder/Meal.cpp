#include "Meal.h"


Meal::Meal(){
        base="";
        sauce="";
        cheese=false;
        toppings;
}       

void Meal::setBase(string s){
        base=s;
}

void Meal::setSauce(string s){
        sauce=s;
}

void Meal::setCheese(bool b){
        cheese=b;
}

void Meal::addToppings(string s){
        toppings.push_back(s);
}