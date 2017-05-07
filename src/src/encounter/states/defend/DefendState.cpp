#include "DefendState.h"
#include "DefendArenaSizeTransitionState.h"

ug::DefendState::DefendState(const std::shared_ptr<ug::Encounter> &encounter) : EncounterState(encounter) {}

void ug::DefendState::onDraw(sf::RenderWindow &window) {
    EncounterState::onDraw(window);
    for(auto &projectile : currentProjectiles) {
        window.draw(projectile.getSprite());
    }
}

void ug::DefendState::onEnter() {
    EncounterState::setActiveButton(ActiveButton::NONE);
    if(!alreadyEntered) {
        encounter->eventHandler->onDefendBegin(*this);
        if(!encounter->temporaryState.customArenaSize)
            states->pushState(std::unique_ptr<ug::State>(new ug::DefendArenaSizeTransitionState(encounter, sf::Vector2f(150, 150))));

        for(auto &enemy : encounter->getAllEnemies()) {
            auto projectiles = enemy.getProjectileSpawner().getInitialProjectiles();
            for(auto &projectile : projectiles) addProjectile(projectile);
        }
        alreadyEntered = true;
    }
    dialogueBox.setSize(encounter->temporaryState.desiredDefendArenaSize);
    dialogueBox.setOrigin(dialogueBox.getSize().x / 2, dialogueBox.getSize().y);
    dialogueBox.setPosition(encounter->temporaryState.endTransitionArenaPosition);
    soul.setPosition(dialogueBox.getPosition().x,
                                     dialogueBox.getPosition().y - (dialogueBox.getSize().y / 2));
}

void ug::DefendState::onUpdate() {
    EncounterState::onUpdate();
    for(auto &enemy : encounter->getAllEnemies()) {
        enemy.updateEvents();
        auto projectiles = enemy.getProjectileSpawner().getNewProjectiles();
        for(auto &projectile : projectiles) addProjectile(projectile);
    }
    for(auto &projectile : currentProjectiles) { projectile.update(*this); }
    encounter->eventHandler->onDefendUpdate(*this);
    handleEvents();
}

void ug::DefendState::onExit() {
    encounter->eventHandler->onDefendEnd(*this);
}

void ug::DefendState::handleEvents() {
    float soulMoveSpeed = player.getStatistics().soulMoveSpeed.getValue();
    if(State::controls.isKeyPressed(Controls::Keys::CANCEL)) soulMoveSpeed /= 2;
    if(State::controls.isKeyPressed(Controls::Keys::UP)) collideableMoveSoul(0, soulMoveSpeed * -1);
    if(State::controls.isKeyPressed(Controls::Keys::DOWN)) collideableMoveSoul(0, soulMoveSpeed * 1);
    if(State::controls.isKeyPressed(Controls::Keys::LEFT)) collideableMoveSoul(-1 * soulMoveSpeed, 0);
    if(State::controls.isKeyPressed(Controls::Keys::RIGHT)) collideableMoveSoul(1 * soulMoveSpeed, 0);
}

void ug::DefendState::collideableMoveSoul(float x, float y) {
    soul.move(x, y);
    if(soul.getPosition().x < dialogueBox.getGlobalBounds().left + 13) {
        soul.setPosition(dialogueBox.getGlobalBounds().left + 13, soul.getPosition().y);
    } else if(soul.getPosition().x > dialogueBox.getGlobalBounds().left + dialogueBox.getGlobalBounds().width - 13) {
        soul.setPosition(dialogueBox.getGlobalBounds().left + dialogueBox.getGlobalBounds().width - 13, soul.getPosition().y);
    } else if(soul.getPosition().y < dialogueBox.getGlobalBounds().top + 13) {
        soul.setPosition(soul.getPosition().x, dialogueBox.getGlobalBounds().top + 13);
    } else if(soul.getPosition().y > dialogueBox.getGlobalBounds().top + dialogueBox.getGlobalBounds().height - 13) {
        soul.setPosition(soul.getPosition().x, dialogueBox.getGlobalBounds().top + dialogueBox.getGlobalBounds().height - 13);
    }
}

void ug::DefendState::addProjectile(ug::Projectile &projectile) {
    projectile.getSprite().move(dialogueBox.getGlobalBounds().left + (dialogueBox.getGlobalBounds().width / 2),
                                dialogueBox.getGlobalBounds().top + (dialogueBox.getGlobalBounds().height / 2));
    currentProjectiles.push_back(projectile);
}
