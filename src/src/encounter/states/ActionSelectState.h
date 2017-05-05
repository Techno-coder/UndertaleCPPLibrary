#ifndef PROJECT_ACTIONSELECTSTATE_H
#define PROJECT_ACTIONSELECTSTATE_H

#include "EncounterState.h"

namespace ug {
    class ActionSelectState : public EncounterState {
        int activeButton = 0;

        void onKeyPressed(Controls::Keys key);
        void updateActiveButton();
    public:
        ActionSelectState(const std::shared_ptr<Encounter> &encounter);

        void onEnter() override;

        void onDraw(sf::RenderWindow &window) override;
        void onUpdate() override;
    };
}

#endif //PROJECT_ACTIONSELECTSTATE_H
