#ifndef PROJECT_FIGHTACTSTATE_H
#define PROJECT_FIGHTACTSTATE_H

#include <SFML/Graphics/RectangleShape.hpp>
#include "../../core/State.h"
#include "../FightInterface.h"
#include "../Fight.h"
#include "../FightInterfaceControls.h"

namespace ug {

    /**
     * @todo Add act stuff
     */
    class FightActState : public State {
        static FightActState instance;

        FightInterfaceControls* interfaceControlsInstance;
        ug::Sprite soulSprite;

        int optionSelectedX = 0;
        int optionSelectedY = 0;

        Fight* currentFight;
        int lastEnemySelected = 0;
    protected:
        void load() override;
    public:
        void initialize() override;

        void handleEvent(sf::Event &event) override;

        void update() override;

        void draw() override;

        void loadFight(Fight* fight);

        static FightActState& getInstance();
    };
}

#endif //PROJECT_FIGHTACTSTATE_H
