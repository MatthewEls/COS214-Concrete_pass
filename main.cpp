#include "Table.h"
#include "TableComposite.h"
#include "Customer.h"
#include "MaitreD.h"
#include "Reservation.h"  
#include "paymentMethod.h"
#include "oneBill.cpp"
#include "splitBill.cpp"
#include "NotReadyState.h"
#include "Tab.cpp"
#include "ReadyState.h"

#include <iostream>
#include <string>
using namespace std;

// Function to display the main menu
void displayMainMenu() {
    cout << "=============================================" << endl;
    cout << "         Restaurant Reservation System       " << endl;
    cout << "=============================================" << endl;
    cout << "1. Make a Reservation" << endl;
    cout << "2. Walk-in Customer" << endl;
    cout << "3. Display Available Tables" << endl;
    cout << "4. Display Reservations" << endl;
    cout << "5. leave Table" << endl;
    cout << "6. Exit"<<endl;
    cout << "=============================================" << endl;
    cout << "Please enter your choice: ";
}

// Function to create a new customer
Customer createCustomer(MaitreD& maitreD) {
    string name;
    int partySize;
    int paymentChoice;
    cout << "Enter customer's name: ";
    cin >> name;
    cout << "Enter party size: ";
    cin >> partySize;

    cout << "Choose a payment method:" << endl;
    cout << "1. One person pays the whole amount" << endl;
    cout << "2. Split the bill" << endl;
    cout << "3. Add to the tab" << endl;
    cout << "Enter your choice: ";
    cin >> paymentChoice;

    Customer customer(name, partySize, &maitreD);

    switch (paymentChoice)
    {
    case 1:
        customer.setPaymentMethod(new oneBill());
        cout << "One bill"<< endl;
        break;
    case 2:
        customer.setPaymentMethod(new splitBill(partySize));
        cout << "Split the bill"<< endl;
        break;
    case 3:
        customer.setPaymentMethod(new Tab());
        cout << "On tab" << endl;
        break;
    default:
        cout << "Invalid payment method. No payment strategy set." << endl;
    }

    return customer;
}

int main() {
    // Create individual tables
    Table table1("Table1");
    Table table2("Table 2");
    Table table3("Table 3");
    Table table4("Table 4");
    Table table5("Table 5");

    // Create MaitreD with tables
    // std::vector<Table> allTables = {table1, table2, table3, table4, table5};
    std::vector<Table> allTables;
    allTables.push_back(table1);
    allTables.push_back(table2);
    allTables.push_back(table3);
    allTables.push_back(table4);
    allTables.push_back(table5);

    MaitreD maitreD(allTables);

    int choice;
    while (true) {
        displayMainMenu();
        cin >> choice;

        switch (choice) {
            case 1: {
                // Make a reservation
                Customer customer = createCustomer(maitreD);
                string reservationTime;
                cout << "Enter reservation time (e.g., 2023-10-31 18:30): ";
                cin >> reservationTime;
                // Update the reservation to include the payment strategy
               // customer.choosePaymentMethod();
                customer.makeReservation(customer.getPartySize(), reservationTime);
                break;
            }
            case 2: {
                // Walk-in customer
                Customer customer = createCustomer(maitreD);
                customer.walkIn(customer.getName(), customer.getPartySize(), &maitreD);
                break;
            }
            case 3: {
                // Display available tables
                maitreD.displayAvailableTables();
                break;
            }
            case 4: {
                // Display reservations
                maitreD.displayReservations();
                break;
            }
            case 5: {
                // Leave Table
                cout << "Enter the name of the table to leave: ";
                string TableName;
                cin >> TableName;

                for (Table &table : allTables)
                {
                    if (table.getName() == TableName)
                    {
                        // Prompt the user to set the customer's state
                        int stateChoice;
                        cout << "Is the customer ready to order? (1 for Yes, 0 for No): ";
                        cin >> stateChoice;

                        if (stateChoice == 1)
                        {
                            // Set the customer's state to "Ready"
                            table.changeState(new ReadyState());
                            table.notifyWaiters();
                        }
                        else if (stateChoice == 0)
                        {
                            // Set the customer's state to "Not Ready"
                            table.changeState(new NotReadyState());
                            cout << "The customer is not ready to order. Waiter will come back later." << endl;
                        }
                        else
                        {
                            cout << "Invalid choice. Please enter 1 for Yes or 0 for No." << endl;
                        }

                        /// Prompt the user to set the bill amount
                        double billAmount;
                        cout << "Enter the bill amount for the table: ";
                        cin >> billAmount;
                        table.setBillAmount(billAmount);

                        // Free the table when the customer leaves
                        table.freeTable();
                        break;
                    }
                }
                break;
            }
            // case 6:
            // {
            //     tState *currentState = table1.getSt();
            //     if (currentState && currentState->getSt() == "Not Ready")
            //     {
            //         cout<< "The Customer is not ready" << endl;
            //         table1.changeState(new ReadyState());
            //         table1.notifyWaiters();
            //     }
            //     break;
            // }
            case 6:
            {
                // Exit the program
                cout << "Thank you for using the Restaurant Reservation System. Goodbye!" << endl;
                return 0;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
            }
        }
    }




  

    return 0;
}
