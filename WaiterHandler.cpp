#include "Handler.h"
#include "WaiterHandler.h"
using namespace std;

WaiterHandler::WaiterHandler(Waiter* hc){
    this->worker=hc;
}

// void WaiterHandler::ChangeWaiter(Waiter*waiter){
//     this->worker=waiter;
// }

void WaiterHandler::handle(Meal* m){
    waiter->returnMeal(m);
	if(this->next!=nullptr)
		next->handle(m);
}