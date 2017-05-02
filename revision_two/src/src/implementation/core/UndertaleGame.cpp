
#include "../../headers/core/UndertaleGame.h"
#include "../../headers/resource/ResourceManager.h"
#include "../../headers/audio/AudioManager.h"
#include "../../headers/core/CoreResources.h"

ug::UndertaleGame* ug::UndertaleGame::instance = new ug::UndertaleGame();

ug::StateManager* const ug::UndertaleGame::getStateManager() {
    return stateManager;
}

ug::Player* const ug::UndertaleGame::getPlayer() {
    return player;
}

void ug::UndertaleGame::initializeModules(const ug::LaunchParameters& parameters) {
    renderer = new Renderer(window);
    resourceManager = new ResourceManager();
    audioManager = new AudioManager(resourceManager);
    player = new Player();
    ug::CoreResources::load();
    stateManager = new StateManager(parameters.getStartingState());
}

ug::Renderer *const ug::UndertaleGame::getRenderer() {
    return renderer;
}

void ug::UndertaleGame::startGameLoop() {
    sf::Clock clock;
    sf::Time accumulator = sf::Time::Zero;
    sf::Time ups = sf::seconds(1.f / 60.f);
    while (window->isOpen()) {
        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window->close();
                return;
            }
            getRenderer()->handleEvent(event);
            getStateManager()->handleEvent(event);
        }

        while (accumulator > ups) {
            accumulator -= ups;
            getStateManager()->update();
        }

        getRenderer()->beforeFrame();
        getStateManager()->draw();
        getRenderer()->afterFrame();

        accumulator += clock.restart();
    }
}

void ug::UndertaleGame::startGame() {
    startGameLoop();
}

ug::ResourceManager *const ug::UndertaleGame::getResourceManager() {
    return resourceManager;
}

ug::UndertaleGame::~UndertaleGame() {
    delete window;
    delete renderer;
    delete resourceManager;
    delete stateManager;
    delete audioManager;
    delete player;
}

ug::AudioManager *const ug::UndertaleGame::getAudioManager() {
    return audioManager;
}

ug::UndertaleGame::UndertaleGame() {

}

ug::UndertaleGame *const ug::UndertaleGame::getInstance() {
    return instance;
}

void ug::UndertaleGame::cleanupGame() {
    delete instance;
}

void ug::UndertaleGame::initializeGame(const LaunchParameters& parameters) {
    launchParameters = parameters;
    window = new sf::RenderWindow;
    window->create(launchParameters.isStartFullscreen() ? sf::VideoMode::getFullscreenModes()[0] :
                   sf::VideoMode(launchParameters.getStartWindowWidth(), launchParameters.getStartWindowHeight()),
                   launchParameters.getStartWindowTitle(),
                   launchParameters.isStartFullscreen() ? sf::Style::Fullscreen : sf::Style::Default);
    window->setFramerateLimit(120);
    initializeModules(launchParameters);
}
