#ifndef PROJECT_MERCYSELECTSTATE_H
#define PROJECT_MERCYSELECTSTATE_H

#include "EncounterState.h"

namespace ug {
    class MercySelectState : public EncounterState {
        int selectedOption = 0;
        std::vector<sf::Text> generatedSprites;

        void onKeyPress(Controls::Keys key);
        void generateSprites();
    protected:
        void onEnter() override;

        void onDraw(sf::RenderWindow &window) override;
    public:
        MercySelectState(const std::shared_ptr<Encounter> &encounter);
    };
}


#endif //PROJECT_MERCYSELECTSTATE_H
