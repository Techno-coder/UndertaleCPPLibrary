#ifndef PROJECT_FIGHTACTIONSELECTSTATE_H
#define PROJECT_FIGHTACTIONSELECTSTATE_H

#include "../FightInterface.h"
#include "../FightInterfaceControls.h"
#include "../Fight.h"

namespace ug {
    class FightActionSelectState : public State {
        static FightActionSelectState instance;
        FightInterfaceControls* interfaceControlsInstance;
        FightInterface* interfaceInstance;

        ug::Sprite soulSprite;
        Fight* currentFight;
    protected:
        void load() override;
    public:
        void initialize() override;

        void handleEvent(sf::Event &event) override;

        void update() override;

        void draw() override;

        void loadFight(Fight* fight);
        void loadFight(Fight* fight, ug::FightInterface::CurrentSelectedButton currentlySelectedButton);

        static FightActionSelectState& getInstance();
    };
}


#endif //PROJECT_FIGHTACTIONSELECTSTATE_H
