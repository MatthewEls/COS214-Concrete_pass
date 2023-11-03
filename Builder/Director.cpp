#include "Director.h"
#include <string>
#include <vector>

Director::Director(Builder* build){
    this->builder=build;
}

void Director::make(Pizza* piz){
    string ret="";
    builder->reset();
    builder->BuildBase();
    builder->BuildSauce();
    builder->BuildCheese();
    builder->BuildToppings(piz->listToppings());
}