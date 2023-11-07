#include "Kitchen.h"
#include "Director.h"
#include "MealBuilder.h"


#include <iostream>
using namespace std;

Kitchen::Kitchen(HeadChef* headC): headChef(headC){
    fetch=nullptr;
    orderer =new CustomerProxy();
    chain=new HeadChefHandler(headC);
    chain->setNext(new WaiterHandler(fetch));
    chain->setNext(new CustomerHandler(orderer));
}

Kitchen::~Kitchen(){
    delete chain;
}

void Kitchen::prepareOrder(Pizza* pizza, Waiter* w, CustomerProxy* c) {
    MealBuilder b;
    b.reset();
    Director d(&b);
    d.make(pizza);
    Meal* m=b.getResults();
    //m->outputContents();     //optional
    fetch=w;
    orderer->setCustomer(c);
    chain->handle(m);
}
