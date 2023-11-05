#include "Handler.h"
#include "WaiterHandler.h"
using namespace std;

WaiterHandler::WaiterHandler(Waiter* hc){
    this->worker=hc;
}

void WaiterHandler::handle(Meal* m){
    waiter->serveTable(m);
	if(this->next!=nullptr)
		next->handle(m);
}