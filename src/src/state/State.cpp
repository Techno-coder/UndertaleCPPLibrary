#include "State.h"

ug::AudioManager ug::State::audio;
ug::Controls ug::State::controls;

ug::State::State() {
    controls.setOnKeyPressedListener([](Controls::Keys key){});
}

void ug::State::event(sf::Event &event) {
    controls.handleEvent(event);
}

void ug::State::enter(StateManager* newStateManager) {
    states = newStateManager;
    onEnter();
}
