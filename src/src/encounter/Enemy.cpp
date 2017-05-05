#include "Enemy.h"

unsigned long ug::Enemy::nextID = 0;
unsigned long ug::Act::nextID = 0;

ug::Enemy::Enemy(const ug::ProjectileSpawner &projectileSpawner, const unsigned long &ID) :
        projectileSpawner(projectileSpawner), ID(ID) {}
ug::Enemy::Enemy(const ug::ProjectileSpawner &projectileSpawner) : Enemy(projectileSpawner, nextID++) {}

ug::Enemy ug::Enemy::clone() const {
    Enemy t(projectileSpawner, ID);
    t.getAttributes() = attributes;
    return t;
}

const ug::ProjectileSpawner &ug::Enemy::getProjectileSpawner() const {
    return projectileSpawner;
}

ug::Enemy::Attributes &ug::Enemy::getAttributes() {
    return attributes;
}

std::vector<ug::Act> &ug::Enemy::getActs() {
    return acts;
}

const std::string &ug::Act::getName() const {
    return name;
}
void ug::Act::setName(const std::string &name) {
    Act::name = name;
}

ug::Act::Act(ug::ActFunction action) : onAct(action), ID(nextID++) {}

void ug::Act::execute(ug::Enemy &enemy) {
    onAct(enemy);
}
