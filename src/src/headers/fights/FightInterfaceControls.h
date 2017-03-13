#ifndef PROJECT_FIGHTINTERFACECONTROLS_H
#define PROJECT_FIGHTINTERFACECONTROLS_H

#include <SFML/Window/Event.hpp>

namespace ug {

    /**
     * Class encapsulating the controls used in fights
     */
    class FightInterfaceControls {
        bool zKeyPressed = false;
        bool xKeyPressed = false;
        bool leftKeyPressed = false;
        bool rightKeyPressed = false;
        bool upKeyPressed = false;
        bool downKeyPressed = false;

        static FightInterfaceControls instance;
    public:
        void handleEvent(sf::Event& event);

        static FightInterfaceControls& getInstance();

        bool isZKeyPressed() const;

        void setZKeyPressed(bool zKeyPressed);

        bool isXKeyPressed() const;

        void setXKeyPressed(bool xKeyPressed);

        bool isLeftKeyPressed() const;

        void setLeftKeyPressed(bool leftKeyPressed);

        bool isRightKeyPressed() const;

        void setRightKeyPressed(bool rightKeyPressed);

        bool isUpKeyPressed() const;

        void setUpKeyPressed(bool upKeyPressed);

        bool isDownKeyPressed() const;

        void setDownKeyPressed(bool downKeyPressed);
    };
}

#endif //PROJECT_FIGHTINTERFACECONTROLS_H
