#include "Controls.h"

void ug::Controls::setOnKeyPressedListener(std::function<void(ug::Controls::Keys key)> listener) {
    onKeyPressedListener = listener;
}

void ug::Controls::handleEvent(sf::Event &event) {
    switch (event.type) {
        case sf::Event::KeyPressed:
        case sf::Event::KeyReleased:
        {
            using sf::Keyboard;
            int keyCode = event.key.code;
            Keys theKey = Keys::INVALID;

            if(keyCode == Keyboard::Up) theKey = Keys::UP;
            if(keyCode == Keyboard::Down) theKey = Keys::DOWN;
            if(keyCode == Keyboard::Left) theKey = Keys::LEFT;
            if(keyCode == Keyboard::Right) theKey = Keys::RIGHT;
            if(keyCode == Keyboard::Z || event.key.shift) theKey = Keys::CONFIRM;
            if(keyCode == Keyboard::X || keyCode == Keyboard::Return) theKey = Keys::CANCEL;

            if(theKey != Keys::INVALID) {
                if(!isKeyPressed(theKey)) {
                    if(event.type == sf::Event::KeyPressed) onKeyPressedListener(theKey);
                }
                setKeyPressed(theKey, event.type == sf::Event::KeyPressed);
            }
            break;
        }
        default:
            break;
    }
}

bool ug::Controls::isKeyPressed(ug::Controls::Keys key) {
    return keysPressed[key];
}

void ug::Controls::setKeyPressed(ug::Controls::Keys key, bool isPressed) {
    keysPressed[key] = isPressed;
}
