#ifndef GUIFRAME_H
#define GUIFRAME_H

#include "Menu.h"
#include "Toppings.h"
#include "Pizza.h"
#include "Godfather.h"
#include "Customer.h"
#include "OrderCommand.h"
#include "Kitchen.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Waiter.h"
#include <wx/wx.h>
#include <streambuf>

class GUIFrame : public wxFrame
{

public:
    // Toppings toppings;
    // Kitchen kitchen;
    // std::vector<Customer> customers;
    // std::vector<Waiter> allWaiters;
    // std::vector<Table*> allTables;
    // MaitreD maitreD;
    GUIFrame();
    ~GUIFrame();
    // void initializegame();
    // void Onbutton_make_reservationClick(wxCommandEvent& event);
    // void Onbutton_walk_inClick(wxCommandEvent& event);
    // void Onbutton_display_tablesClick(wxCommandEvent& event);
    // void Onbutton_display_reservationsClick(wxCommandEvent& event);
    // void Onbutton_view_waitersClick(wxCommandEvent& event);
    // void Onbutton_leave_tableClick(wxCommandEvent& event);
    // void Onbutton_order_pizzaClick(wxCommandEvent& event);
    // void Onbutton_closeClick(wxCommandEvent& event);
    


    private:
    wxTextCtrl* textInput;
    wxTextCtrl* textOutput;
    std::streambuf* oldCoutStreamBuf;
};


#endif