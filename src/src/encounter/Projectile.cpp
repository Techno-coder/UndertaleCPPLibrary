#include "Projectile.h"

sf::Sprite &ug::Projectile::getSprite() {
    return sprite;
}

ug::Projectile ug::Projectile::clone(Projectile toBeCloned) {
    return toBeCloned;
}

void ug::Projectile::collide(ug::EncounterState &state) {
    onCollide(state, *this);
}

void ug::Projectile::update(ug::EncounterState &state) {
    onUpdate(state, *this);
}

void ug::Projectile::setOnCollide(const ug::ProjectileEventHandler &onCollide) {
    Projectile::onCollide = onCollide;
}

void ug::Projectile::setOnUpdate(const ug::ProjectileEventHandler &onUpdate) {
    Projectile::onUpdate = onUpdate;
}
