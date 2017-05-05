#include "MercySelectState.h"

ug::MercySelectState::MercySelectState(const std::shared_ptr<ug::Encounter> &encounter) : EncounterState(encounter) {
    EncounterState::setActiveButton(ActiveButton::MERCY);
}

void ug::MercySelectState::onDraw(sf::RenderWindow &window) {
    EncounterState::onDraw(window);
    for(auto text : generatedSprites) {
        window.draw(text);
    }
}

void ug::MercySelectState::onEnter() {
    State::controls.setOnKeyPressedListener(std::bind(&MercySelectState::onKeyPress, this, std::placeholders::_1));
    generateSprites();
    onKeyPress(Controls::Keys::INVALID);
}

void ug::MercySelectState::onKeyPress(ug::Controls::Keys key) {
    switch (key) {
        case Controls::Keys::UP:
            if(selectedOption > 0) {
                --selectedOption;
                audio.playSound(sounds.MENU_MOVE);
            }
            break;
        case Controls::Keys::DOWN:
            if(selectedOption < 1) {
                ++selectedOption;
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
    soul.setPosition(73, (286 + (selectedOption * 32)));
}

void ug::MercySelectState::generateSprites() {
    sf::Text asterix("*", State::fonts.MONO, 25);
    sf::Text option("Spare", State::fonts.MONO, 25);
    for(auto &enemy : encounter->getAllEnemies()) {
        if(enemy.getAttributes().spareable) {
            option.setFillColor(sf::Color::Yellow);
            break;
        }
    }
    asterix.setPosition(100, 270);
    option.setPosition(130, 270);
    generatedSprites.push_back(asterix);
    generatedSprites.push_back(option);

    option.setFillColor(sf::Color::White);
    option.setString("Flee");
    asterix.setPosition(100, 270 + 32);
    option.setPosition(130, 270 + 32);

    generatedSprites.push_back(asterix);
    generatedSprites.push_back(option);
}
