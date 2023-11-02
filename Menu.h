#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include <vector>

/**
 * @class MenuItem
 * @brief An abstract base class for menu items.
 */
class MenuItem {
    public:
        /**
        * Get the description of the menu item.
        * @return A string describing the menu item.
        */
        virtual std::string getItemType() const = 0;

        /**
        * Get the price of the menu item.
        * @return The price of the menu item.
        */
        virtual double getPrice() const = 0;
        

        /**
        * Virtual destructor for the menu item.
        */
        virtual ~MenuItem() {}
    private:
    

};

/**
 * @class Menu
 * @brief A class to manage and display a menu of items.
 */
class Menu {
    public:
        /**
        * Add a menu item to the menu.
        * @param item The menu item to add.
        */
        void addItem(MenuItem* item);

        /**
        * Display the entire menu to the console.
        */
        void displayMenu() const;

        size_t getItemsCount() const;
        MenuItem* getItem(int index) const;
        

    private:
        std::vector<MenuItem*> items; /**< The list of menu items. */
};

#endif
