#ifndef PROJECT_DEFENDSTATE_H
#define PROJECT_DEFENDSTATE_H

#include "../EncounterState.h"

namespace ug {
    class DefendState : public EncounterState {
        std::vector<Projectile> currentProjectiles;

        bool alreadyEntered = false;
        void handleEvents();
        void collideableMoveSoul(float x, float y);
        void addProjectile(Projectile &projectile);
    protected:
        virtual void onEnter() override;
        virtual void onExit() override;

        virtual void onDraw(sf::RenderWindow &window) override;
        virtual void onUpdate() override;
    public:
        DefendState(const std::shared_ptr<Encounter> &encounter);
    };
}


#endif //PROJECT_DEFENDSTATE_H
