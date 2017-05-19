#include "DefendArenaSizeTransitionState.h"

ug::DefendArenaSizeTransitionState::DefendArenaSizeTransitionState(const std::shared_ptr<ug::Encounter> &encounter,
                                                                   sf::Vector2f desiredSize) :
        EncounterState(encounter), desiredSize(desiredSize) {
    EncounterState::setActiveButton(ActiveButton::NONE);
    encounter->temporaryState.desiredDefendArenaSize = desiredSize;
}

void ug::DefendArenaSizeTransitionState::onUpdate() {
    sf::Vector2f encounterSize = dialogueBox.getSize();
    if(compareFloats(encounterSize.x, desiredSize.x) && compareFloats(encounterSize.y, desiredSize.y)) {
        encounter->temporaryState.endTransitionArenaPosition = dialogueBox.getPosition();
        states->popState();
        return;
    }

    encounterSize.x += xChange;
    encounterSize.y += yChange;
    dialogueBox.setSize(encounterSize);
    dialogueBox.setOrigin(dialogueBox.getSize().x / 2, dialogueBox.getSize().y);
}

void ug::DefendArenaSizeTransitionState::onEnter() {
    EncounterState::soul.setPosition(-100, -100);

    sf::Vector2f encounterSize = dialogueBox.getSize();
    float xDiff = desiredSize.x - encounterSize.x;
    xChange = xDiff / 30.0f;

    float yDiff = desiredSize.y - encounterSize.y;
    yChange = yDiff / 30.0f;

    onUpdate();
}

bool ug::DefendArenaSizeTransitionState::compareFloats(float a, float b) {
    constexpr float EPSILON = 1.0f;
    float diff = a - b;
    return (diff < EPSILON) && (-diff < EPSILON);
}

ug::DefendArenaSizeTransitionState::DefendArenaSizeTransitionState(const std::shared_ptr<ug::Encounter> &encounter,
                                                                   sf::Vector2f startingSize,
                                                                   sf::Vector2f desiredSize) :
        DefendArenaSizeTransitionState(encounter, desiredSize) {
    dialogueBox.setSize(startingSize);
}
