#include "Meal.h"


Meal::Meal(){
        base="";
        sauce="";
        cheese=false;
        Toppings toppings;
}       

void Meal::setType(string s){
        type=s;
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

void Meal::outputContents(){
        cout<< "Type: "<<type<<"\n";
        cout<< "Base: "<< base<<"\n";
        cout<< "Sauce: "<< sauce<<"\n";
        cout<< "Has Cheese: : "<< ((cheese)? "Yes":"No") <<"\n";
        cout<< "Toppings: \n";
        for (string& topping : toppings) {
                cout << "       " << topping<<"\n";
        }
}
