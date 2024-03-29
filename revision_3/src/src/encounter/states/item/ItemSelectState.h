#ifndef PROJECT_ITEMSELECTSTATE_H
#define PROJECT_ITEMSELECTSTATE_H

#include "../EncounterState.h"

namespace ug {
    class ItemSelectState : public EncounterState {
        int optionsX = 0;
        int optionsY = 0;

        std::vector<ug::Item> itemCache;
        std::vector<sf::Text> generatedSprites;

        void onKeyPressed(Controls::Keys key);
        void generateSprites();
    protected:
        void onEnter() override;

        void onDraw(sf::RenderWindow &window) override;

    public:
        ItemSelectState(std::shared_ptr<Encounter> encounter);
    };
}

#endif //PROJECT_ITEMSELECTSTATE_H
