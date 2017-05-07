#include <vector>
#include "Inventory.h"

static ug::Item EMPTY_ITEM([](ug::Player &player, ug::State &state){});

void ug::Inventory::addItem(const ug::Item &item) {
    items.emplace(item.getID(), item);
}

void ug::Inventory::removeItem(const unsigned long &itemID) {
    items.erase(itemID);
}

std::vector<ug::Item> ug::Inventory::getAllItems() {
    std::vector<ug::Item> temp;
    temp.reserve(items.size());
    for(auto element : items) {
        temp.push_back(element.second);
    }
    return temp;
}

ug::Item &ug::Inventory::getItem(const unsigned long &itemID) {
    auto it = items.find(itemID);
    return it != items.end() ? it->second : EMPTY_ITEM;
}
