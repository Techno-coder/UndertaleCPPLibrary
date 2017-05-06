#include "FightEnemySelectState.h"
#include "FightAttackState.h"

ug::FightEnemySelectState::FightEnemySelectState(const std::shared_ptr<ug::Encounter> &encounter) :
        EnemySelectState(encounter) {
    EncounterState::setActiveButton(ActiveButton::FIGHT);
}

void ug::FightEnemySelectState::onEnter() {
    EnemySelectState::onEnter();
    generateHealthBars();
}

void ug::FightEnemySelectState::onDraw(sf::RenderWindow &window) {
    EnemySelectState::onDraw(window);
    for(auto healthBar : enemyHealthBars) {
        window.draw(healthBar);
    }
}

void ug::FightEnemySelectState::goToNextState(std::vector<Enemy>::iterator selectedEnemy) {
    std::unique_ptr<ug::State> temp(new FightAttackState(encounter, selectedEnemy));
    states->popState();
    states->changeState(std::move(temp));
}

void ug::FightEnemySelectState::generateHealthBars() {
    int currentIndex = 0;
    for(auto enemy : *enemyCache) {
        sf::RectangleShape maxHealth(sf::Vector2f(100, 20));
        maxHealth.setFillColor(sf::Color::Red);
        maxHealth.setPosition(275, 277 + (currentIndex * 32));

        int enemyHealth = enemy.getAttributes().health;
        int enemyMaxHealth = enemy.getAttributes().maxHealth;
        sf::RectangleShape health(sf::Vector2f(enemyHealth == 0 ? 100 : (enemyMaxHealth / (float) enemyMaxHealth), 20));
        health.setFillColor(sf::Color::Green);
        health.setPosition(275, 277 + (currentIndex * 32));

        enemyHealthBars.push_back(maxHealth);
        enemyHealthBars.push_back(health);

        ++currentIndex;
    }
}

ug::FightEnemySelectState::~FightEnemySelectState() {}
