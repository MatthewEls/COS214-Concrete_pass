#include "MealBuilder.h"

#include <string>
using namespace std;

    MealBuilder::MealBuilder(){
        result=new Meal();
    }

    void MealBuilder::reset(){
        result=new Meal();
    }

    MealBuilder::~MealBuilder(){

    };

    string MealBuilder::BuildBase(string s = "Normal"){
        string pizzaBaseCheff= "placeolder";
        string returnSTR= "Chef "+ pizzaBaseCheff +"makes the pizza base.";
        result->setBase(s);
        return returnSTR;
    }
    
    string MealBuilder::BuildSauce(string s = "Tomato"){
        string pizzaBaseCheff= "placeolder";
        string returnSTR= "Chef "+ pizzaBaseCheff +"adds the "+s+"sauce to the base";
        result->setSauce(s);
        return returnSTR;

    }
    
    string MealBuilder::BuildCheese(){
        string pizzaBaseCheff= "placeolder";
        string returnSTR= "Chef "+ pizzaBaseCheff +"adds cheese to the pizza";
        result->setCheese(true);
        return returnSTR;

        
    }
    
    string MealBuilder::BuildToppings(vector <string> v){
        string pizzaBaseCheff= "placeolder";
        string returnSTR= "Chef "+ pizzaBaseCheff +"adds: ";
        for(string& topping :v){
            returnSTR+= topping+", ";
            result->addToppings(topping);
        }
        returnSTR.pop_back();
        returnSTR.pop_back();

        return returnSTR;
    }
    Meal* MealBuilder::getResults(){
        return result;
    }