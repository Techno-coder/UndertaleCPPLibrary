
#include "../../../headers/fights/states/FightActEnemySelectState.h"
#include "../../../headers/fights/FightInterface.h"
#include "../../../headers/fights/states/FightActState.h"
#include "../../../headers/fights/states/FightActionSelectState.h"

ug::FightActEnemySelectState ug::FightActEnemySelectState::instance;

void ug::FightActEnemySelectState::initialize() {
    soulSprite.setTextureID("SOUL_SPRITE");
    soulSprite.setXPosition(65);
}

void ug::FightActEnemySelectState::handleEvent(sf::Event &event) {
    interfaceControlsInstance->handleEvent(event);
}

void ug::FightActEnemySelectState::update() {
    if(interfaceControlsInstance->isXKeyPressed()) {
        ug::FightActionSelectState::getInstance().loadFight(currentFight, ug::FightInterface::ACT);
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
        ug::FightActState::getInstance().loadFight(currentFight);
        ug::UndertaleGame::getInstance()->getStateManager()->changeState(&ug::FightActState::getInstance());
        interfaceControlsInstance->setZKeyPressed(false);
        ug::UndertaleGame::getInstance()->getAudioManager()->playSound("SELECT_SOUND");
    }
}

void ug::FightActEnemySelectState::draw() {
    FightInterface::getInstance().draw();

    auto enemiesIterator = currentFight->getEnemies().begin();
    int currentIndex = 0;
    do {
        sf::Text asterix("*", ug::UndertaleGame::getInstance()->getResourceManager()->getFont("DETERMINATION_MONO_FONT"), 25);
        sf::Text option(enemiesIterator->getEnemyName(),
                        ug::UndertaleGame::getInstance()->getResourceManager()->getFont("DETERMINATION_MONO_FONT"), 25);
        asterix.setPosition(100, 270 + (currentIndex * 32));
        option.setPosition(130, 270 + (currentIndex * 32));
        ug::UndertaleGame::getInstance()->getRenderer()->drawRawSprite(asterix);
        ug::UndertaleGame::getInstance()->getRenderer()->drawRawSprite(option);
        ++enemiesIterator;
        ++currentIndex;
    } while (enemiesIterator != currentFight->getEnemies().end());

    soulSprite.setYPosition((278 + (currentEnemySelected * 32)));
    ug::UndertaleGame::getInstance()->getRenderer()->drawSprite(soulSprite);
}

void ug::FightActEnemySelectState::load() {
    FightInterface::getInstance().load();
    interfaceControlsInstance = &FightInterfaceControls::getInstance();
}

ug::FightActEnemySelectState &ug::FightActEnemySelectState::getInstance() {
    return instance;
}

void ug::FightActEnemySelectState::loadFight(ug::Fight *fight) {
    currentEnemySelected = 0;
    currentFight = fight;
}

void ug::FightActEnemySelectState::loadFight(ug::Fight *fight, int currentlySelected) {
    currentEnemySelected = currentlySelected;
    currentFight = fight;
}

int ug::FightActEnemySelectState::getCurrentEnemySelected() const {
    return currentEnemySelected;
}
