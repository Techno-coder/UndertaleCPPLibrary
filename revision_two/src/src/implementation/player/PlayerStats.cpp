
#include "../../headers/player/PlayerStats.h"

void ug::PlayerStats::setLevel(const int& newLevel) {
    int oldLevel = level;
    level = newLevel;
    for(PlayerStatsHandler* handler : handlers) {
        handler->onLevelChange(oldLevel, newLevel);
    }
}

const int& ug::PlayerStats::getLevel() {
    return level;
}

void ug::PlayerStats::setExp(const int& newExp) {
    int oldExp = exp;
    exp = newExp;
    for(PlayerStatsHandler* handler : handlers) {
        handler->onExpChange(oldExp, newExp);
    }
}

void ug::PlayerStats::registerHandler(ug::PlayerStatsHandler *const handler) {
    handlers.push_back(handler);
}

const int &ug::PlayerStats::getExp() {
    return exp;
}

void ug::PlayerStats::addExp(const int &addAmount) {
    setExp(exp + addAmount);
}

void ug::PlayerStats::setMaxHealth(const int &newMaxHealth) {
    int oldMaxHealth = maxHealth;
    maxHealth = newMaxHealth;
    for(PlayerStatsHandler* handler : handlers) {
        handler->onMaxHealthChange(oldMaxHealth, newMaxHealth);
    }
}

const int &ug::PlayerStats::getMaxHealth() {
    return maxHealth;
}

void ug::PlayerStats::setHealth(const int &newHealth, const bool &ignoreMaxHealth) {
    int oldHealth = health;
    int tempNewHealth = newHealth;
    if(!ignoreMaxHealth && newHealth > maxHealth) {
        tempNewHealth = maxHealth;
    }
    health = tempNewHealth;
    for(PlayerStatsHandler* handler : handlers) {
        handler->onHealthChange(oldHealth, tempNewHealth);
    }
}

void ug::PlayerStats::addHealth(const int &addAmount) {
    setHealth(addAmount, false);
}

void ug::PlayerStats::removeHealth(const int &removeAmount) {
    setHealth(health - removeAmount, false);
}

const int &ug::PlayerStats::getHealth() {
    return health;
}

void ug::PlayerStats::setDefense(const int &newDefense) {
    int oldDefense = defense;
    defense = newDefense;
    for(PlayerStatsHandler* handler : handlers) {
        handler->onDefenseChange(oldDefense, newDefense);
    }
}

const int &ug::PlayerStats::getDefense() {
    return defense;
}

void ug::PlayerStats::setAttack(const int &newAttack) {
    int oldAttack = attack;
    attack = newAttack;
    for(PlayerStatsHandler* handler : handlers) {
        handler->onAttackChange(oldAttack, newAttack);
    }
}

const int &ug::PlayerStats::getAttack() {
    return attack;
}

void ug::PlayerStats::setName(const std::string &newName) {
    std::string oldName = name;
    std::transform(newName.begin(), newName.end(), name.begin(), toupper);
    for(PlayerStatsHandler* handler : handlers) {
        handler->onNameChange(oldName, name);
    }
}

const std::string &ug::PlayerStats::getName() {
    return name;
}
