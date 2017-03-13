#ifndef PROJECT_FIGHTINTERFACESPRITES_H
#define PROJECT_FIGHTINTERFACESPRITES_H

#include <SFML/Graphics/RectangleShape.hpp>
#include "../render/Sprite.h"
#include "../core/UndertaleGame.h"

namespace ug {

    /**
     * Class encapsulating common Fight state sprites
     */
    class FightInterface {
        ug::Sprite fightButton;
        ug::Sprite actButton;
        ug::Sprite itemButton;
        ug::Sprite mercyButton;
        sf::RectangleShape dialogueBox;
        sf::Text playerName;
        sf::Text playerLevel;
        sf::Text playerHealthLabel;
        sf::Text playerHealthFraction;
        sf::RectangleShape currentHealthBar;
        sf::RectangleShape maxHealthBar;

        UndertaleGame* gameInstance;
        bool loaded = false;
        static FightInterface instance;

        void initializeSprites();
        void updatePlayerVariables();

    public:
        static FightInterface &getInstance();

        enum CurrentSelectedButton {
            FIGHT = 0,
            ACT = 1,
            ITEM = 2,
            MERCY = 3,
            NONE = 4
        };

        void setCurrentlySelectedButton(CurrentSelectedButton newCurrent);
        const CurrentSelectedButton& getCurrentlySelectedButton();

        void load();
        void draw();
    private:
        CurrentSelectedButton currentSelectedButton = FIGHT;
    };
}

#endif //PROJECT_FIGHTINTERFACESPRITES_H
