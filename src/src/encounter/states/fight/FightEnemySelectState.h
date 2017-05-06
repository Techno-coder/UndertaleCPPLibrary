#ifndef PROJECT_FIGHTENEMYSELECTSTATE_H
#define PROJECT_FIGHTENEMYSELECTSTATE_H

#include "../EnemySelectState.h"

namespace ug {
    class FightEnemySelectState : public EnemySelectState {
        std::vector<sf::RectangleShape> enemyHealthBars;

        void generateHealthBars();
    protected:
        void onEnter() override;

        void onDraw(sf::RenderWindow &window) override;

        void goToNextState(std::vector<Enemy>::iterator selectedEnemy) override;
    public:
        FightEnemySelectState(const std::shared_ptr<Encounter> &encounter);
        virtual ~FightEnemySelectState();
    };
}

#endif //PROJECT_FIGHTENEMYSELECTSTATE_H
