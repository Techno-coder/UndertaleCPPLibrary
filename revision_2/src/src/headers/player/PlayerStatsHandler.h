#ifndef PROJECT_PLAYERSTATSHANDLER_H
#define PROJECT_PLAYERSTATSHANDLER_H

#include <string>

namespace ug {

    /**
     * @todo Consider that using setter functions in these functions may result in an infinite recursive loop
     */
    class PlayerStatsHandler {
    public:
        /**
         * Called after the level changes
         * @param oldLevel The old level
         * @param newLevel The new level set
         */
        void onLevelChange(const int& oldLevel, const int& newLevel) {};

        /**
         * Called after the exp changes
         * @param oldExp The old exp
         * @param newExp The new exp set
         */
        void onExpChange(const int& oldExp, const int& newExp) {};

        /**
         * Called after the maxHealth changes
         * @param oldMaxHealth The old maxHealth
         * @param newMaxHealth The new maxHealth
         */
        void onMaxHealthChange(const int& oldMaxHealth, const int& newMaxHealth) {};

        /**
         * Called after the health changes
         * @param oldHealth The old health
         * @param newHealth The new health
         */
        void onHealthChange(const int& oldHealth, const int& newHealth) {};

        /**
         * Called after the defense changes
         * @param oldDefense The old defense
         * @param newDefense The new defense
         */
        void onDefenseChange(const int& oldDefense, const int& newDefense) {};

        /**
         * Called after the attack changes
         * @param oldAttack The old attack amount
         * @param newAttack The new attack amount
         */
        void onAttackChange(const int& oldAttack, const int& newAttack) {};

        /**
         * Called after the players name changes
         * @param oldName The old name
         * @param newName The new name
         */
        void onNameChange(const std::string& oldName, const std::string& newName) {};
    };
}

#endif //PROJECT_PLAYERSTATSHANDLER_H
