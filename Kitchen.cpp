#include "Kitchen.h"
#include <iostream>
using namespace std;

void Kitchen::prepareOrder(Pizza* pizza) {
    

    // Simulate food prepation specific to the pizza
    cout<<"Preparing "<<pizza->getItemType()<<endl;
    
    //cout<<"Adding "<<pizza->listToppings() <<endl;

    // You can add more logic here for preparing the pizza, such as cooking, baking, etc.
}
