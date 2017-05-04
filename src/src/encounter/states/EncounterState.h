#ifndef PROJECT_ENCOUNTERSTATE_H
#define PROJECT_ENCOUNTERSTATE_H

#include "../../state/State.h"
#include "../../../external/resources/TexturesResources.h"
#include "../../../external/resources/SoundsResources.h"
#include "../../../external/resources/FontsResources.h"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <map>

namespace ug {
    class EncounterState : public State {
        class Fonts : FontsResources {
            const std::string PATH_PREFIX{"resources/default/encounter/"};
        public:
            FontsResourceItem CRYPT{PATH_PREFIX + "CryptOfTomorrow.ttf", this};
            FontsResourceItem MARS{PATH_PREFIX + "mars.ttf", this};
        };
        class Textures : TexturesResources {
            const std::string PATH_PREFIX{"resources/default/encounter/"};
        public:
            TexturesResourceItem FIGHT{PATH_PREFIX + "FightButton.png", this};
            TexturesResourceItem FIGHT_HIGHLIGHT{PATH_PREFIX + "FightHighlightButton.png", this};
            TexturesResourceItem ACT{PATH_PREFIX + "ActButton.png", this};
            TexturesResourceItem ACT_HIGHLIGHT{PATH_PREFIX + "ActHighlightButton.png", this};
            TexturesResourceItem ITEM{PATH_PREFIX + "ItemButton.png", this};
            TexturesResourceItem ITEM_HIGHLIGHT{PATH_PREFIX + "ItemHighlightButton.png", this};
            TexturesResourceItem MERCY{PATH_PREFIX + "MercyButton.png", this};
            TexturesResourceItem MERCY_HIGHLIGHT{PATH_PREFIX + "MercyHighlightButton.png", this};
            TexturesResourceItem SOUL{PATH_PREFIX + "heartDefend.png", this};
        };
//TODO Consider moving sounds to global state as these sounds apply to all
        class Sounds : SoundsResources {
            const std::string PATH_PREFIX{"resources/default/all/"};
        public:
            SoundsResourceItem MENU_CONFIRM{PATH_PREFIX + "menuconfirm.wav", this};
            SoundsResourceItem MENU_MOVE{PATH_PREFIX + "menumove.wav", this};
        };
    protected:
        enum class ActiveButton{FIGHT, ACT, ITEM, MERCY} activeButton;
        void setActiveButton(ActiveButton button);

        static Sounds sounds;
        sf::Sprite soul;

        virtual void onDraw(sf::RenderWindow& window) override;
    public:
        EncounterState();
    private:
        static Textures textures;
        static Fonts fonts;
        struct PrivateSprites {
            sf::Sprite actButton;
            sf::Sprite fightButton;
            sf::Sprite itemButton;
            sf::Sprite mercyButton;

            sf::Text playerName;
            sf::Text playerLevel;
            sf::Text playerHealthLabel;
            sf::Text playerHealthFraction;
            sf::RectangleShape currentHealthBar;
            sf::RectangleShape maxHealthBar;
        } privateSprites;

        void initializePrivateSprites();
    };
}

#endif //PROJECT_ENCOUNTERSTATE_H
