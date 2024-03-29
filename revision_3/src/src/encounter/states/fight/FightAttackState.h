#ifndef PROJECT_FIGHTATTACKSTATE_H
#define PROJECT_FIGHTATTACKSTATE_H

#include "../EncounterState.h"

namespace ug {
    class FightAttackState : public EncounterState {
        class FightTextures : public TexturesResources {
            const std::string PATH_PREFIX{"resources/default/encounter/"};
            const std::string SLICE_PREFIX{PATH_PREFIX + "fight/"};
        public:
            TexturesResourceItem FIGHT_BAR{PATH_PREFIX + "fightBar.png", this};

            TexturesResourceItem SLICE_0{SLICE_PREFIX + "spr_slice_o_0.png", this};
            TexturesResourceItem SLICE_1{SLICE_PREFIX + "spr_slice_o_1.png", this};
            TexturesResourceItem SLICE_2{SLICE_PREFIX + "spr_slice_o_2.png", this};
            TexturesResourceItem SLICE_3{SLICE_PREFIX + "spr_slice_o_3.png", this};
            TexturesResourceItem SLICE_4{SLICE_PREFIX + "spr_slice_o_4.png", this};
            TexturesResourceItem SLICE_5{SLICE_PREFIX + "spr_slice_o_5.png", this};
        }; //TODO potentially be static
        class FightSounds : public SoundsResources {
            const std::string PATH_PREFIX{"resources/default/encounter/fight/"};
        public:
            SoundsResourceItem SLICE{PATH_PREFIX + "slice.wav", this};
            SoundsResourceItem HIT{PATH_PREFIX + "hitsound.wav", this};
        };
        class FightFonts : public FontsResources {
            const std::string PATH_PREFIX{"resources/default/encounter/fight/"};
        public:
            FontsResourceItem HACHICRO{PATH_PREFIX + "hachicro.ttf", this};
        };

        static FightTextures textures;
        static FightSounds sounds;
        static FightFonts fonts;

        sf::Sprite fightBar;
        sf::RectangleShape targetLine{sf::Vector2f(7, 122)};

        sf::Sprite slice{textures.SLICE_0};
        sf::RectangleShape maxHealthRect;
        sf::RectangleShape healthRect;
        sf::Text damageText{"", fonts.HACHICRO};

        float initialHealthRectSize;
        int damageDealt;
        std::vector<Enemy>::iterator enemy;

        int timerCounter = 0;
        int sliceCounter = 0;
        bool hit = false;

        void onKeyPress(Controls::Keys key);
        void calculateDamageDealt();
        float getRandomFloat(float max);
    protected:
        void onEnter() override;

        void onUpdate() override;
        void onDraw(sf::RenderWindow &window) override;

    public:
        FightAttackState(const std::shared_ptr<Encounter> &encounter, std::vector<Enemy>::iterator enemy);
        virtual ~FightAttackState();
    };
}


#endif //PROJECT_FIGHTATTACKSTATE_H
