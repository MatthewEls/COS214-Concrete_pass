#include "GUIFrame.h"

using namespace std;

GUIFrame::GUIFrame() : wxFrame(NULL, wxID_ANY, "My App", wxDefaultPosition, wxSize(1280, 720))
    {
        // Create the background panel with an image
        wxPanel* backgroundPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);
        wxBitmap bitmap("Images/MainMenuBackground.jpg", wxBITMAP_TYPE_JPEG);
        wxStaticBitmap* background = new wxStaticBitmap(backgroundPanel, wxID_ANY, bitmap, wxDefaultPosition, wxDefaultSize);

        // Create a panel for input buttons
        wxPanel* headingPanel = new wxPanel(backgroundPanel, wxID_ANY, wxDefaultPosition, wxSize(500, 200));
        // Create a wxStaticText instance with your desired text
        wxStaticText* heading = new wxStaticText(headingPanel, wxID_ANY, "Welcome!", wxDefaultPosition, wxDefaultSize);

        // wxBoxSizer* headingsizer = new wxBoxSizer(wxVERTICAL);
        // headingsizer->Add(headingPanel, 0, wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 0);
        // headingPanel->SetSizer(headingsizer);

        wxBoxSizer* backgroundSizer = new wxBoxSizer(wxVERTICAL);
        backgroundSizer->Add(headingPanel, 0, wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL, 0);
        backgroundPanel->SetSizer(backgroundSizer);

        wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
        mainSizer->Add(backgroundPanel, 1, wxEXPAND);
        SetSizer(mainSizer);

    // Redirect cout to the text control
    //      std::streambuf* orig_cout = std::cout.oldCoutStreamBuf();
    // std::cout.oldCoutStreamBuf(textOutput->oldCoutStreamBuf());

    //     // // Show the frame
    //     // Show(true);
    }
    // void GUIFrame::initializegame(){
    // Table table1("Table1");
    // Table table2("Table 2");
    // Table table3("Table 3");
    // Table table4("Table 4");
    // Table table5("Table 5");

    // Waiter waiter1("Waiter 1", 1000.0);
    // Waiter waiter2("Waiter 2", 950.0);
    // Waiter waiter3("Waiter 3", 900.0);
    // Waiter waiter4("Waiter 4", 850.0);
    // Waiter waiter5("Waiter 5", 800.0);

    // table1.setWaiter(&waiter1);

    // waiter1.assignTable(&table1);
    // waiter2.assignTable(&table2);
    // waiter3.assignTable(&table3);
    // waiter4.assignTable(&table4);
    // waiter5.assignTable(&table5);

    // allWaiters = {waiter1, waiter2, waiter3, waiter4, waiter5};
    // // Create MaitreD with tables
    // allTables.push_back(&table1);

    // std::vector<Table> allTablesCopy;

    // for (Table* tablePtr : allTables) {
    //     if (tablePtr) {  // Check if the pointer is not null
    //         allTablesCopy.push_back(*tablePtr);  // Dereference the pointer and copy the Table object
    //     }
    // }

    // maitreD.addTablesToMaitreD(allTablesCopy);

    // // Create instances of different pizza types.
    // Godfather godfatherPizza(toppings);
    // Margherita margheritaPizza(toppings);
    // Miami miamiPizza(toppings);

    // cout << "Instantiation/Creation of the 3 different base pizza types." << endl;
    // cout << endl;

    // Menu menu;
    // menu.addItem(&godfatherPizza);
    // menu.addItem(&margheritaPizza);
    // menu.addItem(&miamiPizza);
    // }



    // void GUIFrame::Onbutton_make_reservationClick(wxCommandEvent& event)
    // {
    //     wxString inputText = textInput->GetValue();
    //     textOutput->AppendText(inputText + "\n");
    //     textInput->Clear();

    //     // // Create a new frame when Button 1 is pressed
    //     // MyFrame* newFrame = new MyFrame();
    //     // newFrame->Show(true);
    // }



    // void GUIFrame::Onbutton_walk_inClick(wxCommandEvent& event)
    // {
    //     // Walk-in customer
    //     // Customer customer = createCustomer(maitreD);
    //     // customers push_back(customer);
    //     // customer.walkIn(customer.getName(), customer.getPartySize(), &maitreD);
    // }

    // void GUIFrame::Onbutton_display_tablesClick(wxCommandEvent& event)
    // {
    //     // Display available tables
    //     maitreD.displayAvailableTables();
    // }

    // void GUIFrame::Onbutton_display_reservationsClick(wxCommandEvent& event)
    // {
    //     // Display reservations
    //     maitreD.displayReservations();
    // }
    // void GUIFrame::Onbutton_view_waitersClick(wxCommandEvent& event)
    // {
    //     // View waiters
    //     // viewWaiters(allTables, allWaiters);
    // }
    // void GUIFrame::Onbutton_leave_tableClick(wxCommandEvent& event)
    // {
    //     // Close all frames when Button 2 is pressed
    //     Close(true);
    // }

    // void GUIFrame::Onbutton_order_pizzaClick(wxCommandEvent& event)
    // {
    //     // Close all frames when Button 2 is pressed
    //     Close(true);
    // }

    // void GUIFrame::Onbutton_closeClick(wxCommandEvent& event)
    // {
    //     // Close all frames when Button 2 is pressed
    //     Close(true);
    // }

    GUIFrame::~GUIFrame() {
        // Restore the original cout stream buffer
        std::cout.rdbuf(oldCoutStreamBuf);
    }
