#ifndef PROJECT_IENCOUNTER_H
#define PROJECT_IENCOUNTER_H

#include <vector>
#include "Enemy.h"

namespace ug {
    class Encounter {
        std::vector<Enemy> enemies;
    public:
        void addEnemy(Enemy enemy);
        std::vector<Enemy>& getAllEnemies();
    };
}

#endif //PROJECT_IENCOUNTER_H
