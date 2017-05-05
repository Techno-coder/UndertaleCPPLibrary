#include "ActEnemySelectState.h"

ug::ActEnemySelectState::ActEnemySelectState(const std::shared_ptr<ug::Encounter> &encounter) : EnemySelectState(
        encounter) {
    EncounterState::setActiveButton(ActiveButton::ACT);
}

void ug::ActEnemySelectState::goToNextState(std::vector<Enemy>::iterator selectedEnemy) {
    //TODO
}
