#include <vector>
#include "Enemy.h"

unsigned long ug::Enemy::nextID;

ug::Enemy::Enemy(const ug::ProjectileSpawner &projectileSpawner, const unsigned long &ID) :
        projectileSpawner(projectileSpawner), ID(ID) {}
ug::Enemy::Enemy(const ug::ProjectileSpawner &projectileSpawner) : Enemy(projectileSpawner, nextID++) {}

ug::Enemy ug::Enemy::clone() const {
    Enemy t(projectileSpawner, ID);
    t.setName(t.getName());
    return t;
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

const ug::ProjectileSpawner &ug::Enemy::getProjectileSpawner() const {
    return projectileSpawner;
}
