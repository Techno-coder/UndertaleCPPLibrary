
#include "headers/StateManager.h"
#include "headers/states/IntroState.h"

void ug::StateManager::beginFight(ug::Fight fight) {

}

sf::View getLetterboxView(sf::View view, int windowWidth, int windowHeight) { //TODO

    // Compares the aspect ratio of the window to the aspect ratio of the view,
    // and sets the view's viewport accordingly in order to archieve a letterbox effect.
    // A new view (with a new viewport set) is returned.

    float windowRatio = windowWidth / (float) windowHeight;
    float viewRatio = view.getSize().x / (float) view.getSize().y;
    float sizeX = 1;
    float sizeY = 1;
    float posX = 0;
    float posY = 0;

    bool horizontalSpacing = true;
    if (windowRatio < viewRatio)
        horizontalSpacing = false;

    // If horizontalSpacing is true, the black bars will appear on the left and right side.
    // Otherwise, the black bars will appear on the top and bottom.

    if (horizontalSpacing) {
        sizeX = viewRatio / windowRatio;
        posX = (1 - sizeX) / 2.f;
    }

    else {
        sizeY = windowRatio / viewRatio;
        posY = (1 - sizeY) / 2.f;
    }

    view.setViewport( sf::FloatRect(posX, posY, sizeX, sizeY) );

    return view;
}

void ug::StateManager::startGame() { //TODO change later
    window.create(sf::VideoMode(800, 600), "Library Test TODO CHANGE");

    sf::View view; //TODO FIX UP LATER
    view.setSize( 800, 600 );
    view.setCenter( view.getSize().x / 2, view.getSize().y / 2 );
    window.setView(getLetterboxView(window.getView(), 640, 480));

    window.setFramerateLimit(60);
    states.push(new ug::IntroState());

    sf::Clock clock;
    sf::Time accumulator = sf::Time::Zero;
    sf::Time ups = sf::seconds(1.f / 60.f);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::Resized) { //TODO AND THIS FIX UP TOO
                view = getLetterboxView(view, event.size.width, event.size.height);
            } else {
                states.top()->handleEvent(event);

            }
        }

        while (accumulator > ups) {
            accumulator -= ups;
            states.top()->update();
        }

        window.clear(sf::Color::Black); //TODO REMOVE LATER
        window.setView(view);
        window.display();

        states.top()->draw();
        accumulator += clock.restart();
    }
}
