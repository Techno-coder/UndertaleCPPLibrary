
#include <SFML/Graphics/View.hpp>
#include "../../headers/render/LetterboxView.h"

void ug::LetterboxView::handleEvent(sf::Event &event) {
    if (event.type == sf::Event::Resized && enableLetterBox) {
        setLetterboxView(event.size.width, event.size.height);
    }
}

void ug::LetterboxView::initialize(sf::RenderWindow *newWindow, int width, int height) {
    window = newWindow;
    view.setSize(width, height);
    view.setCenter(view.getSize().x / 2, view.getSize().y / 2);
    setLetterboxView(window->getSize().x, window->getSize().y);
}

void ug::LetterboxView::setLetterboxView(int width, int height) {
    enableLetterBox = true;
    desiredWidth = width;
    desiredHeight = height;

    float windowRatio = desiredWidth / (float) desiredHeight;
    float viewRatio = view.getSize().x / view.getSize().y;
    float sizeX = 1;
    float sizeY = 1;
    float posX = 0;
    float posY = 0;

    bool horizontalSpacing = windowRatio > viewRatio;
    if (horizontalSpacing) {
        sizeX = viewRatio / windowRatio;
        posX = (1 - sizeX) / 2.f;
    } else {
        sizeY = windowRatio / viewRatio;
        posY = (1 - sizeY) / 2.f;
    }

    view.setViewport(sf::FloatRect(posX, posY, sizeX, sizeY));
    window->setView(view);
}

void ug::LetterboxView::disableLetterboxView() {
    view.setViewport(sf::FloatRect(0, 0, 1, 1));
    window->setView(view);
}
