#include "ActionSelectState.h"
#include "item/ItemSelectState.h"
#include "fight/FightEnemySelectState.h"
#include "act/ActEnemySelectState.h"
#include "MercySelectState.h"

void ug::ActionSelectState::onDraw(sf::RenderWindow &window) {
    EncounterState::onDraw(window);
}

void ug::ActionSelectState::onUpdate() {}

ug::ActionSelectState::ActionSelectState(const std::shared_ptr<Encounter> &encounter) : EncounterState(encounter) {
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
                    states->pushState(std::unique_ptr<State>(new FightEnemySelectState(encounter)));
                    break;
                case 1:
                    states->pushState(std::unique_ptr<State>(new ActEnemySelectState(encounter)));
                    break;
                case 2:
                    states->pushState(std::unique_ptr<State>(new ItemSelectState(encounter)));
                    break;
                case 3:
                    states->pushState(std::unique_ptr<State>(new MercySelectState(encounter)));
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

ug::ActionSelectState::~ActionSelectState() {}
