#include "ActEnemySelectState.h"
#include "ActSelectState.h"

ug::ActEnemySelectState::ActEnemySelectState(const std::shared_ptr<ug::Encounter> &encounter) : EnemySelectState(
        encounter) {
    EncounterState::setActiveButton(ActiveButton::ACT);
}

void ug::ActEnemySelectState::goToNextState(std::vector<Enemy>::iterator selectedEnemy) {
    if(currentSelectedEnemy != encounter->temporaryState.lastEnemySelected) {
        encounter->temporaryState.lastActSelected = 0;
    }
    states->pushState(std::unique_ptr<ug::State>(new ug::ActSelectState(encounter, selectedEnemy)));
}

ug::ActEnemySelectState::~ActEnemySelectState() {}

void ug::ActEnemySelectState::onEnter() {
    EnemySelectState::onEnter();
    currentSelectedEnemy = encounter->temporaryState.lastEnemySelected;
}

void ug::ActEnemySelectState::onExit() {
    encounter->temporaryState.lastActSelected = 0;
}
