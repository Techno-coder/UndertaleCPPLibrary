#include "EncounterEventHandler.h"
#include "states/defend/DefendArenaSizeTransitionState.h"

void ug::EncounterEventHandler::exitDefendState(ug::EncounterState &encounterState) {
    encounterState.states->changeState(
            std::unique_ptr<ug::State>(
                    new ug::DefendArenaSizeTransitionState(
                            encounterState.encounter,
                            encounterState.dialogueBox.getSize(),
                            sf::Vector2f(570, 130))));
}

void ug::EncounterEventHandler::setArenaSize(float width, float height, ug::EncounterState &encounterState) {
    encounterState.encounter->temporaryState.customArenaSize = true;
    encounterState.states->pushState(std::unique_ptr<ug::State>(new DefendArenaSizeTransitionState(
            encounterState.encounter,
            sf::Vector2f(width, height)
    )));
}
