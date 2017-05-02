
#include "../../headers/fights/Fight.h"
#include "../../headers/core/Logger.h"

void ug::Fight::registerHandler(ug::FightEventHandler *const handler) {
    handlers.push_back(handler);
}

void ug::Fight::addEnemy(ug::Enemy& enemy) {
    if(enemies.size() >= 3) {
        ug::Logger::instance().warning("FIGHT", "Only up to (and including) three enemies can be in a fight");
        return;
    }

    enemies.push_back(enemy);
}

void ug::Fight::removeEnemy(const std::string& enemyID) {
    for(auto it = enemies.begin(); it != enemies.end(); ++it) {
        if(it->getEnemyID() == enemyID) {
            enemies.erase(it);
            return;
        }
    }
}

std::vector<ug::Enemy> &ug::Fight::getEnemies() {
    return enemies;
}
