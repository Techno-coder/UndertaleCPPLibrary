#ifndef PROJECT_STATE_H
#define PROJECT_STATE_H

#include <SFML/Window.hpp>

namespace ug {

    /**
     * States are recommended to be implemented as a singleton
     */
    class State {
    protected:
        bool loaded = false;

        /**
         * Called one time in the lifespan of the game to load resources
         */
        virtual void load() {};

        /**
         * Protected constructor to force singleton implementation
         */
        State() {};
    public:

        /**
         * Function encapsulating load
         * load() is called once in the lifespan of the game to load resources needed
         * Override load() to load resources required for this state
         */
        void loadState() {
            if(!loaded) {
                load();
                loaded = true;
            }
        }

        /**
         * Called when this state is added
         */
        virtual void initialize() {};

        /**
         * Called when this state is removed
         */
        virtual void cleanup() {};

        /**
         * Called when another state is added
         */
        virtual void pause() {};

        /**
         * Called when the state on top is removed
         */
        virtual void resume() {};

        /**
         * Called when a SFML event occurs
         */
        virtual void handleEvent(sf::Event& event) = 0;

        /**
         * Called each tick
         * @todo Tick speed to be decided
         */
        virtual void update() = 0;

        /**
         * Called each render tick
         * @todo Render tick speed to be decided
         */
        virtual void draw() = 0;
    };
}

#endif //PROJECT_STATE_H
