#include "Enemy.h"

ug::Enemy::Enemy(const ug::GetDamagersFunction &getDamagers, const unsigned long &ID) :
        getDamagersFunction(getDamagers), ID(ID) {}

ug::Enemy::Enemy(const ug::GetDamagersFunction &getDamagers) : Enemy(getDamagers, nextID++){}

ug::Enemy ug::Enemy::clone() const {
    Enemy t(getDamagers, ID);
    t.setName(t.getName());
    return t;
}

std::vector<Damager> ug::Enemy::getDamagers(int frames) const {
    return getDamagersFunction(frames);
}

const std::string &ug::Enemy::getName() const {
    return name;
}

void ug::Enemy::setName(const std::string &name) {
    Enemy::name = name;
}
