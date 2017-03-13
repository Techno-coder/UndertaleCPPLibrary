#ifndef PROJECT_PLAYER_H
#define PROJECT_PLAYER_H

#include <string>
#include "PlayerStats.h"

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
    public:
        PlayerStats& getPlayerStats();
    };
}

#endif //PROJECT_PLAYER_H
