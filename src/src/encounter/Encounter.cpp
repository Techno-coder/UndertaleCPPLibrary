#include "Encounter.h"

void ug::Encounter::addEnemy(Enemy enemy) {
    enemies.push_back(enemy);
}

std::vector<ug::Enemy>& ug::Encounter::getAllEnemies() {
    return enemies;
}

ug::Encounter::Encounter() : eventHandler(new EncounterEventHandler) {}
