// #include "Table.h"
// #include "TableComposite.h"
// #include "Customer.h"
// #include "MaitreD.h"
// #include "Reservation.h"
// #include "Waiter.h"
// #include <algorithm>
// #include <iostream>
// #include <string>
// using namespace std;

// // Function to display the main menu
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
//     cout << "6. Leave Table" << endl; // Added option for leaving the table
//     cout << "7. Exit" << endl;
//     cout << "=============================================" << endl;
//     cout << "Please enter your choice: ";
// }





// void viewWaiters(std::vector<Table>& allTables, std::vector<Waiter>& allWaiters)
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
//         for (Table& table : allTables)
//         {
//             if (table.getName() == tableName)
//             {
//                 Waiter* assignedWaiter = table.getWaiter();
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
//         for (Waiter& waiter : allWaiters)
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

// int main()
// {

//     std::vector<Customer> customers;
//     Customer *customerToRemove = nullptr;
//     // Create individual tables
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
//             //
//             // Customer customer = createCustomer(maitreD);
//             // customers.push_back(customer);
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
//             viewWaiters(allTables,allWaiters);
//             break;
//         }

//         case 6:
//         {

//             // Remove customer
//             removeCustomerByName(customers);
//             break;
//         }
//         case 7:
//         {
//             // Exit the program
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