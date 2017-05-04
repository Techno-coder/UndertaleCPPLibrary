#ifndef PROJECT_PLAYER_H
#define PROJECT_PLAYER_H

#include <string>
#include "../../external/ObservableField.h"
#include "Inventory.h"

namespace ug {
    class Player {
        struct PlayerStatistics {
            ObservableField<short> health{10};
            ObservableField<short> maxHealth{20};
            ObservableField<short> level{3};
            ObservableField<std::string> playerName{"CHARA"};
        } playerStatistics;
        Inventory playerInventory;
    public:
        Player(); //TODO REMOVE LATER

        PlayerStatistics& getStatistics();
        Inventory& getInventory();
    };
}

#endif //PROJECT_PLAYER_H
