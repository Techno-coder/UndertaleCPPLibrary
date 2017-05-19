#ifndef PROJECT_FIGHTACTENEMYSELECTSTATE_H
#define PROJECT_FIGHTACTENEMYSELECTSTATE_H

#include "../../core/State.h"
#include "../FightInterfaceControls.h"
#include "../Fight.h"
#include "../../render/Sprite.h"

namespace ug {
    class FightActEnemySelectState : public State {
        static FightActEnemySelectState instance;
        FightInterfaceControls* interfaceControlsInstance;
        ug::Sprite soulSprite;

        int currentEnemySelected = 0;

        Fight* currentFight;
    protected:
        void load() override;
    public:
        static FightActEnemySelectState& getInstance();

        void initialize() override;

        void handleEvent(sf::Event &event) override;

        void update() override;

        void draw() override;

        void loadFight(Fight* fight);
        void loadFight(Fight* fight, int currentlySelected);

        int getCurrentEnemySelected() const;
    };
}

#endif //PROJECT_FIGHTACTENEMYSELECTSTATE_H
