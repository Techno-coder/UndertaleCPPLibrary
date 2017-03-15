#ifndef PROJECT_PLAYER_H
#define PROJECT_PLAYER_H

#include <string>
#include "PlayerStats.h"
#include "inventory/Item.h"

namespace ug {

    /**
     * The player of the game
     * @todo
     */
    class Player {

        /**
         * @todo Consider allowing the library user to set a new instance of PlayerStats
         */
        PlayerStats playerStats;

        /**
         * @todo consider creating inventory class for handling items
         */
        std::vector<Item> inventory;
    public:
        PlayerStats& getPlayerStats();

        std::vector<Item>& getInventory();

        void addItem(Item& item);
    };
}

#endif //PROJECT_PLAYER_H
