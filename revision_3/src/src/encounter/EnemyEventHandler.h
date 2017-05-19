#ifndef PROJECT_ENEMYEVENTHANDLER_H
#define PROJECT_ENEMYEVENTHANDLER_H

#include "Enemy.h"

namespace ug {
    class Enemy;

    class EnemyEventHandler {
    public:
        /**
         * Called when the enemy is damaged
         * @param enemy The enemy
         */
        void onDamaged(Enemy &enemy) {};

        /**
         * Called when the enemy dies
         * @param enemy The enemy
         */
        void onDeath(Enemy &enemy) {};

        /**
         * Called every 60th of a second
         * @param enemy
         */
        void onUpdate(Enemy &enemy) {};
    };
}

#endif //PROJECT_ENEMYEVENTHANDLER_H
