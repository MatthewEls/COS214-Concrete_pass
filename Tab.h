#pragma once
#include "paymentMethod.h"
#include "TabCalculator.h"
#include <fstream>
#include <sstream>
#include <string>

class Tab : public paymentMethod
{
private:
    TabCalculator *tabCalculator;
    double total;
    std::string fname, cname;

public:
    double calculateTotal(double subtotal, double out) override;
    // Tab(TabCalculator &calculator) : tabCalculator(calculator) {}
    Tab() {}
    Tab(std::string fn , std::string cn):  fname(fn), cname(cn) {}
    void setTabCalculator(TabCalculator *calculator);
    void pay(double amount) override;
    double getOutstandingAmountFromTextFile(const std::string &filename, const std::string &customerName);
};
