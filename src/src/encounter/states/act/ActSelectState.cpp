#include "ActSelectState.h"

ug::ActSelectState::ActSelectState(const std::shared_ptr<ug::Encounter> &encounter,
                                   std::vector<ug::Enemy>::iterator enemyIterator) :
        EncounterState(encounter), enemyIterator(enemyIterator) {
    EncounterState::setActiveButton(ActiveButton::ACT);
}

void ug::ActSelectState::onKeyPressed(ug::Controls::Keys key) {
    switch (key) {
        case Controls::Keys::UP:
            if(optionsY > 0) {
                --optionsY;
                audio.playSound(sounds.MENU_MOVE);
            }
            break;
        case Controls::Keys::DOWN:
            if(std::min(4, (int) actCache->size()) - 2 > (optionsY * 2) + optionsX) {
                ++optionsY;
                audio.playSound(sounds.MENU_MOVE);
            }
            break;
        case Controls::Keys::LEFT:
            if(optionsX == 1) {
                --optionsX;
                audio.playSound(sounds.MENU_MOVE);
            }
            break;
        case Controls::Keys::RIGHT:
            if(optionsX == 0 && (actCache->size() - 1) > (optionsY * 2) + optionsX) {
                ++optionsX;
                audio.playSound(sounds.MENU_MOVE);
            }
            break;
        case Controls::Keys::CONFIRM:
            audio.playSound(sounds.MENU_CONFIRM);
            //TODO
            break;
        case Controls::Keys::CANCEL:
            states->popState();
            break;
        default:
            break;
    }
    soul.setPosition(73 + (optionsX * 260), 286 + (optionsY * 32));
}

void ug::ActSelectState::generateSprites() {
    int currentX = 0;
    int currentY = 0;
    for(const auto &act : *actCache) {
        sf::Text asterix("*", State::fonts.MONO, 25);
        sf::Text option(act.getName(), State::fonts.MONO, 25);
        asterix.setPosition(100 + (currentX * 260), 270 + (currentY * 32));
        option.setPosition(130 + (currentX * 260), 270 + (currentY * 32));
        generatedSprites.push_back(asterix);
        generatedSprites.push_back(option);

        if(currentY >= 1 && currentX >= 1) break;

        if(currentX == 0) currentX = 1;
        else if(currentX == 1) {
            currentX = 0;
            ++currentY;
        }
    }
}

void ug::ActSelectState::onDraw(sf::RenderWindow &window) {
    EncounterState::onDraw(window);
    for(auto &text : generatedSprites) {
        window.draw(text);
    }
}

void ug::ActSelectState::onEnter() {
    actCache = &enemyIterator->getActs();
    if(actCache->empty()) {
        states->popState();
        return;
    }

    State::controls.setOnKeyPressedListener(std::bind(&ActSelectState::onKeyPressed, this, std::placeholders::_1));
    generateSprites();
    onKeyPressed(Controls::Keys::INVALID);
}

ug::ActSelectState::~ActSelectState() {}
