#ifndef PROJECT_FIGHT_H
#define PROJECT_FIGHT_H

#include <string>
#include "AttackSequence.h"

namespace ug {

/**
 * Fight abstract class; Inherit this class to create your own fight
 */
    class Fight {
    public:
        /**
         * Get the attack sequence for this turn
         * @param turnIndex The amount of players turns since the start of the fight
         * @return The attack sequence for this turn
         */
        virtual AttackSequence getNextAttackSequence(int turnIndex) = 0;

        /**
         * Gets the next flavour text that appears on the players turn
         * @param turnIndex The amount of players turns since the start of the fight
         * @return The flavour text for the players turn
         */
        virtual std::string getNextFlavourText(int turnIndex) { return ""; }

        /**
         * Function called before the fight begins
         */
        virtual void initializeFight() {};

        /**
         * Function called after the fight ends
         */
        virtual void finalizeFight() {};

        /**
         * Function called when a FightEntity collides or intersects with another FightEntity
         * @param entityA The first FightEntity
         * @param entityB The second FightEntity
         */
        virtual void onEnemyEntityCollision(FightEntity entityA, FightEntity entityB) {};

        /**
         * Function called when a FightEntity collides or intersects with the players heart
         * @param entity The entity that collided with the players heart
         */
        virtual void onPlayerCollision(FightEntity entity) {};

    };
}


#endif //PROJECT_FIGHT_H
