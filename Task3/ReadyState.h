#pragma once
#include "CustomerState.h"

class ReadyState : public CustomerState
{
public:
    void handle(Table *table) override;
};
