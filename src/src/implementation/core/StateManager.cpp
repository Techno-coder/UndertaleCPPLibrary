
#include "../../headers/core/StateManager.h"

void ug::StateManager::changeState(ug::State *const newState) {
    states.top()->cleanup();
    states.pop();
    states.push(newState);
    states.top()->loadState();
    states.top()->initialize();
}

void ug::StateManager::pushState(ug::State *const state) {
    states.top()->pause();
    states.push(state);
    states.top()->loadState();
    states.top()->initialize();
}

void ug::StateManager::popState() {
    states.top()->cleanup();
    states.pop();
    states.top()->resume();
}

void ug::StateManager::handleEvent(sf::Event& event) {
    states.top()->handleEvent(event);
}

void ug::StateManager::update() {
    states.top()->update();
}

void ug::StateManager::draw() {
    states.top()->draw();
}

ug::StateManager::StateManager(ug::State *const startingState) {
    states.push(startingState);
    states.top()->loadState();
    states.top()->initialize();
}
