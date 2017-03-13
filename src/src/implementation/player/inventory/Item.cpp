
#include "../../../headers/player/inventory/Item.h"

ug::Item::Item(const std::string &itemID, const std::string &itemName) : itemID(itemID), itemName(itemName) {
}

ug::Item::Item(const std::string &itemName) : Item(itemName, itemName) {
}

const std::string &ug::Item::getItemID() {
    return itemID;
}

const std::string &ug::Item::getItemName() {
    return itemName;
}
