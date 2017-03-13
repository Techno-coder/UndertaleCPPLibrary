
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
        ug::UndertaleGame::getInstance()->getAudioManager()->playSound("MENU_MOVE_SOUND");
        interfaceControlsInstance->setXKeyPressed(false);
    }

    if(interfaceControlsInstance->isZKeyPressed()) {
        currentFight->getEnemies()[lastEnemySelected].getActCommands()[(optionSelectedY * 2) + optionSelectedX]->handle();
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
            if((currentFight->getEnemies()[lastEnemySelected].getActCommands().size() - 1) > (optionSelectedY * 2) + optionSelectedX) {
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
        if((currentFight->getEnemies()[lastEnemySelected].getActCommands().size() - 2) > (optionSelectedY * 2) + optionSelectedX) {
            ++optionSelectedY;
            ug::UndertaleGame::getInstance()->getAudioManager()->playSound("MENU_MOVE_SOUND");
        }
        interfaceControlsInstance->setRightKeyPressed(false);
    }
}

void ug::FightActState::draw() {
    ug::FightInterface::getInstance().draw();

    auto actsIterator = currentFight->getEnemies()[lastEnemySelected].getActCommands().begin();
    int currentX = 0;
    int currentY = 0;
    while (actsIterator != currentFight->getEnemies()[lastEnemySelected].getActCommands().end()) {
        sf::Text asterix("*", ug::UndertaleGame::getInstance()->getResourceManager()->getFont("DETERMINATION_MONO_FONT"), 25);
        sf::Text option((*actsIterator)->getActName(),
                        ug::UndertaleGame::getInstance()->getResourceManager()->getFont("DETERMINATION_MONO_FONT"), 25);
        asterix.setPosition(100 + (currentX * 260), 270 + (currentY * 32));
        option.setPosition(130 + (currentX * 260), 270 + (currentY * 32));
        ug::UndertaleGame::getInstance()->getRenderer()->drawRawSprite(asterix);
        ug::UndertaleGame::getInstance()->getRenderer()->drawRawSprite(option);
        ++actsIterator;

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

void ug::FightActState::load() {
    ug::FightInterface::getInstance().load();
    interfaceControlsInstance = &FightInterfaceControls::getInstance();
}

void ug::FightActState::initialize() {
    lastEnemySelected = ug::FightActEnemySelectState::getInstance().getCurrentEnemySelected();
    optionSelectedX = 0;
    optionSelectedY = 0;
    soulSprite.setTextureID("SOUL_SPRITE");
}

ug::FightActState &ug::FightActState::getInstance() {
    return instance;
}

void ug::FightActState::loadFight(Fight *fight){
    currentFight = fight;
}
