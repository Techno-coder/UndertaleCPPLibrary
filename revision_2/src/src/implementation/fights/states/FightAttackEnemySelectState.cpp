
#include "../../../headers/fights/FightInterface.h"
#include "../../../headers/fights/states/FightActState.h"
#include "../../../headers/fights/states/FightActionSelectState.h"
#include "../../../headers/core/Logger.h"
#include "../../../headers/fights/states/FightAttackEnemySelectState.h"

ug::FightAttackEnemySelectState ug::FightAttackEnemySelectState::instance;

void ug::FightAttackEnemySelectState::initialize() {
    soulSprite.setTextureID("SOUL_SPRITE");
    soulSprite.setXPosition(65);
}

void ug::FightAttackEnemySelectState::handleEvent(sf::Event &event) {
    interfaceControlsInstance->handleEvent(event);
}

void ug::FightAttackEnemySelectState::update() {
    if(interfaceControlsInstance->isXKeyPressed()) {
        ug::FightActionSelectState::getInstance().loadFight(currentFight, ug::FightInterface::FIGHT);
        ug::UndertaleGame::getInstance()->getStateManager()->changeState(&ug::FightActionSelectState::getInstance());
        ug::UndertaleGame::getInstance()->getAudioManager()->playSound("MENU_MOVE_SOUND");
    }

    if(interfaceControlsInstance->isDownKeyPressed() && currentEnemySelected < (currentFight->getEnemies().size() - 1)) {
        ++currentEnemySelected;
        interfaceControlsInstance->setDownKeyPressed(false);
        ug::UndertaleGame::getInstance()->getAudioManager()->playSound("MENU_MOVE_SOUND");
    }

    if(interfaceControlsInstance->isUpKeyPressed() && currentEnemySelected > 0) {
        --currentEnemySelected;
        interfaceControlsInstance->setUpKeyPressed(false);
        ug::UndertaleGame::getInstance()->getAudioManager()->playSound("MENU_MOVE_SOUND");
    }

    if(interfaceControlsInstance->isZKeyPressed()) {
        // TODO load attack state
        interfaceControlsInstance->setZKeyPressed(false);
        ug::UndertaleGame::getInstance()->getAudioManager()->playSound("SELECT_SOUND");
    }
}

void ug::FightAttackEnemySelectState::draw() {
    FightInterface::getInstance().draw();

    auto enemiesIterator = currentFight->getEnemies().begin();
    int currentIndex = 0;
    while (enemiesIterator != currentFight->getEnemies().end()) {
        sf::Text asterix("*", ug::UndertaleGame::getInstance()->getResourceManager()->getFont("DETERMINATION_MONO_FONT"), 25);
        sf::Text option(enemiesIterator->getEnemyName(),
                        ug::UndertaleGame::getInstance()->getResourceManager()->getFont("DETERMINATION_MONO_FONT"), 25);
        asterix.setPosition(100, 270 + (currentIndex * 32));
        option.setPosition(130, 270 + (currentIndex * 32));

        sf::RectangleShape maxHealth(sf::Vector2f(100, 20));
        maxHealth.setFillColor(sf::Color::Red);
        maxHealth.setPosition(275, 277 + (currentIndex * 32));
        sf::RectangleShape health(sf::Vector2f(enemiesIterator->getMaxHealth() == 0 ? 100 :
                (enemiesIterator->getHealth() / (float) enemiesIterator->getMaxHealth()) * 100, 20));
        health.setFillColor(sf::Color::Green);
        health.setPosition(275, 277 + (currentIndex * 32));

        ug::UndertaleGame::getInstance()->getRenderer()->drawRawSprite(asterix);
        ug::UndertaleGame::getInstance()->getRenderer()->drawRawSprite(option);
        ug::UndertaleGame::getInstance()->getRenderer()->drawRawSprite(maxHealth);
        ug::UndertaleGame::getInstance()->getRenderer()->drawRawSprite(health);

        ++enemiesIterator;
        ++currentIndex;
    }

    soulSprite.setYPosition((278 + (currentEnemySelected * 32)));
    ug::UndertaleGame::getInstance()->getRenderer()->drawSprite(soulSprite);
}

void ug::FightAttackEnemySelectState::load() {
    FightInterface::getInstance().load();
    interfaceControlsInstance = &FightInterfaceControls::getInstance();
}

ug::FightAttackEnemySelectState &ug::FightAttackEnemySelectState::getInstance() {
    return instance;
}

void ug::FightAttackEnemySelectState::loadFight(ug::Fight *fight) {
    currentFight = fight;
}

void ug::FightAttackEnemySelectState::loadFight(ug::Fight *fight, int currentlySelected) {
    if(currentlySelected >= fight->getEnemies().size()) {
        currentEnemySelected = (int) fight->getEnemies().size() - 1;
        ug::Logger::instance().warning("ATTACK_ENEMY_SELECT", "Variable currentlySelected is larger than the amount of enemies");
    } else {
        currentEnemySelected = currentlySelected;
    }
    currentFight = fight;
}

int ug::FightAttackEnemySelectState::getCurrentEnemySelected() const {
    return currentEnemySelected;
}
