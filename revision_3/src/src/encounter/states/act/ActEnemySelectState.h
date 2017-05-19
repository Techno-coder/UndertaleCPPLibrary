#ifndef PROJECT_ACTENEMYSELECTSTATE_H
#define PROJECT_ACTENEMYSELECTSTATE_H

#include <ostream>
#include "../EnemySelectState.h"

namespace ug {
    class ActEnemySelectState : public EnemySelectState {
        int currentSelectedEnemy = 0;
    protected:
        void goToNextState(std::vector<Enemy>::iterator selectedEnemy) override;

        void onEnter() override;
        void onExit() override;
    public:
        ActEnemySelectState(const std::shared_ptr<Encounter> &encounter);
        virtual ~ActEnemySelectState();
    };
}

#endif //PROJECT_ACTENEMYSELECTSTATE_H
