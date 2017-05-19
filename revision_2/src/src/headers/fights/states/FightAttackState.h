#ifndef PROJECT_FIGHTATTACKSTATE_H
#define PROJECT_FIGHTATTACKSTATE_H


#include "../../core/State.h"
#include "../Fight.h"

namespace ug {
    class FightAttackState : public State {
        static FightAttackState instance;
    public:
        static FightAttackState& getInstance();

        void handleEvent(sf::Event &event) override;

        void update() override;

        void draw() override;

        void loadFight(Fight* fight);
    };
}


#endif //PROJECT_FIGHTATTACKSTATE_H
