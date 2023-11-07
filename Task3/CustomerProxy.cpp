#include "CustomerProxy.h"

void CustomerProxy::Test(){
    realCustomer->Test();
}

CustomerProxy::CustomerProxy(){
    realCustomer=nullptr;
}

CustomerProxy::CustomerProxy(CustomerSubject* RealCustomer): realCustomer(RealCustomer){}

void CustomerProxy::setCustomer(CustomerSubject* RealCustomer){
    realCustomer=RealCustomer;
}

void CustomerProxy::ReceveMeal(Meal* m){
    realCustomer->ReceveMeal(m);
}