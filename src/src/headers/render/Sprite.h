#ifndef PROJECT_SPRITE_H
#define PROJECT_SPRITE_H

#include <string>

namespace ug {

    /**
     * @todo documentation
     */
    class Sprite {
        std::string textureID;
        int xPosition = 0;
        int yPosition = 0;

        int width = -1;
        int height = -1;
    public:
        void setTextureID(const std::string& newTextureID);

        const std::string &getTextureID() const;

        int getXPosition() const;

        void setXPosition(int xPosition);

        int getYPosition() const;

        void setYPosition(int yPosition);

        /**
         * Set the size in pixels of the sprite in respect to a 640x480 resolution
         * @param newWidth The width it should be on a 640x480 resolution
         * @param newHeight The height it should be on a 640x480 resolution
         */
        void setSize(int newWidth, int newHeight);

        int getWidth() const;

        int getHeight() const;
    };
}

#endif //PROJECT_SPRITE_H
