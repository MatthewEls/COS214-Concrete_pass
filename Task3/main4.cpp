// #include "Menu.h"
// #include "Toppings.h"
// #include "Pizza.h"
// #include "Godfather.h"
// #include "Margherita.h"
// #include "Miami.h"
// #include "Customer.h"
// #include "OrderCommand.h"
// #include "Kitchen.h"
// #include <iostream>
// #include <string>
// #include <vector>
// #include <algorithm>
// #include "Table.h"
// #include "TableComposite.h"
// #include "Waiter.h"

// using namespace std;

// void displayMainMenu()
// {
//     cout << "=============================================" << endl;
//     cout << "         Restaurant Reservation System       " << endl;
//     cout << "=============================================" << endl;
//     cout << "1. Make a Reservation" << endl;
//     cout << "2. Walk-in Customer" << endl;
//     cout << "3. Display Available Tables" << endl;
//     cout << "4. Display Reservations" << endl;
//     cout << "5. View Waiters Assigned to Tables" << endl;
//     cout << "6. Exit/Leave Table" << endl; // Merged Exit and Leave Table
//     cout << "7. Order Pizza" << endl;
//     cout << "=============================================" << endl;
//     cout << "Please enter your choice: ";
// }

// void viewWaiters(std::vector<Table> &allTables, std::vector<Waiter> &allWaiters)
// {
//     std::cout << "Do you want to view waiters for a specific table? (Y/N): ";
//     char choice;
//     std::cin >> choice;

//     if (choice == 'Y' || choice == 'y')
//     {
//         // Ask for the table's name
//         std::string tableName;
//         std::cout << "Enter the name of the table: ";
//         std::cin.ignore(); // Clear the newline character
//         std::getline(std::cin, tableName);

//         // Find the table by name and get its waiter
//         for (Table &table : allTables)
//         {
//             if (table.getName() == tableName)
//             {
//                 Waiter *assignedWaiter = table.getWaiter();
//                 if (assignedWaiter != nullptr)
//                 {
//                     std::cout << "Table " << tableName << " is served by " << assignedWaiter->getType() << std::endl;
//                 }
//                 else
//                 {
//                     std::cout << "Table " << tableName << " is not assigned to any waiter." << std::endl;
//                 }
//                 break; // Stop searching after finding the table
//             }
//         }
//     }
//     else
//     {
//         // View all waiters
//         for (Waiter &waiter : allWaiters)
//         {
//             waiter.serveTable();
//         }
//     }
// }

// void viewWaitersAssignedToTables(Waiter waiter)
// {
//     waiter.serveTable();
// }

// void addCustomerAndMakeReservation(std::vector<Customer> &customers, MaitreD &maitreD)
// {
//     std::string name;
//     int partySize;
//     std::string reservationTime;

//     std::cout << "Enter customer's name: ";
//     std::cin >> name;
//     std::cout << "Enter party size: ";
//     std::cin >> partySize;
//     std::cout << "Enter reservation time (e.g., 2023-10-31 18:30): ";
//     std::cin.ignore(); // Clear the newline character
//     std::getline(std::cin, reservationTime);

//     customers.push_back(Customer(name, partySize, &maitreD));
//     Customer &customer = customers.back(); // Get a reference to the newly added customer
//     customer.makeReservation(partySize, reservationTime);
//     customer.viewReservations();
// }

// // Function to remove a customer by name
// void removeCustomerByName(std::vector<Customer> &customers)
// {
//     std::string customerName;
//     std::cout << "Enter the name of the customer to remove from the table: ";
//     std::cin >> customerName;

//     // Find the customer by name
//     Customer *customerToRemove = nullptr;
//     for (Customer &customer : customers)
//     {
//         if (customer.getName() == customerName)
//         {
//             customerToRemove = &customer;
//             break;
//         }
//     }

//     if (customerToRemove)
//     {
//         customerToRemove->Leave(); // Remove the selected customer from the table
//     }
//     else
//     {
//         std::cout << "Customer not found." << std::endl;
//     }

//     auto it = std::remove_if(customers.begin(), customers.end(), [&customerName](const Customer &customer)
//                              { return customer.getName() == customerName; });

