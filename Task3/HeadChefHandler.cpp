#include "Handler.h"
#include "HeadChefHandler.h"
using namespace std;

HeadChefHandler::HeadChefHandler(HeadChef* hc){
    this->worker=hc;
    this->hc=hc;
}

void HeadChefHandler::handle(Meal* m){
    hc->decorate(m);
	if(this->next!=nullptr)
		next->handle(m);
}
