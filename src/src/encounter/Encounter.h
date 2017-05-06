#ifndef PROJECT_IENCOUNTER_H
#define PROJECT_IENCOUNTER_H

#include <vector>
#include "Enemy.h"

namespace ug {
    class Encounter {
        std::vector<Enemy> enemies;

        //TODO consider having variables here which determine the fight states; easy modifying of functionality
    public:
        void addEnemy(Enemy enemy);
        std::vector<Enemy>& getAllEnemies();
    };
}

#endif //PROJECT_IENCOUNTER_H
