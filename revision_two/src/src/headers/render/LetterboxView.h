#ifndef PROJECT_LETTERBOXVIEW_H
#define PROJECT_LETTERBOXVIEW_H

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

namespace ug {
    class LetterboxView {
        sf::RenderWindow* window;
        bool enableLetterBox = false;
        int desiredWidth = 0;
        int desiredHeight = 0;
        sf::View view;
    public:
        /**
         * Function that should be called when there is a window event
         * @param event The event
         */
        void handleEvent(sf::Event& event);

        /**
         * Show black bars on the sides of the window to preserve aspect ratio when the window is resized
         * @note The width and height are only used to calculate the desired aspect ratio
         * @param width The desirable width of the window
         * @param height The desirable height of the window
         */
        void setLetterboxView(int width, int height);

        /**
         * Disables the letterbox view if it is enabled
         */
        void disableLetterboxView();

        /**
         * Function that should be called before other functions are used
         * @note The width and height are only used to calculate the desired aspect ratio
         * @param newWindow The window to be letter boxed
         * @param width The preferred width
         * @param height The preferred height
         */
        void initialize(sf::RenderWindow* newWindow, int width, int height);
    };
}

#endif //PROJECT_LETTERBOXVIEW_H
