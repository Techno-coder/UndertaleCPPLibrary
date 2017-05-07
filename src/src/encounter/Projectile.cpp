#include "Projectile.h"

ug::ProjectileInstance::ProjectileInstance(ug::Projectile &projectile) : projectile(&projectile) {}
ug::ProjectileInstance ug::Projectile::createInstance() {
    return ProjectileInstance(*this);
}

ug::Projectile& ug::ProjectileInstance::getProjectile() {
    return *projectile;
}
sf::Sprite &ug::Projectile::getSprite() {
    return sprite;
}

std::vector<ug::ProjectileInstance> ug::ProjectileSpawner::getInitialProjectiles() {
    return std::vector<ug::ProjectileInstance>();
}
std::vector<ug::ProjectileInstance> ug::ProjectileSpawner::getNewProjectiles() {
    return std::vector<ug::ProjectileInstance>();
}

void ug::ProjectileSpawner::onUpdate() {}
