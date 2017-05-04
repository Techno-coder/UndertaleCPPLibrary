#include "Player.h"

ug::Player::PlayerStatistics& ug::Player::getStatistics() {
    return playerStatistics;
}

ug::Inventory &ug::Player::getInventory() {
    return playerInventory;
}

ug::Player::Player() {
    Item testItem([](Player &player) {
        printf("ITEM ONE!!!");
    });
    playerInventory.addItem(testItem.clone());
    playerInventory.addItem(testItem.clone());
    playerInventory.addItem(testItem.clone());
}
