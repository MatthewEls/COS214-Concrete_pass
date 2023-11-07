#include "Handler.h"
using namespace std;

void Handler::setNext(Handler* append){
    if (next) 
		next->setNext(append); 
	else 
		next = append;
}
void Handler::handle(Meal* meal){
	worker->work(/*meal?*/);
	if(next!=nullptr)
		next->handle(meal);
}
Handler::~Handler(){
	if(next)
		delete next;
}