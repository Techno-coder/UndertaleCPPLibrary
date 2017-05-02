#ifndef PROJECT_STATE_H
#define PROJECT_STATE_H

#include <SFML/Window/Event.hpp>

namespace ug {
    class State {
    public:
        virtual void init() = 0;
        virtual void finalize() = 0;

        virtual void pause() = 0;
        virtual void resume() = 0;

        virtual void handleEvent(sf::Event event) = 0;
        virtual void update() = 0;
        virtual void draw() = 0;
    };
}

#endif //PROJECT_STATE_H