//     if (it != customers.end())
//     {
//         customers.erase(it, customers.end());
//         std::cout << "Customer " << customerName << " has been removed." << std::endl;
//     }
//     else
//     {
//         std::cout << "Customer not found." << std::endl;
//     }
// }

// // Function to split a string into individual toppings based on a delimiter
// vector<string> splitString(const string &input, char delimiter)

//     vector<string> tokens;
//     size_t start = 0;
//     size_t end = input.find(delimiter);

//     while (end != string::npos)
//     {
//         tokens.push_back(input.substr(start, end - start));
//         start = end + 1;
//         end = input.find(delimiter, start);
//     }

//     tokens.push_back(input.substr(start, end));

//     return tokens;
// }

// // Method to handle the pizza ordering process
// void orderPizza(Menu &menu, Toppings &toppings, Customer &customer, Kitchen &kitchen)
// {
//     while (true)
//     {
//         cout << "Welcome to the pizza menu. Please select a pizza from the menu (enter item number):" << endl;
//         menu.displayMenu();
//         cout << "Enter 0 to exit." << endl;

//         size_t choice;
//         cin >> choice;

//         if (choice == 0)
//         {
//             customer.displayOrder(); // Display the current order
//             cout << "Total Price: R" << customer.getOrderTotal() << endl;
//             cout << "Thank you for ordering. Goodbye!" << endl;
//             break;
//         }
//         else if (choice > 0 && choice <= menu.getItemsCount())
//         {
//             // Get the selected pizza
//             Pizza *selectedPizza = dynamic_cast<Pizza *>(menu.getItem(choice - 1));

//             if (selectedPizza)
//             {
//                 // Ask if the customer wants additional toppings
//                 cout << "Would you like to add additional toppings or drinks? (yes/no): ";
//                 string additionalToppingsChoice;
//                 cin >> additionalToppingsChoice;

//                 if (additionalToppingsChoice == "yes")
//                 {
//                     // Display available toppings
//                     toppings.displayToppingPrices();

//                     // Ask the user to select toppings
//                     cout << "Enter the topping(s) you want (comma-separated, e.g., Olives,Basil): ";
//                     cin.ignore(); // Consume the newline character
//                     string selectedToppings;
//                     getline(cin, selectedToppings);

//                     // Split the selected toppings into individual toppings
//                     vector<string> toppingsList = splitString(selectedToppings, ',');

//                     for (const string &topping : toppingsList)
//                     {
//                         selectedPizza->addTopping(topping);
//                     }
//                 }

//                 cout << "Your order for " << selectedPizza->getItemType() << " has been placed." << endl;
//                 Command *orderCommand = new OrderCommand(kitchen, selectedPizza);

//                 // Place the order
//                 customer.placeOrder(orderCommand);

//                 // Example: Get the description, price, and toppings of a specific pizza.
//                 cout << endl;
//                 cout << "\nDescription: " << selectedPizza->getItemType() << endl;
//                 vector<string> pizzaToppings = selectedPizza->listToppings();
//                 cout << "Additional Toppings (included in current price):\n";
//                 for (const string &topping : pizzaToppings)
//                 {
//                     double toppingPrice = toppings.getToppingPrice(topping); // Get the topping price.
//                     cout << topping << " (+ R" << toppingPrice << ")\n";
//                 }
//                 cout << endl;
//             }
//             else
//             {
//                 cout << "Invalid choice. Please select a valid pizza item." << endl;
//             }
//         }
//         else
//         {
//             cout << "Invalid choice. Please select a valid item number." << endl;
//         }
//     }
// }

// int main()
// {
//     // Create a Toppings object to manage toppings.
//     Toppings toppings;
//     Kitchen kitchen;
//     std::vector<Customer> customers;

//     Table table1("Table1");
//     Table table2("Table 2");
//     Table table3("Table 3");
//     Table table4("Table 4");
//     Table table5("Table 5");

//     Waiter waiter1("Waiter 1", 1000.0);
//     Waiter waiter2("Waiter 2", 950.0);
//     Waiter waiter3("Waiter 3", 900.0);
//     Waiter waiter4("Waiter 4", 850.0);
//     Waiter waiter5("Waiter 5", 800.0);

