#ifndef PROJECT_ENEMYEVENTHANDLER_H
#define PROJECT_ENEMYEVENTHANDLER_H

#include "Enemy.h"

namespace ug {
    class Enemy;

    class EnemyEventHandler {
    public:
        void onDamaged(Enemy &enemy) {};
        void onDeath(Enemy &enemy) {};
        void onUpdate(Enemy &enemy) {};
    };
}

#endif //PROJECT_ENEMYEVENTHANDLER_H
