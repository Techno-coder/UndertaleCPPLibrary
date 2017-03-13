
#include <SFML/Window/Event.hpp>
#include "../../../headers/fights/states/FightActEnemySelectState.h"
#include "../../../headers/core/Logger.h"
#include "../../../headers/fights/states/FightActionSelectState.h"

ug::FightActionSelectState ug::FightActionSelectState::instance;

void ug::FightActionSelectState::initialize() {
    soulSprite.setTextureID("SOUL_SPRITE");
    soulSprite.setYPosition(444);
}

void ug::FightActionSelectState::handleEvent(sf::Event &event) {
    interfaceControlsInstance->handleEvent(event);
}

void ug::FightActionSelectState::update() {
    if(interfaceControlsInstance->isZKeyPressed()) {
        //TODO finish change states
        switch (interfaceInstance->getCurrentlySelectedButton()) {
            case FightInterface::FIGHT:break;
            case FightInterface::ACT:
                if(currentFight->getEnemies().size() > 0) {
                    ug::FightActEnemySelectState::getInstance().loadFight(currentFight);
                    ug::UndertaleGame::getInstance()->getStateManager()->changeState(&ug::FightActEnemySelectState::getInstance());
                }
                break;
            case FightInterface::ITEM:break;
            case FightInterface::MERCY:break;
            case FightInterface::NONE:break;
        }
        interfaceControlsInstance->setZKeyPressed(false);
        ug::UndertaleGame::getInstance()->getAudioManager()->playSound("SELECT_SOUND");
    }

    if(interfaceControlsInstance->isLeftKeyPressed()) {
        if(interfaceInstance->getCurrentlySelectedButton() != ug::FightInterface::FIGHT) {
            interfaceInstance->setCurrentlySelectedButton((ug::FightInterface::CurrentSelectedButton)((int) interfaceInstance->getCurrentlySelectedButton() - 1));
            ug::UndertaleGame::getInstance()->getAudioManager()->playSound("MENU_MOVE_SOUND");
        }
        interfaceControlsInstance->setLeftKeyPressed(false);
    }

    if(interfaceControlsInstance->isRightKeyPressed()) {
        if(interfaceInstance->getCurrentlySelectedButton() != ug::FightInterface::MERCY) {
            interfaceInstance->setCurrentlySelectedButton((ug::FightInterface::CurrentSelectedButton)((int) interfaceInstance->getCurrentlySelectedButton() + 1));
            ug::UndertaleGame::getInstance()->getAudioManager()->playSound("MENU_MOVE_SOUND");
        }
        interfaceControlsInstance->setRightKeyPressed(false);
    }
}

void ug::FightActionSelectState::draw() {
    interfaceInstance->draw();

    switch (interfaceInstance->getCurrentlySelectedButton()) {
        case FightInterface::FIGHT:
            soulSprite.setXPosition(39);
            break;
        case FightInterface::ACT:
            soulSprite.setXPosition(195);
            break;
        case FightInterface::ITEM:
            soulSprite.setXPosition(353);
            break;
        case FightInterface::MERCY:
            soulSprite.setXPosition(508);
            break;
        case FightInterface::NONE:
            ug::Logger::instance().warning("FIGHT_ACTION_SELECT", "Currently selected button should not be set to NONE");
            break;
    }

    ug::UndertaleGame::getInstance()->getRenderer()->drawSprite(soulSprite);
}

void ug::FightActionSelectState::load() {
    interfaceInstance = &ug::FightInterface::getInstance();
    interfaceInstance->load();
    interfaceControlsInstance = &ug::FightInterfaceControls::getInstance();
}

ug::FightActionSelectState &ug::FightActionSelectState::getInstance() {
    return instance;
}

void ug::FightActionSelectState::loadFight(ug::Fight *fight) {
    ug::FightInterface::getInstance().setCurrentlySelectedButton(ug::FightInterface::FIGHT);
    currentFight = fight;
}

void ug::FightActionSelectState::loadFight(ug::Fight *fight, ug::FightInterface::CurrentSelectedButton currentlySelectedButton) {
    ug::FightInterface::getInstance().setCurrentlySelectedButton(currentlySelectedButton);
    currentFight = fight;
}
