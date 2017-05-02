#ifndef PROJECT_INTROSTATE_H
#define PROJECT_INTROSTATE_H

#include "State.h"

namespace ug {
    class IntroState : public State {
        void init() override;

        void finalize() override;

        void handleEvent(sf::Event event) override;

        void update() override;

        void draw() override;

        void pause() override;

        void resume() override;

    };
}

#endif //PROJECT_INTROSTATE_H
