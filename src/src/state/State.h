#ifndef PROJECT_STATE_H
#define PROJECT_STATE_H

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "../core/AudioManager.h"
#include "../core/Controls.h"
#include "StateManager.h"
#include "../player/Player.h"
#include "../../external/resources/FontsResources.h"


namespace ug {
    class StateManager;

    class State {
        class GlobalFonts : FontsResources {
            const std::string PATH_PREFIX{"resources/default/all/"};
        public:
            FontsResourceItem MONO{PATH_PREFIX + "DTM-Mono.otf", this};
            FontsResourceItem SANS{PATH_PREFIX + "DTM-Sans.otf", this};
        };

        void event(sf::Event &event);
        void enter(StateManager* newStateManager);

        friend StateManager;
    protected:
        static AudioManager audio;
        static Controls controls;
        static Player player; //TODO Temporary until a player save system is devised

        static GlobalFonts fonts;

        /**
         * Set your listeners and handlers here
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
        virtual ~State();

        StateManager* states;
    };
}

#endif //PROJECT_STATE_H
