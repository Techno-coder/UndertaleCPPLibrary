#ifndef PROJECT_PLAYERSTATS_H
#define PROJECT_PLAYERSTATS_H

#include <vector>
#include <string>
#include "PlayerStatsHandler.h"

namespace ug {

    /**
     * Handles and stores common player stats
     */
    class PlayerStats {

        /**
         * @todo Consider using a map for functionality of removing handlers
         */
        std::vector<PlayerStatsHandler*> handlers;

        /**
         * The attack used when determining damage dealt in fights
         * @todo Consider the damage dealt to be calculated manually (by the library user)
         */
        int attack = 0;

        /**
         * The defense used when determining damage received in fights
         * @todo Consider the damage received to be calculated manually (by the library user)
         */
        int defense = 0;

        /**
         * The exp shown in various places
         */
        int exp = 0;

        /**
         * The level shown in various places
         */
        int level = 1;

        /**
         * The maximum health the player can have
         * @note This variable is ignored when using setHealth
         */
        int maxHealth = 0;

        /**
         * The amount of health the player has
         * @note The variable is limited by the variable maxHealth unless using setHealth
         */
        int health = 0;

        /**
         * The name of the player used in various places
         */
        std::string name = "DEFAUL";

    public:

        /**
         * Add an EventHandler to listen for events
         * @param handler The handler to add
         * @todo Consider functionality for removing handlers - if so may require unique pointers for potential leak
         */
        void registerHandler(PlayerStatsHandler* const handler);

        /**
         * Set the level
         * @param newLevel The level that it should be set to
         */
        void setLevel(const int& newLevel);

        /**
         * Get the level
         * @return The level the player currently has
         */
        const int& getLevel();

        /**
         * Set the exp
         * @param newExp The exp that it should be set to
         */
        void setExp(const int& newExp);

        /**
         * Adds an amount of exp to the current amount
         * @param addAmount The amount of exp that should be added
         */
        void addExp(const int& addAmount);

        /**
         * Get the exp
         * @return The amount of exp the player has
         */
        const int& getExp();

        /**
         * Set the maxHealth
         * @param newMaxHealth The maxHealth that it should be set to
         */
        void setMaxHealth(const int& newMaxHealth);

        /**
         * Get the maxHealth
         * @return The maximum amount of health the player can have
         */
        const int& getMaxHealth();

        /**
         * Set the health of the player
         * @param newHealth The amount of health the player should have
         * @param ignoreMaxHealth Whether the newHealth should be constrained by maxHealth
         */
        void setHealth(const int& newHealth, const bool& ignoreMaxHealth);

        /**
         * Heal the player an amount
         * This function is affected by maxHealth
         * @param addAmount The amount to heal
         */
        void addHealth(const int& addAmount);

        /**
         * Remove some health from the player
         * This function is affected by maxHealth
         * This functions is unaffected by the defense statistic
         * @param removeAmount The amount to remove
         */
        void removeHealth(const int& removeAmount);

        /**
         * Get the health
         * @return The current amount of health
         */
        const int& getHealth();

        /**
         * Set the defense of the player
         * @param newDefense The new defense
         */
        void setDefense(const int& newDefense);

        /**
         * Get the defense of the player
         * This statistic is used in determining the amount of damage received in fights
         * @return The defense statistic
         */
        const int& getDefense();

        /**
         * Set the attack of the player
         * @param newAttack The new attack amount
         */
        void setAttack(const int& newAttack);

        /**
         * Get the attack statistic of the player
         * @return The attack statistic
         */
        const int& getAttack();

        /**
         * Set the name of the player (shown in various places)
         * @param newName The new name
         */
        void setName(const std::string& newName);

        /**
         * Get the name of the player
         * @return The name
         */
        const std::string& getName();
    };
}

#endif //PROJECT_PLAYERSTATS_H
