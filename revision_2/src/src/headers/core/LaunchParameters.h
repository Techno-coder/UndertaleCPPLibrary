#ifndef PROJECT_LAUNCHPARAMETERS_H
#define PROJECT_LAUNCHPARAMETERS_H

#include <string>
#include "State.h"

namespace ug {
    class LaunchParameters {
        bool startFullscreen = false;
        unsigned int startWindowWidth = 640;
        unsigned int startWindowHeight = 480;
        std::string startWindowTitle = "DEFAULT WINDOW TITLE";
        ug::State* startingState; //TODO set a default state

    public:
        /**
         * Getter
         * @return Whether the game starts fullscreen
         */
        bool isStartFullscreen() const;

        /**
         * Set whether the game should start fullscreen
         * @param startFullscreen True if the game should start fullscreen
         */
        void setStartFullscreen(bool startFullscreen);

        /**
         * Getter
         * @return The initial width of the game
         */
        unsigned int getStartWindowWidth() const;

        /**
         * Set the initial window width of the game
         * @param startWindowWidth The initial window width
         */
        void setStartWindowWidth(unsigned int startWindowWidth);

        /**
         * Getter
         * @return The initial height of the game
         */
        unsigned int getStartWindowHeight() const;

        /**
         * Set the initial window height of the game
         * @param startWindowHeight The initial window height
         */
        void setStartWindowHeight(unsigned int startWindowHeight);

        /**
         * Getter
         * @return The initial window title of the game
         */
        const std::string &getStartWindowTitle() const;

        /**
         * Set the initial window title of the game
         * @param startWindowTitle The initial window title
         */
        void setStartWindowTitle(const std::string &startWindowTitle);

        /**
         * Getter
         * @return The starting state of the game
         */
        State *getStartingState() const;

        /**
         * Set the state that the game should load after starting
         * @param startingState The state to load after starting
         */
        void setStartingState(State *startingState);
    };
}

#endif //PROJECT_LAUNCHPARAMETERS_H
