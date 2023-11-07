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
// #include "Table.h"
// #include "TableComposite.h"
// #include "Waiter.h"
// #include "WalkInStrategy.h"

// class RestaurantFacade {
// public:
//     RestaurantFacade() {
//         // Initialize your reservation system, tables, waiters, and other components
//     }

//     void addCustomerAndMakeReservation(std::vector<Customer> &customers) {
//         // Implement the logic to add a customer and make a reservation
//     }

//     void addCustomerAndMakeWalkin(std::vector<Customer> &customers) {
//         // Implement the logic to add a customer and make a walk-in reservation
//     }

//     void displayAvailableTables() {
//         // Implement the logic to display available tables
//     }

//     void displayReservations() {
//         // Implement the logic to display reservations
//     }

//     void viewWaiters(std::vector<Table> &allTables, std::vector<Waiter> &allWaiters) {
//         // Implement logic to view waiters for tables
//     }

//     void removeCustomerByName(std::vector<Customer> &customers) {
//         // Implement logic to remove a customer by name
//     }

//     void orderPizza(Menu &menu, Toppings &toppings, Customer &customer, Kitchen &kitchen, std::vector<Waiter> &waiter) {
//         // Implement the logic to handle pizza ordering
//     }

//     void mainLoop() {
//         while (true) {
//             displayMainMenu();

//             int choice;
//             cin >> choice;

//             switch (choice) {
//                 case 1:
//                     addCustomerAndMakeReservation(customers);
//                     break;
//                 case 2:
//                     addCustomerAndMakeWalkin(customers);
//                     break;
//                 case 3:
//                     displayAvailableTables();
//                     break;
//                 case 4:
//                     displayReservations();
//                     break;
//                 case 5:
//                     viewWaiters(allTables3, allWaiters);
//                     break;
//                 case 6:
//                     removeCustomerByName(customers);
//                     cout << "Thank you for using the Restaurant Reservation System. Goodbye!" << endl;
//                     return;
//                 case 7:
//                     orderPizza(menu, toppings, *selectedCustomer, kitchen, allWaiters);
//                     break;
//                 default:
//                     cout << "Invalid choice. Please try again." << endl;
//             }
//         }
//     }

//     ~RestaurantFacade() {
//         // Clean up resources and perform necessary cleanup
//     }
// };

