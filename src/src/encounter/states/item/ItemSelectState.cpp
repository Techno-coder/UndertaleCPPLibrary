#include "ItemSelectState.h"

void ug::ItemSelectState::onEnter() {
    itemCache = player.getInventory().getAllItems();
    if(itemCache.empty()) {
        states->popState();
        return;
    }

    controls.setOnKeyPressedListener(std::bind(&ItemSelectState::onKeyPressed, this, std::placeholders::_1));
    generateSprites();
    onKeyPressed(Controls::Keys::INVALID);
}

void ug::ItemSelectState::onDraw(sf::RenderWindow &window) {
    EncounterState::onDraw(window);
    for(auto text : generatedSprites) {
        window.draw(text);
    }
}

ug::ItemSelectState::ItemSelectState(std::shared_ptr<Encounter> encounter) : EncounterState(encounter) {
    EncounterState::setActiveButton(ActiveButton::ITEM);
}

void ug::ItemSelectState::onKeyPressed(ug::Controls::Keys key) {
    switch (key) {
        case Controls::Keys::UP:
            if(optionsY > 0) {
                --optionsY;
                audio.playSound(sounds.MENU_MOVE);
            }
            break;
        case Controls::Keys::DOWN:
            if(std::min(4, (int) itemCache.size()) - 2 > (optionsY * 2) + optionsX) {
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
            if(optionsX == 0 && (itemCache.size() - 1) > (optionsY * 2) + optionsX) {
                ++optionsX;
                audio.playSound(sounds.MENU_MOVE);
            }
            break;
        case Controls::Keys::CONFIRM:
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

void ug::ItemSelectState::generateSprites() {
    int currentX = 0;
    int currentY = 0;
    for(const auto &item : itemCache) {
        sf::Text asterix("*", State::fonts.MONO, 25);
        sf::Text option(item.getName(), State::fonts.MONO, 25);
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
