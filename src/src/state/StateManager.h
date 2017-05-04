#ifndef PROJECT_STATEMANAGER_H
#define PROJECT_STATEMANAGER_H

#include <stack>
#include "State.h"


namespace ug {
    class State;

    class StateManager {
        std::stack<std::unique_ptr<State>> states;

        void startGameLoop();
    public:
        StateManager(std::unique_ptr<State> startingState);

        void pushState(std::unique_ptr<State> state);
        void popState();
        void changeState(std::unique_ptr<State> state);

        void handleEvent(sf::Event &event);
        void update();
        void draw(sf::RenderWindow &window);
    };
}

#endif //PROJECT_STATEMANAGER_H
