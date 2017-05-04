#ifndef PROJECT_ENEMY_H
#define PROJECT_ENEMY_H

#include <functional>
#include <SFML/Graphics/Sprite.hpp>
#include <string>

namespace ug {
    struct Damager {
        sf::Sprite sprite;
        short damageOnCollide;
    };

    typedef std::function<std::vector<Damager>(int frames)> GetDamagersFunction;

    class Enemy {
        const GetDamagersFunction getDamagersFunction;

        static unsigned long nextID;
        const unsigned long ID;

        std::string name = "Default Enemy";
    public:
        Enemy(const GetDamagersFunction &getDamagers, const unsigned long& ID);
        Enemy(const GetDamagersFunction &getDamagers);

        Enemy clone() const;

        std::vector<Damager> getDamagers(int frames) const;

        const std::string &getName() const;
        void setName(const std::string &name);
    };
}

#endif //PROJECT_ENEMY_H
