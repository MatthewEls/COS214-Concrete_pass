#include "Menu.h"
#include "Toppings.h"
#include "Pizza.h"
#include "Godfather.h"
#include "Margherita.h"
#include "Miami.h"
#include "Customer.h"
#include "OrderCommand.h"
#include "Kitchen.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Table.h"
#include "TableComposite.h"
#include "Waiter.h"
#include "WalkInStrategy.h"
#include "splitBill.h"
#include "oneBill.h"
#include "paymentMethod.h"
#include "Tab.h"
#include "ReadyState.h"
#include <cstdlib>  // For system function
#include <unistd.h> // For sleep function
#include <iomanip>


// Color escape sequences
const std::string RESET = "\033[0m";
const std::string BLACK = "\033[30m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string BLUE = "\033[34m";
const std::string MAGENTA = "\033[35m";
const std::string CYAN = "\033[36m";
const std::string WHITE = "\033[37m";
const std::string BOLD = "\033[1m";

void displayMainMenu()
{
    std::cout << "=============================================" << std::endl;
    std::cout << "         Restaurant Reservation System       " << std::endl;
    std::cout << "=============================================" << std::endl;
    std::cout << "1. Make a Reservation" << std::endl;
    std::cout << "2. Walk-in Customer" << std::endl;
    std::cout << "3. Display Available Tables" << std::endl;
    std::cout << "4. Display Reservations" << std::endl;
    std::cout << "5. View Waiters Assigned to Tables" << std::endl;
    std::cout << "6. Leave Table" << std::endl;
    std::cout << "7. Order Pizza" << std::endl; // Added option to order pizza
    std::cout << "8. Exit" << std::endl;
    std::cout << "=============================================" << std::endl;
    std::cout << "Please enter your choice: ";
}

void viewWaiters(std::vector<Table> &allTables, std::vector<Waiter> &allWaiters)
{
    std::cout << "Do you want to view waiters for a specific table? (Y/N): ";
    char choice;
    std::cin >> choice;

    if (choice == 'Y' || choice == 'y')
    {
        // Ask for the table's name
        std::string tableName;
        std::cout << "Enter the name of the table: ";
        std::cin.ignore(); // Clear the newline character
        std::getline(std::cin, tableName);

        // Find the table by name and get its waiter
        for (Table &table : allTables)
        {
            if (table.getName() == tableName)
            {
                Waiter *assignedWaiter = table.getWaiter();
                if (assignedWaiter != nullptr)
                {
                    std::cout << "Table " << tableName << " is served by " << assignedWaiter->getType() << std::endl;
                }
                else
                {
                    std::cout << "Table " << tableName << " is not assigned to any waiter." << std::endl;
                }
                break; // Stop searching after finding the table
            }
        }
    }
    else
    {
        // View all waiters
        for (Waiter &waiter : allWaiters)
        {
            waiter.serveTable();
        }
    }
}

void viewWaitersAssignedToTables(Waiter waiter)
{

    waiter.serveTable();
}

void addCustomerAndMakeReservation(std::vector<Customer> &customers, MaitreD &maitreD)
{
    std::string name;
    int partySize;
    std::string reservationTime;

    std::cout << "Enter customer's name: ";
    std::cin >> name;
    std::cout << "Enter party size: ";
    std::cin >> partySize;
    std::cout << "Enter expected time (e.g., 18:30): ";
    std::cin.ignore(); // Clear the newline character
    std::getline(std::cin, reservationTime);

    customers.push_back(Customer(name, partySize, &maitreD));
    Customer &customer = customers.back(); // Get a reference to the newly added customer
    customer.makeReservation(partySize, reservationTime);
    customer.viewReservations();
}

void viewWaitersAssignedToTables1(Waiter waiter)
{

    waiter.serveTable();
}

void addCustomerAndMakeWalkin(std::vector<Customer> &customers, MaitreD &maitreD)
{
    std::string name;
    int partySize;
    std::string reservationTime;

    std::cout << "Enter customer's name: ";
    std::cin >> name;
    std::cout << "Enter party size: ";
    std::cin >> partySize;
    // std::cin.ignore(); // Clear the newline character
    // std::getline(std::cin, reservationTime);

    customers.push_back(Customer(name, partySize, &maitreD));

    Customer &customer = customers.back(); // Get a reference to the newly added customer
    customer.walkIn(name, partySize);
    maitreD.displayWalkIns();
}

// Function to remove a customer by name
void removeCustomerByName(std::vector<Customer> &customers,string customerName)
{
    //std::string customerName;
    //std::cout << "Enter the name of the customer to remove from the table: ";
    //std::cin >> customerName;

    // Find the customer by name
    // Find the customer by name
    Customer *customerToRemove = nullptr;
    for (Customer &customer : customers)
    {
        if (customer.getName() == customerName)
        {
            customerToRemove = &customer;
            break;
        }
    }

    if (customerToRemove)
    {

        customerToRemove->Leave(); // Remove the selected customer from the table
    }
    else
    {
        std::cout << "Customer not found." << std::endl;
    }

    auto it = std::remove_if(customers.begin(), customers.end(), [&customerName](const Customer &customer)
                             { return customer.getName() == customerName; });

    if (it != customers.end())
    {
        customers.erase(it, customers.end());
        std::cout << "Customer " << customerName << " has been removed." << std::endl;
    }
    else
    {
        std::cout << "Customer not found." << std::endl;
    }
}

// Function to split a string into individual toppings based on a delimiter
vector<string> splitString(const string &input, char delimiter)
{
    vector<string> tokens;
    size_t start = 0;
    size_t end = input.find(delimiter);

    while (end != string::npos)
    {
        tokens.push_back(input.substr(start, end - start));
        start = end + 1;
        end = input.find(delimiter, start);
    }

    tokens.push_back(input.substr(start, end));

    return tokens;
}

// Method to handle the pizza ordering process
void orderPizza(Menu &menu, Toppings &toppings, Customer &customer, Kitchen &kitchen, std::vector<Waiter> &waiter)
{

    vector<Command*> tableOrder;


    while (true)
    {
        cout << "Welcome to the pizza menu. Please select a pizza from the menu (enter item number):" << endl;
        menu.displayMenu();
        cout << "Enter 0 to exit." << endl;

        size_t choice;
        cin >> choice;

        if (choice == 0)
        { 
             for (Command* orderCommand : tableOrder) {
                customer.placeOrder(orderCommand);
             }
            //  customer.getOrderTotal();
            //customer.displayOrder(); // Display the current order
            float total = customer.getOrderTotal();
            cout << "Total "<<std::setprecision(2)<<std::fixed<<"R"<<total<<endl;
            //cout << "Thank you for ordering. Goodbye!" << endl;
            break;
        }
        else if (choice > 0 && choice <= menu.getItemsCount())
        {
            // Get the selected pizza
            Pizza *selectedPizza = dynamic_cast<Pizza *>(menu.getItem(choice - 1));

            if (selectedPizza)
            {
                // Ask if the customer wants additional toppings
                cout << "Would you like to add additional toppings or drinks? (yes/no): ";
                string additionalToppingsChoice;
                cin >> additionalToppingsChoice;

                if (additionalToppingsChoice == "yes")
                {
                    // Display available toppings
                    toppings.displayToppingPrices();

                    // Ask the user to select toppings
                    cout << "Enter the topping(s) you want (comma-separated, e.g., Olives,Basil): ";
                    cin.ignore(); // Consume the newline character
                    string selectedToppings;
                    getline(cin, selectedToppings);

                    // Split the selected toppings into individual toppings
                    vector<string> toppingsList = splitString(selectedToppings, ',');

                    for (const string &topping : toppingsList)
                    {
                        selectedPizza->addTopping(topping);
                    }
                }

                // Command *orderCommand = new OrderCommand(kitchen, selectedPizza);
                // customer.getReservations().getTables();
                int i = 0;
                if (!customer.getReservations().empty())
                {
                    /* code */

                    for (Waiter waiter : waiter)
                    {

                        if (customer.getReservations()[i].getTable()->getName() == "Composite Table")
                        {
                            if (waiter.getTable()->getName() == customer.getReservations()[i].getTable()->getSubTable()->getName())
                            {
                                /* code */
                                cout << YELLOW<<"\t\t\t\tWaiter found" << RESET<<endl;

                                waiter.getTable()->addObserver(&waiter);
                                waiter.getTable()->notifyWaiters();
                                Command *orderCommand = new OrderCommand(kitchen, selectedPizza, &waiter, &customer);
                                tableOrder.push_back(orderCommand);
                                //customer.placeOrder(orderCommand);
                                // cout << "Your order for  " << selectedPizza->getItemType() << " has been placed." << endl;
                                // i++;
                                break;
                            }
                        }
                        else if (waiter.getTable()->getName() == customer.getReservations()[i].getTable()->getName())
                        {
                            // Table *comp = waiter.getTable()->getSubTable();
                            cout <<YELLOW<< "\t\t\t\tWaiter found" <<RESET<< endl;

                            waiter.getTable()->addObserver(&waiter);
                            waiter.getTable()->notifyWaiters();
                            Command *orderCommand = new OrderCommand(kitchen, selectedPizza, &waiter, &customer);
                            tableOrder.push_back(orderCommand);
                            //customer.placeOrder(orderCommand);
                            // cout << "Your order for  " << selectedPizza->getItemType() << " has been placed." << endl;
                            // i++;
                            break;
                        }
                        else
                        {
                            cout <<YELLOW<< "\t\t\t\tWaiter not found" <<RESET<< endl;
                            // cout << waiter.getTable()->getName() << endl;
                        }
                    }
                }
                else if (!customer.getWalkIns().empty())
                {
                    /* code */
                    for (Waiter waiter : waiter)
                    {

                        if (customer.getWalkIns()[i].getTable()->getName() == "Composite Table")
                        {
                            if (waiter.getTable()->getName() == customer.getWalkIns()[i].getTable()->getSubTable()->getName())
                            {
                                /* code */
                                cout <<YELLOW<< "\t\t\t\tWaiter found" <<RESET<< endl;

                                waiter.getTable()->addObserver(&waiter);
                                waiter.getTable()->notifyWaiters();
                                Command *orderCommand = new OrderCommand(kitchen, selectedPizza, &waiter, &customer);
                                tableOrder.push_back(orderCommand);
                                //customer.placeOrder(orderCommand);
                                // cout << "Your order for  " << selectedPizza->getItemType() << " has been placed." << endl;
                                // i++;
                                break;
                            }
                        }
                        else if (waiter.getTable()->getName() == customer.getWalkIns()[i].getTable()->getName())
                        {

                            cout <<YELLOW<<"\t\t\t\tWaiter found" <<RESET<< endl;
                            Command *orderCommand = new OrderCommand(kitchen, selectedPizza, &waiter, &customer);
                            tableOrder.push_back(orderCommand);
                            //customer.placeOrder(orderCommand);
                            // cout << "Your order for Here" << selectedPizza->getItemType() << " has been placed." << endl;
                            // i++;
                            break;
                        }
                        else
                        {
                            /* code */
                            cout <<YELLOW<< "\t\t\t\tWaiter not found" << RESET<<endl;
                        }
                        
                    }
                }
                else
                {
                    /* code */
                    cout <<YELLOW<< "\t\t\t\tWaiter not assigned to a table" <<RESET<< endl;
                }

                // Example: Get the description, price, and toppings of a specific pizza.
                cout << endl;
                cout << "\nDescription: " << selectedPizza->getItemType() << endl;
                vector<string> godfatherToppings = selectedPizza->listToppings();
                cout << "Additional Toppings (included in current price):\n";
                for (const string &topping : godfatherToppings)
                {
                    double toppingPrice = toppings.getToppingPrice(topping); // Get the topping price.
                    cout << topping << " (+ R" << toppingPrice << ")\n";
                }
                cout << endl;
            }
            else
            {
                cout << "Invalid choice. Please select a valid pizza item." << endl;
            }
        }
        else
        {
            cout << "Invalid choice. Please select a valid item number." << endl;
        }
    }
}

void displayLogo(){
    cout<<endl<<"           @@  @@ @@  @@"<<CYAN<<"                  @@@@@@@@@@@@@@@@@                 "<<WHITE<<"      @@@@@             "<<endl;
    cout<<"           @@  @@ @@  @@"<<CYAN<<"                @@@@@@@@@@@@@@@@@@@@@(              "<<WHITE<<"    @@@@@@@@#           "<<endl;
    cout<<"           @@  @@ @@  @@"<<CYAN<<"            .@@@@,      *@@@@@(       @@@@@         "<<WHITE<<"    @@@@@@@@@           "<<endl;
    cout<<"           @@  @@ @@  @@"<<CYAN<<"          @@@*   %@@@             #@@@    @@@@      "<<WHITE<<"    @@@@@@@@@           "<<endl;
    cout<<"           @@  @@ @@  @@"<<CYAN<<"       (@@@   @@                       @@   #@@@    "<<WHITE<<"    @@@@@@@@@           "<<endl;
    cout<<"           @@@@@@@@@@@@@ "<<CYAN<<"     @@@  ,@*                            @@  #@@(   "<<WHITE<<"   @@@@@@@@@           "<<endl;
    cout<<"           @@@@@@@@@@@@@"<<CYAN<<"    (@@   @%                                @/  @@@   "<<WHITE<<"  @@@@@@@@@           "<<endl;
    cout<<"            @@@@   @@@@ "<<CYAN<<"   /@@  .@                                   @@  @@@  "<<WHITE<<"  @@@@@@@@@           "<<endl;
    cout<<"               @   @  "<<CYAN<<"     @@   @                                     @@  @@* "<<WHITE<<"  @@@@@@@@@           "<<endl;
    cout<<"               @   @  "<<CYAN<<"    @@@  @@                                      @  @@@ "<<WHITE<<"  @@@@@@@@@           "<<endl;
    cout<<"               @   @  "<<CYAN<<"    @@@  @                                       @  /@@ "<<WHITE<<"  @@@@,  %@           "<<endl;
    cout<<"               @   @  "<<CYAN<<"    @@@  @#                                      @  @@@  "<<WHITE<<" @@@@    @           "<<endl;
    cout<<"               @   @  "<<CYAN<<"     @@  &@                                     @@  @@@ "<<WHITE<<"  @@@@    @           "<<endl;
    cout<<"               @   @  "<<CYAN<<"     @@@  @@                                   .@  @@@    "<<WHITE<<"   @    @           "<<endl;
    cout<<"               @   @  "<<CYAN<<"      @@@  @@                                 @@  &@@    "<<WHITE<<"    @    @           "<<endl;
    cout<<"               @   @  "<<CYAN<<"       @@@   @@                              @(  @@@    "<<WHITE<<"     @    @           "<<endl;
    cout<<"               @   @  "<<CYAN<<"         @@@   @@                         @@   @@@#     "<<WHITE<<"     @    @           "<<endl;
    cout<<"               @   @  "<<CYAN<<"           @@@    @@@                 .@@,   @@@#     "<<WHITE<<"       @    @           "<<endl;
    cout<<"               @   @  "<<CYAN<<"             @@@@@     @@@@@@@@@@@@@#    .@@@@        "<<WHITE<<"       @    @           "<<endl;
    cout<<"               @   @  "<<CYAN<<"                 @@@@@@,            @@@@@@              "<<WHITE<<"     @    @           "<<endl;
    cout<<"                @@@/  "<<CYAN<<"                       @@@@@@@@@@@@@*                   "<<WHITE<<"      @@@@            "<<endl<<endl;
}
void displayName()
{

    system("clear");
      cout<<CYAN;
        cout<<"  ______  _                                    ______            _               "<<endl;
        cout<<" |  ____|| |                                  |  ____|          (_)              "<<endl;
        cout<<" | |__   | |  __ _ __   __ ___   _   _  _ __  | |__  _   _  ___  _   ___   _ __  "<<endl;
        cout<<" |  __|  | | / _` |\\ \\ / // _ \\ | | | || '__| |  __|| | | |/ __|| | / _ \\ | '_ \\ "<<endl;
        cout<<" | |     | || (_| | \\ V /| (_) || |_| || |    | |   | |_| |\\__ \\| || (_) || | | |"<<endl;
        cout<<" |_|     |_| \\__,_|  \\_/  \\___/  \\__,_||_|    |_|    \\__,_||___/|_| \\___/ |_| |_|"<<endl<<endl;
        cout<<RESET;


}

void displayInitRestaurant()
{
cout<<"  _____       _ _   _       _ _     _                               _                              _"<<endl;    
cout<<" |_   _|     (_) | (_)     | (_)   (_)                             | |                            | |   "<<endl;   
cout<<"   | |  _ __  _| |_ _  __ _| |_ ___ _ _ __   __ _     _ __ ___  ___| |_ __ _ _   _ _ __ __ _ _ __ | |_  "<<endl;
cout<<"   | | | '_ \\| | __| |/ _` | | / __| | '_ \\ / _` |   | '__/ _ \\/ __| __/ _` | | | | '__/ _` | '_ \\| __| "<<endl;
cout<<"  _| |_| | | | | |_| | (_| | | \\__ \\ | | | | (_| |   | | |  __/\\__ \\ || (_| | |_| | | | (_| | | | | |_  "<<endl;
cout<<" |_____|_| |_|_|\\__|_|\\__,_|_|_|___/_|_| |_|\\__, |   |_|  \\___||___/\\__\\__,_|\\__,_|_|  \\__,_|_| |_|\\__| "<<endl;
cout<<"                                             __/ |                                                    "<<endl;
cout<<"                                            |___/                                                     "<<endl<<endl;




                                                                                 
                                                                                 
}

int main()
{
  displayName();
  displayLogo();
  displayInitRestaurant();

    // Create a Toppings object to manage toppings.
    Toppings toppings;
    // Kitchen kitchen;
    HeadChef headChef("Gordon");
    Kitchen kitchen(&headChef);
    std::vector<Customer> customers;

    cout<<"============================="<<endl;
    cout<<"Creating tables"<<endl;
    cout<<"============================="<<endl<<endl;
    Table table1("T1");
    Table table2("T2");
    Table table3("T3");
    Table table4("T4");
    Table table5("T5");
    Table table6("T6");
    Table table7("T7");
    Table table8("T8");
    Table table9("T9");
    Table table10("T10");

    displayName();

    cout<<endl<<"============================="<<endl;
    cout<<"Waiters signing in for shift"<<endl;
    cout<<"============================="<<endl<<endl;
    Waiter waiter1("James Smith", 1000.0);
    Waiter waiter2("Lucy Waters", 950.0);
    Waiter waiter3("Tina Turner", 900.0);
    Waiter waiter4("Siya Zulu", 850.0);
    Waiter waiter5("Jane Turner", 800.0);
    Waiter waiter6("Celemusa Zondi", 750.0);
    Waiter waiter7("Ashton Wheel", 700.0);
    Waiter waiter8("Jason Judge", 650.0);
    Waiter waiter9("Anne Irish", 600.0);
    Waiter waiter10("Andile Dube", 550.0);

    table1.setWaiter(&waiter1);
    cout<<endl<<"Allocating waiters to tables for shift"<<endl;
    waiter1.assignTable(&table1);
    waiter2.assignTable(&table2);
    waiter3.assignTable(&table3);
    waiter4.assignTable(&table4);
    waiter5.assignTable(&table5);
    waiter6.assignTable(&table6);
    waiter7.assignTable(&table7);
    waiter8.assignTable(&table8);
    waiter9.assignTable(&table9);
    waiter10.assignTable(&table10);



    std::vector<Waiter> allWaiters = {waiter1, waiter2, waiter3, waiter4, waiter5, waiter6, waiter7, waiter8, waiter9, waiter10};
    // Create MaitreD with tables

    std::vector<Table> allTables = {table1, table2, table3, table4, table5};
    std::vector<Table> allTables2 = {table6, table7, table8, table9, table10};
    std::vector<Table> allTables3 = {table1, table2, table3, table4, table5, table6, table7, table8, table9, table10};


    cout<<endl<<"Allocating tables for reservations"<<endl;
    ReservationStrategy *reservationStrategy = new ReservationStrategy(allTables);
    MaitreD maitreD(reservationStrategy);

    cout<<endl<<"Allocating tables for walk-ins"<<endl;
    WalkInStrategy *walkInStrategy = new WalkInStrategy(allTables2);
    MaitreD maitreD1(walkInStrategy);


    cout<<endl<<"============================="<<endl;
    cout<<"Designing different pizza types"<<endl;
    cout<<"============================="<<endl<<endl;
    Godfather godfatherPizza(toppings);
    godfatherPizza.displayToppings();
    Margherita margheritaPizza(toppings);
    margheritaPizza.displayToppings();
    Miami miamiPizza(toppings);
    miamiPizza.displayToppings();


    cout<<endl<<"============================="<<endl;
    cout<<"Creating Menu for shift"<<endl;
    cout<<"============================="<<endl<<endl;

    Menu menu;
    menu.addItem(&godfatherPizza);
    menu.addItem(&margheritaPizza);
    menu.addItem(&miamiPizza);

    menu.displayMenu();

    // Call the orderPizza method to handle pizza ordering
    // orderPizza(menu, toppings, customer, kitchen);

    int choice;
    while (true)
    {
        displayMainMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            // Add a customer and make a reservation

            // MaitreD maitreD(reservationStrategy);
            addCustomerAndMakeReservation(customers, maitreD);
            break;
        }
        case 2:
        {
            // Walk-in customer
            // Customer customer = createCustomer(maitreD);
            // customers push_back(customer);
            // customer.walkIn(customer.getName(), customer.getPartySize(), &maitreD);

            addCustomerAndMakeWalkin(customers, maitreD1);

            break;
        }
        case 3:
        {
            // Display available tables
            cout<<"Tables for Reservations"<<endl;
            maitreD1.displayAvailableTables();
            cout<<"Tables for Walk-ins"<<endl;
            maitreD.displayAvailableTables();

            break;
        }
        case 4:
        {
            // Display reservations
            maitreD.displayReservations();
            break;
        }
        case 5:
        {
            viewWaiters(allTables3, allWaiters);
            break;
        }

        case 6:
        {
            // Check if there are customers
            if (customers.empty())
            {
                cout << "No customers available. Please add customers first." << endl;
                break;
            }

            // Ask the user to enter the name of the customer
            string customerName;
            cout << "Enter the name of the customer to display their order: ";
            cin.ignore(); // Clear the newline character
            getline(cin, customerName);

            // Find the customer by name
            Customer *selectedCustomer = nullptr;
            for (Customer &c : customers)
            {
                if (c.getName() == customerName)
                {
                    selectedCustomer = &c;
                    break;
                }
            }

            if (selectedCustomer != nullptr)
            {
                // Display the selected customer's order
                double total = selectedCustomer->getOrderTotal();
                cout <<std::setprecision(2)<<std::fixed<< "Total R"<<total<<endl;
                cout << "========================================================================================" << endl;
                if (total == 0)
                {
                    cout << "No order to pay for" << endl;
                    removeCustomerByName(customers,customerName);
                    break;
                }
                cout << "How would you Like to Pay" << endl;
                cout << "1. Cash" << endl;
                cout << "2. Credit Card" << endl;
                int payChoice;
                cin >> payChoice;
                if (payChoice == 1 || payChoice == 2)
                {
                    /* code */
                    cout << "Are you splitting the Bill or not" << endl;
                    cout << "1. Yes" << endl;
                    cout << "2. No" << endl;
                    cout << "3. Tab" << endl;
                    int splitChoice;
                    cin >> splitChoice;

                    if (splitChoice == 1)
                    {
                        int size = selectedCustomer->getPartySize();
                        splitBill *bill = new splitBill(size);
                        selectedCustomer->setPaymentMethod(bill);
                        selectedCustomer->payOrder(selectedCustomer->getOrderTotal());
                    }
                    else if (splitChoice == 2)
                    {
                        int size = selectedCustomer->getPartySize();
                        oneBill *bill = new oneBill();
                        selectedCustomer->setPaymentMethod(bill);
                        selectedCustomer->payOrder(selectedCustomer->getOrderTotal());
                    }
                    else if (splitChoice == 3)
                    {
                        /* code */
                        Tab *tab = new Tab();
                        selectedCustomer->setPaymentMethod(tab);
                        selectedCustomer->payOrder(selectedCustomer->getOrderTotal());
                    }
                    else
                    {
                        cout << "Invalid Choice" << endl;
                    }
                }
                else
                {
                    cout << "Customer not found. Please enter a valid customer name." << endl;
                }
                removeCustomerByName(customers,customerName);
                cout << "Thank you for using the Restaurant Reservation System. Goodbye!" << endl;
                break;
            }
        }
        case 7:
        {
            // Check if there are customers
            if (customers.empty())
            {
                cout << "No customers available. Please add customers first." << endl;
                break;
            }

            // Ask the user to enter the name of the customer
            string customerName;
            cout << "Enter the name of the customer to order pizza for: ";
            cin.ignore(); // Clear the newline character
            getline(cin, customerName);

            // Find the customer by name
            Customer *selectedCustomer = nullptr;
            for (Customer &c : customers)
            {
                if (c.getName() == customerName)
                {
                    selectedCustomer = &c;
                    break;
                }
            }

            if (selectedCustomer != nullptr)
            {

                {
                    // Call the orderPizza method to handle pizza ordering for the selected customer
                    orderPizza(menu, toppings, *selectedCustomer, kitchen, allWaiters);
                }
            }
            else
            {
                cout << "Customer not found. Please enter a valid customer name." << endl;
            }
            break;
        }
        case 8:
        {
            // Exit the program
            cout << "Thank you for using the Restaurant Reservation System. Goodbye!" << endl;
            return 0;
        }
        case 9:
        {
            Customer *selectedCustomer = nullptr;
            cout << "Customers";
            for (Customer &c : customers)
            {
               cout << c.getName()<<endl;
            }
            break;
        }

        default:
        {
            cout << "Invalid choice. Please try again." << endl;
        }
        }
    }

    return 0;
}
