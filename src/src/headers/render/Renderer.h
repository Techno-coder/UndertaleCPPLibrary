#ifndef PROJECT_RENDERER_H
#define PROJECT_RENDERER_H

#include <SFML/Graphics/RenderWindow.hpp>
#include "LetterboxView.h"
#include "Sprite.h"

namespace ug {

    /**
     * Responsible for drawing to the screen
     * @todo Add draw function as other functions go to this class for drawing sprites
     * @todo Consider adding the resource manager into the destructor
     */
    class Renderer {
        sf::RenderWindow* const window;

        LetterboxView letterboxViewModule;

        /**
         * @todo Consider having each module implement a renderModule class for easy event handling and polymorphic storage
         */
        void initializeModules();
    public:
        Renderer(sf::RenderWindow* const window);

        /**
         * Function that should be called before sprites are drawn each frame
         */
        void beforeFrame();

        /**
         * Function that should be called after sprites are drawn each frame
         */
        void afterFrame();

        /**
         * Draw a sprite onto the screen
         * @param sprite The sprite to draw
         */
        void drawSprite(const Sprite& sprite);

        /**
         * Draw a SFML sprite
         * @param sprite The SFML sprite to draw
         */
        void drawRawSprite(const sf::Drawable& sprite);

        /**
         * Function that should be called each time there is a window event
         * @param event The event
         */
        void handleEvent(sf::Event& event);

    };
}

#endif //PROJECT_RENDERER_H
