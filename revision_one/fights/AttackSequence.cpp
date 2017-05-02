
#include <memory>
#include "../headers/fights/AttackSequence.h"

void ug::EntityBoard::addEnemyEntity(const std::unique_ptr <ug::FightEntity> &entity) {
    entities.push_back(entity);
}
