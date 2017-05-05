#ifndef PROJECT_ACTSELECTSTATE_H
#define PROJECT_ACTSELECTSTATE_H

#include "../EncounterState.h"

namespace ug {
    class ActSelectState : public EncounterState {
        std::vector<sf::Text> generatedSprites;
        std::vector<ug::Act>* actCache;

        int optionsX = 0;
        int optionsY = 0;

        void onKeyPressed(Controls::Keys key);
        void generateSprites();

        std::vector<Enemy>::iterator enemyIterator;
    protected:
        void onEnter() override;

        void onDraw(sf::RenderWindow &window) override;
    public:
        ActSelectState(const std::shared_ptr<Encounter> &encounter, std::vector<Enemy>::iterator enemyIterator);
    };
}

#endif //PROJECT_ACTSELECTSTATE_H
