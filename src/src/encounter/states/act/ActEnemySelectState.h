#ifndef PROJECT_ACTENEMYSELECTSTATE_H
#define PROJECT_ACTENEMYSELECTSTATE_H

#include "../EnemySelectState.h"

namespace ug {
    class ActEnemySelectState : public EnemySelectState {
    protected:
        void goToNextState(std::vector<Enemy>::iterator selectedEnemy) override;

    public:
        ActEnemySelectState(const std::shared_ptr<Encounter> &encounter);
    };
}

#endif //PROJECT_ACTENEMYSELECTSTATE_H
