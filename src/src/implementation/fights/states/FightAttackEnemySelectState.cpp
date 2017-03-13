
#include "../../../headers/fights/FightInterface.h"
#include "../../../headers/fights/states/FightAttackEnemySelectState.h"
#include "../../../headers/fights/states/FightAttackState.h"

ug::FightAttackEnemySelectState ug::FightAttackEnemySelectState::instance;

ug::FightAttackEnemySelectState &ug::FightAttackEnemySelectState::getInstance() {
    return instance;
}

void ug::FightAttackEnemySelectState::loadFight(ug::Fight *fight) {
    currentEnemySelected = 0;
    currentFight = fight;
}

void ug::FightAttackEnemySelectState::loadFight(ug::Fight *fight, int currentlySelected) {
    currentEnemySelected = currentlySelected;
    currentFight = fight;
}

int ug::FightAttackEnemySelectState::getCurrentEnemySelected() const {
    return currentEnemySelected;
}

void ug::FightAttackEnemySelectState::initialize() {
    soulSprite.setTextureID("SOUL_SPRITE");
    soulSprite.setXPosition(65);
}

void ug::FightAttackEnemySelectState::handleEvent(sf::Event &event) {
    interfaceControlsInstance->handleEvent(event);
}

void ug::FightAttackEnemySelectState::load() {
    FightInterface::getInstance().load();
    interfaceControlsInstance = &FightInterfaceControls::getInstance();
}

void ug::FightAttackEnemySelectState::draw() {
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

        //TODO draw health bar

        ++enemiesIterator;
        ++currentIndex;
    } while (enemiesIterator != currentFight->getEnemies().end());

    soulSprite.setYPosition((278 + (currentEnemySelected * 32)));
    ug::UndertaleGame::getInstance()->getRenderer()->drawSprite(soulSprite);
}

void ug::FightAttackEnemySelectState::update() {
    if(interfaceControlsInstance->isXKeyPressed()) {
        ug::FightActionSelectState::getInstance().setFight(currentFight, ug::FightInterface::FIGHT);
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
        ug::FightAttackState::getInstance().loadFight(currentFight);
        ug::UndertaleGame::getInstance()->getStateManager()->changeState(&ug::FightAttackState::getInstance());
        interfaceControlsInstance->setZKeyPressed(false);
        ug::UndertaleGame::getInstance()->getAudioManager()->playSound("SELECT_SOUND");
    }
}
