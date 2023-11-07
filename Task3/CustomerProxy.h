#ifndef CUSTOMERPROXY_H
#define CUSTOMERPROXY_H

#include "CustomerSubject.h"
#include "Customer.h"
#include <string>
/**
 * @brief Class acting as Proxy for concrete class Customer
 */
class CustomerProxy: public CustomerSubject{
public:
    CustomerProxy();

    /**
     * @brief Constructs the proxy for the Real Class Customer.
     * @param RealCustomer The Real Class Customer the proxy will be made for.
     */
    CustomerProxy(CustomerSubject* RealCustomer);

    /**
     * @brief Dynamicaly changes the Customer pointed to.
     * @param RealCustomer The Real Class Customer the proxy will be made for.
     */
    void setCustomer(CustomerSubject* RealCustomer);


    /**
     * @brief Returns the type of the employee.
     * @return The type of the employee (e.g., "Chef").
     */
    // void ReceveMeal(Meal* m);
    void ReceveMeal(Meal* m) override;
    void Test() override;

private:
    CustomerSubject * realCustomer;
};

#endif