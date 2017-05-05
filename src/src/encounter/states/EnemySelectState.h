#ifndef PROJECT_ENEMYSELECTSTATE_H
#define PROJECT_ENEMYSELECTSTATE_H

#include "EncounterState.h"

namespace ug {
    class EnemySelectState : public EncounterState {
        std::vector<sf::Text> generatedSprites;

        int selectedOption = 0;

        void onKeyPressed(Controls::Keys key);
        void generateSprites();
    protected:
        std::vector<Enemy>* enemyCache;

        virtual void onEnter() override;

        virtual void onDraw(sf::RenderWindow &window) override;

        virtual void goToNextState(std::vector<Enemy>::iterator selectedEnemy) = 0;
    public:
        EnemySelectState(const std::shared_ptr<Encounter> &encounter);
    };
}

#endif //PROJECT_ENEMYSELECTSTATE_H
