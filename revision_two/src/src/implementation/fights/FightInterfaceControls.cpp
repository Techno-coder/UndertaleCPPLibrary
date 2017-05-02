
#include "../../headers/fights/FightInterfaceControls.h"

ug::FightInterfaceControls ug::FightInterfaceControls::instance;

void ug::FightInterfaceControls::handleEvent(sf::Event &event) {
    switch (event.type) {
        case sf::Event::KeyPressed:
            switch (event.key.code) {
                case sf::Keyboard::Z:
                    zKeyPressed = true;
                    break;
                case sf::Keyboard::X:
                    xKeyPressed = true;
                    break;
                case sf::Keyboard::Left:
                    leftKeyPressed = true;
                    break;
                case sf::Keyboard::Right:
                    rightKeyPressed = true;
                    break;
                case sf::Keyboard::Up:
                    upKeyPressed = true;
                    break;
                case sf::Keyboard::Down:
                    downKeyPressed = true;
                    break;
                default:
                    break;
            }
            break;
        case sf::Event::KeyReleased:
            switch (event.key.code) {
                case sf::Keyboard::Z:
                    zKeyPressed = false;
                    break;
                case sf::Keyboard::X:
                    xKeyPressed = false;
                    break;
                case sf::Keyboard::Left:
                    leftKeyPressed = false;
                    break;
                case sf::Keyboard::Right:
                    rightKeyPressed = false;
                    break;
                case sf::Keyboard::Up:
                    upKeyPressed = false;
                    break;
                case sf::Keyboard::Down:
                    downKeyPressed = false;
                    break;
                default:
                    break;
            }
            break;

        default:
            break;
    }
}

ug::FightInterfaceControls &ug::FightInterfaceControls::getInstance() {
    return instance;
}

bool ug::FightInterfaceControls::isZKeyPressed() const {
    return zKeyPressed;
}

void ug::FightInterfaceControls::setZKeyPressed(bool zKeyPressed) {
    FightInterfaceControls::zKeyPressed = zKeyPressed;
}

bool ug::FightInterfaceControls::isXKeyPressed() const {
    return xKeyPressed;
}

void ug::FightInterfaceControls::setXKeyPressed(bool xKeyPressed) {
    FightInterfaceControls::xKeyPressed = xKeyPressed;
}

bool ug::FightInterfaceControls::isLeftKeyPressed() const {
    return leftKeyPressed;
}

void ug::FightInterfaceControls::setLeftKeyPressed(bool leftKeyPressed) {
    FightInterfaceControls::leftKeyPressed = leftKeyPressed;
}

bool ug::FightInterfaceControls::isRightKeyPressed() const {
    return rightKeyPressed;
}

void ug::FightInterfaceControls::setRightKeyPressed(bool rightKeyPressed) {
    FightInterfaceControls::rightKeyPressed = rightKeyPressed;
}

bool ug::FightInterfaceControls::isUpKeyPressed() const {
    return upKeyPressed;
}

void ug::FightInterfaceControls::setUpKeyPressed(bool upKeyPressed) {
    FightInterfaceControls::upKeyPressed = upKeyPressed;
}

bool ug::FightInterfaceControls::isDownKeyPressed() const {
    return downKeyPressed;
}

void ug::FightInterfaceControls::setDownKeyPressed(bool downKeyPressed) {
    FightInterfaceControls::downKeyPressed = downKeyPressed;
}
