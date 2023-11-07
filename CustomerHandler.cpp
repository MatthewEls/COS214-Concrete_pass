#include "Handler.h"
#include "CustomerHandler.h"
using namespace std;

CustomerHandler::CustomerHandler(CustomerProxy* c){
    customer=c;
}

// void WaiterHandler::ChangeWaiter(Waiter*waiter){
//     this->worker=waiter;
// }

void CustomerHandler::handle(Meal* m){
    //customer->receveFood(m);      //function for the customer?
	if(this->next!=nullptr)
		next->handle(m);
}