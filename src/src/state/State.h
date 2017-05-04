#ifndef PROJECT_STATE_H
#define PROJECT_STATE_H

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "../core/AudioManager.h"
#include "../core/Controls.h"
#include "StateManager.h"
#include "../Player/Player.h"


namespace ug {
    class StateManager;

    class State {
        void event(sf::Event &event);
        void enter(StateManager* newStateManager);

        friend StateManager;
    protected:
        static AudioManager audio;
        static Controls controls;
        static Player player; //TODO Temporary until a player save system is devised

        StateManager* states;

        /**
         * Set the listeners and handlers here
         */
        virtual void onEnter() {};

        /**
         * Unregister your listeners and handlers here
         */
        virtual void onExit() {};

        virtual void onUpdate() {};
        virtual void onDraw(sf::RenderWindow &window) {};
    public:
        State();
    };
}

#endif //PROJECT_STATE_H
