#include "paymentMethod.h"
#include "splitBill.h"
#include <iostream>


   splitBill:: splitBill(int x ){
        this->div = x;
    }

    

    void splitBill::pay(double amount) {
                std::cout << "The bill is split, each person pays R" << amount/ div << std::endl;

    }
        


