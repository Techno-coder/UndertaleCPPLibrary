#ifndef PROJECT_ENEMY_H
#define PROJECT_ENEMY_H

#include <vector>
#include "../ActCommand.h"
#include "EnemyEventHandler.h"

namespace ug {
    class ActCommand;

    class Enemy {

        /**
         * @todo consider using unique pointers
         * @warning When copying this Enemy the handler pointers will point to the same handlers
         */
        std::vector<EnemyEventHandler*> enemyEventHandlers;

        /**
         * @todo consider using unique pointers
         */
        std::vector<ActCommand*> actCommands;

        bool canSpare = false;
        std::string enemyName;
        std::string enemyID;

        int health = 0;
        int maxHealth = 0;
    public:

        /**
         * Constructor
         * @param enemyName The name of the enemy shown on any enemy selection menu
         */
        Enemy(const std::string& enemyID, const std::string& enemyName);
        Enemy(const std::string& enemyName);

        /**
         * Get the act commands for this enemy
         * @return A vector of act commands
         */
        std::vector<ActCommand*>& getActCommands();

        /**
         * Add an act command to be displayed
         * @param actCommand The act command
         */
        void addActCommand(ActCommand* const actCommand);

        /**
         * Add a handler
         * @param handler The handler to add
         */
        void registerHandler(EnemyEventHandler*const handler);

        /**
         * Set whether this enemy can be spared
         * @param spare True if this enemy can be spared now
         */
        void setCanSpare(bool spare);

        /**
         * Whether this enemy can be spared
         * @return True if this enemy can be spared
         */
        const bool& isCanSpare();

        /**
         * Create a new enemy from this one
         * @return An enemy exactly like this one
         */
        Enemy clone();

        /**
         * Get the enemy name
         * @return The enemy name
         */
        const std::string &getEnemyName() const;

        /**
         * Get the enemy ID
         * @return The enemy ID
         */
        const std::string &getEnemyID() const;

        int getHealth() const;

        void setHealth(int health);

        int getMaxHealth() const;

        void setMaxHealth(int maxHealth);
        //TODO get attack helicopter
    };

}

#endif //PROJECT_ENEMY_H
