#ifndef PROJECT_CONTROLSMANAGER_H
#define PROJECT_CONTROLSMANAGER_H

#include <SFML/Window/Event.hpp>
#include <functional>
#include <map>

namespace ug {
    class Controls {
    public:
        void handleEvent(sf::Event &event);

        enum class Keys{UP, DOWN, LEFT, RIGHT, CONFIRM, CANCEL, INVALID};
        bool isKeyPressed(Keys key);
        void setOnKeyPressedListener(std::function<void(Keys key)> listener);
    private:
        std::map<Keys, bool> keysPressed;
        std::function<void(Keys key)> onKeyPressedListener;

        void setKeyPressed(Keys key, bool isPressed);
    };
}

#endif //PROJECT_CONTROLSMANAGER_H
