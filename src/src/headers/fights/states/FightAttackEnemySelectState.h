#ifndef PROJECT_FIGHTATTACKENEMYSELECTSTATE_H
#define PROJECT_FIGHTATTACKENEMYSELECTSTATE_H

#include "../../core/State.h"
#include "../FightInterfaceControls.h"
#include "../Fight.h"
#include "../../render/Sprite.h"

namespace ug {
    class FightAttackEnemySelectState : public State {
        static FightAttackEnemySelectState instance;
        FightInterfaceControls* interfaceControlsInstance;
        ug::Sprite soulSprite;

        int currentEnemySelected = 0;

        Fight* currentFight;
    protected:
        void load() override;
    public:
        static FightAttackEnemySelectState& getInstance();

        void initialize() override;

        void handleEvent(sf::Event &event) override;

        void update() override;

        void draw() override;

        void loadFight(Fight* fight);
        void loadFight(Fight* fight, int currentlySelected);

        int getCurrentEnemySelected() const;
    };
}


#endif //PROJECT_FIGHTATTACKENEMYSELECTSTATE_H
