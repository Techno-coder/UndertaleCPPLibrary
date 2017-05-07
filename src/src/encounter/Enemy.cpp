#include "Enemy.h"

unsigned long ug::Enemy::nextID = 0;
unsigned long ug::Act::nextID = 0;

ug::Enemy::Enemy(const ug::ProjectileSpawner &projectileSpawner, sf::Sprite sprite, const unsigned long &ID) :
        projectileSpawner(projectileSpawner), ID(ID), sprite(sprite) {
    attributes.health.registerObserver(&defaultObservers.onDeath);
    attributes.health.registerObserver(&defaultObservers.onDamaged);
}
ug::Enemy::Enemy(const ug::ProjectileSpawner &projectileSpawner, sf::Sprite sprite) : Enemy(projectileSpawner, sprite, nextID++) {}

ug::Enemy ug::Enemy::clone(sf::Vector2f position) const {
    Enemy t(projectileSpawner, sprite, ID);
    t.getSprite().setPosition(position);
    t.getAttributes().name = attributes.name;
    t.getAttributes().defense = attributes.defense;
    t.getAttributes().spareable = attributes.spareable;
    t.getAttributes().maxHealth.setValue(attributes.maxHealth.getValue(), false);
    t.getAttributes().health.setValue(attributes.health.getValue(), false);
    t.getActs() = acts;
    return t;
}

ug::ProjectileSpawner &ug::Enemy::getProjectileSpawner() {
    return projectileSpawner;
}

ug::Enemy::Attributes &ug::Enemy::getAttributes() {
    return attributes;
}

std::vector<ug::Act> &ug::Enemy::getActs() {
    return acts;
}

sf::Sprite &ug::Enemy::getSprite() {
    return sprite;
}

ug::Enemy::Enemy(const ug::ProjectileSpawner &projectilesSpawner, sf::Sprite sprite,
                 ug::EnemyEventHandler eventHandler) : Enemy(projectilesSpawner, sprite) {
    Enemy::eventHandler = eventHandler;
}

void ug::Enemy::setEventHandler(const ug::EnemyEventHandler &eventHandler) {
    Enemy::eventHandler = eventHandler;
}

void ug::Enemy::updateEvents() {
    eventHandler.onUpdate(*this);
    projectileSpawner.onUpdate();
}

ug::Enemy::~Enemy() {
    attributes.health.unregisterObserver(&defaultObservers.onDeath);
    attributes.health.unregisterObserver(&defaultObservers.onDamaged);
}

const std::string &ug::Act::getName() const {
    return name;
}
void ug::Act::setName(const std::string &name) {
    Act::name = name;
}

ug::Act::Act(ug::ActFunction action) : onAct(action), ID(nextID++) {}

void ug::Act::execute(ug::EncounterState &state) {
    onAct(state);
}

ug::Enemy::Observers::Observers(ug::Enemy *instance) : instance(instance) {}
