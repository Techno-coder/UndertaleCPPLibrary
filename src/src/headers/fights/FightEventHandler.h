
#ifndef PROJECT_FIGHTEVENTHANDLER_H
#define PROJECT_FIGHTEVENTHANDLER_H

#include "ActCommand.h"
#include "../player/inventory/Item.h"

namespace ug {

    /**
     * Inherit this class to create your own event handler
     * Functions in this class will be called when the appropriate event in the fight occurs
     * @todo Events in here need to be thought about carefully
     * @todo Rethink this as there can be multiple enemies
     */
    class FightEventHandler {
    public:
        /**
         * Called when the fight starts
         */
        virtual void onFightStart() {};

        /**
         * Called before the enemy starts talking
         */
        virtual void onEnemyDialogueStart() {};

        /**
         * Called after the enemy stops talking
         */
        virtual void onEnemyDialogueEnd() {};

        /**
         * Called after the enemies wave ends
         * @param numOfWaves The amount of waves survived since the start of the encounter
         */
        virtual void onWaveEnd(int numOfWaves) {};

        /**
         * Called when an act is used
         * @param act The act that was used
         * @warning Implement the handle function of the ActCommand instead of this to add functionality to the act
         */
        virtual void onActUse(const ActCommand& act) {};

        /**
         * Called when an item is used
         * @param item The item that was used
         * @warning Implement the handle function of the Item instead of this to add functionality to the item
         */
        virtual void onItemUse(const Item& item) {};
    };
}

#endif //PROJECT_FIGHTEVENTHANDLER_H
