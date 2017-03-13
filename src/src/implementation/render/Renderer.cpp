
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "../../headers/render/Renderer.h"
#include "../../headers/core/UndertaleGame.h"

ug::Renderer::Renderer(sf::RenderWindow *const window) : window(window) {
    initializeModules();
}

void ug::Renderer::beforeFrame() {
    window->clear(sf::Color::Black);
}

void ug::Renderer::afterFrame() {
    window->display();
}

void ug::Renderer::handleEvent(sf::Event& event) {
    letterboxViewModule.handleEvent(event);
}

void ug::Renderer::initializeModules() {
    letterboxViewModule.initialize(window, 640, 480);
}

void ug::Renderer::drawSprite(const ug::Sprite& sprite) {
    sf::Sprite sfSprite;
    sfSprite.setTexture(ug::UndertaleGame::getInstance()->getResourceManager()->getTexture(sprite.getTextureID()));
    sfSprite.setPosition(sprite.getXPosition(), sprite.getYPosition());
    if(sprite.getWidth() != -1 && sprite.getHeight() != -1) {
        sfSprite.setScale(sfSprite.getLocalBounds().width / sprite.getWidth(), sfSprite.getLocalBounds().height / sprite.getHeight());
    }
    drawRawSprite(sfSprite);
}

void ug::Renderer::drawRawSprite(const sf::Drawable& sprite) {
    window->draw(sprite);
}
