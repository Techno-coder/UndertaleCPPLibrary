#ifndef PROJECT_FIGHT_H
#define PROJECT_FIGHT_H

#include <vector>
#include <map>
#include "FightEventHandler.h"
#include "enemies/Enemy.h"

namespace ug {
    class Fight {
        /**
         * @todo Consider using map for functionality in removing handlers
         * @todo Consider using unique pointers to avoid memory leaks
         */
        std::vector<FightEventHandler*> handlers;

        std::vector<Enemy> enemies;
    public:

        /**
         * Add an EventHandler to listen for events
         * @param handler The handler to add
         * @warning May cause memory leaks if the pointer is not used with delete
         * @todo Consider using unique pointers
         */
        void registerHandler(FightEventHandler* const handler);

        /**
         * Add an enemy to the fight
         * @param enemy An enemy instance
         * @param enemyID The string to reference this particular enemy
         */
        void addEnemy(Enemy& enemy);

        /**
         * Remove an enemy from the fight
         * @param enemyID The enemyID
         */
        void removeEnemy(const std::string& enemyID);

        /**
         * Get the enemies in this fight
         * @return A vector of enemies
         */
        std::vector<Enemy>& getEnemies();

    };
}

#endif //PROJECT_FIGHT_H
