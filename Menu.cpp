#include "Menu.h"

void Menu::addItem(MenuItem* item) {
    items.push_back(item);
}

void Menu::displayMenu() const {
    std::cout << "Menu:\n";
    for (const auto item : items) {
        std::cout << "Item: " << item->getItemType() << ", Price: R" << item->getPrice() << std::endl;
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

