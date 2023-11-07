#include "Menu.h"
#include <iomanip>

void Menu::addItem(MenuItem* item) {
    items.push_back(item);
}

void Menu::displayMenu() const {
    std::cout << "Menu:\n";
    int itemNo=1;
    for (const auto item : items) {
        std::cout <<std::setprecision(2)<<std::fixed;
        std::cout << "Item #"<<itemNo<<": " << item->getItemType() << "\tPrice: R" << item->getPrice() << std::endl;
        itemNo++;
    }
}
size_t Menu::getItemsCount() const {
    return items.size();
}

MenuItem* Menu::getItem(int index) const {
    if (index >= 0 && static_cast<size_t>(index) < items.size()) {
        return items[index];
    }
    return nullptr; // Return nullptr for an invalid index.
}

std::vector<MenuItem*> Menu::showItems(){
    return items;
}