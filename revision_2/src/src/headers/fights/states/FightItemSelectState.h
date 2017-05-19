#ifndef PROJECT_FIGHTITEMSELECTSTATE_H
#define PROJECT_FIGHTITEMSELECTSTATE_H

#include "../../core/State.h"
#include "../../render/Sprite.h"
#include "../FightInterfaceControls.h"
#include "../Fight.h"
#include "../../player/Player.h"

namespace ug {
    class FightItemSelectState : public State {
        static FightItemSelectState instance;
        FightInterfaceControls* interfaceControlsInstance;
        ug::Sprite soulSprite;

        int optionSelectedX = 0;
        int optionSelectedY = 0;

        Player* currentPlayer;
        Fight* currentFight;
    protected:
        void load() override;

    public:
        static FightItemSelectState& getInstance();

        void initialize() override;

        void handleEvent(sf::Event &event) override;

        void update() override;

        void draw() override;

        void loadFight(Fight* fight);
    };
}

#endif //PROJECT_FIGHTITEMSELECTSTATE_H
