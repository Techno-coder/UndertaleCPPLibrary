#include "Player.h"

ug::Player::PlayerStatistics& ug::Player::getStatistics() {
    return playerStatistics;
}

ug::Inventory &ug::Player::getInventory() {
    return playerInventory;
}

ug::Player::Player() {
    Item testItem([](Player &player, State &state) {
        printf("POWOWOWOAODSO");
        player.getStatistics().health.setValue(player.getStatistics().health.getValue() + 10);
    });
    playerInventory.addItem(testItem.clone());
    playerInventory.addItem(testItem.clone());
    playerInventory.addItem(testItem.clone());
}
