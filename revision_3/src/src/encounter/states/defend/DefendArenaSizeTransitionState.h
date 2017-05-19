#ifndef PROJECT_DEFENDARENASIZETRANSITIONSTATE_H
#define PROJECT_DEFENDARENASIZETRANSITIONSTATE_H

#include "../EncounterState.h"

namespace ug {
    class DefendArenaSizeTransitionState : public EncounterState {
        sf::Vector2f desiredSize;

        float xChange;
        float yChange;

        bool compareFloats(float a, float b);
    protected:
        void onEnter() override;

        void onUpdate() override;
    public:
        DefendArenaSizeTransitionState(const std::shared_ptr<Encounter> &encounter, sf::Vector2f desiredSize);
        DefendArenaSizeTransitionState(const std::shared_ptr<Encounter> &encounter, sf::Vector2f startingSize,
                                       sf::Vector2f desiredSize);
    };
}

#endif //PROJECT_DEFENDARENASIZETRANSITIONSTATE_H
