
#include "../../../headers/fights/states/FightActState.h"
#include "../../../headers/fights/states/FightActEnemySelectState.h"

ug::FightActState ug::FightActState::instance;

void ug::FightActState::handleEvent(sf::Event &event) {
    interfaceControlsInstance->handleEvent(event);
}

void ug::FightActState::update() {
    if(interfaceControlsInstance->isXKeyPressed()) {
        ug::FightActEnemySelectState::getInstance().loadFight(currentFight, lastEnemySelected);
        ug::UndertaleGame::getInstance()->getStateManager()->changeState(&ug::FightActEnemySelectState::getInstance());
        ug::UndertaleGame::getInstance()->getAudioManager()->playSound("SELECT_SOUND");
        interfaceControlsInstance->setXKeyPressed(false);
    }
}

void ug::FightActState::draw() {
    ug::FightInterface::getInstance().draw();
}

void ug::FightActState::load() {
    ug::FightInterface::getInstance().load();
    interfaceControlsInstance = &FightInterfaceControls::getInstance();
}

void ug::FightActState::initialize() {
    lastEnemySelected = ug::FightActEnemySelectState::getInstance().getCurrentEnemySelected();
    soulSprite.setTextureID("SOUL_SPRITE");
    //TODO set position
}

ug::FightActState &ug::FightActState::getInstance() {
    return instance;
}

void ug::FightActState::loadFight(Fight *fight){
    currentFight = fight;
}
