#include "Menu.h"
#include <vector>
#include <iostream>

void Menu::addItem(MenuItem* item) {
    items.push_back(item);
}

void Menu::displayMenu() const {
    std::cout << "Menu:\n";
    for (const auto item : items) {
        std::cout << "Item: " << item->getItemType() << ", Price: R" << item->getPrice() << std::endl;
    }
}

std::vector<MenuItem*> Menu::showItems(){
    return items;
}