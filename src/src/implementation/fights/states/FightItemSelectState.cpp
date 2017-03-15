
#include "../../../headers/fights/states/FightItemSelectState.h"
#include "../../../headers/fights/states/FightActionSelectState.h"

ug::FightItemSelectState ug::FightItemSelectState::instance;

ug::FightItemSelectState &ug::FightItemSelectState::getInstance() {
    return instance;
}

void ug::FightItemSelectState::loadFight(ug::Fight *fight) {
    currentFight = fight;
}

void ug::FightItemSelectState::handleEvent(sf::Event &event) {
    interfaceControlsInstance->handleEvent(event);
}

void ug::FightItemSelectState::update() {
    if(interfaceControlsInstance->isXKeyPressed()) {
        ug::FightActionSelectState::getInstance().loadFight(currentFight, ug::FightInterface::ITEM);
        ug::UndertaleGame::getInstance()->getStateManager()->changeState(&ug::FightActionSelectState::getInstance());
        ug::UndertaleGame::getInstance()->getAudioManager()->playSound("MENU_MOVE_SOUND");
        interfaceControlsInstance->setXKeyPressed(false);
    }

    if(interfaceControlsInstance->isZKeyPressed()) {
        currentPlayer->getInventory()[(optionSelectedY * 2) + optionSelectedX].handle();
        //TODO Change state to defending state
        ug::UndertaleGame::getInstance()->getAudioManager()->playSound("SELECT_SOUND");
        interfaceControlsInstance->setZKeyPressed(false);
    }

    if(interfaceControlsInstance->isLeftKeyPressed()) {
        if(optionSelectedX == 1) {
            --optionSelectedX;
            ug::UndertaleGame::getInstance()->getAudioManager()->playSound("MENU_MOVE_SOUND");
        }
        interfaceControlsInstance->setLeftKeyPressed(false);
    }

    if(interfaceControlsInstance->isRightKeyPressed()) {
        if(optionSelectedX == 0) {
            if((currentPlayer->getInventory().size() - 1) > (optionSelectedY * 2) + optionSelectedX) {
                ++optionSelectedX;
                ug::UndertaleGame::getInstance()->getAudioManager()->playSound("MENU_MOVE_SOUND");
            }
        }
        interfaceControlsInstance->setRightKeyPressed(false);
    }

    if(interfaceControlsInstance->isUpKeyPressed()) {
        if(optionSelectedY > 0) {
            --optionSelectedY;
            ug::UndertaleGame::getInstance()->getAudioManager()->playSound("MENU_MOVE_SOUND");
        }
        interfaceControlsInstance->setRightKeyPressed(false);
    }

    if(interfaceControlsInstance->isDownKeyPressed()) {
        int maxOptionsAmount = std::min(4, (int) currentPlayer->getInventory().size());
        if((maxOptionsAmount - 2) > (optionSelectedY * 2) + optionSelectedX) {
            ++optionSelectedY;
            ug::UndertaleGame::getInstance()->getAudioManager()->playSound("MENU_MOVE_SOUND");
        }
        interfaceControlsInstance->setRightKeyPressed(false);
    }
}

void ug::FightItemSelectState::draw() {
    ug::FightInterface::getInstance().draw();

    auto itemsIterator = currentPlayer->getInventory().begin();
    int currentX = 0;
    int currentY = 0;
    while (itemsIterator != currentPlayer->getInventory().end()) {
        sf::Text asterix("*", ug::UndertaleGame::getInstance()->getResourceManager()->getFont("DETERMINATION_MONO_FONT"), 25);
        sf::Text option((*itemsIterator).getItemName(),
                        ug::UndertaleGame::getInstance()->getResourceManager()->getFont("DETERMINATION_MONO_FONT"), 25);
        asterix.setPosition(100 + (currentX * 260), 270 + (currentY * 32));
        option.setPosition(130 + (currentX * 260), 270 + (currentY * 32));
        ug::UndertaleGame::getInstance()->getRenderer()->drawRawSprite(asterix);
        ug::UndertaleGame::getInstance()->getRenderer()->drawRawSprite(option);
        ++itemsIterator;

        if(currentY >= 1 && currentX >= 1) {
            break;
        }

        if(currentX == 0) {
            currentX = 1;
        } else if(currentX == 1) {
            currentX = 0;
            ++currentY;
        }
    }

    soulSprite.setXPosition(65 + (optionSelectedX) * 260);
    soulSprite.setYPosition(278 + (optionSelectedY * 32));
    ug::UndertaleGame::getInstance()->getRenderer()->drawSprite(soulSprite);
}

void ug::FightItemSelectState::initialize() {
    optionSelectedX = 0;
    optionSelectedY = 0;
    soulSprite.setTextureID("SOUL_SPRITE");
}

void ug::FightItemSelectState::load() {
    currentPlayer = ug::UndertaleGame::getInstance()->getPlayer();
    interfaceControlsInstance = &ug::FightInterfaceControls::getInstance();
}
