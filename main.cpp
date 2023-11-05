#include "Command.h"
#include "Customer.h"
#include "Employee.h"
#include "Godfather.h"
#include "Handler.h"
#include "HeadChef.h"
#include "HeadChefHandler.h"
#include "Kitchen.h"
#include "Meal.h"
#include "Menu.h"
#include "OrderCommand.h"
#include "Pizza.h"
#include "Toppings.h"
#include "WaiterHandler.h"
// #include ""

int main(){

    //Create waiter
    Waiter server("sandwich, Idiot",0);
    // Create a kitchen.
    HeadChef headChef("Gordon");
    Kitchen kitchen(&headChef);
    Toppings toppings;
    // Create a customer.
    Customer customer("sandwich, Idiot");
    
    // Create a Godfather pizza.
    Godfather godfatherPizza(toppings); // Assuming a base price of 15.0
    godfatherPizza.addTopping("Figs");
    godfatherPizza.addTopping("Mince");
    godfatherPizza.addTopping("Olives");
    godfatherPizza.addTopping("Mushrooms");

    // Create an OrderCommand to order the pizza.
    Command* orderCommand = new OrderCommand(kitchen, &godfatherPizza, &server, &customer);

    // Place the order and execute it.
    customer.placeOrder(orderCommand);

    cout << endl;

    // Display the customer's order.
    customer.displayOrder();



    // Get the total price of the order.
    double total = customer.getOrderTotal();
    cout << "Total Price: R" << total << endl;

    return 0;


}