#include <vector>
#include "Enemy.h"

unsigned long ug::Enemy::nextID;

ug::Enemy::Enemy(const ug::GetDamagersFunction &getDamagers, const unsigned long &ID) :
        getDamagersFunction(getDamagers), ID(ID) {}
ug::Enemy::Enemy(const ug::GetDamagersFunction &getDamagers) : Enemy(getDamagers, nextID++) {}

ug::Enemy ug::Enemy::clone() const {
    Enemy t(getDamagersFunction, ID);
    t.setName(t.getName());
    return t;
}

std::vector<ug::Damager> ug::Enemy::getDamagers(int frames) const {
    return getDamagersFunction(frames);
}

const std::string &ug::Enemy::getName() const {
    return name;
}
void ug::Enemy::setName(const std::string &name) {
    Enemy::name = name;
}

bool ug::Enemy::canSpare() const {
    return spareable;
}
void ug::Enemy::setCanSpare(bool canSpare) {
    Enemy::spareable = canSpare;
}
