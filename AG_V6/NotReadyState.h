#pragma once
#include "CustomerState.h"

class NotReadyState : public CustomerState
{
public:
    void handle(Table *table) override;
};
