#include "ActEnemySelectState.h"
#include "ActSelectState.h"

ug::ActEnemySelectState::ActEnemySelectState(const std::shared_ptr<ug::Encounter> &encounter) : EnemySelectState(
        encounter) {
    EncounterState::setActiveButton(ActiveButton::ACT);
}

void ug::ActEnemySelectState::goToNextState(std::vector<Enemy>::iterator selectedEnemy) {
    states->pushState(std::unique_ptr<ug::State>(new ug::ActSelectState(encounter, selectedEnemy)));
}

ug::ActEnemySelectState::~ActEnemySelectState() {}