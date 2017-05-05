#include "Projectile.h"

ug::ProjectileInstance::ProjectileInstance(const ug::Projectile &projectile) : projectile(projectile) {}
ug::ProjectileInstance ug::Projectile::createInstance() {
    return ProjectileInstance(*this);
}

ug::Projectile const& ug::ProjectileInstance::getProjectile() {
    return projectile;
}
const sf::Sprite &ug::Projectile::getSprite() const {
    return sprite;
}

std::vector<ug::ProjectileInstance> ug::ProjectileSpawner::getInitialProjectiles() {
    return std::vector<ug::ProjectileInstance>();
}
std::vector<ug::ProjectileInstance> ug::ProjectileSpawner::getNewProjectiles() {
    return std::vector<ug::ProjectileInstance>();
}
