#include "ActionSelectState.h"
#include "ItemSelectState.h"

void ug::ActionSelectState::onDraw(sf::RenderWindow &window) {
    EncounterState::onDraw(window);
}

void ug::ActionSelectState::onUpdate() {}

ug::ActionSelectState::ActionSelectState() {
    EncounterState::setActiveButton(ActiveButton::FIGHT);
    EncounterState::soul.setPosition(47, 452);
}

void ug::ActionSelectState::onKeyPressed(ug::Controls::Keys key) {
    switch (key) {
        case Controls::Keys::LEFT:
            --activeButton;
            updateActiveButton();
            break;
        case Controls::Keys::RIGHT:
            ++activeButton;
            updateActiveButton();
            break;
        case Controls::Keys::CONFIRM:
            switch (activeButton) {
                case 0:
                    break;
                case 1:
                    break;
                case 2:
                    states->pushState(std::unique_ptr<ug::State>(new ug::ItemSelectState));
                    break;
                case 3:
                    break;
                default:
                    break;
            }
            audio.playSound(sounds.MENU_CONFIRM);
            break;
        default:
            break;
    }
}

void ug::ActionSelectState::onEnter() {
    State::controls.setOnKeyPressedListener(std::bind(&ActionSelectState::onKeyPressed, this, std::placeholders::_1));
}

void ug::ActionSelectState::updateActiveButton() {
    activeButton = (activeButton + 4) % 4;
    State::audio.playSound(EncounterState::sounds.MENU_MOVE);
    switch (activeButton) {
        case 0:
            EncounterState::setActiveButton(ActiveButton::FIGHT);
            EncounterState::soul.setPosition(47, 452);
            break;
        case 1:
            EncounterState::setActiveButton(ActiveButton::ACT);
            EncounterState::soul.setPosition(203, 452);
            break;
        case 2:
            EncounterState::setActiveButton(ActiveButton::ITEM);
            EncounterState::soul.setPosition(361, 452);
            break;
        case 3:
            EncounterState::setActiveButton(ActiveButton::MERCY);
            EncounterState::soul.setPosition(516, 452);
            break;
        default: break;
    }
}
