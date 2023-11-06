#include "Handler.h"
#include "CustomerHandler.h"
using namespace std;

CustomerHandler::CustomerHandler(CustomerProxy* c){
    customer=c;
}


void CustomerHandler::handle(Meal* m){
//    customer->receveFood(m);      //function for the customer?
    customer->ReceveMeal(m);
	if(this->next!=nullptr)
		next->handle(m);
}