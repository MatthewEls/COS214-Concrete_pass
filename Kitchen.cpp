#include "Kitchen.h"
#include "Director.h"
#include "MealBuilder.h"

#include <iostream>
using namespace std;

Kitchen::Kitchen(HeadChef* headC): headChef(headC){
    fetch=nullptr;
    orderer=nullptr;
    chain=new HeadChefHandler(headC);
    chain->setNext(new WaiterHandler(fetch));
    chain->setNext(new CustomerHandler(orderer));
}

Kitchen::~Kitchen(){
    delete chain;
}

void Kitchen::prepareOrder(Pizza* pizza, Waiter* w, Customer* c) {
    MealBuilder b;
    b.reset();
    Director d(&b);
    d.make(pizza);
    Meal* m=b.getResults();
    m->outputContents();     //optional
    fetch=w;
    orderer=c;
    chain->handle(m);
}
