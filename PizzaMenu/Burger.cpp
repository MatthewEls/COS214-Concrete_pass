#include "Burger.h"

Burger::Burger(std::string ItemType, double basePrice)
    : ItemType(ItemType), basePrice(basePrice) {}

std::string Burger::getItemType() const {
    return ItemType;
}

double Burger::getPrice() const {
    return basePrice;
}
