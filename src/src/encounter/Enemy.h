#ifndef PROJECT_ENEMY_H
#define PROJECT_ENEMY_H

#include <functional>
#include <SFML/Graphics/Sprite.hpp>
#include <string>
#include "Projectile.h"

namespace ug {
    class Enemy;
    typedef std::function<void(Enemy &enemy)> ActFunction;

    class Act {
        static unsigned long nextID;
        unsigned long ID;

        std::string name = "Default Name";
        ActFunction onAct;
    public:
        Act(ActFunction action);
        void execute(Enemy &enemy);

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

        std::vector<Act>& getActs();
        Attributes &getAttributes();
    };
}

#endif //PROJECT_ENEMY_H
