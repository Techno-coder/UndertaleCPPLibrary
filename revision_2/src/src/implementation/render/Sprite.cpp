
#include "../../headers/render/Sprite.h"

const std::string &ug::Sprite::getTextureID() const {
    return textureID;
}

int ug::Sprite::getXPosition() const {
    return xPosition;
}

void ug::Sprite::setXPosition(int xPosition) {
    Sprite::xPosition = xPosition;
}

int ug::Sprite::getYPosition() const {
    return yPosition;
}

void ug::Sprite::setYPosition(int yPosition) {
    Sprite::yPosition = yPosition;
}

void ug::Sprite::setTextureID(const std::string &newTextureID) {
    textureID = newTextureID;
}

void ug::Sprite::setSize(int newWidth, int newHeight) {
    width = newWidth;
    height = newHeight;
}

int ug::Sprite::getWidth() const {
    return width;
}

int ug::Sprite::getHeight() const {
    return height;
}