//     table1.setWaiter(&waiter1);

//     waiter1.assignTable(&table1);
//     waiter2.assignTable(&table2);
//     waiter3.assignTable(&table3);
//     waiter4.assignTable(&table4);
//     waiter5.assignTable(&table5);

//     std::vector<Waiter> allWaiters = {waiter1, waiter2, waiter3, waiter4, waiter5};
//     // Create MaitreD with tables
//     std::vector<Table> allTables = {table1, table2, table3, table4, table5};
//     MaitreD maitreD(allTables);

//     // Create instances of different pizza types.
//     Godfather godfatherPizza(toppings);
//     Margherita margheritaPizza(toppings);
//     Miami miamiPizza(toppings);

//     cout << "Instantiation/Creation of the 3 different base pizza types." << endl;
//     cout << endl;

//     Menu menu;
//     menu.addItem(&godfatherPizza);
//     menu.addItem(&margheritaPizza);
//     menu.addItem(&miamiPizza);

//     int choice;
//     while (true)
//     {
//         displayMainMenu();
//         cin >> choice;

//         switch (choice)
//         {
//         case 1:
//         {
//             // Add a customer and make a reservation
//             addCustomerAndMakeReservation(customers, maitreD);
//             break;
//         }
//         case 2:
//         {
//             // Walk-in customer
//             // Customer customer = createCustomer(maitreD);
//             // customers push_back(customer);
//             // customer.walkIn(customer.getName(), customer.getPartySize(), &maitreD);
//             break;
//         }
//         case 3:
//         {
//             // Display available tables
//             maitreD.displayAvailableTables();
//             break;
//         }
//         case 4:
//         {
//             // Display reservations
//             maitreD.displayReservations();
//             break;
//         }
//         case 5:
//         {
//             viewWaiters(allTables, allWaiters);
//             break;
//         }
//         case 6:
//         {
//             // Exit or Leave Table
//             if (customers.empty())
//             {
//                 cout << "No customers available. Please add customers first." << endl;
//                 break;
//             }

//             string customerName;
//             cout << "Enter the name of the customer to leave the table: ";
//             cin.ignore();
//             getline(cin, customerName);

//             Customer *selectedCustomer = nullptr;
//             for (Customer &c : customers)
//             {
//                 if (c.getName() == customerName)
//                 {
//                     selectedCustomer = &c;
//                     break;
//                 }
//             }

//             if (selectedCustomer != nullptr)
//             {
//                 selectedCustomer->Leave();
//                 cout << "Customer " << customerName << " has left the table." << endl;

//                 auto it = std::remove_if(customers.begin(), customers.end(), [&customerName](const Customer &customer)
//                 { return customer.getName() == customerName; });

//                 if (it != customers.end())
//                 {
//                     customers.erase(it, customers.end());
//                 }
//             }
//             else
//             {
//                 cout << "Customer not found. Please enter a valid customer name." << endl;
//             }
//             break;
//         }
//         case 7:
//         {
//             // Order pizza
//             if (customers.empty())
//             {
//                 cout << "No customers available. Please add customers first." << endl;
//                 break;
//             }

//             string customerName;
//             cout << "Enter the name of the customer to order pizza for: ";
//             cin.ignore();
//             getline(cin, customerName);

//             Customer *selectedCustomer = nullptr;
//             for (Customer &c : customers)
//             {
//                 if (c.getName() == customerName)
//                 {
//                     selectedCustomer = &c;
//                     break;
//                 }
//             }

//             if (selectedCustomer != nullptr)
//             {
//                 orderPizza(menu, toppings, *selectedCustomer, kitchen);
//             }
//             else
//             {
//                 cout << "Customer not found. Please enter a valid customer name." << endl;
//             }
//             break;
//         }
//         case 8:
//         {
//             cout << "Thank you for using the Restaurant Reservation System. Goodbye!" << endl;
//             return 0;
//         }
//         default:
//         {
//             cout << "Invalid choice. Please try again." << endl;
//         }
//         }
//     }

//     return 0;
// }
