// #include "Customer.h"
// #include "MaitreD.h"
// #include "Table.h"
// #include "Reservation.h"
// #include <iostream>
// #include <vector>
// #include <algorithm>

// // Function to add a customer and make a reservation
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
//     Customer* customerToRemove = nullptr;
//     for (Customer& customer : customers) {
//         if (customer.getName() == customerName) {
//             customerToRemove = &customer;
//             break;
//         }
//     }

//     if (customerToRemove) {
//         customerToRemove->Leave(); // Remove the selected customer from the table
//     } else {
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
//     // Create a MaitreD and tables
//     std::vector<Table> allTables;
//     for (int i = 1; i <= 5; i++)
//     {
//         allTables.push_back(Table("Table " + std::to_string(i)));
//     }

//     MaitreD maitreD(allTables);

//     std::vector<Customer> customers; // Vector to store customers

//     int choice;
//     while (true)
//     {
//         // Display the main menu
//         std::cout << "=============================================" << std::endl;
//         std::cout << "         Restaurant Reservation System       " << std::endl;
//         std::cout << "=============================================" << std::endl;
//         std::cout << "1. Add Customer and Make Reservation" << std::endl;
//         std::cout << "2. Remove Customer" << std::endl;
//         std::cout << "3. Exit" << std::endl;
//         std::cout << "=============================================" << std::endl;
//         std::cout << "Please enter your choice: ";
//         std::cin >> choice;

//         switch (choice)
//         {
//         case 1:
//             // Add a customer and make a reservation
//             addCustomerAndMakeReservation(customers, maitreD);
//             break;
//         case 2:
//             // Remove a customer by name
//             removeCustomerByName(customers);
//             break;
//         case 3:
//             std::cout << "Thank you for using the Restaurant Reservation System. Goodbye!" << std::endl;
//             return 0;
//         default:
//             std::cout << "Invalid choice. Please try again." << std::endl;
//         }
//     }

//     return 0;
// }
