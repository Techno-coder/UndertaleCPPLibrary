#include "StateManager.h"

void ug::StateManager::pushState(std::unique_ptr<ug::State> state) {
    states.push(std::move(state));
    states.top()->enter(this);
}

void ug::StateManager::popState() {
    states.top()->onExit();
    states.pop();
}

void ug::StateManager::changeState(std::unique_ptr<ug::State> state) {
    popState();
    pushState(std::move(state));
}

void ug::StateManager::handleEvent(sf::Event &event) {
    states.top()->event(event);
}

void ug::StateManager::update() {
    states.top()->onUpdate();
}

void ug::StateManager::draw(sf::RenderWindow &window) {
    states.top()->onDraw(window);
}

ug::StateManager::StateManager(std::unique_ptr<ug::State> startingState) {
    pushState(std::move(startingState));
    startGameLoop();
}

sf::View getLetterboxView(sf::View view, int width, int height) {
    float windowRatio = width / (float) height;
    float viewRatio = view.getSize().x / view.getSize().y;
    float sizeX = 1;
    float sizeY = 1;
    float posX = 0;
    float posY = 0;

    bool horizontalSpacing = windowRatio >= viewRatio;
    if (horizontalSpacing) {
        sizeX = viewRatio / windowRatio;
        posX = (1 - sizeX) / 2.f;
    } else {
        sizeY = windowRatio / viewRatio;
        posY = (1 - sizeY) / 2.f;
    }

    view.setViewport(sf::FloatRect(posX, posY, sizeX, sizeY));
    return view;
}

void ug::StateManager::startGameLoop() {
    sf::RenderWindow window;
    window.create(sf::VideoMode(640, 480), "Undertale Game");
    window.setVerticalSyncEnabled(true);

    sf::View view;
    view.setSize(640, 480);
    view.setCenter(view.getSize().x / 2, view.getSize().y / 2);
    view = getLetterboxView(view, 640, 480);
    window.setView(view);

    sf::Clock clock;
    sf::Time accumulator = sf::Time::Zero;
    sf::Time ups = sf::seconds(1.f / 60.f);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                return;
            } else if (event.type == sf::Event::Resized) {
                view = getLetterboxView(view, event.size.width, event.size.height);
            }
            handleEvent(event);
        }
        while (accumulator > ups) {
            accumulator -= ups;
            update();
        }

        window.clear(sf::Color::Black);
        window.setView(view);
        draw(window);
        window.display();

        accumulator += clock.restart();
    }
}
