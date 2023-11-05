#include "Command.h"
#include "Customer.h"
#include "CustomerProxy.h"
#include "Employee.h"
#include "Godfather.h"
#include "Handler.h"
#include "HeadChefHandler.h"
#include "Kitchen.h"
#include "Meal.h"
#include "Menu.h"
#include "OrderCommand.h"
#include "Pizza.h"
#include "Toppings.h"
#include "WaiterHandler.h"
#include <iostream>

// #include ""


// int main(){

//     //Create waiter
//     Waiter server("sandwich, Idiot",0);
//     // Create a kitchen.
//     HeadChef headChef("Gordon");
//     Kitchen kitchen(&headChef);
//     Toppings toppings;
//     // Create a customer.
//     Customer customer("sandwich, Idiot");
    
//     // Create a Godfather pizza.
//     Godfather godfatherPizza(toppings); // Assuming a base price of 15.0
//     godfatherPizza.addTopping("Figs");
//     godfatherPizza.addTopping("Mince");
//     godfatherPizza.addTopping("Olives");
//     godfatherPizza.addTopping("Mushrooms");

//     Command* orderCommand = new OrderCommand(kitchen, &godfatherPizza, &server, &customer);
    
    
//     // Place the order and execute it.
//     customer.placeOrder(orderCommand);

//     cout << endl;

//     // Display the customer's order.
//     customer.displayOrder();



//     // Get the total price of the order.
//     double total = customer.getOrderTotal();
//     cout << "Total Price: R" << total << endl;

//     return 0;


// }

#include <wx/wx.h>
#include "CustomOutputStreamBuffer.h" 

class WaiterNameFrame : public wxFrame
{
public:
    WaiterNameFrame(const wxString& title)
        : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(400, 200))
    {
        wxPanel* panel = new wxPanel(this);
        wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);

        wxButton* inputButton = new wxButton(panel, wxID_ANY, "Input Waiter Name");
        mainSizer->Add(inputButton, 1, wxALL | wxEXPAND, 10);

        nameInput = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER);
        nameInput->Hide();
        mainSizer->Add(nameInput, 1, wxALL | wxEXPAND, 10);

        submitButton = new wxButton(panel, wxID_ANY, "Submit");
        submitButton->Hide();
        mainSizer->Add(submitButton, 1, wxALL | wxEXPAND, 10);

        displayButton = new wxButton(panel, wxID_ANY, "Display Waiters");
        displayButton->Hide();
        mainSizer->Add(displayButton, 1, wxALL | wxEXPAND, 10);

        outputText = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | wxTE_READONLY);
        outputText->Hide();
        mainSizer->Add(outputText, 1, wxALL | wxEXPAND, 10);

        panel->SetSizerAndFit(mainSizer);

        waiterName = "";

        inputButton->Bind(wxEVT_BUTTON, &WaiterNameFrame::OnInputButton, this);
        nameInput->Bind(wxEVT_TEXT_ENTER, &WaiterNameFrame::OnSubmit, this);
        submitButton->Bind(wxEVT_BUTTON, &WaiterNameFrame::OnSubmit, this);
        displayButton->Bind(wxEVT_BUTTON, &WaiterNameFrame::OnDisplayWaiters, this);

        // Create the wxTextCtrl for displaying the output
        outputText = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | wxTE_READONLY);
        outputText->Hide();
        mainSizer->Add(outputText, 1, wxALL | wxEXPAND, 10);

        // Redirect std::cout to the custom stream buffer
        customOutputStreamBuffer = std::make_unique<CustomOutputStreamBuffer>(outputText);
        std::streambuf* originalBuffer = std::cout.rdbuf(customOutputStreamBuffer.get());
        originalBuffer_ = originalBuffer;
    }

    ~WaiterNameFrame()
    {
        // Restore the original std::cout streambuf
        std::cout.rdbuf(originalBuffer_);
    }

    void OnInputButton(wxCommandEvent& event)
    {
        nameInput->Show();
        submitButton->Show();
        displayButton->Hide(); // Hide the "Display Waiters" button
        Layout();
    }

    void OnSubmit(wxCommandEvent& event)
    {
        waiterName = nameInput->GetValue();
        nameInput->Hide();
        submitButton->Hide();
        Waiter server(waiterName.ToStdString(),0);
        cout<<"hello"<<endl;
        displayButton->Show(); // Show the "Display Waiters" button
        event.Skip(); // Allow default handling of the event
    }

    void OnDisplayWaiters(wxCommandEvent& event)
    {
        outputText->SetValue(waiterName);
        outputText->Show();
        Layout();
    }

private:
    wxString waiterName;
    wxTextCtrl* nameInput;
    wxButton* submitButton;
    wxButton* displayButton;
    wxTextCtrl* outputText;
    unique_ptr<CustomOutputStreamBuffer> customOutputStreamBuffer;
    streambuf* originalBuffer_;
};

class MyApp : public wxApp
{
public:
    virtual bool OnInit()
    {
        WaiterNameFrame* frame = new WaiterNameFrame("Waiter Name Input");
        frame->Show(true);
        return true;
    }
};

wxIMPLEMENT_APP(MyApp);