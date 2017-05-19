#ifndef PROJECT_ENEMYSELECTSTATE_H
#define PROJECT_ENEMYSELECTSTATE_H

#include "EncounterState.h"

namespace ug {
    class EnemySelectState : public EncounterState {
        std::vector<sf::Text> generatedSprites;

        void generateSprites();
        void onKeyPressed(Controls::Keys key);
    protected:
        int selectedOption = 0;

        virtual void onEnter() override;

        virtual void onDraw(sf::RenderWindow &window) override;

        virtual void goToNextState(std::vector<Enemy>::iterator selectedEnemy) = 0;
    public:
        EnemySelectState(const std::shared_ptr<Encounter> &encounter);
        virtual ~EnemySelectState();
    };
}

#endif //PROJECT_ENEMYSELECTSTATE_H
