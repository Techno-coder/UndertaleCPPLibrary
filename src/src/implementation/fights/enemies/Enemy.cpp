
#include "../../../headers/fights/enemies/Enemy.h"

std::vector<ug::ActCommand*>& ug::Enemy::getActCommands() {
    return actCommands;
}

void ug::Enemy::addActCommand(ug::ActCommand *const actCommand) {
    actCommands.push_back(actCommand);
}

void ug::Enemy::registerHandler(ug::EnemyEventHandler* handler) {
    enemyEventHandlers.push_back(handler);
}

void ug::Enemy::setCanSpare(bool spare) {
    canSpare = spare;
}

const bool &ug::Enemy::isCanSpare() {
    return canSpare;
}

ug::Enemy::Enemy(const std::string &enemyName) : Enemy(enemyName, enemyName) {
}

ug::Enemy ug::Enemy::clone() {
    Enemy temp(*this);
    return temp;
}

const std::string &ug::Enemy::getEnemyName() const {
    return enemyName;
}

ug::Enemy::Enemy(const std::string &enemyID, const std::string &enemyName) : enemyID(enemyID), enemyName(enemyName) {
}

const std::string &ug::Enemy::getEnemyID() const {
    return enemyID;
}

