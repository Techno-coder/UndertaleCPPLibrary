#ifndef PROJECT_ENEMY_H
#define PROJECT_ENEMY_H

#include <functional>
#include <SFML/Graphics/Sprite.hpp>
#include <string>
#include "Projectile.h"
#include "../state/State.h"

namespace ug {
    class Enemy;
    typedef std::function<void(State &state)> ActFunction;

    class Act {
        static unsigned long nextID;
        unsigned long ID;

        std::string name = "Default Name";
        ActFunction onAct;
    public:
        Act(ActFunction action);
        void execute(State &state);

        const std::string &getName() const;
        void setName(const std::string &name);
    };

    class Enemy {
        const ProjectileSpawner projectileSpawner;
        std::vector<Act> acts;

        static unsigned long nextID;
        //TODO figure out if ID is required still
        const unsigned long ID;

        struct Attributes {
            std::string name = "Default Enemy";
            bool spareable = false;
            int health = 0;
            int maxHealth = 0;
        } attributes;

        sf::Sprite sprite;
    public:
        Enemy(const ProjectileSpawner &projectileSpawner, sf::Sprite sprite, const unsigned long& ID);
        Enemy(const ProjectileSpawner &projectilesSpawner, sf::Sprite sprite);

        /**
         * Creates a copy of this enemy instance
         *
         * @warning Does not copy the current spareable state of the enemy
         * @param The position of the new enemy relative to the top left corner of the window
         * @return A copy of this enemy
         */
        Enemy clone(sf::Vector2f position) const;

        const ProjectileSpawner &getProjectileSpawner() const;

        std::vector<Act>& getActs();
        Attributes &getAttributes();

        /**
         * Get the sprite of this enemy
         * @warning The sprites position should be relative to the top left corner of the window
         * @param sprite The sprite
         */
        sf::Sprite &getSprite();
    };
}

#endif //PROJECT_ENEMY_H
