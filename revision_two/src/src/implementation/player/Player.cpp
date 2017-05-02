
#include "../../headers/player/Player.h"
#include "../../headers/player/inventory/Item.h"


ug::PlayerStats& ug::Player::getPlayerStats() {
    return playerStats;
}

std::vector<ug::Item> &ug::Player::getInventory() {
    return inventory;
}

void ug::Player::addItem(ug::Item &item) {
    inventory.push_back(item);
}
