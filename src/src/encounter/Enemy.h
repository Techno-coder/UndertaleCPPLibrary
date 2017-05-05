#ifndef PROJECT_ENEMY_H
#define PROJECT_ENEMY_H

#include <functional>
#include <SFML/Graphics/Sprite.hpp>
#include <string>
#include "Projectile.h"

namespace ug {
    class Enemy {
        const ProjectileSpawner projectileSpawner;

        static unsigned long nextID;
        //TODO figure out if ID is required still
        const unsigned long ID;

        std::string name = "Default Enemy";
        bool spareable = false;

    public:
        Enemy(const ProjectileSpawner &projectileSpawner, const unsigned long& ID);
        Enemy(const ProjectileSpawner &projectilesSpawner);

        /**
         * Creates a copy of this enemy instance
         *
         * @warning Does not copy the current spareable state of the enemy
         * @return A copy of this enemy
         */
        Enemy clone() const;

        const ProjectileSpawner &getProjectileSpawner() const;

        const std::string &getName() const;
        void setName(const std::string &name);

        bool canSpare() const;
        void setCanSpare(bool canSpare);
    };
}

#endif //PROJECT_ENEMY_H
