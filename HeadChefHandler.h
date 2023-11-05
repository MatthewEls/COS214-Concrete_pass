#ifndef HEADCHEFHANDLER_H
#define HEADCHEFHANDLER_H

#include <string>
#include "Handler.h"
#include "HeadChef.h"

class HeadChefHandler: public Handler{

public:
    HeadChefHandler(HeadChef* hc);
    // void handle(Meal* m);
    void handle(Meal* m) override;

private:
    HeadChef* hc;
};

#endif
