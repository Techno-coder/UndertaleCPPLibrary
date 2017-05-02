#ifndef PROJECT_STATEMANAGER_H
#define PROJECT_STATEMANAGER_H

#include <stack>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "State.h"

namespace ug {
    class StateManager {
        std::stack<State*> states;
    public:
        StateManager(State* const startingState);

        /**
         * Pause the current state and initialize the new state
         * @param state The state to be initialized
         */
        void pushState(State* const state);

        /**
         * Remove the current state
         * @todo Something should happen when there are no more states
         */
        void popState();

        /**
         * Remove the current state and add a new one
         * @param newState The state to be initialized
         */
        void changeState(State* const newState);

        /**
         * Call the current states event handler
         * @param event The event to be handled
         */
        void handleEvent(sf::Event& event);

        /**
         * Call the current states update function
         */
        void update();

        /**
         * Call the current states draw function
         */
        void draw();
    };
}

#endif //PROJECT_STATEMANAGER_H
